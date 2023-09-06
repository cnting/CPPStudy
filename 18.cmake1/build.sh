#!/bin/bash
rm -rf build
mkdir build
cd build
NDK_PATH='/Users/cnting/Library/Android/sdk/ndk/25.1.8937393'
cmake -DANDROID_NDK=${NDK_PATH} \
  -DCMAKE_TOOLCHAIN_FILE=${NDK_PATH}/build/cmake/android.toolchain.cmake \
  -DANDROID_ABI='armeabi-v7a' \
  -DANDROID_NATIVE_API_LEVEL=19 ..
make
#./hello
