cmake_minimum_required(VERSION 3.10)


project(ChessGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

ADD_SUBDIRECTORY(googletest)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/build")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/build")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/build")

add_library(game
    lib/Board.cpp
    lib/pawn.cpp
    lib/king.cpp
    lib/rook.cpp
    lib/bishop.cpp
    lib/knight.cpp
    lib/queen.cpp
    lib/Display.cpp
    lib/ui.cpp
    lib/Game.cpp
)

# Add executable target
# add_executable(ChessGameExecutable
#    main.cpp  # Replace with your actual main file
# )

# # Link the library to the executable
# target_link_libraries(ChessGameExecutable PRIVATE game)

# Add executable testing target
add_Executable(test
    test.cpp
)

TARGET_LINK_LIBRARIES(test game)
TARGET_LINK_LIBRARIES(test gtest)

# Necessary edit for gtest compatibility
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)

# ptionally, you can set the output name explicitly
# set_target_properties(ChessGameExecutable PROPERTIES OUTPUT_NAME "ChessGame")
