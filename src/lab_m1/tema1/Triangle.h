#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace Triangle
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateTriangle(const std::string& name, glm::vec3 leftBottomCorner, double length, glm::vec3 color, bool fill = false, std :: string type = "right", int angle_type = 0);
}
