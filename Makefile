repl:
	cc -std=c99 -Wall \
	src/mpc.c \
	src/repl.c \
	-ledit -lm \
	-o bin/repl
