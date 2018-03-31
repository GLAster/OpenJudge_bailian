#include <bits/stdc++.h>
using namespace std;
int cnts=0,n;
void slv(int num,int k)
{
	if(num==0) cnts++;
	for(int i=k;i>=1;--i){
		if(num-i>=0) slv(num-i,i);
	}
}
int main()
{
	while(~scanf("%d",&n)){
		cnts=0;
		slv(n,n);
		printf("%d\n",cnts);
	}
	return 0;
}
