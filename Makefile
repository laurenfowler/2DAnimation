CC = g++ 
GLUT = -lGL -lGLU -lglut
OBJS = display.o circle.o calc_points.o tree.o keyboard_mouse.o pipeline.o matrix_ops.o

run: main.o $(OBJS)
	$(CC) main.o $(OBJS) $(GLUT) 

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

clean:
	rm *.o
	rm a.out
