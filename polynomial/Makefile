# creates the exucutable program polyapp
polyapp: utils.o poly.o polyapp.o
	gcc -o polyapp utils.o poly.o polyapp.o

utils.o: utils.c utils.h
	gcc -c utils.c

poly.o: poly.c poly.h utils.h
	gcc -c poly.c

polyapp.o: polyapp.c poly.h utils.h
	gcc -c polyapp.c

# target for cleaning up the build artifacts
clean:
	rm -f *.o *~ polyapp
