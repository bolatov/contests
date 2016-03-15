package main

import "testing"

func TestQuickSort(t *testing.T) {
	arr := []int{9, 7, 5, 11, 12, 2, 14, 3, 10, 6}
	quickSort(arr)
	if !isSorted(arr) {
		t.Error("Array is not sorted")
	}
}

func TestQuickSortBig(t *testing.T) {
	arr := randomInts(100000, 10000000)
	quickSort(arr)
	if !isSorted(arr) {
		t.Error("Array is not sorted")
	}
}
