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

## How falseChar decompiler works
when decompiling, the script will loop through characters in given falseChar file. when it hits **(** it will enter closure mode and connect string until it hits **)**, then it will convert it into integer, find the character in **falseCharTable** file and add it to output string. if it hits **>** and currently not in closure mode, it will add what's in **line 1** of the falseCharTable file which should be space.

## How falseChar compiler works
when compiling, the script will loop through characters in given text file. while doing that, it also loop through **falseCharTable Modals** and check if it equal to or not, for **Modal** that are over 1 character long, it will check exactly that much of character and skip what it found. once it found falseCharTable index for the word, it will add into the output string. if it hit space however, it will put **>** instead of index.

## falseCharTable (fcT)
falseCharTable is the file that define what index means what. saperated by lines, Modals can be more than 1 character long! **line 1** is exclusive to **>** which by default defines space, **but doesn't mean you can't change it ;)**.

## Tips
1. Any characters that it hits outside closure mode and not **(** or **>** are ignored and can be used as comments
2. This is not a good program to be used as compression **BUT** if the file you want to compress have mutiple of repeated words or lines then this could be a great option but I honestly would suggest [ZIP](https://en.wikipedia.org/wiki/ZIP_(file_format)) or [7-Zip](https://en.wikipedia.org/wiki/7-Zip) compression.