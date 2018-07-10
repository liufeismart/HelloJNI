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
        String s = HelloJNI.helloJNI()+"\n";
        int add = HelloJNI.add(3, 66);
        s += "我是一个加法: "+add+"\n";
        textView.setText(s);
        s += "字符串: "+HelloJNI.stringJni("liufeismart")+"\n";
        textView.setText(s);
        //

    }



}
