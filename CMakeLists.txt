cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

project(AudioPluginExample
    VERSION     0.0.1
    LANGUAGES   CXX)

include(FetchContent)

FetchContent_Declare(
  JUCE
  GIT_REPOSITORY https://github.com/juce-framework/JUCE
  GIT_TAG        6.1.4)
FetchContent_MakeAvailable(JUCE)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v2.13.7)
FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/contrib)

enable_testing()
include(Catch)

add_subdirectory(src)
add_subdirectory(test)
