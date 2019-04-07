/* Problem Description
 * A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, with the least significant bit on the right.
Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.

Example:

Input: n = 1
Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
Note:
The order of output does not matter.
The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".

Solution:
1. find out all the nums with n 1's. Difficult
2. Iterate through the valid times and count num of 1s in them

Tags
Bits
*/

#include"header.h"
class Solution {
public:

  int numSet(int n) {
    int sum = 0 ;
    while(n) {
      n = n & (n-1);
      sum++;
    }

    return sum;
  }
    
    vector<string> readBinaryWatch(int num) {
      vector<string> R;
      for(int h = 0; h < 12 ; h++) {
        for(int m = 0; m < 60 ; m++) {
          int time = (h << 6) | m;
          if(num == numSet(time)) {
            string hour = std::to_string(h);
            string min = std::to_string(m);
            if(1 == min.length()) {
              min.push_back(min[0]);
              min[0] = '0';
            }
            R.push_back(hour + ":" + min);
          }
        }
      }
        
      return R;
    }
};


int main() {
  Solution S;

  cout << S.readBinaryWatch(5);

  return 0;
}
