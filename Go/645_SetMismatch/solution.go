package solution

import (
)

func FindErrorNums2(nums []int) []int {
    xor :=0
    //Find xor of nums and [1...n]
    for i := 0 ; i < len(nums); i++ {
        xor = xor ^ nums[i]
        xor = xor ^ (i+1)
    }

    //Find the rightmost set bit
    rsb := xor & ^(xor-1)

    x,y := 0,0
    //Find xor of all elements having rsb ON
    for i := 0 ; i < len(nums); i++ {
        if 0 != (nums[i] & rsb) {
            x = x ^ nums[i]
        } else {
            y = y ^ nums[i]
        }
        if 0 != ((i+1) & rsb) {
            x = x ^ (i+1)
        } else {
            y = y ^ (i+1)
        }
    }

    //Figure out which one among is missing
    for i := 0 ; i < len(nums); i++ {
        if x == nums[i] {
            return []int{x,y}
        }
    }

    return []int{y,x}

 }

func FindErrorNums1(nums []int) []int {
	n := len(nums)
  k := n+1

	for i, _ := range nums {
		actual_val := nums[i] % k
    //fmt.Println(actual_val)
		nums[actual_val-1] = nums[actual_val-1] + k
	}

	dup, miss := -1, -1
	for i, _ := range nums {
		aux_val := nums[i] / k
		if 2 == aux_val {
			dup = i + 1
		}
		if 0 == aux_val {
			miss = i + 1
		}
	}

  // Unmodify the input array
  for i, _ := range nums {
    nums[i] = nums[i]%k
  }


	return []int{dup, miss}
}
