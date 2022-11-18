#include <stdio.h>
#include <string.h>
#include	"./User/config.h"
#include 	"./User/includes.h"


xdata u8 localid[ID_LENTH];//本机ID。

#if(BOARD_NO	==	10)  //测试板号	 10

	char code Serial_id[]	=	"D17E44A102A05E,D17E848950061C,D17E84A15005AB,D17E0133A2BD36,D17E8139169D06,\
													D17E44B202A001,D17E0139FAFEAB,D17E8139169006,D17E84894E54E4";
	
#elif(BOARD_NO	==	GZ_QNZ_DSJJ_KM2)  //贵州省黔南州独山剑江科目二	 49
	
	char code Serial_id[]	=	"D17E8133195407,D17E8133195405,D17E8165195AAF,D17E81CD205F9E";
	
#elif(BOARD_NO	==	SD_WF_SGJD_KM2)  //山东省潍坊市寿光金盾驾校科目二	 66

	char code Serial_id[]	=	"D17E013FB88FD6,D17E0133B89555,D17E01B2B89592,D17E0165B88FE7,D17E0165B88FF8,\
													D17E01D3B88F9C,D17E01F1B89591,D17E01F4B88DF7,D17E0144001063,D17E01A3B89549,\
													D17E0133B894FE,D17E0165B88FE8,D17E84894E54E4,D17E0144001063";

#elif(BOARD_NO	==	HB_ZJK_XH_KM2)  //河北省张家口市宣化科目二考场	 71

	char code Serial_id[]	=	"D17E0134857619,D17E0133A2BD5C,D17E016885762D,D17E01B2A2BD0C,D17E013FA2BB05,\
													D17E01D3A2BABE,D17E013985762D,D17E016885799E,D17E0134857992,D17E01348579B7,\
													D17E01448579BC,D17E01398579D3,D17E01688579C3,D17E0144857671,D17E013985767C,\
													D17E01348575F2,D17E016884295E,D17E016885767B,D17E01348579A4,D17E013984295F,\
													D17E01398579D2,D17E01688579C2,D17E01448579A8,D17E014484294F,D17E0168857984,\
													D17E016885799C,D17E0144857994,D17E0144857961,D17E0139857975,D17E0134857990,\
													D17E01398579AB,D17E0144857995,D17E01348579C8,D17E01348579B6,D17E01348575FA,\
													D17E01688579D2,D17E01448579BB,D17E016885760E,D17E01448579CD,D17E01688579D3,\
													D17E01398579E3,D17E011C0266CC,D17E01448579CC,D17E011C0266CD,D17E00D402EA43,\
													D17E0134FAFEAB,D17E01348579C7,D17E016885799D,D17E0134857991,D17E01F1B89595";	
	
#elif(BOARD_NO	==	GZ_TR_SNTN_KM2)  //贵州省铜仁思南铜南科目二	 81
	
	char code Serial_id[]	=	"D17E461B01687B,D17E45F0016881,D17E45F101688D,D17E45F201687A,D17E45F2016879,\
													D17E461B016889,D17E45EC01A1DB,D17E45EB01A1D1,D17E8407500645,D17E848950061C";
	
#elif(BOARD_NO==GZ_QNZ_DYJD_KM2)  //贵州省黔南州都匀金都科目二 84
	
	char code Serial_id[]	=	"D17EO144FAFEB8,D17EO1B2A2BD3E,D17EO1A3A2BD44,D17EO144001084,D17EO144FAFE43,\
													D17EO134FAFEB3,D17E013900114B,D17E0168001095,D17E0134001097,D17E01680010CF,\
													D17E014400111B,D17E84075005AB,D17E84A14E54E8,D17E81951D2015,D17E0144001405,\
													D17E01680010CF,D17E01680013B2,D17E01D3B88EA4,D17E0134001093,D17E81341688C5,\
													D17E013400114C,D17E01680010CF,D17E01440013AC,D17E84075005AB,D17E0144001083,\
													D17E01D3B88EA4,D17E014103788E,D17E440702A031";
	
#elif(BOARD_NO	==	SD_WF_GMCY_KM2)  //山东省潍坊市高密超越驾校科目二	    87
	
	char code Serial_id[]	=	"D17E01A3B89335,D17E0133B8930E,D17E0133B892F6,D17E01F1B89336,D17E01A3B89334,\
													D17E01B2B89320,D17E01B2B89338,D17E01F1B8931D,D17E01A3B8934D,D17E01B2B8933A,\
													D17E0133B8930F,D17E01F1B89337,D17E01F1B8931E,D17E01F1B8931C,D17E0165B88CAD,\
													D17E0133B892F5,D17E01A3B89359,D17E01A3B8934C,D17E01A3B89336,D17E01B2B89339,\
													D17E01B2B8931F,D17E01340013A3,D17E0139001361,D17E84A15005AB,D17E44A102A08E,\
													D17E817C198978,D17E01F4A2BB06,D17E44A102A5C4";

#elif(BOARD_NO	==	SD_WF_WFLY_KM2)  //山东省潍坊市陆洋驾校科目二训练	    88
	
	char code Serial_id[]	=	"D17E0134001363,D17E0139001360,D17E016800135C,D17E013FB88CF5,D17E0144001353"

#elif(BOARD_NO	==	GZ_QDN_TZQT_KM2)  //贵州省黔东南州天柱县擎天驾校科目二	    98

	char code Serial_id[]	=	"D17E45F0016869,D17E45F1016870,D17E45F0016868,D17E45F2016860,D17E461B01686B,\
													D17E45F1016871,D17EC5F311BE9C,D17EC3B109B889";


#elif(BOARD_NO	==	GZ_QX_QZ_KM2) 	//贵州省黔西黔职科目二  102

	char code Serial_id[]	=	"D17E44B201E22A,D17E440701E226,D17E44B201E218,D17E44A101E22C,D17E448901E22A,\
													D17E448901E217,D17E440701E214,D17E44A101E21A";
	
#elif(BOARD_NO	==	HB_JZK_XH_KM3) 	 //河北省张家口市宣化科目三考场  108

	char code Serial_id[]	=	"D17E0134857619,D17E0133A2BD5C,D17E016885762D,D17E01B2A2BD0C,D17E013FA2BB05,\
													D17E01D3A2BABE,D17E013985762D,D17E016885799E,D17E0134857992,D17E01348579B7,\
													D17E01448579BC,D17E01398579D3,D17E01688579C3,D17E0144857671,D17E013985767C,\
													D17E01348575F2,D17E016884295E,D17E016885767B,D17E01348579A4,D17E013984295F,\
													D17E01398579D2,D17E01688579C2,D17E01448579A8,D17E014484294F,D17E0168857984,\
													D17E016885799C,D17E0144857994,D17E0144857961,D17E0139857975,D17E0134857990,\
													D17E01398579AB,D17E0144857995,D17E01348579C8,D17E01348579B6,D17E01348575FA,\
													D17E01688579D2,D17E01448579BB,D17E016885760E,D17E01448579CD,D17E01688579D3,\
													D17E01398579E3,D17E011C0266CC,D17E01448579CC,D17E011C0266CD,D17E00D402EA43,\
													D17E0134FAFEAB,D17E01348579C7,D17E016885799D,D17E0134857991,D17E01F1B89595";

#elif(BOARD_NO	==	HB_SJZ_YH_KM2) 	 //河北省石家庄市育华驾校科目二   109

	char code Serial_id[]	=	"D17E016885762E,D17E0144857625,D17E013485761A,D17E013985762E,D17E0144857624,\
													D17E01D3A2BABD,D17E01398579ED,D17E01348579D3,D17E01F1B895A8";
	
#elif(BOARD_NO	==	GZ_QNZ_LLJD_KM2) 	 //贵州省黔南州龙里县金都驾校科目二 119

	char code Serial_id[]	=	"D17E81951D1E82,D17E01D3B88F72,D17E848950061C,D17E0165A2BB2D,D17E0133A2BD35";	
	
#elif(BOARD_NO	==	GZ_QDN_JPLX_KM2) 	  //贵州省黔东南州锦屏县龙翔机动车驾驶培训有限公司科目二 120

	char code Serial_id[]	=	"D17E45EB017EFB,D17E45F3017EE6,D17E45EB017EFC,D17E45EA017EF1,D17E45F3017EE7,\
													D17E45EC017EFC,D17E461B0167D6,D17E45EA017EF0";	
	
#elif(BOARD_NO	==	HN_YZ_JJZD_KM2) 	  //湖南省永州市交警支队支队科目二  125;

	char code Serial_id[]	=	"D17E84894E54E4,F527448900F162";			
	
#elif(BOARD_NO	==	HB_SJZ_YSPA_KM2) 	  //河北省石家庄市元氏平安驾校科目二 127

	char code Serial_id[]	=	"D17E01A3A2BCED,D17E016EA2BCF1,D17E01B2A2BD0D,D17E0133A2BD05,D17E45F201668F,\
													D17E461B016689,D17E45F101668F,D17E01B2A2BD0D";			
		
#elif(BOARD_NO	==	GZ_TR_XJB_KM2) 	 	 //贵州省铜仁市许家坝科目二考场  128

	char code Serial_id[]	=	"D17E461B01687B,D17E45F0016881";		
	
#elif(BOARD_NO	==	GZ_QNZ_HSJD_KM2) 	 //贵州省黔南州惠水金都科目二 131

	char code Serial_id[]	=	"D17E45EB017F7E,D17E45EC017F7C,D17E45EA017F6D,D17E45F3017F67,D17E00D402F3EC,\
													D17E8165195A92,D17E81331954D0,D17E8133195406,D17E81CD205EE2,D17E44B201E279,\
													D17E0141038263,D17E81CD205EE2,D17E00D402F3EC,D17E8165195A92,D17E8133195406";	
	
#elif(BOARD_NO	==	GZ_QDN_TZRH_KM2) 	 //贵州省黔东南州天柱县嵘华科目二   133

	char code Serial_id[]	=	"D17E84894E54E4,D17E81951D1C07,D17E8489500626,D17E84B24E54E4,D17E84A15005F2,\
													D17E84B24E54E4,D17E44A101E1BB,D17E448901E1B8,D17E0168001399,D17E44A1029E67,\
													D17E8139169C9C,D17E8489500626,D17E0139FDB367,D17E8139169C9C,D17EC5F0044E51";		
	
#elif(BOARD_NO	==	NM_CF_AQTD_KM2_3)  //内蒙古赤峰市阿旗通达驾校科目二、三 134

	char code Serial_id[]	=	"D17E840750063E,D17E8407500650,D17E8407500644,D17E8407500624,D17E8407500626,\
													D17E84B2500617,D17E440702A6CF,D17E44A102A07D,D17E440702A6FC";	

#elif(BOARD_NO	==	NM_CF_YBSHD_KM3)  	//内蒙古赤峰市元宝山赫达驾校科目三 135

	char code Serial_id[]	=	"D17E813D573887,D17E84B24E54BF,D17E84B25005FB,D17E84A1500643,D17E84A1500622,\
													D17E84A1500644,D17E84A1500623,D17E84A150064E,D17E848950058B,D17E81CD206163,\
													D17E81F81AD996,D17E81951D2014,D17E84B25005FC,D17E813D573887,D17E44B202A07F,\
													D17E448902A08B";	

#elif(BOARD_NO	==	GZ_QNZ_WAJF_KM2)  	//贵州省黔南州瓮安江沣科目二 136

	char code Serial_id[]	=	"D17E45F2016871,D17E45F0016879,D17E461B01687F,D17E45F3017F5D,D17E45EB017F74,\
													D17E81951D1E81,D17E44B201E1AA,D17E01A3A2BD44";	

#elif(BOARD_NO	==	GZ_QNZ_FQJC_KM2_3)  //贵州省黔南州福泉市锦程驾校科目二 三 140

	char code Serial_id[]	=	"D17E45F0016856,D17E45F201684D,D17E45F101685E,D17E45F101685D,D17E45F0016855,\
													D17E461B01685A,D17E84075005F1,D17E84B24E54E5,D17E45F30281BA,D17E45F30281BB,\
													D17E440701E186,D17E448901E189,D17E44A101E18D,D17E44B201E18B,D17E440701E185,\
													D17E44B201E18A,D17E448901E188,D17E44A101E18C,D17E440701E184,D17E45EB02821A,\
													D17E44B201E189,D17E44A101E1C4,D17E45EA028219,D17E45F0026EAD";

#elif(BOARD_NO	==	GZ_QDN_ZYJT_KM2_3)  //贵州省黔东南镇远金通驾校科目二、三  141

	char code Serial_id[]	=	"D17E45EB017F7A,D17E45EA017F62,D17E45EB017F75,D17E45EC017F73,D17E45F3017F5C,\
													D17E45F001684C,D17E461B016850,D17E45F001684D,D17E45F001684B,D17E461B016852,\
													D17E45EA017F63,D17E813D573886,D17E45EC017F72,D17E461B016851,D17E45EB017F73,\
													D17E45EA017F61,D17E45F2016846,D17E45F2016845,D17E45F00167D1,D17E45F10167D7,\
													D17E45F00167D0,D17E461B0167D5,D17E45F20167CD,D17E45F20167CE,D17E45F1016854,\
													D17E45F1016855,D17E44B201E20C,D17E45EC017F6F,D17E45F001681B,D17E014400111C,\
													D17EC5F104D6BA,D17EC5F004D229,D17E84A14E54E8,D17EC5F204D28C,D17EC62E0356A8,\
													D17EC5F104D6BC,D17EC5F004D22C,D17E45F0016865,D17EC5F30658DD,D17E4489029FEC,\
													D17E8168169C75,D17E016800114D,D17E0168001095";

#elif(BOARD_NO	==	GZ_QNZ_QYDQS_KM3) 	 //贵州省黔南黔云栋青树金都科目三  142
	
	char code Serial_id[]	=	"D17E461B016853,D17E440701E193,D17E44A101E199,D17E448901E196,D17E448901E195,\
													D17E44A101E19A,D17E440701E192,D17E44A101E1B9,D17E44B201E198,D17E448901E27B,\
													D17E44B201E27B,D17E44A101E260,D17E440701E25A,D17E44B201E260,D17E44A101E262,\
													D17E448901E25E,D17E44A101E261,D17E440701E25B,D17E44B201E25F,D17E448901E25F,\
													D17E448901E209,D17E44A101E201,D17E448901E1FF,D17E440701E1FC,D17E440701E1FD,\
													D17E44B201E1FF,D17E448901E200,D17E44B201E201,D17E44B201E200,D17E44A101E202,\
													D17E440701E1FB,D17E440702A031,D17E44A1029FF3,D17E01340013BC,D17E4489029FEC,\
													D17E8168169C75";

#elif(BOARD_NO	==	GZ_QDN_TZRH_KM3) 	  	//贵州省黔东南州天柱县嵘华驾校科目三 143
	
	char code Serial_id[]	=	"D17E84B24E34E5,D17E84B24E54E5,D17E84894E54E4,D17E81E7196C13,D17E45F3017F68,\
													D17E45EB017F80,D17E45EA017F6F,D17E45EB017F7F,D17E817C198978,D17E0144001084,\
													D17E8168169CDF,D17E81E7196C13,D17E440701E1A1,D17E440701E225,D17E44B201E1A6,\
													D17E8139169C9C,D17E0139FDB367,D17E0168001075,D17E8139169D05,D17EC5F1045292";

#elif(BOARD_NO	==	GZ_GY_YG_KM2) 	  		//贵州省贵阳市阳光驾校科目二  151
	
	char code Serial_id[]	=	"D17E461B016865,D17E45F201685B,D17E45F0016862,D17E45F00168B2,D17E461B016866,\
													D17E45F201685A,D17E45F2016866,D17EC62E02089F,D17E45F0016862";

#elif(BOARD_NO	==	HN_YZ_XTYG_KM2) 	  	//湖南省永州市新田阳光驾校科目二152
	
	char code Serial_id[]	=	"D17E84B2500588,D17E84A15005AA,D17E84B250054A,D17E84B950061B,D17E8489500551,\
													D17E84B9500601,D17E84A1500624,D17E84A1500567,D17E848950058C,D17E84A1500568,\
													D17E84895005FF,D17E848950058D,D17E848950061D,D17E848950061B,D17E84B9500601,\
													D17E8489500601,D17E84B2500621,D17E44B202A6C1,D17E44B202A6C2,D17E448902A6BD,\
													D17E440702A6C0,D17E84A1500569,D17E44A102A6C6,D17E84B2500618,D17E448902A0CB";
	
#elif(BOARD_NO	==	GZ_QDN_JPLX_KM3) 	  	//贵州省黔东南州锦屏县龙翔驾校科目三153
	
	char code Serial_id[]	=	"D17E448901E194,D17E448901E193,D17E44A101E198,D17E44A101E20D,D17E45F2016885,\
													D17E45EA017EF2,D17E45EC017F7D,D17E45EA017F6E,D17E01F4B88DC9,D17E0133B894FF,\
													D17E0165B88FBB,D17E0165B88FBC,D17E01A3B8959F,D17E01F4B88DCA,D17E01A3B8959E,\
													D17E01F1B8958D,D17E0133B894FD,D17E0133B89551,D17E01B2B8953C,D17E01680012DC,\
													D17E01D3B88F71";

#elif(BOARD_NO	==	GZ_QDN_BJHZ_KM3) 	  	 //贵州省黔东南州毕节赫章科三154
	
	char code Serial_id[]	=	"D17E448901E194,D17E448901E280,D17E44B201E27F,D17E440701E220,D17E44A101E1A5,\
													D17E440701E27D,D17E44A101E1D8,D17E44B201E21D,D17E44A101E282,D17E448901E193,\
													D17E448901E1A2,D17E440701E26E,D17E440701E219,D17E448901E27F,D17E44B201E1A4,\
													D17E44A101E198,D17EC5EC03330F";
	
#elif(BOARD_NO	==	GZ_QNZ_PTDF_KM3) 	  	 //贵州省黔南州平塘县东方驾校科目三156
	
	char code Serial_id[]	=	"D17E440701E249,D17E44B201E202,D17E448901E202,D17E440701E1FE,D17E44B201E258,\
													D17E44A101E203,D17E44B201E280,D17E448901E255,D17E44A101E22A,D17E448901E281,\
													D17E0168001142,D17E01B2B89597,D17E01F1B89594,D17E45EC028209,D17E81331954CF,\
													D17E44B201E1B9,D17E01B2A2BD51,D17E45F001688C,D17E0133B89559,D17E440701E249,\
													D17E44B201E280,D17E0144FAD64D";
	
#elif(BOARD_NO	==	GZ_GY_KC_KM2_3) 	  	 //贵州省贵阳市凯城汽车驾驶培训有限公司科目二 三  157
	
	char code Serial_id[]	=	"D17E01A3A2BCED,D17E016EA2BCF1,D17E01B2A2BD0D,D17E0133A2BD05,D17E461B01681B,\
													D17E45F2016812,D17E461B016855,D17E45F101681F,D17E461B016819,D17E45F0016819,\
													D17E461B01681A,D17E45F2016813,D17E461B0167D4,D17E45F10167D6,D17E81331954CF,\
													D17E45F20167CC,D17E45F001681B,D17E45EB017F71,D17E45F3017F59,D17E45EC017F6F,\
													D17E45EA017F5F,D17E45F3017F66,D17E45EB017F7D,D17E448901E1A1,D17E440701E19E,\
													D17E44B201E1A2,D17E44A101E1A4,D17E44B201E1A3,D17E44A101E151,D17E448901E1A0,\
													D17E45F101686B,D17E461B016893,D17E45F0016863,D17E461B016868,D17E461B016867,\
													D17E45F101686C,D17E45F10167D6,D17E45F20167CC,D17E461B0167D4,D17E45F001681B,\
													D17E45EB017F71,D17E45EB017F7D,D17E45EA017F5F,D17E45EC017F6F,D17E45F3017F59,\
													D17E45F3017F66,D17E45F00167CF,D17E44A101E1C9,D17E448901E1C6,D17E44A101E1CA,\
													D17E44A101E1CC,D17E448901E1C9,D17E440701E1C3,D17E448901E1C7,D17E44B201E1C7,\
													D17E44B201E1C8,D17E440701E1C2,D17E44A101E20C,D17E44B201E20C,D17E45F10167D6,\
													D17E448901E1A0,D17E44B201E1CA,D17E44A101E20D,D17E44B201E225,D17E440701E252,\
													D17E44A101E284,D17E440701E27B,D17E448901E228,D17E440701E27C,D17E44A101E283,\
													D17E44B201E27E,D17E44A101E19E,D17E448901E1D0,D17E448901E1A3,D17E45F30281BA,\
													D17E448901E172,D17E45F30281BC,D17E45F2026ED1,D17E448901E256,D17E440701E254,\
													D17E44A101E259,D17E448901E203,D17E448901E27A,D17E44A101E258,D17E440701E278,\
													D17E44B201E204,D17E44A101E27D,D17E45EB017F7D,D17E45EA017F5F,D17E44A101E24F,\
													D17E44A101E27E,D17E440701E277,D17E448901E228,D17E440701E277";
	
#elif(BOARD_NO	==	GZ_GY_JYCX_KM2) 	  	 //贵州省贵阳市金阳诚信驾校科目二        158
	
	char code Serial_id[]	=	"D17E440701E1FF,D17E448901E279,D17E44B201E203,D17E44B201E257,D17E440701E253,\
													D17E440701E276,D17E44B201E27A,D17E44A101E204,D17E44A102A013";
	
#elif(BOARD_NO	==	GZ_QNZ_LPXSD_KM2) 	  	//贵州省黔南州荔波县兴盛达驾校科目二   159
	
	char code Serial_id[]	=	"D17E01F1B89535,D17E45F2016886,D17E01A3B895BC,D17E0133B8956B,D17E8168169CDF";
	
#elif(BOARD_NO	==	GZ_QDN_KLGL_KM2) 	  	 //贵州省黔东南州凯里市贵龙驾校科目二  160
	
	char code Serial_id[]	=	"D17E461B016887,D17E45F101688C,D17E45F0016882,D17E45F201687A,D17E461B016889,\
													D17E45F2016878";
	
#elif(BOARD_NO	==	SD_WF_AQAJ_KM2) 	  	 //山东潍坊安丘安驾科目二  162
	
	char code Serial_id[]	=	"D17EC5F3044F32,D17EC5EB044FA7,D17EC5EC045034,D17EC5EB044FA5,D17EC5F3044F31,\
													D17EC5EC045036,D17EC5EB044FA6,D17EC5F3044F30,D17EC5EC045035,D17EC5F2044EA1,\
													D17EC62E032222,D17EC5F0044FA9,D17EC62E03239A";
	
#elif(BOARD_NO	==	GZ_GY_ZJDLP_KM2) 	  	 //贵州省贵阳市智杰驾校灯笼坡分校科目二  164
	
	char code Serial_id[]	=	"D17E45F0016866,D17E440701E207,D17E45F201685D,D17E461B016869,D17E45F101686E,\
													D17E45F101686D";
	
#elif(BOARD_NO	==	GZ_QNZ_FQXQ_KM3) 	  	 //贵州省黔南州福泉市鑫泉驾校科目三  165
	
	char code Serial_id[]	=	"D17E44A101E176,D17E44B201E175,D17E44A101E177,D17E440701E16F,D17E448901E172,\
													D17E44B201E174,D17E440701E16E,D17E440701E170,D17E461B026EBA,D17E44B201E171,\
													D17E448901E171,D17E45F1026EDE,D17E45F2026ED0,D17E00D402F3EC,D17E8165195A92,\
													D17E81331954D0,D17E8133195406,D17E81CD205EE2,D17E44B201E279,D17E45F101686A,\
													D17E461B016854,D17E45F1016858,D17E44B2029FFE,D17E440701E1FE";
	
#elif(BOARD_NO	==	GZ_GY_YMG_KM2) 	  	 //贵州省贵阳市永铭贵驾校科目二  168
	
	char code Serial_id[]	=	"D17E45F1016858,D17E45F2016848,D17E45F0016850,D17E461B016854,D17E45F2016849,\
													D17E45F001684F,D17EC5F3033181";
	
#elif(BOARD_NO	==	GZ_QNZ_SDXX_KM2) 		//贵州省黔南州三都县兴鑫驾校科目二   170
	
	char code Serial_id[]	=	"D17E45F2016865,D17E461B016871,D17E45F001686D";
	
#elif(BOARD_NO	==	GZ_QNZ_HSQL_KM2) 	 //贵州省黔南州惠水黔岭科目二（改造） 171
	
	char code Serial_id[]	=	"D17E45F2016889,D17E45F001688E,D17E461B016894,D17E45F101689C,D17E461B016895,\
													D17E45F101689B";
	
#elif(BOARD_NO	==	GZ_QDN_TZQT_KM3) 	 //贵州省黔东南州天柱县擎天驾校科目三    172
	
	char code Serial_id[]	=	"D17E448901E27C,D17E44A101E19B,D17E44B201E1AB,D17E44A101E197,D17E448901E1AA,\
													D17E44A101E1AE,D17E440701E1A7,D17E44B201E195,D17E440701E208,D17E440701E18F,\
													D17E44B201E27C,D17E44A101E27F,D17E448901E20B,D17E448901E192,D17E440701E1A5,\
													D17E440701E190,D17E440701E279,D17E44A101E1AC,D17E440701E1A6,D17E448901E1A9,\
													D17E440701E15A,D17E44A101E1AD,D17E44B201E1AC,D17E44B201E20D,D17E44B201E196,\
													D17E440701E191,D17E01A105CFFE";
	
#elif(BOARD_NO	==	GZ_QNZ_HSSX_KM3) 	 //贵州省黔南州惠水县顺行驾校科目三      173
	
	char code Serial_id[]	=	"D17E44B201E1BA,D17E448901E1B7,D17E440701E1B5,D17E440701E1A8,D17E448901E1B9,\
													D17E44B201E1AD,D17E44A101E1AF,D17E448901E1AC,D17E44B201E19E,D17E44A101E19F,\
													D17E448901E19C,D17E440701E199,D17E44B201E19F,D17E44A101E1A0,D17E440701E198,\
													D17E448901E19B,D17E4489029FDD,D17E4407029FB9,D17E440702A066,D17E440702A0A4,\
													D17E44B2029FD4,D17E44A1029FF3,D17E440702A063,D17E448902A058,D17E44B2029E5B,\
													D17E44B202A04C,D17E4489029FDE";
	
#elif(BOARD_NO	==	GZ_GY_QF_KM3) 	  //贵州省贵阳市黔丰驾校科目三   174
	
	char code Serial_id[]	=	"D17E448901E271,D17E44A101E274,D17E44A101E1C5,D17E440701E1A2,D17E44B201E1C3,\
													D17E44B201E271,D17E44B201E256,D17E44A101E257,D17E44B201E1A7,D17E448901E1C2,\
													D17E440701E1BF,D17E44B201E255,D17E440701E26E,D17E440701E251,D17E448901E254,\
													D17E44A101E281,D17E448901E27E,D17E440701E27B,D17E440701E27A,D17E44A101E22A,\
													D17E448901E228,D17E44B201E27D,D17E44A101E280,D17E440701E1BE,D17E440701E224,\
													D17E44A101E256,D17E44B201E229,D17E448901E27D,D17E448901E253,D17E448901E1A5,\
													D17E44A101E283,D17E440701E27C,D17E44B201E27E,D17E448901E27D,D17EC5F2045047";
	
#elif(BOARD_NO	==	GZ_BJ_HZZH_KM2) 	 //贵州省毕节市赫章县众汇科目二智能化考试服务有限责任公司 175
	
	char code Serial_id[]	=	"D17E01340013BB,D17E440701E225,D17E44A101E22B,D17E448901E229,D17E448901E194,\
													D17E440701E194,D17E44B201E199,D17E01340013BC,D17E01340013BB,D17E81341688C5,\
													D17E84B24E54E5,D17E84075005F0,D17E84075005F0,D17EC61B0E0B91,D17EC62E0EF0ED";
	
#elif(BOARD_NO	==	GZ_QDN_TZYY_KM2) 	 //贵州省黔东南州天柱县友谊驾校科目二      177
	
	char code Serial_id[]	=	"D17E45F3017EE8,D17E45EB017EFC,D17E45F001686E,D17E45F2016847,D17E45EC017EFC,\
													D17E45F001684E";
	
#elif(BOARD_NO	==	GZ_QNZ_QC_KM2) 	  ``//贵州省黔南州惠水启程机动车驾驶培训有限公司科目二 178
	
	char code Serial_id[]	=	"D17E8195102015,D17E81F81AD995,D17E45F1016899,D17E461B016892,D17E45F001688D";
	
#elif(BOARD_NO	==	GZ_QNZ_DYHOY_KM2) 	//贵州省黔南州都匀市宏源驾校科目二179
	
	char code Serial_id[]	=	"D17E45F0016849,D17E45F2016842,D17E45F1016852,D17E461B01684E";
	
#elif(BOARD_NO	==	GZ_QNZ_PTXSD_KM2) 	   	//贵州省黔南州平塘县兴盛达驾校科目二 180
	
	char code Serial_id[]	=	"D17E461B016880,D17E461B016883,D17E461B01687E,D17E45F1016883,D17EC5F10335D8";
	
#elif(BOARD_NO	==	GZ_GY_SF_KM2) 	 			//贵州省贵阳市时发驾校科目二 184
	
	char code Serial_id[]	=	"D17E45EC017F71,D17E45EA017F60,D17E45EB017F72,D17E45F3017F5A,D17E45EC017F70,\
													D17E45F201685E,D17E461B016869";
	
#elif(BOARD_NO	==	SD_JN_MY_KM2_3) 	  	//山东省济南市明苑科目二考场    185
	
	char code Serial_id[]	=	"D17E0144FDB377,D17E0134FDB386,D17E0139FDB367,D17E0168FDB35A,D17E0139FDB366,\
													D17E0144FDB376,D17E0134FDB385,D17E0168FDB359,D17E0144FB02DB,D17E0168FB02DD,\
													D17E84074E542E,D17E84894E542E,D17E84A14E5433,D17E81DC1765E8,D17E84B24E542F,\
													D17E84894E542C,D17E84A14E5432,D17E84894E542D,D17E84B24E5430,D17E84074E542D,\
													D17E84B24E5460,D17E84894E545F,D17E84A14E5466,D17E84074E545F,D17E84B24E5449,\
													D17E84074E5460,D17E81DC1765E7,D17E84B24E5461,D17E84A14E5465,D17E84A14E544D,\
													D17E81E7177C86,D17E8133177501,D17E84894E545E,D17E8133177502,D17E81E7177C88,\
													D17E84074E542E,D17E8133177503,D17E81E7177C87,D17E81E7177C85,D17E81DC1765E5,\
													D17E81DC1765E6,D17E84B24E5138,D17E84894E5136,D17E84A14E5152,D17E84B24E533D,\
													D17E84B24E5139,D17E84A14E5153,D17E84074E5131,D17E84074E545E,D17E84A14E5464,\
													D17E0134FAFE66,D17E84894E5135,D17E84894E5041,D17E0165B88EFD,D17E01D3B88EB7,\
													D17E0144001396,D17E013FB88EF6,D17E0165B88EFC,D17E013FB88EE5,D17E0144001070,\
													D17E01D3B88EB8,D17E01F4B88D08,D17E0144FB033F,D17E0139FB0353,D17E84A14E5153,\
													D17E84074E549F,D17E84074E545E,D17E0139001430,D17E0139FB0353,D17E81E7197043,\
													D17E84074E555C,D17E01F4B88D08,D17E0168FB0341,";
	
#elif(BOARD_NO	==	GZ_QNZ_FQQY_KM2) 	   //贵州省黔南州福泉市骐源驾校科目二      186
	
	char code Serial_id[]	=	"D17E45F0016878,D17E45F2016864,D17E45F1016875,D17E45F001686C";
	
#elif(BOARD_NO	==	GZ_QNZ_WAYL_KM2) 	 		//贵州省黔南州瓮安县云岭驾校科目二  188
	
	char code Serial_id[]	=	"D17E45F1016884,D17E45F1016885,D17E45F001687A,D17E45F2016872,F527C4B200E088,\
													D17EC5F2033286";

#elif(BOARD_NO	==	GZ_QNZ_SDSS_KM2) 	 		//贵州省黔南州三都山水科二  189
	
	char code Serial_id[]	=	"D17E45F1016877,D17E461B016870,D17E45F1016876,D17E45F2016866,D17E45F201685C,\
													D17E45F201685C";

#elif(BOARD_NO	==	GZ_QNZ_QYJD_KM2) 	  //贵州省黔南州金都黔云科二    190
	
	char code Serial_id[]	=	"D17E45F001684A,D17E45F2016843,D17E461B01684F,D17E45F1016853,D17E81341688C5,\
													D17E013400114C,D17E0134001097,D17E01340010CE,D17E01680013B2,D17E01680013BZ";
	
#elif(BOARD_NO	==	GZ_GY_KYXT_KM2) 	    //贵州省贵阳开阳新天科目二   192
	
	char code Serial_id[]	=	"D17E016541E8B4,D17E01F441E8B8,D17E01F441E947,D17E01681CF408";
	
#elif(BOARD_NO	==	GZ_GY_XFXT_KM2) 	    //贵州省贵阳市息峰县新天驾校科目二 194
	
	char code Serial_id[]	=	"D17E01441CEEEC,D17E01391CEEFC,D17E01341CEED7,D17E01391CEEF4";
	
#elif(BOARD_NO	==	GZ_QNZ_CS_KM2) 	    //贵州省黔南州长顺驾校科目二考场   195
	
	char code Serial_id[]	=	"D17E01D341E899,D17E01D341E873,D17E01F441E8B7,D17E013907F6EB,D17E01391CF420,\
													D17EC5F3044F32,F527C48911A363,F527448900F162";

#elif(BOARD_NO	==	GZ_QNZ_HSXS_KM3) 	  	//贵州省黔南惠水鑫盛科目三   196
	
	char code Serial_id[]	=	"D17E0133B89301,D17E01F4B88D00,D17E01390012DE,D17E01F4B88CF7,D17E0165B88EE9,\
													D17E81951D1C07,D17E44B201E1AA,D17E44A101E19E,D17E44B201E19D,D17E448901E1D1,\
													D17E44B201E1D3,D17E440701E1CE,D17E440701E1CD,D17E44B201E1D2,D17E448901E1D0,\
													D17E44A101E1D4,D17E448901E1A3,D17E44B201E1A5,D17E44A101E1A7,D17E448901E1A4,\
													D17E448901E228,D17E44B201E27D,D17E44A101E280,D17E440701E1BE,D17E440701E224,\
													D17E8134168857,D17E8139169C9D,D17E01441CF409,D17E016EA2BCEF";
	
#elif(BOARD_NO	==	TJ_XD_KM3) 	  				//天津市先达驾校科目三考场    197
	
	char code Serial_id[]	=	"D17E0134FAFEB2,D17E016EA2BD47,D17E0168FAFEA5,D17E01A3A2BD33,D17E0144FAFE46,\
													D17E0133A2BD48,D17E01F4A2BB07,D17E0139FAFEC7,D17E0168FAFD55,D17E0144FAFE98,\
													D17E0134FAFEB1,D17E0139FAFD4E,D17E0144FAFD45,D17E0168FAFE79,D17E01B2A2BD64,\
													D17E0139FAFEC8,D17E01B2A2BD52,D17E0168FAFEC8,D17E0133A2BD44,D17E01348579C6,\
													D17E013FB88FD5,D17E0133A2BD4B,D17E01F4B88DF6,D17E01B2B8953B,D17E01B2B89345,\
													D17E0133B89318,D17E01F1B89341,D17E01B2B89344,D17E01F1B89327,D17E01B2B8931E,\
													D17E01A3B89358,D17E01F1B89340,D17E01B2B89343,D17E0133B892FF,D17E01B2B8932A,\
													D17E01F1B89328,D17E01B2B8932B,D17E01A3B89340,D17E0133B89300,D17E013FB88FA9,\
													D17E01A3B8933F,D17E013FB88FAB,D17E01A3B89357,D17E01440012D3,D17E0133A2BD36,\
													D17E01D3B88F9B,D17E0165B88FE6,D17E012C02CC65";
	
#elif(BOARD_NO	==	SD_RZ_SJ_ZNC) 	 		//山东省日照顺吉驾校智能培训车 198
	
	char code Serial_id[]	=	"D17E0168FAFE7A,D17E012C02D63C,D17E0144FAFE6C,D17E0139FAFE7A,D17E0168FAFE7B,\
													D17E01D3B88EB8,D17E01F4B88D07";

#elif(BOARD_NO	==	GZ_GY_DHY_KM2) 	 		//贵州省贵阳大关云顺达科目二   199
	
	char code Serial_id[]	=	"D17E01F1B8958B,D17E0133B89552,D17E01F1B895A9,D17E01A3B895A0,D17E01448579CB,\
													D17E01A3B895B7,D17E45F0016866,D17E45F201685D,D17E461B016869,D17E45F101686E,\
													D17E45F101686D,D17E45F0016865,D17E01B2B8958D,D17E44A101E22B,D17EC5F311BE9D";

#elif(BOARD_NO	==	GZ_QNZ_DSXSD_KM2) 	//贵州省黔南州独山兴盛达科目二  200 
	
	char code Serial_id[]	=	"D17E01398579D3,D17E016800112A,D17E013400112A,D17E0139001128,D17E016800112B,\
													D17E014400111C,D17E01390013B9";
	
#elif(BOARD_NO	==	GZ_QNZ_DSXY_KM2) 	  //贵州省黔南州独山县兴宇驾校科目二  201
	
	char code Serial_id[]	=	"D17E01B2B8958E,D17E45F0016864,D17E45F101689A,D17E45F001688F";
	
#elif(BOARD_NO	==	GZ_QNZ_GDWT_KM2) 	//贵州省黔南贵定万通驾校科目二		202
	
	char code Serial_id[]	=	"D17E0133B89550,D17E01B2B895AA,D17E0134FAFE91,D17E01F1B8958C,D17E013FB88FAA,\
													D17E448902A6E0,D17E0139FAFEAB";
	
#elif(BOARD_NO	==	GZ_QNZ_GDDC_KM3) //贵州省黔南州贵定县东成驾校科目三 204
	
	char code Serial_id[]	=	"D17E01A3B8954A,D17E01B2B89595,D17E0133B89301,D17E01F1B89594,D17E01398579D3,\
													D17E01448579D8,D17E01D3B88F9D,D17E0133B89559,D17E01F1B89342,D17E01F1B89335,\
													D17E01B2B89597,D17E011C0266CE,D17E0139FAFECC,D17E0134001416,D17E01680010D1,\
													D17E0134001075,D17E01340010CB,D17E014400107F,D17E013900108B,D17E0144001133,\
													D17E01D3B88F90,D17E01390010CD,D17E0168001096,D17E01440010C1,D17E01440013AB,\
													D17E0134001416,D17E01440010CD,D17E013400138C,D17E016800135B,D17E01440013AB,\
													D17E01B2A2BD51,D17E0134001141,D17E0139001140,D17E0133B89301,D17E016800114C,\
													D17E0144001352,D17E014400113E,D17E0139001090,D17E01340012EF,D17E0133A2BD04,\
													D17E01440013C2,D17E01390010CD,D17E01390012EC,D17E01390013A0,D17E81951D1E01,\
													D17E01440010C0,D17E84B25005CA,D17E0134001097";
	
#elif(BOARD_NO	==	HN_YZ_NYZN_KM2) 	 		//湖南省永州宁远忠南驾校科目二 205	
	
	char code Serial_id[]	=	"D17E0165B88CAA,D17E013FB88C9B,D17E01D3B88C80,D17E01D3B88C7F,D17E01F1B89329,\
													D17E013FB88C9D,D17E01D3B88C81,D17E013FB88C9C,D17E01A3B89341,D17E0165B88CAC,\
													D17E013FB88C9E,D17E0165B88CAB,D17E01680012E9,D17E01440012DF,F405011B0169CE";
	
#elif(BOARD_NO	==	GZ_QDN_ZYQXJT_KM2) 		//贵州省黔东南镇远清溪金通科目二 206
	
	char code Serial_id[]	=	"D17E01D3B88EA3,D17E013900139F,D17E014400111C,D17E013900106F,D17E01390010CD,\
													D17E016800139A,D17EC62E0356A9";
	
#elif(BOARD_NO	==	SD_RZ_LXKT_KM2) 	  	//山东省日照莒县坤涛科目二训练 207
	
	char code Serial_id[]	=	"D17E0144001071,D17E0134001083,D17E0168001083,D17E013900142F";
	
#elif(BOARD_NO	==	SD_JN_YSJX_KM2) 		 //山东省济南市影山俊翔科目二训练 208
	
	char code Serial_id[]	=	"D17E0134001433,D17E0144001422,D17E0144001399,D17E01390013A1,D17E01340013A4,\
													D17E0168001426,D17E013FB88EE6";
	
#elif(BOARD_NO	==	TJ_JHDS_KM3) 				//天津市静海都顺驾校科目三考场 209
	
	char code Serial_id[]	=	"D17E01440012E1,D17E01340012F0,D17E01440012E0,D17E813D573721,D17E81651958FE,\
													D17E817C198801,D17E81F81AD82F,D17E817C1987FF,D17E813D573F22,D17E013FB88ED3,\
													D17E81F81AD830,D17E01390013D1,D17E817C198888,D17E81F81AD82E,D17E813D573723,\
													D17E81F81AD831,D17E01390012EB,D17E01340012E0,D17E817C19897A,D17E81E7196D8F,\
													D17E81951D1D87,D17E81951D1D89,D17E81F81AD997,D17E81951D1D88,D17E817C198800,\
													D17E01340012E1,D17E01390012DD,D17E81951D2077,D17E813D5738C6,D17E81331956CA,\
													D17E817C19899D,D17E813D5738AA,D17E81F81AD9B9,D17E81331953D4,D17E81331953D5,\
													D17E81E7196D92,D17E81E7196D90,D17E81951D1D8A,D17E8165195A93,D17E817C19899E,\
													D17E81F81AD9BB,D17E813D5738AB,D17E01440012D2,D17E813D573722,D17E0165B88EE8,\
													D17E013FB88ED2,D17E8168169C72,D17E81E719701C";
	
#elif(BOARD_NO	==	GZ_LPS_KD_KM3) 				//贵州六盘水凯达驾校科目三 210
	
	char code Serial_id[]	=	"D17E81951D1DBB,D17E8133195691,D17E81CD205EE0,D17E817C1989BB,D17E81E7196DBD,\
													D17E81CD205EE1,D17E8133195664,D17E81E7196E07,D17E81F81AD9D6,D17E01F1B89594,\
													D17E84B24E54E3,D17E81CD206139,D17E81E7196DDE,D17E813D5738C7,D17E81F81AD9BA,\
													D17E81E7196DBF,D17E81951D1DBA,D17E01440012D3,D17E01680012DB,D17E01440012D1,\
													D17E81E7196E86,D17E81331953D6,D17E81951010BB,D17E81E7196D91,D17E81E719707A,\
													D17E84074E54E4,D17E81E7196DBE,D17E817C198979,D17E0139001140,D17E84074E54E3,\
													D17E84895005CF,D17E01680012DA,D17E84895005CF,D17E84075005F1";
	
#elif(BOARD_NO	==	SD_TA_DCBFS_KM2) 	  	//山东泰安市东成县白佛山驾校科目二训练   211
	
	char code Serial_id[]	=	"D17E01F4B88D09,D17E01390013A7";
	
	
#elif(BOARD_NO	==	GZ_QNZ_LLXX_KM2) 			 //贵州省黔南州龙里兴鑫科目二   212
	
	char code Serial_id[]	=	"D17E84B2500587,D17E8165195A71,D17E85A14E54E7,D17E84894E54E3,D17E8165195A72,\
													D17E84A14E54E7";
	
#elif(BOARD_NO	==	SD_JN_LS_KM2) 		 			//山东省济南市路舜驾校科目二训练  213
	
	char code Serial_id[]	=	"D17E0134FAFE65,D17E84894E54E7,D17E01D3B88EB6,D17E0168FAFE8C,D17E0134FAFE64,\
													D17E0165B88EFB,D17E84B24E54E8,D17E013FB88EE6";
	
#elif(BOARD_NO	==	GZ_LPS_DA_KM2) 	  			//贵州省六盘水达安驾校科目二考场  214
	
	char code Serial_id[]	=	"D17E8168169C74,D17E8139169C9B,D17E8168169C73,D17E8134168858";
	
#elif(BOARD_NO	==	HN_YZ_QY_KM2) 				 //湖南省永州市祁阳科目二考场        215
	
	char code Serial_id[]	=	"D17E44A102A6FA,D17E44B202A6E6,D17E44A102A6E8,D17E44B202A6E4,D17E440702A6E3,\
													D17E448902A6DF,D17E44B202A6F5,D17E440702A6E4,D17E448902A6F1,D17E44A102A6EA,\
													D17E44A102A6E9,D17E440702A6F5,D17E0133A2BD06,D17E448902A6F0,D17E440702A6F4,\
													D17E44A102A6F5,D17E44A102A6F9,D17E448902A6BC,D17E44A102A6C5,D17E44B202A6F6,\
													D17E44B202A6C0,D17E440702A6BF,D17E44B202A04D,D17E44B2029FE1,D17E4407029FE9,\
													D17E448902A00F,D17E00D5058B59,D17E448902A6CC";	
	
#elif(BOARD_NO	==	SD_JN_SHXF_KM2) 	 		//山东省济南市商河谢芳驾校科目二训练场  216
	
	char code Serial_id[]	=	"D17E01390013A4,D17E013900107C,D17E0168FB0341,D17E0139001430,D17E84A14E5560,\
													D17E84074E555C,D17E84894E555C,D17E012C02D63C,D17E81E7197043,D17E84074E549F";
	
#elif(BOARD_NO	==	LJ82_HCLL_ZZPP) 	 			//82军合成6旅智能评判系统  220
	
	char code Serial_id[]	=	"D17E448902A059,D17E4489029FDF,D17E44A1029FF2,D17E8144169D50,D17E8144169D50,\
													D17E013FB88ED1,D17E013FB88ED1";
	
#elif(BOARD_NO	==	LJ81_ZLZYL_ZZPP) 	 		//81军战略支援旅智能评判系统  221
	
	char code Serial_id[]	=	"D17E440702A033,D17E44A1029FF1,D17E4407029FC7,D17E448902A08A,D17E440702A065,\
													D17E44B2029FD3,D17E44A102A05D,D17E448902A057";	
	
#elif(BOARD_NO	==	GZ_QNZ_WAYL_KM3) 			//贵州省黔南州瓮安云岭科目三考场  227
	
	char code Serial_id[]	=	"D17EC5F2033286,D17EC62E0323BB,D17EC5F0044FCE,D17EC5F1045407,D17EC5F0044FF1,\
													D17EC5F0044FF1,D17EC5F0044FF1,D17EC61B01A9D2,D17EC62E032372,D17EC5F2045026,\
													D17EC5F0044FB1,D17EC5F2045025,D17EC5F1045427,D17EC62E03237A,D17EC5F0033205,\
													D17EC62E02089E,D17EC5F10335D9,D17EC5F0033204,D17EC5EB0332B1,D17EC5F1045408";
	
#endif
	
	
//========================================================================
// 函数: void ByteToHexStr(const char* source, unsigned char* dest, int sourceLen)
// 描述: 将字节流转换为十六进制字符串。
// 参数：source数据源地址  dest转换后保存的目标地址  sourceLen转换长度 
// 返回: 无
// 版本: V1.0, 2022-10-17
//========================================================================
//void ByteToHexStr(const unsigned char* source, char* dest, int sourceLen)   
//{  
//    xdata short i=0;  
//    xdata unsigned char highByte, lowByte;  
//    for (i = 0; i < sourceLen; i++)  
//    {  
//        highByte = source[i] >> 4;  
//        lowByte = source[i] & 0x0f;  
//  
//        highByte += 0x30;  
//  
//        if (highByte > 0x39)  
//            dest[i * 2] = highByte + 0x07;  
//        else  
//            dest[i * 2] = highByte;  
//  
//        lowByte += 0x30;  
//        if (lowByte > 0x39)  
//            dest[i * 2 + 1] = lowByte + 0x07;  
//        else  
//            dest[i * 2 + 1] = lowByte;  
//    }  
//    return;  
//}  	
//========================================================================
// 函数: u8 Check_Serial_Id(void)
// 描述: 校验ID信息
// 参数：无
// 返回: 检验有效返回TURE,校验失败返回FALSE
// 版本: V1.0, 2022-10-17
//========================================================================
void Check_Serial_Id(void)	 //校验ID信息
{
		xdata char sn[3] = "";
		xdata char strid[ID_LENTH * 2+1] = "";
		xdata u8 i = 0;
	
		BSP_GetlocalId(localid);	//读取本机单片机ID信息
	  
		for (i = 0; i < ID_LENTH; i++)
		{
					sprintf(sn,"%b02X",localid[i]);
					strcat(strid,sn);
		}
		#ifdef DEBUG
				printf("DEBUG SN = %s\r\n",strid);
		#endif
		
		#ifdef CHECKID
		
			if(strstr(Serial_id,strid) != NULL)//比较字符串
			{
				
				#ifdef DEBUG
					delay_ms(1000);
					printf("DEBUG checkid,ok!\r\n");	
				#endif
				return;
			}
			else 
			{
					while(1)	//序列号不匹配在此处死循环
					{
						printf("SN = %s\r\n",strid);
						USART_Sendbuffer(DEBUG_USART,strid,strlen(strid));
						USART_Sendbuffer(DEBUG_USART,"\r\n",2);
						#ifdef  STC15W4K48S4
						USART_Sendbuffer(NETWORK_USART,strid,strlen(strid));
						USART_Sendbuffer(NETWORK_USART,"\r\n",2);
						#endif
						delay_ms(1000);
					}
				
				//return FLASE;
			}
		#endif
			
		#ifndef CHECKID
				#ifdef DEBUG
				printf("DEBUG NO_CHECKID!!!\r\n");
				#endif
		#endif
}
//========================================================================
// 函数: u8 Checksum(void)
// 描述: 计算校验和，将检验和保存到缓存的最后一个字节
// 参数：pbuffer需要校验的缓存区地址，lenth需要计算的长度
// 返回: 
// 版本: V1.0, 2022-10-17
//========================================================================
void Checksum(u8 *pbuffer, u16 lenth)	 //计算校验和
{
	xdata u16 i = 0;
	xdata u8 *psum = (pbuffer + lenth -1);
	for (i = 0; i<(lenth-1);i++)
	{
		*psum += *pbuffer++;
	}
}

//========================================================================
// 函数: void ByteArrayCompar(const u8 *source, const u8 *dest,u16 lenth)
// 描述: 比较两个内存，看source是否包含dest，
// 参数：*source需要比较的源数据,		srclen为源数据的长度  
//				*dest需要比较的目标数据,		deslen为目标数据的长度
// 返回: 出现目标数据的地址，不包含返回NULL
// 版本: V1.0, 2022-10-17
//========================================================================
u8 * ByteArrayCompar(const u8 *source,u16 srclen, const u8 *dest,u16 deslen)	
{
	xdata u16 slen= srclen; 
	xdata u16 dlen= deslen;
	
	xdata const u8 *psrc = source;
	xdata const u8 *pdes = dest;
	xdata const u8 *p = source;
	
	while(slen >= dlen)
	{
			psrc = p;
			pdes = dest;
			dlen = deslen;
			slen--;
			while((*psrc == *pdes) && (dlen > 0))
			{
				psrc++;
				pdes++;	
				dlen--;				
			}
			if(dlen == 0)
			{
				return (char *)p;
			} 		
			p++;
	}
	return NULL;

}
#ifdef  STC15W4K48S4
//========================================================================
// 函数: void ByteArrayCompar(const u8 *source, const u8 *dest,u16 lenth)
// 描述: 比较两个内存，看source是否包含dest，
// 参数：*source需要比较的源数据,		srclen为源数据的长度  
//				*dest需要比较的目标数据,		deslen为目标数据的长度
// 返回: 最后出现目标数据的地址，不包含返回NULL（从后往前进行比较）
// 版本: V1.0, 2022-10-17
//========================================================================
u8 * ByteArrayCompar_r(const u8 *source,u16 srclen, const u8 *dest,u16 deslen)	
{
	xdata u16 slen= srclen; 
	xdata u16 dlen= deslen;
	
	xdata const u8 *psrc = (u8 *)(source + srclen - 1);
	xdata const u8 *pdes = dest;
	xdata const u8 *p = (u8 *)(source + srclen - 1);
	
	while(slen > 0)
	{
			psrc = p;
			pdes = dest;
			dlen = deslen;
			slen--;
			while((*psrc == *pdes) && (dlen > 0) && (psrc < (source + srclen)))
			{
				psrc++;
				pdes++;	
				dlen--;				
			}
			if(dlen == 0)
			{
				return (char *)p;
			} 		
			p--;
	}
	return NULL;

}
#endif
	
