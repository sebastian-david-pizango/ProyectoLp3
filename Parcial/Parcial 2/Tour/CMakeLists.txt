cmake_minimum_required(VERSION 3.16)

project(Tours VERSION 0.1 LANGUAGES CXX)

# Habilitar generación automática para MOC, UIC y RCC
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Buscar paquetes de Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# Lista de archivos fuente y encabezados
set(PROJECT_SOURCES
    main.cpp

    mainwindow.cpp
    mainwindow.h
    mainwindow.ui

    registerwindow.cpp
    registerwindow.h
    registerwindow.ui

    graph.cpp
    graph.h
)

# Si es Qt6, usar qt_add_executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Tours
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
<<<<<<< HEAD
        registerwindow.h registerwindow.cpp registerwindow.ui
        graph.h graph.cpp graph.ui
=======
>>>>>>> 43a9f85fd96ba7ac00c22c1bd6dcaa908bbfc71d
    )
else()
    # Qt5
    if(ANDROID)
        add_library(Tours SHARED ${PROJECT_SOURCES})
    else()
        add_executable(Tours ${PROJECT_SOURCES})
    endif()
endif()

# Enlazar con Qt Widgets
target_link_libraries(Tours PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Opcional: configuraciones para iOS/macOS
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.Tours)
endif()

set_target_properties(Tours PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Instalación
include(GNUInstallDirs)
install(TARGETS Tours
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Qt6: finalizar configuración del ejecutable
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Tours)
endif()

