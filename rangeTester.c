#include <stdio.h>
#include <assert.h>

Test_Case0()
{
  int currentRange[4] = {10,1,4,6};
  int sortedRange[4] = {1,10,4,6};
  int length = sizeof(currentRange)/sizeof(currentRange[0]);
  sortRange(currentRange, length, 0);
  
  for(int index = 0; index < length; index++)
  {
    assert(currentRange[index] == sortedRange[0]);
  }
}

int main()
{
  Test_Case0();
}
