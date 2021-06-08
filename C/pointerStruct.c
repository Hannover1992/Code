typedef struct {
	int x, y;
} Point;

Point make_point(int x, int y){
	Point p = {x, y};
	return p;
}
