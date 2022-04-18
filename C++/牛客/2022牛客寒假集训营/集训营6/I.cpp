#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int k;
vector<int> add(vector<int> &A, vector<int> &B)
{
	vector<int> C;

	int t = 0;
	for (int i = 0; i < A.size() || i < B.size(); i++)
	{
		if (i < A.size()) t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % k);
		t /= k;
	}
	if (t)
		C.push_back(1);

	return C;
}

int main()
{
    cin >> k;
    string a, b;
	vector<int> A, B;

	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0'); // 1 4
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0'); // 7 0 4

	vector<int> C = add(A, B);
	
	for (int i = C.size() - 1; i >= 0; i--)
	{
		printf("%d", C[i]);
	}

	return 0;
}