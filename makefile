CC = gcc
CFLAGS = -Wall -Wextra -g

SRC = main.c src/app.c src/utils/*.c src/ui/*.c src/ui/components/*.c src/ui/pages/*.c
OUT = build/main.out

all:
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(OUT) `pkg-config --cflags --libs gtk4`

run: all
	./$(OUT)

clean:
	rm -rf build