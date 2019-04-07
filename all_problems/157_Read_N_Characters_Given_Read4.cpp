/* Problem Description
 * The API: int read4(char *buf) reads 4 characters at a time from a file.

The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.

By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

Note:
The read function will only be called once for each test case.
*/

#include"header.h"

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
     
     int read(char *buf, int n) {
    int res = 0;
    while(res < n){
        int r4 = read4(buf);
        if(r4 == 4){res += r4;}
        else{
            res += r4;
            break;
        }
        buf += r4;
    }
    return min(res,n);
}
     
    int read2(char *buf, int n) {
        
        int q = n/4;
        int r  = n%4;
        bool premature_end = false;
        int sum = 0;
        string str("");
        
        // read q nmber of times 
        for(int i = 0 ; i < q ; i ++) {
            int k = read4(buf);
            buf += k;
            sum += k;
            str += string(buf);
            if(k < 4) {
                premature_end = true;
                break;
            }
            //cout << str << "\n";
        } 
        // read the remainder
        if(0 != r && false == premature_end) {
            int k =  read4(buf);
            
            if(k > r) {
                buf[r] = '\0';
                sum += r;
            } else {
                buf[k] = '\0';
                sum +=k;    
            } 
          //  cout << str << "\n";
        }
        
      
        cout << buf;
        return sum;
    }
};

int main() {
  Solution S;

  vector<string> D;

  D.push_back("dear");
  D.push_back("cart");
  D.push_back("cane");
  D.push_back("make");

  S.ValidWordAbbr(D);

  return 0;
}
