#include "stats.h"

struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0.0f;
    s.min = 0.0f;
    s.max = 0.0f;
	
	float temp;
	int outer_loop, inner_loop;
	
	/*Argment validation*/
	if (setlength == 0)
	{
		s.average = s.min = s.max = INFINITY;
	}
	else
	{
		/*Sorting the numbers in ascending*/
		for (outer_loop = 0; outer_loop < setlength-1; outer_loop++)
		{
			for (inner_loop = outer_loop+1; inner_loop < setlength; inner_loop++)
			{
				if (numberset[outer_loop] > numberset[inner_loop])
				{
					temp = numberset[outer_loop];
					numberset[outer_loop] = numberset[inner_loop];
					numberset[inner_loop] = temp;
				}
			}
		}
		/*calculating the total*/
		for (outer_loop = 0; outer_loop < setlength; outer_loop++)
		{
			s.average += numberset[outer_loop];
		}
		s.average = s.average/setlength;
		s.min = numberset[0];
		s.max = numberset[setlength-1];
	}
	return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
