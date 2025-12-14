CC = gcc
SRC_DIR = source_code
INC_DIR = all_headers
CFLAGS = -Wall -g -I$(INC_DIR)

OBJS = gamemain.o variables.o movement.o renderfns.o isitfns.o criticalscenarios.o sidenotes.o

Target = chessgame

all: $(Target)

$(Target): $(OBJS)
	$(CC) $(CFLAGS) -o $(Target) $(OBJS)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	del *.o $(Target).exe