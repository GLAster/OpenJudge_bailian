#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k,res=0;
		int m[128]={},p[128]={},dp[128]={};
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;++i){
			scanf("%d",m+i);
		}
		for(int i=1;i<=n;++i){
			scanf("%d",p+i);
		}
		for(int i=1;i<=n;++i){
			dp[i]=p[i];
			for(int j=1;j<i;++j){
				if(m[i]-m[j]>k) dp[i]=max(dp[i],dp[j]+p[i]);
			}
			res=max(res,dp[i]);
		}
		printf("%d\n",res);
	}
	return 0;
}
