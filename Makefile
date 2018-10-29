GLUT = -lGL -lGLU -lglut
OBJS = display.o circle.o calc_points.o tree.o

run: main.o $(OBJS)
	c++ main.o $(GLUT) $(OBJS)

main.o: main.cpp 
	c++ -c main.cpp

display.o: display.cpp
	c++ -c display.cpp

circle.o: circle.cpp
	c++ -c circle.cpp

calc_points.o: calc_points.cpp
	c++ -c calc_points.cpp

tree.o: tree.cpp
	c++ -c tree.cpp

clean:
	rm *.o
	rm a.out
