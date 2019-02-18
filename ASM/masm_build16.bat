@echo off
D:\masm32\bin\ml /c /Fl /Sa "%1.asm"
D:\masm32\bin\link16 "%1.obj","%1.com","%1.map";