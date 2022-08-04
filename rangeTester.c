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
  int length;
  
  int currentRange1[4] = {10,1,4,6};
  length = sizeof(currentRange1)/sizeof(currentRange1[0]);
  
  assert(get_noofRanges(currentRange1, length) == 4);
  
  int currentRange2[10] = {10,1,4,6,2,5,3,8,9,11};
  length = sizeof(currentRange2)/sizeof(currentRange2[0]);
  
  assert(get_noofRanges(currentRange2, length) == 2);
  
  int currentRange3[5] = {10,10,10,10,10};
  length = sizeof(currentRange3)/sizeof(currentRange3[0]);
  
  assert(get_noofRanges(currentRange3, length) == 1);
}

int main()
{
  Test_Case0();
  Test_Case1();
  Test_Case2();
}
