compile: bin
	cc -Wall \
	src/eval.c \
	src/parser.c \
	src/mpc.c \
	src/repl.c \
	-ledit -lm \
	-o bin/lambo

bin:
	mkdir -p bin
