all:
	g++ -Iinclude -Llib -o main src/*.cpp -lmingw32 -lSDL2main -lSDL2 -lSDL2_image