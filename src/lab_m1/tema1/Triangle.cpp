#include "Triangle.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* Triangle::CreateTriangle(const std::string& name, glm::vec3 leftBottomCorner, double length, glm::vec3 color, bool fill, std :: string type, int angle_type) {
    
    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices;

    if (type == "right") {
        if (angle_type == 1) {
            vertices.push_back(VertexFormat(corner + glm::vec3(2 * length, 0, 0), color));
            vertices.push_back(VertexFormat(corner + glm::vec3(0, -length, 0), color));
            vertices.push_back(VertexFormat(corner, color));
        }
        else {
            vertices.push_back(VertexFormat(corner + glm::vec3(2 * length, 0, 0), color));
            vertices.push_back(VertexFormat(corner + glm::vec3(0, length, 0), color));
            vertices.push_back(VertexFormat(corner, color));
        }
    }

    if (type == "isoscel") {
        vertices.push_back(VertexFormat(corner + glm::vec3(0, length, 0), color));
        vertices.push_back(VertexFormat(corner + glm::vec3(2 * length, length / 2, 0), color));
        vertices.push_back(VertexFormat(corner, color));
    }
    
    Mesh* my_bird = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2 };

    if (!fill) {
        my_bird->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        indices.push_back(0);
        indices.push_back(2);
    }

    my_bird->InitFromData(vertices, indices);
    return my_bird;
}
