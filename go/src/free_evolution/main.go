package main

import "fmt"

type point struct {
	x float64
	y float64
}

type upperNeuron struct {
	in            point
	out           point
	amplification float64
	sensitivity   float64
	bias          float64
}

type upperCode []upperNeuron

type lowNeuron struct {
	in            point
	out           point
	amplification float64
	sensitivity   float64
	bias          float64
}

type lowCode []lowNeuron

func main() {
	fmt.Println("Hello, World!")
}
