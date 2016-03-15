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

func readInt() int64 {
	sc.Scan()
	ans, _ := strconv.ParseInt(sc.Text(), 10, 64)
	return ans
}

func printInts(ints ...int64) {
	for _, v := range ints {
		wr.WriteString(strconv.FormatInt(v, 10))
		wr.WriteByte(' ')
	}
}

func println() {
	wr.WriteByte('\n')
}

type pt struct {
	x, y int64
}

func main() {
	defer wr.Flush()
	sc.Split(bufio.ScanWords)

	var n int64 = readInt()

	cols := make(map[int64]int64)
	rows := make(map[int64]int64)
	set := make(map[pt]int64)
	for i := int64(0); i < n; i++ {
		x, y := readInt(), readInt()
		if _, prs := cols[x]; prs {
			cols[x] = cols[x] + 1
		} else {
			cols[x] = 1
		}
		if _, prs := rows[y]; prs {
			rows[y] = rows[y] + 1
		} else {
			rows[y] = 1
		}
		p := pt{x, y}
		if _, prs := set[p]; prs {
			set[p] = set[p] + 1
		} else {
			set[p] = 1
		}
	}
	var r int64
	for _, v := range rows {
		r += v * (v - 1) / 2
	}
	for _, v := range cols {
		r += v * (v - 1) / 2
	}
	for _, v := range set {
		if v > 1 {
			r -= v * (v - 1) / 2
		}
	}
	printInts(r)
	println()
}
