################################################################################
# Makefile for STM32F407 Project in VSCode
################################################################################

# Toolchain
CC       = arm-none-eabi-gcc
OBJCOPY  = arm-none-eabi-objcopy
OBJDUMP  = arm-none-eabi-objdump
SIZE     = arm-none-eabi-size

# Project Name
PROJECT  = firmware

# Linker Script
LDSCRIPT = STM32F407VGTX_FLASH.ld

# Source Directories
SRC_DIRS = Src Startup

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

# Compiler Flags
CFLAGS   = -mcpu=cortex-m4 -std=gnu11 -g3 -O0 -Wall -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -ffunction-sections -fdata-sections -fstack-usage --specs=nano.specs -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb
CFLAGS  += $(INCLUDES)

# Linker Flags
LDFLAGS  = -T $(LDSCRIPT) -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb

# Output directory
OUTDIR = ../build

# Convert source files to object files (preserving directory structure)
COBJS = $(C_SOURCES:%.c=$(OUTDIR)/%.o)
AOBJS = $(ASM_SOURCES:%.s=$(OUTDIR)/%.o)
OBJS  = $(COBJS) $(AOBJS)

# Ensure build subdirectories exist
$(shell mkdir -p $(OUTDIR)/Src $(OUTDIR)/Startup)

# Targets
all: $(OUTDIR)/$(PROJECT).elf

# Link .o files to create .elf file
$(OUTDIR)/$(PROJECT).elf: $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^
	@echo "Linked $^ to create $@"

# Compile C source files (preserving subdirectories)
$(OUTDIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble .s files (preserving subdirectories)
$(OUTDIR)/%.o: %.s
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Create HEX file
hex: $(OUTDIR)/$(PROJECT).elf
	$(OBJCOPY) -O ihex $< $(OUTDIR)/$(PROJECT).hex
	@echo "Generated HEX file: $(OUTDIR)/$(PROJECT).hex"

# Create BIN file
bin: $(OUTDIR)/$(PROJECT).elf
	$(OBJCOPY) -O binary $< $(OUTDIR)/$(PROJECT).bin
	@echo "Generated BIN file: $(OUTDIR)/$(PROJECT).bin"

# Show binary size
size: $(OUTDIR)/$(PROJECT).elf
	$(SIZE) $<

# Clean up build files
clean:
	rm -rf $(OUTDIR)
	@echo "Cleaned project files."

.PHONY: all clean hex bin size
