/*******************************************************************************
    OpenAirInterface 
    Copyright(c) 1999 - 2014 Eurecom

    OpenAirInterface is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.


    OpenAirInterface is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with OpenAirInterface.The full GNU General Public License is 
   included in this distribution in the file called "COPYING". If not, 
   see <http://www.gnu.org/licenses/>.

  Contact Information
  OpenAirInterface Admin: openair_admin@eurecom.fr
  OpenAirInterface Tech : openair_tech@eurecom.fr
  OpenAirInterface Dev  : openair4g-devel@eurecom.fr
  
  Address      : Eurecom, Campus SophiaTech, 450 Route des Chappes, CS 50193 - 06904 Biot Sophia Antipolis cedex, FRANCE

 *******************************************************************************/
#include <stdint.h>

/* Twiddles generated with
twa = floor(32767*exp(-sqrt(-1)*2*pi*(0:511)/1536));
twb = floor(32767*exp(-sqrt(-1)*2*pi*(0:2:1022)/1536));
twa2 = zeros(1,1024);
twb2 = zeros(1,1024);
twa2(1:2:end) = real(twa);
twa2(2:2:end) = imag(twa);
twb2(1:2:end) = real(twb);
twb2(2:2:end) = imag(twb);


 */

int16_t twa1536[1024] __attribute__((aligned(16))) = {32767,0,32766,-135,32765,-269,32764,-403,32762,-537,32760,-671,32757,-805,32753,-939,32749,-1073,32744,-1207,32739,-1340,32733,-1474,32727,-1608,32720,-1742,32713,-1876,32705,-2010,32696,-2144,32687,-2277,32678,-2411,32668,-2545,32657,-2678,32646,-2812,32634,-2945,32622,-3079,32609,-3212,32595,-3346,32581,-3479,32567,-3612,32552,-3745,32536,-3878,32520,-4012,32503,-4145,32486,-4277,32468,-4410,32450,-4543,32431,-4676,32412,-4808,32392,-4941,32371,-5073,32350,-5206,32329,-5338,32307,-5470,32284,-5602,32261,-5734,32237,-5866,32213,-5998,32188,-6130,32163,-6262,32137,-6393,32110,-6524,32084,-6656,32056,-6787,32028,-6918,31999,-7049,31970,-7180,31941,-7311,31911,-7441,31880,-7572,31849,-7702,31817,-7832,31785,-7962,31752,-8092,31718,-8222,31684,-8352,31650,-8481,31615,-8611,31580,-8740,31544,-8869,31507,-8998,31470,-9127,31432,-9255,31394,-9384,31356,-9512,31316,-9640,31277,-9768,31236,-9896,31196,-10024,31154,-10152,31113,-10279,31070,-10406,31028,-10533,30984,-10660,30940,-10787,30896,-10913,30851,-11039,30806,-11165,30760,-11291,30713,-11417,30666,-11543,30619,-11668,30571,-11793,30522,-11918,30473,-12043,30424,-12167,30374,-12292,30323,-12416,30272,-12540,30221,-12664,30169,-12787,30116,-12910,30063,-13034,30009,-13156,29955,-13279,29901,-13401,29846,-13524,29790,-13646,29734,-13767,29678,-13889,29621,-14010,29563,-14131,29505,-14252,29446,-14373,29387,-14493,29328,-14613,29268,-14733,29207,-14853,29146,-14972,29085,-15091,29023,-15210,28960,-15328,28897,-15447,28834,-15565,28770,-15683,28706,-15800,28641,-15918,28575,-16035,28510,-16151,28443,-16268,28377,-16384,28309,-16500,28242,-16616,28173,-16731,28105,-16846,28036,-16961,27966,-17075,27896,-17190,27825,-17304,27754,-17417,27683,-17531,27611,-17644,27538,-17757,27466,-17869,27392,-17981,27319,-18093,27244,-18205,27170,-18316,27094,-18427,27019,-18538,26943,-18648,26866,-18758,26789,-18868,26712,-18977,26634,-19087,26556,-19195,26477,-19304,26398,-19412,26318,-19520,26238,-19627,26158,-19734,26077,-19841,25995,-19948,25913,-20054,25831,-20160,25749,-20265,25665,-20370,25582,-20475,25498,-20580,25414,-20684,25329,-20788,25243,-20891,25158,-20994,25072,-21097,24985,-21199,24898,-21301,24811,-21403,24723,-21504,24635,-21605,24546,-21706,24457,-21806,24368,-21906,24278,-22005,24188,-22105,24097,-22203,24006,-22302,23915,-22400,23823,-22497,23731,-22595,23638,-22692,23545,-22788,23452,-22884,23358,-22980,23264,-23075,23169,-23170,23074,-23265,22979,-23359,22883,-23453,22787,-23546,22691,-23639,22594,-23732,22496,-23824,22399,-23916,22301,-24007,22202,-24098,22104,-24189,22004,-24279,21905,-24369,21805,-24458,21705,-24547,21604,-24636,21503,-24724,21402,-24812,21300,-24899,21198,-24986,21096,-25073,20993,-25159,20890,-25244,20787,-25330,20683,-25415,20579,-25499,20474,-25583,20369,-25666,20264,-25750,20159,-25832,20053,-25914,19947,-25996,19840,-26078,19733,-26159,19626,-26239,19519,-26319,19411,-26399,19303,-26478,19194,-26557,19086,-26635,18976,-26713,18867,-26790,18757,-26867,18647,-26944,18537,-27020,18426,-27095,18315,-27171,18204,-27245,18092,-27320,17980,-27393,17868,-27467,17756,-27539,17643,-27612,17530,-27684,17416,-27755,17303,-27826,17189,-27897,17074,-27967,16960,-28037,16845,-28106,16730,-28174,16615,-28243,16499,-28310,16383,-28378,16267,-28444,16150,-28511,16034,-28576,15917,-28642,15799,-28707,15682,-28771,15564,-28835,15446,-28898,15327,-28961,15209,-29024,15090,-29086,14971,-29147,14852,-29208,14732,-29269,14612,-29329,14492,-29388,14372,-29447,14251,-29506,14130,-29564,14009,-29622,13888,-29679,13766,-29735,13645,-29791,13523,-29847,13400,-29902,13278,-29956,13155,-30010,13033,-30064,12909,-30117,12786,-30170,12663,-30222,12539,-30273,12415,-30324,12291,-30375,12166,-30425,12042,-30474,11917,-30523,11792,-30572,11667,-30620,11542,-30667,11416,-30714,11290,-30761,11164,-30807,11038,-30852,10912,-30897,10786,-30941,10659,-30985,10532,-31029,10405,-31071,10278,-31114,10151,-31155,10023,-31197,9895,-31237,9767,-31278,9639,-31317,9511,-31357,9383,-31395,9254,-31433,9126,-31471,8997,-31508,8868,-31545,8739,-31581,8610,-31616,8480,-31651,8351,-31685,8221,-31719,8091,-31753,7961,-31786,7831,-31818,7701,-31850,7571,-31881,7440,-31912,7310,-31942,7179,-31971,7048,-32000,6917,-32029,6786,-32057,6655,-32085,6523,-32111,6392,-32138,6261,-32164,6129,-32189,5997,-32214,5865,-32238,5733,-32262,5601,-32285,5469,-32308,5337,-32330,5205,-32351,5072,-32372,4940,-32393,4807,-32413,4675,-32432,4542,-32451,4409,-32469,4276,-32487,4144,-32504,4011,-32521,3877,-32537,3744,-32553,3611,-32568,3478,-32582,3345,-32596,3211,-32610,3078,-32623,2944,-32635,2811,-32647,2677,-32658,2544,-32669,2410,-32679,2276,-32688,2143,-32697,2009,-32706,1875,-32714,1741,-32721,1607,-32728,1473,-32734,1339,-32740,1206,-32745,1072,-32750,938,-32754,804,-32758,670,-32761,536,-32763,402,-32765,268,-32766,134,-32767,0,-32767,-135,-32767,-269,-32766,-403,-32765,-537,-32763,-671,-32761,-805,-32758,-939,-32754,-1073,-32750,-1207,-32745,-1340,-32740,-1474,-32734,-1608,-32728,-1742,-32721,-1876,-32714,-2010,-32706,-2144,-32697,-2277,-32688,-2411,-32679,-2545,-32669,-2678,-32658,-2812,-32647,-2945,-32635,-3079,-32623,-3212,-32610,-3346,-32596,-3479,-32582,-3612,-32568,-3745,-32553,-3878,-32537,-4012,-32521,-4145,-32504,-4277,-32487,-4410,-32469,-4543,-32451,-4676,-32432,-4808,-32413,-4941,-32393,-5073,-32372,-5206,-32351,-5338,-32330,-5470,-32308,-5602,-32285,-5734,-32262,-5866,-32238,-5998,-32214,-6130,-32189,-6262,-32164,-6393,-32138,-6524,-32111,-6656,-32085,-6787,-32057,-6918,-32029,-7049,-32000,-7180,-31971,-7311,-31942,-7441,-31912,-7572,-31881,-7702,-31850,-7832,-31818,-7962,-31786,-8092,-31753,-8222,-31719,-8352,-31685,-8481,-31651,-8611,-31616,-8740,-31581,-8869,-31545,-8998,-31508,-9127,-31471,-9255,-31433,-9384,-31395,-9512,-31357,-9640,-31317,-9768,-31278,-9896,-31237,-10024,-31197,-10152,-31155,-10279,-31114,-10406,-31071,-10533,-31029,-10660,-30985,-10787,-30941,-10913,-30897,-11039,-30852,-11165,-30807,-11291,-30761,-11417,-30714,-11543,-30667,-11668,-30620,-11793,-30572,-11918,-30523,-12043,-30474,-12167,-30425,-12292,-30375,-12416,-30324,-12540,-30273,-12664,-30222,-12787,-30170,-12910,-30117,-13034,-30064,-13156,-30010,-13279,-29956,-13401,-29902,-13524,-29847,-13646,-29791,-13767,-29735,-13889,-29679,-14010,-29622,-14131,-29564,-14252,-29506,-14373,-29447,-14493,-29388,-14613,-29329,-14733,-29269,-14853,-29208,-14972,-29147,-15091,-29086,-15210,-29024,-15328,-28961,-15447,-28898,-15565,-28835,-15683,-28771,-15800,-28707,-15918,-28642,-16035,-28576,-16151,-28511,-16268,-28444};

int16_t twb1536[1024] __attribute__((aligned(16))) = {32767,0,32765,-269,32762,-537,32757,-805,32749,-1073,32739,-1340,32727,-1608,32713,-1876,32696,-2144,32678,-2411,32657,-2678,32634,-2945,32609,-3212,32581,-3479,32552,-3745,32520,-4012,32486,-4277,32450,-4543,32412,-4808,32371,-5073,32329,-5338,32284,-5602,32237,-5866,32188,-6130,32137,-6393,32084,-6656,32028,-6918,31970,-7180,31911,-7441,31849,-7702,31785,-7962,31718,-8222,31650,-8481,31580,-8740,31507,-8998,31432,-9255,31356,-9512,31277,-9768,31196,-10024,31113,-10279,31028,-10533,30940,-10787,30851,-11039,30760,-11291,30666,-11543,30571,-11793,30473,-12043,30374,-12292,30272,-12540,30169,-12787,30063,-13034,29955,-13279,29846,-13524,29734,-13767,29621,-14010,29505,-14252,29387,-14493,29268,-14733,29146,-14972,29023,-15210,28897,-15447,28770,-15683,28641,-15918,28510,-16151,28377,-16384,28242,-16616,28105,-16846,27966,-17075,27825,-17304,27683,-17531,27538,-17757,27392,-17981,27244,-18205,27094,-18427,26943,-18648,26789,-18868,26634,-19087,26477,-19304,26318,-19520,26158,-19734,25995,-19948,25831,-20160,25665,-20370,25498,-20580,25329,-20788,25158,-20994,24985,-21199,24811,-21403,24635,-21605,24457,-21806,24278,-22005,24097,-22203,23915,-22400,23731,-22595,23545,-22788,23358,-22980,23169,-23170,22979,-23359,22787,-23546,22594,-23732,22399,-23916,22202,-24098,22004,-24279,21805,-24458,21604,-24636,21402,-24812,21198,-24986,20993,-25159,20787,-25330,20579,-25499,20369,-25666,20159,-25832,19947,-25996,19733,-26159,19519,-26319,19303,-26478,19086,-26635,18867,-26790,18647,-26944,18426,-27095,18204,-27245,17980,-27393,17756,-27539,17530,-27684,17303,-27826,17074,-27967,16845,-28106,16615,-28243,16383,-28378,16150,-28511,15917,-28642,15682,-28771,15446,-28898,15209,-29024,14971,-29147,14732,-29269,14492,-29388,14251,-29506,14009,-29622,13766,-29735,13523,-29847,13278,-29956,13033,-30064,12786,-30170,12539,-30273,12291,-30375,12042,-30474,11792,-30572,11542,-30667,11290,-30761,11038,-30852,10786,-30941,10532,-31029,10278,-31114,10023,-31197,9767,-31278,9511,-31357,9254,-31433,8997,-31508,8739,-31581,8480,-31651,8221,-31719,7961,-31786,7701,-31850,7440,-31912,7179,-31971,6917,-32029,6655,-32085,6392,-32138,6129,-32189,5865,-32238,5601,-32285,5337,-32330,5072,-32372,4807,-32413,4542,-32451,4276,-32487,4011,-32521,3744,-32553,3478,-32582,3211,-32610,2944,-32635,2677,-32658,2410,-32679,2143,-32697,1875,-32714,1607,-32728,1339,-32740,1072,-32750,804,-32758,536,-32763,268,-32766,0,-32767,-269,-32766,-537,-32763,-805,-32758,-1073,-32750,-1340,-32740,-1608,-32728,-1876,-32714,-2144,-32697,-2411,-32679,-2678,-32658,-2945,-32635,-3212,-32610,-3479,-32582,-3745,-32553,-4012,-32521,-4277,-32487,-4543,-32451,-4808,-32413,-5073,-32372,-5338,-32330,-5602,-32285,-5866,-32238,-6130,-32189,-6393,-32138,-6656,-32085,-6918,-32029,-7180,-31971,-7441,-31912,-7702,-31850,-7962,-31786,-8222,-31719,-8481,-31651,-8740,-31581,-8998,-31508,-9255,-31433,-9512,-31357,-9768,-31278,-10024,-31197,-10279,-31114,-10533,-31029,-10787,-30941,-11039,-30852,-11291,-30761,-11543,-30667,-11793,-30572,-12043,-30474,-12292,-30375,-12540,-30273,-12787,-30170,-13034,-30064,-13279,-29956,-13524,-29847,-13767,-29735,-14010,-29622,-14252,-29506,-14493,-29388,-14733,-29269,-14972,-29147,-15210,-29024,-15447,-28898,-15683,-28771,-15918,-28642,-16151,-28511,-16384,-28378,-16616,-28243,-16846,-28106,-17075,-27967,-17304,-27826,-17531,-27684,-17757,-27539,-17981,-27393,-18205,-27245,-18427,-27095,-18648,-26944,-18868,-26790,-19087,-26635,-19304,-26478,-19520,-26319,-19734,-26159,-19948,-25996,-20160,-25832,-20370,-25666,-20580,-25499,-20788,-25330,-20994,-25159,-21199,-24986,-21403,-24812,-21605,-24636,-21806,-24458,-22005,-24279,-22203,-24098,-22400,-23916,-22595,-23732,-22788,-23546,-22980,-23359,-23170,-23170,-23359,-22980,-23546,-22788,-23732,-22595,-23916,-22400,-24098,-22203,-24279,-22005,-24458,-21806,-24636,-21605,-24812,-21403,-24986,-21199,-25159,-20994,-25330,-20788,-25499,-20580,-25666,-20370,-25832,-20160,-25996,-19948,-26159,-19734,-26319,-19520,-26478,-19304,-26635,-19087,-26790,-18868,-26944,-18648,-27095,-18427,-27245,-18205,-27393,-17981,-27539,-17757,-27684,-17531,-27826,-17304,-27967,-17075,-28106,-16846,-28243,-16616,-28378,-16384,-28511,-16151,-28642,-15918,-28771,-15683,-28898,-15447,-29024,-15210,-29147,-14972,-29269,-14733,-29388,-14493,-29506,-14252,-29622,-14010,-29735,-13767,-29847,-13524,-29956,-13279,-30064,-13034,-30170,-12787,-30273,-12540,-30375,-12292,-30474,-12043,-30572,-11793,-30667,-11543,-30761,-11291,-30852,-11039,-30941,-10787,-31029,-10533,-31114,-10279,-31197,-10024,-31278,-9768,-31357,-9512,-31433,-9255,-31508,-8998,-31581,-8740,-31651,-8481,-31719,-8222,-31786,-7962,-31850,-7702,-31912,-7441,-31971,-7180,-32029,-6918,-32085,-6656,-32138,-6393,-32189,-6130,-32238,-5866,-32285,-5602,-32330,-5338,-32372,-5073,-32413,-4808,-32451,-4543,-32487,-4277,-32521,-4012,-32553,-3745,-32582,-3479,-32610,-3212,-32635,-2945,-32658,-2678,-32679,-2411,-32697,-2144,-32714,-1876,-32728,-1608,-32740,-1340,-32750,-1073,-32758,-805,-32763,-537,-32766,-269,-32767,-1,-32766,268,-32763,536,-32758,804,-32750,1072,-32740,1339,-32728,1607,-32714,1875,-32697,2143,-32679,2410,-32658,2677,-32635,2944,-32610,3211,-32582,3478,-32553,3744,-32521,4011,-32487,4276,-32451,4542,-32413,4807,-32372,5072,-32330,5337,-32285,5601,-32238,5865,-32189,6129,-32138,6392,-32085,6655,-32029,6917,-31971,7179,-31912,7440,-31850,7701,-31786,7961,-31719,8221,-31651,8480,-31581,8739,-31508,8997,-31433,9254,-31357,9511,-31278,9767,-31197,10023,-31114,10278,-31029,10532,-30941,10786,-30852,11038,-30761,11290,-30667,11542,-30572,11792,-30474,12042,-30375,12291,-30273,12539,-30170,12786,-30064,13033,-29956,13278,-29847,13523,-29735,13766,-29622,14009,-29506,14251,-29388,14492,-29269,14732,-29147,14971,-29024,15209,-28898,15446,-28771,15682,-28642,15917,-28511,16150,-28378,16383,-28243,16615,-28106,16845,-27967,17074,-27826,17303,-27684,17530,-27539,17756,-27393,17980,-27245,18204,-27095,18426,-26944,18647,-26790,18867,-26635,19086,-26478,19303,-26319,19519,-26159,19733,-25996,19947,-25832,20159,-25666,20369,-25499,20579,-25330,20787,-25159,20993,-24986,21198,-24812,21402,-24636,21604,-24458,21805,-24279,22004,-24098,22202,-23916,22399,-23732,22594,-23546,22787,-23359,22979,-23170,23169,-22980,23358,-22788,23545,-22595,23731,-22400,23915,-22203,24097,-22005,24278,-21806,24457,-21605,24635,-21403,24811,-21199,24985,-20994,25158,-20788,25329,-20580,25498,-20370,25665,-20160,25831,-19948,25995,-19734,26158,-19520,26318,-19304,26477,-19087,26634,-18868,26789,-18648,26943,-18427,27094,-18205,27244,-17981,27392,-17757,27538,-17531,27683,-17304,27825,-17075,27966,-16846,28105,-16616,28242};