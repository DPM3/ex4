project(ex4)
cmake_minimum_required(VERSION 3.0.0)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)
add_compile_options(-Wall -Wextra -pedantic -Werror -pthread)
include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_library(mySerialServer      SHARED server/mySerialServer.cpp)

add_library(myTestClientHandler SHARED clientHandler/myTestClientHandler.cpp)

add_library(myTestOperatorID    SHARED operatorID/myTestOperatorID.cpp)
add_library(operatorIDParser    SHARED operatorID/parser.cpp)
add_library(myClientHandler     SHARED clientHandler/myClientHandler.cpp)
target_link_libraries(myClientHandler myTestOperatorID operatorIDParser)

add_library(mySolver            SHARED solver/mySolver.cpp)

add_library(fileCacheManager    SHARED cacheManager/fileCacheManager/fileCacheManager.cpp)
add_library(folderManager       SHARED cacheManager/fileCacheManager/folderManager.cpp)
target_link_libraries(fileCacheManager folderManager myTestOperatorID)


add_executable(test_basicServer tests/basicServer.cpp)
target_link_libraries(test_basicServer mySerialServer myTestClientHandler Threads::Threads)

add_executable(test_betterServer tests/betterServer.cpp)
target_link_libraries(test_betterServer mySerialServer myClientHandler mySolver fileCacheManager Threads::Threads)

add_executable(test_properServer tests/properServer.cpp)
target_link_libraries(test_properServer mySerialServer myClientHandler mySolver fileCacheManager Threads::Threads)
