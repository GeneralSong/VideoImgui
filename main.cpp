#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>


#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

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
    ImGuiIO& io = ImGui::GetIO();
    (void)io;

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

        ImGui::Begin("MyImgWindow", 0, ImGuiWindowFlags_::ImGuiWindowFlags_MenuBar);
        ImGui::Text(Text.c_str());
        if (ImGui::Button("MyButton")) {
            Text = "You Click The Button";
        }
        ImGui::InputText("Test Text Box", textbox, 50);

        ImGui::ListBoxHeader("List Box");
        for (int i = 0; i < 100; i++) {
            if (ImGui::Selectable(std::to_string(i).c_str())) {
                Text = std::to_string(i);
            }
        }
        ImGui::ListBoxFooter();

        if (ImGui::BeginCombo("##combo", Text.c_str())) // The second parameter is the label previewed before opening the combo.
        {
            for (int i = 0; i< 100;i++)
            {
                if (ImGui::Selectable(std::to_string(i).c_str())) {
                    Text = std::to_string(i);
                }
            }
            ImGui::EndCombo();
        }


        ImGui::ColorEdit4("Test color", (float*)&color,ImGuiColorEditFlags_::ImGuiColorEditFlags_AlphaBar);

        ImGui::End();




        ImGui::ShowDemoWindow();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(Windows);
        glfwPollEvents();
    }

    return 0;
}



