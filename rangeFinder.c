#include <stdio.h>
#include "rangeFinder.h"

int startRange;
int endRange;
static int rangeCounter = 1;

void sortGivenIndexPosition(int *Range, int noOfElements, int received_position) {
	int temp;
	
	for(int index = received_position+1 ; index < noOfElements; index++) {
	if(Range[received_position] > Range[index]) {
	temp = Range[received_position];
     	Range[received_position] = Range[index];
     	Range[index] = temp;
   	}
 	}
}

void sortRange(int *getRange, int no_Of_Elements) {
  	for(int index = 0; index < no_Of_Elements; index++) {
    	sortGivenIndexPosition(getRange, no_Of_Elements, index); 
  	}
}

void getsortedRange(int *getsortRange, int no_Of_Elements)
{	
	startRange = getsortRange[0]; 
	
	for(int index = 0; index < no_Of_Elements; index++) {
	if((getsortRange[index] == getsortRange[index+1]) || (getsortRange[index]+1 == getsortRange[index+1]))
	{
		endRange = getsortRange[index+1];
		++rangeCounter;
	}
 	else
	{
		printRange();
		rangeCounter = 1;
		startRange = getsortRange[index+1];
	}
	}
}

void printRange()
{
	if(rangeCounter == 1)
	{
		printf("Range: %d  Counter: %d\n",startRange,rangeCounter);
	}
	else
	{
		printf("Range: %d - %d Counter: %d\n",startRange,endRange,rangeCounter);
	}
}

void findRange(int *receiveRange, int no_Of_Elements)
{
	sortRange(receiveRange, no_Of_Elements);
	getsortedRange(receiveRange, no_Of_Elements);
}


