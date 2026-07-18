# base-converter

a modular command-line toolkit written in C for exploring number systems, binary arithmetic, bitwise operations, digital logic concepts, and IEEE
754 floating-point representation.

---

## Overview

The base converter is a collection of utilities that perform common operations involving binary, hexadecimal, octal, Gray code, Binary-Coded Decimal (BCD), complements, and IEEE 754 floating-point numbers.

Each feature is implemented as an independent module, making the project easy to understand, maintain, and extend. Rather than relying solely on built-in library functions, many algorithms are implemented manually to illustrate how computers represent and manipulate data internally.

---

## Features

### Number System Conversions

* Decimal -> Binary
* Binary -> Decimal
* Decimal -> Hexadecimal
* Hexadecimal -> Decimal
* Decimal -> Octal
* Octal -> Decimal

### Binary Arithmetic

* Binary Addition
* Binary Subtraction
* Binary Multiplication

### Bitwise Operations

* Bitwise AND
* Bitwise OR
* Bitwise XOR
* Bitwise NOT
* Left Shift
* Right Shift

### Binary Complements

* 1’s Complement
* 2’s Complement
* Signed Magnitude Representation
* 1’s Complement Representation
* 2’s Complement Representation

### Gray Code

* Binary -> Gray Code
* Gray Code -> Binary

### Binary-Coded Decimal (BCD)

* Decimal -> BCD
* BCD -> Decimal

### IEEE 754 Floating-Point

* Decimal -> IEEE 754 (Single Precision)
* IEEE 754 -> Decimal
* IEEE 754 Bit Breakdown
* Step-by-step IEEE 754 Conversion Explanation
    * Sign Bit
    * Exponent
    * Mantissa
    * Normalization
    * Exponent Bias
    * Final 32-bit Representation

---

## Project Structure

```

base-converter/
  │
  ├── include/
  │   ├── arithmetic.h
  │   ├── bcd.h
  │   ├── bitwise.h
  │   ├── complements.h
  │   ├── conversions.h
  │   ├── graycode.h
  │   ├── ieee754.h
  │   └── utils.h
  │
  ├── src/
  │   ├── arithmetic.c
  │   ├── bcd.c
  │   ├── bitwise.c
  │   ├── complements.c
  │   ├── conversions.c
  │   ├── graycode.c
  │   ├── ieee754.c
  │   ├── utils.c
  │   └── main.c
  │
  ├── Makefile
  ├── README.md
  └── LICENSE

```
---

## File Description

main.c
```
The application’s entry point.

Responsible for:
* Displaying the interactive menu
* Reading user input
* Calling the appropriate module
* Managing the program loop
```

conversions.c
```
Implements conversions between common number systems.

Functions include:
* Decimal <-> Binary
* Decimal <-> Hexadecimal
* Decimal <-> Octal
```

arithmetic.c
```
Implements arithmetic operations performed on binary numbers.

Includes:
* Binary Addition
* Binary Subtraction
* Binary Multiplication
```

bitwise.c
```
Contains implementations of common bitwise operators.

Includes:
* AND
* OR
* XOR
* NOT
* Left Shift
* Right Shift
```

complements.c
```
Implements binary complement operations and signed number representations.

Includes:
* 1’s Complement
* 2’s Complement
* Signed Magnitude
* 1’s Complement Representation
* 2’s Complement Representation
```

graycode.c
```
Handles Gray code conversions.

Includes:
* Binary -> Gray Code
* Gray Code -> Binary
```

bcd.c
```
Implements Binary-Coded Decimal conversions.

Includes:
* Decimal -> BCD
* BCD -> Decimal
```

ieee754.c
```
Implements IEEE 754 single-precision floating-point utilities.

Includes:
* Decimal -> IEEE 754
* IEEE 754 -> Decimal
* Sign, Exponent and Mantissa extraction
* Step-by-step conversion walkthrough
```

utils.c
```
Contains helper functions shared across multiple modules.

Examples include:
* Input validation
* Binary validation
* Hexadecimal validation
* Octal validation
* Binary conversion helpers
* String utility functions
* Console helper functions
```

---

## How It Works

The project follows a modular architecture.

1. The application starts in main.c.
2. A menu is presented to the user.
3. The selected option invokes the corresponding module.
4. Each module performs a specific task independently.
5. Control returns to the main menu after the operation completes.

This separation of responsibilities makes the project easier to maintain and extend.

---

## Build & Run

## Build

Compile the project using the provided Makefile.
```
make
```
Or compile manually.
```
gcc -Wall \
src/main.c \
src/conversions.c \
src/arithmetic.c \
src/bitwise.c \
src/complements.c \
src/graycode.c \
src/bcd.c \
src/ieee754.c \
src/utils.c \
-o toolkit
```

### Run

Using the Makefile:
```
make run
```
Or execute the compiled binary directly.
```
./toolkit
```
