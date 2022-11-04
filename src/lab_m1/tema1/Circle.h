#pragma once

#include <string>

#include "core/gpu/mesh.h"
#include "utils/glm_utils.h"


namespace Circle
{

    // Create square with given bottom left corner, length and color
    Mesh* CreateCircle(const std::string& name, int centerOfCircleX, int centerOfCircleY, double radius, glm::vec3 color, bool fill);
}
