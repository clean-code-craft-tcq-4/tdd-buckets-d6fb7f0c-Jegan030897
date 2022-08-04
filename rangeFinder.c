#include <stdio.h>
#include "rangeFinder.h"

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

int get_noofRanges(int *getsortRange, int no_Of_Elements)
{
	no_ofRanges = 0;
	
	for(int index = 0; index < no_Of_Elements; index++)
	{
		if((getsortRange[index] != getsortRange[index+1]) || (getsortRange[index]+1 != getsortRange[index+1]))
		{
			++no_ofRanges;	
		}
	}
	return no_ofRanges;
}

void getsortedRange(int *getsortRange, int no_Of_Elements)
{
	int range;
	int no_of_Ranges = 0;

	range = get_noofRanges(getsortRange, no_Of_Elements);
	
	rangeFinder_s rangeList[range]; 
	
	rangeList[no_of_Ranges].startRange = getsortRange[0]; 
	
	for(int index = 0; index < no_Of_Elements; index++) {
		if((getsortRange[index] == getsortRange[index+1]) || (getsortRange[index]+1 == getsortRange[index+1]))
		{
			rangeList[no_of_Ranges].endRange = getsortRange[index+1];
			++rangeList[no_of_Ranges].rangeCounter; 
		}
		else
		{	
			++no_of_Ranges;
			rangeList[no_of_Ranges].startRange = getsortRange[index+1];
		}
	}
}

void findRange(int *receiveRange, int no_Of_Elements)
{
	sortRange(receiveRange, no_Of_Elements);
	getsortedRange(receiveRange, no_Of_Elements);
}


