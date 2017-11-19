##Simple_Shell Project
###Synopsis
The objective of the simple_shell project is learn how the base functions of the shell work and implement them ourselves to create our own simple interactive shell.

###Environment
Our simple_shell project was tested and compiled on `Ubuntu 14.04 (trusty64)` via Vagrant run through VirtualBox.

###Repository Contents
This repository contains the following files:
| **File** | **Description** |
| -------- | --------------- |
| AUTHORS | Contains the authors of the project |
| envfxn.c | Contains the function to print the environment |
| exitfxn.c | Our built-in exit function to exit programs and the shell |
| handlepath.c | Handles the path so the simple_shell can take commands like ls, pwd, echo, etc. |
| holberton.h | Contains prototypes, structs, libraries used, and defines macros. |
| linestore.c | Handles getting the user arguments and stores them in a buffer |
| shellentry.c | The main function and built-in searcher |
| strcompare.c | Contains our custom strcmp function |
| tokenize.c | Tokenizes the user inputted arguments to be able to check for commands |
| utilizers.c | Contains more custom helper functions like strlen |

###Description of functions
| **Function** | **Description** |
| -------- | ----------- |
| `char *getlinefxn()` | This function gets the user input and stores it in a buffer to be tokenized |
| `char **tokenfxn(char *buff)` | This function tokenizes the buffer that stores the user input so it can be searched for commands |
| `int _strcmp(char *s1, char *s2)` | Compares two strings, if the strings match it returns 0 otherwise it returns the difference of the first differing letter |
| `void exitfxn(char *buff, char **commands)` | This function exits out of the active processes. |
| `void envfxn(char *buff, char **commands)` | This function prints the environment |
| `int builtinfxn(char *buff, char **commands)` | This function checks to see if the command is a shell built-in. |
| `char *loopenvironment()` | This function loops through the environment |
| `char *concat(char *token, char **tokens, char *commands)` | This function appends the command to the PATH token |
| `char *_strcpy(char *dest, char *src)` | Custom function to copy a string to another string |
| `char *_strdup(char *str)` | Custom function to duplicate a string |
| `char *getpath(char *commands)` | This function finds the path and appends the desired command |
| `char *_strcat(char *dest, char *src)` | Custom function to concatenate two strings |
| `int _strlen(char *s)` | Custom function to get the length of a string |

##Compilation
This code was compiled using GNU Compiler Collection (gcc) with the following flags: `gcc -Wall -Werror -Wextra -pedantic -g3 *.c -o hsh`
######Example commands
```
TalkToMe$ ls
AUTHORS envfxn.c exitfxn.c handlepath.c holberton.h linestore.c README.md shellentry.c strcompare.c tokenize.c utilizers.c
TalkToMe$ 
```
##Notes
This shell is a very simple interactive shell, it does not handle special characters

##Authors
[Jacob Biehler](https://github.com/biehlerj)
[Lindsey Hemenez](https://github.com/hemenez)
