# Carl Knori -- 11/16/2020 -- CS300:Frupal:Group 4
# This makefile will ideally compile the whole program

CC=g++
CFLAGS=-Wall -Werror -g
OBJECTS=frupal_main.o game.o menu.o map.o player.o item.o entity.o

frupal: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o frupal

frupal_main.o: frupal_main.cpp game.o
	$(CC) $(CFLAGS) frupal_main.cpp -c

game.o: game.cpp game.h menu.o
	$(CC) $(CFLAGS) game.cpp -c

menu.o: menu.cpp menu.h map.o
	$(CC) $(CFLAGS) menu.cpp -c

map.o: map.cpp map.h player.o
	$(CC) $(CFLAGS) map.cpp -c

player.o: player.cpp player.h item.o
	$(CC) $(CFLAGS) player.cpp -c

item.o: item.cpp item.h entity.o
	$(CC) $(CFLAGS) item.cpp -c

entity.o: entity.cpp entity.h
	$(CC) $(CFLAGS) entity.cpp -c

clean:
	rm *.o *.plist frupal
