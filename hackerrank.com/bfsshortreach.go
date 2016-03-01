package main

import (
	"fmt"
	"math"
)

type edge struct {
	u, v int
}

func (e *edge) String() string {
	return fmt.Sprintf("%d %d", e.u, e.v)
}

const max = math.MaxInt64

func solve(n, s int, es []edge) []int64 {
	r := make([]int64, n)
	for i := 0; i < n; i++ {
		r[i] = max
	}
	r[s-1] = 0
	for i := 0; i < n; i++ {
		for _, e := range es {
			if r[i] < max {
				if r[e.v-1] > r[e.u-1]+1 {
					r[e.v-1] = r[e.u-1] + 1
				}
			}
		}
	}

	return r
}

func print(r []int64) {
	for _, v := range r {
		if v == 0 {
			continue
		} else if v == max {
			fmt.Print("-1 ")
		} else {
			fmt.Printf("%d ", v*6)
		}
	}
	fmt.Println()
}

func main() {
	var t int
	fmt.Scanf("%d\n", &t)
	for it := 0; it < t; it++ {
		var n, m int
		fmt.Scanf("%d %d\n", &n, &m)

		var es []edge
		for i := 0; i < m; i++ {
			var e edge
			fmt.Scanf("%d %d\n", &e.u, &e.v)
			es = append(es, e)

		}
		var s int
		fmt.Scanf("%d\n", &s)
		r := solve(n, s, es)
		print(r)
	}
	fmt.Println()
}
