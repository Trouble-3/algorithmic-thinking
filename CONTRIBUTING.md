# Contributing

Thanks for helping improve this learning repository.

## Development workflow

1. Create a focused branch from `main`.
2. Keep changes scoped to one algorithm, exercise, test, or documentation topic.
3. Build with C11 and run the test suite before opening a pull request.
4. Run the sanitizer checks for changes that touch memory management or pointer-heavy code.
5. Update complexity notes or learning notes when an implementation changes the algorithmic trade-off.

## Local checks

```bash
make
make test
make sanitize
```

For a release-style build:

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build
ctest --test-dir build --output-on-failure
```

## C style

- C11, with compiler warnings enabled.
- Prefer small functions with explicit ownership and error paths.
- Keep public interfaces in `include/` and implementations in `src/`.
- Avoid hidden global state.
- Document non-obvious invariants in code comments.

## Tests

A change should include or update a test when behavior changes. Pay particular attention to:

- empty inputs;
- singleton inputs;
- duplicate values;
- disconnected graphs;
- unreachable vertices;
- boundary indices;
- integer overflow risks;
- allocation failures where the API exposes an error path.

## Pull requests

A good pull request explains:

- what changed;
- why the change is needed;
- the algorithm/data-structure choice;
- expected time and space complexity;
- how it was tested.

Keep commit messages focused, for example:

```text
feat(graph): add BFS distance computation
test(heap): cover repeated minimum values
docs(dp): explain bottom-up state transition
refactor(hash): isolate bucket lookup
```
