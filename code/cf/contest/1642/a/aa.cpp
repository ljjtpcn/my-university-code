#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct node
{
	double x,y;
}arr[10]; 

void solve()
{
	double fy = -1;
	for(int i = 0;i < 3;i ++)
	{
		cin >> arr[i].x >> arr[i].y;
		fy = max(fy, arr[i].y);
	}
	    
	
	       
	if(arr[0].y == arr[1].y && fy == arr[0].y)
	{
		double p =  arr[0].x - arr[1].x;
		cout << abs(p) <<endl;
	}
	else if(arr[1].y == arr[2].y && fy == arr[1].y)
	{
		double p =  arr[1].x - arr[2].x;
		cout << abs(p) <<endl;
	}
	else if(arr[0].y == arr[2].y && fy == arr[0].y)
	{
		double p =  arr[0].x - arr[2].x;
		cout << abs(p) <<endl;
	}
	else cout << "0" << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin >> t;
	while(t --)
	{
		solve();
	} 
	return 0;
} 
/*
5
8.11111 4 
10 4
6 2
*/
