# file2string

A quick-and-easy C program to create a one line string from a file or a list of
files. I use it a lot to generate help files or output to the user that is
nicely formatted.

## Features
It can recognize newlines, tab characters, and it transforms all double
quotes into single quotes.

## Installing

A pre-built Windows Binary is available in the Releases tag.

For Linux, no binary has been compiled, however all Linux distributions come with inbuilt gcc (C Compiler). You can follow the instructions for Manual building or Automated building if you have CMake.

## Building from source:

### Dependencies
You will need a C Compiler (gcc, clang, MSVC, etc), CMake 3.0+ (optional), git, and help2man.

To check, run the following commands on your terminal:
```
cc --version
cmake --version
git --version
help2man --version
```

### Automated building using CMake:
Run the following commands on your machine:
```
git clone https://github.com/thomastay/file-to-string.git
cd file-to-string
mkdir build bin
cd build
cmake ..
make
sudo make install
```

### Manual building (will not auto install):
Run the following command in the source directories
```
git clone https://github.com/thomastay/file-to-string.git
cd file-to-string
mkdir bin
cc -Wall -Wextra -Wpedantic -O2 file2string.c -o bin/file2string
help2man -o ../bin/file2string.1 ../bin/file2string
```

## Usage

```
file2string [FILE] ...
```

If no file, or '-' is specified, read from standard input.
