package main

import (
	"bufio"
	"fmt"
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

func printStr(s string) {
	wr.WriteString(s)
}

func println() {
	wr.WriteByte('\n')
}

func main() {
	defer wr.Flush()
	sc.Split(bufio.ScanWords)

	n, a, b, t := readInt(), readInt64(), readInt64(), readInt64()
	s := readStr()

	var tm, res int64
	is := true
	for i := 0; i < n && tm < t; i++ {
		tm++
		si := string(s[i])
		if (is && si == "h") || (!is && si == "w") {
			tm += b
			is = !is
		}
		tm += a
		res = int64(i) + 1
		fmt.Printf("%v %v\n", i, tm)
	}
	printInt64s(res)
	println()
}
