#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int n,m,degree[512];
bool visit[512];
vector<int> v[512];
int getzeroinDegree()
{
	for(int i=1;i<=n;++i)
		if(visit[i]==0&&degree[i]==0) return i;
	return -1;
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;++i)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].push_back(b);
		degree[b]++;
	}
	int x=getzeroinDegree();
	vector<int> result;
	while(x!=-1){
		visit[x]=1;
		result.push_back(x);
		int len=v[x].size();
		for(int i=0;i<len;++i){
			int w=v[x][i];
			if(visit[w]==0){
				degree[w]--;
			}
		}
		x=getzeroinDegree();
	}
	int len=result.size();
	for(int i=0;i<len;++i){
		printf("v%d ",result[i]);
	}
	return 0;
}
