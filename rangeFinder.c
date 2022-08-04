#include <stdio.h>

void sortRange(int *Range, int noOfElements)
{
	int temp;
	for(int i = 0; i < noOfElements; i++)
	{
	    for(int j = i+1; j < noOfElements; j++)
	    {
		  if(Range[i] > Range[j])
		  {
			temp = Range[i];
			Range[i] = Range[j];
			Range[j] = temp;
		  }
	    }
	}
}
