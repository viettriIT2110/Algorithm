#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{   // chặt nhị phân tìm kiếm vị trí số bé hơn gần nhất có cần tìm :
	cin>>n;
	int a[n];
	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
    int val;
    cin>>val;
    int l = 0, r = n;
    while(l < r){
        int mid = (l + r) / 2;
        if(a[mid] <=val) l = mid + 1;
        else r = mid;
    }
		cout<<l<<" ";
}
