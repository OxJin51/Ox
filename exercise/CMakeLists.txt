cmake_minimum_required(VERSION 3.26)
project(Code)

set(CMAKE_CXX_STANDARD 11)

file (GLOB_RECURSE files *.cpp)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" soft ${file})
    add_executable (${soft} ${file})
endforeach ()

file (GLOB_RECURSE files *.c)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" soft ${file})
    add_executable (${soft} ${file})
endforeach ()
