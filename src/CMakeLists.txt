include(FetchContent)

FetchContent_Declare(
    boost
    GIT_REPOSITORY https://github.com/boostorg/boost.git
    GIT_TAG master
)
FetchContent_MakeAvailable(boost)

message("BOOST DIR: ${boost_SOURCE_DIR}")

find_package(Threads REQUIRED)

add_library(mapreduce STATIC FileReader.cpp
                             MapReduceService.cpp
                             Mapper.cpp
                             Reducer.cpp
                             ShortestPrefixFinder.cpp
                             Shuffler.cpp
                             Splitter.cpp)
add_executable(mapreduce_cli Main.cpp)
set_target_properties(mapreduce_cli PROPERTIES OUTPUT_NAME mapreduce) #rename the executable to "mapreduce"

target_include_directories(mapreduce PRIVATE ${boost_SOURCE_DIR})

target_link_libraries(mapreduce ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(mapreduce_cli PRIVATE mapreduce)

#BEGIN release
install(TARGETS mapreduce_cli)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
#END
