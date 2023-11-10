# gnl
Reading a line from an fd is way too tedious!!
This project is about programming a function that lets you read the text file pointed to by the file descriptor, one line at a time.

## [Input-output system calls in C](https://www.geeksforgeeks.org/input-output-system-calls-c-create-open-close-read-write/)

## File Descriptor

- **What is File Descriptor:**
  - In simple words, when you open a file, the operating system creates an entry to represent that file and store the information about that opened file. So if there are 100 files opened in your OS then there will be 100 entries in OS (somewhere in the kernel). These entries are represented by integers like (...100, 101, 102....). This entry number is the file descriptor. So it is just an integer number that uniquely represents an opened file for the process. If your process opens 10 files then your Process table will have 10 entries for file descriptors.

- **What's the difference between a file descriptor and a file pointer:**
  - A file descriptor is a low-level integer "handle" used to identify an opened file (or socket, or whatever) at the kernel level, in Linux and other Unix-like systems.
  - You pass a file descriptor to actual Unix calls, such as `read()`, `write()`, and so on.
  - A `FILE` pointer is a C standard library-level construct, used to represent a file. The `FILE` wraps the file descriptor and adds buffering and other features to make I/O easier.
  - You pass `FILE` pointers to standard C functions such as `fread()` and `fwrite()`.

## Static keyword in C
Quoting [Wikipedia](http://en.wikipedia.org/wiki/Static_variable):

> In the C programming language, static is used with global variables and functions to set their scope to the containing file. In local variables, static is used to store the variable in the statically allocated memory instead of the automatically allocated memory. While the language does not dictate the implementation of either type of memory, statically allocated memory is typically reserved in the data segment of the program at compile-time, while the automatically allocated memory is normally implemented as a transient call stack.
>

- Static is useful for cases where a function needs to keep some state between invocations, and you don't want to use global variables.
- It's used widely as an "access control" feature. If you have a .c file implementing some functionality, it usually exposes only a few "public" functions to users. The rest of its functions should be made static so that the user won't be able to access them. This is encapsulation, a good practice.
- A static variable isn't stored in the stack frame, it's stored in the same memory used for global variables "Data Segment"
