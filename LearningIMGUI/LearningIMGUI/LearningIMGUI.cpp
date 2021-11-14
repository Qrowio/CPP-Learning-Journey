#include "imgui.h"
#include "imgui-SFML.h"
#include <iostream>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

void Style() {
    ImGuiStyle& style = ImGui::GetStyle();
    style.Colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_TextDisabled] = ImVec4(0.73f, 0.75f, 0.74f, 1.00f);
    style.Colors[ImGuiCol_WindowBg] = ImVec4(0.09f, 0.09f, 0.09f, 0.94f);
    style.Colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
    style.Colors[ImGuiCol_Border] = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
    style.Colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
    style.Colors[ImGuiCol_FrameBg] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
    style.Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.40f);
    style.Colors[ImGuiCol_FrameBgActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.67f);
    style.Colors[ImGuiCol_TitleBg] = ImVec4(0.47f, 0.22f, 0.22f, 0.67f);
    style.Colors[ImGuiCol_TitleBgActive] = ImVec4(0.47f, 0.22f, 0.22f, 1.00f);
    style.Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.47f, 0.22f, 0.22f, 0.67f);
    style.Colors[ImGuiCol_MenuBarBg] = ImVec4(0.34f, 0.16f, 0.16f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
    style.Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    style.Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
    style.Colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
    style.Colors[ImGuiCol_SliderGrab] = ImVec4(0.71f, 0.39f, 0.39f, 1.00f);
    style.Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.84f, 0.66f, 0.66f, 1.00f);
    style.Colors[ImGuiCol_Button] = ImVec4(0.47f, 0.22f, 0.22f, 0.65f);
    style.Colors[ImGuiCol_ButtonHovered] = ImVec4(0.71f, 0.39f, 0.39f, 0.65f);
    style.Colors[ImGuiCol_ButtonActive] = ImVec4(0.20f, 0.20f, 0.20f, 0.50f);
    style.Colors[ImGuiCol_Header] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
    style.Colors[ImGuiCol_HeaderHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.65f);
    style.Colors[ImGuiCol_HeaderActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.00f);
    style.Colors[ImGuiCol_Separator] = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
    style.Colors[ImGuiCol_SeparatorHovered] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
    style.Colors[ImGuiCol_SeparatorActive] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
    style.Colors[ImGuiCol_ResizeGrip] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
    style.Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
    style.Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
    style.Colors[ImGuiCol_Tab] = ImVec4(0.71f, 0.39f, 0.39f, 0.54f);
    style.Colors[ImGuiCol_TabHovered] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
    style.Colors[ImGuiCol_TabActive] = ImVec4(0.84f, 0.66f, 0.66f, 0.66f);
    style.Colors[ImGuiCol_TabUnfocused] = ImVec4(0.07f, 0.10f, 0.15f, 0.97f);
    style.Colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.14f, 0.26f, 0.42f, 1.00f);
    style.Colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
    style.Colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
    style.Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
    style.Colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
    style.Colors[ImGuiCol_NavHighlight] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
    style.Colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
    style.Colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
    style.Colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
}

int main() {
    sf::RenderWindow window(sf::VideoMode(700, 800), "ImGui + SFML = <3");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
    const char* comboItems[] = { "H" };
    const char* healthModeItems[] = { "Number" };
    int selectedItem = 0;
    bool playersCheck = true;
    bool animalsCheck = false;
    bool monstersCheck = false;
    bool itemsCheck = true;
    bool showTamedCheck = true;
    bool showOwnerCheck = true;
    bool horseStatsCheck = true;
    float slideFloat = 3;
    bool showNameCheck = true;
    bool showHealthCheck = true;
    bool customNameCheck = true;
    bool itemCountCheck = true;
    bool playersTracerCheck = true;
    bool monstersTracerCheck = false;
    bool animalsTracerCheck = false;
    bool itemsTracerCheck = false;
    bool crystalsTracerCheck = false;
    bool vehiclesTracerCheck = false;
    float tracerWidth = 0;
    float tracerOpacity = 1;

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Hacks", 0, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoBringToFrontOnFocus);
        Style();

        ImGui::BeginTabBar("TabBar");

        if (ImGui::BeginTabItem("Combat")) {
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Player")) {
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Movement")) {
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("World")) {
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Render")) {
            ImGui::CollapsingHeader("Full Bright");
            if (ImGui::CollapsingHeader("Name Tags"))
            {
                ImGui::Combo("Armor Mode", &selectedItem, comboItems, IM_ARRAYSIZE(comboItems));
                ImGui::Combo("Health Mode", &selectedItem, healthModeItems, IM_ARRAYSIZE(healthModeItems));
                ImGui::Checkbox("Players", &playersCheck);
                ImGui::Checkbox("Animals", &animalsCheck);
                ImGui::Checkbox("Monsters", &monstersCheck);
                ImGui::Checkbox("Items", &itemsCheck);
                ImGui::Checkbox("Show Tamed", &showTamedCheck);
                ImGui::Checkbox("Show Owner", &showOwnerCheck);
                ImGui::Checkbox("Horse Stats", &horseStatsCheck);
                ImGui::SliderFloat("Size", &slideFloat, 0.0f, 5.0f);
                ImGui::Checkbox("Show Name", &showNameCheck);
                ImGui::Checkbox("Show Health", &showHealthCheck);
                ImGui::Checkbox("Custom Name", &customNameCheck);
                ImGui::Checkbox("Item Count", &itemCountCheck);
            }
            if (ImGui::CollapsingHeader("Tracers"))
            {
                ImGui::Checkbox("Players", &playersTracerCheck);
                ImGui::Checkbox("Monsters", &monstersTracerCheck);
                ImGui::Checkbox("Animals", &animalsTracerCheck);
                ImGui::Checkbox("Items", &itemsTracerCheck);
                ImGui::Checkbox("Crystals", &crystalsTracerCheck);
                ImGui::Checkbox("Vehicles", &vehiclesTracerCheck);
                ImGui::SliderFloat("Width", &tracerWidth, 0.0f, 5.0f);
                ImGui::SliderFloat("Opacity", &tracerOpacity, 0.0f, 1.0f);
            }
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Exploits")) {
            ImGui::EndTabItem();
        }

        if (ImGui::BeginTabItem("Misc")) {
            ImGui::EndTabItem();
        }

        ImGui::EndTabBar();

        {
            ImGui::SetWindowPos(ImVec2(0, 0));
            ImGui::SetWindowSize(ImVec2(window.getSize().x, window.getSize().y));
        }


        ImGui::End();

        window.clear();
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}