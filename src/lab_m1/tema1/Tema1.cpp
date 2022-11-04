#include "lab_m1/tema1/Tema1.h"

#include <vector>
#include <iostream>

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

double wing_side;
double body_side;
double beak_side;
double radius;


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
    wing_side = 60;
    body_side = 120;
    beak_side = 16;
    radius = 45;
    cx = 2;

    // TODO(student): Compute coordinates of a square's center, and store
    // then in the `cx` and `cy` class variables (see the header). Use
    // `corner` and `squareSide`. These two class variables will be used
    // in the `Update()` function. Think about it, why do you need them?
    //cx = corner.x + squareSide / 2;
    //cy = corner.y + squareSide / 2;
    // Initialize tx and ty (the translation steps)
    translateX = 0;
    translateY = 0;
    float tranx = 0;
    float trany = 0;
    // Initialize sx and sy (the scale factors)
    scaleX = 1;
    scaleY = 1;
    trX = 0;
    trY = 0;
    int pul = false;
    depldr = false;
    // Initialize angularStep
    angularStep = 0;

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


void Tema1::Update(float deltaTimeSeconds)
{
    // TODO(student): Update steps for translation, rotation and scale,
    // in order to create animations. Use the class variables in the
    // class header, and if you need more of them to complete the task,
    // add them over there!
    /*if (trX < 400)
    {
        trX += deltaTimeSeconds * 100;
    }
    if (trY < 400)
    {
        trY += deltaTimeSeconds * 100;
    }*/

    transform_matrix = glm::mat3(1);
    transform_matrix *= transform2D::Translate(trX, trY);
    transform_matrix *= transform2D::Translate(260, 330);

    RenderMesh2D(meshes["head"], shaders["VertexColor"], transform_matrix);



    transform_matrix = glm::mat3(1);
    transform_matrix *= transform2D::Translate(trX, trY);
    transform_matrix *= transform2D::Translate(200, 100);
    RenderMesh2D(meshes["body"], shaders["VertexColor"], transform_matrix);


    transform_matrix = glm::mat3(1);
    transform_matrix *= transform2D::Translate(trX, trY);
    if (angularStep < 0.1)
        angularStep += deltaTimeSeconds;
    else if (angularStep > 0.1)
        angularStep = -angularStep;
    transform_matrix *= transform2D::Translate(250, 210);
    //transform_matrix *= transform2D::Rotate(angularStep);
    transform_matrix *= transform2D::Rotate(grad_to_radian(90));


    RenderMesh2D(meshes["first_wing"], shaders["VertexColor"], transform_matrix);

    transform_matrix = glm::mat3(1);
    transform_matrix *= transform2D::Translate(trX, trY);
    transform_matrix *= transform2D::Translate(270, 270);
    //transform_matrix *= transform2D::Rotate(angularStep);
    transform_matrix *= transform2D::Rotate(grad_to_radian(-90));



    RenderMesh2D(meshes["second_wing"], shaders["VertexColor"], transform_matrix);

    transform_matrix = glm::mat3(1);
    transform_matrix *= transform2D::Translate(trX, trY);
    transform_matrix *= transform2D::Translate(255, 375);
    RenderMesh2D(meshes["beak"], shaders["VertexColor"], transform_matrix);
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
