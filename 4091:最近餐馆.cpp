#include <bits/stdc++.h>
using namespace std;
int ss(int x){
	return x*x;
}
int cpt(vector<int> &x,vector<int> &y)
{
	int res=0,n=x.size();
	for(int i=0;i<n;++i){
		res+=ss(x[i]-y[i]);
	}
	return res;
}
int main()
{
	// freopen("3.txt","r",stdin);
	int n,k;
	while(~scanf("%d %d",&n,&k)){
		int y[8]={};
		vector<vector<int>> v;
		for(int i=0;i<n;++i){
			for(int j=0;j<k;++j){
				scanf("%d",y+j);
			}
			v.push_back(vector<int>(y,y+k));
		}
		int t,m;
		scanf("%d",&t);
		while(t--){
			vector<int> vy(k);
			for(int j=0;j<k;++j){
				scanf("%d",&vy[j]);
			}
			scanf("%d",&m);
			typedef pair<int,int> ele;
			vector<ele> A;
			for(int i=0;i<n;++i){
				A.push_back(ele(cpt(v[i],vy),i));
			}
			partial_sort(A.begin(),A.begin()+m,A.end());
			printf("the closest %d points are:\n",m);
			for(int i=0;i<m;++i){
				for(int x:v[A[i].second]){
					printf("%d ",x);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
