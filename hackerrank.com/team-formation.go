package main

import (
	"fmt"
	"math"
	"sort"
)

func min(i, j int) int {
	if i > j {
		return j
	} else {
		return i
	}
}

const max = math.MaxInt64

func main() {
	var t, n int
	fmt.Scan(&t)
	for it := 0; it < t; it++ {
		fmt.Scan(&n)
		v := make([]int, n)
		for i := 0; i < n; i++ {
			fmt.Scan(&v[i])
		}

		sort.Ints(v)
		if n == 0 {
			fmt.Println(0)
			continue
		} else if n == 1 {
			fmt.Println(1)
			continue
		}

		r, c := max, 1
		for i := 1; i < n; i++ {
			if v[i]-v[i-1] == 1 {
				c++
			} else {
				r = min(r, c)
				c = 1
			}
			if i == n-1 && c > 1 {
				r = min(r, c)
			}
		}
		fmt.Println(r)
	}
}
