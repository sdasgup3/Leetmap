### Tips
  - In grid traversal problems, do not forget to provide base case for gird retrival; else you will end up traversing in a loop
  - In grid traversal, while traversal the 4 corners, make make sure to check
    ```
        for(int i = 0 ; i < c; i++) {
            if(r > 1)
              if(board[r-1][i] == 'O') { // else r-1 is -1
                mark(board, r-1, i);
              }
        }
    ```
  - If we know the size of the input that we intend to store in a map, go for an array instead
    ```
     Say we need to know the frequency of each char in a string and we know the string is composed of 256 chars max
     so instead of doing M[c] ++ , do V[c] ++

    ```

  - For getting for aux info of a tree, do the computation using a runner. Using root instead will modify the tree itself.
  - While using a map check if the problem can be solved with a constant space map. This will reduce the space complexity to constant space.
    Candidates are if the number od keys is a constant like english alphabets. Example:   771 Jewels
  - Be careful about the definition of swap
  - While doing binary search make sure we do not have computation incloving mid +- n, for example
  ```
   bool findPivot(const vector<int>& nums, int &pivot) {
        int n = nums.size();
        
        if(nums[0] < nums[n-1]) {
            return false;
        }
        
        int first = 0;
        int last = n-1;
        while(first <= last) {
            auto mid = first + (last-first)/2;
            // Added to avoid OOB nid -1
            if(mid == first) {
                mid++;
            }

            if(nums[mid] < nums[mid-1]) {
                pivot = mid;
                return true;
            }
            if(nums[first] < nums[mid]) {
                first = mid;
            } else {
                last = mid;        
            }
        }
    }

  ```
  - Handy merge list
  ```
    ListNode *mergeList(ListNode*l1, ListNode *l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1->val <= l2->val) {
            l1->next = mergeList(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeList(l1, l2->next);
            return l2;
        }
    }

  ```

### Algorithm
- Find all the root to leaf path
  Consider the following recursive calls for left and right  subtree. If str is  a reference then the entire left path
  will be reflected in right path as well. We don't want that. So choose ref carefully!!
   ```
            helper(root->left, str);
            helper(root->right, str); 
   ```

- Count number of 1s
    ```
    int numSet(int n) {
        int sum = 0 ;
        while(n) {
          n = n & (n-1);
          sum++;
        }

        return sum;
      }

    ```

- Quick Sort
  - Ascending
  ```
   int QS(vector<int> &nums, int first, int last) {
      int pivot = nums[first];
      int pivot_ind = first;
      while(first < last) {

        while(first < last && nums[first] <= pivot) {
          first++;
        }
        while(nums[last] > pivot) {
          last--;
        }

        if(first < last) {
          swap(&nums[first], &nums[last]);
        }
      }

      swap(&nums[pivot_ind], &nums[last]);

      return last;
    }

  ```
  - Descending
  ```
   int QS(vector<int> &nums, int first, int last) {
      int pivot = nums[first];
      int pivot_ind = first;
      while(first < last) {

        while(first < last && nums[first] >= pivot) {
                                         ----
          first++;
        }
        while(nums[last] < pivot) {
                        ----
          last--;
        }

        if(first < last) {
          swap(&nums[first], &nums[last]);
        }
      }

      swap(&nums[pivot_ind], &nums[last]);

      return last;
    }

  ```
- Reservoir Sampling
  ```
  Problem: Choose k entries from n numbers. Make sure each number is selected with the probability of k/n
  [Special case](https://leetcode.com/problems/random-pick-index/)
  where we need to select 1 entry out of the possible n target indices; each selection is made with 1/n prob.

  Example:
  Problem: Choose 3 numbers from [111, 222, 333, 444]. Make sure each number is selected with a probability of 3/4

  First, choose [111, 222, 333] as the initial reservior
  Then choose 444 with a probability of 3/4
  For 111, it stays with a probability of
  P(either 444 is not selected) + P(or 444 is selected but it replaces 222 or 333)
  = 1/4 + 3/4*2/3
  = 3/4
  The same case with 222 and 333
  Now all the numbers have the probability of 3/4 to be picked

  Basic idea:
  Choose 1, 2, 3, ..., k first and put them into the reservoir.
  For k+1, pick it with a probability of k/(k+1), and randomly replace a number in the reservoir.
  For k+i, pick it with a probability of k/(k+i), and randomly replace a number in the reservoir.
  Repeat until k+i reaches n

  Further Explanation: For this problem, the simplest concrete example would be
  a stream that only contained a single item. In this case, our algorithm
  should return this single element with probability 1.

  Now let’s try a slightly harder problem, a stream with exactly two elements.
  We know that we have to hold on to the first element we see from this stream,
  because we don’t know if we’re in the case that the stream only has one
  element. When the second element comes along, we know that we want to return
  one of the two elements, each with probability 1/2. So let’s generate a
  random number R between 0 and 1, and return the first element if R is less
  than 0.5 and return the second element if R is greater than 0.5.

  Now let’s try to generalize this approach to a stream with three elements.
  After we’ve seen the second element in the stream, we’re now holding on to
  either the first element or the second element, each with probability 1/2.
  When the third element arrives, what should we do? Well, if we know that
  there are only three elements in the stream, we need to return this third
  element with probability 1/3, which means that we’ll return the other element
  we’re holding with probability 1 – 1/3 = 2/3. That means that the probability
  of returning each element in the stream is as follows:

  First Element: (1/2)(prob of selecting) * (2/3)(probablity of holding) = 1/3
  Second Element: (1/2) * (2/3) = 1/3
  Third Element: 1/3

  By considering the stream of three elements, we see how to generalize this
  algorithm to any N: at every step N, keep the next element in the stream with
  probability 1/N. This means that we have an (N-1)/N probability of keeping
  the element we are currently holding on to, which means that we keep it with
  probability (1/(N-1)) * (N-1)/N = 1/N.

- Implementing operators using ne
```
a > b == b < a
a <= b == !(b < a)
a >= b == !(a < b)
It's even possible to implement equality in terms of less than (Kind of abusing my meta-syntax here):

(a == b) == (!(a < b) && !(b < a))
(a != b) == (a < b || b < a)
```

- tookenization
```
vector<std::string> split(const std::string &str, char delim) {
  std::vector<std::string> tokens;
  std::string token;
  std::istringstream tokenStream(str);
  while (std::getline(tokenStream, token, delim)) {
    // cout << token << "\n";
    // cout << trim(token) << "\n";
    tokens.push_back(trim(token));
  }
  return tokens;
}

```
