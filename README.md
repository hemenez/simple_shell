## Simple_Shell Project

### Synopsis
The objective of the simple_shell project is learn how the base functions of the shell work and implement them ourselves to create our own simple interactive shell.

### Learning Objectives
Through this project the authors learned:
* Who designed and implemented the original UNIX operating system
* Who wrote the first version of the UNIX shell
* Who invented the B programming language, which is the predecessor to the C programming language
* Who Ken Thompson is
* How the shell works
* What a pid and ppid are
* How to manipulate the environment of the current process
* What the difference between a function and a system call is
* How to create processes
* What the 3 prototypes of main are
* How the shell uses the environment variable PATH to find the programs
* How to execute programs with the execve system call
* How to suspend a process until one or all of its children terminates
* What end-of-file (EOF) is.

### Requirements
* Allowed editors: `vi`, `vim`, `emacs`
* All files must be compiled on Ubuntu 14.04 LTS
* Your C programs and functions must be compiled with gcc 4.8.4 using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
* All of our files should end with a new line
* A `README.md` at the root of the folder of the project is mandatory
* No more than 5 functions per file
* All our header files should be guarded

### Output
* Unless specified our program **must have the exact same output** as `sh`(`/bin/sh`) as well as the exact same error output.
* The only difference is when we print an error, the name of the program must be equivalent to our `argv[0]`(see below).
Example of error with `sh`:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
Same error with our program `hsh`:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```

### List of allowed functions and system calls
* `access`(man 2 access)
* `chdir`(man 2 chdir)
* `close`(man 2 close)
* `closedir`(man 3 closedir)
* `execve`(man 2 execve)
* `exit`(man 3 exit)
* `fork`(man 2 fork)
* `free`(man 3 free)
* `stat`(`__xstat`)(man 2 lstat)
* `lstat`(`__lxstat`)(man 2 lstat)
* `fstat`(`__fxstat`)(man 2 fstat)
* `getcwd`(man 3 getcwd)
* `getline`(man 3 getline)
* `kill`(man 2 kill)
* `malloc`(man 3 malloc)
* `open`(man 2 open)
* `opendir`(man 3 opendir)
* `perror`(man 3 perror)
* `read`(man 2 read)
* `readdir`(man 3 readdir)
* `signal`(man 2 signal)
* `strtok`(man 3 strtok)
* `wait`(man 2 pid)
* `waitpid`(man 2 waitpid)
* `wait3`(man 2 wait3)
* `wait4`(man 2 wait4)
* `write`(man 2 write)
* `_exit`(man 2 `_exit`)
* `isatty`(man 3 isatty)
* `fflush`(man 3 fflush)

### Testing
Our shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### Environment
Our simple_shell project was tested and compiled on `Ubuntu 14.04 (trusty64)` via Vagrant run through VirtualBox.

### Repository Contents
This repository contains the following files:
| **File** | **Description** |
| -------- | --------------- |
| AUTHORS | Contains the authors of the project |
| envfxn.c | Contains the function to print the environment |
| exitfxn.c | Our built-in exit function to close active processes and exit the shell |
| handlepath.c | Handles the path so the simple_shell can take commands like ls, pwd, echo, etc. |
| holberton.h | Contains prototypes, structs, libraries used, and defines macros. |
| linestore.c | Handles getting the user arguments and stores them in a buffer |
| shellentry.c | The main function and built-in searcher |
| strcompare.c | Contains our custom strcmp function |
| tokenize.c | Tokenizes the user inputted arguments to be able to check for commands |
| utilizers.c | Contains more custom helper functions like strlen |

### Description of functions
| **Function** | **Description** |
| -------- | ----------- |
| `char *getlinefxn()` | This function gets the user input and stores it in a buffer to be tokenized |
| `char **tokenfxn(char *buff)` | This function tokenizes the buffer that stores the user input so it can be searched for commands |
| `int _strcmp(char *s1, char *s2)` | Compares two strings, if the strings match it returns 0 otherwise it returns the difference of the first differing letter |
| `void exitfxn(char *buff, char **commands)` | This function exits out of the active processes and the simple shell. |
| `void envfxn(char *buff, char **commands)` | This function prints the environment |
| `int builtinfxn(char *buff, char **commands)` | This function checks to see if the command is a shell built-in. |
| `char *loopenvironment()` | This function loops through the environment |
| `char *concat(char *token, char **tokens, char *commands)` | This function appends the command to the PATH token |
| `char *_strcpy(char *dest, char *src)` | Custom function to copy a string to another string |
| `char *_strdup(char *str)` | Custom function to duplicate a string |
| `char *getpath(char *commands)` | This function finds the path and appends the desired command |
| `char *_strcat(char *dest, char *src)` | Custom function to concatenate two strings |
| `int _strlen(char *s)` | Custom function to get the length of a string |

### Compilation
This code was compiled using GNU Compiler Collection (gcc) with the following flags: `gcc -Wall -Werror -Wextra -pedantic -g3 *.c -o hsh`
###### Example commands
```
TalkToMe$ ls
AUTHORS envfxn.c exitfxn.c handlepath.c holberton.h linestore.c README.md shellentry.c strcompare.c tokenize.c utilizers.c
TalkToMe$ 
```
### Notes
This shell is a very simple interactive shell, it does not handle special characters

### Authors
[Jacob Biehler](https://github.com/biehlerj)
[Lindsey Hemenez](https://github.com/hemenez)
