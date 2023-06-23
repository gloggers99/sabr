//
// Created by lucas on 6/19/23.
//

#pragma once

#include <iostream>
#include <unordered_map>
#include <filesystem>

#include <unistd.h>

#include "Project.hpp"
#include "Spinner.hpp"
#include "Config.hpp"

// Builder.hpp:
//
// This class is almost like a wrapper
// around project that builds and manages
// your project;

enum Result {
    Success = 0,
    Failure = 1
};

class Builder {
private:
    Project project;

public:
    Result build();
    Result install();
    Result uninstall();
    Result clean();

    explicit Builder(const Project& project) : project(project) {}
    ~Builder() = default;
};
