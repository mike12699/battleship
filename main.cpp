#include "logic.h"
#include <cstdlib>
#include <iostream>
int main() 
{
  int ships = 3;
  bool **board = create_board(6, 6);
  destroy_board(board, 6);
  place_ships(board, ships, 6, 6);
  guess(board, 6, 6);
}
