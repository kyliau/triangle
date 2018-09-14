package main

import (
	"fmt"
)

type Node struct {
	val         int
	left, right *Node
}

func makeNodes(nums []int) []Node {
	nodes := make([]Node, 0, len(nums))
	for _, num := range nums {
		nodes = append(nodes, Node{num, nil, nil})
	}
	return nodes
}

func linkNodes(nodes []Node) {
	for i, j, level := 0, 0, 1; i + level < len(nodes); i++ {
		nodes[i].left = &nodes[i + level]
		nodes[i].right = &nodes[i + level + 1]
		j++
		if j == level {
			j = 0
			level++
		}
	}
}

func main() {
	fmt.Println("Hello World")
	nodes := makeNodes([]int{5, 9, 6, 4, 6, 8, 0, 7, 1, 5})
	linkNodes(nodes)
	fmt.Print(nodes)
}
