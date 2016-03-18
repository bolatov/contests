package main

import (
	"fmt"
)

func initHeap(s []int) []int {
	return s
}

func print(j int, s []int) {
	for i, v := range s {
		if i == j {
			fmt.Printf("^%v^ ", v)
		} else {
			fmt.Printf(" %v  ", v)
		}
	}
	// fmt.Printf("\t\t[%d]", j)
	fmt.Println()
}

func printX(k, j int, s []int) {
	// fmt.Printf("CHANGE:\t")
	for i, v := range s {
		if i == k || i == j {
			fmt.Printf("[%d] ", v)
		} else {
			fmt.Printf(" %v  ", v)
		}
	}
	fmt.Println()
}

func h(i int, s []int, n int) []int {
	for ; i >= 0; i-- {
		l := 2*i + 1
		r := l + 1

		if (l < n && s[i] < s[l]) || (r < n && s[i] < s[r]) {
			if (r < n && s[l] > s[r]) || r >= n {
				// s[i], s[l] = s[l], s[i]
				t := s[i]
				s[i] = s[l]
				s[l] = t
				s = h(l, s, n)
			} else {
				// s[i], s[r] = s[r], s[i]
				t := s[i]
				s[i] = s[r]
				s[r] = t
				s = h(r, s, n)
			}
		}
	}

	return s
}

func heapify(s []int) []int {
	return h(len(s)/2, s, len(s))
}

func buildHeap(s []int) []int {
	for i := len(s) - 1; i >= 0; {
		// s[0], s[i] = s[i], s[0]
		t := s[0]
		s[0] = s[i]
		s[i] = t

		i--
		s = h(0, s, i)
		// printX(0, i, s)
	}
	return s
}

func heapSort(s []int) []int {
	s = initHeap(s)
	s = heapify(s)
	s = buildHeap(s)
	return s
}
