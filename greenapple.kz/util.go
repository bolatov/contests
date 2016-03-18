package main

import (
	"fmt"
	"math/rand"
)

func isSorted(s []int) bool {
	for i := 1; i < len(s); i++ {
		if s[i-1] > s[i] {
			return false
		}
	}
	return true
}

func randomInts(n, max int) []int {
	s := make([]int, n)
	for i := 0; i < n; i++ {
		s[i] = rand.Intn(max)
	}
	return s
}

func printSlice(arr []int) {
	for _, v := range arr {
		fmt.Printf("%v ", v)
	}
	fmt.Println()
}
