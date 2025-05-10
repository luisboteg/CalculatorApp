# Calculator App

A simple calculator application written in C++ that supports basic arithmetic operations and keeps a history of all operations performed.

## Features

- Addition, subtraction, multiplication, division
- Stores each operand and result along with metadata (order and even/odd)
- Saves and loads history to/from a file
- Filters history by number type (even/odd) and operation type
- Unit tests implemented using GoogleTest

## Requirements

- Visual Studio 2022
- CMake >= 3.10
- C++17 support

## Build & Run

1. Open **Visual Studio 2022**.
2. Go to **File > Open > Folder...** and select the root of this project.
3. Visual Studio will automatically detect and configure the CMake project.
4. To run the calculator:
   - In the Solution Explorer, right-click on `CalculatorApp` and choose **Set as Startup Item**.
   - Press **Ctrl+F5** or choose **Start Without Debugging** from the Debug menu.

## 🧪 Run Tests

1. In the Solution Explorer, right-click on `CalculatorTest` and choose **Set as Startup Item**.
2. Press **Ctrl+F5** to build and run the tests. Results will be displayed in the terminal window.

## File Formats

- History is saved to and loaded from `history.txt` in CSV format.

## Project Structure

```
CalculatorApp/
├── include/
│   └── Calculator.hpp
├── src/
│   └── Calculator.cpp
│   └── main.cpp
├── tests/
│   └── CalculatorTest.cpp
├── external/
│   └── googletest/ (added as a Git submodule)
├── CMakeLists.txt
└── README.md
```

## License

MIT License. See `LICENSE` file for details.
