CC = gcc
CFLAGS = -g -Wall

OperatingSystemsA1 : OperatingSystemsA1.o phones.o persons.o 

OperatingSystemsA1.o phones.o persons.o : OperatingSystemsA1.h phones.h persons.h linkedlist.o 

linkedlist.o : linkedlist.h



clean: 
	rm -f *.o core OperatingSystemsA1