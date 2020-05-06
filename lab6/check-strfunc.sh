#!/bin/bash
sym=`gcc -c mystring.c; /usr/bin/nm mystring.o | grep -c '|str'`
echo $sym
if [ "$sym" != "0" ]; then
    echo DO NOT USE ANY STRING FUNCTION IN mystring.c OR YOU MAY LOOSE MANY POINTS;
    /usr/bin/nm mystring.o | grep '|str'
    exit 1
else
    echo OK. No string functions;
fi

sym=`grep -c '\[' mystring.c`
echo $sym
if [ "$sym" != "0" ]; then
    echo "DO NOT USE ARRAYS IN mystring.c USE POINTERS";
    grep -c '\[' mystring.c
    exit 1
else
    echo OK. No array operations;
    exit 0
fi


