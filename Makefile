CFLAGS=-ggdb

ptz.o: ptz.c
	gcc $(CFLAGS) -c $^

clean:
	rm *.o

ptz_tests.o: ptz_tests.c
	gcc $(CFLAGS) -c $^

test: ptz_tests.o ptz.o
	gcc $(CFLAGS) -o test $^
