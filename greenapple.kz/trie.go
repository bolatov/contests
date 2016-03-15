package main

const (
	TERMINAL = "$"
)

type trieNode struct {
	// children
	ch map[rune]*trieNode
}

func newTrieNode() *trieNode {
	ch := make(map[rune]*trieNode)
	return &trieNode{ch}
}

// initTrie initializes a trie data structure
// based on a list of words and returns a reference
// to the root node.
func initTrie(ws []string) *trieNode {
	root := newTrieNode()
	for _, w := range ws {
		node := root
		w += TERMINAL
		for _, r := range w {
			ch, ok := node.ch[r]
			if ok {
				node = ch
			} else {
				node.ch[r] = newTrieNode()
				node = node.ch[r]
			}
		}
	}

	return root
}

// searchWord iteratively searches for the word w
// in the trie which starts with a node r.
// Returns true if trie contains the word w, false otherwise.
func searchWord(r *trieNode, w string) bool {
	if w == "" {
		return true
	}

	w += TERMINAL
	for _, v := range w {
		_, ok := r.ch[v]
		if !ok {
			return false
		}
		r = r.ch[v]
	}

	return true
}
