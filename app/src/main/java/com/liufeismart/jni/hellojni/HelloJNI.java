package com.liufeismart.jni.hellojni;

/**
 * Created by humax on 18/6/4
 */

public class HelloJNI {
    //helloJNI
    public static native String helloJNI();
    public static native int add(int a, int b);

    public static native String stringJni(String javaString);

    static {
        //名字必须和build.gradle中的moduleName一致
        System.loadLibrary("Hello");
    }
}
