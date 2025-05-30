# Homework.
Егор Шастин Олегович, gruppa b81-mm
Contact: st129457@student.spbu.ru,egor.shast0.0@gmail.com

# STL-conrainer Project

## Overview

This repository contains a C++ implementation of a custom STL-style container. The container uses a Skip List as an internal data structure. The goal of the project is to create a container that is as compatible with the STL philosophy as possible: full support for iterators, standard concepts and operators, safe error handling, clean and readable code, as well as built-in tests and CI for reliability and quality assurance.

## Table of Contents
- [Installation and Build](#installation-and-build)
- [Tests](#tests)

## Installation and Build

### Building the Project

```sh
make
```

### Running the Decoder
To start the programm, run the compiled executable:

```sh
./bin/Start -d # Running a sample program
```

## Tests

#### Continuous Integration (CI)
This project uses GitHub Actions for automated builds and testing. All tests are run in the CI pipeline on every commit.

#### Running Tests Locally
To run tests, you can use the following commands:

```sh
make test    # Runs tests for all programm
```

