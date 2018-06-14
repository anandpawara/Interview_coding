//Maximum sum of hour glass in matrix

/*
Input : 1 1 1 0 0 
        0 1 0 0 0 
        1 1 1 0 0 
        0 0 0 0 0 
        0 0 0 0 0 
Output : 7
Below is the hour glass with
maximum sum:
1 1 1 
  1
1 1 1
                                                      
Input : 0 3 0 0 0
        0 1 0 0 0
        1 1 1 0 0
        0 0 2 4 4
        0 0 0 2 4
Output : 11
Below is the hour glass wuth
maximum sum
1 0 0
  4
0 2 4

*/
#include<stdio.h>
//Declaring global variables
int const R = 5;
int const C = 5;
int INT_MIN = -1000; //Lower limit
#define max(a,b) (((a) >= (b) ) ? (a):(b))

//Return maximun sum of hour glass in arr[][]
int findMaxSum(int mat[R][C])
{
	if(R < 3 || C < 3)
		return -1;
	//Here loop run for (R - 2)*(C - 2) times considering different top left cells of hour glasses.
	int max_sum = INT_MIN;
	for(int i = 0;i < R-2;i++)
	{
		for(int j = 0;j < C - 2;j++)
		{
			int sum = (mat[i][j] + mat[i][j+1] + mat[i][j+2] + mat[i+1][j+1] + mat[i+2][j] + mat[i][j+1] + mat[i][j+2]);
			//If previous sum is less then update current sum
			max_sum = max(max_sum,sum);
		}
	}
	return max_sum;
}




//Driver code
int main()
{
	int mat[5][5] = {{1,2,3,0,0},
			{0,0,0,0,0},
			{2,1,4,0,0},
			{0,0,0,0,0},
			{1,1,0,1,0}};
	int res = findMaxSum(mat);
	if(res == -1)
		printf("Not possible\n");
	else
		printf("Maximum sum of hour glass = %d\n",res);
	return 0;
}
