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
You will need a compiler with C support, CMake 3.0+ (optional), and git.

To check, run the following commands on your terminal:
```
cc --version
cmake --version
git --version
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
cc -Wall -Werror -Wpedantic -O2 file2string.c -o bin/file2string
```

## Usage

```
file2string [FILE] ...
```

If no file is specified, read from standard input.
