# falseChar
A simple, non-global rule, customizable and man processable encryption program

## General description
This is a simple C++ program that can be used to encrypt and decrypt ASCII printable characters to code, (inspired by [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck)), you are free to use this program in your application, service or anything without credit or permission.

## DISCLAIMER
falseChar is made on a hobby by a teenager who just started using C++ for few months, code may be badly optimized and unreliable. ***Please test this program and make sure it met your requirements and safety***

**⫸** We are **NOT** responsible for any damages cause by this program, please refer to this program licensing for more information.

## How this program works
There's 2 C++ scripts and 1 **falseCharTable** (fcT) file. let's start with the scripts, compiler.cpp is for compiling text files into fc (falseChar) file, note that it works with any file, it will print it in terminal and save it into fc-output.fc file in the same directory as it, decompiler.cpp is for decompiling fc files back to text file, it takes absolute file path for argument for input file.

Character codes are defined by CharTable.fcT (falseCharTable file) and saperated by lines, **line 1 is exclusive to space**.

## How to use
compile the C++ code, then run it with argument as the input file absolute path. **CharTable.fcT must be in the same directory as the program**.