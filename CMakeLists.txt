project(Coblock)
cmake_minimum_required(VERSION 2.0)

set(BONES_SRC_FILES ${BONES_SRC_FILES}
    "${PROJECT_SOURCE_DIR}/src/Bones/Game.cpp"
    "${PROJECT_SOURCE_DIR}/src/Bones/Signal.cpp"
    "${PROJECT_SOURCE_DIR}/src/Bones/ResourceManager.cpp"
    "${PROJECT_SOURCE_DIR}/src/Bones/Entity.cpp"
    "${PROJECT_SOURCE_DIR}/src/Bones/SpriteEntity.cpp"
    "${PROJECT_SOURCE_DIR}/src/Bones/Vector2.cpp"

    "${PROJECT_SOURCE_DIR}/include/Bones/Game.h"
    "${PROJECT_SOURCE_DIR}/include/Bones/Signal.h"
    "${PROJECT_SOURCE_DIR}/include/Bones/ResourceManager.h"
    "${PROJECT_SOURCE_DIR}/include/Bones/Entity.h"
    "${PROJECT_SOURCE_DIR}/include/Bones/SpriteEntity.h"
    "${PROJECT_SOURCE_DIR}/include/Bones/Vector2.h"
)

SOURCE_GROUP(Bones FILES ${BONES_SRC_FILES})

set(SRC_FILES ${SRC_FILES}
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/Coblock.cpp"
    #"${PROJECT_SOURCE_DIR}/src/Bones/Block.cpp"

    "${PROJECT_SOURCE_DIR}/include/Coblock.h"
    #"${PROJECT_SOURCE_DIR}/include/Bones/Block.h"

    ${BONES_SRC_FILES}
)
set(INCLUDE ${INCLUDE} "${PROJECT_SOURCE_DIR}/include")

# Modules
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules")

# Boost
set(BOOST_COMPONENTS ${BOOST_COMPONENTS}
    signals
)
find_package(Boost REQUIRED COMPONENTS ${BOOST_COMPONENTS})
set(LIBS ${LIBS} ${Boost_LIBRARIES})
include_directories(${Boost_INCLUDE_DIRS})

# SFML
find_package(SFML REQUIRED COMPONENTS System Graphics)
set(LIBS ${LIBS} ${SFML_LIBRARY})
set(INCLUDE ${INCLUDE} ${SFML_INCLUDE_DIR})

# SndFile
find_package(SndFile REQUIRED)
set(LIBS ${LIBS} ${SNDFILE_LIBRARY})
set(INCLUDE ${INCLUDE} ${INCLUDE_DIRECTORIES})

# Chipmunk
find_package(Chipmunk REQUIRED)
set(LIBS ${LIBS} ${CHIPMUNK_LIBRARY})
set(INCLUDE ${INCLUDE} ${CHIPMUNK_INCLUDE_DIR}) 

include_directories(${INCLUDE})

if(APPLE)
    set(TARGETS ${TARGETS} MACOSX_BUNDLE)
endif(APPLE)

add_executable(Coblock 
    ${TARGETS}
    ${SRC_FILES}
)

target_link_libraries(Coblock ${LIBS})
