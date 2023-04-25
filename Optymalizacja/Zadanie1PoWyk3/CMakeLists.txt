cmake_minimum_required(VERSION 3.0)
project(MyProgram)


# Add all the source files to a variable
set(SOURCES
    main.cpp
)

add_executable(MyProgram ${SOURCES})