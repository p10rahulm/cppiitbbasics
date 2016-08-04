#include<iostream>
using namespace std;

struct point {
	int x, y;
};

struct triangle {
	point p[3];
};

void read_point(point &p) {
	cin >> p.x >> p.y;
}

void read_triangle(triangle &t) {
	read_point(t.p[0]);
	read_point(t.p[1]);
	read_point(t.p[2]);
}

int gcd(int x, int y) {
	while (y != 0) {
		int temp = x;
		x = y;
		y = temp%y;
	}
	return x;
}

int main() {
	triangle t;
	read_triangle(t);

	int a = gcd(abs(t.p[1].x - t.p[0].x), abs(t.p[1].y - t.p[0].y));
	int b = gcd(abs(t.p[2].x - t.p[1].x), abs(t.p[2].y - t.p[1].y));
	int c = gcd(abs(t.p[2].x - t.p[0].x), abs(t.p[2].y - t.p[0].y));

	int ans;
	ans = a + b + c;
	cout << ans << endl;
}
