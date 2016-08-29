/* Question   : Convert prefix to infix notation of expression */
#include <string>
#include <stack>
#include <algorithm>
#include <iterator>

using namespace std;


string prefix_to_infix(string expr) 
{
    // fill in the function (you can create extra functions if need be)
    
    std::stack<std::string> queuedopers;
    std::stack<std::string> queuedexprs;
    std::reverse(expr.begin(), expr.end());
    string opers = "+-*/^%";
    int i =0;
    while (i != expr.size()){
        if ( opers.find(expr[i]) !=std::string::npos ){ 
            string s;
            s = expr[i];
            queuedopers.push(s);
        }
        else { 
            string s;
            s = expr[i];
            queuedexprs.push(s);
        }
        while (queuedexprs.size() >=2 and queuedopers.size()>0){
                string a,b,infix_opr;
                a = queuedexprs.top();
                queuedexprs.pop();
                b = queuedexprs.top();
                queuedexprs.pop();
                infix_opr = queuedopers.top();
                queuedopers.pop();
                queuedexprs.push("(" + a + infix_opr + b + ")");
        }
        i+=1;
        
    }
    return queuedexprs.top();
}
