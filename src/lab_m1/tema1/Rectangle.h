#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace Rectangle
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateRectangle(const std::string& name, glm::vec3 leftBottomCorner, double l, double L, glm::vec3 color, bool fill = false, std :: string type = "vertical");
}
