#########################################################################
#
#  CMAKE
#
#########################################################################

###
#  Minimum Version
#  ---------------
#  The CMake version required.
###
cmake_minimum_required(VERSION 3.1)

###
#  CMake Configuration
#  -------------------
#  Configuration settings for CMake.
#
#  NOTE:
#  These settings have to be applied before the project() setting!
###
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_C_STANDARD 99)

###
#  Project Info
#  ------------
#  General simple information about our project.
###
project(libmrhevdata VERSION 1.0.0
                     DESCRIPTION "MRH Platform event data library"
                     LANGUAGES C)
set(LIB_SO_VERSION 1)

#########################################################################
#
#  PATHS
#
#########################################################################

###
#  Install Paths
#  -------------
#  GNU system paths for installation.
###
include(GNUInstallDirs)

###
#  Build Paths
#  -----------
#  The paths for the cmake build.
###
set(BUILD_DIR_PATH "${CMAKE_SOURCE_DIR}/build/")
file(MAKE_DIRECTORY ${BUILD_DIR_PATH})

###
#  Source Paths
#  ------------
#  The paths to the source files to use.
###
set(SRC_DIR_PATH "${CMAKE_SOURCE_DIR}/src/")
set(INCLUDE_DIR_PATH "${CMAKE_SOURCE_DIR}/include/")

set(SRC_LIST_BASE "${SRC_DIR_PATH}/libmrhevdata/MRH_EvDataEvent.c"
                  "${SRC_DIR_PATH}/libmrhevdata/MRH_EvDataRevision.c"
                  "${SRC_DIR_PATH}/libmrhevdata.c"
                  "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/MRH_EvDataEvent.h"
                  "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/MRH_EvDataRevision.h"
                  "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata.h")
					
set(SRC_LIST_EVENT "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/Version/MRH_EvBase.h"
                   "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/MRH_EvSystem.h"
                   "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/MRH_EvCustom.h"
                   "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/MRH_EvListen.h"
                   "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/MRH_EvSay.h"
                   "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/MRH_EvPassword.h"
                   "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/MRH_EvUser.h"
                   "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/MRH_EvApplication.h"
                   "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/MRH_EvNotification.h")
                   
set(SRC_LIST_EVENT_V1 "${SRC_DIR_PATH}/libmrhevdata/Version/1/MRH_EvSystem_V1.c"
                      "${SRC_DIR_PATH}/libmrhevdata/Version/1/MRH_EvCustom_V1.c"
                      "${SRC_DIR_PATH}/libmrhevdata/Version/1/MRH_EvListen_V1.c"
                      "${SRC_DIR_PATH}/libmrhevdata/Version/1/MRH_EvSay_V1.c"
                      "${SRC_DIR_PATH}/libmrhevdata/Version/1/MRH_EvPassword_V1.c"
                      "${SRC_DIR_PATH}/libmrhevdata/Version/1/MRH_EvUser_V1.c"
                      "${SRC_DIR_PATH}/libmrhevdata/Version/1/MRH_EvApplication_V1.c"
                      "${SRC_DIR_PATH}/libmrhevdata/Version/1/MRH_EvNotification_V1.c"
                      "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/Version/1/MRH_EvSystem_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/Version/1/MRH_EvCustom_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/Version/1/MRH_EvListen_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/Version/1/MRH_EvSay_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/Version/1/MRH_EvPassword_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/Version/1/MRH_EvUser_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/Version/1/MRH_EvApplication_V1.h"
                      "${INCLUDE_DIR_PATH}/libmrhevdata/libmrhevdata/Version/1/MRH_EvNotification_V1.h")

###
#  Public API Path
#  ---------------
#  The path to the public api include folder.
###
set(PUBLIC_API_DIR_PATH "${INCLUDE_DIR_PATH}/libmrhevdata")
					 
#########################################################################
#
#  TARGET
#
#########################################################################

###
#  Target
#  ------
#  The target(s) to build.
###
add_library(libmrhevdata_Shared SHARED ${SRC_LIST_BASE}
                                       ${SRC_LIST_EVENT}
                                       ${SRC_LIST_EVENT_V1})
set_target_properties(libmrhevdata_Shared
                      PROPERTIES
                      PREFIX "lib"
                      OUTPUT_NAME "mrhevdata"
                      SUFFIX ".so"
                      VERSION ${PROJECT_VERSION}
                      SOVERSION ${LIB_SO_VERSION})

###
#  Install
#  -------
#  Library installation.
###
install(TARGETS libmrhevdata_Shared
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY "${PUBLIC_API_DIR_PATH}/"
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        FILES_MATCHING
        PATTERN "*.h")