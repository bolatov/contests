package main

import "testing"

func TestHeapSort(t *testing.T) {
	arr := randomInts(100000, 10000000)
	arr = heapSort(arr)
	if !isSorted(arr) {
		t.Error("Array is not sorted")
	}
}

func TestHeapify(t *testing.T) {
	n, maxValue := 10000, 50000
	s := randomInts(n, maxValue)
	s = heapify(s)
	for i, v := range s {
		l := 2*i + 1
		r := l + 1
		if l < n && v < s[l] {
			t.Fatal("Expected valid heap")
		}
		if r < n && v < s[r] {
			t.Fatal("Expected valid heap")
		}
	}
}
