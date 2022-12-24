#!/bin/sh
export TOP_DIR=`pwd`"/../../../"

main()
{
    rm -rf build

    mkdir build && cd build && cmake ..
    make
}



main
