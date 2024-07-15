all:
	gcc -Iinclude -Llib -o main src/*.cpp -lstdc++ `sdl2-config --cflags --libs` -lm