#include "logic.h"
#include <cstdlib>
#include <iostream>

bool **create_board(const int height, const int width) 
{
  bool **board = (bool **)malloc(sizeof(bool *) * height);
  for (int i = 0; i < height; i++) 
  {
    board[i] = (bool *)malloc(sizeof(bool) * width);
  }
  return board;
}

void destroy_board(bool **board, const int height) 
{
  for (int i = 0; i < height; i++) 
  {
    free(board[i]);
  }
  free(board);
}

//Randomly places the ships on the 6 x 6 board
void place_ships(bool **board, const int shipcount, const int width, const int height) 
{
  int ships = 0;
  while(ships < shipcount)
  {
    int x = rand() % width;
    int y = rand() % height;
    if(board[x][y] != 1)
    {
      ships++;
      board[x][y] = 1;
    }
  }
}

void *find_ships(bool **board, const int width, const int height)
{
  for(int i = 0; i < height; i++)
  {
    guess(board, width, i);
  }
  return find_ships(board, width, height);
}

//Naturally this would display if the ship was either got a hit, near miss, or miss
ResponseType guess(bool **board, const int x, const int y)
{
  find_ships(board, x, y);
  if(board[x][y] == 0)
  {
    //std::cout << ResponseType::HIT << std::endl;
    return ResponseType::HIT;
  }
  else if(board[x][y] == 0)
  {
    //std::cout << ResponseType::MISS << std::endl;
    return ResponseType::MISS;
  }
  else
  {
    //std::cout << ResponseType::NEAR_MISS << std::endl;
    return ResponseType::NEAR_MISS;
  }
}