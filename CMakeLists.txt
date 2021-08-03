cmake_minimum_required(VERSION 3.0.0)
set(INCR "0" CACHE_VARIABLES )

set(PROJECT_NAME
    "zbrushlib"
    )

# find_package(OpenGL REQUIRED)
# find_package(GLFW REQUIRED)

project(${PROJECT_NAME} VERSION 0.1.0)

set(SRCS
    "src/main.cpp"
    # unnecessary
    "src/pch.cpp"
    "src/stdafx.cpp"
    )
    
set(HEADERS
    "src/main.h"
    # unnecessary
    "src/pch.h"
    "src/stdafx.h"
    )

# include(CTest)
# enable_testing()

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

add_library(${PROJECT_NAME} SHARED ${SRCS} ${HEADERS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)



set_target_properties(${PROJECT_NAME} PROPERTIES
                      RUNTIME_OUTPUT_DIRECTORY_DEBUG "D:\\Imaging\\Pixologic\\ZBrush 2020\\ZStartup\\ZPlugs64\\debug\\"
                      RUNTIME_OUTPUT_DIRECTORY_RELEASE "D:\\Imaging\\Pixologic\\ZBrush 2020\\ZStartup\\ZPlugs64\\debug\\"
                      RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "D:\\Imaging\\Pixologic\\ZBrush 2020\\ZStartup\\ZPlugs64\\debug\\"
)
file(WRITE
     "D:\\Imaging\\Pixologic\\ZBrush 2020\\ZStartup\\ZPlugs64\\debug\\dllversion.txt"
     ${PROJECT_NAME}
     
    )