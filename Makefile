GLUT = -lGL -lGLU -lglut
OBJS = display.o circle.o calc_points.o draw_tree.o

run: main.o 
	c++ main.o $(GLUT) $(OBJS)

main.o: main.cpp $(OBJS)
	c++ -c main.cpp

display.o: display.cpp
	c++ -c display.cpp

circle.o: circle.cpp
	c++ -c circle.cpp

calc_points.o: calc_points.cpp
	c++ -c calc_points.cpp

draw_tree.o: draw_tree.cpp
	c++ -c draw_tree.cpp

clean:
	rm *.o
	rm a.out
