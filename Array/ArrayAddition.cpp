#include<iostream>
#include<vector>
#include<assert.h>
using namespace std;


class ArrayAddition {

  public:
    ArrayAddition() {};
    vector<int> add(vector<int> v1, vector<int> v2) {

      int sizeOfv1 = v1.size();
      int sizeOfv2 = v2.size();
      int sizeOfresult = std::max(sizeOfv1, sizeOfv2);

      vector<int> result(sizeOfresult + 1);
      int i = sizeOfv1 -1, j = sizeOfv2 - 1, k  =sizeOfresult , c = 0;

      for(; i >= 0 && j >= 0 ; i--, j--) {
        int temp = v1[i] + v2[j] + c;
        c = temp / 10;
        result[k--] = temp % 10;
      }

      while(i >= 0) {
        int temp = v1[i--] + c;
        c = temp / 10;
        result[k--] = temp % 10;
      }

      while(j >= 0) {
        int temp = v2[j--] + c;
        c = temp / 10;
        result[k--] = temp % 10;
      }

      assert(k == 0);

      result[k] = c;
      return result;
    }
};

std::ostream& operator<<(std::ostream& stream, vector<int> v) {
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;
}

void vector_add(vector<int> &R, vector<int> v1, vector<int> v2) {
  int index = R.size()-1;

  int carry =0,i,j;
  for(i=v1.size() -1, j=v2.size() -1; i >= 0, j >=0; i--, j--) {
    int a = v1[i] + v2[j] + carry;
    int q = a/10;
    int r = a%10;
    R[index--] = r;
    carry = q;  
  }

  if(i == -1) {
    for(;j >=0;  j--) {
      int a = v2[j] + carry;
      int q = a/10;
      int r = a%10;
      R[index--] = r;
      carry = q;  
    }
  }
  if(j == -1) {
    for(;i >=0;  i--) {
      int a = v1[i] + carry;
      int q = a/10;
      int r = a%10;
      R[index--] = r;
      carry = q;  
    }
  }
  R[index] = carry;
}

int main() {
  int *arr[2][2];
  arr[0][0] = new int[7];
  arr[0][1] = new int[6];
  arr[1][0] = new int[6];
  arr[1][1] = new int[7];

  arr[0][0][0] = 9; arr[0][1][0] = 1;
  arr[0][0][1] = 9; arr[0][1][1] = 6;
  arr[0][0][2] = 9; arr[0][1][2] = 8; 
  arr[0][0][3] = 9; arr[0][1][3] = 2;
  arr[0][0][4] = 9; arr[0][1][4] = 6;
  arr[0][0][5] = 9; arr[0][1][5] = 7;
  arr[0][0][6] = 9;
  

  arr[1][1][0] = 9; arr[1][0][0] = 1;
  arr[1][1][1] = 9; arr[1][0][1] = 6;
  arr[1][1][2] = 9; arr[1][0][2] = 8; 
  arr[1][1][3] = 9; arr[1][0][3] = 2;
  arr[1][1][4] = 9; arr[1][0][4] = 6;
  arr[1][1][5] = 9; arr[1][0][5] = 7;
  arr[1][1][6] = 9;


    vector<int> v1(arr[0][0], arr[0][0] + 7);
    vector<int> v2(arr[0][1], arr[0][1] + 6);
    cout << v1;
    cout << v2;

    ArrayAddition A;
    vector<int> result =  A.add(v1, v2);

    std::cout << "After Adding (starting from LSW)\n";
    cout << result;

    int max_len = v1.size() >= v2.size() ? v1.size(): v2.size(); 
    vector<int> R(max_len + 1,0);
    vector_add(R, v1, v2);
    std::cout << "After Adding (starting from LSW)\n";
    cout << R;

    vector<int> v01(arr[1][0], arr[1][0] + 6);
    vector<int> v02(arr[1][1], arr[1][1] + 7);
    cout << v01;
    cout << v02;

    result =  A.add(v01, v02);

    std::cout << "After Adding (starting from LSW)\n";
    cout << result;

    max_len = v1.size() >= v2.size() ? v1.size(): v2.size(); 
    vector<int> R1(max_len + 1,0);
    vector_add(R1, v1, v2);
    std::cout << "After Adding (starting from LSW)\n";
    cout << R1;
  return 0;
}
