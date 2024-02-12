# specify all source files here
SRCS = $(shell ls *.c)
# specify target here (name of executable)
TARGETS = $(SRCS:.c=)
# specify compiler, compile flags, and needed libs
CC = gcc
OPTS = -Wall -O
LIBS = -lm

# all is not really needed, but is used to generate the exececutables
#@echo "Generando ejecutables"
#@echo $(TARGETS)
	

all: $(TARGETS)

list_sources: 
	@echo $(SRCS)

# this is a generic rule for executable files
%: %.c
	$(CC) $(OPTS) -o $@ $<

# and finally, a clean line
clean:
	rm -f $(TARGETS)
