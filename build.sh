#!/usr/bin/fish

set TC_DIR "$HOME/tc"

export KBUILD_BUILD_HOST="notkernel"
export KBUILD_BUILD_USER="Panda"

make O=out ARCH=arm64 vendor/kishi-perf_defconfig

set PATH "$TC_DIR/clang/bin:$TC_DIR/gcc/bin:$TC_DIR/gcc_32/bin:$PATH"

make -j(nproc --all) O=out ARCH=arm64 CC=clang \
		CLANG_TRIPLE=aarch64-linux-gnu- \
		CROSS_COMPILE=aarch64-linux-android- \
		CROSS_COMPILE_ARM32=arm-linux-androideabi-
