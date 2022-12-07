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
        void Tema2::MyRenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix);
        void OnInputUpdate(float deltaTime, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
		void Tema2::create_road();
		void Tema2::render_road();
        void Tema2::create_trees();
        void Tema2::render_trees();
        void Tema2::update_camera();
        void Tema2::update_truck();
        void Tema2::render_ground();
        void Tema2::create_obstacles();
        void Tema2::render_obstacles();
        void Tema2::update_obstacles_points();
        void Tema2::create_parallelepiped(std :: string name, double point1_x, double point1_y, double point2_x, double point2_y, double height1, double height2, glm::vec3 color);
		void extract_road_points(std :: vector<std :: pair<double, double>> &first_road_line) {
            first_road_line.push_back({ -0.50000000000000000, -0.00000000000000000 });
            first_road_line.push_back({ -0.84200522012896695, -1.72259195953113986 });
            first_road_line.push_back({ -1.37161397430853738, -3.20549647123393955 });
            first_road_line.push_back({ -2.00714447932402207, -4.52951835668286762 });
            first_road_line.push_back({ -2.90747936142929220, -5.80057936671383878 });
            first_road_line.push_back({ -3.75485336811660542, -6.75387512423706760 });
            first_road_line.push_back({ -4.86703175189370363, -7.76013175717825288 });
            first_road_line.push_back({ -6.08513188650671566, -8.76638839011943816 });
            first_road_line.push_back({ -7.51507552279155711, -9.66672327222470962 });
            first_road_line.push_back({ -8.83909740824048384, -10.67297990516589579 });
            first_road_line.push_back({ -10.16311929368941058, -11.46739303643525254 });
            first_road_line.push_back({ -11.43418030372037997, -12.31476704312256665 });
            first_road_line.push_back({ -12.22859343498973494, -13.00325842355600869 });
            first_road_line.push_back({ -13.07596744167704905, -14.11543680733310779 });
            first_road_line.push_back({ -13.50000000000000000, -15.00000000000000000 });
            first_road_line.push_back({ -13.76445882211048932, -16.28683269946935042 });
            first_road_line.push_back({ -13.71149794669253374, -17.66381546033623806 });
            first_road_line.push_back({ -13.34077181876683404, -19.09375909662107773 });
            first_road_line.push_back({ -12.65228043833339200, -20.52370273290592095 });
            first_road_line.push_back({ -11.59306292997425025, -21.42403761501119419 });
            first_road_line.push_back({ -10.74568892328693792, -22.16548987086259359 });
            first_road_line.push_back({ -9.52758878867392589, -22.64213774962420800 });
            first_road_line.push_back({ -8.20356690322499915, -22.95990300213194857 });
            first_road_line.push_back({ -6.77362326694015771, -23.17174650380377798 });
            first_road_line.push_back({ -5.23775787981940333, -23.01286387754990770 });
            first_road_line.push_back({ -3.80781424353456277, -22.64213774962420800 });
            first_road_line.push_back({ -2.21898798099585060, -21.79476374293689389 });
            first_road_line.push_back({ -0.78904434471100959, -20.94738973624957978 });
            first_road_line.push_back({ 0.64089929157383085, -19.88817222789043626 });
            first_road_line.push_back({ 1.85899942618684344, -18.77599384411333716 });
            first_road_line.push_back({ 2.65341255745619931, -17.39901108324644952 });
            first_road_line.push_back({ 3.50078656414351208, -15.86314569612569336 });
            first_road_line.push_back({ 4.50704319708469647, -14.59208468609472220 });
            first_road_line.push_back({ 5.77810420711566586, -13.90359330566128016 });
            first_road_line.push_back({ 7.26100871881846377, -13.26806280064579369 });
            first_road_line.push_back({ 8.79687410593921726, -12.95029754813805134 });
            first_road_line.push_back({ 10.43866124389588812, -12.89733667272009399 });
            first_road_line.push_back({ 11.86860488018072779, -13.10918017439192340 });
            first_road_line.push_back({ 13.19262676562965453, -13.42694542689966575 });
            first_road_line.push_back({ 14.94033565442223832, -14.38024118442289456 });
            first_road_line.push_back({ 16.50000000000000000, -15.00000000000000000 });
            first_road_line.push_back({ 17.32357504823030325, -16.44571532572322070 });
            first_road_line.push_back({ 17.80022292699191766, -17.98158071284397863 });
            first_road_line.push_back({ 17.80022292699191766, -19.62336785080065127 });
            first_road_line.push_back({ 17.27061417281234768, -21.21219411333936478 });
            first_road_line.push_back({ 16.42324016612503357, -22.80102037587807828 });
            first_road_line.push_back({ 15.20514003151202331, -24.12504226132700680 });
            first_road_line.push_back({ 13.45743114271943952, -25.02537714343227648 });
            first_road_line.push_back({ 11.33899612600115780, -25.66090764844776473 });
            first_road_line.push_back({ 9.37944373553674637, -25.81979027470163501 });
            first_road_line.push_back({ 7.89653922383394846, -25.50202502219389089 });
            first_road_line.push_back({ 6.50000000000000000, -25.00000000000000000 });
            first_road_line.push_back({ 4.77184757417448147, -24.60169014008862121 });
            first_road_line.push_back({ 3.18302131163576973, -24.81353364176045062 });
            first_road_line.push_back({ 1.50000000000000000, -25.00000000000000000 });
            first_road_line.push_back({ 0.27017316364813149, -25.55498589761185002 });
            first_road_line.push_back({ -0.63016171845713842, -26.24347727804529029 });
            first_road_line.push_back({ -1.37161397430853738, -27.46157741265830410 });
            first_road_line.push_back({ -1.68937922681627972, -28.73263842268927704 });
            first_road_line.push_back({ -1.84826185307015090, -30.26850380981003852 });
            first_road_line.push_back({ -2.11306623015993633, -31.69844744609488174 });
            first_road_line.push_back({ -2.48379235808563559, -32.91654758070789910 });
            first_road_line.push_back({ -3.11932286310112072, -34.02872596448499820 });
            first_road_line.push_back({ -4.12557949604230512, -35.40570872535188585 });
            first_road_line.push_back({ -5.23775787981940333, -36.57084798454694408 });
            first_road_line.push_back({ -6.29697538817854419, -37.36526111581630261 });
            first_road_line.push_back({ -7.72691902446338474, -38.42447862417544258 });
            first_road_line.push_back({ -9.10390178533026884, -39.16593088002684198 });
            first_road_line.push_back({ -10.74568892328693792, -40.06626576213211877 });
            first_road_line.push_back({ -12.06971080873586466, -40.75475714256555904 });
            first_road_line.push_back({ -13.18188919251296198, -41.39028764758104018 });
            first_road_line.push_back({ -14.66479370421576078, -41.97285727717856929 });
            first_road_line.push_back({ -16.04177646508264488, -42.60838778219405754 });
            first_road_line.push_back({ -17.41875922594952897, -43.13799653637362752 });
            first_road_line.push_back({ -18.90166373765232422, -43.93240966764298605 });
            first_road_line.push_back({ -20.38456824935512302, -44.56794017265847430 });
            first_road_line.push_back({ -21.92043363647587739, -45.15050980225600341 });
            first_road_line.push_back({ -23.35037727276071706, -45.94492293352535484 });
            first_road_line.push_back({ -25.30992966322513027, -46.31564906145105454 });
            first_road_line.push_back({ -27.53428643077932492, -46.20972731061514338 });
            first_road_line.push_back({ -29.49383882124373812, -45.52123593018170311 });
            first_road_line.push_back({ -30.71193895585675193, -44.35609667098664488 });
            first_road_line.push_back({ -31.65130600314507348, -43.06787633732022158 });
            first_road_line.push_back({ -31.81018862939894376, -41.79681532728925220 });
            first_road_line.push_back({ -31.59834512772711435, -40.36687169100441253 });
            first_road_line.push_back({ -31.22761899980141465, -38.77804542846570257 });
            first_road_line.push_back({ -30.53912761936797438, -37.34810179218086290 });
            first_road_line.push_back({ -29.42694923559087883, -36.28888428382171583 });
            first_road_line.push_back({ -27.83812297305216532, -35.44151027713440527 });
            first_road_line.push_back({ -26.24929671051345537, -34.64709714586504674 });
            first_road_line.push_back({ -24.55454869713883070, -33.95860576543160647 });
            first_road_line.push_back({ -23.17756593627195016, -33.21715350958020707 });
            first_road_line.push_back({ -21.90650492624098078, -32.26385775205697826 });
            first_road_line.push_back({ -21.00617004413571109, -31.04575761744396800 });
            first_road_line.push_back({ -20.37063953912022640, -29.77469660741299862 });
            first_road_line.push_back({ -19.94695253577657112, -28.50363559738202923 });
            first_road_line.push_back({ -19.73510903410474171, -27.07369196109718956 });
            first_road_line.push_back({ -19.84103078494065642, -25.64374832481234634 });
            first_road_line.push_back({ -20.42360041453818198, -24.37268731478137695 });
            first_road_line.push_back({ -21.32393529664345166, -23.36643068184019256 });
            first_road_line.push_back({ -22.54203543125646547, -22.41313492431696730 });
            first_road_line.push_back({ -23.86605731670539043, -21.61872179304760877 });
            first_road_line.push_back({ -25.24304007757226032, -20.93023041261416495 });
            first_road_line.push_back({ -26.67298371385709999, -20.34766078301663939 });
            first_road_line.push_back({ -27.89108384847011379, -19.34140415007545499 });
            first_road_line.push_back({ -29.05622310766516492, -18.86475627131384059 });
            first_road_line.push_back({ -30.32728411769613430, -18.54699101880609646 });
            first_road_line.push_back({ -31.91611038023484781, -18.44106926797018531 });
            first_road_line.push_back({ -33.29309314110172835, -18.49403014338814089 });
            first_road_line.push_back({ -34.82895852822247917, -18.65291276964201117 });
            first_road_line.push_back({ -36.15298041367140769, -18.86475627131384059 });
            first_road_line.push_back({ -37.42404142370237707, -18.65291276964201117 });
            first_road_line.push_back({ -39.01286768624108703, -18.22922576629835589 });
            first_road_line.push_back({ -40.38985044710796757, -17.38185175961104179 });
            first_road_line.push_back({ -41.44906795546711464, -16.32263425125190182 });
            first_road_line.push_back({ -42.40236371299033635, -14.89269061496706037 });
            first_road_line.push_back({ -43.24973771967764691, -13.25090347701039128 });
            first_road_line.push_back({ -43.77934647385721689, -11.71503808988963691 });
            first_road_line.push_back({ -44.30895522803679398, -10.02029007651501047 });
            first_road_line.push_back({ -44.52079872970861629, -8.16665943688651375 });
            first_road_line.push_back({ -43.99118997552904631, -6.73671580060167319 });
            first_road_line.push_back({ -43.50000000000000000, -5.00000000000000000 });
            first_road_line.push_back({ -42.61420721466216577, -4.03571115428586236 });
            first_road_line.push_back({ -41.44906795546711464, -3.13537627218059267 });
            first_road_line.push_back({ -40.17800694543614526, -2.18208051465736874 });
            first_road_line.push_back({ -38.85398505998721674, -1.70543263589575522 });
            first_road_line.push_back({ -37.26515879744850679, -1.75839351131371235 });
            first_road_line.push_back({ -35.72929341032774886, -1.81135438673166926 });
            first_road_line.push_back({ -34.24638889862495716, -2.12911963923941183 });
            first_road_line.push_back({ -32.97532788859398778, -2.71168926883693961 });
            first_road_line.push_back({ -31.65130600314505926, -3.29425889843446740 });
            first_road_line.push_back({ -30.43320586853204901, -4.24755465595769444 });
            first_road_line.push_back({ -29.16214485850107963, -5.30677216431683618 });
            first_road_line.push_back({ -27.67924034679828438, -6.15414617100414940 });
            first_road_line.push_back({ -25.93153145800570059, -6.73671580060167674 });
            first_road_line.push_back({ -24.28974432004903505, -6.73671580060167674 });
            first_road_line.push_back({ -22.80683980834623625, -6.41895054809393439 });
            first_road_line.push_back({ -21.48281792289731129, -6.04822442016823469 });
            first_road_line.push_back({ -20.26471778828430104, -5.46565479057070736 });
            first_road_line.push_back({ -19.36438290617903135, -4.77716341013726531 });
            first_road_line.push_back({ -18.25220452240193225, -3.77090677719608092 });
            first_road_line.push_back({ -16.92818263695300729, -2.44688489174715418 });
            first_road_line.push_back({ -16.02784775484773760, -0.75213687837252796 });
            first_road_line.push_back({ -15.76304337775795261, 1.04853288583801230 });
            first_road_line.push_back({ -15.39231724983225291, 2.74328089921263851 });
            first_road_line.push_back({ -15.81600425317590819, 4.64987241425909303 });
            first_road_line.push_back({ -16.66337825986322230, 5.92093342429006242 });
            first_road_line.push_back({ -17.72259576822236227, 7.24495530973898916 });
            first_road_line.push_back({ -18.88773502741741694, 8.46305544435200297 });
            first_road_line.push_back({ -20.47656128995612690, 9.62819470354705764 });
            first_road_line.push_back({ -21.37689617206139658, 11.26998184150373206 });
            first_road_line.push_back({ -21.53577879831527042, 12.64696460237061437 });
            first_road_line.push_back({ -21.21801354580752630, 14.18282998949136875 });
            first_road_line.push_back({ -20.68840479162795631, 15.93053887828395254 });
            first_road_line.push_back({ -19.84103078494064221, 17.20159988831492015 });
            first_road_line.push_back({ -18.46404802407376167, 18.41970002292793396 });
            first_road_line.push_back({ -17.61667401738644756, 19.74372190837686247 });
            first_road_line.push_back({ -16.29265213193752260, 20.80293941673600244 });
            first_road_line.push_back({ -14.65086499398085351, 21.27958729549761685 });
            first_road_line.push_back({ -12.69131260351644563, 21.70327429884127213 });
            first_road_line.push_back({ -10.99656459014182097, 21.54439167258740184 });
            first_road_line.push_back({ -9.14293395051332425, 21.22662642007965772 });
            first_road_line.push_back({ -7.18338156004891459, 20.59109591506417303 });
            first_road_line.push_back({ -5.27679004500246140, 19.63780015754094777 });
            first_road_line.push_back({ -3.31723765453805086, 19.21411315419728894 });
            first_road_line.push_back({ -1.51656789032751238, 19.10819140336137778 });
            first_road_line.push_back({ 0.23114099846506964, 19.10819140336137778 });
            first_road_line.push_back({ 2.03181076267560856, 19.16115227877933336 });
            first_road_line.push_back({ 3.88544140230410440, 19.16115227877933336 });
            first_road_line.push_back({ 5.58018941567872950, 19.16115227877933336 });
            first_road_line.push_back({ 7.27493742905335417, 19.21411315419728894 });
            first_road_line.push_back({ 9.07560719326389354, 19.10819140336137778 });
            first_road_line.push_back({ 11.19404220998217347, 19.00226965252546307 });
            first_road_line.push_back({ 13.31247722670045519, 19.10819140336137778 });
            first_road_line.push_back({ 15.11314699091099456, 19.05523052794341510 });
            first_road_line.push_back({ 16.91381675512153393, 18.94930877710750394 });
            first_road_line.push_back({ 18.82040827016798801, 18.84338702627158924 });
            first_road_line.push_back({ 20.51515628354261267, 18.94930877710750394 });
            first_road_line.push_back({ 22.10398254608132262, 19.00226965252545952 });
            first_road_line.push_back({ 23.63984793320207700, 18.63154352459975982 });
            first_road_line.push_back({ 24.91090894323304283, 18.20785652125610454 });
            first_road_line.push_back({ 26.49973520577175634, 17.41344338998674601 });
            first_road_line.push_back({ 27.87671796663863688, 16.46014763246352075 });
            first_road_line.push_back({ 29.35962247834143568, 15.40093012410437900 });
            first_road_line.push_back({ 30.63068348837240507, 13.97098648781953933 });
            first_road_line.push_back({ 31.00140961629810121, 12.48808197611674231 });
            first_road_line.push_back({ 31.05437049171606034, 10.74037308732415852 });
            first_road_line.push_back({ 31.00140961629810121, 9.09858594936748943 });
            first_road_line.push_back({ 30.52476173753649036, 7.61568143766469241 });
            first_road_line.push_back({ 29.94219210793896124, 6.13277692596189450 });
            first_road_line.push_back({ 29.09481810125165069, 4.86171591593092511 });
            first_road_line.push_back({ 27.55895271413089631, 3.90842015840769808 });
            first_road_line.push_back({ 25.70532207450240136, 3.16696790255629912 });
            first_road_line.push_back({ 23.85169143487390286, 2.74328089921264295 });
            first_road_line.push_back({ 22.15694342149927820, 2.63735914837672869 });
            first_road_line.push_back({ 20.35627365728873883, 2.53143739754081443 });
            first_road_line.push_back({ 18.76744739475002888, 2.47847652212285752 });
            first_road_line.push_back({ 16.75493412886766009, 2.53143739754081443 });
            first_road_line.push_back({ 14.95426436465712250, 2.53143739754081443 });
            first_road_line.push_back({ 13.25951635128249784, 2.84920265004855677 });
            first_road_line.push_back({ 11.77661183957970081, 3.48473315506404147 });
            first_road_line.push_back({ 9.87002032453324851, 4.06730278466156925 });
            first_road_line.push_back({ 8.12231143574066650, 4.27914628633339778 });
            first_road_line.push_back({ 6.53348517320195565, 4.01434190924361189 });
            first_road_line.push_back({ 4.57393278273754600, 3.59065490589995573 });
            first_road_line.push_back({ 3.19695002187066324, 3.11400702713834221 });
            first_road_line.push_back({ 2.08477163809356547, 2.58439827295877178 });
            first_road_line.push_back({ 0.65482800180872580, 1.68406339085350143 });

		}

    protected:
        Camera *camera;
        glm::mat4 main_transform;
        glm::mat4 ground_transformation;
        glm::mat4 projectionMatrix;
        float translateX, translateY, translateZ;
        float initial_camera_X;
        float initial_camera_Y;
        float initial_camera_Z;
        GLenum polygonMode;
        double obstacle_speed;
        GLfloat truck_speed = 2.5;
        GLfloat rotation_angle_OY = 0;
        ViewportArea miniViewportArea;
        
    };
}   // namespace m1

