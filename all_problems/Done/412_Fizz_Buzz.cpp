/* 
 * Problem Description
 Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
 * Solution
 First tackel the most contrained case, then the least ones

 * Tags
 Math, Array


*/

#include"header.h"
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        
        for(int i = 1; i <= n ; i++) {
            if( (0 == i %3)  && (0 == i % 5)) {
                result.push_back("FizzBuzz");
            }  else if((0 == i %3)) {
                result.push_back("Fizz");
            } else if ((0 == i %5)) {
                result.push_back("Buzz");
            } else {
                result.push_back(to_string(i));
            }
        }
        
        return result;
    }
};


int main() {
  Solution S;

  cout << S.fizzBuzz(15);

  return 0;
}
