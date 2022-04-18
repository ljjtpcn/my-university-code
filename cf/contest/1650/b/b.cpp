# include<iostream>
# include<string.h>
using namespace std;

char s[100];
char c;

void  solve()
{
	int l, r, a;
	cin >> l >> r >> a;
	int x = r % a;
	if(r - x  > l)
	{
		cout << (r - x - 1) % a + (r - x - 1) / a <<endl;
	}
	else cout << r % a + r / a << endl; 
}

int main()
{
	int t = 1;
	scanf("%d",&t);
    while(t --)
    {
    	solve();
	}
	return 0;
}
