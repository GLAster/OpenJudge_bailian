#include <bits/stdc++.h>
using namespace std;
double val[4];
bool visit[4],ans;
void dfs(int lev)
{
	if(lev==3){
		for(int i=0;i<4;++i)
			if(visit[i]==0&&abs(val[i]-24.0)<0.001) ans=1;
		return;
	}
	for(int i=0;i<4;++i){
		if(visit[i]) continue;
		for(int j=0;j<4;++j){
			if(visit[j]||i==j) continue;
			double a=val[i],b=val[j];
			visit[j]=1;
			val[i]=a+b;dfs(lev+1);
			val[i]=a-b;dfs(lev+1);
			val[i]=a*b;dfs(lev+1);
			if(b!=0.0) val[i]=a/b;dfs(lev+1);
			val[i]=a;
			visit[j]=0;
		}
	}
}
int main()
{
	while(true){
		scanf("%lf %lf %lf %lf",val,val+1,val+2,val+3);
		if(val[0]==0.0) break;
		ans=0;
		dfs(0);
		ans?printf("YES\n"):printf("NO\n");
	}
	return 0;
}
