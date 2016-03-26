package main

import (
	"bufio"
	"os"
	"strconv"
)

func invCount(lst []int) int {
	_, j := mergeInvCount(lst)
	return j
}

func mergeInvCount(lst []int) ([]int, int) {
	if len(lst) <= 1 {
		return lst, 0
	}
	middle := len(lst) / 2
	left, a := mergeInvCount(lst[:middle])
	right, b := mergeInvCount(lst[middle:])
	result, c := mergeCountSplitInversion(left, right)
	return result, (a + b + c)
}

func mergeCountSplitInversion(left, right []int) ([]int, int) {
	result := make([]int, 0)
	var i, j, count int
	left_len := len(left)
	for i < left_len && j < len(right) {

		if left[i] <= right[j] {

			result = append(result, left[i])
			i++
		} else {
			result = append(result, right[j])
			count = count + left_len - i
			j++
		}
	}
	for _, v := range left[i:] {
		result = append(result, v)
	}
	for _, v := range right[j:] {
		result = append(result, v)
	}
	return result, count
}

func main() {
	defer wr.Flush()
	sc.Split(bufio.ScanWords)

	var n, k int = readInt(), readInt()
	v := make([]int, n)
	for i := 0; i < n; i++ {
		v[i] = i + 1
	}
	p, q := 0, n-1
	for i := 0; i < k; i++ {
		if q <= p {
			break
		}
		v[p], v[q] = v[q], v[p]
		p++
		q--
	}
	// for _, vl := range v {
	// 	printInts(vl)
	// }
	// println()
	r := invCount(v)
	printInts(r)
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
