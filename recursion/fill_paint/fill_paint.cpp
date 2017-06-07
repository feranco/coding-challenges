#include <iostream>
#include <string>

using namespace std;

struct Image {
	int size_x, size_y;
	int** grid;
	Image(int x, int y): size_x(x), size_y(y) {
		*grid = new int[size_y];//rows
		for (int i = 0; i < size_x; ++i) 
			grid[i] = new int[size_x];//cols
	}
};

struct Point {
	int x, y;
	Point(int x, int y) : x(x), y(y) {}
};

void fillPaint(Image img, Point p, int color, int old_color) {
	if (p.x < 0 || p.y < 0 || p.x >= img.size_x || p.y >= img.size_y || img.grid[p.y][p.x] != old_color) return;
	img.grid[p.y][p.x] = color;
	Point up(p.x, p.y - 1);
	Point down(p.x, p.y + 1);
	Point right(p.x + 1, p.y);
	Point left(p.x - 1, p.y);
	fillPaint(img, up, color, old_color);
	fillPaint(img, down, color, old_color);
	fillPaint(img, right, color, old_color);
	fillPaint(img, left, color, old_color);
}

void fillPaint(Image img, Point p, int color) {
	int old_color = img.grid[p.x][p.y];
	fillPaint(img, p, color, old_color);
}


int main(void) {

}
