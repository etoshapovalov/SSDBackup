#pragma once
#include <iostream>
class ProgressIndicator {
private:
    const char* title = "";
    unsigned int progress = 0;
    unsigned int total = 0;
public:
    ProgressIndicator(const char* title, unsigned int totalCount) : title(title), total(totalCount){};
    void incrementProgress();
    void printProgress();
};