#include <iostream>
#include <fstream>
using namespace std;

const int NUM_ROWS = 100;
const int TOTAL_ELEM = (1 + NUM_ROWS) * NUM_ROWS * 0.5;

void readFile(unsigned int tri[])
{
  ifstream inFile;
  inFile.open("triangle.txt");
  for (int i = 0; i < TOTAL_ELEM; ++i)
  {
    inFile >> tri[i];
  }
  inFile.close();
}

int main()
{
  unsigned int tri[TOTAL_ELEM];
  readFile(tri);
  // "base case" for the DP problem is row 100
  // starting filling out the solution "bottom up" starting from last
  // element on row 99
  int row = NUM_ROWS - 1;
  int count = 0;
  for (int i = TOTAL_ELEM - NUM_ROWS - 1; i >= 0; i--)
  {
    tri[i] += ((tri[i+row] > tri[i+row+1]) ? tri[i+row] : tri[i+row+1]);
    count++;
    if (count == row)
    {
      count = 0;
      row--;
    }
  }
  cout << "The largest sum is: " << tri[0] << '\n';
  return 0;
}
