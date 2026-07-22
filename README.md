# chesspp — Chess rules engine & CLI

A complete chess rules engine and terminal application in C++17, with a threaded time-control system and a unit-test suite under GoogleTest. Play against another human or a CPU that makes random legal moves.

## Features

**Full rules engine**

- Legal move generation for all pieces, including pins and check evasion
- Castling, en passant, and pawn promotion (with piece selection)
- Check and checkmate detection
- All draw conditions: stalemate, the 50-move rule, threefold repetition, and insufficient material (including the king-and-minor-piece and two-knight cases), plus draw by agreement

**Notation & I/O**

- FEN parsing — construct any position from a FEN string
- Algebraic-notation move output with disambiguation, capture, castling, and check/checkmate annotation
- PGN game logging

**Representation & type safety**

- Contiguous `std::array<ChessPiece, 64>` board representation
- `enum class`-based piece and color types
- Type-safe index wrappers (`RangedInt`, `BoardIndex`, `FileRankIndex`) that validate their range on construction and assignment, making out-of-bounds board access unrepresentable

**Concurrency**

- A dedicated timer thread and a non-blocking input thread run alongside the game loop
- The `ChessTimer` coordinates state with `std::atomic`, `std::mutex`, and `std::condition_variable`, and cleans up its thread via RAII

**Opponent**

- The CPU plays random legal moves (uniform selection over legal moves) — this is a rules engine, not a searching/evaluating chess AI. A stronger opponent is a possible future extension.

**Configuration**

- File-based configuration for time controls, player types, and CPU move delay

## Build & run

Requires a C++17 compiler, CMake 3.28+. GoogleTest is fetched automatically.

```bash
git clone --recursive https://github.com/schnyle/chesspp.git
cd chesspp
mkdir build && cd build
cmake ..
make
./chess
```

## Tests

```bash
ctest --verbose
```

The suite covers move generation, piece behavior, rendering, and utilities (friend-class access is used to test internals).
