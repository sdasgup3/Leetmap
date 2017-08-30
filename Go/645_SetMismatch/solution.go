package solution

import (

)

func SetMismatch(moves string) bool {
	count := 0
	for _, move := range moves {
		if move == 'U' || move == 'R' {
			count++
		} else {
			count--
		}
	}

	if 0 == count {
		return true
	}
	return false
}
