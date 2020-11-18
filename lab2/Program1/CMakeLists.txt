#ustawienie wersji CMake
cmake_minimum_required(VERSION 3.10)

#nazwa projektu
project(lab_ppo)

# dodanie pliku wykonywalnego
#add_executable(Main main.cpp)

#w przypadku kilku plików źródłowych
add_executable(Main main.cpp lab01.cpp lab01.h)
#set(CMAKE_CXX_FLAGS "-Wall -g")