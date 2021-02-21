AC_ADD_SCRIPT("${CMAKE_CURRENT_LIST_DIR}/src/DesertionWarnings.cpp")
AC_ADD_SCRIPT_LOADER("DesertionWarnings" "${CMAKE_CURRENT_LIST_DIR}/src/loader.h")

AC_ADD_CONFIG_FILE("${CMAKE_CURRENT_LIST_DIR}/conf/desertion-warnings.conf.dist")