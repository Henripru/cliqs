cmake_minimum_required(VERSION 4.0)

project(
    cliqs
    LANGUAGES CXX
    VERSION 1.1.0 
    DESCRIPTION "mDNS wrapper for simplified consumption")

# ============================================================================
# configuration
# ============================================================================

option(CLIQS_INSTALL "Enable installation of cliqs" OFF)
option(CLIQS_BUILD_TESTING "Enable building cliqs tests" ON)
option(CLIQS_BUILD_SAMPLES "Enable building cliqs samples" ON)

if(NOT DEFINED CMAKE_BUILD_TYPE AND NOT IS_MULTI)
    message(STATUS "No CMAKE_BUILD_TYPE set -- using Debug")
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT DEFINED CMAKE_BUILD_TYPE AND NOT IS_MULTI)

include(GNUInstallDirs)

# ============================================================================
# cliqs
# ============================================================================

set(CLIQS_PUBLIC_HDRS 
    cliqs.hpp
)

set(CLIQS_SRCS
    cliqs.cpp
)

if(WIN32)
    set(CMAKE_DEBUG_POSTFIX "d")
endif(WIN32)

add_library(cliqs STATIC ${CLIQS_SRCS} ${CLIQS_PUBLIC_HDRS})
add_library(cliqs::cliqs ALIAS cliqs)

target_include_directories(
    cliqs
    PUBLIC $<BUILD_INTERFACE:${cliqs_BINARY_DIR}>
            $<BUILD_INTERFACE:${cliqs_SOURCE_DIR}>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

# ============================================================================
# Install
# ============================================================================
if(CLIQS_INSTALL)
    install(
        TARGETS cliqs
        COMPONENT Development
        EXPORT cliqsExport
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}")

    install(
        EXPORT cliqsExport
        FILE cliqs.cmake
        NAMESPACE cliqs::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cliqs)
    
    install(FILES ${cliqs_BINARY_DIR}/cliqsConfig.cmake
            DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/cliqs)

    install(
        FILES ${CLIQS_PUBLIC_HDRS}
        COMPONENT Development
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

    install(
        FILES LICENSE
        COMPONENT Docs
        DESTINATION "${CMAKE_INSTALL_DOCDIR}/cliqs")

endif(CLIQS_INSTALL)

# ============================================================================
# Tests
# ============================================================================
# if(CLIQS_BUILD_TESTING)
#     enable_testing()
#     add_subdirectory(test)
# endif(CLIQS_BUILD_TESTING)

# ============================================================================
# Sample
# ============================================================================
if(CLIQS_BUILD_SAMPLES)
    add_subdirectory(sample)
endif(CLIQS_BUILD_SAMPLES)