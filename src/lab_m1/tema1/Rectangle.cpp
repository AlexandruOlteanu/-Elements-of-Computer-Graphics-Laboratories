#include "Rectangle.h"
#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* Rectangle::CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, double l, double L, glm::vec3 color, bool fill, std :: string type) {

    glm::vec3 corner = leftBottomCorner;

    std::vector<VertexFormat> vertices;

    if (type == "vertical") {

        vertices =
        {
            VertexFormat(corner, color),
            VertexFormat(corner + glm::vec3(l, 0, 0), color),
            VertexFormat(corner + glm::vec3(l, L, 0), color),
            VertexFormat(corner + glm::vec3(0, L, 0), color)
        };
    }
    else {
        vertices =
        {
            VertexFormat(corner, color),
            VertexFormat(corner + glm::vec3(L, 0, 0), color),
            VertexFormat(corner + glm::vec3(L, l, 0), color),
            VertexFormat(corner + glm::vec3(0, l, 0), color)
        };
    }

    Mesh* rectangle = new Mesh(name);
    std::vector<unsigned int> indices = { 0, 1, 2, 3 };

    if (!fill) {
        rectangle->SetDrawMode(GL_LINE_LOOP);
    }
    else {
        // Draw 2 triangles. Add the remaining 2 indices
        indices.push_back(0);
        indices.push_back(2);
    }

    rectangle->InitFromData(vertices, indices);
    return rectangle;
}
