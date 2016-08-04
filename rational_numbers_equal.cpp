//-----Include required headers here-----
#include<iostream>
using namespace std;

//-----End of headers-----

//-----Don't change/delete structs-----
struct rational {
	int numerator;
	int denominator;
};
//-----Structs end here


int abs(int x) {
	if (x<0) return -x;
	else return x;
}
int exact(int a, int b) {
	if (a%b == 0) return b;
	int n = a%b;
	if (b%n == 0) return n;
	else return exact(b, n);
}

rational simplify(rational &r2) {
	int s2 = exact(abs(r2.numerator), r2.denominator);
	r2.numerator = r2.numerator / s2;
	r2.denominator = r2.denominator / s2;
	if (r2.denominator < 0) {
		r2.numerator = -r2.numerator;
		r2.denominator = -r2.denominator;
	}
	return r2;
}

/*Question: Reduce the number 'inputrational' to its lowest form and store it in 'outputrational'
struct rational *inputrational  : Actual rational number to be reduced
struct rational *outputrational : Variable to store the rational number in its lowest form */
void reduce(struct rational *inputrational, struct rational *outputrational) {
	//Write your solution code below this line
	outputrational = simplify(inputrational);

}
rational reduction(struct rational &inputrational) {
	//Write your solution code below this line
	return simplify(inputrational);

}

/* Question: Check whether both the rational numbers obtained in the lowest form are equal or not.
Retrun true or false accordingly
*/
bool isEqual(struct rational num1, struct rational num2) {
	//Write your solution code below this line
	simplify(num1);
	simplify(num2);
	if (num1 == num2) return true;
	return false;
}