package solution

import (
	"testing"
)

func TestCheckPossibility(t *testing.T) {
	for _, tc := range []struct {
		input []int
		want  bool
	}{
		{
			input: []int{4, 2, 3},
			want:  true,
		},
		{
			input: []int{4, 2, 1},
			want:  false,
		},
		{
			input: []int{3, 4, 2, 3},
			want:  false,
		},
	} {
		got := CheckPossibility(tc.input)
		if got != tc.want {
			t.Errorf("Fail\n\t input: %#v\n\t got: %#v\n\t want: %#v",
				tc.input, got, tc.want)
		}
	}
}
