#include <stdio.h>
#include <assert.h>
#include "currentRangeFinder.h"

/* sorting given current Ranges */
void Test_Case0()
{
  int currentRange_1[4] = {10,1,4,6}, currentRange_2[10] = {10,1,4,6,2,5,3,8,9,6}, currentRange_3[5] = {10,10,10,10,10};
  int sorted_currentRange_1[4] = {1,4,6,10}, sorted_currentRange_2[10] = {1,2,3,4,5,6,6,8,9,10}, sorted_currentRange_3[5] = {10,10,10,10,10};
  
  int length = sizeof(currentRange_1)/sizeof(currentRange_1[0]);
  int length1 = sizeof(currentRange_2)/sizeof(currentRange_2[0]);
  int length2 = sizeof(currentRange_3)/sizeof(currentRange_3[0]);
  
  sort_currentRangeList(currentRange_1, length);
  sort_currentRangeList(currentRange_2, length1);
  sort_currentRangeList(currentRange_3, length2);
  
  for(int index = 0; index < length; index++)
  {
    assert(currentRange_1[index] == sorted_currentRange_1[index]);
    assert(currentRange_2[index] == sorted_currentRange_2[index]);
    assert(currentRange_3[index] == sorted_currentRange_3[index]);
  }
}

/* To get no of Ranges and this range used to update structure member default value */
void Test_Case_1A()
{
  int currentRange[10] = {1,2,3,4,5,6,6,8,9,10};
  
  int length = sizeof(currentRange)/sizeof(currentRange[0]);
  
  assert(get_noofRanges(currentRange, length) == 2);
}

void Test_Case_1B()
{
  int currentRange[4] = {10,1,4,6};
  
  int length = sizeof(currentRange)/sizeof(currentRange[0]);
  
  assert(get_noofRanges(currentRange, length) == 4);
}

void Test_Case_1C()
{
  int currentRange[5] = {10,10,10,10,10};
  
  int length = sizeof(currentRange)/sizeof(currentRange[0]);
  
  assert(get_noofRanges(currentRange, length) == 1);
}

/* updating structure member default value based on Ranges */
void Test_Case_2A()
{
  int currentRange[10] = {1,2,3,4,5,6,6,8,9,10}, no_of_Ranges;
  
  int length = sizeof(currentRange)/sizeof(currentRange[0]);
  
  no_of_Ranges = get_noofRanges(currentRange, length);
  update_RangefinderStruct_Defaultvalue(no_of_Ranges);
  
  for(int index = 0; index < no_of_Ranges; index++)
  {
    assert(current_rangeList[index].startRange == 0);
    assert(current_rangeList[index].endRange == 0);
    assert(current_rangeList[index].rangeCounter == 1);
  }
}

int main()
{
  Test_Case0();
  Test_Case_1A();
  Test_Case_1B();
  Test_Case_1C();
  Test_Case_2A();
  //Test_Case3();
}
