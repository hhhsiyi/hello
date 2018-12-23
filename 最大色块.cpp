#include<iostream>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define PI acos(-1)
#define eps 1e-8
#define inf 0x3f3f3f
#define debug(x) cout<<"-----"<<x<<"_____"<<endl
typedef long long ll;
char str[55][55];
bool vis[55][55];
int dix[4]= {1,-1,0,0};
int diy[4]= {0,0,1,-1};
int m,n;
struct node
{
	int x,y;
};
int cango(int x,int y)
{
	return x>=0&&x<m&&y>=0&&y<n&&vis[x][y]==false;
}
int bfs(int x,int y)
{
	if (vis[x][y]==true)
		return 0;
	queue<node>qu;
	node gg;
	gg.x = x;
	gg.y = y;
	qu.push(gg);
	vis[x][y] = true;
	int sum = 0;
	while (!qu.empty())
	{
		gg = qu.front();
		qu.pop();
		sum++;
		for(int i = 0; i<4; i++)
		{
			int _x = gg.x+dix[i];
			int _y = gg.y+diy[i];
			if(cango(_x,_y)&&str[_x][_y]==str[x][y])
			{
				node hh;
				hh.x = _x;
				hh.y = _y;
				qu.push(hh);
				vis[_x][_y] = true;
			}
		}
	}
	return sum;
}
int main()
{
	while(cin>>m>>n)
	{
		memset(vis,false,sizeof(vis));
		for(int i = 0; i<m; i++)
			cin>>str[i];
		int ans = 0;
		for(int i = 0; i<m; i++)
			for(int j = 0; j<n; j++)
				ans = max(ans,bfs(i,j));
		cout<<ans<<endl;
	}
	return 0;
}
//使用git提交 
//20181223
