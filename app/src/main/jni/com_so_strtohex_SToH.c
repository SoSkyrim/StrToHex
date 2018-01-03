//
// Created by so on 2017/12/27.
//
#include "com_so_strtohex_SToH.h"
#include <string.h>
#include <stdio.h>
#include <android/log.h>

#define TAG "sorrower" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__)   //定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__)    //定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__)    //定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__)   //定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__)   //定义LOGF类型

#define CBUFLEN (cLen * 2 + 1)

JNIEXPORT jstring JNICALL Java_com_so_strtohex_SToH_StrToHexC
  (JNIEnv * env, jobject obj, jstring str){
    //1.获取字符串和其长度
    jsize jLen = (*env)->GetStringLength(env,str);
    const char * cStr = (*env)->GetStringUTFChars(env, str, 0);
    int cLen = jLen;

    //2.设置缓存并初始化
    unsigned char cBuf[CBUFLEN];
    memset (cBuf, '-', CBUFLEN);
    cBuf[CBUFLEN - 1] = 0;

    //3.测试初始化结果和长度
    LOGI ("cBuf: %s cLen: %d", cBuf, cLen);

    //4.开始转换
    unsigned char cH, cL;
    int i;
    for (i = 0; i < cLen; i++){
        //4.1 获取高低位
        cH = cStr[i] >> 4;
        cL = cStr[i] & 0x0f;

        //4.2 转换为16进制
        if (cH > 9){
            cH = cH + 'A' - 10;
        }
        else {
            cH = cH | 0x30;
        }

        if (cL > 9){
            cL = cL + 'A' - 10;
        }
        else {
            cL = cL | 0x30;
        }

        //4.3 存储高低位到缓存串
        cBuf[i * 2] = cH;
        cBuf[i * 2 + 1] = cL;
    }

    //5.检测结果, 并返回
    LOGI ("cBuf: %s", cBuf);
    jstring hexStr = (*env)->NewStringUTF(env, cBuf);
    return hexStr;
  }
