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
#include <filesystem>

#include <nlohmann/json.hpp>


using json = nlohmann::json;

class Project {
private:
    std::string              sabrFile;
    json                     sabrFileJson;

    std::string              projectName = "blank";
    std::string              projectAuthor = "blank";
    std::string              projectBinary = "a.out";
    std::vector<std::string> projectSources = { "main.cpp" };
    std::string              projectCompiler = "g++";
    std::string              projectCompilerFlags = "-O3";
    std::string              projectCompilerFormat = "%c %s -o %o %f";

public:
    bool isBuilt();

    explicit Project(const std::string& sabrFile = "./build.sabr") : sabrFile(sabrFile) {
        try {
            std::ifstream sabrFileStream(sabrFile);
            this->sabrFileJson = json::parse(sabrFileStream);
            sabrFileStream.close();

            // if the json is missing a part it will just use the default values from above ^
            try { this->projectName = this->sabrFileJson["name"]; } catch (std::exception &_i) {}
            try { this->projectAuthor = this->sabrFileJson["author"]; } catch (std::exception &_i) {}
            try { this->projectBinary = this->sabrFileJson["binary"]; } catch (std::exception &_i) {}
            try { this->projectSources = this->sabrFileJson["sources"]; } catch (std::exception &_i) {}
            try { this->projectCompiler = this->sabrFileJson["compiler"]; } catch (std::exception &_i) {}
            try { this->projectCompilerFlags = this->sabrFileJson["compilerFlags"]; } catch (std::exception &_i) {}
            try { this->projectCompilerFormat = this->sabrFileJson["compilerFormat"]; } catch (std::exception &_i) {}
        } catch (std::exception &_i) {
            throw std::runtime_error("failed to read sabr file.");
        }
    }
    ~Project() = default;

    friend std::ostream &operator<<(std::ostream &out, const Project &project);
    friend class Builder;
};


#endif //SABR_PROJECT_HPP
