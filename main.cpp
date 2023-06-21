#include <iostream>
#include <string>
#include <filesystem>

#include "Builder.hpp"
#include "Project.hpp"

static bool verboseMode;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        Builder(Project()).build();
    } else {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-v") == 0) {
                verboseMode = true;
            }
        }
    }

    return 0;
}
