# the compiler to use.
CC=g++
# CFLAGS will be the
# options I'll pass to the compiler.
# -c compile and assemble but do not link
CFLAGS=-c -g -xc++ \
		-fno-common \
		-Wall \
		-Wextra \
		-Wformat=2 \
		-Winit-self \
		-Winline \
		-Wpacked \
		-Wp,-D_FORTIFY_SOURCE=2 \
		-Wpointer-arith \
		-Wlarger-than-65500 \
		-Wmissing-declarations \
		-Wmissing-format-attribute \
		-Wmissing-noreturn \
		-Wredundant-decls \
		-Wsign-compare \
		-Wstrict-aliasing=2 \
		-Wswitch-enum \
		-Wundef \
		-Wunreachable-code \
		-Wunsafe-loop-optimizations \
		-Wwrite-strings \
		-Wuninitialized \
		-Weffc++

TARGETS= Main.o
		

all: Main

main: $(TARGETS)
	$(CC) $(TARGETS) -o Main

%.o: %.cpp
	$(CC) $(CFLAGS) $<

%.o: %.cc
	$(CC) $(CFLAGS) $<

clean:
	rm -rf *.o Main


