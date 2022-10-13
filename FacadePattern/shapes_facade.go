package main

import "fmt"

// Shape interface with draw method to be implemented by concrete shapes
type Shape interface {
	draw() error
}

// Rectangle struct with length and width fields
type Rectangle struct {
	length float64
	width  float64
}

// Square struct with side field
type Square struct {
	side float64
}

// Circle struct with radius field
type Circle struct {
	radius float64
}

// Implementation of draw method for Rectangle. Assumed to have some complicated logic in actual code
func (r *Rectangle) draw() error {
	area := r.length * r.width
	fmt.Println("Complicated logic of Rectangle::draw() called." + fmt.Sprintf("Area Drawn: %f", area))
	return nil
}

// Implementation of draw method for Square. Assumed to have some complicated logic in actual code
func (s *Square) draw() error {
	fmt.Println("Complicated logic of Square::draw() called." + fmt.Sprintf("Area Drawn: %f", s.side*s.side))
	return nil
}

// Implementation of draw method for Circle. Assumed to have some complicated logic in actual code
func (c *Circle) draw() error {
	fmt.Println("Complicated logic of Circle::draw() called." + fmt.Sprintf("Area Drawn: %f", 3.14*c.radius*c.radius))
	return nil
}

// ShapeMakerFacade struct with pointers to concrete shapes to be drawn by client
//
// ShapeMakerFacade abstracts the complicated logic of:
// 1. Delegating Dimensions
// 2. Calculating Areas
// 3. Drawing Shapes
//
// Resources: 
// - https://en.wikipedia.org/wiki/Facade_pattern,
// - https://www.tutorialspoint.com/design_pattern/facade_pattern.htm
type ShapeMakerFacade struct {
	circle *Circle
	rectangle *Rectangle
	square *Square
}

// NewShapeMakerFacade returns a new ShapeMakerFacade with pointers to concrete shapes
func NewShapeMakerFacade() *ShapeMakerFacade {
	// ShapeMakerFacade can keep default dimensions of shapes as needed
	return &ShapeMakerFacade{
		circle: &Circle{ radius: 10 },
		rectangle: &Rectangle{ length: 10, width: 20 },
		square: &Square{ side: 10 },
	}
}

// drawCircle is a helper method to draw circle, abstracting the complicated logic of calculating area
func (s *ShapeMakerFacade) drawCircle() error {
	return s.circle.draw()
}

// drawRectangle is a helper method to draw rectangle, abstracting the complicated logic of calculating area
func (s *ShapeMakerFacade) drawRectangle() error {
	return s.rectangle.draw()
}

// drawSquare is a helper method to draw square, abstracting the complicated logic of calculating area
func (s *ShapeMakerFacade) drawSquare() error {
	return s.square.draw()
}

func main() {
	shapeMaker := NewShapeMakerFacade()

	shapeMaker.drawCircle()
	shapeMaker.drawRectangle()
	shapeMaker.drawSquare()
}
