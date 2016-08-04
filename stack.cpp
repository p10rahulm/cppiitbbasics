#include <iostream>
#include <stack>          // std::stack
#include <stdio.h>
using namespace std;

void  magic(int n) {
	std::stack<int> s; // assume a empty stack created
					   //int s[7];  
	while (n > 0) {
		s.push(n % 2);
		n = n / 2;
	}
	while (!s.empty()) {
		printf("%d", s.top()); // pop an element from s and print it
		s.pop(); //("%d", s.pop())
	}
}

int main() {
	// your code goes here
	int n = 42;
	magic(n);
}