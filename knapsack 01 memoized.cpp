#include<iostream>
#include <bits/stdc++.h> 
using namespace std;

int static t[102][1002]={-1};  //for array size ebter constraints in your question size and capacity


int knapsack(int wt[],int val[],int w, int n)
{
	//memset (t,-1,sizeof(t));
	if(n==0 || w==0)
		return 0;
	
	if(t[n][w]==-1)
		return t[n][w];
		
	if(wt[n-1]<=w)
		return t[n][w]=max((val[n-1]+ knapsack(wt,val,w-wt[n-1],n-1)),knapsack(wt,val,w,n-1));
	
	else if(wt[n-1]>w)
		return t[n][w]=knapsack(wt,val,w,n-1);
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
