cmake_minimum_required(VERSION 3.10)
project(ChangeLocale VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(ChangeLocale SHARED src/ChangeLocale.cpp)

target_compile_definitions(ChangeLocale PRIVATE _WINDLL _UNICODE UNICODE)

if(MSVC)
  target_compile_options(ChangeLocale PRIVATE /EHsc /MD)
endif()

if(MSVC)
  set_target_properties(ChangeLocale PROPERTIES LINK_FLAGS "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/src/ChangeLocale.def")
else()
  set_target_properties(ChangeLocale PROPERTIES LINK_FLAGS "-Wl,--defsym,DllMain=DllMain")
endif()

# Set the output file name
set_target_properties(ChangeLocale PROPERTIES OUTPUT_NAME "ChangeLocale")

# Remove the prefix
set_target_properties(ChangeLocale PROPERTIES PREFIX "")

# Enable precompiled headers
if(MSVC)
  target_precompile_headers(ChangeLocale PRIVATE src/stdafx.h)
endif()


# Define the destination directory for the DLL
set(DIST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/dist")

# Create the destination directory if it does not exist
file(MAKE_DIRECTORY ${DIST_DIR})

# Add a custom command to copy the DLL after the build
add_custom_command(TARGET ChangeLocale POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                   $<TARGET_FILE:ChangeLocale>
                   ${DIST_DIR}/ChangeLocale.dll)
