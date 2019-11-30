# List of all the board related files.
BOARDSRC = ./STM32F401C_BLACKPILL/board.c

# Required include directories
BOARDINC = ./STM32F401C_BLACKPILL

# Shared variables
ALLCSRC += $(BOARDSRC)
ALLINC  += $(BOARDINC)
