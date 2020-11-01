find_package(jsoncpp QUIET)

if(jsoncpp_FOUND)
    message(STATUS "Found jsoncpp version ${jsoncpp_VERSION}")
else()
    message(STATUS "jsoncpp could not be located, Building jsoncpp instead.")
    include(FetchContent)

    FetchContent_Declare(
            _jsoncpp
            GIT_REPOSITORY  https://github.com/open-source-parsers/jsoncpp.git
            GIT_TAG         1.9.4
            CMAKE_ARGS
            -JSONCPP_WITH_EXAMPLE:BOOL="0"
            -JSONCPP_WITH_POST_BUILD_UNITTEST:BOOL="0"
            -JSONCPP_WITH_TESTS:BOOL="0")

    FetchContent_GetProperties(_jsoncpp)
    if(NOT _jsoncpp_POPULATED)
        FetchContent_Populate(_jsoncpp)
        message(STATUS "Added jsoncpp source : ${_jsoncpp_SOURCE_DIR}")
        message(STATUS "Added jsoncpp binary : ${_jsoncpp_BINARY_DIR}")
        add_subdirectory(
                ${_jsoncpp_SOURCE_DIR}
                ${_jsoncpp_BINARY_DIR}
        )
    endif()
    target_include_directories(csugar PRIVATE "${_jsoncpp_SOURCE_DIR}/include")
    if(ENABLE_UNIT_TESTS)
        target_include_directories(tests_csugar PRIVATE "${_jsoncpp_SOURCE_DIR}/include")
    endif()
endif()