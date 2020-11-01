find_package(Boost 1.63 QUIET COMPONENTS random system thread filesystem chrono atomic date_time regex)

if(Boost_FOUND)
    message(STATUS "Found Boost version ${Boost_MAJOR_VERSION}.${Boost_MINOR_VERSION}.${Boost_SUBMINOR_VERSION}")
else()
    message(STATUS "Boost could not be located, Building Boost instead.")
    include(FetchContent)

    set(BOOST_URL "https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.bz2" CACHE STRING "Boost download URL")
    set(BOOST_URL_SHA256 "d73a8da01e8bf8c7eda40b4c84915071a8c8a0df4a6734537ddde4a8580524ee" CACHE STRING "Boost download URL SHA256 checksum")

    FetchContent_Declare(
            _Boost
            URL ${BOOST_URL}
            URL_HASH SHA256=${BOOST_URL_SHA256}
            CMAKE_ARGS
            -DBUILD_TESTS:BOOL="0")

    FetchContent_GetProperties(_Boost)
    if(NOT _Boost_POPULATED)
        FetchContent_Populate(_Boost)
        message(STATUS "Added Boost source : ${_Boost_SOURCE_DIR}")
        message(STATUS "Added Boost binary : ${_Boost_BINARY_DIR}")
        add_subdirectory(
                ${_Boost_SOURCE_DIR}
                ${_Boost_BINARY_DIR}
        )
    endif()
    target_include_directories(csugar PRIVATE "${_Boost_SOURCE_DIR}/include")
    if(ENABLE_UNIT_TESTS)
        target_include_directories(tests_csugar PRIVATE "${_Boost_SOURCE_DIR}/include")
    endif()
endif()