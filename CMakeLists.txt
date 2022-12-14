cmake_minimum_required(VERSION 3.1)
project(testbed)

set(PROJECT_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src)
set(PROJECT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

set(TARGET_INSTALL_DIR /usr/local/testbed/)
set(CONFIG_INSTALL_DIR /usr/local/testbed/config/)

include_directories(
    ${PROJECT_SOURCE_DIR}
    ${PROJECT_INCLUDE_DIR})

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES 
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

install(TARGETS ${PROJECT_NAME} 
        RUNTIME DESTINATION ${TARGET_INSTALL_DIR})

target_compile_definitions(
    ${PROJECT_NAME} 
    PUBLIC
    VERSION_PATH="${TARGET_INSTALL_DIR}")

install(FILES VERSION 
        DESTINATION ${TARGET_INSTALL_DIR})

target_compile_definitions(
    ${PROJECT_NAME} 
    PUBLIC
    DEFAULT_CONFIG_PATH="${CONFIG_INSTALL_DIR}")

install(FILES default.config 
        DESTINATION ${CONFIG_INSTALL_DIR})
