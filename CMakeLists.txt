cmake_minimum_required(VERSION 3.26)

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing executable name in this file
# for now, the project name is used as the executable name
project(oop)
# set(CMAKE_PROJECT_VERSION_MAJOR 0)
# set(CMAKE_PROJECT_VERSION_MINOR 0)
# set(CMAKE_PROJECT_VERSION_PATCH 1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(cmake/Options.cmake)

###############################################################################

# Ensure Clang is used for compilation
set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

# Add debugging and MemorySanitizer flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -fsanitize=memory -fno-omit-frame-pointer")
set(CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fsanitize=memory")

###############################################################################

# external dependencies with FetchContent
# include(FetchContent)
#
# set(FETCHCONTENT_QUIET OFF)
# set(FETCHCONTENT_UPDATES_DISCONNECTED ON)
#
# NOTE: Also update env vars used for caching in
#         - .github/actions/configure-cmake/action.yml
#         - .github/workflows/cmake.yml
# FetchContent_Declare(
#         SomeLib
#         GIT_REPOSITORY https://github.com/<SomeUser>/<SomeLib>.git
#         GIT_TAG        <some_git_hash> # <which tag/branch @ <some_date>
#         GIT_SHALLOW    1  # works only with branches or tags, not with arbitrary commit hashes
# )
#
# FetchContent_MakeAvailable(SomeLib)

###############################################################################

# external dependencies with find_package

# find_package(Threads REQUIRED)

###############################################################################

# NOTE: update executable name in .github/workflows/cmake.yml:25 when changing name here
add_executable(${PROJECT_NAME}
        main.cpp
        MediaItem.cpp
        MediaItem.h
        User.cpp
        User.h
        Actor.cpp
        Actor.h
        Category.cpp
        Category.h
        Watchlist.cpp
        Watchlist.h
        Movie.cpp
        Movie.h
        Serial.cpp
        Serial.h
        TVShow.cpp
        TVShow.h
        DramaCategory.cpp
        DramaCategory.h
        SciFiCategory.cpp
        SciFiCategory.h
        ComedyCategory.cpp
        ComedyCategory.h
        AdminUser.cpp
        AdminUser.h
        PremiumUser.cpp
        PremiumUser.h
        GuestUser.cpp
        GuestUser.h
        LeadActor.cpp
        LeadActor.h
        SupportingActor.cpp
        SupportingActor.h
        GuestActor.cpp
        GuestActor.h
        FavoritesWatchlist.cpp
        FavoritesWatchlist.h
        RecommendationsWatchlist.cpp
        RecommendationsWatchlist.h
        RecentWatchlist.cpp
        RecentWatchlist.h
        WatchlistUtils.cpp
        WatchlistUtils.h
        Observer.cpp
        Observer.h
        ConcreteObserver.cpp
        ConcreteObserver.h
        Singleton.cpp
        Singleton.h
)

# Add custom compiler flags (if needed)
include(cmake/CompilerFlags.cmake)

###############################################################################

# use SYSTEM so cppcheck and clang-tidy do not report warnings from these directories
# target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ext/<SomeHppLib>/include)
# target_include_directories(${PROJECT_NAME} SYSTEM PRIVATE ${<SomeLib>_SOURCE_DIR}/include)
# target_link_directories(${PROJECT_NAME} PRIVATE ${<SomeLib>_BINARY_DIR}/lib)
# target_link_libraries(${PROJECT_NAME} <SomeLib>)

###############################################################################

# copy binaries to "bin" folder; these are uploaded as artifacts on each release
# DESTINATION_DIR is set as "bin" in cmake/Options.cmake:6
install(TARGETS ${PROJECT_NAME} DESTINATION ${DESTINATION_DIR})
if(APPLE)
    install(FILES launcher.command DESTINATION ${DESTINATION_DIR})
endif()

include(cmake/CopyHelper.cmake)
copy_files(FILES tastatura.txt)
# copy_files(FILES tastatura.txt config.json DIRECTORY images sounds)
# copy_files(DIRECTORY images sounds)
