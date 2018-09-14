CC = gcc
CFLAGS = -g -Wall

OperatingSystemsA1 : OperatingSystemsA1.o phones.o persons.o 

OperatingSystemsA1.o phones.o persons.o : OperatingSystemsA1.h phones.h persons.h linkedList.o 

linkedList.o : linkedList.h



clean: 
	rm -f *.o core OperatingSystemsA1