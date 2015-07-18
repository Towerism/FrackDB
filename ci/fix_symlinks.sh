#!/bin/sh

rm -f /usr/bin/g++
rm -f /usr/bin/gcov

ln -s /usr/bin/g++-5 /usr/bin/g++
ln -s /usr/bin/gcov-5 /usr/bin/gcov
