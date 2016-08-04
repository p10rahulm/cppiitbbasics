//-----Include required headers here-----
#include <iostream>
using namespace std;
//-----End of headers-----

//-----Don't change/delete structs-----
struct vertex {
	float x;
	float y;
};

struct triangle {
	vertex v[3];//vertex vertices[3];
};
//-----Structs end here


//-----Add new functions here(if any)-----
void input_points(vertex &v) {
	v.x = v.x;
	v.y = v.y;
	//cin >> v.x >> v.y;
	cout << v.x << v.y;
}

void input_triangle(triangle &t) {
	input_points(t.v[0]);
	input_points(t.v[1]);
	input_points(t.v[2]);

}

float abs(float x) {
	if (x<0) return -x;
	else return x;
}
float area(triangle t) {
	return 0.5 * abs((t.v[1].x - t.v[0].x)*(t.v[2].y - t.v[0].y) - (t.v[2].x - t.v[0].x)*(t.v[1].y - t.v[0].y));
}


//-----New functions end here-----

float cal_area(triangle aTriangle) {
	//Write your solution below this line
	input_triangle(aTriangle);
	//cout << area(aTriangle) << endl;

	return (area(aTriangle));

	//Dont write below this line
}