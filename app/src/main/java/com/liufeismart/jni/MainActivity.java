package com.liufeismart.jni;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.liufeismart.jni.hellojni.HelloJNI;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        TextView textView = (TextView) findViewById(R.id.tv);
        String s = HelloJNI.helloJNI();
        int add = HelloJNI.add(3, 66);
        textView.setText(s+"\n"+"我是一个加法: "+add);
        textView.setText(textView.getText().toString()+HelloJNI.setName("liufeismart"));
    }


    static {
        //名字必须和build.gradle中的moduleName一致
        System.loadLibrary("Hello");
    }
}
