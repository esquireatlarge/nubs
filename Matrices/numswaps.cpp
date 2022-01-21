//Matrix is 2x3
//Numbers are positive
//-1 implies no possible swaps
//swaps are possible up, down, left, right
//multiple swaps allowed to achieve result

//Input:
//1 2 3
//4 5 6 

//Output:
//1 2 6
//4 5 3

//One swap

#include <iostream>
#include <cmath>

struct Position
{
	int row;
	int column;
	int value;
	bool isSwappable;

	Position(int r, int c, int v)
	{
		row = r;
		column = c;
		value = v;
		isSwappable = true;
	}

	Position()
	{
	}
};

Position nullPosition(-1, -1, -1);

//A matrix is defined as a series of six positions
//00 01 02
//10 11 12

class Matrix
{
public:
	Matrix(int* values)
	{
		//Assume size of array
		mat[0][0] = Position(0, 0, values[0]);
		mat[0][1] = Position(0, 1, values[1]);
		mat[0][2] = Position(0, 2, values[2]);
		mat[1][0] = Position(1, 0, values[3]);
		mat[1][1] = Position(1, 1, values[4]);
		mat[1][2] = Position(1, 2, values[5]);
	}

	//Calculate swaps
	int NumSwaps(const Matrix& target)
	{
		int totalSwaps = 0;

		//The target value exists at the same position

		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 3; j++)
				totalSwaps += Process(mat[i][j], target);

		return totalSwaps;
	}

	int Process(Position& home, const Matrix& target)
	{
		Position p1 = FindInMatrix(target, home.value);

		//if p1 == nullPosition
		//return -1
		//add equality operator to Position class

		int mag = GetMagnitude(home, p1);
		if (mag != 0)
			DoSwap(home, *GetAtPosition(p1.row, p1.column));
		home.isSwappable = false;

		return mag;
	}

	Position FindInMatrix(const Matrix& m, int value)
	{
		//Iterate through each element in array
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (m.mat[i][j].value == value)
					return m.mat[i][j];
			}
		}

		return nullPosition;
	}

	int GetMagnitude(const Position& start, const Position& end)
	{
		int rowDist = abs(end.row - start.row);
		int colDist = abs(end.column - start.column);

		std::cout << "distance found of " << rowDist + colDist << std::endl;

		return rowDist + colDist;
	}

	Position* GetAtPosition(int row, int column)
	{
		//Assume values fit within 2 and 3
		return &mat[row][column];
	}

	void DoSwap(Position& p1, Position& p2)
	{
		//null check
		//null check
		int temp = p1.value;
		p1.value = p2.value;
		p2.value = temp;
	}

private:
	Position mat[2][3];
};

int main()
{
	int v1[] = { 1, 2, 3, 4, 5, 6 };
	int v2[] = { 3, 2, 1, 6, 5, 4 };


	//1 2 3  to   1 2 6
	//4 5 6       4 5 3

	//1 2 3  to   3 2 1  
	//4 5 6       6 5 4

	//Input 1 2 3 4 5 6
	Matrix start(v1);
	Matrix end(v2);

	//How many swaps
	std::cout << start.NumSwaps(end) << std::endl;
	std::cin;

	return 0;
}

/*
1 2 3    1 3 5
4 5 6    4 6 2

1 5 3
4 2 6

1 5 3   1 6 3
4 6 2   4 5 2
*/