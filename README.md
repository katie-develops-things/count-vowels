# Count Vowels in a File (Full Version)

This simple program in C displays the count of the vowels A, E, I, O, and U contained in a file. The filename (without full file path) is specified by the user as a command line argument when the program is called to be executed. The program will then search the system for a readable file with that name to get its full file path. This program is only to be run on Linux systems.

## User Information
###### Usage
To run the program, enter the program directory and type the following into a bash or zsh shell. The filename is the file you wish to count the occurence of vowels in.
```
./count-vowels filename.txt
```

###### Note
If multiple readable files with the same name exist on the system, the last returned file by the shell's `find` command will be the one scanned for vowels.

###### Testing
This program was tested on a virtual machine provided by Parallels for using Ubuntu 22.04 for ARM64.

###### To compile
If the program needs to be recomplied for some reason, type the following commands into a shell to generate an executable file.
```
gcc count-vowels.c
```

## Security
This program only allows for reading of files; writing privilidges are not granted anywhere in the program's source code. Further, sudo privilidges are not granted when reading files, so any file that requires sudo privilidges will not be able to be opened by this program. By default on Ubuntu 20.x, many system files do not give the root user reading access unless permissions are explicitly changed for that file or directory, so these files my not be read by this program either.
However, this program does implicitly allow the user to see if the particular file they enter as an argument exists or not, which could allow a malicious actor to perform a directory traversal attack.
