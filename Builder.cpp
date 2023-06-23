//
// Created by lucas on 6/19/23.
//

#include "Builder.hpp"

Result Builder::build() {
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

    std::cout << "compiling with: \"" << buildCommand << "\".\n";
    int result = system(buildCommand.c_str());

    spinner->stop();

    return result == 0 ? Success : Failure;
}

Result Builder::install() {
    if (!this->project.isBuilt()) {
        this->build();
    }

    Spinner *spinner = new Spinner();
    spinner->setInterval(100);
    spinner->setSymbols("dots2");
    spinner->setText("installing project...");
    spinner->start();

    std::cout << "ensuring privileges...\n";
    if (geteuid() != 0) {
        spinner->stop();
        throw std::runtime_error("can not continue without elevated privileges");
    }

    std::cout << "checking install directory...\n";
    std::filesystem::create_directories(/*Config.hpp::*/installDirectory);

    std::cout << "copying files...\n";
    std::filesystem::copy_file("./bin/" + this->project.projectBinary,
                               installDirectory + this->project.projectBinary,
                               std::filesystem::copy_options::overwrite_existing);

    spinner->stop();

    // If it gets this far then it must have succeeded
    return Success;
}

Result Builder::uninstall() {
    Spinner *spinner = new Spinner();
    spinner->setInterval(100);
    spinner->setSymbols("dots2");
    spinner->setText("uninstalling project...");
    spinner->start();

    std::cout << "ensuring privileges...\n";
    if (geteuid() != 0) {
        spinner->stop();
        throw std::runtime_error("can not continue without elevated privileges");
    }

    return std::filesystem::remove(installDirectory + this->project.projectBinary) ? Success : Failure;
}

Result Builder::clean() {
    Spinner *spinner = new Spinner();
    spinner->setInterval(100);
    spinner->setSymbols("dots2");
    spinner->setText("cleaning project...");
    spinner->start();

    std::filesystem::remove_all("./bin/");

    spinner->stop();

    return Success;
}
