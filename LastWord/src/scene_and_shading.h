#pragma once

#include <memory>
#include <string>
#include <vector>

#include "base/application.h"
#include "base/camera.h"
#include "base/glsl_program.h"
#include "base/model.h" // 把model.h重写?
#include "rifle.h"
#include "base/skybox.h"
#include "base/texture2d.h"

class scene_and_shading : public Application {
public:
    scene_and_shading(const Options& options);

    ~scene_and_shading() = default;

    void handleInput() override;

    void renderFrame() override;

private:
    std::vector<std::unique_ptr<Camera>> _cameras;
    
    bool third_camera = false;

    bool Scope = false;

    int activeCameraIndex = 0;

    std::unique_ptr<Model> _rifle; 

    std::unique_ptr<GLSLProgram> _shader;

    void initShader();

    std::unique_ptr<SkyBox> _skybox;

// -------------------------------------------------------------------------------

};