#pragma once

#include "components/simple_scene.h"
#include "lab_m1/tema2/camera.h"

namespace m1
{
    class Tema2 : public gfxc::SimpleScene
    {
    public:
        struct ViewportArea
        {
            ViewportArea() : x(0), y(0), width(1), height(1) {}
            ViewportArea(int x, int y, int width, int height)
                : x(x), y(y), width(width), height(height) {}
            int x;
            int y;
            int width;
            int height;
        };

        Tema2();
        ~Tema2();

        void Init() override;

    private:
        void FrameStart() override;
        void Update(float deltaTimeSeconds) override;
        void FrameEnd() override;
        void Tema2::MyRenderMesh(Mesh* mesh, Shader* shader, const glm::mat4& modelMatrix);
        void OnInputUpdate(float deltaTime, int mods) override;
        void OnKeyPress(int key, int mods) override;
        void OnKeyRelease(int key, int mods) override;
        void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
        void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
        void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
        void OnWindowResize(int width, int height) override;

    protected:
        Camera *camera;
        glm::mat4 main_transform;
        glm::mat4 ground_transformation;
        glm::mat4 projectionMatrix;
        glm::vec3 endPos, midPos, startPos;
        float translateX, translateY, translateZ;
        float initial_camera_X;
        float initial_camera_Y;
        float initial_camera_Z;
        float truck_center_X;
        float truck_center_Y;
        float truck_center_Z;
        float scaleX, scaleY, scaleZ;
        float angularStepOX, angularStepOY, angularStepOZ;
        GLenum polygonMode;

        GLfloat translateZSine, translateXSine, translateYSine;
        GLfloat angleX, angleZ;
        GLfloat posX, posZ, angle;
        GLfloat angleJump;
        GLfloat truck_speed = 7;
        GLfloat rotation_angle_OY = 0;
        ViewportArea miniViewportArea;
    };
}   // namespace m1

