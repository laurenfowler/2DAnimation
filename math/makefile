all: lib

dot.o: dot.c
	gcc -c dot.c

intersect.o: intersect.cpp
	c++ -c intersect.cpp

cp.o: cp.cpp
	c++ -c cp.cpp

angle_check.o: angle_check.cpp
	c++ -c angle_check.cpp

triangle_are2D.o: triangle_area2D.cpp
	c++ -c triangle_area2D.cpp

lib: dot.o intersect.o cp.o angle_check.o triangle_area2D.o
	ar -rc libmath.a dot.o intersect.o cp.o angle_check.o triangle_area2D.o
	ranlib libmath.a

#Default targets for cleaning up enviroment

clean:
	rm *.o
	touch *.c

pristine:
	make clean
	rm *.a
