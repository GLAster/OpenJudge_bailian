#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<pair<int,int>> v;
vector<string> mv;
int r(string str)
{
	int res=0;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			if(str[i]>str[j])
				res++;
		}
	}
	return res;
}
bool cmp(const pair<int,int> &a,const pair<int,int> &b)
{
	return a.second==b.second?a.first<b.first:a.second<b.second;
}
int main()
{
	// freopen("1.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		string str;
		cin>>str;
		mv.push_back(str);
		v.push_back(make_pair(i,r(str)));
	}
	sort(v.begin(),v.end(),cmp);
	for(auto &x:v){
		cout<<mv[x.first]<<endl;
	}
	return 0;
}
