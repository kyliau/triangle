package main

import (
	"fmt"
)

type Node struct {
	val         int
	left, right *Node
}

func makeTree(nums []int) *Node {
	nodes := make([]Node, 0, len(nums))
	for _, num := range nums {
		nodes = append(nodes, Node{num, nil, nil})
	}
	// Link the nodes
	for i, j, level := 0, 0, 1; i+level < len(nodes); i++ {
		nodes[i].left = &nodes[i+level]
		nodes[i].right = &nodes[i+level+1]
		j++
		if j == level {
			j = 0
			level++
		}
	}
	return &nodes[0]
}

func maxSumPath(root *Node) int {
	if root == nil {
		return 0
	}
	if root.left == nil && root.right == nil {
		return root.val
	}
	left := maxSumPath(root.left)
	right := maxSumPath(root.right)
	if left > right {
		return root.val + left
	}
	return root.val + right
}

func main() {
	root := makeTree([]int{5, 9, 6, 4, 6, 8, 0, 7, 1, 5})
	fmt.Println(maxSumPath(root))
}
