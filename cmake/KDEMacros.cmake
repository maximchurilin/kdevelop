#neundorf@kde.org

#this should better be part of cmake:
#add an additional file to the list of files a source file depends on
MACRO(ADD_FILE_DEPENDANCY file)
   SET(${file}_deps ${${file}_deps} ${ARGN})
   SET_SOURCE_FILES_PROPERTIES(
      ${file}
      PROPERTIES
      OBJECT_DEPENDS
      "${${file}_deps}"
   )
ENDMACRO(ADD_FILE_DEPENDANCY)


#create the kidl and skeletion file for dcop stuff
#usage: KDE_ADD_COP_SKELS(foo_SRCS ${dcop_headers})
MACRO(KDE_ADD_DCOP_SKELS _sources)
   FOREACH (_current_FILE ${ARGN})
      GET_FILENAME_COMPONENT(_basename ${_current_FILE} NAME_WE)
      
	  SET(_skel ${CMAKE_CURRENT_BINARY_DIR}/${_basename}_skel.cpp)
      SET(_kidl ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.kidl)

	  ADD_CUSTOM_COMMAND(OUTPUT ${_kidl}
         COMMAND ${DCOPIDL}
         ARGS ${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE} > ${_kidl}
         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE}
      )                
      
	  ADD_CUSTOM_COMMAND(OUTPUT ${_skel}
         COMMAND ${DCOPIDL2CPP}
         ARGS --c++-suffix cpp --no-signals --no-stub ${_kidl} 
         DEPENDS ${_kidl}
      )                

      SET(${_sources} ${${_sources}} ${_skel})
   
   ENDFOREACH (_current_FILE)

ENDMACRO(KDE_ADD_DCOP_SKELS)

#create the moc files and add them to the list of sources
#usage: KDE_ADD_MOC_FILES(foo_SRCS ${moc_headers})
MACRO(KDE_ADD_MOC_FILES _sources)
   FOREACH (_current_FILE ${ARGN})
	  GET_FILENAME_COMPONENT(_basename ${_current_FILE} NAME_WE)
      GET_FILENAME_COMPONENT(_path ${_current_FILE} PATH)
      SET(_moc ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.moc.cpp)

      ADD_CUSTOM_COMMAND(OUTPUT ${_moc}
         COMMAND moc
         ARGS ${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE} -o ${_moc}
         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE}
      )                

      SET(${_sources} ${${_sources}} ${_moc})
   
   ENDFOREACH (_current_FILE)
ENDMACRO(KDE_ADD_MOC_FILES)

#create the moc files aka automoc from automake
#usage: KDE_CREATE_AUTOMOC_FILES(${foo_automoc_SRCS})
MACRO(KDE_CREATE_AUTOMOC_FILES )
   FOREACH (_current_FILE ${ARGN})
      GET_FILENAME_COMPONENT(_basename ${_current_FILE} NAME_WE)
      GET_FILENAME_COMPONENT(_ext ${_current_FILE} EXT)
      SET(_moc ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.moc)
      SET(_header ${CMAKE_CURRENT_SOURCE_DIR}/${_basename}.h)

      ADD_CUSTOM_COMMAND(OUTPUT ${_moc}
         COMMAND moc
         ARGS ${_header} -o ${_moc}
         DEPENDS ${_header}
      )                

      ADD_FILE_DEPENDANCY(${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE} ${_moc})
  
   ENDFOREACH (_current_FILE)
ENDMACRO(KDE_CREATE_AUTOMOC_FILES)

#create the implementation files from the ui files and add them to the list of sources
#usage: KDE_ADD_UI_FILES(foo_SRCS ${ui_files})
MACRO(KDE_ADD_UI_FILES _sources )
   FOREACH (_current_FILE ${ARGN})
      
	  GET_FILENAME_COMPONENT(_basename ${_current_FILE} NAME_WE)
      SET(_header ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.h)
      SET(_src ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.cpp)
	  SET(_moc ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.moc.cpp)
	  
      ADD_CUSTOM_COMMAND(OUTPUT ${_header}
         COMMAND uic
         ARGS  -o ${_header} ${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE}
         DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE}
      )                
      
	  ADD_CUSTOM_COMMAND(OUTPUT ${_src}
         COMMAND uic
         ARGS -o ${_src} -impl ${_header} ${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE} 
         DEPENDS ${_header}
      )                
      
      ADD_CUSTOM_COMMAND(OUTPUT ${_moc}
         COMMAND moc
         ARGS ${_header} -o ${_moc}
         DEPENDS ${_header}
      )                

      SET(${_sources} ${${_sources}} ${_src} ${_moc} )
      
   ENDFOREACH (_current_FILE)
ENDMACRO(KDE_ADD_UI_FILES)

MACRO(KDE_AUTOMOC)
   SET(_matching_FILES )
   FOREACH (_current_FILE ${ARGN})
      IF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE})
         GET_FILENAME_COMPONENT(_basename ${_current_FILE} NAME_WE)
         SET(_moc ${_basename}.moc)
      
         FILE(READ ${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE} _contents)
      
         STRING(REGEX MATCH "#include.+${_moc}" _match "${_contents}")

         IF(_match)

            SET(_moc_FILE ${CMAKE_CURRENT_BINARY_DIR}/${_basename}.moc)
            SET(_header ${CMAKE_CURRENT_SOURCE_DIR}/${_basename}.h)

            ADD_CUSTOM_COMMAND(OUTPUT ${_moc_FILE}
               COMMAND moc
               ARGS ${_header} -o ${_moc_FILE}
              DEPENDS ${_header}
            )                

            ADD_FILE_DEPENDANCY(${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE} ${_moc_FILE})


#            MESSAGE(STATUS "matches: "${_current_FILE})
#            SET(_matching_FILES ${_matching_FILES}  ${_current_FILE})
#            KDE_CREATE_AUTOMOC_FILES(${_current_FILE})      
         ENDIF(_match)
      ENDIF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${_current_FILE})
   ENDFOREACH (_current_FILE)
#   MESSAGE(STATUS "files: "${_matching_FILES})   
#   KDE_CREATE_AUTOMOC_FILES(${_matching_FILES})
ENDMACRO(KDE_AUTOMOC)

