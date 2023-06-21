//
// Created by lucas on 6/19/23.
//

#pragma once

#include <unordered_map>
#include <filesystem>

#include "Project.hpp"

#include "Spinner.hpp"


enum Result {
    Success = 0,
    Failure = 1
};

class Builder {
private:
    Project project;
public:
    Result build() {
        Spinner *spinner = new Spinner();
        spinner->setInterval(100);
        spinner->setSymbols("dots2");
        spinner->setText("building project...");
        spinner->start();

        std::filesystem::create_directories("./bin");

        std::string buildCommand = project.projectCompilerFormat;

        std::string sourcesCat;
        for (const auto &str : project.projectSources) sourcesCat += (str + " ");

        std::unordered_map<std::string, std::string> formatMap = {
                {"%c", project.projectCompiler},
                {"%s", sourcesCat},
                {"%o", "./bin/" + project.projectBinary},
                {"%f", project.projectCompilerFlags}
        };

        for (const auto &[key, value] : formatMap) {
            size_t index = 0;
            while ((index = buildCommand.find(key, index)) != std::string::npos) {
                buildCommand.replace(index, key.length(), value);
                index += value.length();
            }
        }

        std::cout << "running build command: \"" << buildCommand << "\"\n";
        int result = system(buildCommand.c_str());

        spinner->stop();

        return result == 0 ? Result::Success : Result::Failure;
    }

    Builder(Project project) : project(project) {}
    ~Builder() = default;
};
