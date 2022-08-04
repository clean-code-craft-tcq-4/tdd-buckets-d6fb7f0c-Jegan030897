#include <stdio.h>
#include <assert.h>
#include "rangeFinder.h"

void Test_Case0()
{
  int currentRange[4] = {10,1,4,6};
  int sortedRange[4] = {1,10,4,6};
  int length = sizeof(currentRange)/sizeof(currentRange[0]);
  sortGivenIndexPosition(currentRange, length, 0);
  
  for(int index = 0; index < length; index++)
  {
    assert(currentRange[index] == sortedRange[index]);
  }
}

void Test_Case1()
{
  int currentRange[4] = {10,1,4,6};
  int sortedRange[4] = {10,1,4,6};
  int length = sizeof(currentRange)/sizeof(currentRange[0]);
  sortGivenIndexPosition(currentRange, length, 1);
  
  for(int index = 0; index < length; index++)
  {
    assert(currentRange[index] == sortedRange[index]);
  }
}

void Test_Case2()
{
  int Range[4] = {10,1,4,6};
  int length = sizeof(currentRange)/sizeof(currentRange[0]);
  
  assert(get_noofRanges(Range, length) == 4);
}

int main()
{
  Test_Case0();
  Test_Case1();
  Test_Case2();
}
