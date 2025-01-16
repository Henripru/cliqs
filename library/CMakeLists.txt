set(SOURCES
    src/cliqs.cpp
)

if (CLIQS_BUILD_SHARED)
    add_library(cliqs SHARED ${SOURCES})
elseif (CLIQS_BUILD_STATIC)
    add_library(cliqs SHARED ${SOURCES})
else()
    message(FATAL_ERROR "No library type specified (expecting CLIQS_BUILD_SHARED or CLIQS_BUILD_STATIC to be defined)")
endif()
target_include_directories(cliqs PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
