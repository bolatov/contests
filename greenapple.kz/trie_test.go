package main

import (
	"math/rand"
	"testing"
	"time"
)

var src = rand.NewSource(time.Now().UnixNano())

const letterBytes = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
const (
	letterIdxBits = 6                    // 6 bits to represent a letter index
	letterIdxMask = 1<<letterIdxBits - 1 // All 1-bits, as many as letterIdxBits
	letterIdxMax  = 63 / letterIdxBits   // # of letter indices fitting in 63 bits
)

//
// source: http://stackoverflow.com/questions/22892120/how-to-generate-a-random-string-of-a-fixed-length-in-golang
func RandStringBytesMaskImprSrc(n int) string {
	b := make([]byte, n)
	// A src.Int63() generates 63 random bits, enough for letterIdxMax characters!
	for i, cache, remain := n-1, src.Int63(), letterIdxMax; i >= 0; {
		if remain == 0 {
			cache, remain = src.Int63(), letterIdxMax
		}
		if idx := int(cache & letterIdxMask); idx < len(letterBytes) {
			b[i] = letterBytes[idx]
			i--
		}
		cache >>= letterIdxBits
		remain--
	}

	return string(b)
}

func initRandDict() []string {
	var dict []string
	var n = 50
	for i := 0; i < n; i++ {
		r := rand.Intn(20)
		s := RandStringBytesMaskImprSrc(r)
		if s != "" {
			dict = append(dict, s)
		}
	}

	return dict
}

func initDict() []string {
	return []string{
		"to", "A", "tea", "ted", "ten", "inn",
	}
}

func TestSearchIter(t *testing.T) {
	ws := initDict()
	r := initTrie(ws)
	for _, w := range ws {
		got := searchWord(r, w)
		if !got {
			t.Errorf("Expected %q to be found in trie", w)
		}
	}

	non := "_non_existent"
	got := searchWord(r, non)
	if got {
		t.Errorf("Expected %q NOT to be found in trie", non)
	}
}

func TestSearchIterWithRand(t *testing.T) {
	ws := initRandDict()
	r := initTrie(ws)
	for _, w := range ws {
		got := searchWord(r, w)
		if !got {
			t.Errorf("Expected %q to be found in trie", w)
		}
	}
}
