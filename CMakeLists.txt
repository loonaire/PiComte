cmake_minimum_required(VERSION 3.5)

project(PiComte LANGUAGES CXX)

#set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_INCLUDE_CURRENT_DIR OFF)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/release)

# fichiers
set(TS_FILES resources/PiComte_en_US.ts)
set(RESSOURCES_FILES resources/resources.qrc)

set(EXECUTABLE_NAME PiComte)

#set(SRC_FILES
#  src/main.cpp
#  src/mainwindow.cpp
#)

#set(HEADER_FILES
#  src/mainwindow.h
#)

file(GLOB SRC_FILES src/*.cpp)

file(GLOB HEADER_FILES src/*.h)


#---------------------------------------------------------------------
# Custom target for make target debug, release, if qtcreator is not used
ADD_CUSTOM_TARGET(debug
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Creating the executable in the debug mode.")

ADD_CUSTOM_TARGET(release
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Release ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Creating the executable in the release mode.")

ADD_CUSTOM_TARGET(releasewithdebug
  COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=RelWithDebInfo ${CMAKE_SOURCE_DIR}
  COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --target all
  COMMENT "Creating the executable in the release with debug information mode.")






#compilation

if(ANDROID) #Android semble un cas a part...  
  message("-- CMake Target: ANDROID")
  add_library(PiComte SHARED
    ${SRC_FILES}
    ${HEADER_FILES}
    ${TS_FILES}
  )

else()
#Pas sur que tout soit fonctionnel mais a test 
  if(WIN32)
    #évite l'ouverture d'une console
    message("-- CMake Target: WIN32")
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU") # if compiler = GCC, add WIN32 
      set(OS_TARGET WIN32)
    endif()

  elseif(APPLE)
    # pour apple
    message("-- CMake Target: APPLE")
    set(OS_TARGET MACOSX_BUNDLE)

  else()
    #pour tout les autres OS
    set(OS_TARGET)
  endif()

    # config par defaut
    add_executable(${EXECUTABLE_NAME}
    ${OS_TARGET}
    ${SRC_FILES}
    ${HEADER_FILES}
    ${TS_FILES}
    ${RESSOURCES_FILES}


) 
endif()

target_link_libraries(PiComte PRIVATE Qt5::Widgets)
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})


