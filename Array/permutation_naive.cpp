#include<iostream>
#include<vector>
#include<assert.h>
#include <algorithm>
using namespace std;

static int Count = 0;  

std::ostream& operator<< (std::ostream& stream, vector<int> v) 
{
  for(int i = 0 ; i < v.size(); i++ ) {
    stream << v[i] << " ";
  }
  stream << endl;
  return stream;


}

void
swap(char* a, char* b) {
  char temp = *b;
  *b = *a;
  *a = temp;
}

void fill(int pos, vector<int> exclude, int n, int r) 
{

  if(pos == r) {
    cout << exclude;
    Count ++;
    return;
  }

  for(int i = 0; i < n; i ++) {
    if(std::find(exclude.begin(), exclude.end(), i) != exclude.end()) {
      continue;
    }
    exclude.push_back(i);
    fill(pos +1, exclude,  n,  r);
    exclude.pop_back();
  }
}


void permute_v(int n, int r) 
{
  vector<int> exclude;
  fill(0, exclude, n, r);

}

void permute_helper1(std::string str, int &r, std::string &ans, int step) {
  if(step == r) {
    std::cout << ans << "\n";
    Count ++;
    return;
  }

  for(int i = 0; i < str.length(); i++  ) {
    ans.push_back(str[i]);

    std::string remain;
    if(i == 0) {
      remain.append(str.begin() + 1, str.end());
    } else {
      remain.append(str.begin(), str.begin() + i);
      remain.append(str.begin()+(i+1), str.end());
    }

    permute_helper1(remain, r, ans, step+1);
    ans.pop_back();
  }
}

void permute_helper2(std::string str, int &r, int step) {
  if(step == r) {
    for(int i = 0; i < r; i ++ ) {
      std::cout << str[i] << " ";
    }
    std::cout << "\n";
    Count ++;
    return;
  }

  for(int i = step; i < str.length(); i++  ) {
    swap(&str[step], &str[i]);
    permute_helper2(str, r, step+1); 
    swap(&str[step], &str[i]);
  }


}

void permute(std::string str, int r) {
  std::string ans;
  //permute_helper1(str, r, ans, 0); 
  permute_helper2(str, r, 0); 
}


int main() {
  std::string str("12345");
  int r = 5;
  cout << str << " r = " << r << endl;
  permute(str,r);
  cout << " Number Of Soln: " << Count << endl;

  return 0;
}
