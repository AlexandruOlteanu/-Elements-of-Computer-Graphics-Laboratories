#include "lab_m1/tema2/tema2.h"

#include <vector>
#include <string>
#include <iostream>

#include "lab_m1/tema2/transform3D.h"
#include "lab_m1/tema2/camera.h"

using namespace std;
using namespace m1;

vector <pair<double, double>> first_road_points;
vector <pair<double, double>> second_road_points;
vector<pair<double, double>> trees_points;

struct triangle {
	pair<double, double> A;
	pair<double, double> B;
	pair<double, double> C;
};

vector<triangle> triangles;

Tema2::Tema2()
{
}


Tema2::~Tema2()
{
}

void Tema2::create_parallelepiped(string name, double point1_x, double point1_z, double point2_x, double point2_z, double height1, double height2, glm::vec3 color) {

	vector<VertexFormat> vertices
	{
		VertexFormat(glm::vec3(point1_x, height1,  point1_z), color),
		VertexFormat(glm::vec3(point2_x, height1,  point1_z), color),
		VertexFormat(glm::vec3(point1_x, height2,  point1_z), color),
		VertexFormat(glm::vec3(point2_x, height2,  point1_z), color),
		VertexFormat(glm::vec3(point1_x, height1,  point2_z), color),
		VertexFormat(glm::vec3(point2_x, height1,  point2_z), color),
		VertexFormat(glm::vec3(point1_x, height2,  point2_z), color),
		VertexFormat(glm::vec3(point2_x, height2,  point2_z), color)

	};

	vector<unsigned int> indices =
	{
		0, 1, 2,
		1, 3, 2,
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

	meshes[name] = new Mesh(name);
	meshes[name]->InitFromData(vertices, indices);

}

double distance(pair<double, double> A, pair<double, double> B) {
	return sqrt((A.first - B.first) * (A.first - B.first) + (A.second - B.second) * (A.second - B.second));
}

void add_triangle(int x, int y, int z, vector<VertexFormat> vertices) {
	triangle t;
	t.A = { vertices[x].position.x, vertices[x].position.z };
	t.B = { vertices[y].position.x, vertices[y].position.z };
	t.C = { vertices[z].position.x, vertices[z].position.z };
	triangles.push_back(t);
}

void make_triangle_indices(double x, double y, double z, vector<unsigned int> &indices, vector<VertexFormat> vertices) {
	indices.push_back(x);
	indices.push_back(y);
	indices.push_back(z);
	add_triangle(x, y, z, vertices);
}

void make_parallel_trace(double width, vector<pair<double, double>> &trace) {
	int n = first_road_points.size();
	for (int i = 0; i < n - 1; ++i) {
		pair<double, double> direction = { first_road_points[i + 1].first - first_road_points[i].first, first_road_points[i + 1].second - first_road_points[i].second };
		pair<double, double> product = { -direction.second, direction.first };
		product.first /= distance(first_road_points[i], first_road_points[i + 1]);
		product.second /= distance(first_road_points[i], first_road_points[i + 1]);

		pair<double, double> exterior_point = { first_road_points[i].first + width * product.first, first_road_points[i].second + width * product.second };

		trace.push_back(exterior_point);
	}
	trace.push_back({ trace[0].first, trace[0].second });
}

void Tema2::create_road() {

	vector<VertexFormat> vertices;
	vector<unsigned int> indices;

	first_road_points.push_back({ first_road_points[0].first, first_road_points[0].second });
	int n = first_road_points.size();
	make_parallel_trace(1.5f, second_road_points);
	for (int i = 0; i < n - 1; ++i) {
		vertices.clear();
		indices.clear();
		vertices.push_back(VertexFormat(glm::vec3(first_road_points[i].first, 0.2, first_road_points[i].second), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(glm::vec3(second_road_points[i].first, 0.2, second_road_points[i].second), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(glm::vec3(first_road_points[i + 1].first, 0.2, first_road_points[i + 1].second), glm::vec3(0, 0, 0)));
		vertices.push_back(VertexFormat(glm::vec3(second_road_points[i + 1].first, 0.2, second_road_points[i + 1].second), glm::vec3(0, 0, 0)));

		make_triangle_indices(0, 1, 2, indices, vertices);
		make_triangle_indices(1, 2, 3, indices, vertices);
		make_triangle_indices(0, 1, 3, indices, vertices);
		make_triangle_indices(0, 2, 3, indices, vertices);


		meshes["road_point_" + to_string(i)] = new Mesh("road_point_" + to_string(i));
		meshes["road_point_" + to_string(i)]->InitFromData(vertices, indices);
	}
}

void Tema2::render_road() {
	int n = first_road_points.size();
	for (int i = 0; i < n - 1; ++i) {
		MyRenderMesh(meshes["road_point_" + to_string(i)], shaders["VertexColor"], glm::mat4(1));
	}
}


double triangle_area(pair<double, double> A, pair<double, double> B, pair<double, double> C) {
	double area = 0;
	pair<double, double> AB = { B.first - A.first, B.second - A.second };
	pair<double, double> AC = { C.first - A.first, C.second - A.second };
	double product = AB.first * AC.second - AB.second * AC.first;
	if (product < 0) {
		product = -product;
	}
	area = product / 2;
	return area;
}

bool in_triangle(pair<double, double> car_point, pair<double, double> A, pair<double, double> B, pair<double, double> C) {

	double ABC_area = triangle_area(A, B, C);
	double sum_area = triangle_area(car_point, A, B);
	sum_area += triangle_area(car_point, B, C);
	sum_area += triangle_area(car_point, A, C);

	if (fabs(ABC_area - sum_area) < 1e-7) {
		return 1;
	}

	return 0;
}

bool check_on_road(double x, double y) {

	int sz = triangles.size();
	for (int i = 0; i < sz; ++i) {
		if (in_triangle({ x, y }, triangles[i].A, triangles[i].B, triangles[i].C)) {
			return 1;
		}
	}
	
	return 0;
}

double tree_size = 0.25;

void Tema2::create_trees() {

	create_parallelepiped("base", -0.5 * tree_size, 0.5 * tree_size, 0.5 * tree_size, -0.5 * tree_size, 0.2 * tree_size, 7 * tree_size, glm::vec3(0.46, 0.36, 0.28));
	create_parallelepiped("branch1", -0.25 * tree_size, 0.25 * tree_size, 0.25 * tree_size, -0.25 * tree_size, 0.25 * tree_size, 3 * tree_size, glm::vec3(0.46, 0.36, 0.28));
	create_parallelepiped("branch2", -0.25 * tree_size, 0.25 * tree_size, 0.25 * tree_size, -0.25 * tree_size, 0.25 * tree_size, 3 * tree_size, glm::vec3(0.46, 0.36, 0.28));
	create_parallelepiped("main_leaf", -2 * tree_size, 2 * tree_size, 2 * tree_size, -2 * tree_size, 0.2 * tree_size, 3 * tree_size, glm::vec3(0.004, 0.196, 0.125));
	create_parallelepiped("leaf1", -1 * tree_size, 1 * tree_size, 1 * tree_size, -1 * tree_size, 0.2 * tree_size, 2 * tree_size, glm::vec3(0.004, 0.196, 0.125));
	create_parallelepiped("leaf2", -1 * tree_size, 1 * tree_size, 1 * tree_size, -1 * tree_size, 0.2 * tree_size, 2 * tree_size, glm::vec3(0.004, 0.196, 0.125));

}

void find_trees_points() {

	for (double x = -50; x <= 35; x += 0.2) {
		for (double z = -50; z <= 25; z += 0.2) {
			bool ok = 1;
			double min_dist = 1e9;
			for (auto point : first_road_points) {
				double dist = distance(point, { x, z });
				if ( dist <= 1.5) {
					ok = 0;
					break;
				}
				min_dist = min(min_dist, dist);
			}

			for (auto point : second_road_points) {
				double dist = distance(point, { x, z });
				if (dist <= 1.5) {
					ok = 0;
					break;
				}
				min_dist = min(min_dist, dist);
			}

			if (min_dist > 3) {
				ok = 0;
			}

			for (auto tree_point : trees_points) {
				if (distance(tree_point, { x, z }) <= 6) {
					ok = 0;
					break;
				}
			}
			if (!ok) {
				continue;
			}
			trees_points.push_back({ x, z });
		}
	}
}

void Tema2::render_trees() {

	for (auto tree_point : trees_points) {

		glm::mat4 main_transformation = glm::mat4(1);
		main_transformation *= transform3D::Translate(tree_point.first, 0, tree_point.second);

		glm::mat4 base_transformation = main_transformation;
		MyRenderMesh(meshes["base"], shaders["VertexColor"], base_transformation);

		glm::mat4 branch1_transformation = main_transformation;
		branch1_transformation *= transform3D::Translate(0, 2 * tree_size, 0);
		branch1_transformation *= transform3D::RotateOZ(1);
		MyRenderMesh(meshes["branch1"], shaders["VertexColor"], branch1_transformation);

		glm::mat4 branch2_transformation = main_transformation;
		branch2_transformation *= transform3D::Translate(0, 3 * tree_size, 0);
		branch2_transformation *= transform3D::RotateOZ(-1);
		MyRenderMesh(meshes["branch2"], shaders["VertexColor"], branch2_transformation);

		glm::mat4 main_leaf_transformation = main_transformation;
		main_leaf_transformation *= transform3D::Translate(0, 6.5 * tree_size, 0);
		MyRenderMesh(meshes["main_leaf"], shaders["VertexColor"], main_leaf_transformation);

		glm::mat4 leaf1_transformation = main_transformation;
		leaf1_transformation *= transform3D::Translate(-2 * tree_size, 3.3 * tree_size, 0);
		leaf1_transformation *= transform3D::RotateOZ(1);
		MyRenderMesh(meshes["leaf1"], shaders["VertexColor"], leaf1_transformation);

		glm::mat4 leaf2_transformation = main_transformation;
		leaf2_transformation *= transform3D::Translate(2 * tree_size, 4.3 * tree_size, 0);
		leaf2_transformation *= transform3D::RotateOZ(-1);
		MyRenderMesh(meshes["leaf2"], shaders["VertexColor"], leaf2_transformation);
	}
}




void Tema2::Init()
{
	camera = new Camera();
	minimap_camera = new Camera();
	extract_road_points(first_road_points);
	create_road();
	create_trees();
	find_trees_points();

	create_parallelepiped("ground", -200, 200, 200, -200, 0.1, 0.1, glm::vec3(0, 1, 1));
	create_parallelepiped("truck", -0.1, 0.2, 0.1, -0.2, 0.2, 0.34, glm::vec3(1, 0, 0));

	translateX = 0;
	translateY = 0;
	translateZ = 0;

	initial_camera_X = 0;
	initial_camera_Y = 0.6;
	initial_camera_Z = 0.9f;

	glm::ivec2 resolution = window->GetResolution();
	miniViewportArea = ViewportArea(50, 50, resolution.x / 3.f, resolution.y / 3.f);
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

void Tema2::FrameStart()
{
	// Clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0.8, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Sets the screen area where to draw
	glm::ivec2 resolution = window->GetResolution();
	glViewport(0, 0, resolution.x, resolution.y);
}

void Tema2::update_camera() {
	camera->Set(glm::vec3(initial_camera_X, initial_camera_Y, initial_camera_Z), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	camera->MoveForward(-translateZ);
	camera->TranslateRight(translateX);
	camera->MoveForward(initial_camera_Z);
	camera->RotateFirstPerson_OY(rotation_angle_OY);
	camera->MoveForward(-initial_camera_Z);
}

void Tema2::update_truck() {
	main_transform = glm::mat4(1);
	main_transform *= transform3D::Translate(translateX, translateY, translateZ);
	main_transform *= transform3D::RotateOY(rotation_angle_OY);
	MyRenderMesh(meshes["truck"], shaders["VertexColor"], main_transform);
}

void Tema2::render_ground() {
	ground_transformation = glm::mat4(1);
	MyRenderMesh(meshes["ground"], shaders["VertexNormal"], ground_transformation);
}

void Tema2::Update(float deltaTimeSeconds)
{
	projectionMatrix = glm::perspective(RADIANS(80), window->props.aspectRatio, 0.01f, 200.0f);
	//DrawCoordinateSystem(camera->GetViewMatrix(), projectionMatrix);
	update_camera();
	render_road();
	render_trees();
	render_ground();
	update_truck();

	glClear(GL_DEPTH_BUFFER_BIT);
	glViewport(miniViewportArea.x, miniViewportArea.y, miniViewportArea.width, miniViewportArea.height);
	camera->Set(glm::vec3(translateX, 6, translateZ), glm::vec3(translateX, 0, translateZ), glm::vec3(-1, 0, -1));

	render_road();
	render_trees();
	render_ground();
	update_truck();

}

void Tema2::OnInputUpdate(float deltaTime, int mods)
{
	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		double new_translate_X = translateX;
		double new_translate_Z = translateZ;
		if (window->KeyHold(GLFW_KEY_S))
		{
			new_translate_Z += truck_speed * cos(rotation_angle_OY) * deltaTime;
			new_translate_X += truck_speed * sin(rotation_angle_OY) * deltaTime;
			if (check_on_road(new_translate_X, new_translate_Z)) {
				translateX = new_translate_X;
				translateZ = new_translate_Z;
			}
		}
		if (window->KeyHold(GLFW_KEY_W))
		{
			new_translate_Z -= truck_speed * cos(rotation_angle_OY) * deltaTime;
			new_translate_X -= truck_speed * sin(rotation_angle_OY) * deltaTime;
			if (check_on_road(new_translate_X, new_translate_Z)) {
				translateX = new_translate_X;
				translateZ = new_translate_Z;
			}
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
			camera->TranslateForward(deltaTime * vitezaCamera);
		}

		if (window->KeyHold(GLFW_KEY_A)) {
			camera->TranslateRight(-deltaTime * vitezaCamera);
		}

		if (window->KeyHold(GLFW_KEY_S)) {
			camera->TranslateForward(-deltaTime * vitezaCamera);
		}

		if (window->KeyHold(GLFW_KEY_D)) {
			camera->TranslateRight(deltaTime * vitezaCamera);
		}

		if (window->KeyHold(GLFW_KEY_Q)) {
			camera->TranslateUpward(-deltaTime * vitezaCamera);
		}

		if (window->KeyHold(GLFW_KEY_E)) {
			camera->TranslateUpward(deltaTime * vitezaCamera);
		}	
	}
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