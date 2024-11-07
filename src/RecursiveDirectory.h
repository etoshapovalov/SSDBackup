#pragma once
#include <string>
#include <filesystem>
#include <vector>
#include <fstream>
#include "FileUtil.h"
#include <iostream>
#include <sys/stat.h>
struct File
{
    std::filesystem::path path;
    unsigned long modTime;
};

class RecursiveDirectory {
// FIELDS
private:

    std::filesystem::path path;
    const char* rootPath;
    std::vector<File> allFiles;
// METHODS
private:
    void scanDirRecurse(const std::filesystem::path& path);
    void addFileToList(const std::filesystem::directory_entry& entry);
public:
    RecursiveDirectory(const char* path);
    ~RecursiveDirectory();
    void scanDirectory();
    uint64_t getFileCount();
    const char* getRootPath();
    const std::vector<File>& getFileListReference();
};