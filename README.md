# Simple_Shell

## Simple Shell > In this project, we coded from scratch a simple Unix Shell
A shell does three main things in its lifetime.
1. Initialize: In this step, a typical shell would read and execute its configuration files. These change aspects of the shell’s behavior.
2. Interpret: Next, the shell reads commands from stdin (which could be interactive, or a file) and executes them.
3. Terminate: After its commands are executed, the shell executes any shutdown commands, frees up any memory, and terminates.
To learn more about how the shell works, visit our blog here [blog]()
## Builtins
* `exit` exits shell (Usage: `exit [status]`)
* `env` prints environmental variables (Usage: `env`)
* `setenv` creates or modifies an environmental variable (Usage: `setenv name value`)
* `unsetenv` removes an envrionmental variable (Usage: `unsetenv name value`)
* `cd` changes directories (Usage: `cd [-][~][path]`)

## Functions and system calls used
`perror`, `fork`, `signal`, `malloc`, `free`, `getcwd`, `chdir`, `execve`, `write`, `wait`, `exit`

## Description of what each file shows:
main.h ---------------------------- holds prototypes of functions spread across all files
shell.c ----------------------------holds entrance into program
man_3_shell ------------------------custom manpage for our simple shell

### Helper files
_env.c------------------------------functions for built-in commands including env, setenv, unsetenv
built_in.c--------------------------functions for built-in commands including exit, cd, ctrl_c
_getbuiltin.c-----------------------execute functions for built-in commands
commandhandler.c--------------------read parse and execute commands 
stringcontrol.c---------------------handle strings including comparing, duplicating, concatenatingand length of a string

## Environment
* Language: C
* OS: Ubuntu 14.04 LTS
* Compiler: gcc 4.8.4
* Style guidelines: Betty style

## How To Install, Compile, and Use

Install and Compile
``` C
(your_terminal)$ git clone https://github.com/Jql11/Simple_Shell.git
(yourRRRR_terminal)$ cd simple_shell
(your_terminal)$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Run the C Shell
```C
./hsh
```

Type in command
```C
echo hello
```

Sample Usage
```C
#cisfun$ echo hello
hello
```
Stop and return to your original shell
```C
#cisfun$ exit
(your_terminal)$
```
## To Do
More functionality can still be added (e.g. handle aliases, pipelines)
***
## Authors

* Jacqueline Lu 
* Yuan Fang 
* Cienna Nguyen









