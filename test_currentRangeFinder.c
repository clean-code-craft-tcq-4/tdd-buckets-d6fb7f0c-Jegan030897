#include <stdio.h>
#include <assert.h>
#include "currentRangeFinder.h"

/* sorting given current Ranges */
void Test_Case0()
{
  int currentRange[4] = {10,1,4,6};
  int sorted_currentRange[4] = {1,4,6,10};
  int length = sizeof(currentRange)/sizeof(currentRange[0]);
  sort_currentRangeList(currentRange, length);
  
  for(int index = 0; index < length; index++)
  {
    assert(currentRange[index] == sorted_currentRange[index]);
  }
}
#if 0
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
  int length, range;
  
  int currentRange1[4] = {10,1,4,6};
  length = sizeof(currentRange1)/sizeof(currentRange1[0]);
  
  range = get_noofRanges(currentRange1, length);
  assert(range == 4);
  
  int currentRange2[10] = {10,1,4,6,2,5,3,8,9,11};
  length = sizeof(currentRange2)/sizeof(currentRange2[0]);
  
  assert(get_noofRanges(currentRange2, length) == 9);
  
  int currentRange3[5] = {10,10,10,10,10};
  length = sizeof(currentRange3)/sizeof(currentRange3[0]);
  
  assert(get_noofRanges(currentRange3, length) == 1);
}

void Test_Case3()
{
  int length;
  
  int Range1[4] = {10,1,4,6};
  length = sizeof(Range1)/sizeof(Range1[0]);
  
  assert(find_currentRangeList(Range1, length) == 4);
  
  int Range2[10] = {10,1,4,6,2,5,3,8,9,11};
  length = sizeof(Range2)/sizeof(Range2[0]);
  
  assert(find_currentRangeList(Range2, length) == 2);
  
  int Range3[5] = {10,10,10,10,10};
  length = sizeof(Range3)/sizeof(Range3[0]);
  
  assert(find_currentRangeList(Range3, length) == 1);
}
#endif
int main()
{
  Test_Case0();
  //Test_Case1();
  //Test_Case2();
  //Test_Case3();
}
