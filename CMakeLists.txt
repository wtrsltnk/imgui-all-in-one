cmake_minimum_required(VERSION 3.7)

project(imgui-all-in-one)

find_package(OPENGL REQUIRED)

add_executable(imgui-all-in-one
    application.cpp
    glad.c
    imgui/imgui.cpp
    imgui/imgui.h
    imgui/imgui_demo.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_impl_opengl3.cpp
    imgui/imgui_impl_opengl3.h
    imgui/imgui_impl_win32.cpp
    imgui/imgui_impl_win32.h
    imgui/imgui_internal.h
    imgui/imgui_widgets.cpp
    main.cpp
    )

target_include_directories(imgui-all-in-one
    PUBLIC include
    PUBLIC imgui)

target_compile_features(imgui-all-in-one
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

target_link_libraries(imgui-all-in-one
    PRIVATE
        ${OPENGL_LIBRARIES})

target_compile_options(imgui-all-in-one
    PUBLIC 
        -DUNICODE
        -D_UNICODE
        -DIMGUI_IMPL_WIN32_DISABLE_GAMEPAD)

if(MINGW)
    target_link_options(imgui-all-in-one
        PUBLIC -static -mwindows -municode)
endif()
