
MKDIR_P = mkdir -p
OUT_DIR = ./build
EXEC = ../server

.PHONY: directories clean run

all: directories $(EXEC)

directories: ${OUT_DIR}

${OUT_DIR}:
	${MKDIR_P} ${OUT_DIR}	

arg1 = 45000
ifeq ($(PORT_SERVER),)
	PORT_SERVER := $(arg1)
endif

CC = gcc
CFLAGS = -g -pthread -Wextra

varA = ./build/sv_task.o
varB = ./build/sv_utils.o
varC = ./build/mt_server.o


$(EXEC): $(varA) $(varB) $(varC)
	$(CC) $(CFLAGS) $(varA) $(varB) $(varC) -o $(EXEC)
	
$(varA): sv_task.c sv_task.h sv_utils.h
	$(CC) -c sv_task.c -o $(varA)
	
$(varB): sv_utils.c sv_utils.h
	$(CC) -c sv_utils.c -o $(varB)
	
$(varC): mt_server.c sv_task.h sv_utils.h
	$(CC) -c mt_server.c -o $(varC)

run:
	$(EXEC) $(PORT_SERVER)
	
clean:
	@$(RM) -rf $(EXEC)
	@$(RM) -rf $(OUT_DIR)
