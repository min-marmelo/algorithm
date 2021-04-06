#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m, cnt = 0;
vector<vector<int> > v(21,vector<int>(21,0));
int ch[21];	// 이거 중요. 체크 배열!! 
void DFS(int vertex) 
{
	int i;
	if(vertex == n) // 내가 원하는 지점
	{
		++cnt;
	}
	else
	{
		for(i = 1; i <= n; ++i)
		{
			if(v[vertex][i] == 1 && ch[i] == 0) // 갈수있는지, 그리고 방문을 안했는지.
			{
				ch[i] = 1; // 방문해줬다고 체크.
				DFS(i);
				ch[i] = 0;	 
			} 
		}
	}
}

int main(void)
{	
	cin >> n >> m;
	int i, a,b;
	for (i = 0; i < m; ++i)
	{
		cin >> a >> b;
		v[a][b] = 1;
	}
	ch[1] = 1;
	DFS(1);
	cout << cnt;

}
