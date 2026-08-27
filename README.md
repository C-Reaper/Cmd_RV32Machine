# Project README

## Overview
This project is a C application that demonstrates parsing and manipulating JSON data. It includes features such as reading from a JSON file, accessing nested objects, modifying values, and updating the JSON file.

## Features
- Reading JSON data from a file.
- Accessing nested objects within the JSON structure.
- Modifying values within the JSON object.
- Writing updated JSON data back to a file.

## Project Structure
- `build/`: Directory for storing executable files produced by the `Main.c` program.
- `src/`: Contains source code files.
  - `Main.c`: Entry point of the application.
- `code/Main.json`: Sample JSON configuration file used by the application.

### Prerequisites
- C/C++ Compiler and Debugger (GCC, Clang)
- Make utility
- Standard development tools

## Build & Run
To build and run the project on Linux:

1. Change to the project directory:
   ```sh
   cd <Project>
   ```

2. Build the project using `make` with the appropriate OS-specific makefile:
   - For Linux:
     ```sh
     make -f Makefile.linux all
     ```
   - For Windows (cross-compilation):
     ```sh
     make -f Makefile.wine all
     ```
   - For WebAssembly:
     ```sh
     make -f Makefile.web all
     ```

3. Execute the built application:
   ```sh
   make -f Makefile.linux exe
   ```

To clean the build artifacts and rebuild:

```sh
make -f Makefile.linux clean
make -f Makefile.linux all
```

For a complete build process that includes building libraries (if applicable):

```sh
make -f Makefile.linux cleanlib
make -f Makefile.linux lib
make -f Makefile.linux all
```