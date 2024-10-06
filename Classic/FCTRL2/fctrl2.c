/*
FCTRL2 - Small factorials
#math #big-numbers

You are asked to calculate factorials of some small positive integers.

Input

An integer t, 1 ≤ t ≤ 100, denoting the number of testcases, followed by
t lines, each containing a single integer n, 1 ≤ n ≤ 100.

Output

For each integer n given at input, display a line with the value of n!

Example

Input:
4
1
2
5
3

Output:
1
2
120
6
*/

#include <stdio.h>
#include <stdlib.h>

void input_values(int * destination, int size);
const char * factorial(int value);
void print_results(int * array, int size);

int main(void)
{
  int test_cases;
  int * results;
  scanf("%d", &test_cases);

  // store the results
  results = (int *)malloc(test_cases * sizeof(int));

  // check the memory
  if (results == NULL)
  {
    printf("Memory allocation failed!\n");
    return 1;
  }

  input_values(results, test_cases);

  printf("\n"); // separate input from output
  print_results(results, test_cases);

  free(results);

  return 0;
}

void input_values(int * destination, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    // store each input in separate array cell
    scanf("%d", &destination[i]);
  }
}

const char * factorial(int value)
{
  const char * factorial_values[101] = {
    "1", // 0!
    "1", // 1!
    "2", // 2!
    "6", // 3!
    "24", // 4!
    "120", // 5!
    "720", // 6!
    "5040", // 7!
    "40320", // 8!
    "362880", // 9!
    "3628800", // 10!
    "39916800", // 11!
    "479001600", // 12!
    "6227020800", // 13!
    "87178291200", // 14!
    "1307674368000", // 15!
    "20922789888000", // 16!
    "355687428096000", // 17!
    "6402373705728000", // 18!
    "121645100408832000", // 19!
    "2432902008176640000", // 20!
    "51090942171709440000", // 21!
    "1124000727777607680000", // 22!
    "25852016738884976640000", // 23!
    "620448401733239439360000", // 24!
    "15511210043330985984000000", // 25!
    "403291461126605635584000000", // 26!
    "10888869450418352160768000000", // 27!
    "304888344611713860501504000000", // 28!
    "8841761993739701954543616000000", // 29!
    "265252859812191058636308480000000", // 30!
    "8222838654177922817725562880000000", // 31!
    "263130836933693530167218012160000000", // 32!
    "8683317618811886495518194401280000000", // 33!
    "295232799039604140847618609643520000000", // 34!
    "10333147966386144929666651337523200000000", // 35!
    "371993326789901217467999448150835200000000", // 36!
    "13763753091226345046315979581580902400000000", // 37!
    "523022617466601111760007224100074291200000000", // 38!
    "20397882081197443358640281739902897356800000000", // 39!
    "815915283247897734345611269596115894272000000000", // 40!
    "33452526613163807108170062053440751665152000000000", // 41!
    "1405006117752879898543142606244511569936384000000000", // 42!
    "60415263063373835637355132068513997507264512000000000", // 43!
    "2658271574788448768043625811014615890319638528000000000", // 44!
    "119622220865480194561963161495657715064383733760000000000", // 45!
    "5502622159812088949850305428800254892961651752960000000000", // 46!
    "258623241511168180642964355153611979969197632389120000000000", // 47!
    "12413915592536072670862289047373375038521486354677760000000000", // 48!
    "608281864034267560872252163321295376887552831379210240000000000", // 49!
    "30414093201713378043612608166064768844377641568960512000000000000", // 50!
    "1551118753287382280224243016469303211063259720016986112000000000000",
    // 51!
    "80658175170943878571660636856403766975289505440883277824000000000000",
    // 52!
    "4274883284060025564298013753389399649690343788366813724672000000000000",
    // 53!
    "230843697339241380472092742683027581083278564571807941132288000000000000",
    // 54!
    "126964033536582759259651008475665169595803210514494367622758400000000000"
    "00", // 55!
    "710998587804863451854045647463724949736497978881168458687447040000000000"
    "000", // 56!
    "405269195048772167556806019054323221349803847962266021451844812800000000"
    "00000", // 57!
    "235056133128287857182947491051507468382886231818114292442069991424000000"
    "0000000", // 58!
    "138683118545689835737939019720389406345902876772687432540821294940160000"
    "000000000", // 59!
    "832098711274139014427634118322336438075417260636124595244927769640960000"
    "0000000000", // 60!
    "507580213877224798800856812176625227226004528988036003099405939480985600"
    "000000000000", // 61!
    "314699732603879375256531223549507640880122807972582321921631682478211072"
    "00000000000000", // 62!
    "198260831540444006411614670836189813754477369022726862810627959961272975"
    "3600000000000000", // 63!
    "126886932185884164103433389335161480802865516174545192198801894375214704"
    "230400000000000000", // 64!
    "824765059208247066672317030678549625218625855134543749292212313438895577"
    "4976000000000000000", // 65!
    "544344939077443064003729240247842752644293064388798874532860126869671081"
    "148416000000000000000", // 66!
    "364711109181886852882498590966054644271676353140495245937016285002679624"
    "36943872000000000000000", // 67!
    "248003554243683059960099041856917158104739920135536767237171073801822144"
    "5712183296000000000000000", // 68!
    "171122452428141311372468338881272839092270544893520369393648040923257279"
    "754140647424000000000000000", // 69!
    "119785716699698917960727837216890987364589381425464258575553628646280095"
    "82789845319680000000000000000", // 70!
    "850478588567862317521167644239926010288584608120796235886430763388588680"
    "378079017697280000000000000000", // 71!
    "612344583768860868615240703852746727407780917846973289838230149639783849"
    "87221689274204160000000000000000", // 72!
    "447011546151268434089125713812505111007680070028290501581908009237042210"
    "4067183317016903680000000000000000", // 73!
    "330788544151938641225953028221253782145683251820934971170611926835411235"
    "700971565459250872320000000000000000", // 74!
    "248091408113953980919464771165940336609262438865701228377958945126558426"
    "77572867409443815424000000000000000000", // 75!
    "188549470166605025498793226086114655823039453537932933567248798296184404"
    "3495537923117729972224000000000000000000", // 76!
    "145183092028285869634070784086308284983740379224208358846781574688061991"
    "349156420080065207861248000000000000000000", // 77!
    "113242811782062978314575211587320462287317495794882519900489628256688353"
    "25234200766245086213177344000000000000000000", // 78!
    "894618213078297528685144171539831652069808216779571907213868063227837990"
    "693501860533361810841010176000000000000000000", // 79!
    "715694570462638022948115337231865321655846573423657525771094450582270392"
    "55480148842668944867280814080000000000000000000", // 80!
    "579712602074736798587973423157810910541235724473162595874586504971639017"
    "9693892056256184534249745940480000000000000000000", // 81!
    "475364333701284174842138206989404946643813294067993328617160934076743994"
    "734899148613007131808479167119360000000000000000000" // 82!
  };

  return factorial_values[value - 1];  
}




void print_results(int * array, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%d\n", array[i]);
  }
}
