$(CC) = gcc
CFLAGS = -g -Wall -O2 -lm

# Include subfolders
INC_SRC = -Isrc

# File definitions
SRC  = src/data_structures.c
OBJ  = $(patsubst %.c, %.o, $(SRC))
MAIN = src/main.c

# Path to current working directory
CURWORKDIR =$(PWD)

# Binaries
FEMESH_BIN = bin/FEMESH


# Make routine
all: $(FEMESH_BIN)
	@echo  "\n------------------------------------"
	@echo  "|     Compilation successfull!     |"
	@echo  "------------------------------------\n"

$(OBJ): $(SRC)
	@echo  "\n------------------------------------"
	@echo  "|     Creating .o files...         |"
	@echo  "------------------------------------\n"
	$(CC) $(CFLAGS) $(INC_SRC) -c src/data_structures.c -o src/data_structures.o

$(FEMESH_BIN): $(MAIN) $(OBJ)
	@echo  "\n------------------------------------"
	@echo  "|     Creating binaries...         |"
	@echo  "------------------------------------\n"
	$(CC) $(CFLAGS) -DCURWORKDIR='"$(CURWORKDIR)"' $(INC_SRC) $^ -lm -o $@


