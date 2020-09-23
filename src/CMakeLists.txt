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

add_library(sha1                SHARED sha1/sha1.cpp)

add_library(direction           SHARED graph/direction.cpp)
add_library(graphPoint          SHARED graph/graphPoint.cpp)
target_link_libraries(graphPoint direction)
add_library(element             SHARED graph/element.cpp)
add_library(grid                SHARED graph/grid.cpp)
target_link_libraries(grid element graphPoint)

add_library(parseGraphPoint     SHARED graph/graphPointParser.cpp)
target_link_libraries(parseGraphPoint graphPoint)
add_library(parseGrid           SHARED graph/gridParser.cpp)
target_link_libraries(parseGrid grid)

add_library(pathFind            SHARED operatorID/pathFind.cpp)
target_link_libraries(pathFind graphPoint grid)
add_library(pathFindBFS         SHARED operatorID/pathFindBFS.cpp)
target_link_libraries(pathFindBFS sha1 grid pathFind)
add_library(pathFindDFS         SHARED operatorID/pathFindDFS.cpp)
target_link_libraries(pathFindDFS sha1 grid pathFind)
add_library(pathFindAStar       SHARED operatorID/pathFindAStar.cpp)
target_link_libraries(pathFindAStar sha1 grid pathFind)
add_library(pathFindBestFS      SHARED operatorID/pathFindBestFS.cpp)
target_link_libraries(pathFindBestFS sha1 grid pathFind)

add_library(operatorIDParser    SHARED operatorID/parser.cpp)
target_link_libraries(operatorIDParser pathFindBestFS pathFindAStar pathFindBFS pathFindDFS grid graphPoint parseGrid parseGraphPoint)

add_library(myClientHandler     SHARED clientHandler/myClientHandler.cpp)
target_link_libraries(myClientHandler operatorIDParser)

add_library(mySolver            SHARED solver/mySolver.cpp)

add_library(fileCacheManager    SHARED cacheManager/fileCacheManager/fileCacheManager.cpp)
add_library(folderManager       SHARED cacheManager/fileCacheManager/folderManager.cpp)
target_link_libraries(fileCacheManager folderManager)


add_executable(test_basicServer tests/basicServer.cpp)
target_link_libraries(test_basicServer mySerialServer myTestClientHandler Threads::Threads)

add_executable(test_betterServer tests/betterServer.cpp)
target_link_libraries(test_betterServer mySerialServer myClientHandler mySolver fileCacheManager Threads::Threads)

add_executable(test_properServer tests/properServer.cpp)
target_link_libraries(test_properServer mySerialServer myClientHandler mySolver fileCacheManager Threads::Threads)
