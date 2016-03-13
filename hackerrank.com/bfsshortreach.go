package main

import (
	"container/list"
	"math"

	"fmt"
)

const max = math.MaxInt64

// solve uses BFS
func solve(s int, g [][]int) []int64 {
	u := make([]bool, len(g))
	d := make([]int64, len(g))
	for i := 0; i < len(d); i++ {
		d[i] = max
	}
	d[s] = 0

	q := list.New()
	q.PushBack(s)

	for e := q.Front(); e != nil; e = e.Next() {
		ch := e.Value.(int)
		if u[ch] {
			continue
		}
		u[ch] = true
		for _, v := range g[ch] {
			if d[ch]+6 < d[v] {
				d[v] = d[ch] + 6
			}
			q.PushBack(v)
		}
	}

	return d
}

func print(d []int64, s int) {
	for i, v := range d {
		if i == s {
			continue
		} else if v == max {
			fmt.Print("-1 ")
		} else {
			fmt.Printf("%d ", v)
		}
	}
	fmt.Println()
}

func main() {
	var t, n, m, u, v, s int
	fmt.Scanf("%d\n", &t)
	for it := 0; it < t; it++ {
		fmt.Scanf("%d %d\n", &n, &m)

		g := make([][]int, n)
		for i := 0; i < len(g); i++ {
			g[i] = make([]int, 0)
		}
		for i := 0; i < m; i++ {
			fmt.Scanf("%d %d\n", &u, &v)
			u--
			v--
			g[u] = append(g[u], v)
			g[v] = append(g[v], u)
		}
		fmt.Scanf("%d\n", &s)
		r := solve(s-1, g)
		print(r, s-1)
	}
}
