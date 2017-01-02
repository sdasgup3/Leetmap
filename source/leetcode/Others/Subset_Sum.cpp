/* Problem Description
 * given an array of ints and a val k ; check if there exists a  subset of int adding up to the val k
*/

#include"header.h"
class Solution {

public:
  bool subsetsum(vector<int> nums, int k) {
    int size = nums.size();
    bool arr[size][k+1];

    //fill the fisrt row
    for(int i = 0 ; i <=k ; i++) {
      if(i == 0) {
        arr[0][i] = true;
      } else if(i == nums[0]) {
        arr[0][i] = true;
      } else {
        arr[0][i] = false;
      }
    }

    for(int j = 1; j < size; j++) {
      arr[j][0] =  true;
      int n = nums[j];
      for(int i = 1 ; i <=k ; i++) {
        arr[j][i] = arr[j-1][i];
        if(i - n >= 0 ) {
          arr[j][i] |= arr[j-1][i-n];
        }
      }
    }

    /*
    for(int i = 0 ; i < size ; i ++) {
      for(int j = 0 ; j <= k ; j ++) {
        cout << arr[i][j] << " " ;
      }
      cout << "\n";
    }
    */

    return arr[size-1][k];

  }
private:

};


int main() {
  Solution S;

  vector<int> D({1,3,4});

  for(int i = 0 ; i < 20; i ++) {
    cout << "k = " << i << " :  " <<  S.subsetsum(D, i) << "\n";
  }

  return 0;
}
