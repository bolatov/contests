package main

func quickSort(s []int) {
	qSort(s, 0, len(s)-1)
}

func qSort(s []int, l, r int) {
	if l >= r {
		return
	}

	var idx int = partition(s, l, r)
	qSort(s, l, idx-1)
	qSort(s, idx+1, r)
}

func swap(s []int, i, j int) {
	s[i], s[j] = s[j], s[i]
}

func partition(s []int, l, r int) int {
	var mid int = (l + r) / 2
	swap(s, mid, r)
	var pivot int = s[r]

	var i int = l - 1
	for j := l; j < r; j++ {
		if s[j] < pivot {
			i++
			swap(s, i, j)
		}
	}
	swap(s, i+1, r)
	return i + 1
}
