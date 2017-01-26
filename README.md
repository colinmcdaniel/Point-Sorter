# Point Sorter

* [GitHub Repository](https://github.com/colinmcdaniel/Point-Sorter)

## Functionality

This program prompts the user to enter points with various attributes, and then prints these points in a sorted order.

This program utilizes polymorphism to store a vector of pointers to Point2D objects, along with the derived classes ColorPoint2D and WeightedPoint2D.

### Ordering Rules
1. Point2D < ColorPoint2D < WeightedPoint2D objects.
2. The lesser of two objects of the same type is defined to be the lesser of the distances from the origin (0,0).
  1. If two Point2D objects have the same distance from the origin [i.e. (-2,3) and (2,3)], the one with the smallest angle to the origin in a counterclockwise orientation is defined to be smaller.
  2. If two ColorPoint2D objects have the same distance from the origin, the one whose color is smaller in lexicographic ordering.
Date: February 10, 2013.
1Our order will not be one in the mathematical sense, which needs to preserve order under certain operations like point-wise addition to both points by a third point. No need to dwell on this, but a quick google search on ordering may leave you confused.
 1
2
PIC 10B DESALVO
 Figure 1. Picture of a point in polar coordinates, with radius r and angle φ. Taken from the Wikipedia page for Complex Numbers.
6. For a WeightedPoint2D object, first attempt to compare the (x,y)-coordinates, and if there is a tie, the lesser point is the one whose weight is smaller.

## Usage



