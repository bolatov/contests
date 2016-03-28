package main

import (
	"bufio"
	"container/list"
	"os"
	"strconv"
)

func main() {
	defer wr.Flush()
	sc.Split(bufio.ScanWords)

	var n, b int = readInt(), readInt()
	b++
	var t, d int64
	res := make([]int64, n)
	q := list.New()
	for i := 0; i < n; i++ {
		t, d = readInt64(), readInt64()

		if i == 0 {
			res[i] = t + d
			q.PushBack(res[i])
			continue
		}

		// clear queue from finished tasks
		var next *list.Element
		for e := q.Front(); q.Len() > 0 && e != nil && e.Value.(int64) <= t; e = next {
			next = e.Next()
			q.Remove(e)
		}
		if q.Len() >= b {
			res[i] = -1
		} else if q.Len() == 0 {
			res[i] = t + d
			q.PushBack(res[i])
		} else {
			res[i] = q.Back().Value.(int64) + d
			q.PushBack(res[i])
		}
	}
	for _, v := range res {
		printInt64s(v)
	}
	println()
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
