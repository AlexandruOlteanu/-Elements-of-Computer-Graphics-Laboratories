#pragma once

#include "components/simple_scene.h"
#include "lab_m1/tema2/camera.h"

#include <vector>
#include <utility>

namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
    public:
        struct ViewportArea
        {
            ViewportArea() : x(0), y(0), width(1), height(1) {}
            ViewportArea(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };

        Tema2();
        ~Tema2();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;
        void Tema2::MiniFrameEnd();
        void Tema2::MyRenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix);
        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;
		void Tema2::create_road();
		void Tema2::render_road();
        void Tema2::create_trees();
        void Tema2::render_trees();
        void Tema2::update_camera();
        void Tema2::update_truck();
        void Tema2::render_ground();
        void Tema2::create_parallelepiped(std :: string name, double point1_x, double point1_y, double point2_x, double point2_y, double height1, double height2, glm::vec3 color);
		void extract_road_points(std :: vector<std :: pair<double, double>> &points) {
            points.push_back({ -2.17543404815316599, -0.00000000000000000 });
            points.push_back({ 3.19863062050413083, -0.00000000000000000 });
            points.push_back({ -2.00000000000000000, -2.00000000000000000 });
            points.push_back({ 2.46994388577093815, -2.67844172091916599 });
            points.push_back({ -2.63086325736141147, -3.92439130848380513 });
            points.push_back({ 1.65017130919609634, -5.58565742523665687 });
            points.push_back({ -3.32003789125443749, -5.65850234442786970 });
            points.push_back({ 0.28388368157135979, -7.66224007117772210 });
            points.push_back({ -5.09018098708593669, -6.91467031863893933 });
            points.push_back({ -1.62891899710327137, -9.73882271711878822 });
            points.push_back({ -7.27624119128551516, -8.57593643539179062 });
            points.push_back({ -3.63280751761955134, -11.98153197473513920 });
            points.push_back({ -10.00000000000000000, -10.00000000000000000 });
            points.push_back({ -6.00000000000000000, -14.00000000000000000 });
            points.push_back({ -12.01270496705126867, -11.89846866889749499 });
            points.push_back({ -8.84141255856639141, -16.39398357324049726 });
            points.push_back({ -14.77677661002421061, -14.12086542587366189 });
            points.push_back({ -12.18794760885643846, -18.28824869604619607 });
            points.push_back({ -18.37588034335501419, -16.01513054867935892 });
            points.push_back({ -15.00000000000000000, -20.00000000000000000 });
            points.push_back({ -20.96470934452278811, -19.23538125744904548 });
            points.push_back({ -16.86046824511046438, -22.83448499077986682 });
            points.push_back({ -22.54326361352752528, -23.08705367382062690 });
            points.push_back({ -17.17617909891141537, -26.11787787030974428 });
            points.push_back({ -23.33564549476776406, -27.35463278861898928 });
            points.push_back({ -17.81979186562886497, -28.84540403973761968 });
            points.push_back({ -23.26110693221183467, -31.52879229175115228 });
            points.push_back({ -16.32902061451024522, -32.05056222964267221 });
            points.push_back({ -21.69579711853728199, -35.55387466977145294 });
            points.push_back({ -13.57109379994079568, -34.21218054376468842 });
            points.push_back({ -17.96886899074072730, -38.98264854734429719 });
            points.push_back({ -10.73862842281541496, -35.92656748255110699 });
            points.push_back({ -13.49655523738486451, -41.81511392446969211 });
            points.push_back({ -8.20431729591375891, -36.67195310811042219 });
            points.push_back({ -9.39693429680865577, -42.63503811258494380 });
            points.push_back({ -5.96816041923582574, -36.89556879577821746 });
            points.push_back({ -3.50838785489010085, -36.74649167066635158 });
            points.push_back({ -2.16669372888334166, -41.36788254913410867 });
            points.push_back({ -5.52092904390023964, -42.18780673724935326 });
            points.push_back({ -0.82499960287658247, -35.03210473187993301 });
            points.push_back({ 0.96392589846576315, -40.10072698568327354 });
            points.push_back({ 1.26208014868948748, -33.91402629354095666 });
            points.push_back({ 4.16908408837079936, -38.38634004689684787 });
            points.push_back({ 2.97646708747590205, -32.72140929264605802 });
            points.push_back({ 6.25616383993686931, -34.95756616932399652 });
            points.push_back({ 4.09454552581486819, -30.18709816574438420 });
            points.push_back({ 7.44878084083176617, -31.30517660408335701 });
            points.push_back({ 4.46723833859452313, -27.13101710095119401 });
            points.push_back({ 8.41778215405886954, -27.87640272651050921 });
            points.push_back({ 4.54177690115045429, -24.00039747360207443 });
            points.push_back({ 8.86501352939445653, -24.59670597404952375 });
            points.push_back({ 6.40524096504873075, -20.42254647091736430 });
            points.push_back({ 11.02663184351645675, -21.68970203436819943 });
            points.push_back({ 9.53586059239783523, -18.26092815679535164 });
            points.push_back({ 13.71002009552997514, -20.57162359602922663 });
            points.push_back({ 12.81555734485880294, -16.62107978056485891 });
            points.push_back({ 17.43694822332652805, -20.04985365813770670 });
            points.push_back({ 16.39340834754349530, -15.80115559244961254 });
            points.push_back({ 20.79118353834342869, -20.42254647091736430 });
            points.push_back({ 20.64210641323156636, -15.42846277966995494 });
            points.push_back({ 23.40003322780101414, -21.83877915948006176 });
            points.push_back({ 25.11442016658742915, -16.84469546823265418 });
            points.push_back({ 25.93434435470267019, -24.07493603615800382 });
            points.push_back({ 28.31957835649246391, -19.82623797046991143 });
            points.push_back({ 28.31957835649247102, -26.90740141328340940 });
            points.push_back({ 31.67381367150936811, -23.47862753571056160 });
            points.push_back({ 30.00000000000000000, -30.00000000000000000 });
            points.push_back({ 33.83543198563136656, -27.65278703884272460 });
            points.push_back({ 30.10850385783481542, -33.91402629354097087 });
            points.push_back({ 34.65535617374661115, -32.87048641775792390 });
            points.push_back({ 28.69227116927212506, -38.08818579667313031 });
            points.push_back({ 34.28266336096695710, -38.53541717200872085 });
            points.push_back({ 27.05242279304163944, -41.81511392446970632 });
            points.push_back({ 32.19558360940088448, -43.15680805047647084 });
            points.push_back({ 24.21995741591626228, -44.79665642670696002 });
            points.push_back({ 28.91588685693991678, -47.48004467872049617 });
            points.push_back({ 21.38749203879088157, -47.18189042849677151 });
            points.push_back({ 25.00000000000000000, -50.00000000000000000 });
            points.push_back({ 20.79118353834343225, -52.32505124485604142 });
            points.push_back({ 18.03325672377398092, -49.04535449239505596 });
            points.push_back({ 17.21333253565873989, -54.26305387131026237 });
            points.push_back({ 15.00000000000000000, -50.00000000000000000 });
            points.push_back({ 12.96463446997066882, -55.23205518453727336 });
            points.push_back({ 11.99563315674356545, -50.23797149328987643 });
            points.push_back({ 8.71593640428259775, -55.53020943476099802 });
            points.push_back({ 8.71593640428259775, -50.53612574351360109 });
            points.push_back({ 5.00000000000000000, -55.00000000000000000 });
            points.push_back({ 5.00000000000000000, -50.00000000000000000 });
            points.push_back({ 1.18754158613356053, -56.20105649776438383 });
            points.push_back({ 0.59123308568611210, -51.20697280651697980 });
            points.push_back({ -2.01761660377147534, -58.28813624933046356 });
            points.push_back({ -4.32831204300533834, -53.96489962108644534 });
            points.push_back({ -5.07369766856464910, -61.26967875156771726 });
            points.push_back({ -7.68254735802223632, -56.20105649776438383 });
            points.push_back({ -8.27885585846968475, -62.90952712779820644 });
            points.push_back({ -10.06778135981203093, -57.98998199910673179 });
            points.push_back({ -12.52755392415775582, -63.87852844102530980 });
            points.push_back({ -13.04932386204927397, -58.88444474977791288 });
            points.push_back({ -16.77625198984582511, -63.35675850313378987 });
            points.push_back({ -15.58363498895093002, -58.66082906211011760 });
            points.push_back({ -19.60871736697120582, -62.01506437712702535 });
            points.push_back({ -18.11794611585258608, -57.76636631143894363 });
            points.push_back({ -22.14302849387286187, -60.22613887578467740 });
            points.push_back({ -20.80133436786610446, -56.27559506032031322 });
            points.push_back({ -24.15556968288300155, -58.36267481188639294 });
            points.push_back({ -22.88841411943217352, -54.48666955897796527 });
            points.push_back({ -27.06257362256431520, -56.64828787309997438 });
            points.push_back({ -25.57180237144569190, -52.92135974530340548 });
            points.push_back({ -29.22419193668631365, -54.41213099642202877 });
            points.push_back({ -27.43526643534396925, -50.68520286862546698 });
            points.push_back({ -31.92342594705541003, -53.37498060377345865 });
            points.push_back({ -30.00000000000000000, -50.00000000000000000 });
            points.push_back({ -35.31656745413744858, -53.12670195691379149 });
            points.push_back({ -33.66137647507304109, -48.07836947076732059 });
            points.push_back({ -38.87522805912593071, -52.71290421214769140 });
            points.push_back({ -37.55107527587440330, -48.07836947076732059 });
            points.push_back({ -41.85457182144186561, -52.96118285900735145 });
            points.push_back({ -41.60629317458220555, -48.32664811762698065 });
            points.push_back({ -45.49599197538356776, -53.70601879958633873 });
            points.push_back({ -45.74427062224322782, -48.90596496029952789 });
            points.push_back({ -49.13741212932526992, -54.45085474016532601 });
            points.push_back({ -49.55120987409137001, -48.74044586239308785 });
            points.push_back({ -52.94435138117340500, -55.36120977865076043 });
            points.push_back({ -53.10987047907985215, -49.56804135192529515 });
            points.push_back({ -55.00000000000000000, -55.00000000000000000 });
            points.push_back({ -56.00645469244256702, -50.06459864564462237 });
            points.push_back({ -57.74440522046019453, -55.11293113179109326 });
            points.push_back({ -58.65476025894562184, -50.31287729250428242 });
            points.push_back({ -60.00000000000000000, -55.00000000000000000 });
            points.push_back({ -60.97202762963578948, -50.06459864564462237 });
            points.push_back({ -63.62033319613884430, -55.03017158283787325 });
            points.push_back({ -63.28929500032596422, -48.98872450925274791 });
            points.push_back({ -66.84795560531443925, -53.20946150586701862 });
            points.push_back({ -65.93760056682901904, -48.07836947076732059 });
            points.push_back({ -70.00000000000000000, -50.00000000000000000 });
            points.push_back({ -68.33762748647241381, -46.75421668751578608 });
            points.push_back({ -72.80664312994632326, -48.32664811762698065 });
            points.push_back({ -70.98593305297546863, -44.27143021891916419 });
            points.push_back({ -75.95150599016869819, -45.26454480635781152 });
            points.push_back({ -73.46871952157208341, -41.12656735869676794 });
            points.push_back({ -78.59981155667175301, -42.86451788671440255 });
            points.push_back({ -75.70322734330903813, -38.97481908591302613 });
            points.push_back({ -80.17224298678293337, -38.56102134114691893 });
            points.push_back({ -76.36530373493479829, -36.07823487255029704 });
            points.push_back({ -80.25500253573616760, -33.67820795290688807 });
            points.push_back({ -75.95150599016869819, -33.84372705081332811 });
            points.push_back({ -79.26188794829751316, -30.36782599477805178 });
            points.push_back({ -73.96527681529140352, -31.52645968012314626 });
            points.push_back({ -76.69634193074767836, -27.96779907513464636 });
            points.push_back({ -71.39973079774156872, -30.36782599477805178 });
            points.push_back({ -72.47560493413344318, -26.56088674292989182 });
            points.push_back({ -68.17210838856597377, -31.85749787593602989 });
            points.push_back({ -67.59279154589343364, -27.80227997722820632 });
            points.push_back({ -65.35828372415647891, -34.17476524662621529 });
            points.push_back({ -63.37205454927918424, -29.87126870105872811 });
            points.push_back({ -62.62721860870020407, -37.23686855789538441 });
            points.push_back({ -60.06167259115036927, -32.18853607174891351 });
            points.push_back({ -60.00000000000000000, -40.00000000000000000 });
            points.push_back({ -57.16508837778765439, -35.82995622569062988 });
            points.push_back({ -56.00645469244256702, -42.28520104404186242 });
            points.push_back({ -53.68918732175239228, -37.89894494952115167 });
            points.push_back({ -51.28916040210899752, -43.03003698462084969 });
            points.push_back({ -50.54432446153001735, -37.73342585161471163 });
            points.push_back({ -46.82014475863509517, -41.12656735869676794 });
            points.push_back({ -48.06153799293340256, -36.82307081312928432 });
            points.push_back({ -43.17872460469339302, -39.14033818381946617 });
            points.push_back({ -45.00000000000000000, -35.00000000000000000 });
            points.push_back({ -40.00000000000000000, -35.00000000000000000 });
            points.push_back({ -43.50976280050627309, -32.85061246337468077 });
            points.push_back({ -38.87522805912593071, -32.27129562070213353 });
            points.push_back({ -42.84768640888051294, -30.45058554373127535 });
            points.push_back({ -38.21315166750016346, -29.20919230943296085 });
            points.push_back({ -43.34424370259983306, -27.96779907513464636 });
            points.push_back({ -38.21315166750016346, -26.56088674292989182 });
            points.push_back({ -43.17872460469339302, -24.90569576386547368 });
            points.push_back({ -38.67241611751930463, -23.58383123557169370 });
            points.push_back({ -44.06474519412505231, -22.08596204762564597 });
            points.push_back({ -39.27156379269771946, -20.68795080554266619 });
            points.push_back({ -45.76233027379723239, -19.09022367173355050 });
            points.push_back({ -40.07042735960227731, -17.79207037551364223 });
            points.push_back({ -46.66105178656485464, -16.19434324170452300 });
            points.push_back({ -41.66815449341138589, -15.69505351238917434 });
            points.push_back({ -47.85934713692169140, -13.29846281167549726 });
            points.push_back({ -42.96630778963128705, -12.99888897408628807 });
            points.push_back({ -49.45707427073079998, -11.20144594855103115 });
            points.push_back({ -45.00000000000000000, -10.00000000000000000 });
            points.push_back({ -50.15607989177228632, -8.10584962679586418 });
            points.push_back({ -46.06190411138643981, -7.30698605989130634 });
            points.push_back({ -50.85508551281377265, -4.11153179227307053 });
            points.push_back({ -46.46133589483871873, -4.11153179227307053 });
            points.push_back({ -50.00000000000000000, -0.00000000000000000 });
            points.push_back({ -45.26304054448188197, -0.81621957879176543 });
            points.push_back({ -47.65963124519554839, 3.47767209332023830 });
            points.push_back({ -42.86644984376821554, 2.27937674296340020 });
            points.push_back({ -45.26304054448188197, 5.97412073989698467 });
            points.push_back({ -40.46985914305454912, 4.07681976849865713 });
            points.push_back({ -42.16744422272672921, 7.57184787370610213 });
            points.push_back({ -36.67525720025791713, 4.97554128126628648 });
            points.push_back({ -38.33287218113581218, 8.37728198503280908 });
            points.push_back({ -33.74759317166082440, 5.56879859172936609 });
            points.push_back({ -35.12317687450332215, 9.35165377454625002 });
            points.push_back({ -30.07936996408082564, 7.46022618313780761 });
            points.push_back({ -33.00248533262113426, 10.95650142786250392 });
            points.push_back({ -28.13062638505395441, 10.55528951453344000 });
            points.push_back({ -32.65858940691050805, 13.70766883354751009 });
            points.push_back({ -27.55746650886958093, 13.65035284592907239 });
            points.push_back({ -32.48664144405519494, 16.34420426399564263 });
            points.push_back({ -28.30257434790926752, 16.57346821446939344 });
            points.push_back({ -33.23174928309488507, 19.61121555824658813 });
            points.push_back({ -28.93305021171207869, 19.89779549633877664 });
            points.push_back({ -34.84169672855544064, 23.14528051715011614 });
            points.push_back({ -30.59145084137538007, 25.42590026149064641 });
            points.push_back({ -36.39666473606034458, 26.35888106599358949 });
            points.push_back({ -32.76840605188223776, 28.95049441183510197 });
            points.push_back({ -40.95790422474138381, 28.01751360733215890 });
            points.push_back({ -38.46995541273354036, 32.06043042684491695 });
            points.push_back({ -44.58616290891948353, 29.57248161483706284 });
            points.push_back({ -43.65318210441654401, 34.13372110351811983 });
            points.push_back({ -50.00000000000000000, 30.00000000000000000 });
            points.push_back({ -50.18404773593712775, 34.96303737418740809 });
            points.push_back({ -54.84895175845183246, 28.84682987800144005 });
            points.push_back({ -56.50758429979039477, 34.54837923885276751 });
            points.push_back({ -58.78820404413091438, 28.32850720883313755 });
            points.push_back({ -61.27615285613875784, 33.82272750201713762 });
            points.push_back({ -62.93478539747732015, 26.87720373516189198 });
            points.push_back({ -65.42273420948515650, 32.99341123134785647 });
            points.push_back({ -70.00000000000000000, 30.00000000000000000 });
            points.push_back({ -66.45937954782175439, 24.07826132165306277 });
            points.push_back({ -72.88658064550868687, 26.35888106599358949 });
            points.push_back({ -68.53267022449496437, 20.76099623897592750 });
            points.push_back({ -74.13055505151260149, 22.52329331414815528 });
            points.push_back({ -70.50229636733450889, 16.71807941946317300 });
            points.push_back({ -75.47819399135018159, 17.54739569013245415 });
            points.push_back({ -70.00000000000000000, 10.00000000000000000 });
            points.push_back({ -76.82583293118776169, 10.29087832177622452 });
            points.push_back({ -75.06353585601554812, 4.79665802859222268 });
            points.push_back({ -68.01434755532666543, 5.21131616392686503 });
            points.push_back({ -72.36825797634038793, -0.69756226459177939 });
            points.push_back({ -65.63006327715247323, 0.44274760757848525 });
            points.push_back({ -70.50229636733450889, -5.25880175327283794 });
            points.push_back({ -63.45310806664561909, -2.45985933976400650 });
            points.push_back({ -68.53267022449496437, -9.40538310661925436 });
            points.push_back({ -62.00180459297438063, -8.26507323444899100 });
            points.push_back({ -68.22167662299398216, -14.17395166296763342 });
            points.push_back({ -61.69081099147339842, -14.79593886596959607 });
            points.push_back({ -70.39863183350084341, -18.11320394864673133 });
            points.push_back({ -63.45310806664561909, -20.39382369298725806 });
            points.push_back({ -74.02689051767895023, -20.39382369298725806 });
            points.push_back({ -69.25832196133058005, -24.33307597866635419 });
            points.push_back({ -77.34415560035606063, -21.84512716665850363 });
            points.push_back({ -76.20384572818581148, -25.88804398617126168 });
            points.push_back({ -82.00905962287076534, -21.84512716665850363 });
            points.push_back({ -82.63104682587272976, -26.61369572300688446 });
            points.push_back({ -85.42998923938155542, -20.49748822682091998 });
            points.push_back({ -89.05824792355964803, -24.95506318166831861 });
            points.push_back({ -88.85091885589233129, -16.97289407647646442 });
            points.push_back({ -92.68650660773775485, -20.60115276065458190 });
            points.push_back({ -91.33462652973419438, -13.94147876875362613 });
            points.push_back({ -96.23113620369645105, -16.89626908924809712 });
            points.push_back({ -97.41305233189423518, -13.43494328524028880 });
            points.push_back({ -93.02307814144531051, -12.25302715704250112 });
            points.push_back({ -98.84823620184869242, -10.14246264240359352 });
            points.push_back({ -94.71152975315644085, -9.12939167537691709 });
            points.push_back({ -100.28342007180314965, -6.84998199956689735 });
            points.push_back({ -95.80902330076867202, -5.66806587136910967 });
            points.push_back({ -101.63418136117203971, -3.81076909848687073 });
            points.push_back({ -96.65324910662423008, -3.21981103438797689 });
            points.push_back({ -102.14071684468538592, 0.83247283371872527 });
            points.push_back({ -96.90651684838090318, 1.17016315606095045 });
            points.push_back({ -101.63418136117203971, 5.47571476592432127 });
            points.push_back({ -96.23113620369645105, 5.39129218533876564 });
            points.push_back({ -101.71860394175759268, 9.19030831168879914 });
            points.push_back({ -96.56882652603867712, 9.44357605344546691 });
            points.push_back({ -103.66032329522539612, 12.48278895452549442 });
            points.push_back({ -98.25727813774979325, 13.58028250213772559 });
            points.push_back({ -105.00000000000000000, 15.00000000000000000 });
            points.push_back({ -100.36784265238870262, 16.87276314497442087 });
            points.push_back({ -107.03722651864764259, 17.88583411200109552 });
            points.push_back({ -103.23821039229760288, 20.08082120722556141 });
            points.push_back({ -110.92066522558322106, 18.64563733727110417 });
            points.push_back({ -108.47241038860208562, 22.36023088303558026 });
            points.push_back({ -115.14179425486102559, 20.67177927132445348 });
            points.push_back({ -112.77796199846545733, 24.38637281708893312 });
            points.push_back({ -117.75889425301326696, 23.28887926947669840 });
            points.push_back({ -115.31063941603214573, 26.41251475114228242 });
            points.push_back({ -121.47348779877773950, 26.32809217055672590 });
            points.push_back({ -118.01216199476994007, 29.78941797456453600 });
            points.push_back({ -122.90867166873219674, 28.86076958812341431 });
            points.push_back({ -120.20714908999440240, 32.49094055330233743 });
            points.push_back({ -124.93481360278553893, 32.99747603681567654 });
            points.push_back({ -119.36292328413883013, 35.36130829321125191 });
            points.push_back({ -124.25943295810108680, 37.64071796902126721 });
            points.push_back({ -117.50562651125659386, 37.04975990492237514 });
            points.push_back({ -120.00000000000000000, 40.00000000000000000 });
            points.push_back({ -113.20007490139323636, 38.31609861370571934 });
            points.push_back({ -114.63525877134769360, 41.10204377302908085 });
            points.push_back({ -109.14779103328653775, 38.31609861370571934 });
            points.push_back({ -109.99201683914209582, 42.28395990122686499 });
            points.push_back({ -104.75781684283761308, 38.65378893604794541 });
            points.push_back({ -105.34877490693651225, 42.62165022356909105 });
            points.push_back({ -101.46533620000093379, 38.48494377487683238 });
            points.push_back({ -101.80302652234315985, 42.45280506239797802 });
            points.push_back({ -97.32862975130868222, 38.14725345253460631 });
            points.push_back({ -97.91958781540756718, 42.95934054591131712 });
            points.push_back({ -93.36076846378753658, 38.31609861370571934 });
            points.push_back({ -93.69845878612976264, 42.70607280415465112 });
            points.push_back({ -89.89944265977973714, 38.82263409721905845 });
            points.push_back({ -90.15271040153641025, 42.45280506239797802 });
            points.push_back({ -86.77580717811416378, 38.99147925839017148 });
            points.push_back({ -87.45118782279860170, 43.04376312649687009 });
            points.push_back({ -83.82101685761969634, 38.99147925839017148 });
            points.push_back({ -84.24312976054747537, 42.53722764298353809 });
            points.push_back({ -79.59988782834189180, 38.65378893604794541 });
            points.push_back({ -79.68431040892744477, 42.36838248181242506 });
            points.push_back({ -73.85915234852406286, 39.32916958073239755 });
            points.push_back({ -75.96971686316297223, 43.71914377118131512 });
            points.push_back({ -70.00000000000000000, 40.00000000000000000 });
            points.push_back({ -71.49532009212849459, 43.63472119059576215 });
            points.push_back({ -65.00000000000000000, 40.00000000000000000 });
            points.push_back({ -66.51438783758068496, 44.14125667410910125 });
            points.push_back({ -61.02692009951952912, 40.34224054775906865 });
            points.push_back({ -60.77365235776286312, 43.71914377118131512 });
            points.push_back({ -56.21483300614283252, 40.34224054775906865 });
            points.push_back({ -55.96156526438615941, 44.05683409352354118 });
            points.push_back({ -51.44512072066560648, 39.67780785595007131 });
            points.push_back({ -52.29001976224635939, 44.15577277632807807 });
            points.push_back({ -46.71368608781337883, 41.19862613079542513 });
            points.push_back({ -49.75532263750410067, 45.93006076364766699 });
            points.push_back({ -43.67204953812266410, 43.98679296801192606 });
            points.push_back({ -47.22062551276183484, 47.95781846344147681 });
            points.push_back({ -41.72878174248693028, 46.60597999691226789 });
            points.push_back({ -44.17898896307112011, 50.32353577986759774 });
            points.push_back({ -36.82836730131855774, 46.85944970938649590 });
            points.push_back({ -38.51816538448006355, 51.33741462976450265 });
            points.push_back({ -32.09693266846633009, 46.26802038027997099 });
            points.push_back({ -32.18142257262440609, 51.08394491729027465 });
            points.push_back({ -28.37937688551101445, 44.83169200959268608 });
            points.push_back({ -26.77406870650758108, 49.98557616323529373 });
            points.push_back({ -23.14100282771033434, 43.64883335137962206 });
            points.push_back({ -22.80304321107803389, 48.71822760086416082 });
            points.push_back({ -17.64915905743543334, 45.25414153038305898 });
            points.push_back({ -20.00000000000000000, 50.00000000000000000 });
            points.push_back({ -13.84711337032203815, 48.46475788838993282 });
            points.push_back({ -17.31119944080313289, 52.18231367134525556 });
            points.push_back({ -12.66425471210898301, 51.08394491729027465 });
            points.push_back({ -17.22670953664505689, 55.05497041271982539 });
            points.push_back({ -11.22792634142169987, 54.63252089192945249 });
            points.push_back({ -17.14221963248698088, 57.75864734577824322 });
            points.push_back({ -12.15731528716053056, 57.33619782498787032 });
            points.push_back({ -18.83201771564849025, 60.88477379962704106 });
            points.push_back({ -13.67813356200588792, 61.13824351210126906 });
            points.push_back({ -19.59242685307116716, 63.50396082852738289 });
            points.push_back({ -15.28344174100932129, 63.92641034931776289 });
            points.push_back({ -22.37496103001045356, 65.90508343812452097 });
            points.push_back({ -17.21463955033675930, 67.85237456252970389 });
            points.push_back({ -24.32225215441561872, 69.41020746205383318 });
            points.push_back({ -18.48037878120011968, 70.96804036157797668 });
            points.push_back({ -25.88008505393975511, 73.30478971086418483 });
            points.push_back({ -21.01185724292683688, 74.18107071684650577 });
            points.push_back({ -26.85373061614233947, 78.07565296565684321 });
            points.push_back({ -21.01185724292683688, 77.39410107211503487 });
            points.push_back({ -24.90643949173717075, 80.89922509604434708 });
            points.push_back({ -18.18828511253934366, 79.73085042140124301 });
            points.push_back({ -20.23294079316476868, 83.52806811399132414 });
            points.push_back({ -15.00000000000000000, 80.00000000000000000 });
            points.push_back({ -15.00000000000000000, 85.00000000000000000 });
            points.push_back({ -11.27540162090100040, 79.53612130896073040 });
            points.push_back({ -9.32811049649583346, 84.11225545131287618 });
            points.push_back({ -7.28345481587040755, 77.49146562833529117 });
            points.push_back({ -4.36251812926265714, 82.06759977068745116 });
            points.push_back({ -5.00000000000000000, 75.00000000000000000 });
            points.push_back({ -0.37057132423206435, 77.49146562833529117 });
            points.push_back({ -3.09677889839929854, 70.87067580535772038 });
            points.push_back({ 2.74509447481620317, 72.03905048000081024 });
            points.push_back({ -2.12313333619671463, 65.51562521324349575 });
            points.push_back({ 3.91346914945930324, 66.00244799434479148 });
            points.push_back({ -1.34421688643464798, 60.84212651467107946 });
            points.push_back({ 4.10819826189981985, 60.84212651467107946 });
            points.push_back({ -2.57753763314594186, 55.60607097415616806 });
            points.push_back({ 3.06318049363932765, 54.44900058917456676 });
            points.push_back({ -4.16850941249563345, 49.53145145300277363 });
            points.push_back({ 2.34001150302583172, 47.94047967365307272 });
            points.push_back({ -4.45777700874103200, 43.31219813372668170 });
            points.push_back({ 3.64171568613012475, 42.44439534499048250 });
            points.push_back({ -3.01143902751403969, 37.52684620881868938 });
            points.push_back({ 5.37732126360251517, 37.67148000694138688 });
            points.push_back({ 0.00000000000000000, 32.60929707264689625 });
            points.push_back({ 8.99316621666999616, 33.76636745762849046 });
            points.push_back({ 3.78634948425282403, 28.27028312896590023 });
            points.push_back({ 9.28243381291539471, 26.67931134961619932 });
            points.push_back({ 13.76608155471907047, 33.47709986138309546 });
            points.push_back({ 15.21241953594606144, 26.53467755149350182 });
            points.push_back({ 17.09265891154115380, 34.34490265011929466 });
            points.push_back({ 19.69606727774973720, 28.41491692708859773 });
            points.push_back({ 20.41923626836323535, 36.65904342008249017 });
            points.push_back({ 25.04751780828960861, 30.58442389892909574 });
            points.push_back({ 24.32434881767611401, 38.68391659380028358 });
            points.push_back({ 29.67579934821598542, 33.91100125575119506 });
            points.push_back({ 28.37409516511169016, 40.27488837314998449 });
            points.push_back({ 34.15944709001966118, 36.22514202571439057 });
            points.push_back({ 33.00237670503806697, 42.29976154686778500 });
            points.push_back({ 39.36626382243683508, 37.52684620881868938 });
            points.push_back({ 39.22163002431413048, 43.60146572997208381 });
            points.push_back({ 45.00698194922210149, 36.80367721820518767 });
            points.push_back({ 46.59795372857179530, 43.02293053748127960 });
            points.push_back({ 50.64770007600736790, 34.48953644824199216 });
            points.push_back({ 54.84208022156564510, 38.53928279567758608 });
            points.push_back({ 52.52793945160246381, 27.83638173459780063 });
            points.push_back({ 59.18109416524662691, 31.59686048578799600 });
            points.push_back({ 51.66013666286626460, 21.76176221344440620 });
            points.push_back({ 59.61499555961471941, 22.62956500218060540 });
            points.push_back({ 48.62282690228958160, 17.27811447164071268 });
            points.push_back({ 55.56524921217914681, 13.37300192232781804 });
            points.push_back({ 45.00698194922210149, 14.81933990355481612 });
            points.push_back({ 47.61039031543068489, 8.60008658427872419 });
            points.push_back({ 39.94479901492763219, 13.80690331669591764 });
            points.push_back({ 40.08943281305032968, 6.28594581431552690 });
            points.push_back({ 35.31651747500125538, 13.22836812420511876 });
            points.push_back({ 33.58091189752886407, 6.43057961243822618 });
            points.push_back({ 29.53116555009328437, 13.80690331669591764 });
            points.push_back({ 25.04751780828960861, 6.71984720868362562 });
            points.push_back({ 24.90288401016691111, 14.38543850918671652 });
            points.push_back({ 19.69606727774973720, 6.71984720868362562 });
            points.push_back({ 17.96046170027734590, 14.09617091294131797 });
            points.push_back({ 15.35705333406876072, 7.44301619929712555 });
            points.push_back({ 12.17510977536937844, 15.39787509604561500 });
            points.push_back({ 11.30730698663318279, 8.16618518991062459 });
            points.push_back({ 4.65415227298901879, 13.95153711481861691 });
            points.push_back({ 7.98072962981110123, 7.00911480492902594 });
            points.push_back({ 0.00000000000000000, 10.00000000000000000 });
            points.push_back({ 4.65415227298901879, 5.12887542933392826 });
            points.push_back({ -1.13119965191894956, 4.83960783308852793 });
            points.push_back({ 3.35244808988472620, 2.23619946687993121 });
            points.push_back({ -1.85244808988472620, 2.44019946687993121 });


		}

    protected:
        Camera *camera;
        Camera* minimap_camera;
        glm::mat4 main_transform;
        glm::mat4 ground_transformation;
        glm::mat4 projectionMatrix;
        glm::vec3 endPos, midPos, startPos;
        float translateX, translateY, translateZ;
        float initial_camera_X;
        float initial_camera_Y;
        float initial_camera_Z;
        float truck_center_X;
        float truck_center_Y;
        float truck_center_Z;
        float scaleX, scaleY, scaleZ;
        float angularStepOX, angularStepOY, angularStepOZ;
        GLenum polygonMode;
        GLfloat translateZSine, translateXSine, translateYSine;
        GLfloat angleX, angleZ;
        GLfloat posX, posZ, angle;
        GLfloat angleJump;
        GLfloat truck_speed = 7;
        GLfloat rotation_angle_OY = 0;
        ViewportArea miniViewportArea;
        
    };
}   // namespace m1

