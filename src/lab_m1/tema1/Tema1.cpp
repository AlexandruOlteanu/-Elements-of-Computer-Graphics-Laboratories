#include "lab_m1/tema1/Tema1.h"

#include <vector>
#include <iostream>
#include <chrono>
#include <random>

#include "lab_m1/tema1/transform2D.h"
#include "lab_m1/tema1/Triangle.h"
#include "lab_m1/tema1/Circle.h"

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
vector<bool> available;
double time_elapsed = 0;
double time_till_escape;
double duck_speed;

mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());


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

    initial_spawn_x = rng() % (resolution.x - 200);
    if (initial_spawn_x < 200) {
        initial_spawn_x = 200;
    }
    initial_spawn_y = 50;

    duck_angle = rng() % 120 + 30;
    trX = 0;
    trY = 0;
    // Initialize angularStep
    fly_angle = 0;
    number_of_lifes = 3;
    life_radius = 17;

    for (int i = 0; i < number_of_lifes; ++i) {
        Mesh* life = Circle::CreateCircle("life_" + to_string(i), 0, 0, life_radius, glm::vec3(1, 0, 0), true);
        lifes.push_back(life);
        available.push_back(true);
        AddMeshToList(life);
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


void Tema1::Update(float deltaTimeSeconds) {


    glm::ivec2 resolution = window->GetResolution();
    double beak_top_x = initial_spawn_x + screen_ratio * 2.08 + 2 * beak_side;
    double beak_top_y = initial_spawn_y + screen_ratio * 0.43 + beak_side / 2;

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
    cout << time_elapsed << '\n';
    
    trX += cos(grad_to_radian(duck_angle)) * deltaTimeSeconds * duck_speed;
    trY += sin(grad_to_radian(duck_angle)) * deltaTimeSeconds * duck_speed;

    if (time_elapsed > time_till_escape) {
        duck_angle = 90;
        if (time_elapsed > time_till_escape + 3) {
            time_elapsed = 0;
            trX = 0, trY = 0;
            initial_spawn_x = rng() % (resolution.x - 200);
            if (initial_spawn_x < 200) {
                initial_spawn_x = 200;
            }
            initial_spawn_y = 50;
            duck_angle = rng() % 120 + 30;
            int sz = available.size();
            for (int i = sz - 1; i >= 0; --i) {
                if (available[i]) {
                    available[i] = false;
                    break;
                }
            }
        }
    }
    else {

        if (beak_top_x + trX < 0 || beak_top_x + trX > resolution.x) {
            duck_angle = 180 - duck_angle;
        }
        else if (beak_top_y + trY < 0 || beak_top_y + trY > resolution.y) {
            duck_angle = -duck_angle;
        }
    }
    glm::mat3 main_transformation = glm::mat3(1);
    main_transformation *= transform2D::Translate(trX, trY);
    main_transformation *= transform2D::Translate(initial_spawn_x, initial_spawn_y);
    main_transformation *= transform2D::Translate(beak_top_x - initial_spawn_x, beak_top_y - initial_spawn_y);
    main_transformation *= transform2D::Rotate(grad_to_radian(duck_angle));
    main_transformation *= transform2D::Translate(-beak_top_x + initial_spawn_x, -beak_top_y + initial_spawn_y);

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
        if (!available[contor]) {
            continue;
        }
        ++contor;
        RenderMesh2D(meshes[life->GetMeshID()], shaders["VertexColor"], life_transformation);
    }

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
