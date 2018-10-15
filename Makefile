GLUT = -lGL -lGLU -lglut
OBJS = display.o circle.o

run: main.o 
	c++ main.o $(GLUT) $(OBJS)

main.o: main.cpp $(OBJS)
	c++ -c main.cpp

display.o: display.cpp
	c++ -c display.cpp

circle.o: circle.cpp
	c++ -c circle.cpp

clean:
	rm *.o
	rm a.out
