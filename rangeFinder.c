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


