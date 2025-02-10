CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lncurses

SRCS = main.c

TARGET = snake

OBJS = $(SRCS:.C=.O)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

clean:
	rm -f *.o $(TARGET)

run:
	./$(TARGET)