
#include <tilemap.hpp>

namespace iq
{
	tilemap::tilemap(const std::string &path, std::map<std::string, iq::tile_ptr> &tiles)
	{
		this->load(path, tiles);

//		this->loadHard();
	}

	void tilemap::draw(const iq::BITMAP_ptr scrbuf) const
	{
		iq::BITMAP_ptr tilebmp;

		for(iq::uint z=0, zlen=this->layers.size(); z<zlen; z++)
		{
			for(iq::uint y=0, ylen=this->layers[z].size(); y<ylen; y++)
			{
				for(iq::uint x=0, xlen=this->layers[z][y].size(); x<xlen; x++)
				{
					tilebmp = this->layers[z][y][x]->bitmap;

					masked_blit(tilebmp.get(), scrbuf.get(), 0, 0,
					            x * tilebmp->w, y * tilebmp->h,
					            tilebmp->w, tilebmp->h);
				}
			}
		}
	}

	void tilemap::load(const std::string &path, std::map<std::string, iq::tile_ptr> &tiles)
	{
		iq::TiXmlDocument_ptr doc(new TiXmlDocument(path));
		TiXmlElement *root = NULL;

		if(!doc->LoadFile())
			throw std::runtime_error("Failed to load tilemap from XML document '" + path + "'.");

		if((root = doc->RootElement()) == NULL)
			throw std::runtime_error("Tilemap XML missing root element.");

		this->load(root, path, tiles);
	}

	void tilemap::load(const TiXmlElement * const map, const std::string &path, std::map<std::string, iq::tile_ptr> &tiles)
	{
		const TiXmlElement *element = NULL;
		const TiXmlElement *texture = NULL;
		const TiXmlElement *dimensions = NULL;
		const TiXmlElement *layout = NULL;
		std::string tag_name;
		iq::BITMAP_ptr tileset;

		if((element = map->FirstChildElement()) == NULL)
			throw std::runtime_error("Tilemap XML root element has no element children.");

		do
		{
			tag_name = element->ValueStr();

			if(tag_name == "MAP_TEXTURE")
				texture = element;
			else if(tag_name == "MAP_DIMENSIONS")
				dimensions = element;
			else if(tag_name == "LAYOUT")
				layout = element;
		}while((element = element->NextSiblingElement()));

		if(texture == NULL)
			throw std::runtime_error("Tilemap XML is missing MAP_TEXTURE element.");

		if(dimensions == NULL)
			throw std::runtime_error("Tilemap XML is missing MAP_DIMENSIONS element.");

		if(layout == NULL)
			throw std::runtime_error("Tilemap XML is missing LAYOUT element.");

		tileset = this->load_tileset(texture);
		this->load_dimensions(dimensions);
		this->load_layout(layout, path, tileset, tiles);
	}

	void tilemap::load_dimensions(const TiXmlElement * const dimensions)
	{
		const TiXmlElement *element = NULL;
		const TiXmlNode *node = NULL;
		int w, h, num_layers;
		std::string s;
		std::stringstream ss;

		if((element = dimensions->FirstChildElement("Tile_Size")) == NULL)
			throw std::runtime_error("MAP_DIMENSIONS XML is missing the Tile_Size element.");

		if((node = element->FirstChild()) == NULL || node->Type() != TiXmlNode::TEXT)
			throw std::runtime_error("Tile_Size XML is invalid.");

		ss.str(s = node->ToText()->ValueStr());

		if(!(ss >> this->tilesize))
			throw std::runtime_error("Invalid tilesize '" + s + "'.");

		if((element = element->NextSiblingElement("Layers")) == NULL)
			throw std::runtime_error("MAP_DIMENSIONS XML is missing Layers element.");

		if((node = element->FirstChild()) == NULL || node->Type() != TiXmlNode::TEXT)
			throw std::runtime_error("Layers XML element is invalid.");

		ss.str(s = node->ToText()->ValueStr());

printf("ss.str=%s ss.fail=%d ss.bad=%d\n", ss.str().c_str(), ss.fail(), ss.bad());

		if(!(ss >> num_layers))
			throw std::runtime_error("Invalid tilemap layers count '" + s + "'.");

		if((element = element->NextSiblingElement("Width")) == NULL)
			throw std::runtime_error("MAP_DIMENSIONS XML is missing Width element.");

		if((node = element->FirstChild()) == NULL || node->Type() != TiXmlElement::TEXT)
			throw std::runtime_error("Width XML element is invalid.");

		ss.str(s = node->ToText()->ValueStr());

		if(!(ss >> w))
			throw std::runtime_error("Invalid tilemap width '" + s + "'.");

		if((element = element->NextSiblingElement("Height")) == NULL)
			throw std::runtime_error("MAP_DIMENSIONS XML is missing Height element.");

		if((node = element->FirstChild()) == NULL || node->Type() != TiXmlElement::TEXT)
			throw std::runtime_error("Height XML element is invalid.");
		
		ss.str(s = node->ToText()->ValueStr());

		if(!(ss >> h))
			throw std::runtime_error("Invalid tilemap width '" + s + "'.");
	}

	const std::vector< std::vector<iq::tile_ptr> > tilemap::load_layer(const TiXmlElement * const layer, const std::string &path, const iq::BITMAP_ptr tileset, std::map<std::string, iq::tile_ptr> &tiles)
	{
		const TiXmlElement *element = NULL;
		std::vector< std::vector<iq::tile_ptr> > l;

		if((element = layer->FirstChildElement("RowInfo")) == NULL)
			throw std::runtime_error("Layer XML missing one or more RowInfo elements.");

		do
		{
			l.push_back(this->load_rowinfo(element, path, tileset, tiles));
		}while((element = element->NextSiblingElement("RowInfo")));

		return l;
	}

	void tilemap::load_layout(const TiXmlElement * const layout, const std::string &path, const iq::BITMAP_ptr tileset, std::map<std::string, iq::tile_ptr> &tiles)
	{
		const TiXmlElement *element = NULL;

		if((element = layout->FirstChildElement("Layer")) == NULL)
			std::runtime_error("LAYOUT XML missing one or more Layer elements.");

		do
		{
			this->layers.push_back(this->load_layer(element, path, tileset, tiles));
		}while((element = element->NextSiblingElement("Layer")));
	}

	const std::vector<iq::tile_ptr> tilemap::load_rowinfo(const TiXmlElement * const rowinfo, const std::string &path, const BITMAP_ptr tileset, std::map<std::string, iq::tile_ptr> &tiles)
	{
		iq::uint i;
		std::stringstream ss;
		std::vector<iq::tile_ptr> tilerow;

		if(!(ss << rowinfo->ValueStr()))
			throw std::runtime_error("Failed to load tilerow.");

		while(ss >> i)
		{
			tilerow.push_back(this->load_tile(tiles, tileset, path, i));
			ss.ignore(1);
		}

		return tilerow;
	}

	const tile_ptr tilemap::load_tile(std::map<std::string, iq::tile_ptr> &tiles, const iq::BITMAP_ptr tileset, const std::string &path, const iq::uint i)
	{
		iq::BITMAP_ptr bitmap;
		const iq::uint d = i * this->tilesize;
		std::map<std::string, iq::tile_ptr>::iterator it;
		std::string k = path + ":" + boost::lexical_cast<std::string>(i);
		iq::tile_ptr tile;

		if((it = tiles.find(k)) != tiles.end())
			return it->second;

		bitmap.reset(create_bitmap(this->tilesize, this->tilesize), destroy_bitmap);

		if(bitmap.get() == NULL)
			throw std::runtime_error("Failed to allocate memory for tile bitmap.");

		blit(tileset.get(), bitmap.get(), d, d, 0, 0, this->tilesize, this->tilesize);

		tile.reset(new iq::tile(bitmap));

		tiles[k] = tile;

		return tile;
	}

	const BITMAP_ptr tilemap::load_tileset(const TiXmlElement * const texture)
	{
		const TiXmlElement *element = NULL;
		const TiXmlNode *node = NULL;
		std::string path;
		iq::BITMAP_ptr tileset;

		if((element = texture->FirstChildElement("FileName")) == NULL)
			throw std::runtime_error("MAP_TEXTURE XML is missing FileName element.");

		if((node = element->FirstChild()) == NULL || node->Type() != TiXmlNode::TEXT)
			throw std::runtime_error("FileName XML is missing it's text value.");

		path = node->ToText()->ValueStr();

		tileset.reset(load_bmp(path.c_str(), NULL), destroy_bitmap);

		if(tileset.get() == NULL)
			throw std::runtime_error("Failed to load tileset '" + path + "'.");

		return tileset;
	}

	// WARNING! A DEADLY KLUDGE LURKS NEARBY!
/*	void tilemap::loadHard()
	{
		int n = 0;
		BITMAP_ptr tmpBitmap;
		tile_ptr tmpTile;

		this->rawTileSetImage.reset(load_bmp("map/example.tileset", NULL), destroy_bitmap);

		if(this->rawTileSetImage.get() == NULL)
			throw std::runtime_error("Failed to load map/example.tileset.");

		this->MapTextureWidth = 64;
		this->MapTextureHeight = 96;
		this->MapNumTilesWide = 2;
		this->MapNumTilesHigh = 3;
		this->TileSize = 32;
		this->MapWidth = 10;
		this->MapHeight = 10;

		for(uint y = 0; y < MapNumTilesHigh; y++)
		{
			for(uint x = 0; x < MapNumTilesWide; x++) 
			{
				tmpBitmap.reset(create_bitmap(TileSize, TileSize), destroy_bitmap);

				blit(rawTileSetImage.get(), tmpBitmap.get(), x * TileSize, y * TileSize, 0, 0, TileSize, TileSize);

				tmpTile.reset(new tile(tmpBitmap));	

				TileSet.push_back(tmpTile);				

			}
		}

		int foo[][10][10] = {
			{
			{2,2,2,2,2,2,2,2,2,2},
			{4,4,4,4,4,4,4,4,4,4},
			{6,6,6,6,6,6,6,6,6,6},
			{1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1},
			{1,1,1,1,1,1,1,1,1,1},
				}
			};

		//STRAIGHT
		for(uint i = 0; i < numLayers; i++)
		{
			this->layers.push_back(std::vector<std::vector<tile_ptr> >() );
			for(uint y = 0; y < MapHeight; y++)
			{
				this->layers[i].push_back(std::vector<tile_ptr>());
				for(uint x = 0; x < MapWidth; x++)
				{
					this->layers[i][y].push_back(TileSet[foo[i][y][x]-1]);
				}
			}
		}

		const iq::uint get_tilesize(void) const
		{
			return this->tilesize;
		}
	}*/
}

