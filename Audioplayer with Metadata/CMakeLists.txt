cmake_minimum_required(VERSION 3.16)
project(audioplayer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CMakeLocal.txt OPTIONAL)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
		Multimedia
        REQUIRED)
qt_standard_project_setup()

add_executable(audioplayer main.cpp mainwindow.cpp mainwindow.h mainwindow.ui)
target_link_libraries(audioplayer PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
		Qt::Multimedia
        )
