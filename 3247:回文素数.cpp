#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n;
void number(string &rp,bool isodd)
{
	if(isodd){
		if((int)rp.size()==n/2+1){
			int fn=rp[0]-'0';
			if(fn&&fn%2&&fn%5){
				string re=rp;
				reverse(re.begin(),re.end());
				int num=stoi(rp+re.substr(1,re.size()-1));
				v.push_back(num);
			}
			return;
		}
	}else{
		if((int)rp.size()==n/2){
			int fn=rp[0]-'0';
			if(fn&&fn%2&&fn%5){
				string re=rp;
				reverse(re.begin(),re.end());
				int num=stoi(rp+re);
				v.push_back(num);
			}
			return;
		}
	}
	for(int k=0;k<10;++k){
		rp+='0'+k;
		number(rp,isodd);
		rp.pop_back();
	}
}
bool isprime(int x){
	if(x<=1) return 0;
	for(int i=2;i*i<=x;++i){
		if(x%i==0) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&n);
	if(n==1){
		printf("4\n2 3 5 7");
		return 0;
	}
	string rp;
	number(rp,n%2);
	vector<int> ans;
	for(int x:v){
		if(isprime(x))
			ans.push_back(x);
	}
	printf("%lld\n",ans.size());
	for(int x:ans){
		printf("%d ",x);
	}
	return 0;
}
