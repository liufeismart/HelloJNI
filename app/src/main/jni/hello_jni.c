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

/*
 * Class:     com_liufeismart_jni_hellojni_HelloJNI
 * Method:    setName
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 * C->Java: NewStringUTF
 * Java->C: GetStringUTFChars
 *
 */
JNIEXPORT jstring JNICALL Java_com_liufeismart_jni_hellojni_HelloJNI_setName
  (JNIEnv* env, jclass instance, jstring name ) {

  jstring javaString;
  const jbyte* str;
  jboolean isCopy;
  str = (*env)->GetStringUTFChars(env, name, &isCopy);
  if(0 != str) {
    printf("Java string: %s", str);
    if(JNI_TRUE == isCopy) {
        printf("C string is a copy of the Java string.");
    } else {
         printf("C string points to actual string");
    }
  }
  (*env)->ReleaseStringChars(env, name, str);


  const char *c_str = NULL;
  char buff[128] = {0};
  c_str = (*env)->GetStringUTFChars(env, name, &isCopy);

  if(c_str == NULL)
  {
     return NULL;
  }
  printf("C_str: %s \n", c_str);
  sprintf(buff, "my name is %s", c_str);
  (*env)->ReleaseStringUTFChars(env, name, c_str);
  return (*env)->NewStringUTF(env,buff);

}

JNIEXPORT jintArray JNICALL Java_com_liufeismart_jni_hellojni_HelloJNI_getArray
  (JNIEnv* env , jclass instance, jintArray jArray) {
    jintArray javaArray = (*env)->NewIntArray(env, 10);
    if(0!=javaArray) {
        /* 对副本操作 */
        jint nativeArray[10];
        (*env)->GetIntArrayRegion(env, javaArray, 0, 10, nativeArray);
        nativeArray[0] = 1;
        nativeArray[1] = 2;
        nativeArray[3] = 3;
        (*env)->SetIntArrayRegion(env,javaArray, 0, 10, nativeArray);
        /* 对直接指针操作 */
        jint* nativeDirectArray;
        jboolean isCopy;
        nativeDirectArray = (*env)->GetIntArrayElements(env, javaArray, &isCopy);
        nativeDirectArray[3] = 5;
        (*env)->ReleaseIntArrayElements(env, javaArray, nativeDirectArray, 0);
    }
    return javaArray;


}