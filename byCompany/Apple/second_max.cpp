/*Find second max values*/

#include<iostream>
#include<vector>
using namespace std;

template <class T>
void printvec(vector<T> v) {
  int len = v.size();

  for(int i = 0; i < len; i ++) {
    cout << v[i] << " " ;
  }
  cout << "\n" ;
}

template <class T> 
void find2Max(vector<T> &v, T &max1, T &max2) {
  int len = v.size();
  max1 = max2 = -1;

  if(len <=1) {
    return;
  }

  max1 = v[0];
  max2 = v[1];

  if(max2 > max1) {
    T temp = max1;
    max1 = max2;
    max2 = temp;
  }

  for(int i = 2; i < len; i ++) {
    if(v[i] <= max2 ) {
      continue;
    } else if(v[i] <= max1 && v[i] > max2 ) {
      max2 = v[i];
    } else if(v[i] > max1) {
      max2 = max1;
      max1 = v[i];
    }
  }

  return;
}

int main()
{
  //int arr[] = {1,2,3,4,5, 5};
  int arr[] = {1,1};
  int max1, max2;
  vector<int> vint(arr , arr + sizeof(arr)/sizeof(arr[0]));
  printvec<int>(vint);

  find2Max<int>(vint, max1, max2);

  cout << max2 << "\n";


}

