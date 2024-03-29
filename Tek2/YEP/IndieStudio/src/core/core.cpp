/*
** EPITECH PROJECT, 2022
** Project
** File description:
** core
*/

#include "core.hpp"
#include <unistd.h>
#include "core/pauseMenu.hpp"
#include "information/info.hpp"
#include "initMap.hpp"

static double clockToMilliseconds(clock_t ticks)
{
    return (ticks / ((double)CLOCKS_PER_SEC)) * ML_BASE;
}

ecs::Scenes coreLoop(std::vector<int> &idControllers, std::vector<int> &settings, std::string &winner, ecs::GameStartMode start_mode)
{
    clock_t sec_clock = clock();
    clock_t fps_clock = clock();
    ecs::Core core;
    try {
        core = mapCreation(idControllers, settings, start_mode);
    } catch (...) {
        throw std::exception();
    }
    int fps = 0;
    raylib::Vector3 initialCamPos = {0.0f, 10.0f, 10.0f};
    core._camera.position = initialCamPos;
    raylib::Vector3 initialCamTarget = {0.0f, 0.0f, 0.0f};
    core._camera.target = initialCamTarget;
    raylib::Vector3 initialCamUp = {0.0f, 1.0f, 0.0f};
    core._camera.up = initialCamUp;
    core._camera.fovy = 80.0f;
    core._camera.projection = CAMERA_PERSPECTIVE;
    bool isOrbital = true;
    bool step = false;
    bool first = true;
    bool second = true;
    float step2 = (MAP_SIZE / 2) - 8;

    // initInformations(core);
    core._camera.SetMode(CAMERA_ORBITAL);
    //core.getEntity("MusicGame")->get<ComponentMusic>()->getMusic().Play();
    while (1) {
        if (clockToMilliseconds(clock() - fps_clock) >= FPS_CAP_REAL) {
            fps_clock = clock();
            fps++;

            core._camera.Update();

            if ((fps) == 1 && isOrbital == true) {
                core._camera.SetMode(CAMERA_CUSTOM);
                isOrbital = false;
            }
            if (first == true && step == false && core._camera.position.x >= -11) {
                core._camera.position.x -= 0.1f / 2;
            } else if (first == true && step == false && core._camera.position.x < -11) {
                first = false;
            }
            if (second == true && step == false && first == false && core._camera.position.z <= step2) {
                core._camera.position.z += 0.1f / 2;
                core._camera.position.x = -11;
            } else if (second == true && step == false && first == false && core._camera.position.z > step2) {
                second = false;
            }
            if (isOrbital == false && core._camera.position.y < 12.5f && first == false && second == false) {
                core._camera.position.y += 0.09f / 2;
                core._camera.position.x += 0.13f / 2;
                step = true;
            }
            if (core.getScene() == ecs::Scenes::Pause)
                core.setScene(pauseMenu(core));
            if (core.getScene() != ecs::Scenes::Game && core.getScene() != ecs::Scenes::Pause)
                break;
            //core.getEntity("MusicGame")->get<ComponentMusic>()->getMusic().Update();
            raylib::Window::BeginDrawing();
            raylib::Window::Clear(raylib::Color::White());
            core._camera.BeginMode();
            if (step == true && core._camera.position.y >= 12.5f) {
                core.get<ecs::SystemEvent>()->update(core);
                SystemIA::update(core);
            }
            core.get<ecs::SystemRender3D>()->update(core);
            core._camera.EndMode();
            core.get<ecs::SystemRender2D>()->update(core);
            raylib::Window::EndDrawing();
        }

        if (clockToMilliseconds(clock() - sec_clock) >= ML_BASE) {
            sec_clock = clock();
            fps = 0;
        }
    }
    for (auto *e : core.getEntities()) {
        if (e->has<ComponentKills>()) {
            if (e->has<ComponentMovable>() && e->get<ComponentDrawable>()->getIsDrawable3D() == true) {
                winner = e->getLabel();
            }
        }
    }
    core.getEntity("MusicGame")->get<ComponentMusic>()->getMusic().Stop();
    return (core.getScene());
}
