package main

import (
	"sync"
	"time"
)

var lock sync.Mutex

func Merge2Channels(f func(int) int, in1 <-chan int, in2 <- chan int, out chan<- int, n int) {
	go func() {
		lock.Lock()
		channels := make([]chan int, n)
		for i := 0; i < n; i++ {
			channel := make(chan int)
			channels[i] = channel
			x1 := <-in1
			x2 := <-in2
			go func() {
				channel <- f(x1) + f(x2)
			}()
		}
		for _, channel := range channels {
			out <- <-channel
		}
		lock.Unlock()
	}()
}

func main() {
	out := make(chan int)
	in1 := make(chan int)
	in2 := make(chan int)

	go func() {
		in1 <- 1
		in1 <- 2
		in1 <- 3
		in1 <- 4
		close(in1)
	}()

	go func() {
		in2 <- 1
		in2 <- 2
		in2 <- 3
		in2 <- 4
		close(in2)
	}()

	Merge2Channels(func(i int) int {
		time.Sleep(1 * time.Second)
		return i
	}, in1, in2, out, 2)
	Merge2Channels(func(i int) int {
		time.Sleep(1 * time.Second)
		return i
	}, in1, in2, out, 2)

	for i := 0; i < 4; i++ {
		print(<- out)
	}
}