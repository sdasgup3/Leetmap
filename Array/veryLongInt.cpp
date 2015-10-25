#include<iostream>
#include<vector>


class veryLongINT {
  private:

  public:
    std::vector<int> I;
    int sign;
    veryLongINT() {}
    veryLongINT(std::vector<int> i, int s) {
      I = i;
      sign = s;
    }
    int size() const {
      return I.size();
    }
    veryLongINT(const veryLongINT& obj) {
      I     = obj.I;
      sign  = obj.sign;
    }
    veryLongINT& operator=(const veryLongINT& obj) {
      I     = obj.I;
      sign  = obj.sign;
      return *this;
    }
    void print() const {
      if(sign == -1) {
        std::cout << "- ";
      }
      for(int i =  I.size() -1 ; i>= 0 ; i--) {
        std::cout << I[i] ;
      }
      std::cout << std::endl;
    }
};


int
abscompare(const veryLongINT& a, const veryLongINT& b) {
  if(a.size() != b.size()) {
    return a.size()  - b.size();
  } 

  int i = 0;
  while(i < a.size()) {
    if(a.I[i] != b.I[i]) {
      break;
    }
    i++;
  }
  if(i == a.size()) {
    return 0;
  } else {
    return a.I[i] - b.I[i];
  }
}

veryLongINT
base_add(const veryLongINT& a, const veryLongINT& b) {
  int carry = 0;
  int i = 0, j=0;
  std::vector<int> v;
  for( i = 0, j=0; i < a.size() && j < b.size(); i++, j++) {
    int sum = a.I[i] + b.I[j] + carry;  
    int q = sum % 10;
    carry = sum / 10;
    v.push_back(q);
  }
  if(i == a.size()) {
    for(;  j < b.size();  j++) {
      int sum = b.I[j] + carry;  
      int q = sum % 10;
      carry = sum / 10;
      v.push_back(q);
    }
  }
  if(j == b.size()) {
    for(;  i < a.size();  i++) {
      int sum = a.I[i] + carry;  
      int q = sum % 10;
      carry = sum / 10;
      v.push_back(q);
    }
  }
  if(carry != 0)  {
    v.push_back(carry);
  }

  veryLongINT v1(v,1);

  return v1;
}

veryLongINT
base_subtract(const veryLongINT& a, const veryLongINT& b) {
  int borrow = 0;
  int i = 0, j=0;
  std::vector<int> v;
  for(i = 0, j=0; i < a.size() && j < b.size(); i++, j++) {
    int sum = 0;
    int _a = a.I[i] - borrow;
    if(_a < b.I[j]) {
      sum = _a + 10 - b.I[j];
      borrow  = 1;
    } else {
      sum = _a - b.I[j];
      borrow  = 0;
    }
    v.push_back(sum);
  }
  if(j == b.size()) {
    for(;  i < a.size();  i++) {
      int sum = 0;
      int _a = a.I[i] - borrow;
      if(_a < 0) {
        sum = _a + 10 ;
        borrow  = 1;
      } else {
        sum = _a ;
        borrow  = 0;
      }
      v.push_back(sum);
    }
  }

  veryLongINT v1(v,1);
  return v1;
}

veryLongINT
operator+(const veryLongINT& a, const veryLongINT& b) {
  if(a.sign == b.sign && a.sign == 1) {
    veryLongINT v = base_add(a,b);
    v.sign = 1;
    return v;
  }

  if(a.sign == b.sign && a.sign == -1) {
    veryLongINT v = base_add(a,b);
    v.sign = -1;
    return v;
  }

  if(a.sign != b.sign ) {
    if(abscompare(a,b) > 0) {
      veryLongINT v = base_subtract(a,b);
      v.sign = a.sign;
      return v;
    } else if(abscompare(a,b) < 0) {
      veryLongINT v = base_subtract(b,a);
      v.sign = b.sign;
      return v;
    } else {
      std::vector<int> a(1,0);
      veryLongINT v(a,1);
      return v;
    }
  }
}

veryLongINT
operator-(const veryLongINT& a, const veryLongINT& b) {
  veryLongINT c(b);
  c.sign = -1*b.sign;
  return a + c;
}

int 
main() {
  std::vector<int> v1, v2, v3, v4;
  veryLongINT V1, V2, V3;

  v1.push_back(1); v1.push_back(2); v1.push_back(3); v1.push_back(4);
  V1 = veryLongINT(v1, -1);

  v2.push_back(1); v2.push_back(2); v2.push_back(3); v2.push_back(4);
  V2 = veryLongINT(v2, -1);

  v1.clear();v2.clear();
  V1.print();
  V2.print();

  V3 = V1+V2;
  V3.print();
  std::cout << "\n";
  V3 = V1-V2;
  V3.print();
  std::cout << "\n";

  v1.push_back(1); v1.push_back(2); v1.push_back(3); v1.push_back(4);
  V1 = veryLongINT(v1, -1);

  v2.push_back(9); v2.push_back(9); v2.push_back(3);
  V2 = veryLongINT(v2, -1);

  v1.clear();v2.clear();
  V1.print();
  V2.print();

  V3 = V1+V2;
  V3.print();
  std::cout << "\n";
  V3 = V1-V2;
  V3.print();
  std::cout << "\n";

  v1.push_back(1); v1.push_back(2); 
  V1 = veryLongINT(v1, -1);

  v2.push_back(9); v2.push_back(9); v2.push_back(3);
  V2 = veryLongINT(v2, 1);

  v1.clear();v2.clear();
  V1.print();
  V2.print();

  V3 = V1+V2;
  V3.print();
  std::cout << "\n";
  V3 = V1-V2;
  V3.print();
  std::cout << "\n";
}
