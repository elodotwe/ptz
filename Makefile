ptz.o: ptz.c
	gcc -c $^

clean:
	rm *.o

ptz_tests.o: ptz_tests.c
	gcc -c $^

test: ptz_tests.o ptz.o
	gcc -o test $^
