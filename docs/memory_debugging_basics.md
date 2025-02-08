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

In the following visual, the variable `int x = 5` is stored starting at address `0x200009b4`. The debugger shows:

![Memory Debugging](uploaded_file_path_1)

- The memory for `x` spans from `0x200009b4` to `0x200009b7`.
- The value `05 00 00 00` represents `5` in little-endian format.

### Interpreting Memory

The red rectangle in the following visual highlights the memory range occupied by the `int` variable:

![Highlighted Memory](/docs/images/highlighted_memory.jpg)

- Each row represents **32 bytes**.
- The offset guide (orange numbers) helps locate specific addresses within each row.
- The `x` variable's 4 bytes (`05 00 00 00`) are correctly highlighted.

---

## Conclusion

Debugging memory is essential for understanding how your program interacts with the hardware. By using tools like the VSCode Memory Viewer and Watch Pane:
- You can locate variable addresses.
- You can inspect memory values and understand data formats (e.g., little-endian).

This guide should help you get started with memory debugging for STM32F4. Let me know if you need further details or examples!
