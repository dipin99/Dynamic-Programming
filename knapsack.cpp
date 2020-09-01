#include<iostream>
using namespace std;
#include<math.h>
int knapsack(int wt[],int val[],int w, int n)
{
	if(n==0 || w==0)
		return 0;
	if(wt[n-1]<=w)
		return max((val[n-1]+ knapsack(wt,val,w-wt[n-1],n-1)),knapsack(wt,val,w,n-1));
	else if(wt[n-1]>w)
		return knapsack(wt,val,w,n-1);
}
int main()
{
	int n,i;
	cout<<"Size:";
	cin>>n;
	int wt[n],val[n];
	cout<<"Enter Weight Matrix:";
	for(i=0;i<n;i++)
		cin>>wt[i];
	cout<<"Enter Value Matrix:";
	for(i=0;i<n;i++)
		cin>>val[i];
	int w;
	cout<<"Enter Capacity";
	cin>>w;
	int result=knapsack(wt,val,w,n);
	cout<<"Max Profit:"<<result;
	return 0;
	
	
    

}
