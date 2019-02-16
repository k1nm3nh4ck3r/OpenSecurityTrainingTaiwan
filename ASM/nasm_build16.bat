@echo off

set PATH=%PATH%;D:\NASM\alink;D:\NASM\
nasm -f obj %1.asm -o %1.obj
alink %1.obj