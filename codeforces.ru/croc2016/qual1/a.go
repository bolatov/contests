package main

import (
	"bufio"
	"os"
	"strconv"
)

func main() {
	defer wr.Flush()
	sc.Split(bufio.ScanWords)

	var n, a, b int = readInt(), readInt(), readInt()
	f := func(x int) int {
		return x/2 + x%2
	}
	pplh, plch := f(n), f(a*b)
	if pplh > plch {
		printInts(-1)
		println()
	} else if b%2 == 1 {
		for i, k := 0, 1; i < a; i++ {
			for j := 0; j < b; j++ {
				if k <= n {
					printInts(k)
					k++
				} else {
					printInts(0)
				}
			}
			println()
		}
	} else {
		is := true
		var m, off int
		for i, k := 0, 1; i < a; i++ {
			if is {
				m, off = i*b+1, 1
			} else {
				m, off = (i+1)*b, -1
			}
			for j := 0; j < b; j++ {
				if k > n || m > n {
					printInts(0)
					m--
				} else {
					printInts(m)
					m += off
					k++
				}
			}
			is = !is
			println()
		}
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
