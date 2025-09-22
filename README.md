# Chesspp - Modern C++ Chess Engine & CLI Application

## Overview

A command-line chess application demonstrating modern C++ programming practices, concurrent system design, and algorithmic problem-solving. This project showcases modern software engineering principles through a complete chess engine implementation with a CPU opponent, built using C++17 standards and best practices.

## Technical Highlights

### Modern C++ Design Patterns & Practices

- **RAII (Resource Acquisition is Initialization)**: Comprehensive smart pointer usage throughout the codebase with `std::unique_ptr` for automatic memory management.
- **Strong Type Safety**: Custom type-safe wrappers (`RangedInt`, `BoardIndex`, `FileRankIndex`) preventing invalid state and runtime errors.
- **Exception Safety**: Robust error handling with custom exception types and RAII guarantees
- **Move Semantics**: Efficient resource management with proper move constructors and assignment operators

### Concurrent Programming and Multithreading

- **Thread-Safe Timer System**: Custom `ChessTimer` class using `std::atomic`, `std::mutex`, and `std::condition_variable` for precise time control
- **Asynchronous Input Handling**: Non-blocking user input system with thread synchronization
- **Lock-Free Programming**: Atomic operations for game state management across threads
- **Producer-Consumer Pattern**: Coordinated communication between game logic, timer, and input threads

### Memory Management & Performance

- **Zero Memory Leaks**: Complete RAII implementation with smart pointers and automatic cleanup
- **Efficient Data Structures**: `std::array` for fixed-size board representation, `std::unordered_map` with custom hash functions for position tracking
- **Cache-Friendly Design**: Contiguous memory layout for board representation

### Testing & Quality Assurance

- **Comprehensive Unit Testing**: Thorough unit testing with Google Test framework covering edge cases and game scenarios
- **Mocking & Dependency Testing**: Friend class testing pattern for private method validation
- **Automated Testing Pipeline**: CMake integration with CTest for continuous testing

## System Design Highlights

### Configurable Management

- **External Configuration**: File-based configuration system with type-safe parsing
- **Runtime Flexibility**: Configurable time controls, player types, and game parameters

### Rendering System

- **Modular Display Architecture**: Separation of game logic and presentation layers
- **ASCII Art Rendering**: Custom frame builder for terminal-based chess board visualization
- **Real-time Updates**: Dynamic board state rendering with move history

### Input/Output System

- **Raw Terminal Mode**: Low-level terminal control for responsive user interaction
- **Cross-platform Compatibility**: POSIX-compliant terminal handling
- **Algebraic Notation**: Standard chess notation parsing and generation

## Build & Run

```bash
git clone --recursive https://github.com/schnyle/chesspp.git
cd chesspp
mkdir build && cd build
cmake ..
make
./chess
```

## Testing

```
ctest --verbose
```

### Requirements

- **Compiler**: C++17 compatible (GCC 7+, Clang 5+, MSVC 2017+)
- **Build System** CMake 3.28+
- **Testing**: Google Test (automatically fetched)
