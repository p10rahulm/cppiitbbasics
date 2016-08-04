#include<iostream>
using namespace std;

int abs(int x) {
	if (x<0) return -x;
	else return x;
}
struct sample {
	int pp, qq;
};

int exact(int a, int b) {
	if (a%b == 0) return b;
	int n = a%b;
	if (b%n == 0) return n;
	else return exact(b, n);
}

void simplify(sample& r2) {
	int s2 = exact(abs(r2.pp), r2.qq);
	r2.pp = r2.pp / s2;
	r2.qq = r2.qq / s2;
	if (r2.qq < 0) {
		r2.pp = -r2.pp;
		r2.qq = -r2.qq;
	}
}

sample action1(sample g1, sample h1) {
	sample i1;
	i1.pp = g1.pp*h1.qq + h1.pp*g1.qq;
	i1.qq = g1.qq*h1.qq;
	simplify(i1);
	return i1;
}

sample action2(sample g1, sample h1) {
	sample i1;
	i1.pp = g1.pp*h1.pp;
	i1.qq = g1.qq*h1.qq;
	simplify(i1);
	return i1;
}

int main() {
	sample num1, num2;
	num1.pp = 6;
	num1.qq = 18;
	num2.pp = 4;
	num2.qq = 12;
	simplify(num1);
	simplify(num2);
	int output1 = action2(num1, num2).pp;
	int output2 = action2(num1, num2).qq;
	int output3 = action1(num1, num2).pp;
	int output4 = action1(num1, num2).qq;
	return 0;
}
