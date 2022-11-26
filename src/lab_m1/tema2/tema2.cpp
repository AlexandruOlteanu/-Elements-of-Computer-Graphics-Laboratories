#include "lab_m1/tema2/tema2.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "lab_m1/tema2/transform3D.h"
#include "lab_m1/tema2/camera.h"

using namespace std;
using namespace m1;

vector <pair<double, double>> points;

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

void Tema2::create_road() {

	vector<VertexFormat> vertices;
	vector<unsigned int> indices;
	points.push_back({ points[0].first, points[0].second });
	points.push_back({ points[1].first, points[1].second });
	int n = points.size();
	for (int i = 0; i <= n - 4; i += 2) {
		vertices.clear();
		indices.clear();
		vertices.push_back(VertexFormat(glm::vec3(points[i].first, 0.2, points[i].second), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(glm::vec3(points[i + 1].first, 0.2, points[i + 1].second), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(glm::vec3(points[i + 2].first, 0.2, points[i + 2].second), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(glm::vec3(points[i + 3].first, 0.2, points[i + 3].second), glm::vec3(0, 0, 0)));

		if (i >= 1) {
			vertices.push_back(VertexFormat(glm::vec3(points[i - 1].first, 0.2, points[i - 1].second), glm::vec3(0, 0, 0)));
			indices.push_back(0);
			indices.push_back(1);
			indices.push_back(4);

			indices.push_back(0);
			indices.push_back(2);
			indices.push_back(4);

			indices.push_back(0);
			indices.push_back(3);
			indices.push_back(4);

			indices.push_back(1);
			indices.push_back(2);
			indices.push_back(4);

			indices.push_back(2);
			indices.push_back(3);
			indices.push_back(4);
		}

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(2);

		indices.push_back(0);
		indices.push_back(1);
		indices.push_back(3);

		indices.push_back(0);
		indices.push_back(2);
		indices.push_back(3);

		indices.push_back(1);
		indices.push_back(2);
		indices.push_back(3);

		meshes["road_point_" + to_string(i / 2)] = new Mesh("road_point_" + to_string(i / 2));
		meshes["road_point_" + to_string(i / 2)]->InitFromData(vertices, indices);
	}
}

void Tema2::render_road() {
	int n = points.size();
	for (int i = 0; i <= n - 4; i += 2) {
		MyRenderMesh(meshes["road_point_" + to_string(i / 2)], shaders["VertexColor"], glm::mat4(1));
	}
}


void Tema2::Init()
{
	camera = new Camera();
	extract_road_points(points);
	create_road();

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
		VertexFormat(glm::vec3(0, 0.2,  1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(1, 0.2,  1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(0, 1,  1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(1, 1,  1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(0, 0.2,  -1), glm::vec3(1, 0, 0)),
		VertexFormat(glm::vec3(1, 0.2,  -1), glm::vec3(1, 0, 0)),
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

	initial_camera_X = 0;
	initial_camera_Y = 3;
	initial_camera_Z = 4.5f;

	truck_center_X = 0.5f;
	truck_center_Y = 0.5f;
	truck_center_Z = 0;

	projectionMatrix = glm::perspective(RADIANS(80), window->props.aspectRatio, 0.01f, 200.0f);

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

void Tema2::Update(float deltaTimeSeconds)
{
	render_road();

	camera->Set(glm::vec3(initial_camera_X, initial_camera_Y, initial_camera_Z), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	ground_transformation = glm::mat4(1);
	MyRenderMesh(meshes["ground"], shaders["VertexNormal"], ground_transformation);
	main_transform = glm::mat4(1);
	main_transform *= transform3D::Translate(translateX, translateY, translateZ);
	camera->MoveForward(-translateZ);
	camera->TranslateRight(translateX);

	main_transform *= transform3D::Translate(0.5, 0, 0);
	camera->TranslateRight(0.5);
	main_transform *= transform3D::RotateOY(rotation_angle_OY);
	main_transform *= transform3D::Translate(-0.5, 0, 0);

	camera->MoveForward(-truck_center_Z + initial_camera_Z);
	camera->RotateFirstPerson_OY(rotation_angle_OY);
	camera->MoveForward(+truck_center_Z - initial_camera_Z);

	MyRenderMesh(meshes["truck"], shaders["VertexColor"], main_transform);
	FrameEnd();

	glClear(GL_DEPTH_BUFFER_BIT);
	glViewport(miniViewportArea.x, miniViewportArea.y, miniViewportArea.width, miniViewportArea.height);
	
	camera->Set(glm::vec3(initial_camera_X, initial_camera_Y, initial_camera_Z), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	ground_transformation = glm::mat4(1);
	ground_transformation *= transform3D::Translate(-25, 0, -25);
	MyRenderMesh(meshes["ground"], shaders["VertexNormal"], ground_transformation);
	main_transform = glm::mat4(1);
	main_transform *= transform3D::Translate(translateX, translateY, translateZ);
	camera->MoveForward(-translateZ);
	camera->TranslateRight(translateX);

	main_transform *= transform3D::Translate(0.5, 0, 0);
	camera->TranslateRight(0.5);
	main_transform *= transform3D::RotateOY(rotation_angle_OY);
	main_transform *= transform3D::Translate(-0.5, 0, 0);

	camera->MoveForward(-truck_center_Z + initial_camera_Z);
	camera->RotateFirstPerson_OY(rotation_angle_OY);
	camera->MoveForward(+truck_center_Z - initial_camera_Z);

	MyRenderMesh(meshes["truck"], shaders["VertexColor"], main_transform);

}


void Tema2::FrameEnd()
{
	DrawCoordinateSystem(camera->GetViewMatrix(), projectionMatrix);
}

void Tema2::MyRenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix)
{
	if (!mesh || !shader || !shader->program)
	    return;

	shader->Use();
	glUniformMatrix4fv(shader->loc_view_matrix, 1, GL_FALSE, glm::value_ptr(camera->GetViewMatrix()));
	glUniformMatrix4fv(shader->loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));
	glUniformMatrix4fv(shader->loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));
	mesh->Render();
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
	}

	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		float vitezaCamera = 3.0f;

		if (window->KeyHold(GLFW_KEY_W)) {
			// TODO(student): Translate the camera forward
			camera->TranslateForward(deltaTime * vitezaCamera);
		}

		if (window->KeyHold(GLFW_KEY_A)) {
			// TODO(student): Translate the camera to the left
			camera->TranslateRight(-deltaTime * vitezaCamera);
		}

		if (window->KeyHold(GLFW_KEY_S)) {
			// TODO(student): Translate the camera backward
			camera->TranslateForward(-deltaTime * vitezaCamera);
		}

		if (window->KeyHold(GLFW_KEY_D)) {
			// TODO(student): Translate the camera to the right
			camera->TranslateRight(deltaTime * vitezaCamera);
		}

		if (window->KeyHold(GLFW_KEY_Q)) {
			// TODO(student): Translate the camera downward
			camera->TranslateUpward(-deltaTime * vitezaCamera);
		}

		if (window->KeyHold(GLFW_KEY_E)) {
			// TODO(student): Translate the camera upward
			camera->TranslateUpward(deltaTime * vitezaCamera);
		}	
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
}


void Tema2::OnKeyRelease(int key, int mods)
{
	// Add key release event
}


void Tema2::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
	if (window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		float sensivityOX = 0.001f;
		float sensivityOY = 0.001f;

		if (window->GetSpecialKeyState() == 0) {
			// TODO(student): Rotate the camera in first-person mode around
			// OX and OY using `deltaX` and `deltaY`. Use the sensitivity
			// variables for setting up the rotation speed.
			camera->RotateFirstPerson_OX(sensivityOX * -deltaY);
			camera->RotateFirstPerson_OY(sensivityOY * -deltaX);
		}

		if (window->GetSpecialKeyState() & GLFW_MOD_CONTROL) {
			// TODO(student): Rotate the camera in third-person mode around
			// OX and OY using `deltaX` and `deltaY`. Use the sensitivity
			// variables for setting up the rotation speed.
			camera->RotateThirdPerson_OX(sensivityOX * -deltaY);
			camera->RotateThirdPerson_OY(sensivityOY * -deltaX);
		}
	}
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
