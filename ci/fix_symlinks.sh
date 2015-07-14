#!/bin/sh

mkdir -p usr/ && mkdir -p usr/bin

ln -s $(which g++-5) usr/bin/g++
ln -s $(which gcc-5) usr/bin/gcc
ln -s $(which gcov) usr/bin/gcov
