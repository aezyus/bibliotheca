CC	:=	gcc
CFLAGS	:=	-std=c11 -Wextra -Wall -Werror -Wpedantic -g -I include
LDFLAGS	:=

BIN	:=	bibtec
SRC	:=	$(wildcard src/*.c)
OBJ :=	$(SRC:src/%.c=build/obj/%.o)
DEP :=	$(OBJ:.o=.d)

all	:	$(BIN)

$(BIN)	:	$(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@

build/obj/%.o:	src/%.c	| build/obj
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

build/obj:
	mkdir -p build/obj

-include $(DEP)


clean:
	rm -rf build $(BIN)

docs:
	doxygen Doxyfile


.PHONY:	all clean docs
