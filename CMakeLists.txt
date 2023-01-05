cmake_minimum_required(VERSION 2.8)

project(BinaryFileConvert)


if (WIN32)
    set(OpenCV_DIR "C:/Program Files/PCL 1.12.0/3rdParty/opencv/build")
else()
    set(OpenCV_DIR "/home/w/Desktop/3.4.0/opencv-3.4.0/build")
    link_libraries(-lvriapi)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lz -Wl,-rpath=./lib -lrt")
endif ()

find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(${PROJECT_NAME} "main.cpp")
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
