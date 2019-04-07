/* 
 * Problem Description
 You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].
 * Solution

1. for each n : nums
    createBST with n as root and other elemnsts as the mebers of BST. Aslo leftTree should contain 
    elements stritly less that root
Also each node shpuld maintain the count of elemets inc self
so for n the answer is going to be root->left-> count

Problem is craete a BST for each member is very costly: n2logn

Also a singke BST is nit enough
2  1 2'  1'
WHat we expect here is
    2
   /   \
   1  2'
   /   /
  1    1
and its diff to get this

Case2:
Sorting the whole array is wrong:
2 6 1
countSmaller(6) = 1
but after sorting 
1 2 6
countSmaller(6) = 2

so start sorting from the end

Traverse from the back to the beginning of the array, maintain an sorted array
of numbers have been visited. Use findIndex() to find the first element in the
sorted array which is larger or equal to target number. For example,
[5,2,3,6,1], when we reach 2, we have a sorted array[1,3,6], findIndex()
returns 1, which is the index where 2 should be inserted and is also the number
smaller than 2. Then we insert 2 into the sorted array to form [1,2,3,6].


 * Tags
 Sort
*/

#include"header.h"


class Solution {
public:
    
    void buildBST(TreeNode**root, int n, int &cnt) {
        if(NULL == *root) {
            *root = new TreeNode(n);
            (*root)->count = 1;
            return;
        }
        
        (*root)->count ++;
        if(n <= (*root)->val) {
            buildBST(&((*root)->left), n, cnt);
        } else {
            cnt += 1;
            if((*root)->left) {
              cnt += (*root)->left->count;
            }
            buildBST(&((*root)->right), n, cnt);
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        int sz = nums.size();
        if(0 ==sz) {
            return res;
        }

        res.resize(sz);
        
        TreeNode *root = NULL;    
        for(int i = sz-1 ; i >= 0; i--) {
          int count = 0 ;
          buildBST(&root, nums[i], count);
          res[i] = count;
        }
        
        return res;
    }

    vector<int> countSmaller1(vector<int>& nums) {
        vector<int> sortarray;
        int sz = nums.size();
        vector<int> res(sz);
        if(0 ==sz) {
            return res;
        }

        for(int i = sz-1; i>=0 ; i--) {
          int posn = 0;
          //find the insert posn
          for(int j = 0 ; j < sortarray.size(); j++) {
            if(sortarray[j] < nums[i]) {
              posn++;
            } else {
              break;
            }
          }

          sortarray.insert(sortarray.begin()+posn, nums[i]);
          res[i] = posn;
        }

        return res;
        
    }
};


int main() {
  Solution S;

  vector<int> D({-1, -1});
  cout << S.countSmaller(D);

  return 0;
}
