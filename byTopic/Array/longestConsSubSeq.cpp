#include<iostream>

//12456789

void
LS(std::string str, int &start, int &end) {
  int max_start = 0, max_end = 0;

  if(0 == str.length()) {
    return;
  }

  for(int i = 0 ; i < str.length(); i++) {
    start = i;
    int j;
    for( j = i +1 ; j < str.length(); j++) {
      if(str[j -1] + 1 != str[j] ) {
        end = j-1;
        if((end - start + 1) > (max_end -max_start +1)) {
          max_start = start;
          max_end = end;
        }
        break;
      }
    }
    if(j == str.length()) {
      end = str.length() -1;
      if((end - start + 1) > (max_end -max_start +1)) {
        max_start = start;
        max_end = end;
      }
    }
  }

  start = max_start;
  end = max_end;
}

//O(n)
void
LS2(std::string str, int &start, int &end) {

  if(0 == str.length()) {
    return;
  }

  int max_start = 0 , max_end = 0 ;
  int i;

  start = 0; end =0;
  for( i = 1 ; i < str.length(); i++) {
    if(str[i-1] + 1 != str[i]) {
      end = i-1;
      if(end - start + 1 > max_end - max_start + 1) {
        max_start = start;
        max_end = end;
      }
      start  = end  = i;
    } 
  }

  if(i == str.length()) {
    end = i-1;
    if(end - start + 1 > max_end - max_start + 1) {
      max_start = start;
      max_end = end;
    }
  }

  start = max_start;
  end = max_end;
}



int main()
{
  int start = -1, end = -1;

  std::string str;
  
  str = std::string("12456789");
  LS(str, start, end); 
  std::cout << str << " "<<  start << " " << end << "\n";

  start = -1; end = -1;
  str = std::string("136890");
  LS(str, start, end); 
  std::cout << str << " "<<  start << " " << end << "\n";

  start = -1; end = -1;
  str = std::string("13690");
  LS(str, start, end); 
  std::cout << str << " "<<  start << " " << end << "\n";

  str = std::string("12456789");
  LS2(str, start, end); 
  std::cout << str << " "<<  start << " " << end << "\n";

  start = -1; end = -1;
  str = std::string("136890");
  LS2(str, start, end); 
  std::cout << str << " "<<  start << " " << end << "\n";

  start = -1; end = -1;
  str = std::string("13690");
  LS2(str, start, end); 
  std::cout << str << " "<<  start << " " << end << "\n";
}
