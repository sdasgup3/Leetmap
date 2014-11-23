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


int main() {
  int arr1[]  = {9,9,9,9,9,9,9};
  int arr2[]  = {1,6,8,2,6,7};


  vector<int> v1(arr1, arr1 + sizeof(arr1)/sizeof(arr1[0]));
  vector<int> v2(arr2, arr2 + sizeof(arr2)/sizeof(arr2[0]));

  cout << v1;
  cout << v2;

  ArrayAddition A;
  vector<int> result =  A.add(v1, v2);

  std::cout << "After Adding (starting from LSW)\n";
  cout << result;

  return 0;
}
