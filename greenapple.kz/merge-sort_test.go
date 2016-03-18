package main

import (
	"fmt"
	"testing"
)

func TestMergeSort(t *testing.T) {
	arr := randomInts(20, 100)
	fmt.Printf("[O]: ")
	printSlice(arr)
	arr = mergeSort(arr, 0, len(arr)-1, " ")
	if !isSorted(arr) {
		t.Error("Array is not sorted")
	}
}
