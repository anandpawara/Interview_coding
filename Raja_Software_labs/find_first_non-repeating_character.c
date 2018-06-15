/*
Algorithm:
1>Scan the string from left to right and construct the count array
2>Again scan the string from left to right and check for count of character,if 1 then return that character
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define NO_OF_CHARS 256

//Structure to store count of a character and index of the first occurrence in the input string

struct countIndex
{
	int count;
	int index;
};

//Returns an array of above structurs and its size is NO_OF_CHARS
struct countIndex *getCountCharArray(char *str)
{
	struct countIndex *countArray = (struct countIndex *)calloc(sizeof(struct countIndex) ,NO_OF_CHARS);
	int i;
	for(i = 0; *(str + i); i++)
	{
		countArray[*(str + i)].count++;
		if(countArray[*(str + i)].count == 1)
			countArray[*(str + i)].index = i;
	}
	return countArray;
}

/*The function the index of the first non repeating character in the string and if there is no non repeating character then it returns INT_MAX*/

int firstNonRepeating(char *str)
{
	struct countIndex *count = getCountCharArray(str);
	int result = INT_MAX,i;

	for(i = 0; i < NO_OF_CHARS; i++)
	{
		if(count[i].count == 1 && result > count[i].index)
			result = count[i].index;
	}
	free(count);
	return result;
}

int main()
{
	char str[] = {"abraKaDabra"};
	int index = firstNonRepeating(str);
	if(index == INT_MAX)
		printf("Either there are no non repeating characters or string is empty\n");
	printf("First non repeating character is %c\n",str[index]);
	return 0;
}
