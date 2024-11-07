#include "ProgressIndicator.h"

void ProgressIndicator::incrementProgress(){
    if(progress+1 <= total) progress++;
    printProgress();
}
void ProgressIndicator::printProgress(){
    std::cout << this->title << " (" << progress << "/" << total << ")" << std::endl; 
}