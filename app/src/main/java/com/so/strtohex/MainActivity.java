package com.so.strtohex;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void StrToHex(View v) {
        //1.获取控件
        EditText et_ascii_str = (EditText) findViewById(R.id.et_ascii_str);
        TextView tv_hex_str = (TextView) findViewById(R.id.tv_hex_str);

        //2.获取输入串并转换
        String input_str = et_ascii_str.getText().toString();
        String hexStr = new SToH().StrToHexC(input_str);

        //3.对返回串处理, 帮助查看
        char[] hexCharArray = hexStr.toCharArray();
        String hexDisplayStr = "";

        for (int i = 0; i < hexCharArray.length; i++) {
            if (i % 2 == 0 && i > 0 && i % 8 != 0) {
                hexDisplayStr += "-";
            }
            if (i % 8 == 0 && i > 0) {
                hexDisplayStr += " ";
            }
            hexDisplayStr += hexCharArray[i];
        }

        //4.显示处理后的结果
        tv_hex_str.setText(hexDisplayStr);
    }
}


