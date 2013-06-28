#include <jni.h>
#include "Hello.h"
#include  <stdio.h>

JNIEXPORT void JNICALL Java_Hello_sayHello (JNIEnv *env, jobject obj) {
        printf("Hello World!\n");
}
