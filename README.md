# Calculator App

A full-featured calculator in C++ using Object-Oriented Programming principles and tested with Google Test.

## Features
- Addition, subtraction, multiplication, division
- History tracking with order, parity, and descriptions
- Save and load operation history from file
- Filter operations by even/odd numbers and operation type
- Console-based menu interface

## Requirements
- Visual Studio 2019 or later (with CMake)
- Google Test (bundled or via vcpkg)

## Build & Run

```bash
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
./CalculatorApp
```

## Run Tests

```bash
./CalculatorTest
```

## Usage

The application presents a menu where you can:
- Perform operations
- Save/load history
- View the full history
- Filter results by conditions

## File Formats

- History is saved to and loaded from `history.txt` in CSV format.
