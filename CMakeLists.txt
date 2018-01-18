cmake_minimum_required(VERSION 3.8)
project(QHexEdit)

set(INCLUDE_FILES
        document/commands/hexcommand.h
        document/commands/insertcommand.h
        document/commands/removecommand.h
        document/commands/replacecommand.h
        document/gapbuffer.h
)

set(SOURCE_FILES
        document/commands/hexcommand.cpp
        document/commands/insertcommand.cpp
        document/commands/removecommand.cpp
        document/commands/replacecommand.cpp
        document/gapbuffer.cpp
        document/qhexcursor.cpp
        document/qhexdocument.cpp
        document/qhextheme.cpp
        paint/qhexmetrics.cpp
        paint/qhexpainter.cpp
        qhexedit.cpp
        qhexeditprivate.cpp
        document/metadata/qhexmetadataitem.cpp
        document/metadata/qhexmetadata.cpp
)

set(QOBJECT_HEADERS
        qhexedit.h
        qhexeditprivate.h
        document/qhexcursor.h
        document/qhexdocument.h
        document/qhextheme.h
        paint/qhexmetrics.h
        paint/qhexpainter.h
        document/metadata/qhexmetadataitem.h
        document/metadata/qhexmetadata.h
)

set(UI_FILES
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package( Qt5Core REQUIRED )
find_package( Qt5Widgets REQUIRED )
find_package( Qt5Gui REQUIRED )

qt5_add_resources(RESOURCE_ADDED ${QT_RESOURCES})

qt5_wrap_cpp(UI_SOURCE
        ${QOBJECT_HEADERS}
        )

qt5_wrap_ui(
        UI_HDRS
        ${UI_FILES}
)

add_library(QHexEdit STATIC
        ${UI_HDRS}
        ${UI_SOURCE}
        ${MAIN_FILE}
        ${SOURCE_FILES}
        ${INCLUDE_FILES}
        ${UNMANAGED_FILES}
        ${RESOURCE_ADDED}
        ${QOBJECT_HEADERS}
)

qt5_use_modules(QHexEdit Core Widgets Gui)

target_include_directories(QHexEdit PUBLIC .)