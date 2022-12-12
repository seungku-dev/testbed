# ABOUT

testbed consists of various test scenarios.

The purpose of this application is to ensure stability by testing various scenarios or to detect changes in external factors in the same scenario.

# BUILD

You can build testbed simply by using a script.

The executable will be installed in ${TARGET_INSTALL_DIR} defined in CMakeLists.txt.

```bash
$ ./run_build.sh
```

You can also simply delete build artifacts with the script option.

```bash
$ ./run_build.sh --clean
```

Alternatively, you can build directly with the cmake command.

```bash
$ mkdir build
$ cmake -S . -B build
$ cmake --build build
$ cmake --install build
```

# Execution

```bash
$ /usr/local/testbed/testbed
```