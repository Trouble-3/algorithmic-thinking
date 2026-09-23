# Benchmarks

The benchmark executable generates deterministic workloads and reports CPU time for several operations at increasing input sizes.

Run:

```bash
make benchmark
```

or:

```bash
./benchmarks/run.sh
```

Output is CSV-like:

```text
benchmark,size,cpu_seconds
hash_set,1000,...
...
```

These numbers are **environment-specific**. Use them to inspect growth trends on your machine, not as universal performance claims.

The benchmark currently covers:

- hash-set insertion + lookup;
- BFS on a path graph;
- segment-tree queries + point updates;
- union-find unions + connectivity checks.

For a serious performance study, repeat runs, pin down the compiler/toolchain, record hardware details, and use larger/generated workloads appropriate to the operation being measured.
