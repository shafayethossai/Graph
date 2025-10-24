#include <bits/stdc++.h>
using namespace std;

int ar[10001],col[10010];
vector<int>v[10001];

bool dfs(int node,int cl)
{
	ar[node]=1;
	col[node]=cl;
	for(int i=0;i<v[node].size();i++)
	{
		int child=v[node][i];
		if(ar[child]==0)
		{
			if(dfs(child,cl^1)==false)
			{
				return false;
			}
		}
		if(col[child]==col[node])return false;
	}
	return true;
}

int main(){
	int t;
	cin >> t;
	int o;
	for (o =1;o<=t;o++) {
		memset(ar,0,sizeof(ar));
		memset(col,0,sizeof(col));
		int n,m,i,x,y;
		cin>>n>>m;
		for(i=1;i<=n;i++)v[i].clear();
		while(m--)
		{
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		bool ans;
		for(i=1;i<=n;i++)
		{
			if(ar[i]==0)
			{
				ans=dfs(i,1);
			}
			if(ans==false)break;
		}
		cout<<"Scenario #"<<o<<":"<<endl;
		if(ans==true)cout<<"No suspicious bugs found!"<<endl;
		else cout<<"Suspicious bugs found!"<<endl;

	}
	return 0;
}
