#include "Circle.h"

#include <vector>

#include "core/engine.h"
#include "utils/gl_utils.h"


Mesh* Circle::CreateCircle(const std::string& name, int centerOfCircleX, int centerOfCircleY, double radius, glm::vec3 color, bool fill) {

    // A triangle with angles of 75, 75, 30.
    std::vector<VertexFormat> vertices =
    {
        VertexFormat(glm::vec3(centerOfCircleX, centerOfCircleY, 0), color)
    };

    for (int i = 0; i < 360; i++) {
        vertices.push_back(VertexFormat(glm::vec3(centerOfCircleX + (radius * cos(i * 2 * M_PI / 360)),
            centerOfCircleY + (radius * sin(i * 2 * M_PI / 360)), 0), color));
    }

    Mesh* circle = new Mesh(name);
    std::vector<unsigned int> indices;

    for (int i = 1; i < 360; i++) {
        indices.push_back(0);
        indices.push_back(i);
        indices.push_back(i + 1);
    }

    indices.push_back(0);
    indices.push_back(360);
    indices.push_back(1);

    if (!fill) {
        circle->SetDrawMode(GL_LINE_LOOP);
    }

    circle->InitFromData(vertices, indices);
    return circle;
}
