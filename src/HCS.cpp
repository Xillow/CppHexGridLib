#include <HCS.h>
#include <iostream>

/// @brief Equal operator overload
/// @param rhs
/// @return true if equal
bool Hex::operator==(Hex rhs)
{
	return (q() == rhs.q() && r() == rhs.r() && s() == rhs.s());
}

/// @brief Not Equal operator overload
/// @param rhs
/// @return true if not equal
bool Hex::operator!=(Hex rhs)
{
	return !(q() == rhs.q() && r() == rhs.r() && s() == rhs.s());
}

/// @brief Addition operator overload
/// @param rhs
/// @return Singular Hex with coordiates added
Hex Hex::operator+(Hex rhs)
{
	return Hex(q() + rhs.q(), r() + rhs.r(), s() + rhs.s());
}

/// @brief Subtraction operator overload
/// @param rhs
/// @returnSingular Hex with coordiates subtracted
Hex Hex::operator-(Hex rhs)
{
	return Hex(q() - rhs.q(), r() - rhs.r(), s() - rhs.s());
}

/// @brief Multiplication operator overload
/// @param rhs
/// @return Singular Hex with coordiates scaled
Hex Hex::operator*(int rhs)
{
	return Hex(q() * rhs, r() * rhs, s() * rhs);
}

/// @brief Insertion operator overload
/// @param os 
/// @param rhs 
/// @return Hex Coordinate Values
std::ostream &operator<<(std::ostream &os, const Hex &rhs)
{
	os << "(q:" << rhs.q() << ", r:" << rhs.r() << ", s:" << rhs.s() << ')';
	return os;
}

const std::vector<Hex> hex_directions = {Hex(1, 0, -1), Hex(1, -1, 0), Hex(0, -1, 1), Hex(-1, 0, +1), Hex(-1, +1, 0), Hex(0, 1, -1)};
/// @brief selects a neighboring Hex from a vector of 6 Hexes
/// @param wedge 
/// @return returns a neighboring hex value
Hex hex_direction(int wedge)
{
	assert(0 <= wedge && wedge < 6);
	return hex_directions[wedge];
}

const std::vector<Hex> hex_diagonal_directions = {Hex(2, -1, -1), Hex(1, -2, 1), Hex(-1, -1, 2), Hex(-2, 1, 1), Hex(-1, 2, -1), Hex(1, +1, -2)};
/// @brief  selects a diagonal Hex from a vector of 6 Hexes
/// @param wedge 
/// @return returns the diagonal hex value 
Hex hex_diagonal_direction(int wedge)
{
	assert(0 <= wedge && wedge < 6);
	return hex_diagonal_directions[wedge];
}

/// @brief helper function for hex_distance
/// @param hex 
/// @return returns the length of the line of a hex
int hex_length(Hex hex)
{
	return int((abs(hex.q()) + abs(hex.r()) + abs(hex.s())) * 0.5);
}

/// @brief Determines the distance of the origin from the target
/// @param origin 
/// @param target 
/// @return the length of the line between the two hexes
int hex_distance(Hex origin, Hex target)
{
	return hex_length(origin - target);
}


/// @brief Determines if the distance between the origin and target is within a specified range
/// @param origin 
/// @param target 
/// @param range 
/// @return returns if the distance is in range of the origin
bool inRange(Hex origin, Hex target, int range)
{
	return (hex_distance(origin, target) <= range);
}


/// @brief Function determins if the target hex is on the axis path of the origin hex
/// @param origin 
/// @param target 
/// @return true if it's on the axis path false if it is off the axis path
bool inPath(Hex origin, Hex target)
{

	int distance = hex_distance(origin, target);

	//translates the coordinate system origin from (0,0,0)->(origin.q(), origin.r(), origin.s())
	int targetQR = (target.q() - origin.q()) - (target.r() - origin.r());
	int targetSQ = (target.s() - origin.s()) - (target.q() - origin.q());
	int targetRS = (target.r() - origin.r()) - (target.s() - origin.s());

	int wedge;

	//if the distance is 1 it's neighboring the origin hex and must be on the path.
	if(distance <= 1){
		return true;
	}

	//Selects which wedge the target hex resides in
	if (abs(targetQR) > abs(targetSQ) && abs(targetQR) > abs(targetRS))
	{
			if (targetQR > 0)
			{
				wedge = 1;
			}
			else
			{
				wedge = 4;
			}
	}
	else
	{
		if (abs(targetSQ) > abs(targetRS))
		{
			if (targetSQ < 0)
			{
				wedge = 0;
			}
			else
			{
				wedge = 3;
			}
		}
		else
		{
			if (targetRS < 0)
			{
				wedge = 2;
			}
			else
			{
				wedge = 5;
			}
		}
	}
	
	//given the distance from the origin determines if the target is on a neighboring hex path from the origin
	return (target == (origin + (hex_direction(wedge) * distance)));
}
