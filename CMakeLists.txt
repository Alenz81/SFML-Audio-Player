cmake_minimum_required(VERSION 3.23)
project(SFML_Audio_Player)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp FileItem.cpp FileItem.h FileNode.cpp FileNode.h FileTree.cpp FileTree.h Box.h Box.cpp Item.cpp Item.h Engine.cpp Engine.h StatesEnum.h States.h States.cpp HistoryNode.h History.h History.cpp GUIComponent.cpp GUIComponent.h SnapshotInterface.h Snapshot.cpp Snapshot.h Application.cpp Application.h MenuBar.h MenuBar.cpp DropDownBox.h DropDownBox.cpp DropDown.cpp DropDown.h IMGDropDown.cpp IMGDropDown.h SoundBar.cpp SoundBar.h SongAndManipulations.cpp SongAndManipulations.h Button.cpp Button.h TimeBar.cpp TimeBar.h Cursor.h Cursor.cpp Letter.h Letter.cpp TextBox.h TextBox.cpp Typing.cpp Typing.h MultiText.h MultiText.cpp FontHelper.cpp FontHelper.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(SFML_Audio_Player WIN32 ${SOURCE_FILES})
else ()
    add_executable(SFML_Audio_Player ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/SFML-2.6.0-windows-gcc-13.1.0-mingw-32-bit/SFML-2.6.0)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH C:/Users/super/CLionProjects/cmake_modules)
set(SFML_DIR C:/SFML/SFML-2.6.0/lib/cmake/SFML)
find_package(SFML REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(SFML_Audio_Player ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()

# cmake_minimum_required(VERSION 3.23)
# project (SFML_Audio_Player)

# set(CMAKE_CXX_STANDARD 14)

# add_executable(SFML_Audio_Player main.cpp)