# This is the Makefile for Doinakra, an Arkanoid clone, done in SFML 2.1

CC = g++
IDIR = ../include/
CFLAGS = -std=c++1y -Wall -Wextra -pedantic
IFLAGS = -I$(IDIR)
LFLAGS = -lsfml-graphics -lsfml-system -lsfml-window

TARGET = Doinakra.bin
OBJECTS = Ball.o Brick.o Game.o main.o Player.o Window.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -O2 $(OBJECTS) -o $@ $(LFLAGS)

debug : $(OBJECTS)
	$(CC) -g $(CFLAGS) $(OBJECTS) -o $(TARGET).debug $(LFLAGS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< $(IFLAGS) $(LFLAGS)

clean :
	rm *.o $(TARGET)*
