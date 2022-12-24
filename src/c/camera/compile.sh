#!/bin/sh

# 这一句是用来找到platform中release代码
export TOP_DIR=`pwd`"/../../../"


main()
{
    rm -rf build
    mkdir build && cd build && cmake ..
    make
}


main
