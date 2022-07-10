package main

import (
	"fmt"
)

var matrix_cop = [][]int{}
var judge_Matrix = [][]int{}
var ans = []int{}
var judge_sum int = 0
var clomn int = 0
var line int = 0

func right(pos_x int, pos_y int) int {
	//返回y坐标
	if judge_Matrix[pos_x][pos_y] != -101 {
		ans = append(ans, matrix_cop[pos_x][pos_y])
		judge_sum++
		judge_Matrix[pos_x][pos_y] = -101
	}
	for pos_y+1 <= line && judge_Matrix[pos_x][pos_y+1] != -101 {
		ans = append(ans, matrix_cop[pos_x][pos_y+1])
		pos_y += 1
		judge_sum++
		judge_Matrix[pos_x][pos_y] = -101
	}
	return pos_y
}
func down(pos_x int, pos_y int) int {
	//返回x坐标
	//fmt.Println("down")
	if judge_Matrix[pos_x][pos_y] != -101 {
		ans = append(ans, matrix_cop[pos_x][pos_y])
		judge_sum++
		judge_Matrix[pos_x][pos_y] = -101
	}
	for pos_x+1 <= clomn && judge_Matrix[pos_x+1][pos_y] != -101 {
		ans = append(ans, matrix_cop[pos_x+1][pos_y])
		pos_x += 1
		judge_sum++
		judge_Matrix[pos_x][pos_y] = -101
	}
	return pos_x
}
func left(pos_x int, pos_y int) int {
	//返回y坐标
	//fmt.Println("left")
	if judge_Matrix[pos_x][pos_y] != -101 {
		ans = append(ans, matrix_cop[pos_x][pos_y])
		judge_sum++
		judge_Matrix[pos_x][pos_y] = -101
	}
	for pos_y-1 >= 0 && judge_Matrix[pos_x][pos_y-1] != -101 {
		ans = append(ans, matrix_cop[pos_x][pos_y-1])
		pos_y -= 1
		judge_sum++
		judge_Matrix[pos_x][pos_y] = -101
	}
	return pos_y
}
func up(pos_x int, pos_y int) int {
	//返回x坐标
	if judge_Matrix[pos_x][pos_y] != -101 {
		ans = append(ans, matrix_cop[pos_x][pos_y])
		judge_sum++
		judge_Matrix[pos_x][pos_y] = -101
	}
	for pos_x-1 >= 0 && judge_Matrix[pos_x-1][pos_y] != -101 {
		ans = append(ans, matrix_cop[pos_x-1][pos_y])
		pos_x -= 1
		judge_sum++
		judge_Matrix[pos_x][pos_y] = -101
	}
	return pos_x
}

func spiralOrder(matrix [][]int) []int {
	matrix_cop = matrix
	judge_Matrix = matrix
	judge_sum = 0
	line = len(matrix[0]) - 1
	clomn = len(matrix) - 1
	ans = []int{}
	pos_x := 0
	pos_y := 0
	leng := len(matrix) * len(matrix[0])
	for judge_sum < leng {
		pos_y = right(pos_x, pos_y)
		pos_x = down(pos_x, pos_y)
		pos_y = left(pos_x, pos_y)
		pos_x = up(pos_x, pos_y)
	}
	return ans
}
func main() {
	aa := [][]int{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
	a := [][]int{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}
	ans := spiralOrder(aa)
	fmt.Println(ans)
	ans = spiralOrder(a)
	fmt.Println(ans)
}
