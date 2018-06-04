//
// Created by humax on 18/6/4.
//
#include "com_liufeismart_jni_hellojni_HelloJNI.h"

JNIEXPORT jstring JNICALL Java_com_liufeismart_jni_hellojni_HelloJNI_helloJNI
        (JNIEnv* env, jclass instance)
{
    return (*env)->NewStringUTF(env,"HelloWorld 我是用jni调用出来的字符串");
}

/*
 * Class:     com_liufeismart_jni_hellojni_HelloJNI
 * Method:    add
 * Signature: (II)V
 */
JNIEXPORT jint JNICALL Java_com_liufeismart_jni_hellojni_HelloJNI_add
        (JNIEnv* env, jclass instance, jint a, jint b)
{
    return a+b;
}