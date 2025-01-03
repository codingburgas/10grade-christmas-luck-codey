# Specify the subproject
project(codeyapp)

# Set paths for includes
include_directories(${CMAKE_SOURCE_DIR}/codeyapp)

set(SQLAPI_LIB_DIR /Users/ani/Documents/School/sqlapi/lib)  # Update with the correct path
set(SQLAPI_INCLUDE_DIR /Users/ani/Documents/School/sqlapi/include)
set(CMAKE_AUTOUIC_SEARCH_PATHS presentationLayer)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

include_directories(
        ${SQLAPI_INCLUDE_DIR}
        dataAccessLayer
        presentationLayer
)

link_directories(${SQLAPI_LIB_DIR})
link_directories(/opt/homebrew/opt/mysql/lib)


# Add source files


# Add the executable
add_executable(codeyapp
        dataAccessLayer/dbConnection.cpp
        dataAccessLayer/dbConnection.h
        presentationLayer/authwindow.cpp
        presentationLayer/authwindow.h
        presentationLayer/dashboard.cpp
        presentationLayer/dashboard.h
        presentationLayer/mainwindow.cpp
        presentationLayer/mainwindow.h
        presentationLayer/mybooks.cpp
        presentationLayer/mybooks.h
        presentationLayer/readbook.cpp
        presentationLayer/readbook.h
        presentationLayer/rent.cpp
        presentationLayer/rent.h
        presentationLayer/writebook.cpp
        presentationLayer/writeBook.h
        main.cpp)


qt6_wrap_ui(UI_HEADERS
        presentationLayer/authwindow.ui
        presentationLayer/dashboard.ui
        presentationLayer/mainwindow.ui
        presentationLayer/readbook.ui
        presentationLayer/writebook.ui
        presentationLayer/mybooks.ui
        presentationLayer/rent.ui
)
target_sources(codeyapp PRIVATE ${UI_HEADERS})

target_link_libraries(codeyapp
        SqlAPI  # Replace with the actual library name if different
        mysqlclient  # MySQL library
        Qt6::Widgets  # Qt Widgets module
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
