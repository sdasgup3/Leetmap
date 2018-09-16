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


### C++ Cheatsheet
  - find
    ```
     find(vector.begin(), vector.end(), target) - vector.begin();
    ```

  - nth_element
  ```
  vector<int> nums;
  auto cmp = ... ;
  nith_element(nums.begin(), nums.begin() + index, nums.end(), cmp);
  // NOTE: nums.begin() + index must point to the actual 0 based index
  // After the call, index posn will have the required element to be present based on cmp sorting.
  ```

  - stoi
    ```
    int stoi (const string&  str, size_t* idx = 0, int base = 10);

    Convert string to integer
    Parses str interpreting its content as an integral number of the specified base, which is returned as an int value.

    If idx is not a null pointer, the function also sets the value of idx to the position of the first character in str after the number.  
    ```

  - Vector
    - vector::insert(iterator, value)
      - you dont need to resize the array
    - Using arr or vector to initiaze another vector
    ```
    int arr[] = {1,2,3};
    vector<int> R(arr, arr + sizeof(arr)/sizeof(arr[0]));
    vector<int> R(V.begin(), V.end()); // Note the last element is always excluded
    ```
    - Using ```std::vector```is too slow than static arrays.
    ```
    NOTE: reserve does not change the size!! resize does
    vector<vector<bool>> table (n, vector<bool> (n, false)); //avoid using this

    After Declaration:
    vector<vector<int>> arr;
    arr.reserve(n);
    for(int i = 0 ; i < s ; i ++) {
      arr[i].reserve(n);
    }


    bool table[n][n];
    memset(table,false,sizeof(table));

    vector<vector<bool>> G(4);
    vector<char> A = {false, true};
    G[0] = A;

    vector<vector<char>> G;
    G.push_back({'1','1','0','0','0'});

    OR

    vector<vector<char>> G[1];
    G[0] = vector<char>({'1','1','0','0','0'});

    vector<int> D({0, 1, 3, 50, 75});

    insert pair in vecor
    V.push_back({e1, e2});

    ```

  - ```std::stack``` access member functions
  ```
  stack::push()  //pushng
  stack::pop()  //pop deletes but returns nothing
  stack::top(); // Use this sequesnce instead
  statck::pop();
  ```

  - ```std::queue```  access member functions

  ```
  queue::front(), queue::back() // Access the front and back of the queue
  queue::push(); // insert element at the back, i.e. after the element accessed by back
  queue::pop();  //removes the front element as  accessed by front();

  /* As before pop deletes but returns nothing, so to access the elemnt before deleting it
  ** do the following
  */
  queue::front();
  queue::pop();
  ```

  - priority_queue
    - (Runtime analysis)[http://www.eecs.wsu.edu/~ananth/CptS223/Lectures/heaps.pdf]
    - constant time lookup and logaritmic time insertion and extraction
    - Insertion of a vector into priority_queue
     ```
     //nlogn
     for(auto n : nums) {
       Q.push(n);
     }
     //n
     priority_queue<T, vector<T>, decltype(cmp)> Q(cmp, nums);
     ```
    - Usage
    ```
    #include<algorithm>
    push/pop/top
    class mycomp {
      public:
      bool operator()(T a, T b) { //functors OR Funcion objects;
        //opposite ordering
      }
    };
    priority_queue<T, vector<T>, mycomp> Q;
    OR
    mycomp cmp;
    priority_queue<T, vector<T>, decltype(cmp)> Q(cmp);

    OR
    typedef bool (*Ty) (T a, T b);
    bool X (T a, T b) {
    //opposite ordering
    }
    priority_queue<T, vector<T>, Ty> Q(X);

    OR
    auto cmp = [](T a, T b) {} ;
    priority_queue<T, vector<T>, decltype(cmp)> Q(cmp);

    ```

  - ```std::string``` member funstions
    - string::string
    ```
    string t(26,0);
    t[0]++;

      ```
  - string::substring
    ```
    // Creates a substring
    string::substr(start, length); //  Ex. s = "codingpuzzle, s.substr(0,6) gives "coding"
    ```
  - string::find
    ```
    // Find a subchar / substring starting at an optional position pos
    size_t string::find(string/char, pos = 0)

    Returns: The position of the first character of the first match.
    If no matches were found, the function returns string::npos.

    size_t is an unsigned integral type (the same as member type string::size_type).
    ```
  - string::compare

    ```
    string::compare(string s); // returns 0,-1,1 as strlen function
    string::push_back(char);
    string::pob_back();
    string::append(int n, char c);// append n consecutive copies of c
    string::append(string/const char*);
    res = s[0] + to_string(len-2) + s[len-1]; // Is valid as there exist a string class friend operator '+' to handle each pair
                                          //(w.r.t left assocoativity)
    For comparision: string.compare(string) or string == string  
     ```
  - Splitting based on a dilimiter
    ```
    #include<sstream>
    #include<iterator>
    istringstream buffer(str);
    istream_iterator<string> begin(buffer);
    istream_iterator<string> end;
    vector<string> V(begin, end);
    ```

  - ```std::map``` member funstions
  ````
  Do not use std::pair as a key of a map. Use unordered_map<int, unordered_map<int, bool> instead;
  ```

  ```
  map::erase(key);

   map<int, int>::iterator  F = M.begin();
   map<int, int>::reverse_iterator  R = M.rbegin();
   F++;
   F - M.begin(); //ERROR: for bidirectional iterator  - op is not supported, only suported for random access iterator
   std::distance(F, M.begin());

    auto i = M.find(k - F->first);
    if(i != M.end()) {
      ...
    }
  ```

  - ```std::unordered_set<T>``` member funstions
  ```
  unordered_set::insert(<T>)
  unordered_set::count(<T>)
  ```

  - ```std::set```
  ```
  useful for set<vector<int>>
  ```

### Misc

This page is about solving coding questions mostly asked in interviews.The problem/analysis/solutions mentioned in the post are categorized and can be used as a quick summary of useful algorithms.


- [Array](http://codingpuzzle.blogspot.com/)
- [Hash Table](http://codingpuzzle.blogspot.com/)
- [Linked List](http://codingpuzzle.blogspot.com/)
- [Math](http://codingpuzzle.blogspot.com/search/label/Math)
- [Two Pointers](http://codingpuzzle.blogspot.com/)
- [String](http://codingpuzzle.blogspot.com/)
- [Divide and Conquer](http://codingpuzzle.blogspot.com/)
- [Binary Search](http://codingpuzzle.blogspot.com/search/label/binarytree)
- [Dynamic Programming](http://codingpuzzle.blogspot.com/)
- [Backtracking](http://codingpuzzle.blogspot.com/)
- [Stack](http://codingpuzzle.blogspot.com/)
- [Heap](http://codingpuzzle.blogspot.com/)
- [Greedy](http://codingpuzzle.blogspot.com/)
- [Sort](http://codingpuzzle.blogspot.com/)
- [Bit Manipulation](http://codingpuzzle.blogspot.com/)
- [Tree](http://codingpuzzle.blogspot.com/)
- [Depth-first Search](http://codingpuzzle.blogspot.com/)
- [Breadth-first Search](http://codingpuzzle.blogspot.com/)
- [Union Find](http://codingpuzzle.blogspot.com/)
- [Graph](http://codingpuzzle.blogspot.com/)
- [Design](http://codingpuzzle.blogspot.com/)
- [Topological Sort](http://codingpuzzle.blogspot.com/)
- [Trie](http://codingpuzzle.blogspot.com/)
- [Binary Indexed Tree](http://codingpuzzle.blogspot.com/)
- [Segment Tree](http://codingpuzzle.blogspot.com/)
- [Binary Search Tree](http://codingpuzzle.blogspot.com/)
- [Recursion](http://codingpuzzle.blogspot.com/)
- [Brainteaser](http://codingpuzzle.blogspot.com/)
- [Memoization](http://codingpuzzle.blogspot.com/)
