cmake_minimum_required(VERSION 3.19)
project(Software_Application)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "C:\\Users\\User\\Desktop\\Setup\\mingw32\\i686-w64-mingw32\\lib\\cmake")
set(QT_VERSION 5)
set(REQUIRED_LIBS Core Gui Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets)


include_directories(.)
add_executable(Software_Application main.cpp Entities/User.cpp Entities/User.h Entities/Issue.h Entities/Issue.cpp Repositories/Repository_User.cpp
        Repositories/Repository_User.h Observer.h Repositories/Repository_Issue.cpp Repositories/Repository_Issue.h QT/User_Window.cpp QT/User_Window.h
        QT/Table_Model.cpp QT/Table_Model.h)


if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})