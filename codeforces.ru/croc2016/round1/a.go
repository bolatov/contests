package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	defer wr.Flush()
	sc.Split(bufio.ScanWords)
	fr := func() string {
		var k, l string = readStr(), readStr()
		l = string(l[1]) + string(l[0])
		var s string = k + l
		var r string
		for _, v := range s {
			if string(v) != "X" {
				r += string(v)
			}
		}
		return r
	}
	fk := func(s string) string {
		for string(s[0]) != "A" {
			s = string(s[1:]) + string(s[0])
			// fmt.Println("..", s)
		}
		return s
	}
	var a, b string = fk(fr()), fk(fr())
	// fmt.Println("a", a)
	// fmt.Println("b", b)
	if a == b {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
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
