################################################################################
# Makefile for STM32F407 Project in VSCode
################################################################################

# Toolchain
CC       = arm-none-eabi-gcc
OBJCOPY  = arm-none-eabi-objcopy
OBJDUMP  = arm-none-eabi-objdump
SIZE     = arm-none-eabi-size

# Project Name
PROJECT  = 001Add

# Linker Script
LDSCRIPT = STM32F407VGTX_FLASH.ld

# C Source Files
C_SOURCES = \
    Src/main.c \
    Src/syscalls.c \
    Src/sysmem.c

# Assembly Source Files
ASM_SOURCES = \
    Startup/startup_stm32f407vgtx.s

# Include Directories
INCLUDES = \
    -IInc \
    -I/home/parallels/STM32CubeF4/Drivers/CMSIS/Include \
    -I/home/parallels/STM32CubeF4/Drivers/CMSIS/Device/ST/STM32F4xx/Include \
    -I/home/parallels/STM32CubeF4/Drivers/STM32F4xx_HAL_Driver/Inc

# Compiler Flags (Ensuring Floating-Point Consistency)
# CFLAGS: Compiler flags for the project
# -mcpu=cortex-m4: Specifies the target CPU architecture (Cortex-M4)
# -mthumb: Generates code for the Thumb instruction set
# -g: Includes debugging information in the output
# -O2: Optimizes the code for performance
# -std=c11: Uses the C11 standard for compiling C code
# -Wall: Enables all compiler's warning messages
# -DSTM32F407xx: Defines the macro STM32F407xx for conditional compilation
# -mfloat-abi=hard: Uses hardware floating-point instructions
# -mfpu=fpv4-sp-d16: Specifies the floating-point unit (FPU) type (single-precision, 16 registers)
CFLAGS = -mcpu=cortex-m4 -mthumb -g -O2 -std=c11 -Wall -DSTM32F407xx \
         -mfloat-abi=hard -mfpu=fpv4-sp-d16
CFLAGS  += $(INCLUDES)

# Linker Flags (Ensuring Floating-Point Consistency)
LDFLAGS = -T$(LDSCRIPT) -Wl,-Map=$(PROJECT).map -Wl,--gc-sections \
          -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 \
          -Wl,--start-group -lc -lm -Wl,--end-group

# Convert source files to object files
COBJS = $(C_SOURCES:.c=.o)
AOBJS = $(ASM_SOURCES:.s=.o)
OBJS  = $(COBJS) $(AOBJS)

# Targets
all: $(PROJECT).elf

# Link .o files to create .elf file
$(PROJECT).elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	@echo "Linked $^ to create $@"

# Compile C source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble .s files
%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

# Create HEX file
hex: $(PROJECT).elf
	$(OBJCOPY) -O ihex $< $(PROJECT).hex
	@echo "Generated HEX file: $(PROJECT).hex"

# Create BIN file
bin: $(PROJECT).elf
	$(OBJCOPY) -O binary $< $(PROJECT).bin
	@echo "Generated BIN file: $(PROJECT).bin"

# Show binary size
size: $(PROJECT).elf
	$(SIZE) $<

# Clean up build files
clean:
	rm -f $(COBJS) $(AOBJS) $(PROJECT).elf \
	      $(PROJECT).hex $(PROJECT).bin $(PROJECT).map
	@echo "Cleaned project files."

.PHONY: all clean hex bin size