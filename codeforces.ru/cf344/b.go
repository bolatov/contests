package main

import (
	"bufio"
	"os"
	"strconv"
)

var (
	sc *bufio.Scanner = bufio.NewScanner(os.Stdin)
	wr *bufio.Writer  = bufio.NewWriter(os.Stdout)
)

func readInt() int {
	sc.Scan()
	ans, _ := strconv.Atoi(sc.Text())
	return ans
}

func printInts(ints ...int) {
	for _, v := range ints {
		wr.WriteString(strconv.Itoa(v))
		wr.WriteByte(' ')
	}
}

func println() {
	wr.WriteByte('\n')
}

func main() {
	defer wr.Flush()
	sc.Split(bufio.ScanWords)

	var n, m, k int = readInt(), readInt(), readInt()
	n++
	m++
	rs := make([]int, n)
	rt := make([]int, n)
	cs := make([]int, m)
	ct := make([]int, m)
	var t, rc, a int
	for i := 1; i <= k; i++ {
		t, rc, a = readInt(), readInt(), readInt()
		if t == 1 {
			rs[rc] = a
			rt[rc] = i
		} else {
			cs[rc] = a
			ct[rc] = i
		}
	}

	for i := 1; i < n; i++ {
		for j := 1; j < m; j++ {
			var v int
			if rt[i] == ct[j] {
				v = 0
			} else if rt[i] > ct[j] {
				v = rs[i]
			} else {
				v = cs[j]
			}
			printInts(v)
		}
		println()
	}
}
