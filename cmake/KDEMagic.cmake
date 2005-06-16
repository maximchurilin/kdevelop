OPTION(KDE_ENABLE_FINAL "Enable final all-in-one compilation")

MACRO(KDE_ADD_KPART _target_NAME )
   FOREACH (_current_FILE ${ARGN})
#      MESSAGE(STATUS "next: ${_current_FILE}")

	  GET_FILENAME_COMPONENT(_ext ${_current_FILE} EXT)

      IF(${_ext} STREQUAL ".ui")
#         MESSAGE(STATUS "adding ui: ${_current_FILE}")
         SET(_magic_UIS ${_magic_UIS} ${_current_FILE})
      ENDIF(${_ext} STREQUAL ".ui")

      IF(${_ext} STREQUAL ".c" OR ${_ext} STREQUAL ".C" OR ${_ext} STREQUAL ".cpp" OR ${_ext} STREQUAL ".cxx" )
#            MESSAGE(STATUS "adding src: ${_current_FILE}")
            SET(_magic_SRCS ${_magic_SRCS} ${_current_FILE})
      ENDIF(${_ext} STREQUAL ".c" OR ${_ext} STREQUAL ".C" OR ${_ext} STREQUAL ".cpp" OR ${_ext} STREQUAL ".cxx" )

   ENDFOREACH (_current_FILE)

   IF(_magic_UIS)
      KDE_ADD_UI_FILES(_magic_SRCS ${_magic_UIS} )
   ENDIF(_magic_UIS)

#   MESSAGE(STATUS "srcs: ${_magic_SRCS}")

   KDE_AUTOMOC(${_magic_SRCS})

   IF (KDE_ENABLE_FINAL)
      FILE(WRITE ${_target_NAME}_final.cpp "//autogenerated file\n")
      FOREACH (_current_FILE ${_magic_SRCS})
         FILE(APPEND ${_target_NAME}_final.cpp "#include \"${_current_FILE}\"\n")
      ENDFOREACH (_current_FILE)
      ADD_LIBRARY(${_target_NAME} MODULE  ${_target_NAME}_final.cpp)
   ELSE (KDE_ENABLE_FINAL)
      ADD_LIBRARY(${_target_NAME} MODULE ${_magic_SRCS} )
   ENDIF (KDE_ENABLE_FINAL)

   KDE_CREATE_LIBTOOL_FILE(${_target_NAME})

ENDMACRO(KDE_ADD_KPART _target_NAME)
