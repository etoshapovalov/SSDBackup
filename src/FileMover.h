#pragma once
#include "RecursiveDirectory.h"
#include "ProgressIndicator.h"
#include <vector>
#include <optional>
#include <fstream>
struct Diff {
    std::filesystem::path fromPath;
    std::filesystem::path toPath;
    bool outFilePresent;
};
class FileMover {
private:
    const std::unique_ptr<RecursiveDirectory>& fromDir;
    const std::filesystem::path toDir;
    std::vector<Diff> diffList;
public:
    FileMover(const std::unique_ptr<RecursiveDirectory>& from,
                        const std::filesystem::path to);
    void findDifferences();
    void moveFilesWithDifferences();
};