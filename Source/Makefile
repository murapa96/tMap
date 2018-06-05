OBJECTS = main.o tTile.o tMap.o tSala.o

comp: main clear
	./pruv
main: $(OBJECTS)
	g++ $(OBJECTS) -o pruv  -lraylib -lglfw -lGL -lopenal -lm -lpthread -ldl -lX11 -lXrandr -lXinerama -lXi -lXxf86vm -lXcursor
main.o: main.cpp
	g++ "main.cpp" -c

tTile.o:
	g++ "Lib/tTile.cpp" -c
tMap.o:
	g++ "Lib/tMap.cpp" -c
tSala.o:	
	g++ "Lib/tSala.cpp" -c

clear:
	rm *.o
