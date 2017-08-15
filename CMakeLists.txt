# Set CMake Version Required
cmake_minimum_required(VERSION 3.0)

# Set Project Name
project(kdeconnect-sms)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 14)

# Set Compiler Flags
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

# Turn On Automoc
set(CMAKE_AUTOMOC ON)

# Find Packages
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5NetworkAuth REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Get Source Files
file(GLOB_RECURSE SOURCE_FILES SourceFiles/*.cpp)

# Add Executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Link Libraries
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::NetworkAuth Qt5::Widgets)
