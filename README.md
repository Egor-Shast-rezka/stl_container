# Homework.
Егор Шастин Олегович, gruppa b81-mm
Contact: st129457@student.spbu.ru,egor.shast0.0@gmail.com

# STL-conrainer Project

## Overview

This C++ code implements a circular linked list, a dynamic data structure where elements are linked in a circular fashion. It provides functionalities for adding, removing, accessing, and manipulating elements, including iterators for traversal and standard container operations.

## Table of Contents
- [Installation and Build](#installation-and-build)
- [Tests](#tests)
- [Doxygen](#doxygen)

## Installation and Build

### Building the Project

```sh
make
```

### Running the Decoder
To start the programm, run the compiled executable:

```sh
./bin/Start # Running a sample program
```

## Tests

#### Continuous Integration (CI)
This project uses GitHub Actions for automated builds and testing. All tests are run in the CI pipeline on every commit.

#### Running Tests Locally
To run tests, you can use the following commands:

```sh
make test    # Runs tests for all programm
```

## Doxygen
This project uses Doxygen to generate developer-friendly documentation from annotated C++ source code.
To generate the documentation locally:

```sh
cd doc
doxygen Doxyfile    # Creating documentation
```
