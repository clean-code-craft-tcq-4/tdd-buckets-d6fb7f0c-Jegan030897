#include <stdio.h>
#include "rangeFinder.h"

int *startRange_a[];
int *endRange_a[];
int no_ofRanges = 0;
int *rangerCounter_a[];

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
	no_ofRanges = 0;
	startRange_a[no_ofRanges] = getsortRange[0]; 
	
	for(int index = 0; index < no_Of_Elements; index++) {
	if((getsortRange[index] == getsortRange[index+1]) || (getsortRange[index]+1 == getsortRange[index+1]))
	{
		endRange_a[no_ofRanges] = getsortRange[index+1];
		++rangerCounter_a[no_ofRanges]; 
	}
 	else
	{	
		++no_ofRanges;
		startRange_a[no_ofRanges] = getsortRange[index+1];
	}
	}
}

void findRange(int *receiveRange, int no_Of_Elements)
{
	sortRange(receiveRange, no_Of_Elements);
	getsortedRange(receiveRange, no_Of_Elements);
}


