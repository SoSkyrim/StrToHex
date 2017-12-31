package com.so.strtohex;

/**
 * Created by so on 2017/12/27.
 */

public class SToH {
    public native int dataServer (String str1, String str2, int len);
    public native int dataTest (String str1, String str2, int len);
    public native String StrToHexC (String str);
    static {
        System.loadLibrary("SToHC");
    }
}
