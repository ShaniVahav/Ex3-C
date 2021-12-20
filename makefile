CC=gcc
AR=ar
FLAGS= -g -Wall

all: stringProg
lib: libClass.a

# crate main:
stringProg: main.o libClass.a
	$(CC) $(FLAGS) main.o -o stringProg libClass.a

main.o: main.c
	$(CC) $(FLAGS) -c main.c

# create library
libClass.a: gematria.o atbash.o anagram.o
	$(AR) -rcs libClass.a gematria.o atbash.o anagram.o 

gematria.o: gematria.c
	$(CC) $(FLAGS) -c gematria.c

atbash.o: atbash.c
	$(CC) $(FLAGS) -c atbash.c

anagram.o: anagram.c
	$(CC) $(FLAGS) -c anagram.c

.PHONY: clean all

clean:
	rm -f *.a *.o stringProg