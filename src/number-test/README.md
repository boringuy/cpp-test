Various tests for different number:
- when storing number in double or float, it's not exact. Not only it may lose precision but can also add extra digits to the number. For the test code (using -74.073300 and 4.635700), using gdb, it prints:

```
Breakpoint 1, main (argc=1, argv=0x7fffffffdd68) at src/number-test/number-test.cc:11
11          std::cout << "v3 = " << v3 << std::endl;
(gdb) print v3
$1 = -74.073300000000003
(gdb) print v4
$2 = -74.0733032
(gdb) print v5
$3 = 4.6356999999999999
(gdb) print v6
$4 = 4.63570023
(gdb) quit
A debugging session is active.
```
