#include <allegro.h>
/* XPM */
static const char *allegico_xpm[] = {
/* columns rows colors chars-per-pixel */
"32 32 224 2",
"   c black",
".  c #0E0E06060000",
"X  c #0B0B08080606",
"o  c #0A0A09090808",
"O  c #08080A0A0C0C",
"+  c #141401010000",
"@  c #1A1A02020000",
"#  c #1F1F05050000",
"$  c #121209090000",
"%  c #1A1A0F0F0303",
"&  c #1C1C0E0E0000",
"*  c #1A1A08080404",
"=  c #1C1C11110606",
"-  c #1A1A11110909",
";  c #222202020000",
":  c #222203030000",
">  c #2F2F04040000",
",  c #20200D0D0000",
"<  c #353505050000",
"1  c #3E3E05050000",
"2  c #3A3A0B0B0000",
"3  c #3D3D0C0C0404",
"4  c #2B2B1A1A0B0B",
"5  c #343416160000",
"6  c #3C3C11110000",
"7  c #313118180000",
"8  c #37371B1B0202",
"9  c #353518180E0E",
"0  c #25251E1E1A1A",
"q  c #38382B2B1C1C",
"w  c #3F3F38381C1C",
"e  c #0C0C14143C3C",
"r  c #1A1A20202727",
"t  c #38382A2A3030",
"y  c #47470F0F0000",
"u  c #5A5A08080000",
"i  c #5B5B09090000",
"p  c #61610E0E0000",
"a  c #61610F0F0000",
"s  c #666613130000",
"d  c #626212120505",
"f  c #636313130707",
"g  c #686815150000",
"h  c #696915150000",
"j  c #6A6A17170000",
"k  c #6C6C1F1F0F0F",
"l  c #70701C1C0000",
"z  c #70701D1D0000",
"x  c #404024240909",
"c  c #4E4E25251111",
"v  c #4F4F31311212",
"b  c #484834341717",
"n  c #5D5D30301A1A",
"m  c #595939391919",
"M  c #5C5C3C3C1B1B",
"N  c #6C6C27270000",
"B  c #6E6E20200F0F",
"V  c #777723230101",
"C  c #787823230000",
"Z  c #7E7E2A2A0202",
"A  c #747423230808",
"S  c #60602D2D1414",
"D  c #717123231212",
"F  c #7D7D31311C1C",
"G  c #7E7E36361C1C",
"H  c #7F7F37371E1E",
"J  c #5E5E48482F2F",
"K  c #636346462727",
"L  c #64644D4D3232",
"P  c #191922224242",
"I  c #2E2E3A3A4B4B",
"U  c #42423C3C4C4C",
"Y  c #343441414E4E",
"T  c #80802B2B0000",
"R  c #80802C2C0202",
"E  c #8F8F38380000",
"W  c #8F8F39390000",
"Q  c #96963F3F0000",
"!  c #82823A3A2020",
"~  c #84843B3B2222",
"^  c #89893F3F2525",
"/  c #9F9F4B4B0909",
"(  c #8F8F41411C1C",
")  c #A6A64E4E0000",
"_  c #ADAD55550000",
"`  c #A9A953530505",
"'  c #BDBD63630000",
"]  c #BEBE67670707",
"[  c #B7B768681717",
"{  c #BBBB6E6E1F1F",
"}  c #BEBE6C6C1C1C",
"|  c #898944442525",
" . c #8E8E49492929",
".. c #97974E4E2020",
"X. c #999953532828",
"o. c #9A9A56562C2C",
"O. c #9D9D59592C2C",
"+. c #9B9B56563333",
"@. c #9C9C5B5B3434",
"#. c #9C9C5C5C3434",
"$. c #9E9E5E5E3636",
"%. c #A2A256562828",
"&. c #BCBC6C6C2020",
"*. c #B6B66C6C2B2B",
"=. c #A1A160603838",
"-. c #A5A567673C3C",
";. c #A9A962623838",
":. c #C1C169690909",
">. c #C0C06C6C0F0F",
",. c #C2C271711616",
"<. c #C2C272721616",
"1. c #C4C476761C1C",
"2. c #C4C476761E1E",
"3. c #CACA77771C1C",
"4. c #C6C67B7B2525",
"5. c #C6C67C7C2525",
"6. c #CECE7E7E2525",
"7. c #9B9B70704242",
"8. c #9E9E75754747",
"9. c #ADAD69694242",
"0. c #AAAA6D6D4040",
"q. c #AFAF74744343",
"w. c #AAAA7D7D4B4B",
"e. c #B6B679794949",
"r. c #AAAAA5A53131",
"t. c #CCCC83832E2E",
"y. c #D2D285852F2F",
"u. c #C9C985853333",
"i. c #CACA86863535",
"p. c #CACA88883838",
"a. c #CBCB8A8A3C3C",
"s. c #D3D38A8A3737",
"d. c #D1D18D8D3C3C",
"f. c #D2D2CDCD2828",
"g. c #D6D6D1D12C2C",
"h. c #E6E6E1E13C3C",
"j. c #B8B880804B4B",
"k. c #B2B296964444",
"l. c #AAAA82825555",
"z. c #BFBF84845050",
"x. c #B9B98A8A5555",
"c. c #B5B58D8D5F5F",
"v. c #BEBE8E8E5858",
"b. c #BBBB90905D5D",
"n. c #AEAE8C8C6B6B",
"m. c #CFCF8E8E4141",
"M. c #CCCC8E8E4646",
"N. c #CDCD90904343",
"B. c #CDCD90904545",
"V. c #CFCF94944B4B",
"C. c #CFCF95954B4B",
"Z. c #CFCF96964D4D",
"A. c #C6C685855555",
"S. c #D1D19A9A5252",
"D. c #D3D39B9B5656",
"F. c #D3D39C9C5555",
"G. c #D8D89E9E5656",
"H. c #D2D29D9D5858",
"J. c #E0E09A9A4B4B",
"K. c #E0E09B9B4E4E",
"L. c #DBDBA1A15A5A",
"P. c #D0D09F9F6868",
"I. c #D5D5A4A46262",
"U. c #D7D7A5A56363",
"Y. c #DADAA7A76565",
"T. c #DBDBA9A96767",
"R. c #DCDCA9A96767",
"E. c #DEDEA1A16868",
"W. c #DEDEABAB6969",
"Q. c #DFDFABAB6969",
"!. c #D4D4ADAD7F7F",
"~. c #EBEBAEAE6767",
"^. c #E1E1ADAD6B6B",
"/. c #E2E2AEAE6C6C",
"(. c #EDEDAFAF6868",
"). c #E3E3AEAE7171",
"_. c #E9E9B3B37171",
"`. c #F0F0B9B97777",
"'. c #F3F3BBBB7979",
"]. c #F6F6BDBD7B7B",
"[. c #F6F6BDBD7C7C",
"{. c #F6F6BEBE7C7C",
"}. c #F6F6BFBF7D7D",
"|. c #E5E5C4C45454",
" X c #E7E7C6C65656",
".X c #EEEECDCD5D5D",
"XX c #F6F6C1C17F7F",
"oX c #58586262B7B7",
"OX c #29294343C5C5",
"+X c #51516F6FD6D6",
"@X c #59596464E7E7",
"#X c #62626A6AEEEE",
"$X c #696983839C9C",
"%X c #7F7F8181E0E0",
"&X c #B6B6A2A29C9C",
"*X c #D8D8BDBD9A9A",
"=X c #F6F6BFBF8080",
"-X c #F6F6C0C08181",
";X c #F6F6C7C78F8F",
":X c #F8F8C6C68F8F",
">X c #F6F6CDCD8B8B",
",X c #FCFCDEDEBEBE",
"<X c #9A9A8989C1C1",
"1X c #9A9A9090C7C7",
"2X c #B2B29F9FC6C6",
"3X c #B6B6A6A6C4C4",
"4X c #86868686E8E8",
"5X c #85859191EEEE",
"6X c #8F8F9797F3F3",
"7X c #9797BEBEF6F6",
"8X c #CBCBBBBBD2D2",
"9X c #CECEBFBFDCDC",
"0X c #ACACD5D5FFFF",
"qX c #E0E0D6D6C4C4",
"wX c #E7E7D8D8CBCB",
"eX c #E0E0CBCBD0D0",
"rX c #F6F6E5E5CCCC",
"tX c #FDFDE2E2C9C9",
"yX c #FFFFE6E6D5D5",
"uX c #D4D4E1E1FBFB",
"iX c #DFDFE8E8FCFC",
"pX c #EAEAF8F8FFFF",
"aX c #F6F6FFFFFFFF",
"sX c gray100",
/* pixels */
"sXsXsXsXsXsXsX; u u u u u u u u u u u u u u u u u u u sXsXsXsXsX",
"sXsXsXsXsXsXsX; u u u u u u u u u u u u u u u u u u u sXsXsXsXsX",
"sXsXsX@ @ @ @ n @.$.9.9.=.@.X.E E s u j E E ;.9.%.E E # @ sXsXsX",
"sXsX@ u u u u -.I.Y.].].Q.I.C.' ' z u C ' ' (.].J.' ' p u @ sXsX",
"sXsX# p a f f 0.U.T.'.'.W.I.Z.] ] V p Z ] ] ~.'.K.:.:.g p # sXsX",
"u u E ' ] I.I._.].`.I.I.I.I.I.I.I.<.' 2.I.I.I.I.^.].].:.' W u u ",
"u u E ' ] I.I._.].`.I.I.I.I.I.I.I.<.' 2.I.I.I.I.^.].].:.' W u u ",
"sXsX6 T R | | *.y.s.I.I.p.5.u.I.I.B.a.i.5.5.H.I.^.].].m.a...u u ",
"sXsX@ u u u u Q ' >.I.I.2.' ,.I.I.I.I.N.' ' S.I.^.].].U.I.#.u u ",
"sXsX@ u i h h / >.1.Y.Y.{ _ [ Y.Y.Y.Y.M._ _ D.Y./.`.`.F.S.o.u u ",
"sXsX@ u p ' ' a.I.Y.].].^ u F ].].].].A.u u E.]._.I.I.] ' W u u ",
"sXsX@ u p ' ' a.I.Y.].].^ u F ].].].].A.u u E.]._.I.I.] ' W u u ",
"sXsX@ u d N.N.O.H  .Q.Q.! u A 6.6.L.Q.e.u u &.6.d.I.I.] ' W u u ",
"sXsX@ u f I.I.| u k I.I.H u l ' ' V.I.q.u u _ ' 4.I.I.] ' W u u ",
"sXsXsX< 3 j.j.G u B R.R.+.F ( 3.3.G.R.z.F F } 3.t.C.C.` ) N < < ",
"sXsXsXsXsXu u u u D ].].].].].].].].].].].].].].J.' ' p u @ sXsX",
"sXsXsXsXsXu u u u D ].].].].].].].].].].].].].].J.' ' p u @ sXsX",
"sXsXsX& , u u > + * q q q q L ].].].].b.q q q q c z z i u 2 & & ",
"sXsX. 7 5 u u :             q ].].].].l.        : u u u u y 7 7 ",
"sXsX. 7 8 ^ ^ 9   O Y Y P e U XXXXXXXXn.e e I Y t 1 1 ~ ^ S 7 7 ",
"sXsX. 7 x ].].J   r 0X0X+XOXoX>X>X>X>X&XOXOX7X0X$X    ).].7.7 7 ",
"sXsX. 7 x ].].J   r 0X0X+XOXoX>X>X>X>X&XOXOX7X0X$X    ).].7.7 7 ",
"sXsXsXsXsXv v 8.P.!.pXpX5X@X%XtXtXtXtX8X@X@XuXpXqXP.P.m v = sXsX",
"sXsXsXsXsX7 7 w.].;XaXaX6X#X4XyXyXyXyX9X#X#XiXaXrX].].x 7 . sXsX",
"sXsXsXsXsX$ $ K w.c.rXrX3X<X2XyXyXyXyXeX1X1XwXrX*Xw.w.% $ sXsXsX",
"sXsXsXsXsXsXsX$ 7 v ].].].].:XyXyXyXyX,X>X>X}.].w.7 7 sXsXsXsXsX",
"sXsXsXsXsXsXsX$ 7 v ].].].].:XyXyXyXyX,X>X>X}.].w.7 7 sXsXsXsXsX",
"sXsXsXsXsXsXsXsXsXsXx x v.].[.-X-X-X-X=X{.{.M x % sXsXsXsXsXsXsX",
"sXsXsXsXsXsXsXsXsXsX7 7 x.].].].].].].].].].v 7 $ sXsXsXsXsXsXsX",
"sXsXsXsXsXsXsXsXsXX 4 4 k..X.X.X.X X|.|.|.|.b 4 - sXsXsXsXsXsXsX",
"sXsXsXsXsX0 0 0 0 0 0 0 r.h.h.h.h.g.f.f.f.f.w 0 0 0 0 0 0 o sXsX",
"sXsXsXsXsX0 0 0 0 0 0 0 r.h.h.h.h.g.f.f.f.f.w 0 0 0 0 0 0 o sXsX"
};
#if defined ALLEGRO_WITH_XWINDOWS && defined ALLEGRO_USE_CONSTRUCTOR
extern void *allegro_icon;
CONSTRUCTOR_FUNCTION(static void _set_allegro_icon(void));
static void _set_allegro_icon(void)
{
    allegro_icon = allegico_xpm;
}
#endif