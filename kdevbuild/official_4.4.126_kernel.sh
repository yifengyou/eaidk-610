#!/bin/bash

set -uxo pipefail

WORKDIR=$(pwd)
export DEBIAN_FRONTEND=noninteractive

#==========================================================================#
#                        init build env                                    #
#==========================================================================#
apt-get update
apt-get install -qq -y ca-certificates
apt-get install -qq -y --no-install-recommends \
  build-essential ca-certificates ccache curl \
  device-tree-compiler vim dosfstools fakeroot file \
  flex gawk gcc-aarch64-linux-gnu git gnupg jq \
  libssl-dev locales lsb-release lzop make \
  ncurses-dev parted patch pigz python python3 \
  python3-distutils python3-pip rsync sed sudo \
  u-boot-tools unzip wget xxd xz-utils zip \
  binwalk zlib1g-dev squashfs-tools rar liblz4-tool \
  genext2fs bc htop openssh-client binwalk libc6-i386

localedef -i zh_CN -f UTF-8 zh_CN.UTF-8 || true
mkdir -p ${WORKDIR}/rockdev
mkdir -p ${WORKDIR}/release

#==========================================================================#
#                        build uboot                                       #
#==========================================================================#
cd ${WORKDIR}/
git clone --depth 1 -b master https://github.com/yifengyou/eaidk610-uboot u-boot.git
cd u-boot.git
ls -alh

if [ ! -d gcc-arm-8.3-2019.03-x86_64-aarch64-linux-gnu ]; then
  cat dependency/* | tar -Jxvf -
fi

export PATH=$(realpath gcc-arm-8.3-2019.03-x86_64-aarch64-linux-gnu/bin):$PATH

make Q= ARCH=arm CROSS_COMPILE="aarch64-linux-gnu-" rk3399_linux_defconfig

make Q= ARCH=arm V=1 CROSS_COMPILE="aarch64-linux-gnu-" ARCHV=aarch64 --jobs=$(nproc)

ls -alh uboot.img
md5sum uboot.img
sha256sum uboot.img

mv uboot.img ${WORKDIR}/release/uboot.img
ls -alh ${WORKDIR}/release/uboot.img
md5sum ${WORKDIR}/release/uboot.img

#==========================================================================#
#                        build kernel                                      #
#==========================================================================#
cd ${WORKDIR}
git clone --depth 1 -b master https://github.com/yifengyou/eaidk610-kernel kernel.git
cd kernel.git
ls -alh

if [ ! -d gcc-arm-11.2-2022.02-x86_64-aarch64-none-linux-gnu ]; then
  cat dependency/* | tar -Jxvf -
fi
export PATH=$(realpath gcc-arm-11.2-2022.02-x86_64-aarch64-none-linux-gnu/bin/):$PATH

# config kernel
make ARCH=arm64 CROSS_COMPILE="aarch64-none-linux-gnu-" rockchip_linux_defconfig

if [ -f scripts/dtc/dtc-lexer.lex.c ]; then
  sed -i 's/^YYLTYPE yylloc;$/extern YYLTYPE yylloc;/g' scripts/dtc/dtc-lexer.lex.c
fi

# build dtbs
make ARCH=arm64 CROSS_COMPILE="aarch64-none-linux-gnu-" dtbs -j$(nproc)

# build kernel
make ARCH=arm64 CROSS_COMPILE="aarch64-none-linux-gnu-" -j$(nproc)

# build kernel module
make modules ARCH=arm64 CROSS_COMPILE="aarch64-none-linux-gnu-" -j$(nproc)

make Q= rk3399-eaidk-linux.img ARCH=arm64 CROSS_COMPILE="aarch64-none-linux-gnu-" -j$(nproc)

# install module
make ARCH=arm64 \
  CROSS_COMPILE="aarch64-none-linux-gnu-" \
  INSTALL_MOD_PATH=$(pwd)/kos \
  modules_install

ls -alh ./arch/arm64/boot/dts/rockchip/rk3399-eaidk-linux.dtb

# output sum
ls -alh boot.img
md5sum boot.img
sha256sum boot.img
cp -a boot.img ${WORKDIR}/release/

# release kernel image
ls -alh arch/arm64/boot/Image
md5sum arch/arm64/boot/Image
cp -a arch/arm64/boot/Image ${WORKDIR}/release/

# release dtb
ls -alh arch/arm64/boot/dts/rockchip/rk3399-eaidk-linux.dtb
md5sum arch/arm64/boot/dts/rockchip/rk3399-eaidk-linux.dtb
cp -a arch/arm64/boot/dts/rockchip/rk3399-eaidk-linux.dtb ${WORKDIR}/release/

# release config
cp .config ${WORKDIR}/release/config-4.4.126-kdev
ls -alh ${WORKDIR}/release/config-4.4.126-kdev
md5sum ${WORKDIR}/release/config-4.4.126-kdev

# release system map
cp System.map ${WORKDIR}/release/System.map-4.4.126-kdev
ls -alh ${WORKDIR}/release/System.map-4.4.126-kdev
md5sum ${WORKDIR}/release/System.map-4.4.126-kdev

# release kernel modules
if [ -d kos/lib/modules ]; then
  find kos -name "*.ko"
  ls -alh kos/lib/modules/
  tar -zcvf ${WORKDIR}/release/kos.tar.gz kos
fi

ls -alh ${WORKDIR}/release/
echo "Build completed successfully!"
exit 0
