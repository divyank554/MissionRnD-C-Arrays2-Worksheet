/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) 
{
	if (A == NULL || B == NULL )
		return NULL;


	int number = BLen + ALen;
	struct transaction *temp = (transaction *)malloc(sizeof(struct transaction) * number);
	int i = 0, j = 0, k = 0;
	while (number != 0)
	{
		printf("number : %d\n", number);
		if (j == BLen)
		{
			temp[k] = A[i];
			k++;
			i++;
			number--;
			continue;
		}
		if (i == ALen)
		{
			temp[k] = B[j];
			k++;
			j++;
			number--;
			continue;
		}
		if (A[i].amount <= B[j].amount)
		{
			temp[k] = A[i];
			i++;
			k++;
			number--;
		}
		else
		{
			temp[k] = B[j];
			j++;
			k++;
			number--;
		}
	}

	return temp;
}