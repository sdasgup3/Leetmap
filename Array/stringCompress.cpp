#include<iostream>
#include<string>
#include<cstring>

std::string myitoa(int count) {
  std::string str("");
  while(0 != count) {
    int q = count/10;
    int r = count%10;

    char c = '0' + r;
    str.push_back(c);
    count  = q;
  }
  return str;
}

std::string stringCompress(std::string str1){
  std::string str2("");
  int len1 = str1.length();

  int ptr1= 0;

  for(; ptr1 < len1; ) {
    char last_c = str1[ptr1];
    str2.push_back(last_c);
    ptr1 ++;
    int count = 0;
    while(ptr1 < len1 && last_c == str1[ptr1]) {
      count++;
      ptr1 ++;
    }
    if(count  > 0) {
      std::string str_count = myitoa(count+1); 
      for(int i = str_count.length() -1 ; i >= 0; i--) {
        str2.push_back(str_count[i]) ;
      }
    }
  }

  if(len1 <= str2.length()) {
    return str1;
  } 
  return str2;
}

std::string stringCompress_v2(std::string str1){
  int len1 = str1.length();

  int ptr1= 0;
  int ptr2= 0;

  for(; ptr1 < len1; ) {
    char last_c = str1[ptr1];
    str1[ptr2] = last_c;
    ptr1 ++; ptr2 ++;
    int count = 0;
    while(ptr1 < len1 && last_c == str1[ptr1]) {
      count++;
      ptr1 ++;
    }
    if(count  > 1) {
      std::string str_count = myitoa(count+1); 
      for(int i = str_count.length() -1 ; i >= 0; i--, ptr2++) {
        str1[ptr2] = str_count[i] ;
      }
    } else if(1 == count) {
      str1[ptr2++] = last_c;
    }
  }
  str1[ptr2] = '\0';
  int len2 =0;
  for(std::string::iterator I = str1.begin(), E = str1.end(); I!= E; I++) {
    if(*I == '\0') break;
    len2++;
  }

  return str1;
}

std::string
Mitoa(int n) {
  std::string str("");

  while(n) {
    int q = n/10;
    int r=  n%10;
    str.push_back(r + 48);  
    n = q;
  }

  return str;

}

std::string stringCompress_v3(std::string str){
  int len = str.length();
  if(0 == len) {
    return str;
  }
  
  int ptr1 =0 ;
  int ptr2 =0 ;

  for( ; ptr1 < len; ) {
    char c = str[ptr1];

    int k = ptr1 +1;
    int count = 0;
    while(k < len && str[k] == c )  {
      count++;
      k++;
    }
    ptr1 = k;
    str[ptr2++] = c;

    if(count >= 2) {
      std::string s = Mitoa(count+1);
      for(int i = s.length()-1 ; i >= 0; i--, ptr2++) {
        str[ptr2] = s[i];
      }
    } else if(count == 1) {
      str[ptr2++] = c;
    }
  }
  str[ptr2] = '\0';
  return str;
}

int main()
{
  std::string str[] = {"aabccccaaa", "abc", "aabbcc"};

  int size = sizeof(str)/sizeof(str[0]);
  for(int i = 0; i < size; i++) {
    std::string str1 = stringCompress(str[i]);
    std::string str2 = stringCompress_v2(str[i]);
    std::string str3 = stringCompress_v3(str[i]);
    std::cout << " Str: "  << str[i] <<  std::endl;
    std::cout << " Compress: " << str1 << std::endl;
    std::cout << " Compress: " << str2.c_str() << std::endl;
    std::cout << " Compress: " << str3.c_str() << std::endl;
  }

  return 0;
}
