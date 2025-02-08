# Memory Debugging Basics for STM32F4

Debugging memory is a crucial aspect of embedded systems development, especially for platforms like the STM32F4 microcontroller. This document will help you understand the basics of memory debugging with examples and visual aids.

## Table of Contents

- [Introduction](#introduction)
- [Key Concepts](#key-concepts)
  - [Memory Layout](#memory-layout)
  - [Variable Storage in Memory](#variable-storage-in-memory)
  - [Little-Endian Representation](#little-endian-representation)
- [Debugging Memory in VSCode](#debugging-memory-in-vscode)
  - [Using the Watch Pane](#using-the-watch-pane)
  - [Using the Memory Viewer](#using-the-memory-viewer)
- [Examples with Visuals](#examples-with-visuals)
  - [Memory Locations for Variables](#memory-locations-for-variables)
  - [Interpreting Memory](#interpreting-memory)
- [Conclusion](#conclusion)

---

## Introduction

Memory debugging involves inspecting and analyzing how variables are stored, how memory is allocated, and how the program interacts with the memory space. In this guide, we focus on:
- Understanding how variables are stored in memory.
- Using debugging tools like **VSCode** to view memory and variable information.
- Interpreting memory content.

This guide is tailored for developers working on **STM32F4** microcontrollers.

---

## Key Concepts

### Memory Layout

In embedded systems like STM32F4, memory is divided into specific regions such as:
- **RAM**: For runtime variable storage.
- **Flash**: For program code.
- **Peripheral Registers**: For direct control of hardware peripherals.

The **RAM** region stores variables and stack information. Each variable occupies a specific number of bytes, depending on its data type.

### Variable Storage in Memory

Each variable is stored at a specific **address** in memory. For example, an `int` variable (4 bytes) stored at address `0x200009b4` will occupy:
- **0x200009b4**
- **0x200009b5**
- **0x200009b6**
- **0x200009b7**

### Little-Endian Representation

STM32F4 uses **little-endian** format, meaning:
- The **least significant byte** is stored at the **lowest memory address**.

For example, if an `int x = 5` is stored in memory:
- The value `5` (0x00000005 in hex) is stored as: `05 00 00 00`.

---

## Debugging Memory in VSCode

### Using the Watch Pane

The Watch Pane displays:
- The **values** of variables.
- The **addresses** where variables are stored.

Example:
If `int x = 5` and it is stored at `0x200009b4`, the Watch Pane will show:
```
x: 5 (address: 0x200009b4)
```

### Using the Memory Viewer

The Memory Viewer displays:
- The raw **memory content**.
- The corresponding **ASCII representation** (if printable).

Example:
At address `0x200009b4`, if `int x = 5`, the memory view will show:
```
00000000200009b4: 05 00 00 00
```

---

## Examples with Visuals

### Memory Locations for Variables

In the source code from **Project001**, the variables `x`, `y`, and `z` are defined and manipulated. According to the Watch Pane in the debugging session, their memory locations and initial values are as follows:

#### Variable `x`
- **Address**: `0x200009b4`
- **Initial Value**: `5 (0x05)`

![Variable x](/docs/images/001/varX.jpg)

#### Variable `y`
- **Address**: `0x200009b8`
- **Initial Value**: `7 (0x07)`

![Variable y](/docs/images/001/varY.jpg)

#### Variable `z`
- **Address**: `0x20000a18`
- **Initial Value**: `0 (0x00)`

![Variable z](/docs/images/001/varZ.jpg)

### Changing Values in Memory

After stepping into the next line in the code (`z = x + y`), the value of `z` updates to the result of the addition:

#### New Value of `z`
- **Address**: `0x20000a18`
- **Updated Value**: `12 (0x0C)`

![Updated Variable z](/docs/images/001/varZ_newvalue.jpg)

This demonstrates how the memory content changes dynamically as the program executes.

---

## Conclusion

Debugging memory is essential for understanding how your program interacts with the hardware. By using tools like the VSCode Memory Viewer and Watch Pane:
- You can locate variable addresses.
- You can inspect memory values and understand data formats (e.g., little-endian).
