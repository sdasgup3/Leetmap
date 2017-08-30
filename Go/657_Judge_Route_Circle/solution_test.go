package solution

import (
	"testing"
)

func TestJudgeCircle(t *testing.T) {
	for _, tc := range []struct {
		input string
		want  bool
	}{
		{
			input: "LL",
			want:  false,
		},
		{
			input: "URDL",
			want:  true,
		},
		{
			input: "URDLDD",
			want:  false,
		},
	} {

		got := JudgeCircle(tc.input)
		if got != tc.want {
			t.Errorf("Fail\n\t input: %#v\n\t got: %#v\n\t want: %#v",
				tc.input, got, tc.want)
		}

	}
}
