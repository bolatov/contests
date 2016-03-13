package main

import "fmt"

func max(i, j int64) int64 {
	if i > j {
		return i
	} else {
		return j
	}
}

func main() {
	var n, m, a, b int
	var k int64
	fmt.Scanf("%d %d\n", &n, &m)
	v := make([]int64, n+1)
	for i := 0; i < m; i++ {
		fmt.Scanf("%d %d %d\n", &a, &b, &k)
		v[a-1] += k
		v[b] -= k
	}
	c := v[0]
	r := c
	for i := 1; i < n; i++ {
		c += v[i]
		r = max(r, c)
	}
	fmt.Println(r)
}
