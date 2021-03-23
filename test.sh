#!/bin/bash
a="./a.exe"

if [ -n "$1" ]
then
g++ *.cpp memwatch.c -DMEMWATCH -DMEMWATCH_STDIO -o a.exe $1
else
g++ *.cpp memwatch.c -DMEMWATCH -DMEMWATCH_STDIO -o a.exe
fi

$a -v -d <in.txt && cat memwatch.log >&2 && rm memwatch.log

echo ""
echo "=======With -d flag========="
echo ""

$a -v <in.txt && cat memwatch.log >&2 && rm memwatch.log
