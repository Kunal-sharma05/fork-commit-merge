#include "FileHandler.h"
#include <fstream>
#include <iostream>

FileHandler::FileHandler() {}

FileHandler::~FileHandler() {}

std::string FileHandler::ReadFile(const std::string& filePath) {
    std::string content;
    std::ifstream file(filePath);

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            content += line + "\n";
        }
        file.close();
    } else {
        std::cerr << "Failed to open the file for reading: " << filePath << std::endl;
    }

    return content;
}

bool FileHandler::WriteFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath);

    if (file.is_open()) {
        file << content;
        file.close();
        return true;
    } else {
        std::cerr << "Failed to open the file for writing: " << filePath << std::endl;
        return false;
    }
}

bool FileHandler::AppendFile(const std::string& filePath, const std::string& content) {
    std::ofstream file(filePath, std::ios::app);

    if (file.is_open()) {
        file << content;
        file.close();
        return true;
    } else {
        std::cerr << "Failed to open the file for appending: " << filePath << std::endl;
        return false;
    }
}

bool FileHandler::FileExists(const std::string& filePath) {
    std::ifstream file(filePath);
    return file.good();
}
