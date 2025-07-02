cmake_minimum_required(VERSION 3.16)

project(Tours VERSION 0.1 LANGUAGES CXX)

# Habilitar generación automática para MOC, UIC y RCC
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Establecer tipo de compilación predeterminado si no se especifica
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build." FORCE)
endif()

# Buscar paquetes de Qt (soporta Qt5 y Qt6)
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
    )
else()
    # Qt5 o anterior
    if(ANDROID)
        add_library(Tours SHARED ${PROJECT_SOURCES})
    else()
        add_executable(Tours ${PROJECT_SOURCES})
    endif()
endif()

# Enlazar con Qt Widgets
target_link_libraries(Tours PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
