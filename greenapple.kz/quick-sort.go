package main

func quickSort(s []int) {
	qSort(s, 0, len(s)-1)
}

func qSort(s []int, left, right int) {
	if left >= right {
		return
	}

	i, j := left, right

	// pivot
	mid := (left + right) / 2
	p := s[mid]

	for i <= j {
		for s[i] < p {
			i++
		}
		for s[j] > p {
			j--
		}
		if i <= j {
			s[i], s[j] = s[j], s[i]
			i++
			j--
		}
	}
	qSort(s, left, j)
	qSort(s, i, right)
}
