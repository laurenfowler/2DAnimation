#ifndef STRUCT_H
#define STRUCT_H
typedef struct point{
	int x, y, w;
} point;

typedef struct vertex{
	float x, y;
}vertex;

typedef struct triangles{
	std::vector <int> p1, p2, p3;
}tri;
#endif 
