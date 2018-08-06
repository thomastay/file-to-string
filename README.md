# file2string

A quick-and-easy C program to create a one line string from a file or a list of
files. I use it a lot to generate help files or output to the user that is
nicely formatted

## Features
It can recognize newlines, tab characters, and it transforms all double
quotes into single quotes.

## Building:

### Dependencies
You will need a compiler with C support, CMake 3.0+, and git.

To check, run the following commands on your terminal:
```
cc --version
cmake --version
git --version
```

### Steps
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

## Usage

```
file2string [FILE] ...
```

If no file is specified, read from standard input.
