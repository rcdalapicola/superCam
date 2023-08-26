cmake_minimum_required(VERSION 3.5.0)
project(opencvtest VERSION 0.1.0)

include(CTest)
enable_testing()

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/src )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/GLFW/include )
include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/GLEW/include )

add_library(superCam ${CMAKE_CURRENT_SOURCE_DIR}/src/superCam.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/buffer.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/glfwContext.cpp)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )
target_link_libraries(superCam ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/GLFW/lib-vc2015/glfw3.lib)
target_link_libraries(superCam ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/GLEW/lib/Release/x64/glew32s.lib)
target_link_libraries(superCam opengl32.lib)
target_link_libraries( ${PROJECT_NAME} superCam )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)