#include <bits/stdc++.h>
using namespace std;
int makeSet(vector<int> &v)
{
	int n,val;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&val);
		v.push_back(val);
	}
	sort(v.begin(),v.end());
	return n;
}
int main()
{
	vector<int> A,B,res;
	int n=makeSet(A),m=makeSet(B);
	int i=0,j=0;
	while(i<n&&j<m){
		if(A[i]==B[j]) ++i,++j;
		else if(A[i]<B[j]) res.push_back(A[i++]);
		else res.push_back(B[j++]);
	}
	if(i<n) res.insert(res.end(),A.begin()+i,A.end());
	else res.insert(res.end(),B.begin()+j,B.end());
	for(int &x:res) printf("%d ",x);
	return 0;
}
