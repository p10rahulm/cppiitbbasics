#include <iostream>

int abs(int x) {
	if (x<0) return -x;
	else return x;
}
struct complx {
	int AA, BB;
};


complx process1(complx g1, complx h1) {
	complx i1;
	i1.AA = g1.AA + h1.AA;
	i1.BB = g1.BB + h1.BB;
	return i1;
}

complx activity3(complx g1, complx h1) {
	complx i1;
	i1.AA = g1.AA - h1.AA;
	i1.BB = g1.BB - h1.BB;
	return i1;
}

complx process2(complx g1, complx h1) {
	complx i1;
	i1.AA = g1.AA*h1.AA - g1.BB*h1.BB;
	i1.BB = g1.AA*h1.BB + g1.BB*h1.AA;
	return i1;
}

complx operation4(complx g1, complx h1) {
	complx i1;
	i1.AA = (g1.AA*h1.AA + g1.BB*h1.BB) / (h1.AA*h1.AA + h1.BB*h1.BB);
	i1.BB = (-g1.AA*h1.BB + g1.BB*h1.AA) / (h1.AA*h1.AA + h1.BB*h1.BB);
	return i1;
}

int main() {
	complx num1, num2;
	/*num1 and num2 are two points in the complex plane */
	num1.AA = 9; // x-coordinate of num1
	num1.BB = -10; // y-coordinate of num1
	num2.AA = 7; // x-coordinate of num2
	num2.BB = 2; // y-coordinate of num2
				 // Line 1
	//(num1.AA - num2.AA)^2 + (num1.BB - num2.BB )  ^2
	double dist = process2(process1(activity3(num1.AA, num2.AA), activity3(num1.AA, num2.AA)), process1(activity3(num1.BB, num2.BB), activity3(num1.BB, num2.BB)));
	return dist;
}