package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func scanInt() int {
	sc.Scan()
	i, err := strconv.Atoi(sc.Text())
	if err != nil {
		panic(err)
	}
	return i
}

const pi float64 = 3.1415926

// Go(1.14.1)
func main() {
	sc.Split(bufio.ScanWords)
	N, M := scanInt(), scanInt()
	vec := make([]int, M)
	for i := 0; i < M; i++ {
		vec[i] = scanInt()
	}
	count := 0
	for _, v := range vec {
		count += v
	}
	if N-count >= 0 {
		fmt.Println(N - count)
	} else {
		fmt.Println(-1)
	}
}
