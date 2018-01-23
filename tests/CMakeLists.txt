
if (EXISTS "${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt")
    add_subdirectory(googletest)
endif()

set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package( Qt5Core REQUIRED )

add_executable(QHexEditTests
    main.cpp
    GapBuffer.cpp
)

target_link_libraries(QHexEditTests
    gtest
    QHexEdit
)

qt5_use_modules(QHexEditTests Core)