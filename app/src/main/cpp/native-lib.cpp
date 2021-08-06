#include <jni.h>
#include <string>
#include <nfiq2.hpp>

//#include<nfiq2api.h>
#include<nfiq2_version.hpp>  //This header file contains an version variable NFIQ2::Version::OpenCV  -> GEts a string as an output telling the version of OpenCV
#include <dlfcn.h>  // Library to load the .so file so that we can use the functions from it
extern "C" JNIEXPORT jstring JNICALL    // C++ and JAVA wrapper
Java_com_example_aug5_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";       // Test string
//    std::string value = NFIQ2::Version::OpenCV;       This didn't work

//============================= Importing Nfiq2Lib.so ========================================
    void *handle;   // Pointer to store the so file's addresses
    char *error;   // Character array to have any error messages displayed
    // Loading the file libNfiq2Api.so into the handle variable
    handle=dlopen("/home/cid/AndroidStudioProjects/aug5/app/src/main/jniLibs/arm64-v8a/libNfiq2Api.so",RTLD_LAZY);
    if(!handle){    // If handle is Null; throw an error
        std::string hello = "TEst";
        return env->NewStringUTF(hello.c_str());
    }
    dlerror();  // Check for any errors reading through the libNfiq2Api.so file and report them
    int *iptr;  // Int pointer to store the inside function from libNfiq2Api file
    iptr=(int *)dlsym(handle,"NFIQ2::Version::OpenCV"); // The dlsym function searches for the 2md arg inside the libNfiq2Api and returns the pointer to that argument
    std::string result; // The NFIQ2::VErsion::OpenCV returns a string. Result will hold the value of the string
    result = std::to_string(*iptr);   // Assigning value of the pointer into the result var
    return env->NewStringUTF(result.c_str());   // Returning the result string after coverting to a char array
}