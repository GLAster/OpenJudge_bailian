#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
	char val;
	TreeNode *left,*right;
	TreeNode(char v):val(v),left(NULL),right(NULL){}
};
queue<TreeNode*> q;
stack<TreeNode*> stk;
TreeNode *build()
{
	char info[4];
	scanf("%s",info);
	if(info[0]=='$') return NULL;
	TreeNode *node=new TreeNode(info[0]);
	if(info[1]=='0'){
		node->left=build();
		node->right=build();
	}
	return node;
}
void revtra(TreeNode *r)
{
	while(r){
		stk.push(r);
		r=r->right;
	}
	while(!stk.empty()){
		TreeNode *s=stk.top();
		stk.pop();
		printf("%c ",s->val);
		q.push(s);
	}
	while(!q.empty()){
		TreeNode *s=q.front();
		q.pop();
		if(s->left) revtra(s->left);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	TreeNode *r=build();
	revtra(r);
	return 0;
}
