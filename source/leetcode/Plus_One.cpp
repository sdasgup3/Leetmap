/* Problem Description
   Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include"header.h"
  class Solution {
public:
	/*
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int carry = 1;
        vector<int> R(size, 0);
        for(int i = size-1; i>=0 ; i --) {
            if(carry) {
                if(digits[i] == 9) {
                    R[i] = 0;
                    carry =1;
                } else {
                    R[i] = digits[i]  + 1;
                    carry =0;
                }
            } else {
                R[i] = digits[i];
                carry =0;
            }
        }
        if(carry) {
            R.push_back(0);
            for(int i = 0; i < size; i++ ) {
              R[i+1] = R[i];
            }
            R[0] = carry;
        }
        return R;
        
    }
    */
  vector<int> plusOne(vector<int>& digits) {
    int size = digits.size();
    bool all9 = true;
    for(int i = 0; i < size; i++ ) {
      if(digits[i] != 9 ) {
        all9 = false;
      }
    }

    vector<int> R(size, 0);
    int ptr = size-1;
    if(all9) {
      R.push_back(0);
      R[0] = 1;
      ptr ++; 
    }

    int carry = 1;
    for(int i = size-1; i>=0 ; i --, ptr--) {
      if(carry) {
        if(digits[i] == 9) {
          R[ptr] = 0;
          carry =1;
        } else {
          R[ptr] = digits[i]  + 1;
          carry =0;
        }
      } else {
        R[ptr] = digits[i];
        carry =0;
      }
    }
    return R;
  }
};


int main() {
  Solution S;
  vector<int> d = {9};

  cout << S.plusOne(d);

  return 0;
}
