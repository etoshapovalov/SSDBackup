#include "RecursiveDirectory.h"

RecursiveDirectory::RecursiveDirectory(const char* path){
    this->path = std::filesystem::path(path);
    this->rootPath = path;
    this->allFiles = std::vector<File>();
}
RecursiveDirectory::~RecursiveDirectory(){}

void RecursiveDirectory::addFileToList(const std::filesystem::directory_entry& entry){
    File file;
    file.path = entry.path();
    struct stat result;
    if(stat(entry.path().c_str(), &result)==0)
    {
        file.modTime = result.st_mtime;
    }
    allFiles.push_back(file);
}
void RecursiveDirectory::scanDirRecurse(const std::filesystem::path& path){
    std::cout << "Scanning dir" << path.c_str() << std::endl;
    for (const std::filesystem::directory_entry& entry : std::filesystem::recursive_directory_iterator(path)){
        if(!entry.is_directory()){
            addFileToList(entry);
        }
    }
}
void RecursiveDirectory::scanDirectory(){
    scanDirRecurse(rootPath);
}

uint64_t RecursiveDirectory::getFileCount(){
    return allFiles.size();
}
const std::vector<File>& RecursiveDirectory::getFileListReference(){
    return allFiles;
}
const char* RecursiveDirectory::getRootPath(){
    return rootPath;
}