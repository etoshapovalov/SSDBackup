#include "FileMover.h"

FileMover::FileMover(const std::unique_ptr<RecursiveDirectory>& from,
                        const std::filesystem::path to) : fromDir(from), toDir(to) {

}
void FileMover::findDifferences(){

    std::vector<File> fileList = fromDir.get()->getFileListReference();
    std::filesystem::path rootPath(fromDir.get()->getRootPath());
    ProgressIndicator progress("Finding differences...",fileList.size());
    for(File file : fileList){
        std::filesystem::path inFileRelativePath = std::filesystem::relative(file.path, rootPath);
        std::filesystem::path outFileAbsolutePath = toDir / inFileRelativePath;
        bool fileExists = std::filesystem::exists(outFileAbsolutePath);
        if(fileExists) {
            unsigned long fromModTime = file.modTime;
            unsigned long toModTime = 0;
            
            struct stat result;
            if(stat(outFileAbsolutePath.c_str(), &result)==0)
            {
                toModTime = result.st_mtime;
            }
            if(fromModTime == 0 || toModTime == 0){
                std::cout << "ERROR DATE MODIFIED NOT FOUND" << std::endl;
                continue;
            }
            if(fromModTime <= toModTime) {
                progress.incrementProgress();
                continue;
            }
        }
        Diff diff;
        diff.fromPath = file.path;
        diff.toPath = outFileAbsolutePath;
        diff.outFilePresent = fileExists;
        diffList.push_back(diff);
        progress.incrementProgress();
    }
}
void FileMover::moveFilesWithDifferences(){
    ProgressIndicator progress("Moving files...",diffList.size());
    for(Diff diff : diffList){
        std::filesystem::create_directories(diff.toPath.parent_path());
        std::filesystem::copy_file(diff.fromPath, diff.toPath, std::filesystem::copy_options::overwrite_existing);
        progress.incrementProgress();
    }
}