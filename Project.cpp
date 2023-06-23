//
// Created by lucas on 6/19/23.
//

#include "Project.hpp"

bool Project::isBuilt() {
    return std::filesystem::exists("./bin/" + this->projectBinary);
}

std::ostream &operator<<(std::ostream &out, const Project &project) {
    out << project.projectName << ":\n"
              << "\tby: \"" << project.projectAuthor << "\"\n"
              << "\tprovides: \"" << project.projectBinary << "\"\n"
              << "\tsources: \n";

    for (const std::string& source : project.projectSources) {
        out << "\t\t\"" << source << "\"\n";
    }

    out << "\tcompiler: \"" << project.projectCompiler << "\"\n"
              << "\tcompiler flags: \"" << project.projectCompilerFlags << "\"\n"
              << "\tcompiler format: \"" << project.projectCompilerFormat << "\""
              << std::endl;

    return out;
}
