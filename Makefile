OBJS = World.o skydrumskibe.o Spaceship.o Bullet.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) -std=c++11
LFLAGS = -Wall $(DEBUG) -lsfml-graphics -lsfml-window -lsfml-system

skydrumskibe : $(OBJS)
	$(CC) $(OBJS) -o skydrumskibe $(LFLAGS)

skydrumskibe.o : skydrumskibe.cpp World.hpp
	$(CC) $(CFLAGS) skydrumskibe.cpp

World.o : World.cpp World.hpp Spaceship.cpp Spaceship.hpp
	$(CC) $(CFLAGS) World.cpp

Spaceship.o: Spaceship.hpp Spaceship.cpp
	$(CC) $(CFLAGS) Spaceship.cpp

Bullet.o: Bullet.hpp Bullet.cpp
	$(CC) $(CFLAGS) Bullet.cpp

clean_all:
	\rm *.o *~ skydrumskibe

clean:
	\rm *.o

tar:
	tar cfv p1.tar Movie.h Movie.cpp Name.h Name.cpp NameList.h \
            NameList.cpp  Iterator.cpp Iterator.h
