cmake_minimum_required(VERSION 3.30)
project(codeyapp)

set(CMAKE_CXX_STANDARD 14)


# Set the SqlAPI++ library path
set(SQLAPI_LIB_DIR /Users/ani/Documents/School/sqlapi/lib)  # Update with the correct path
set(SQLAPI_INCLUDE_DIR /Users/ani/Documents/School/sqlapi/include)  # Update with the correct path

# Find the Qt installation and required components
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Include directories for SqlAPI++ and project headers
include_directories(
    ${SQLAPI_INCLUDE_DIR}
    dataAccessLayer
    presentationLayer
)

# Link directories for SqlAPI++
link_directories(${SQLAPI_LIB_DIR})
link_directories(/opt/homebrew/opt/mysql/lib)


set(UI_FILES
        presentationLayer/authwindow.ui
        presentationLayer/dashboard.ui
        presentationLayer/mainwindow.ui
        presentationLayer/readbook.ui
        presentationLayer/writebook.ui
)



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
    presentationLayer/readbook.cpp
    presentationLayer/readbook.h
    presentationLayer/writebook.cpp
    presentationLayer/writeBook.h
    main.cpp
)
qt6_wrap_ui(UI_HEADERS ${UI_FILES})
target_sources(codeyapp PRIVATE ${UI_HEADERS})
# Link SqlAPI++, MySQL, and Qt libraries
target_link_libraries(codeyapp
    SqlAPI  # Replace with the actual library name if different
    mysqlclient  # MySQL library
    Qt6::Widgets  # Qt Widgets module
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Enable automatic MOC, UIC, and RCC processing for Qt
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Add resources if you have a .qrc file (e.g., images.qrc)
# Uncomment and update if you have resources
# qt6_add_resources(RESOURCES assets/images.qrc)
