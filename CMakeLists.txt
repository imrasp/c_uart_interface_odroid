cmake_minimum_required(VERSION 3.2)
project(c_uart_interface_odroid)

# default built type
IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF()

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
find_package(Qt5Gui)
find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Test)
find_package(Qt5Concurrent)
find_package(Qt5OpenGL)

set(SOURCE_FILES
        autopilot_interface.cpp
        autopilot_interface.h
        configParam.cpp
        configParam.h
        main.cpp
        mavlink_control.cpp
        mavlink_control.h
        serial_port.cpp
        serial_port.h camera_recorder.cpp camera_recorder.h log.cpp log.h imu_recorder.cpp imu_recorder.h)

include_directories(
        ${CMAKE_SOURCE_DIR}/mavlink/include/mavlink/v1.0
)

add_executable(c_uart_interface_odroid ${SOURCE_FILES})

target_link_libraries(
        c_uart_interface_odroid
        pthread

        boost_system
        boost_thread
        boost_filesystem
        boost_date_time
        boost_chrono

        opencv_core
        opencv_highgui
        opencv_calib3d
)