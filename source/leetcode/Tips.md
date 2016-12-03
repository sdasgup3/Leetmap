### Bits
  - Count the nums of 1's  in N
    - Method 1

      ```
      Count[n] : Number of 1 bits
      Count[0] = 0;

      if n is odd; Count[n] = Count[n-1] + 1
      else Count[n] = Count[n/2]

      ```
    
    - Find the range 2 ^ x to 2^ (x+1) - 1  where n falls
      ```
        N  Count
        0   0
        1   1
      1 0  Count(0) + 1
      1 1  Count(1) + 1
    1 0 0  Count(0) + 1
    1 0 1  Count(1) + 1
    1 1 0  Count(2) + 1
    1 1 1  Count(3) + 1

      ```

