/* Question   : Convert prefix to infix notation of expression */
#include <string>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

bool isOperand(char C);

string prefix_to_infix(string expression) {
    // fill in the function (you can create extra functions if need be)
    string st1, st2, st3, temp, infix;
	char ch;
	stack <string> sStack1;
	for (int i = expression.length()-1; i >= 0; i--){
		ch = expression[i];
		//cout << "i= "<<i<<"c = "<<ch<<"expressions="<<expression<<"end"<<endl;
		if (isOperand(ch)){
            sStack1.push(string(1,ch));
		}
		else
		{
			st2 = sStack1.top();
			sStack1.pop();
			st3 = sStack1.top();
			sStack1.pop();
			temp.assign("(");
			temp.append(st2);
			temp.append(1, ch);
			temp.append(st3);
			temp.append(")");
			sStack1.push(temp);
		}
	}
	while (!sStack1.empty()){
	    //cout << sStack1.top() << endl;
		infix += sStack1.top();
		sStack1.pop();
	}
	return infix;
}
bool isOperand(char C){
    //cout << "in isoperadn, C = " << C << endl;
    
	if (C == '+' || C == '-' || C == '*' || C == '/' || C == '^')
	{
	    //cout << "in isoperadn, returned true for operand" << endl;
		return false;
	}
	//cout << "in isoperadn2"<< endl;
	
	if ((C >= '0' && C <= '9') || (C >= 'a' && C <= 'z') || (C >= 'A' && C <= 'Z')) {
		    //cout << "in isoperadn, returned true for number/char" << endl;
			return true;
	}
	//cout << "in isoperadn3"<< endl;

	return false;
}