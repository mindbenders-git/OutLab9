
MKDIR_P = mkdir -p
OUT_DIR = ./build
EXEC = ../client

.PHONY: directories clean run

all: directories $(EXEC)

directories: ${OUT_DIR}

${OUT_DIR}:
	${MKDIR_P} ${OUT_DIR}	

arg1 = localhost
arg2 = 45000
arg3 = 300

ifeq ($(PORT_CLIENT),)
	PORT_CLIENT := $(arg2)
endif

ifeq ($(NUM_CLIENTS),)
	NUM_CLIENTS := $(arg3)
endif
	
CC = gcc
CFLAGS = -g -pthread -Wall

varA = ./build/cl_task.o
varB = ./build/cl_utils.o
varC = ./build/mt_client.o


$(EXEC): $(varA) $(varB) $(varC)
	$(CC) $(CFLAGS) $(varA) $(varB) $(varC) -o $(EXEC)
	
$(varA): cl_task.c cl_task.h cl_utils.h
	$(CC) -c cl_task.c -o $(varA)
	
$(varB): cl_utils.c cl_utils.h
	$(CC) -c cl_utils.c -o $(varB)
	
$(varC): mt_client.c cl_task.h cl_utils.h
	$(CC) -c mt_client.c -o $(varC)
	
	
run:
	$(EXEC) $(arg1) $(PORT_CLIENT) $(NUM_CLIENTS)
	
clean:
	@$(RM) -rf $(EXEC)
	@$(RM) -rf $(OUT_DIR)
