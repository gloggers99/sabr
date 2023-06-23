#include <iostream>
#include <string>
#include <filesystem>

#include "Builder.hpp"
#include "Project.hpp"

enum Mode {
    BUILD,
    INSTALL,
    UNINSTALL,
    CLEAN
};

Mode activeMode;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        Builder(Project()).build();
    } else {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "build") == 0) {
                activeMode = Mode::BUILD;
            } else if (strcmp(argv[i], "install") == 0) {
                activeMode = Mode::INSTALL;
            } else if (strcmp(argv[i], "uninstall") == 0) {
                activeMode = Mode::UNINSTALL;
            } else if (strcmp(argv[i], "clean") == 0)  {
                activeMode = Mode::CLEAN;
            }
        }

        switch (activeMode) {
            case Mode::BUILD:
                Builder(Project()).build();
                break;
            case Mode::INSTALL:
                Builder(Project()).install();
                break;
            case Mode::UNINSTALL:
                Builder(Project()).uninstall();
                break;
            case Mode::CLEAN:
                Builder(Project()).clean();
                break;

        }
    }

    return 0;
}
