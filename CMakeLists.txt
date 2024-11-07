cmake_minimum_required(VERSION 3.30)
project(SSDBackup)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPENSSL_USE_STATIC_LIBS TRUE)
find_package(OpenSSL REQUIRED)

add_executable(SSDBackup src/main.cpp src/RecursiveDirectory.cpp src/RecursiveDirectory.h src/FileMover.h src/FileMover.cpp src/ProgressIndicator.h src/ProgressIndicator.cpp)

target_link_libraries(SSDBackup OpenSSL::Crypto)
