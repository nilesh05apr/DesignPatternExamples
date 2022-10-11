package main

import "fmt"

type Shape interface {
	draw() error
}

type Rectangle struct {
	length float64
	width  float64
}

type Square struct {
	side float64
}

type Circle struct {
	radius float64
}

func (r *Rectangle) draw() error {
	area := r.length * r.width
	fmt.Println("Complicated logic of Rectangle::draw() called." + fmt.Sprintf("Area Drawn: %f", area))
	return nil
}

func (s *Square) draw() error {
	fmt.Println("Complicated logic of Square::draw() called." + fmt.Sprintf("Area Drawn: %f", s.side*s.side))
	return nil
}

func (c *Circle) draw() error {
	fmt.Println("Complicated logic of Circle::draw() called." + fmt.Sprintf("Area Drawn: %f", 3.14*c.radius*c.radius))
	return nil
}

type ShapeMakerFacade struct {
	circle *Circle
	rectangle *Rectangle
	square *Square
}

func NewShapeMakerFacade() *ShapeMakerFacade {
	// ShapeMakerFacade can keep default dimensions of shapes as needed
	return &ShapeMakerFacade{
		circle: &Circle{ radius: 10 },
		rectangle: &Rectangle{ length: 10, width: 20 },
		square: &Square{ side: 10 },
	}
}

func (s *ShapeMakerFacade) drawCircle() error {
	return s.circle.draw()
}

func (s *ShapeMakerFacade) drawRectangle() error {
	return s.rectangle.draw()
}

func (s *ShapeMakerFacade) drawSquare() error {
	return s.square.draw()
}

func main() {
	// ShapeMakerFacade abstracts the complicated logic of
	// 1. Delegating Dimensions
	// 2. Calculating Areas
	// 3. Drawing Shapes
	shapeMaker := NewShapeMakerFacade()

	shapeMaker.drawCircle()
	shapeMaker.drawRectangle()
	shapeMaker.drawSquare()
}
