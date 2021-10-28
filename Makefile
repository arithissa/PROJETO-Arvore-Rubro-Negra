objects =   warmup.o main.o

all :   $(objects)
	gcc -o  alg $(objects)

run :   alg
	./alg

warmup.o :   warmup.h
main.o  :   warmup.h

clean   :
	rm *.o alg
