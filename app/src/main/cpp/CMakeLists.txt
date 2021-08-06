cmake_minimum_required(VERSION 3.10.2) # Defining the minimum version reqrd for CMAKe

project("aug5")  # NAme of the project
add_library( # Sets the name of the library. and assigns the "main" c++ file to goto
        aug5

        # Sets the library as a shared library.
        SHARED  # The other option is STATIC; which makes it private

        # Provides a relative path to your source file(s).
        native-lib.cpp)     # The Main C++ file
add_library(Nfiq2Api SHARED IMPORTED)       # ADding the library with a pseudoname as Nfiq2Api with SHARED and IMPORTED properties
set_target_properties(Nfiq2Api PROPERTIES IMPORTED_LOCATION     #Assigning the path to the Nfiq2Api with SHARED and IMPORTED props
        "/home/cid/AndroidStudioProjects/aug5/app/src/main/jniLibs/arm64-v8a/libNfiq2Api.so") # The .so file is compiled for ARM and

find_library( # Sets the name of the path variable.
        #        log-lib
        #        aug5
        Nfiq2Api    #Making sure the Nfiq2Api path is valid
        FRFXLL      # Making sure the FRFXLL path is valid
        )

target_link_libraries( # Specifies the target library.
        aug5        # linking aug5 with the log lib
        Nfiq2Api    # linking Nfiq2Api with log lib
        # Linkss the target library to the log library
        # included in the NDK.
        ${log-lib})

#message(${PROJECT_SOURCE_DIR})
#add_library(Nfiq2Api SHARED IMPORTED)
#set_property(TARGET Nfiq2Api
#        PROPERTY IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../jniLibs/arm64-v8a/libNfiq2Api.so")
#find_library( # Sets the name of the path variable.
##        log-lib
##        aug5
#        Nfiq2Api
#        FRFXLL
#        )
#
#target_link_libraries( # Specifies the target library.
#        aug5
#        Nfiq2Api
#        # Linkss the target library to the log library
#        # included in the NDK.
#        ${log-lib})
