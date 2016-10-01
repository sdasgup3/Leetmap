/* Problem Description
 * Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to file in the abstracted file system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
*/

#include"header.h"
class Solution {
public:
    int getSum(vector<int> &V) {
      int sum = 0;
      for(int i = 0 ; i < V.size(); i++) {
        sum += V[i];  
      }
      return sum;
    }
    bool isFile(string str) {
      return string::npos != str.find('.', 0);
    }

    int getLevel(string str) {
      int level = 0;
      size_t pos = str.find("\n", 0);
      if(pos == string::npos) {
        return level;
      }

      while(1) {
        pos = str.find("\t", pos+1);
        if(pos != string::npos) {
          level ++;
        } else {
          break;
        }
      }

      return level;
    }

    void parse(string str, vector<string> &R) {
      size_t start = 0 ;
      size_t last =0;

      while(1) {
        last = str.find("\n", start +1);
        if(last == string::npos) {
          last  = str.length();
          R.push_back(str.substr(start, last-1 -start + 1)); 
          break;
        }
        R.push_back(str.substr(start, last-start));  
        start = last;
      }
    }

    int lengthLongestPath(string input) {

      cout << input << "\n";
      vector<string> I;
      parse(input, I);

      int result = 0;
      vector<int> runner;

      int prev_level = -1;
      for(auto str : I) {
        int level = getLevel(str);
        int len_tobe_added = str.length() - (level +1) + 1;
        cout << str << " " << level << " " << len_tobe_added << "\n";
        if(level > prev_level) {
          runner.push_back(len_tobe_added); // remov the #\t == level + \n and add \ instead
          if(isFile(str)) {
            result = max(result, getSum(runner));  
          }
        } else {
          int depth = prev_level - level +1;
          while(depth) {
            runner.pop_back();
            depth--;
          }
          runner.push_back(len_tobe_added);
        }
        prev_level = level;
      }

      return result;
    }
};


int main() {
  Solution S;

  //string path = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
  //string path = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
  //string path = "a";
  string path = "dir\n    file.txt";

  cout << S.lengthLongestPath(path);

  return 0;
}
