# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(Simple Vector Operations C)

# Set the C standard to C99
set(CMAKE_C_STANDARD 99)

# Add source files
set(SOURCE_FILES
    vec2.c
    vec3.c
    vecn.c
    matrixn.c
    main.c
    app.c
)

# Add header files
set(HEADER_FILES
    vec2.h
    vec3.h
)

# Create the executable
add_executable(app ${SOURCE_FILES} ${HEADER_FILES})

# Optionally, set compiler flags
# target_compile_options(matrixn PRIVATE -Wall -Wextra)
