/**
 *  A simple class that implements an 8x8 game checker board with three possible values
 *  for each cell:  0, 1 or 2.
 *
 **/
  /**
	Briefly explain the function of this class.

	@author 			shau shiun chu
	@ID 				B06501018
	@Department 		Engineering Science and Ocean Engineering
	@Affiliation 	National Taiwan University

	version 1.0
  */
#include "CheckerBoard.h"
#include <typeinfo>

  /**
   *  Construct a new board in which all cells are zero.
   */
CheckerBoard::CheckerBoard() {
	for (int i = 0; i < DIMENSION; i++)
		for (int j = 0; j < DIMENSION; j++)
			grid[i][j] = 0;
}

/**
 *  Construct a new board with the given variable.
 *  @param is CheckerBoard.
 */
CheckerBoard::CheckerBoard(const CheckerBoard &board) {
	CheckerBoard copy_b = board;
	for (int i = 0; i < DIMENSION; i++)
		for (int j = 0; j < DIMENSION; j++)
			grid[i][j] = copy_b.elementAt(i, j);
}

/**
 *  Set the cell (x, y) in the board to the given value mod 3.
 *  @param value to which the element should be set (normally 0, 1, or 2).
 *  @param x is the x-index.
 *  @param y is the y-index.
 *  @exception ArrayIndexOutOfBoundsException is thrown if an invalid index
 *  is given.
 **/
void CheckerBoard::setElementAt(int x, int y, int value) {
	grid[x][y] = value % 3;
	if (grid[x][y] < 0) {
		grid[x][y] += 3;
	}
}

/**
 *  Get the valued stored in cell (x, y).
 *  @param x is the x-index.
 *  @param y is the y-index.
 *  @return the stored value (between 0 and 2).
 *  @exception ArrayIndexOutOfBoundsException is thrown if an invalid index
 *  is given.
 */
int CheckerBoard::elementAt(int x, int y) {
	return grid[x][y];
}

/**
 *  Returns true if "this" CheckerBoard and "board" have identical values in
 *    every cell.
 *  @param board is the second CheckerBoard.
 *  @return true if the boards are equal, false otherwise.
 */
bool CheckerBoard::equals(const CheckerBoard& board) {
	// Replace the following line with your solution.  Be sure to return false
	//   (rather than throwing a ClassCastException) if "board" is not
	//   a CheckerBoard.
	if (typeid(board) != typeid(CheckerBoard)) {
		return false;
	}

	CheckerBoard checkEqual_b = board;
	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			if (grid[i][j] != checkEqual_b.elementAt(i, j))
				return false;
		}
	}
	return true;
}

/**
 *  Returns a hash code for this CheckerBoard.
 *  @return a number between Integer.MIN_VALUE and Integer.MAX_VALUE.
 */
int CheckerBoard::hashCode() {
	// Replace the following line with your solution.
	int hashVal = 0;
	for (int i = 0; i < DIMENSION; i++)
	{
		for (int j = 0; j < DIMENSION; j++)
		{
			hashVal = ((7*i+1)*this->elementAt(i, j) + 37 * (j+1)*hashVal) % 1690877;
		}
	}
	return hashVal;
}
