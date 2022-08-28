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

/* Getting range counter, start and end range based on sorted input */
void Test_Case_3()
{
  int currentRange[10] = {1,2,3,4,5,6,6,8,9,10};
  int start_Range[2] = {1,8}, end_Range[2] = {6,10}, range_Counter[2] = {7, 3};
  
  int length = sizeof(currentRange)/sizeof(currentRange[0]);
  
  get_currentRangesandCounter(currentRange, length);
  
  assert(current_rangeList[0].startRange == start_Range[0]);
  assert(current_rangeList[0].endRange == end_Range[0]);
  assert(current_rangeList[0].rangeCounter == range_Counter[0]);
  assert(current_rangeList[1].startRange == start_Range[1]);
  assert(current_rangeList[1].endRange == end_Range[1]);
  assert(current_rangeList[1].rangeCounter == range_Counter[1]);
}

void Test_Case_4A()
{
  int currentRange_1[10] = {10,1,4,6,2,5,3,8,9,6}, no_of_Ranges;
  int start_Range_1[2] = {1,8}, end_Range_1[2] = {6,10}, range_Counter_1[2] = {7, 3};
  
  int length = sizeof(currentRange_1)/sizeof(currentRange_1[0]);
  
  no_of_Ranges = find_currentRangeList(currentRange_1, length);
  
  for(int index = 0; index < no_of_Ranges; index++)
  {
    assert(current_rangeList[index].startRange == start_Range_1[index]);
    assert(current_rangeList[index].endRange == end_Range_1[index]);
    assert(current_rangeList[index].rangeCounter == range_Counter_1[index]);
  }
}

void Test_Case_4B()
{
  int currentRange_2[5] = {10,10,10,10,10}, no_of_Ranges;
  int start_Range_2[1] = {10}, end_Range_2[1] = {0}, range_Counter_2[1] = {5};
  
  int length = sizeof(currentRange_2)/sizeof(currentRange_2[0]);
  
  no_of_Ranges = find_currentRangeList(currentRange_2, length);
  
  for(int index = 0; index < no_of_Ranges; index++)
  {
    assert(current_rangeList[index].startRange == start_Range_2[index]);
    assert(current_rangeList[index].endRange == end_Range_2[index]);
    assert(current_rangeList[index].rangeCounter == range_Counter_2[index]);
  }
}

void Test_Case_4C()
{
  int currentRange_3[4] = {10,1,4,6}, no_of_Ranges;
  int start_Range_3[4] = {1,4,6,10}, end_Range_3[4] = {0,0,0,0}, range_Counter_3[4] = {1,1,1,1};
  
  int length = sizeof(currentRange_3)/sizeof(currentRange_3[0]);
  
  no_of_Ranges = find_currentRangeList(currentRange_3, length);
  
  for(int index = 0; index < no_of_Ranges; index++)
  {
    assert(current_rangeList[index].startRange == start_Range_3[index]);
    assert(current_rangeList[index].endRange == end_Range_3[index]);
    assert(current_rangeList[index].rangeCounter == range_Counter_3[index]);
  }
}

int main()
{
  Test_Case0();
  Test_Case_1A();
  Test_Case_1B();
  Test_Case_1C();
  Test_Case_2A();
  Test_Case_3();
  Test_Case_4A();
  Test_Case_4B();
  Test_Case_4C();
}
