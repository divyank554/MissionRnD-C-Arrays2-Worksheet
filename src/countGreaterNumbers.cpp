/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int stringcmp(char *d1, char *d2)
{
	int i = 0;
	int flag = 0;
	while (d1[i] != '\0')
	{
		if (d1[i] == d2[i])
			i++;
		else
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date)
{
	int i = 0;
	int result;
	int count = 0;
	int temp = len;
	while (len != 0)
	{
		len--;
		result = stringcmp(Arr[i].date, date);
		if (result == 0)
		{
			count++;
			temp = temp - 1 - i;
		}

		if (count >1)
			return 0;

		i++;
	}

	if (count == 1)
		return temp;
	else
		return 0;
}
