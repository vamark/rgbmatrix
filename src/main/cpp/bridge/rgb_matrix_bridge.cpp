#include "rgb_matrix_bridge.h"

jobject RGBMatrixBridge::toJava(RGBMatrix* matrix) {
    return Bridge<RGBMatrix>::toJava(matrix, "io/vagvolgyi/rgbmatrix/jni/RGBMatrixJNI", "(J)V");
}