#include<stack>
#include<iostream>

/*
 * Length of the longest valid substring
Given a string consisting of opening and closing parenthesis, find length of the longest valid parenthesis substring.

Examples:

Input : ((()
Output : 2
Explanation : ()

Input: )()())
Output : 4
Explanation: ()() 

Input:  ()(()))))
Output: 6
Explanation:  ()(()))


*/

using namespace std;
 
int findMaxLen(string str)
{
    int n = str.length();
 
    stack<char> stk;
    int unmatchedright = 0;
 
    for (int i=0; i<n; i++) {

        if (str[i] == '(') {
          stk.push(str[i]);
        } else {
          if(stk.empty()) {
            unmatchedright ++;
          } else {
            stk.pop();
          }
       }
    }

    return n - stk.size() - unmatchedright;
}
 
// Driver program
int main()
{
    string str = "((()";
    cout << findMaxLen(str) << endl;

    str = "((()()";
    cout << findMaxLen(str) << endl;
 
    str = "()(()))))";
    cout << findMaxLen(str) << endl ;
 
    str = ")(";
    cout << findMaxLen(str) << endl ;
    return 0;
}
