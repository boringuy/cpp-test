Testing of various modern C++ features

To build with debug symbol:

``` bash
bazel build --compilation_mode=dbg src/...
```

To build with optimization (in order to get rid of the `***WARNING*** Library was built as DEBUG. Timings may be affected.` from google-benchmark

``` bash
bazel build -c opt src/...
```
