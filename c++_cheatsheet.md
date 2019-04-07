### C++ Cheatsheet

  - tolower
    - This is a method to convert a char to another char; Not for string  
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
    ```
    priority_queue::push()  //pushng
    priority_queue::pop()  //pop deletes but returns nothing
    priority_queue::top();
    ```
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

  - ```std::map``` member functions
    - Initialize
    ```
      map<int, int> M = {
        {1,2},
        {3,4}
      };

      map<int, int> M = ({
        {1,2},
        {3,4}
      });
    ```

    - pair
    ````
      Do not use std::pair as a key of a map. Use unordered_map<int, unordered_map<int, bool> instead;
    ```
    - erase
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
  auto cmp = ...
  set<Class_C, decltype(cmp)> S(cmp);

  pair<it, bool> S.insert();

  The first member pair::first set to an iterator pointing to either the newly
  inserted element or to the equivalent element already in the set. The
  pair::second element in the pair is set to true if a new element was inserted
  or false if an equivalent element already existed.

  ```

  - STL heap
  ```
    vector<int> T = {2,5,8,1,0,3};
    auto cmp = [](int a, int b) {
      return a < b;
    };
    make_heap(T.begin(), T.end(), cmp);

    vector<int> P = {20,50,80};
    for(auto p : P) {
      T.push_back(p);
      push_heap(T.begin(), T.end(), cmp);
    }

    while(!T.empty()) {
      cout << T[0] <<  " ";
      pop_heap(T.begin(), T.end(), cmp);
      T.pop_back();
    }
  ```
