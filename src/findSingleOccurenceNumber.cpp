/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

int findSingleOccurenceNumber(int *A, int len) 
{
	if (A == '\0')
		return -1;
	int i, j, a;
	for (i = 0; i < len; ++i)
	{
		for (j = i + 1; j < len; ++j)
		{
			if (A[i] > A[j])
			{
				a = A[i];
				A[i] = A[j];
				A[j] = a;
			}
		}
	}

	int temp = 0;
	int res;
	while (temp != len)
	{
		if (A[temp] == A[temp + 2])
			temp = temp + 3;
		else
			return A[temp];
	}
	return -1;
}