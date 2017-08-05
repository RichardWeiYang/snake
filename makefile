SOURCES := $(wildcard *.c)
OBJS := $(subst .c,.o,$(SOURCES))
PROGRAM := snake

.PHONY: all clean
all: $(PROGRAM)

%.o: %.c
	gcc -Wall -c $< -o $@

$(PROGRAM): $(OBJS)
	gcc -Wall $^ -o $@ -lncurses -lm

clean:
	rm -f $(PROGRAM) $(OBJS)
