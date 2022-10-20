package main

import (
	"fmt"
	"errors"
)

type Shape interface {
	Circle() (float64, error)
	Square() (float64, error)
	Rectangle() (float64, error)
}

type dimensions struct {
	height float64
	length float64
}

func (d dimensions) Circle() float64 {
	return d.height * d.height * 3.14
}

func (d dimensions) Square() float64 {
	return d.height * d.height
}

func (d dimensions) Rectangle() float64 {
	return d.height * d.length
}


func getArea(shape string) (float64, error) {

	if(shape == "circle") {
		return dimensions{height: 10}.Circle(), errors.New("Circle")
	} else if (shape == "square") {
		return dimensions{height: 10}.Square(), errors.New("Square")
	} else if (shape == "rectangle") {
		return dimensions{height: 10, length: 20}.Rectangle(), errors.New("Rectangle")
	}
	return 0, errors.New("Invalid shape")
}

func getAreaProxy(shape string) float64 {


	cache := make(map[string]float64)
	area := func(shape string) (float64) {
		if _, ok := cache[shape]; !ok {
			cache[shape],_ = getArea(shape)
		}
		return cache[shape]
	}

	return area(shape)

}

func main() {
	fmt.Println(getAreaProxy("circle"))
	fmt.Println(getAreaProxy("square"))
	fmt.Println(getAreaProxy("rectangle"))
	fmt.Println(getAreaProxy("circle"))
	fmt.Println(getAreaProxy("square"))
	fmt.Println(getAreaProxy("rectangle"))
}