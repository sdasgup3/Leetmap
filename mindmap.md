## Array
  # 665. Non-decreasing Array
  - Example: A = [a b c  d]
      - Find all pairs such that A[i] > A[i+1]
        - If more that one such pairs, return false
        - We have one pair
          -  Let the pair be A[i] = b  and A[i+1] = c
          -  Try modifying b
              - We have  a <= b and b > c; Also b cannot be > c
                - So for the series to be in order we must have a <= c
          - Try Modifying c
            - We have  b > c && c <= d; Also c cannot be > d
              -  So for the series to be in order we must have b <= d
  - Example: 3 4 2 3
    - Pair: 4 2
      - Try modifying 4
        - Not possible as modified value can be at max 2, but 3 is not <= 2
      - Try modifying 2
        - Not possible as modified value can be at max 3, but 4 is not <= 3
  - Example 1 4 2 3
    - 4 is modifiable is the pair 4 2
  - Example 3 4 2 4
    - 2 is modifiable is the pair 4 2 

                -
