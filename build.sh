#!/usr/bin/fish

set PATH $HOME/tc/proton-clang/bin $PATH
export KBUILD_BUILD_HOST="notkernel"
export KBUILD_BUILD_USER="Panda"

# Push kernel to channel
function push
    cd AnyKernel3
    set ZIP (echo *.zip)
    curl -F document=@$ZIP "https://api.telegram.org/bot$token/sendDocument" \
        -F chat_id="$chat_id"
end

# Fin Error
function finerr
    curl -s -X POST "https://api.telegram.org/bot$token/sendMessage" \
        -d chat_id="$chat_id" \
        -d "disable_web_page_preview=true" \
        -d "parse_mode=markdown" \
        -d text="Build throw an error(s)"
    exit 1
end

# Compile plox
function compile
    make O=out ARCH=arm64 vendor/kishi-perf_defconfig
    make -j(nproc --all) O=out ARCH=arm64 CC=clang AR=llvm-ar NM=llvm-nm \
        OBJCOPY=llvm-objcopy OBJDUMP=llvm-objdump STRIP=llvm-strip \
        CROSS_COMPILE=aarch64-linux-gnu- \
        CROSS_COMPILE_ARM32=arm-linux-gnueabi- \
        Image.gz-dtb

    if test $status -eq 0
        cd AnyKernel3
        make clean
        cp ../out/arch/arm64/boot/Image.gz-dtb .
        make notkernel
        cp NotKernel*.zip ~/upload
        cd ..
     else
        finerr
     end
end

compile
push
