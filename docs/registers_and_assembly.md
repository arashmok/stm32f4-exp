# Understanding Registers and Assembly Instructions in STM32F4

This document explains how registers interact with memory and variables, providing insights into their role in assembly-level operations. The examples focus on an STM32F4 microcontroller and a simple program where variables are manipulated.

## Table of Contents

- [Introduction](#introduction)
- [Registers Overview](#registers-overview)
  - [General-Purpose Registers (R0–R12)](#general-purpose-registers-r0-r12)
  - [Special Registers](#special-registers)
    - [Stack Pointer (SP)](#stack-pointer-sp)
    - [Link Register (LR)](#link-register-lr)
    - [Program Counter (PC)](#program-counter-pc)
    - [Program Status Register (xPSR)](#program-status-register-xpsr)
- [Assembly Instructions](#assembly-instructions)
  - [Annotated Example Code](#annotated-example-code)
  - [Step-by-Step Execution](#step-by-step-execution)
- [Conclusion](#conclusion)

---

## Introduction

Registers are small, fast storage locations within the CPU that temporarily hold data, addresses, or instructions during program execution. They are critical for efficient processing, reducing the need for frequent memory access. This guide explores their role in a practical example.

---

## Registers Overview

### General-Purpose Registers (R0–R12)
- These registers are used for temporary storage, function arguments, and intermediate results.
- For example:
  - **R0–R3**: Commonly used to pass arguments to functions or hold temporary results.
  - **R4–R12**: Available for general-purpose usage.

### Special Registers

#### Stack Pointer (SP)
- **SP (e.g., 0x2001fff8)**: Points to the current top of the stack in memory.
- The stack stores local variables, return addresses, and function call information.

#### Link Register (LR)
- **LR (e.g., 0x80075c7)**: Stores the return address when a function is called.
- After the function completes, the CPU jumps back to this address.

#### Program Counter (PC)
- **PC (e.g., 0x80072ea)**: Holds the address of the next instruction to execute.
- The CPU fetches instructions sequentially from the address stored in the PC.

#### Program Status Register (xPSR)
- **xPSR (e.g., 0x61000000)**: Contains flags and system state information, such as:
  - **Zero flag**: Indicates the result of the last operation was zero.
  - **Negative flag**: Indicates a negative result.

The following image shows the registers and their values during a debugging session:

![Registers Debug View](/docs/images/001/registers.jpg)

---

## Assembly Instructions

This section explains how assembly instructions manipulate registers and memory during program execution.

### Annotated Example Code
Below is the assembly code for a simple operation (`z = x + y`):

```
0x080072dc <main+4>:    ldr r3, [pc, #28]   ; Load value of x (5) into r3
0x080072e0 <main+6>:    ldr r2, [r3, #0]    ; Load value of y (7) into r2
0x080072e4 <main+8>:    add r3, r2          ; Add r2 (y) to r3 (x), store result in r3
0x080072e8 <main+16>:   str r3, [r2, #0]    ; Store result (12) into z
```

The following image shows the corresponding assembly instructions during the debugging session:

![Assembly Instructions](/docs/images/001/assembly.jpg)

### Step-by-Step Execution

#### Initial Conditions
- **Memory**:
  - `x`: Stored at `0x200009b4`, value `5`.
  - `y`: Stored at `0x200009b8`, value `7`.
  - `z`: Stored at `0x20000a18`, value `0`.
- **Registers**:
  - `R2`: Points to `z`'s address (`0x20000a18`).
  - `R3`: Temporarily holds values during operations.

#### Execution Flow
1. **Load x**:
   - Instruction: `ldr r3, [pc, #28]`
   - Action: Load the value of `x` (`5`) into `R3`.
   - Result: `R3 = 5`.

2. **Load y**:
   - Instruction: `ldr r2, [r3, #0]`
   - Action: Load the value of `y` (`7`) into `R2`.
   - Result: `R2 = 7`.

3. **Perform Addition**:
   - Instruction: `add r3, r2`
   - Action: Add `R2` (7) to `R3` (5).
   - Result: `R3 = 12`.

4. **Store Result**:
   - Instruction: `str r3, [r2, #0]`
   - Action: Store the value of `R3` (12) into the memory address of `z`.
   - Result: Memory at `0x20000a18` contains `0x0C`.

---

## Conclusion

Registers play a critical role in efficient program execution by:
- Temporarily holding data for operations.
- Providing addresses for memory access.
- Controlling program flow via the PC, SP, and LR.

Understanding assembly instructions and their interaction with registers helps you debug and optimize embedded systems effectively!
