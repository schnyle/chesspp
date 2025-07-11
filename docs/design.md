# design

## game logic

- board representation
  - length 81 array
- legal move generation
  - piece movement
    - pawn
      - en passant
      - promotion
    - knight
    - bishop
    - rook
    - king
      - castling
    - queen
  - castling
  - check detection
- game state management
  - turn tracking
  - castling rights
  - en passant
- end game scenarios

  - checkmate
  - resignation
  - timeout
  - draw
    - stalemate
    - 50-move rule
    - repetition
    - agreement
    - insufficient material
      - king vs king
      - king + minor piece vs king
      - king + two knights vs king
      - king + minor piece vs king + minor piece
      - timeout vs insufficient material

- FEN/PGN support

## testing

- unit tests
- integration tests (game scenarios)
- regression tests

## graphics/user interface

- interactive 2D board rendering with SDL2
- settings menu for application configuration
- animation system

## networking

- p2p connection

## modern C++ best practices

- smart pointers for memory management
- RAII
