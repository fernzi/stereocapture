cmake_minimum_required(VERSION 3.1.0)

project(StereoCapture VERSION 0.1.0)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 11)

include_directories(source)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5MultimediaWidgets REQUIRED)

file(GLOB_RECURSE SRC
  source/*.cc
)

file(GLOB_RECURSE RCC
  source/*.qrc
)

configure_file(source/config.hh.in config.hh)

qt5_add_resources(SRC ${RCC})

set(BIN_NAME stereocapture)
add_executable(${BIN_NAME} ${SRC})
target_link_libraries(${BIN_NAME}
  Qt5::Widgets
  Qt5::Multimedia
  Qt5::MultimediaWidgets
)
install(TARGETS ${BIN_NAME} DESTINATION bin)
