repl:
	cc -std=c99 -Wall \
	src/eval.c \
	src/parser.c \
	src/mpc.c \
	src/repl.c \
	-ledit -lm \
	-o bin/repl
