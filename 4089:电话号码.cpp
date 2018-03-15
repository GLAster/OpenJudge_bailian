#include <bits/stdc++.h>
using namespace std;
void solve(int n)
{
	char buff[12];
	vector<string> v;
	for(int i=0;i<n;++i){
		scanf("%s",buff);
		v.push_back(buff);
	}
	sort(v.begin(),v.end());
	for(int i=0;i<n-1;++i){
		if(v[i+1].find(v[i])==0){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		solve(n);
	}
	return 0;
}
