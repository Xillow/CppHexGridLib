// Hex Coordinate System Library
// Developed by Matthew Brown
// Based on Amit Patel's Write ups on Hexagonal Grids https://www.redblobgames.com/grids/hexagons

/*
The Hex Maps will be stored in arrays using a method of indexing
that will minimize array size while keeping shape of the array

as a result we will store it using Axial coordinatres,
but translate it to cube for algorithms
*/

#ifndef HCS_H
#define HCS_H

#include <assert.h>
#include <cmath>
#include <vector>
#include <iostream>


//FlatTop Orientation


class Hex
{
	private:
	const int q_, r_;

	public:
	Hex(int q, int r, int s) : q_(q), r_(r)
	{		
		assert(q + r + s == 0);
	}

	inline int q() const { return q_; }
	inline int r() const { return r_; }
	inline int s() const { return -q_ - r_; }

	/// @brief Equal operator overload
	/// @param rhs
	/// @return true if equal
	bool operator==(Hex rhs);

	/// @brief Not Equal operator overload
	/// @param rhs
	/// @return true if not equal
	bool operator!=(Hex rhs);

	/// @brief Addition operator overload
	/// @param rhs
	/// @return Singular Hex with coordiates added
	Hex operator+(Hex rhs);

	/// @brief Subtraction operator overload
	/// @param rhs
	/// @returnSingular Hex with coordiates subtracted
	Hex operator-(Hex rhs);

	/// @brief Multiplication operator overload
	/// @param rhs
	/// @return Singular Hex with coordiates scaled
	Hex operator*(int rhs);

	/// @brief Insertion operator overload
	/// @param os
	/// @param rhs
	/// @return Hex Coordinate Values
	friend std::ostream& operator<<(std::ostream& os, const Hex& rhs);  
  
};

/// @brief selects a neighboring Hex from a vector of 6 Hexes
/// @param wedge
/// @return returns a neighboring hex value
Hex hex_direction(int wedge);

/// @brief  selects a diagonal Hex from a vector of 6 Hexes
/// @param wedge
/// @return returns the diagonal hex value
Hex hex_diagonal_direction(int wedge);

/// @brief helper function for hex_distance
/// @param hex
/// @return returns the length of the line of a hex
int hex_length(Hex hex);

/// @brief Determines the distance of the origin from the target
/// @param origin
/// @param target
/// @return the length of the line between the two hexes
int hex_distance(Hex origin, Hex target);

/// @brief Determines if the distance between the origin and target is within a specified range
/// @param origin
/// @param target
/// @param range
/// @return returns if the distance is in range of the origin
bool inRange(Hex origin, Hex target, int range);

/// @brief Function determins if the target hex is on the axis path of the origin hex
/// @param origin
/// @param target
/// @return true if it's on the axis path false if it is off the axis path
bool inPath(Hex origin, Hex targer);

//ADD: a function to create default map shapes
//ADD: a pathfinding algorithm
//ADD: Field of View functions
//ADD: Obstable functions

#endif // HCS_H
