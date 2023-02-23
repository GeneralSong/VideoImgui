#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "GUI.h"

GLFWwindow* Windows;

int main(int argc, char* argv[]) {

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Windows = glfwCreateWindow(900, 800, "GeneralImgui", nullptr, nullptr);

    glfwMakeContextCurrent(Windows);
    glfwSwapInterval(0);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext(nullptr);
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.Fonts->AddFontFromFileTTF("arial.ttf",18,nullptr,io.Fonts->GetGlyphRangesChineseFull());

    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(Windows, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    std::string Text = "112233";
    char textbox[50] = "textbox";
    ImVec4 color;
    while (!glfwWindowShouldClose(Windows)) {
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        DrawGUI();

        ImGui::ShowDemoWindow();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(Windows);
        glfwPollEvents();
    }

    return 0;
}



