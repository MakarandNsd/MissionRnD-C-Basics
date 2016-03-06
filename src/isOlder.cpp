/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int Valid(int, int, int);
int isOlder(char *dob1, char *dob2)
{
	int day1 = 0, day2 = 0, mnth1 = 0, mnth2 = 0, yr1 = 0, yr2 = 0;
	int i;
	for (i = 0; i < 2; i++)
	{
		if (dob1[i]<48 || dob1[i]>57 || dob2[i]<48 || dob2[i]>57)
			return -1;
		day1 = (day1 * 10) + (dob1[i] - '0');
		day2 = (day2 * 10) + (dob2[i] - '0');
	}
	for (i = 3; i < 5; i++)
	{
		if (dob1[i]<48 || dob1[i]>57 || dob2[i]<48 || dob2[i]>57)
			return -1;
		mnth1 = (mnth1 * 10) + (dob1[i] - '0');
		mnth2 = (mnth2 * 10) + (dob2[i] - '0');
	}
	for (i = 6; i < 10; i++)
	{
		if (dob1[i]<48 || dob1[i]>57 || dob2[i]<48 || dob2[i]>57)
			return -1;
		yr1 = (yr1 * 10) + (dob1[i] - '0');
		yr2 = (yr2 * 10) + (dob2[i] - '0');
	}
	if (Valid(day1, mnth1, yr1) && Valid(day2, mnth2, yr2))
	{
		if (yr1 < yr2)
			return 1;
		else if (yr2 < yr1)
			return 2;
		else
		{
			if (mnth1 < mnth2)
				return 1;
			else if (mnth2 < mnth1)
				return 2;
			else
			{
				if (day1 < day2)
					return 1;
				else if (day2 < day1)
					return 2;
				else
					return 0;
			}
		}
	}
	else
		return -1;


}
int Valid(int day, int mnth, int yr)
{
	if (yr % 4 == 0 && mnth == 02 && day < 30)
		return 1;
	else if ((mnth == 1 || mnth == 3 || mnth == 5 || mnth == 7 || mnth == 8 || mnth == 10 || mnth == 12) && day < 32)
		return 1;
	else if ((mnth == 4 || mnth == 6 || mnth == 9 || mnth == 11) && day < 31)
		return 1;
	else if (mnth == 02 && day > 28)
		return 0;
	else
		return 0;

}
