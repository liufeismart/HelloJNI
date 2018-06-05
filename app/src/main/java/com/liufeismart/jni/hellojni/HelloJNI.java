package com.liufeismart.jni.hellojni;

/**
 * Created by humax on 18/6/4
 */

public class HelloJNI {
    //helloJNI
    public static native String helloJNI();
    public static native int add(int a, int b);

    //Java String 与C char/jbyte
    public static native String setName(String name);

    public static native int[] getArray(int[] array);
}
