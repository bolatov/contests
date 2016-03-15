package main

import (
	"fmt"
)

func mx(x []int) int {
	amax := 0
	n := len(x)
	for i := 0; i < n; i++ {
		for j := i; j < n; j++ {
			t := x[i]
			for k := i; k <= j; k++ {
				t |= x[k]
			}
			if amax < t {
				amax = t
			}
		}
	}
	return amax
}

func main() {
	var n int
	fmt.Scan(&n)
	a := make([]int, n)
	b := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	for i := 0; i < n; i++ {
		fmt.Scan(&b[i])
	}
	fmt.Println(mx(a) + mx(b))
}
