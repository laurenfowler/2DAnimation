void myglutInit(int argc, char** argv);
void myInit(void);
void display(void);
void sin();
void circle(int radius, int &num_points, struct point center, struct point circ_points[]);
int total_points(int radius, int counter);
void draw_tree(int &num_points, struct point circle_points[], struct point trunk_points[]);
