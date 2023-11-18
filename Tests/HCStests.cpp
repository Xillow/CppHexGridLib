#include <HCS.h>
#include <iostream>
//Tests needs to check the following
//Functions are opperating as they should be
//Objects are being made and stored in an array
//Access of Objects in the array are being handled correctly
//objects data is being properly changed when accessed

// Test Functions
void equTest(Hex a, Hex b) { std::cout << ((a == b) ? "equTest:Valid" : "equTest:Invalid") << std::endl; }

void inEquTest(Hex a, Hex b) { std::cout << ((a != b) ? "inEquTest:Valid" : "inEquTest:Invalid") << std::endl; }

void addTest(Hex a, Hex b, Hex c) { std::cout << (((a + b) == c) ? "addTest:Valid" : "addTest:Invalid") << std::endl; }

void subTest(Hex a, Hex b, Hex c) { std::cout << (((c - b) == a) ? "subTest:Valid" : "subTest:Invalid") << std::endl; }

void scaleTest(Hex a, int k, Hex b) { std::cout << (((a * k) == b) ? "subTest:Valid" : "subTest:Invalid") << std::endl; }

void dirTest(Hex a, int k) { std::cout << "DirTest: " << k << ": " << hex_direction(k) << std::endl; }

void diaDirTest(Hex a, int k) { std::cout << "diaDirTest: " << k << ": " <<hex_diagonal_direction(k) << std::endl; }

void lenTest(Hex a, Hex b, Hex c) { std::cout << "lenTest: A:" << hex_length(a) << " B:" << hex_length(b) << " C:" << hex_length(c) << std::endl; }

void distanceTest(Hex a, Hex b) { std::cout << "distanceTest:" << hex_distance(a, b) << std::endl; }

void rangeTest(Hex a, Hex b, int range) { std::cout << (inRange(a, b, range) ? "rangeTest:Valid" : "rangeTest:Invalid") << std::endl; }

void pathTest(Hex a, Hex b) { std::cout << (inPath(a, b) ? "pathTest:Valid" : "pathTest:Invalid") << std::endl; }

int main(int argc, char *argv[])
{
	std::cout << "start" << std::endl;

	Hex origin(0, 0, 0);

	Hex pointA(0, 1, -1);

	Hex pointB(0, 2, -2);

	Hex pointC(1, -3, 2);

	Hex pointD(-1, -1, 2);

	equTest(pointA, pointA);

	inEquTest(pointA, pointB);
	
	addTest(pointA, pointB, pointC);

	subTest(pointA, pointB, pointC);

	scaleTest(pointA, 2, pointB);

	for (size_t i = 0; i < 6; i++){	dirTest(origin, i);}

	for (size_t  i =0; i < 6; i++){ diaDirTest(origin,i);}
	
	lenTest(pointA, pointB, pointC);

	distanceTest(pointA, pointB);

	rangeTest(origin, pointB, 2);

	pathTest(pointA, pointD);
	/*

	//Create 3 Hexes

	//check every operator

	//create a vector or an array

	//loop filling vector or array

	//Run through checks again

*/

	return 0;
}



