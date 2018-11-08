CC = g++ 
GLUT = -lGL -lGLU -lglut
OBJS = display.o circle.o calc_points.o tree.o keyboard_mouse.o pipeline.o matrix_ops.o clipper.o tesselation.o

run: main.o $(OBJS)
	$(CC) main.o $(OBJS) $(GLUT) math/libmath.a

math:
	cd math && $(MAKE)

main.o: main.cpp  
	$(CC) -c main.cpp

display.o: display.cpp
	$(CC) -c display.cpp

circle.o: circle.cpp
	$(CC) -c circle.cpp

calc_points.o: calc_points.cpp
	$(CC) -c calc_points.cpp

keyboard_mouse.o: keyboard_mouse.cpp
	$(CC) -c keyboard_mouse.cpp

tree.o: tree.cpp
	$(CC) -c tree.cpp

pipeline.o: pipeline.cpp
	$(CC) -c pipeline.cpp

matrix_ops.o: matrix_ops.cpp
	$(CC) -c matrix_ops.cpp

clipper.o: clipper.cc
	$(CC) -c clipper.cc

tesselation.o: tesselation.cpp
	$(CC) -c tesselation.cpp

clean:
	rm *.o
	rm a.out

pristine:
	rm *.o
	rm a.out
	cd math && $(MAKE) pristine
	
