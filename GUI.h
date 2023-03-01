#pragma once
#include "imgui/imgui.h"
#include <vector>

std::vector<int> DragList;
void DrawGUI() {
    ImGui::Begin("window");
    if (ImGui::IsKeyPressed(ImGuiKey_Q) && ImGui::IsItemHovered()) {
        ImGui::Text("hello");
    }

    for (int i = 0; i < 5; i++) {
        ImGui::Button(std::to_string(i).c_str());
        if (i + 1 < 5) {
            ImGui::SameLine();
        }
        if (ImGui::BeginDragDropSource()) {
            ImGui::Text(std::string("Drag : ").append(std::to_string(i)).c_str());
            ImGui::SetDragDropPayload("DragIndexButton", &i, sizeof(i));
            ImGui::EndDragDropSource();
        }
    }


    ImGui::End();

    ImGui::Begin("Drag WIndow");

    ImGui::Text("Drag Target");

    if (ImGui::BeginDragDropTarget()) {
        if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("DragIndexButton")) {

            DragList.push_back(*(const int*)payload->Data);
        }
        ImGui::EndDragDropTarget();
    }

    for (int i = 0; i < DragList.size(); i++) {
        if (ImGui::Button(std::to_string(DragList[i]).c_str())) {
            DragList.erase(DragList.begin() + i);
        }
        if (i + 1 < DragList.size()) {
            ImGui::SameLine();
        }
    }

    ImGui::End();



}