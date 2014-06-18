# This is the Makefile for Doinakra, an Arkanoid clone, done in SFML 2.1

CC = g++
IDIR = ../include/
CFLAGS = -std=c++1y -Wall -Wextra -pedantic -O2
IFLAGS = -I$(IDIR)
LFLAGS = -lsfml-graphics -lsfml-system -lsfml-window

OBJECTS = Ball.o Brick.o Game.o main.o Player.o Window.o

all : Doinakra.bin

Doinakra.bin : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@ $(LFLAGS)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< $(IFLAGS) $(LFLAGS)

clean :
	rm *.o Doinakra.bin
