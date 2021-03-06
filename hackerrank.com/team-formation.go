package main

import (
	"bufio"
	"math"
	"os"
	"sort"
	"strconv"
)
f
unc main() {
	var t, n int
	t = readInt()
	for it := 0; it < t; it++ {
		n = readInt()
		v := make([]int, n)
		for i := 0; i < n; i++ {
			v[i] = readInt()
		}

		sort.Ints(v)
		if n == 0 {
			printInts(0)
			continue
		} else if n == 1 {
			printInts(1)
			continue
		}

		var (
			tsSize = []int{1}
			tsLast = []int{v[0]}
		)
		for i := 1; i < len(v); i++ {
			lst := len(tsLast) - 1
			if tsLast[lst] != v[i] {
				tsLast = append(tsLast, v[i])
				tsSize = append(tsSize, 1)
			} else {

			}
		}
		r := tsSize[0]
		for _, sz := range tsSize {
			r = min(r, sz)
		}
		printInts(r)
	}
}

var (
	sc *bufio.Scanner = bufio.NewScanner(os.Stdin)
	wr *bufio.Writer  = bufio.NewWriter(os.Stdout)
)

func readInt() int {
	sc.Scan()
	ans, _ := strconv.Atoi(sc.Text())
	return ans
}

func readInt64() int64 {
	sc.Scan()
	ans, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return ans
}

func printInts(ints ...int) {
	for _, v := range ints {
		wr.WriteString(strconv.Itoa(v))
		wr.WriteByte(' ')
	}
}
func printInt64s(ints ...int64) {
	for _, v := range ints {
		wr.WriteString(strconv.FormatInt(v, 10))
		wr.WriteByte(' ')
	}
}

func readStr() string {
	sc.Scan()
	return sc.Text()
}

func println() {
	wr.WriteByte('\n')
}

func min(i, j int) int {
	if i > j {
		return j
	} else {
		return i
	}
}

const max = math.MaxInt64
