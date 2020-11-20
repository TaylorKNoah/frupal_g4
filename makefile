# Carl Knori -- 11/16/2020 -- CS300:Frupal:Group 4
# This makefile will ideally compile the whole program

CC=g++
CFLAGS=-Wall -Werror -g
OBJECTS=frupal_main.o game.o menu.o map.o player.o item.o interactables.o \
	entity.o

frupal: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o frupal

# I am unsure what exactly our file containing main will actually include. This
# was not outlined in our diagram.
frupal_main.o: frupal_main.cpp game.h menu.h map.h player.h item.h \
	interactables.h entity.h
	$(CC) $(CFLAGS) frupal_main.cpp -c

game.o: game.cpp game.h menu.h map.h player.h
	$(CC) $(CFLAGS) game.cpp -c

menu.o: menu.cpp menu.h map.h
	$(CC) $(CFLAGS) menu.cpp -c

map.o: map.cpp map.h player.h entity.h
	$(CC) $(CFLAGS) map.cpp -c

player.o: player.cpp player.h item.h entity.h
	$(CC) $(CFLAGS) player.cpp -c

item.o: item.cpp item.h interactables.h entity.h
	$(CC) $(CFLAGS) item.cpp -c

interactables.o: interactables.cpp interactables.h entity.h
	$(CC) $(CFLAGS) interactables.cpp -c

entity.o: entity.cpp entity.h
	$(CC) $(CFLAGS) entity.cpp -c

clean:
	rm *.o *.plist frupal
