CC = gcc
objects = tensor_glvm.o fun.o
out = tensor_glvm.out
mult: $(objects)
	$(CC) -o tensor $(objects) -lrt

tensor_glvm.o: fun.h

fun.o: fun.h

clean:
	rm $(objects) tensor

cleanAll:
	rm $(objects) $(out) tensor