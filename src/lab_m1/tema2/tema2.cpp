#include "lab_m1/tema2/tema2.h"

#include <vector>
#include <string>
#include <iostream>

#include "lab_m1/tema2/transform3D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}


void Tema2::Init()
{
	polygonMode = GL_FILL;

	Mesh* mesh = new Mesh("box");
	mesh->LoadMesh(PATH_JOIN(window->props.selfDir, RESOURCE_PATH::MODELS, "primitives"), "box.obj");
	meshes[mesh->GetMeshID()] = mesh;

	vector<VertexFormat> vertices
	{
		// TODO(student): Complete the vertices data for the cube mesh
		VertexFormat(glm::vec3(1000, 0.1,  -1000), glm::vec3(0, 1, 1)),
		VertexFormat(glm::vec3(1000, 0.1,  1000), glm::vec3(0, 1, 1)),
		VertexFormat(glm::vec3(1000, 0.1,  -1000), glm::vec3(0, 1, 1)),
		VertexFormat(glm::vec3(1000, 0.1,  -1000), glm::vec3(0, 1, 1)),
		VertexFormat(glm::vec3(-1000, 0.1,  0), glm::vec3(0, 1, 1)),
		VertexFormat(glm::vec3(1000, 0.1,  0), glm::vec3(0, 1, 1)),
		VertexFormat(glm::vec3(-1000, 0.1,  -1000), glm::vec3(0, 1, 1)),
		VertexFormat(glm::vec3(1000, 0.1,  0), glm::vec3(0, 1, 1))

	};

	vector<unsigned int> indices =
	{
		0, 1, 2,    // indices for first triangle
		1, 3, 2,    // indices for second triangle
		2, 3, 7,
		2, 7, 6,
		1, 7, 3,
		1, 5, 7,
		6, 7, 4,
		7, 5, 4,
		0, 4, 1,
		1, 4, 5,
		2, 6, 4,
		0, 2, 4

	};

	meshes["ground"] = new Mesh("ground");
	meshes["ground"]->InitFromData(vertices, indices);

	vector<VertexFormat> vertices1
	{
		// TODO(student): Complete the vertices data for the cube mesh
		VertexFormat(glm::vec3(0, 0,  1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(1, 0,  1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(0, 1,  1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(1, 1,  1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(0, 0,  -1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(1, 0,  -1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(0, 1,  -1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(1, 1,  -1), glm::vec3(1, 0, 0))

	};

	vector<unsigned int> indices1 =
	{
		0, 1, 2,    // indices for first triangle
		1, 3, 2,    // indices for second triangle
		2, 3, 7,
		2, 7, 6,
		1, 7, 3,
		1, 5, 7,
		6, 7, 4,
		7, 5, 4,
		0, 4, 1,
		1, 4, 5,
		2, 6, 4,
		0, 2, 4

	};

	meshes["truck"] = new Mesh("truck");
	meshes["truck"]->InitFromData(vertices1, indices1);


	// Initialize tx, ty and tz (the translation steps)
	translateX = 0;
	translateY = 0;
	translateZ = 0;

	translateXSine = 0.f;
	translateYSine = 0.f;
	translateZSine = 0.f;

	// initialize sx, sy and sz (the scale factors)
	scaleX = 1.f;
	scaleY = 1.f;
	scaleZ = 1.f;

	// initialize angularSteps
	angularStepOX = 0.f;
	angularStepOY = 0.f;
	angularStepOZ = 0.f;



	angleX = 0.f;
	angleZ = 0.f;
	angle = 5.f;

	posX = cos(angle);
	posZ = sin(angle);

	angleJump = 0.f;

	startPos = glm::vec3(1.f, 1.f, 1.f);
	endPos = glm::vec3(1.f + 4.f, 1.f, 1.f);

	glm::ivec2 resolution = window->GetResolution();
	miniViewportArea = ViewportArea(50, 50, resolution.x / 5.f, resolution.y / 5.f);
}


void Tema2::FrameStart()
{
	// Clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0.8, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Sets the screen area where to draw
	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::RenderScene()
{

	/*modelMatrix = glm::mat4(1);
	modelMatrix *= transform3D::Translate(-2.5f, 0.5f, 1.5f);
	modelMatrix *= transform3D::Translate(translateX, translateY, translateZ);
	RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix *= transform3D::Translate(0.0f, 0.5f, -1.5f);
	modelMatrix *= transform3D::Scale(scaleX, scaleY, scaleZ);
	RenderMesh(meshes["box"], shaders["Simple"], modelMatrix);

	modelMatrix = glm::mat4(1);
	modelMatrix *= transform3D::Translate(2.5f, 0.5f, 1.5f);
	modelMatrix *= transform3D::RotateOX(angularStepOX);
	modelMatrix *= transform3D::RotateOY(angularStepOY);
	modelMatrix *= transform3D::RotateOZ(angularStepOZ);
	RenderMesh(meshes["box"], shaders["VertexNormal"], modelMatrix);*/
}

void Tema2::Update(float deltaTimeSeconds)
{
	glLineWidth(3);
	glPointSize(5);
	glPolygonMode(GL_FRONT_AND_BACK, polygonMode);

	//RenderMesh(meshes["ground"], shaders["VertexNormal"], glm::vec3(-25, 0, -25), glm::vec3(0.75f));
	main_transform = glm::mat4(1);
	main_transform *= transform3D::Translate(translateX, translateY, translateZ);
	main_transform *= transform3D::Translate(0.5, 0, 0);
	main_transform *= transform3D::RotateOY(rotation_angle_OY);
	main_transform *= transform3D::Translate(-0.5, 0, 0);
	RenderMesh(meshes["truck"], shaders["VertexColor"], main_transform);



	DrawCoordinateSystem();
	RenderScene();

	glClear(GL_DEPTH_BUFFER_BIT);
	glViewport(miniViewportArea.x, miniViewportArea.y, miniViewportArea.width, miniViewportArea.height);

	// TODO(student): render the scene again, in the new viewport
	RenderMesh(meshes["ground"], shaders["VertexNormal"], glm::vec3(-25, 0, -25), glm::vec3(0.75f));
	main_transform = glm::mat4(1);
	main_transform *= transform3D::Translate(translateX, translateY, translateZ);
	main_transform *= transform3D::Translate(0.5, 0, translateZ);
	main_transform *= transform3D::RotateOY(rotation_angle_OY);
	main_transform *= transform3D::Translate(-0.5, 0, -translateZ);
	RenderMesh(meshes["truck"], shaders["VertexColor"], main_transform);
	//DrawCoordinateSystem();

	RenderScene();



}


void Tema2::FrameEnd()
{
	DrawCoordinateSystem();
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema2::OnInputUpdate(float deltaTime, int mods)
{
	// TODO(student): Add transformation logic
	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		if (window->KeyHold(GLFW_KEY_S))
		{
			translateZ += truck_speed * cos(rotation_angle_OY) * deltaTime;
			translateX += truck_speed * sin(rotation_angle_OY) * deltaTime;
		}
		if (window->KeyHold(GLFW_KEY_W))
		{
			translateZ -= truck_speed * cos(rotation_angle_OY) * deltaTime;
			translateX -= truck_speed * sin(rotation_angle_OY) * deltaTime;
		}
		if (window->KeyHold(GLFW_KEY_D))
		{
			if (window->KeyHold(GLFW_KEY_W)) {
				rotation_angle_OY -= deltaTime;
			}
			else if (window->KeyHold(GLFW_KEY_S)) {
				rotation_angle_OY += deltaTime;
			}
			else {
				rotation_angle_OY -= deltaTime;
			}
		}
		if (window->KeyHold(GLFW_KEY_A))
		{
			if (window->KeyHold(GLFW_KEY_W)) {
				rotation_angle_OY += deltaTime;
			}
			else if (window->KeyHold(GLFW_KEY_S)) {
				rotation_angle_OY -= deltaTime;
			}
			else {
				rotation_angle_OY += deltaTime;
			}
		}
		if (window->KeyHold(GLFW_KEY_R))
		{
			translateY += 1.5 * deltaTime;
		}
		if (window->KeyHold(GLFW_KEY_F))
		{
			translateY -= 1.5 * deltaTime;
		}
	}

	if (window->KeyHold(GLFW_KEY_1))
	{
		scaleX += deltaTime;
		scaleY += deltaTime;
		scaleZ += deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_2))
	{
		scaleX -= deltaTime;
		scaleY -= deltaTime;
		scaleZ -= deltaTime;
	}

	if (window->KeyHold(GLFW_KEY_3))
	{
		angularStepOX += deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_4))
	{
		angularStepOX -= deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_5))
	{
		angularStepOY += deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_6))
	{
		angularStepOY -= deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_7))
	{
		angularStepOZ += deltaTime;
	}
	if (window->KeyHold(GLFW_KEY_8))
	{
		angularStepOZ -= deltaTime;
	}

	if (window->KeyHold(GLFW_KEY_0))
	{
		angle += deltaTime;

		if (angle >= 360.f)
		{
			angle = 0;
		}

		posX = cos(angle);
		posZ = sin(angle);
	}

	if (window->KeyHold(GLFW_KEY_9))
	{
		angle -= deltaTime;

		if (angle <= -360.f)
		{
			angle = 0;
		}

		posX = cos(angle);
		posZ = sin(angle);
	}

	if (window->KeyHold(GLFW_KEY_I)) {
		miniViewportArea.y++;
	}
	if (window->KeyHold(GLFW_KEY_K)) {
		miniViewportArea.y--;
	}
	if (window->KeyHold(GLFW_KEY_L)) {
		miniViewportArea.x += 1;
	}
	if (window->KeyHold(GLFW_KEY_J)) {
		miniViewportArea.x -= 1;
	}
	if (window->KeyHold(GLFW_KEY_U)) {
		miniViewportArea.height += 1;
		miniViewportArea.width += 3;
	}
	if (window->KeyHold(GLFW_KEY_O)) {
		miniViewportArea.height -= 1;
		miniViewportArea.width -= 3;
	}


}


void Tema2::OnKeyPress(int key, int mods)
{
	// Add key press event
	if (key == GLFW_KEY_SPACE)
	{
		switch (polygonMode)
		{
		case GL_POINT:
			polygonMode = GL_FILL;
			break;
		case GL_LINE:
			polygonMode = GL_POINT;
			break;
		default:
			polygonMode = GL_LINE;
			break;
		}
	}
	/*if (key == GLFW_KEY_I) {
		miniViewportArea.y += 10;
	}
	if (key == GLFW_KEY_K) {
		miniViewportArea.y -= 10;
	}
	if (key == GLFW_KEY_L) {
		miniViewportArea.x += 10;
	}
	if (key == GLFW_KEY_J) {
		miniViewportArea.x -= 10;
	}
	if (key == GLFW_KEY_U) {
		miniViewportArea.height+=10;
		miniViewportArea.width+=10;
	}
	if (key == GLFW_KEY_O) {
		miniViewportArea.height -=10;
		miniViewportArea.width -=10;
	}*/
}


void Tema2::OnKeyRelease(int key, int mods)
{
	// Add key release event
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	// Add mouse move event
}


void Tema2::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// Add mouse button press event
}


void Tema2::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
	// Add mouse button release event
}


void Tema2::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema2::OnWindowResize(int width, int height)
{
}
