CC = g++ 
GLUT = -lGL -lGLU -lglut
OBJS = display.o circle.o calc_points.o tree.o

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

#draw_tree.o: draw_tree.cpp
#	$(CC) -c draw_tree.cpp

tree.o: tree.cpp
	$(CC) -c tree.cpp

clean:
	rm *.o
	rm a.out
