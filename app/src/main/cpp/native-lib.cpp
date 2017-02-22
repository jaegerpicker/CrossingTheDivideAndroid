#include <jni.h>
#include <string>
#include "../../../../../CrossingTheDivideLib/CrossingTheDivideLib/CrossingTheDivideLib.hpp"

extern "C"
jstring
Java_com_codeartgames_crossingthedivide_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
jstring
Java_com_codeartgames_crossingthedivide_MainActivity_stringFromJniLib(
        JNIEnv* env,
        jobject) {
    std::string hello = "Meetup";
    CrossingTheDivideLib* crossingTheDivideLib = new CrossingTheDivideLib();
    return env->NewStringUTF(crossingTheDivideLib->HelloWorld(hello).c_str());
}

extern "C"
jintArray
Java_com_codeartgames_crossingthedivide_MainActivity_sortArray(
        JNIEnv* env,
        jobject,
        jintArray unsorted,
        jint size) {
    jintArray res;
    res = (*env).NewIntArray(size);
    if(res == NULL) {
        return NULL;
    }
    CrossingTheDivideLib* lib = new CrossingTheDivideLib();
    jint buf[size];
    (*env).GetIntArrayRegion(unsorted, 0, size, buf);
    lib->quickSort(buf, 0, size);
    (*env).SetIntArrayRegion(res, 0, size, buf);
    return res;
}

