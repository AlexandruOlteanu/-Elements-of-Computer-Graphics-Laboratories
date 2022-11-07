#include "lab_m1/tema1/Tema1.h"

#include <vector>
#include <iostream>
#include <chrono>
#include <random>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/Triangle.h"
#include "lab_m1/tema1/Circle.h"
#include "lab_m1/tema1/Rectangle.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}

double direction_X, direction_Y;
double screen_ratio;
double wing_side;
double body_side;
double beak_side;
double radius;
double beak_X, beak_Y;
double duck_angle;
double fly_angle;
bool type;
bool fly_type;
double initial_spawn_x;
double initial_spawn_y;
int number_of_lifes;
double life_radius;
vector<Mesh*> lifes;
int number_of_bullets;
int shot_bullets;
vector<Mesh*>bullets;
double bullet_side;
vector<bool> available_life;
vector<bool> available_bullet;
vector<Mesh*>current_scores;
vector<bool> available_scores;
double time_elapsed = 0;
double time_till_escape;
double duck_speed;
bool hit_duck;
double hit_distance;
double background_l, background_L;
double score_border_l, score_border_L;

struct intersection_rectangle {
    double x1, y1, x2, y2, x3, y3, x4, y4;
}rectangle;

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());


void remove_life() {
    int sz = available_life.size();
    for (int i = sz - 1; i >= 0; --i) {
        if (available_life[i]) {
            available_life[i] = false;
            break;
        }
    }
}

void remove_bullet() {
    int sz = available_bullet.size();
    for (int i = sz - 1; i >= 0; --i) {
        if (available_bullet[i]) {
            available_bullet[i] = false;
            break;
        }
    }
}

void reset_bullets() {
    shot_bullets = 0;
    int sz = available_bullet.size();
    for (int i = 0; i < sz; ++i) {
        available_bullet[i] = true;
    }
}

void init_duck_values(glm::ivec2 resolution) {
    time_elapsed = 0;
    direction_X = 0, direction_Y = 0;
    initial_spawn_x = rng() % (resolution.x - 200);
    if (initial_spawn_x < 200) {
        initial_spawn_x = 200;
    }
    initial_spawn_y = 50;
    duck_angle = rng() % 120 + 30;
}

void increase_score() {
    int sz = available_scores.size();
    for (int i = 0; i < sz; ++i) {
        if (!available_scores[i]) {
            available_scores[i] = true;
            break;
        }
    }
}


void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);

    // Default : 16.41
    screen_ratio = resolution.x / 16.41;
    wing_side = screen_ratio * 0.4871;
    body_side = screen_ratio;
    beak_side = screen_ratio * 0.1333;
    beak_X = 0;
    beak_Y = 0;
    radius = screen_ratio * 0.3666;
    type = 0;
    fly_type = 0;
    duck_speed = 150;
    time_till_escape = 20;
    hit_duck = false;

    initial_spawn_x = rng() % (resolution.x - 200);
    if (initial_spawn_x < 200) {
        initial_spawn_x = 200;
    }
    initial_spawn_y = 50;

    duck_angle = rng() % 120 + 30;
    direction_X = 0;
    direction_Y = 0;
    fly_angle = 0;
    number_of_lifes = 3;
    life_radius = 17;
    number_of_bullets = 3;
    shot_bullets = 0;
    bullet_side = 17;
    background_l = 150;
    background_L = 1280;
    score_border_l = 28;
    score_border_L = 280;
    
    for (int i = 0; i < number_of_lifes; ++i) {
        Mesh* life = Circle::CreateCircle("life_" + to_string(i), 0, 0, life_radius, glm::vec3(1, 0, 0), true);
        lifes.push_back(life);
        available_life.push_back(true);
        AddMeshToList(life);
    }

    for (int i = 0; i < number_of_bullets; ++i) {
        Mesh* bullet = Rectangle::CreateRectangle("bullet_" + to_string(i), corner, bullet_side, 2 * bullet_side, glm::vec3(0, 1, 0), true, "vertical");
        bullets.push_back(bullet);
        available_bullet.push_back(true);
        AddMeshToList(bullet);
    }

    for (int i = 0; i < 5; ++i) {
        Mesh* score = Rectangle::CreateRectangle("score_" + to_string(i), corner, score_border_l - 3, score_border_L / 5, glm::vec3(0, 0, 1), true, "horizontal");
        current_scores.push_back(score);
        available_scores.push_back(false);
        AddMeshToList(score);
    }

    Mesh* head = Circle::CreateCircle("head", 0, 0, radius, glm::vec3(0.0f, 0.2f, 0.0f), true);
    AddMeshToList(head);

    Mesh* first_wing = Triangle::CreateTriangle("first_wing", corner, wing_side, glm::vec3(0.3f, 0.2f, 0.0f), true, "right", 1);
    AddMeshToList(first_wing);

    Mesh* second_wing = Triangle::CreateTriangle("second_wing", corner, wing_side, glm::vec3(0.3f, 0.2f, 0.0f), true, "right", 2);
    AddMeshToList(second_wing);

    Mesh* body = Triangle::CreateTriangle("body", corner, body_side, glm::vec3(0.3f, 0.2f, 0.0f), true, "isoscel", 0);
    AddMeshToList(body);

    Mesh* beak = Triangle::CreateTriangle("beak", corner, beak_side, glm::vec3(1.0f, 0.7f, 0.0f), true, "isoscel", 0);
    AddMeshToList(beak);

    Mesh* ground = Rectangle::CreateRectangle("ground", corner, background_l, background_L, glm::vec3(0, 0.2, 0), true, "horizontal");
    AddMeshToList(ground);

    Mesh* score_border = Rectangle::CreateRectangle("score_border", corner, score_border_l, score_border_L + 2, glm::vec3(1, 1, 1), false, "horizontal");
    AddMeshToList(score_border);

}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);
}

double grad_to_radian(double grad) {
    double pi = acos(-1);
    return grad * pi / 180;
}

double calculate_distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void Tema1::Update(float deltaTimeSeconds) {

    glm::ivec2 resolution = window->GetResolution();
    double beak_top_x = initial_spawn_x + screen_ratio * 2.08 + 2 * beak_side;
    double beak_top_y = initial_spawn_y + screen_ratio * 0.43 + beak_side / 2;

    double body_center_x = (initial_spawn_x + beak_top_x) / 2;
    double body_center_y = beak_top_y;

    if (!fly_type) {
        fly_angle += deltaTimeSeconds;
    }
    else {
        fly_angle -= deltaTimeSeconds;
    }

    if (fly_angle > 0.35) {
        fly_type ^= 1;
    }
    if (fly_angle < -0.35) {
        fly_type ^= 1;
    }

    time_elapsed += deltaTimeSeconds;
    
    direction_X += cos(grad_to_radian(duck_angle)) * deltaTimeSeconds * duck_speed;
    direction_Y += sin(grad_to_radian(duck_angle)) * deltaTimeSeconds * duck_speed;

    rectangle.x1 = rectangle.x3 = initial_spawn_x + direction_X;
    rectangle.x2 = rectangle.x4 = beak_top_x + direction_X;
    rectangle.y1 = rectangle.y2 = body_center_y - (beak_top_x - body_center_x) + direction_Y;
    rectangle.y3 = rectangle.y4 = body_center_y + (beak_top_x - body_center_x) + direction_Y;
    hit_distance = calculate_distance(rectangle.x1, rectangle.y1, rectangle.x4, rectangle.y4);
    if (time_elapsed > time_till_escape) {
        duck_angle = 90;
        if (body_center_y + direction_Y > resolution.y + 100) {
            init_duck_values(resolution);
            remove_life();
            reset_bullets();
        }
    }
    else {

        if (body_center_x + direction_X < 0 || body_center_x + direction_X > resolution.x) {
            duck_angle = 180 - duck_angle;
        }
        else if (body_center_y + direction_Y < 0 || body_center_y + direction_Y > resolution.y) {
            duck_angle = -duck_angle;
        }
    }

    if (hit_duck) {
        duck_angle = 270;
        if (body_center_y + direction_Y < 0) {
            init_duck_values(resolution);
            reset_bullets();
            increase_score();
            hit_duck = false;
        }
    }
    
    glm::mat3 main_transformation = glm::mat3(1);
    main_transformation *= transform2D::Translate(direction_X, direction_Y);
    main_transformation *= transform2D::Translate(initial_spawn_x, initial_spawn_y);
    main_transformation *= transform2D::Translate(body_center_x - initial_spawn_x, body_center_y - initial_spawn_y);
    main_transformation *= transform2D::Rotate(grad_to_radian(duck_angle));
    main_transformation *= transform2D::Translate(-body_center_x + initial_spawn_x, -body_center_y + initial_spawn_y);

    glm::mat3 body_transformation = glm::mat3(1);
    body_transformation = main_transformation;

    glm::mat3 beak_tranformation = glm::mat3(1);
    beak_tranformation = body_transformation;
    beak_tranformation *= transform2D::Translate(screen_ratio * 2.08, screen_ratio * 0.43);

    glm::mat3 head_transformation = glm::mat3(1);
    head_transformation = body_transformation;
    head_transformation *= transform2D::Translate(screen_ratio * 1.72, screen_ratio * 0.5);

    glm::mat3 first_wing_transformation = glm::mat3(1);
    first_wing_transformation = body_transformation;
    first_wing_transformation *= transform2D::Translate(screen_ratio * 1.2, screen_ratio * 0.5);
    first_wing_transformation *= transform2D::Rotate(grad_to_radian(-90));
    first_wing_transformation *= transform2D::Rotate(-fly_angle);
    

    glm::mat3 second_wing_transformation = glm::mat3(1);
    second_wing_transformation = body_transformation;
    second_wing_transformation *= transform2D::Translate(screen_ratio * 1.2, screen_ratio * 0.5);
    second_wing_transformation *= transform2D::Rotate(grad_to_radian(90));
    second_wing_transformation *= transform2D::Rotate(fly_angle);

    int contor = 0;
    for (auto life : lifes) {
        glm::mat3 life_transformation = glm::mat3(1);
        life_transformation *= transform2D::Translate(resolution.x - 300, resolution.y - 50);
        life_transformation *= transform2D::Translate(contor * 50, 0);
        if (!available_life[contor]) {
            continue;
        }
        ++contor;
        RenderMesh2D(meshes[life->GetMeshID()], shaders["VertexColor"], life_transformation);
    }
    
    contor = 0;
    for (auto bullet : bullets) {
        glm::mat3 bullet_transformation = glm::mat3(1);
        bullet_transformation *= transform2D::Translate(resolution.x - 150, resolution.y - 65);
        bullet_transformation *= transform2D::Translate(contor * 50, 0);
        if (!available_bullet[contor]) {
            continue;
        }
        ++contor;
        RenderMesh2D(meshes[bullet->GetMeshID()], shaders["VertexColor"], bullet_transformation);
    }

    contor = 0;
    for (auto score : current_scores) {
        glm::mat3 score_transformation = glm::mat3(1);
        score_transformation *= transform2D::Translate(resolution.x - 309, resolution.y - 118);
        score_transformation *= transform2D::Translate(contor * score_border_L / 5, 0);
        if (!available_scores[contor]) {
            continue;
        }
        ++contor;
        RenderMesh2D(meshes[score->GetMeshID()], shaders["VertexColor"], score_transformation);
    }

    glm::mat3 score_transformation = glm::mat3(1);
    score_transformation *= transform2D::Translate(resolution.x - 310, resolution.y - 120);
    RenderMesh2D(meshes["score_border"], shaders["VertexColor"], score_transformation);

    RenderMesh2D(meshes["ground"], shaders["VertexColor"], glm::mat3(1));

    RenderMesh2D(meshes["beak"], shaders["VertexColor"], beak_tranformation);

    RenderMesh2D(meshes["head"], shaders["VertexColor"], head_transformation);

    RenderMesh2D(meshes["body"], shaders["VertexColor"], body_transformation);

    RenderMesh2D(meshes["first_wing"], shaders["VertexColor"], first_wing_transformation);

    RenderMesh2D(meshes["second_wing"], shaders["VertexColor"], second_wing_transformation);
}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button press event

    if (shot_bullets >= number_of_bullets) {
        return;
    }
    ++shot_bullets;
    remove_bullet();
    glm::ivec2 resolution = window->GetResolution();
    mouseY = resolution.y - mouseY;
    bool consider = true;
    vector<pair<double, double>> points;
    points.push_back({ rectangle.x1, rectangle.y1 });
    points.push_back({ rectangle.x2, rectangle.y2 });
    points.push_back({ rectangle.x3, rectangle.y3 });
    points.push_back({ rectangle.x4, rectangle.y4 });

    for (auto point : points) {
        double distance = calculate_distance(mouseX, mouseY, point.first, point.second);
        if (distance > hit_distance) {
            consider = false;
        }
    }
    if (consider) {
        hit_duck = true;
    }

}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
