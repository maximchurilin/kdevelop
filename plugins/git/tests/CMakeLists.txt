# Running the test only makes sense if the git command line client
# is present. So check for it before adding the test...
find_program(GIT_FOUND NAMES git)

if (GIT_FOUND)
    include_directories(
        ..
        ${CMAKE_CURRENT_BINARY_DIR}/..
    )

    remove_definitions(
        -DQT_NO_CAST_FROM_ASCII
        -DQT_NO_CAST_TO_ASCII
        -DQT_NO_CAST_FROM_BYTEARRAY
    )

    set(gittest_SRCS
        test_git.cpp
        ../gitplugin.cpp
        ../gitclonejob.cpp
        ../stashmanagerdialog.cpp
        ../stashpatchsource.cpp
        ../rebasedialog.cpp
        ../gitjob.cpp
        ../gitmessagehighlighter.cpp
        ../gitplugincheckinrepositoryjob.cpp
        ../gitnameemaildialog.cpp
        ${kdevgit_LOG_PART_SRCS}
    )
    ki18n_wrap_ui(gittest_SRCS ../stashmanagerdialog.ui)
    ki18n_wrap_ui(gittest_SRCS ../gitnameemaildialog.ui)
    ki18n_wrap_ui(gittest_SRCS ../rebasedialog.ui)
    ecm_add_test(${gittest_SRCS}
        TEST_NAME test_kdevgit
        LINK_LIBRARIES Qt5::Test KDev::Vcs KDev::Util KDev::Tests
        GUI)
endif ()
