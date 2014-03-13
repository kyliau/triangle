#include <iostream>
#include <fstream>
using namespace std;

const unsigned int NUM_ROWS = 100;
const unsigned int TOTAL_ELEM = (1 + NUM_ROWS) * NUM_ROWS * 0.5;

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
  unsigned int in[TOTAL_ELEM];
  for (int i = 0; i < TOTAL_ELEM; i++)
  {
    in[i] = tri[i];
  }
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
  unsigned int sum = tri[0];
  unsigned int sol[NUM_ROWS];
  int index = 0;
  for (int i = 0; i < TOTAL_ELEM; i++)
  {
    if (tri[i] == sum)
    {
      sol[index++] = in[i];
      cout << in[i] << '\n';
      sum -= in[i];
    }
  }
  unsigned int cumSum = 0;
  for (int i = 0; i < NUM_ROWS; i++)
  {
    cumSum += sol[i];
  }
  cout << "Double check: " << cumSum << '\n';
  return 0;
}
