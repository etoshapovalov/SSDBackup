#include <iostream>
#include "RecursiveDirectory.h"
#include "FileMover.h"
int main(int argc, char** argv){
    std::unique_ptr<RecursiveDirectory> fromFolder = std::make_unique<RecursiveDirectory>("/Volumes/MacHDD/Users/andry/Documents/SoundProjectsSSD/");
    std::filesystem::path toFolder("/Volumes/DATA/ProjectsBackup/");

    std::cout << "Scanning FROM directory..." << std::endl;
    fromFolder.get()->scanDirectory();

    FileMover mover(fromFolder, toFolder);
    std::cout << "Finding differences..." << std::endl;
    mover.findDifferences();
    std::cout << "Moving files..." << std::endl;
    mover.moveFilesWithDifferences();
    return 0;
}