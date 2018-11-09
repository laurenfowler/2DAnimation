CC = g++ 
CFLAGS = -g
GLUT = -lGL -lGLU -lglut
OBJS = display.o circle.o calc_points.o tree.o keyboard_mouse.o pipeline.o matrix_ops.o clipper.o tesselation.o

run: main.o $(OBJS)
	$(CC) -g  main.o $(OBJS) $(GLUT) math/libmath.a

math:
	cd math && $(MAKE)

main.o: main.cpp  
	$(CC) $(CFLAGS) -c main.cpp

display.o: display.cpp
	$(CC) $(CFLAGS) -c display.cpp

circle.o: circle.cpp
	$(CC) $(CFLAGS) -c circle.cpp

calc_points.o: calc_points.cpp
	$(CC) $(CFLAGS) -c calc_points.cpp

keyboard_mouse.o: keyboard_mouse.cpp
	$(CC) $(CFLAGS) -c keyboard_mouse.cpp

tree.o: tree.cpp
	$(CC) $(CFLAGS) -c tree.cpp

pipeline.o: pipeline.cpp
	$(CC) $(CFLAGS) -c pipeline.cpp

matrix_ops.o: matrix_ops.cpp
	$(CC) $(CFLAGS) -c matrix_ops.cpp

clipper.o: clipper.cc
	$(CC) $(CFLAGS) -c clipper.cc

tesselation.o: tesselation.cpp
	$(CC) $(CFLAGS) -c tesselation.cpp

clean:
	rm *.o
	rm a.out

pristine:
	rm *.o
	rm a.out
	cd math && $(MAKE) pristine
	
