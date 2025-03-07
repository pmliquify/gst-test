cmake_minimum_required(VERSION 3.10)
project(gst-test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Suchen Sie nach der OpenCV-Bibliothek (mit GStreamer-Unterstützung, sofern vorhanden)
find_package(OpenCV REQUIRED)

add_executable(${PROJECT_NAME}
        main.cpp
)

# Linken Sie das Projekt mit den gefundenen OpenCV-Bibliotheken
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})
