# Architecture

```text
                     +----------------------+
                     |      examples/       |
                     |  small runnable C    |
                     +----------+-----------+
                                |
                                v
+----------------+      +-------+--------+      +----------------+
|    problems/   | ---> | include/ + src | <--- |     tests/     |
| chapter tasks  |      |  algorithms    |      | correctness    |
+----------------+      +-------+--------+      +----------------+
                                |
                                v
                     +----------+-----------+
                     | CMake + GitHub CI    |
                     | build / test / lint  |
                     +----------------------+
```

The repository deliberately separates:

- **learning problems** — what should be solved;
- **library code** — reusable data structures and algorithms;
- **tests** — executable correctness checks;
- **examples** — small programs showing the API;
- **docs** — complexity, roadmap, benchmarks, and design notes.
