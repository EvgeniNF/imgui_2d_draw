set(LIB_NAME imgui)

set(IMGUI_DIR ${PROJECT_SOURCE_DIR}/third_party/imgui)

message("-- Build ImGui")

include_directories(${IMGUI_DIR})

set(HDRS
    ${IMGUI_DIR}/imconfig.h
    ${IMGUI_DIR}/imgui_internal.h
    ${IMGUI_DIR}/imgui.h 
    ${IMGUI_DIR}/imstb_rectpack.h 
    ${IMGUI_DIR}/imstb_textedit.h 
    ${IMGUI_DIR}/imstb_truetype.h
    ${IMGUI_DIR}/backends/imgui_impl_glfw.h
    ${IMGUI_DIR}/backends/imgui_impl_opengl2.h

    common.hpp
)

set(SRCS
    ${IMGUI_DIR}/imgui_demo.cpp 
    ${IMGUI_DIR}/imgui_draw.cpp 
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl2.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
)

add_library(ImGui STATIC ${HDRS} ${SRCS})

target_include_directories(
    ImGui
    PUBLIC
    ${IMGUI_DIR}
    ${PROJECT_SOURCE_DIR}/src
)
