package solution

import (
	"testing"
)

func TestFindTwoMissing(t *testing.T) {
	for _, tc := range []struct {
		input []int
		want  []int
	}{
		{
			input: []int{1, 2, 2, 4},
			want:  []int{2, 3},
		},
		{
			input: []int{1, 2, 4, 4, 5,6},
			want:  []int{4, 3},
		},
	} {

		got := FindErrorNums(tc.input)

		if false == equalSliceInts(got, tc.want) {
			t.Errorf("Fail\n\t input: %#v\n\t got: %#v\n\t want: %#v",
				tc.input, got, tc.want)
		}
	}
}

func equalSliceInts(a, b []int) bool {
	if len(a) != len(b) {
		return false
	}

	for i := range a {
		if a[i] != b[i] {
			return false
		}
	}

	return true
}
