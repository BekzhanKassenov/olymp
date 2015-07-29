#include "Client/SolutionAdapter.h"
#include "jni.h"
#include <cstdlib>
#include <cstring>
#include <iostream>

#ifndef CLASSNAME
#define CLASSNAME Solution
#endif

#define QUOTE(x) #x
#define TOSTR(x) QUOTE(x)

using namespace std;

jclass Adapter_class;
jmethodID Adapter_strategy_MID;
jmethodID Adapter_program_MID;
jmethodID Adapter_init_MID;

bool inited = false;
JNIEnv *env;
JavaVM *jvm;

void initJVM() {
    JavaVMInitArgs args;
    memset (&args, 0, sizeof(args));
    args.version = JNI_VERSION_1_2;
    int code = JNI_GetDefaultJavaVMInitArgs(&args);
    if (code) {
        logprintf("JNI_GetDefaultJavaVMInitArgs failed with return value %d\n", code);
        exit(1);
    }

    code = JNI_CreateJavaVM(&jvm, (void **)&env, &args);
    if (code) {
        logprintf("JNI_CreateJavaVM failed with return value %d\n", code);
        exit(1);
    }
}


static void init() {
    inited = true;
    initJVM();

    Adapter_class = env->FindClass("Adapter");
    if(Adapter_class == NULL) {
        logprintf("Failed to find Adapter class\n");
        exit(1);
    }

    Adapter_strategy_MID = env->GetStaticMethodID(Adapter_class, "strategy", "()[I");
    if(Adapter_strategy_MID == NULL) {
        logprintf("Failed to find Adapter.strategy method\n");
        exit(1);
    }

    Adapter_program_MID = env->GetStaticMethodID(Adapter_class, "program", "(I)[Ljava/lang/String;");
    if(Adapter_program_MID == NULL) {
        logprintf("Failed to find Adapter.program method\n");
        exit(1);
    }

    Adapter_init_MID = env->GetStaticMethodID(Adapter_class, "init", "(Ljava/lang/String;II)V");
    if(Adapter_init_MID == NULL) {
        logprintf("Failed to find Adapter.init method\n");
        exit(1);
    }

    logprintf("Using class \"%s\"\n", TOSTR(CLASSNAME)".class");
    jobject solutionClassFileName = env->NewStringUTF(TOSTR(CLASSNAME)".class");
    if(solutionClassFileName == NULL) {
        logprintf("Failed to construct solution class file name\n");
        exit(1);
    }

    env->CallStaticVoidMethod(Adapter_class, Adapter_init_MID, solutionClassFileName, (jint) pWorld, (jint) playerIndex);
    if(env->ExceptionCheck()) {
        logprintf("Adapter.init is finished with exception\n");
        exit(1);
    }
}


std::map<int, int> Strategy() {
    if(!inited) init();

    //TODO:
    jintArray res = (jintArray)env->CallStaticObjectMethod(Adapter_class, Adapter_strategy_MID);
    if(env->ExceptionCheck()) {
        logprintf("Adapter.strategy is finished with exception\n");
        exit(1);
    }

    jsize len = env->GetArrayLength(res);

    int * arr = (int*)env->GetIntArrayElements(res, NULL);
    if(arr == NULL) {
        logprintf("GetIntArrayElements is failed\n");
        exit(1);
    }

    map<int, int> m;
    for(int i = 0; i < len; i += 2) {
//        logprintf("%d -> %d\n", arr[i], arr[i+1]);
        m[arr[i]] = arr[i+1];
    }

    env->ReleaseIntArrayElements(res, (jint*)arr, JNI_ABORT);
    env->DeleteLocalRef(res);

    return m;
}

string jstring2string(jstring jstr) {
    const char * s = env->GetStringUTFChars(jstr, NULL);
    if(s == NULL) {
        logprintf("GetStringUTFChars is failed\n");
        exit(1);
    }
    int len = env->GetStringUTFLength(jstr);
    string res(s, s + len);
    env->ReleaseStringUTFChars(jstr, s);
    return res;
}

std::pair<std::string, std::string> Program(int robotIndex) {
    if(!inited) init();

    jobjectArray res = (jobjectArray)env->CallStaticObjectMethod(Adapter_class, Adapter_program_MID, robotIndex);
    if(env->ExceptionCheck()) {
        logprintf("Adapter.program is finished with exception\n");
        exit(1);
    }

    jobject str1 = env->GetObjectArrayElement(res, 0);
    if(env->ExceptionCheck()) {
        logprintf("GetObjectArrayElemet is failed\n");
        exit(1);
    }
    jobject str2 = env->GetObjectArrayElement(res, 1);
    if(env->ExceptionCheck()) {
        logprintf("GetObjectArrayElemet is failed\n");
        exit(1);
    }

    string s1 = jstring2string((jstring)str1);
    string s2 = jstring2string((jstring)str2);

    env->DeleteLocalRef(str1);
    env->DeleteLocalRef(str2);
    env->DeleteLocalRef(res);

    return pair<string,string>(s1, s2);
}

void destroyJVM () {
    jvm->DestroyJavaVM();
}

