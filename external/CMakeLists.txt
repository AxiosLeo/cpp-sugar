message(STATUS "Install external libraries")

if(ENABLE_UNIT_TESTS)
    message(STATUS "Enable testing: ${ENABLE_UNIT_TESTS}")
    add_subdirectory(googletest)
endif()
