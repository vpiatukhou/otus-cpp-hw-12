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

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.81.0 EXACT)

if (Boost_FOUND)
    target_include_directories(mapreduce PRIVATE ${Boost_INCLUDE_DIRS})
else() #used by GitHub Actions. Please see .github/workflows/release.yaml
    target_include_directories(mapreduce PRIVATE $ENV{BOOST_ROOT})
endif()

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
