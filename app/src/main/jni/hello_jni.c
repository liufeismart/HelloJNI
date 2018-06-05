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
 */
JNIEXPORT jstring JNICALL Java_com_liufeismart_jni_hellojni_HelloJNI_setName
  (JNIEnv* env, jclass instance, jstring name ) {

  jstring javaString;
  /* C->Java: NewStringUTF */


  /* Java->C: GetStringUTFChars*/
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