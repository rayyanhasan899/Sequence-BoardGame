# Validation and limitations

## Observed locally — 6 November 2026

- CMake configure/build succeeded on Windows with MSVC 19.50.35730 and C++17.
- CTest: 2/2 executables passed (`input_test`, `rules_test`). Checks cover malformed/out-of-range input, horizontal/vertical/diagonal wins, the wrong player, and draw-deck exhaustion.
- Existing card/jack and win-rule expressions remain unchanged. The exhaustion bound now matches the actual 104-element array instead of reading beyond it.
- Compiler warnings remain. A complete interactive match and every rule combination were not tested.

Run: `cmake -S . -B build`, `cmake --build build --config Debug`, then `ctest --test-dir build -C Debug --output-on-failure`.
