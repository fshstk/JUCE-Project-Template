# JUCE Project Template

[![Build and Test](https://github.com/fshstk/jucetest/actions/workflows/build_test.yml/badge.svg)](https://github.com/fshstk/jucetest/actions/workflows/build_test.yml)

This is an attempt at a barebones template for a cross-platform plugin/app using
the [JUCE](https://github.com/juce-framework/JUCE) framework. CMake is used to
dynamically download dependencies at configure-time, and a basic unit testing
template is provided using the [Catch2](https://github.com/catchorg/Catch2)
framework.

The actual headers/sources are based on the CMake project template from the JUCE
project itself, with no changes except for code formatting.

## Installing/Running/Compiling

I recommend using something like VS Code with the CMakeTools extension to work
on this project, but you can use anything you like as long as you have CMake
installed. After cloning, you should be able to compile and run tests using
these two commmands from within the repository directory:

```bash
# Configure project:
$ cmake -B build

# Build project:
$ cmake --build build

# Run unit tests:
$ cd ctest --test-dir build
```

No external dependencies are required; the JUCE and Catch2 frameworks are
automatically downloaded when you configure the project. This also means that
the first command may take a long time to run.

A note about platforms: this should work fine on both Mac and Windows. I have no
idea about Linux. The Ubuntu CI runner complains about missing dependencies and
I don't have the time or the energy to troubleshoot that particular nest of
rats. If you get this working on Linux, please submit a PR!

## Customizing

Set the name of your project and plugin in the top-level CMakeLists file:

```cmake
project(AudioPluginExample ...)
```

Remember to add new files to `target_sources` in the CMakeLists file in `src/`.

## Code Formatting

I highly recommend using `clang-format` inside your editor to automatically
format your code on every save. A formatting template is provided that is in
line with the existing formatting of the headers/sources.

## Unit Testing

If you are writing unit tests for your project (and you should), you will have
to add them to `target_sources` in the CMakeLists file of the `test/` directory.
A simple test case is provided as an example.

## Continuous Integration

If you host your repository on GitHub, automatic CI actions for building/testing
under Mac and Windows are provided and triggered on every push and PR.

## License

This template is distributed under the ISC license. If you wish to disable the
mandatory JUCE splash screen, you will need to either purchase a commercial
license from JUCE or license your code under the GNU Public License.
