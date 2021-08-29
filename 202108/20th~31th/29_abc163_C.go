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
	N := scanInt()
	m := make(map[int]int)
	for i := 0; i < N-1; i++ {
		tmp := scanInt()
		tmp--
		m[tmp]++
	}
	for i := 0; i < N; i++ {
		fmt.Println(m[i])
	}
}
