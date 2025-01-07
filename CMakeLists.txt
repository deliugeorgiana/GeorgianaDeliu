cmake_minimum_required(VERSION 3.16)

# Setează numele proiectului
project(ShowRadar LANGUAGES CXX)

# Specifică standardul C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Activează avertismentele stricte
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wall -Wextra -Wpedantic -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4 /WX)
endif()

# Adaugă directoarele cu fișierele sursă
add_executable(oop
        main.cpp
        MediaItem.cpp
        MediaItem.h
        User.cpp
        User.h
        Category.cpp
        Category.h
        Actor.cpp
        Actor.h
        Watchlist.cpp
        Watchlist.h
)

# Activează sanitizările pentru debug (doar dacă sunt suportate)
if (CMAKE_BUILD_TYPE STREQUAL "Debug" AND (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID STREQUAL "GNU"))
    add_compile_options(-fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(oop PRIVATE -fsanitize=address,undefined)
endif()

# Include directoarele pentru fișierele de antet
target_include_directories(oop PRIVATE ${CMAKE_SOURCE_DIR})
