#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<functional>
using namespace std;

#define me(x) memset(x,0,sizeof(x))
#define sy system("pause")
#define maxn 100005
using namespace std;
struct edge
{
	int to, nx;
};
edge es[maxn * 2];//边集
int st[maxn], en;//en表示边的个数，st[x]是链表的头结点
map<int, int> cs[maxn];//cs[i][j]表示结点i为根且颜色为j的儿子结点的个数
int n, q, ans;
int fa[maxn], color[maxn];//fa[i]表示结点i的父结点，color[i]表示结点i的颜色


void d__add(int x, int y)
{
	edge e;
	e.to = y;
	e.nx = st[x];
	es[++en] = e;
	st[x] = en;
}
void add(int x, int y)//加边操作
{
	d__add(x, y);
	d__add(y, x);
}

void dfs(int x)//无根树转化为以x为根的有根树
{
	int i, tot = 0;
	for (i = st[x]; i; i = es[i].nx)
	if (es[i].to != fa[x])
	{
		fa[es[i].to] = x;
		tot++;
		dfs(es[i].to);
	}
	cs[x][0] = tot;//儿子结点的个数
}
void change(int x, int y)//将结点x的颜色修改为y
{
	if (color[x] == color[fa[x]]) ans++;//假设修改后父子结点的颜色会不同，预先加1
	ans += cs[x][color[x]];//先加上所有原来颜色的儿子结点的个数
	if (fa[x])//如果x的父结点存在，更新fa[x]的子结点情况
	{
		cs[fa[x]][color[x]]--;//父结点的子结点中颜色为color[x]的减少一个
		cs[fa[x]][y]++;//颜色为y的增加一个
	}
	color[x] = y;//修改颜色
	if (color[x] == color[fa[x]]) ans--;//如果修改后的颜色和父结点的颜色一致，结果减一
	ans -= cs[x][color[x]];///减去所有目前颜色的儿子结点的个数
}
void solve(int cas)
{
	int i, a, b;
	scanf("%d", &n);
	me(st); en = 0;
	for (i = 1; i<n; i++)
	{
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	for (i = 1; i <= n; i++) cs[i].clear();
	fa[1] = 0; me(color); color[0] = -10000097;
	dfs(1); ans = 1;
	scanf("%d", &q);
	printf("Case #%d:\n", cas);
	for (i = 0; i<q; i++)
	{
		scanf("%d", &a);
		if (a == 1) printf("%d\n", ans);
		else
		{
			scanf("%d%d", &a, &b);
			change(a, b);
		}
	}
}
int main()
{
	//freopen("t.txt", "r", stdin);
	int T, i;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) solve(i);
	return 0;
}
