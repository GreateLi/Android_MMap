#include <jni.h>
#include <string>
#include <sstream>
#include <exception>
#include<iostream>
using namespace std;


inline ostream &_concat(ostream &os){
    return os;
};
template <typename T1, typename... TT>
inline ostream &_concat(ostream &os,const T1 &t1, TT && ... tt){
    os<<t1;
    return _concat(os,tt...);
};
extern "C" JNIEXPORT jstring JNICALL
Java_cn_com_jni_myapplication_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject obj/* this */) {
    std::string hello = "Hello from C++";


    return env->NewStringUTF(hello.c_str());
}
#include <jni.h>
#include <string>
#include "mmap_util.h"

extern "C"
JNIEXPORT void JNICALL
Java_cn_com_jni_myapplication_MainActivity_mmapWrite(JNIEnv *env, jclass type, jstring data_, jstring path_,
                                                     jstring fileName_) {
    const char *data = env->GetStringUTFChars(data_, 0);
    const char *path = env->GetStringUTFChars(path_, 0);
    const char *fileName = env->GetStringUTFChars(fileName_, 0);
    mmap_write(data,env->GetStringUTFLength(data_),path,fileName);//这里有个陷进，如果使用GetStringLength的话可能会因为编码问题导致数据丢失
    env->ReleaseStringUTFChars(data_, data);
    env->ReleaseStringUTFChars(path_, path);
    env->ReleaseStringUTFChars(fileName_, fileName);
}

extern "C"
JNIEXPORT void JNICALL
Java_cn_com_jni_myapplication_MainActivity_mmapWriteByte(JNIEnv *env, jclass type, jbyteArray data_,
                                                         jstring path_, jstring fileName_) {
    jbyte *data = env->GetByteArrayElements(data_, NULL);
    const char *path = env->GetStringUTFChars(path_, 0);
    const char *fileName = env->GetStringUTFChars(fileName_, 0);

    mmap_write(data,env->GetArrayLength(data_),path,fileName);

    env->ReleaseByteArrayElements(data_, data, 0);
    env->ReleaseStringUTFChars(path_, path);
    env->ReleaseStringUTFChars(fileName_, fileName);
}

