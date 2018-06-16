#include<stdio.h>

//Solution structure
struct interval
{
  int buy;
  int sell;
};

//This function helps to find buy sell schedule
void stockBuySell(int price[],int n)
{
  //If array is only length 1
  if(n == 1)
    return 0;
  //Array of interval to store prices
  interval sol[n/2 + 1];
  int i = 0;
  //traverse till last element
  while(i < n-1)
  {
    //Find local maxima
    if(i < (n-1) && (price[i] < price[i - 1]))
      sol[count].sell = i++;


    if(i < (n - 1) && (price[i] > price[i - 1]))
      sol[count].buy = i++;

    count++;
  }
  if(count == 0)
    printf("There is no buying on this day\n", );
  else
  {

  }
}
