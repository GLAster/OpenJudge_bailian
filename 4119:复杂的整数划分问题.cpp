#include <bits/stdc++.h>
using namespace std;
int slvK(int n,int k){
	auto dp=vector<vector<int>>(n+1,vector<int>(n+1,0));
	//dp[i][j]:将整数i划分为j个整数之和的划分数
	dp[0][0]=1;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			dp[i][j]=dp[i-j][j]+dp[i-1][j-1];
			//dp[i-j][j]:i的划分中不包含1
			//dp[i-1][j-1]:划分包含1
		}
	}
	return dp[n][k];
}
int slvD(int n){
	auto dp=vector<vector<int>>(n+1,vector<int>(n+1,0));
	//dp[i][j]:将整数i划分为最大数为j的划分数
	dp[0]=vector<int>(n+1,1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(j>i) dp[i][j]=dp[i][i];
			else dp[i][j]=dp[i-j][j-1]+dp[i][j-1];
			//dp[i-j][j-1]:i里包含j
			//dp[i][j-1]:不包含j
		}
	}
	return dp[n][n];
}
int slvO(int n)
{
	auto dp=vector<vector<int>>(n+1,vector<int>(n+1,0));
	//dp[i][j]:将整数i划分为最大数为j的划分数
	for(int i=1;i<=n;++i){
		dp[i][1]=dp[0][i]=1;
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(j%2){//j为奇数
				if(j>i) dp[i][j]=dp[i][i];
				else dp[i][j]=dp[i-j][j]+dp[i][j-1];
			}
			else dp[i][j]=dp[i][j-1];
		}
	}
	return dp[n][n];
}
int main()
{
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		printf("%d\n",slvK(n,k));
		printf("%d\n",slvD(n));
		printf("%d\n",slvO(n));
	}
	return 0;
}
