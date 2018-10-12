GLUT = -lGL -lGLU -lglut
OBJS = display.o

run: main.o 
	c++ main.o $(GLUT) $(OBJS)

main.o: main.cpp $(OBJS)
	c++ -c main.cpp

display.o: display.cpp
	c++ -c display.cpp

clean:
	rm *.o
	rm a.out
