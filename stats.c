#include "stats.h"
#include <math.h>

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;

void emailAlerter ()
{
	emailAlertCallCount = emailAlertCallCount + 1;
}

void ledAlerter ()
{
	ledAlertCallCount = ledAlertCallCount + 1;
}
struct Stats compute_statistics(const float* numberset, int setlength) {
    struct Stats s;
    s.average = 0.0f;
    s.min = 0.0f;
    s.max = 0.0f;
	
	int ele = 0, loop;
	
	/*Argument validation*/
	if (setlength == 0)
	{
		s.average = s.min = s.max = NAN;
	}
	else
	{
		if (numberset [ele] > numberset [ele+1])
		{
			s.max = numberset [ele];
			s.min = numberset [ele+1];
		}
		else
		{
			s.min = numberset [ele];
			s.max = numberset [ele+1];
		}
			
		/*Sorting the numbers in ascending*/
		for (loop = ele+2; loop < setlength; loop++)
		{
			if (numberset[loop] > s.max)
			{
				s.max = numberset[loop];
			}
			else if (numberset[loop] < s.min)
			{
				s.min = numberset[loop];
			}
		}
		/*calculating the total*/
		for (loop = 0; loop < setlength; loop++)
		{
			s.average += numberset[loop];
		}
		s.average = s.average/setlength;

	}
	return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
	if (computedStats.max > maxThreshold)
	{
		alerters[0]();
		alerters[1]();
	}
}