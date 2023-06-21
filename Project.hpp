//
// Created by lucas on 6/19/23.
//

#pragma once

#ifndef SABR_PROJECT_HPP
#define SABR_PROJECT_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include <nlohmann/json.hpp>


using json = nlohmann::json;

class Project {
private:
    std::string              sabrFile;
    json                     sabrFileJson;

    std::string              projectName;
    std::string              projectBinary;
    std::vector<std::string> projectSources;
    std::string              projectCompiler;
    std::string              projectCompilerFlags;
    std::string              projectCompilerFormat;

public:
    friend std::ostream &operator<<(std::ostream &out, const Project &project);

    explicit Project(const std::string& sabrFile = "./build.sabr") : sabrFile(sabrFile) {
        try {
            std::ifstream sabrFileStream(sabrFile);
            this->sabrFileJson = json::parse(sabrFileStream);
            sabrFileStream.close();

            this->projectName = this->sabrFileJson["name"];
            this->projectBinary = this->sabrFileJson["binary"];
            this->projectSources = this->sabrFileJson["sources"];
            this->projectCompiler = this->sabrFileJson["compiler"];
            this->projectCompilerFlags = this->sabrFileJson["compilerFlags"];
            this->projectCompilerFormat = this->sabrFileJson["compilerFormat"];
        } catch (std::exception &_ignored) {
            throw std::runtime_error("Failed to read sabr file.");
        }
    }
    ~Project() = default;

    friend class Builder;
};


#endif //SABR_PROJECT_HPP
