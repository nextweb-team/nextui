#include <filesystem>
#include "loader.hpp"
#include <fstream>
#include <iostream>

std::string Loader::loadFile(const std::string& fileName)
{

std::filesystem::path path(fileName);
    if (path.extension() != ".nui")
    {
        std::cerr << "Loading file " << fileName << "failed (wrong extension)" << std::endl;
        return "";
    }
    std::ifstream file(fileName);

    if (!file.is_open())
    {
        std::cerr << "Loading file " << fileName << "failed: cannot open the file" << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
