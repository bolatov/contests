package main

import "fmt"

func mergeSort(arr []int, start, end int, s string) []int {
	if start == end {
		return arr
	}
	var mid int = (start + end) / 2
	l := mergeSort(arr[start:mid], start, mid, s+" ")
	r := mergeSort(arr[mid+1:end], mid+1, end, s+" ")

	fmt.Printf(s + "[L]: ")
	printSlice(l)
	fmt.Printf(s + "[R]: ")
	printSlice(r)

	i, j := start, mid+1
	buf := make([]int, start-end+1)
	for i <= mid && j <= end {
		if l[i] < r[i] {
			buf = append(buf, l[i])
			i++
		} else {
			buf = append(buf, r[j])
			j++
		}

	}
	for ; i <= mid; i++ {
		buf = append(buf, l[i])
	}
	for ; j <= end; j++ {
		buf = append(buf, r[j])
	}
	return buf
}
