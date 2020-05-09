cmake_minimum_required(VERSION 2.8.9)
project(nk_openmp)
set(CMAKE_BUILD_TYPE Release)
 
#Bring the headers, such as Student.h into the project
include_directories(include)
 
#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/*.c")
 
#Generate the static library from the sources
add_library(nk_openmp STATIC ${SOURCES})
 
#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to appl
install(TARGETS nk_openmp DESTINATION /home/446/openmp/lib)
