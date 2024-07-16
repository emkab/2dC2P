all:
	g++ -Iinclude -Llib -o 2dC2P ico.res src/*.cpp -lmingw32 -mwindows -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf