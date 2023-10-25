// C++ - Medium

#pragma once
#include <string>

class FileHandler {
public:
    // TODO: Implement the FileHandler class
    FileHandler();  // Constructor
    ~FileHandler(); // Destructor

    std::string ReadFile(const std::string& filePath);
    bool WriteFile(const std::string& filePath, const std::string& content);
    bool AppendFile(const std::string& filePath, const std::string& content);
    bool FileExists(const std::string& filePath);
};
