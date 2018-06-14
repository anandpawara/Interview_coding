/*
Algorithm:
1>Scan the string from left to right and construct the count array
2>Again scan the string from left to right and check for count of character,if 1 then return that character
*/

#include<stdio.h>
#include<stdlib.h>
#define NO_OF_CHARS 256

//Structure to store count of a character and index of the first occurrence in the input string

struct countIndex
{
	int count;
	int index;
};

/* Return an array of above structure type.The size of array is NO_OF_CHARS*/

struct countIndex *getCharCountArray(char *str)
{
	struct countIndex *count = (struct countIndex *)calloc(sizeof(countIndex),NO_OF_CHARS);
	int i;
	for(
