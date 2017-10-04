bin=bin/hotwire
libs=-lsfml-graphics -lsfml-window -lsfml-system -lsfgui
objs=$(patsubst src/%.cpp,obj/%.o,$(wildcard src/*.cpp))
flags=-g

all: bin obj $(bin)

bin:
	mkdir bin

obj:
	mkdir obj

$(bin): $(objs)
	g++ $(objs) $(libs) -o $@

obj/main.o: src/main.cpp obj/hotwire.o 
	g++ -c $(flags) $< -Iinclude/ -o $@

obj/texture_manager.o: src/texture_manager.cpp include/texture_manager.h
	g++ -c $(flags) $< -Iinclude/ -o $@

obj/hotwire.o: src/hotwire.cpp include/hotwire.h obj/texture_manager.o
	g++ -c $(flags) $< -Iinclude/ -o $@

clear:
	-rm $(bin) $(objs)
