#include <stdio.h>
  
typedef struct 
{
	int startRange;
	int endRange;
	int rangeCounter;
} rangeFinder_s;

extern rangeFinder_s rangeList[];

void sortGivenIndexPosition(int *Range, int noOfElements, int received_position);
void sortRange(int *getRange, int no_Of_Elements);
int get_noofRanges(int *getsortRange, int no_Of_Elements);
void getsortedRange(int *getsortRange, int no_Of_Elements);
void findRange(int *receiveRange, int no_Of_Elements);
void printRange();
