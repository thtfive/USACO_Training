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
edge es[maxn * 2];//�߼�
int st[maxn], en;//en��ʾ�ߵĸ�����st[x]�������ͷ���
map<int, int> cs[maxn];//cs[i][j]��ʾ���iΪ������ɫΪj�Ķ��ӽ��ĸ���
int n, q, ans;
int fa[maxn], color[maxn];//fa[i]��ʾ���i�ĸ���㣬color[i]��ʾ���i����ɫ


void d__add(int x, int y)
{
	edge e;
	e.to = y;
	e.nx = st[x];
	es[++en] = e;
	st[x] = en;
}
void add(int x, int y)//�ӱ߲���
{
	d__add(x, y);
	d__add(y, x);
}

void dfs(int x)//�޸���ת��Ϊ��xΪ�����и���
{
	int i, tot = 0;
	for (i = st[x]; i; i = es[i].nx)
	if (es[i].to != fa[x])
	{
		fa[es[i].to] = x;
		tot++;
		dfs(es[i].to);
	}
	cs[x][0] = tot;//���ӽ��ĸ���
}
void change(int x, int y)//�����x����ɫ�޸�Ϊy
{
	if (color[x] == color[fa[x]]) ans++;//�����޸ĺ��ӽ�����ɫ�᲻ͬ��Ԥ�ȼ�1
	ans += cs[x][color[x]];//�ȼ�������ԭ����ɫ�Ķ��ӽ��ĸ���
	if (fa[x])//���x�ĸ������ڣ�����fa[x]���ӽ�����
	{
		cs[fa[x]][color[x]]--;//�������ӽ������ɫΪcolor[x]�ļ���һ��
		cs[fa[x]][y]++;//��ɫΪy������һ��
	}
	color[x] = y;//�޸���ɫ
	if (color[x] == color[fa[x]]) ans--;//����޸ĺ����ɫ�͸�������ɫһ�£������һ
	ans -= cs[x][color[x]];///��ȥ����Ŀǰ��ɫ�Ķ��ӽ��ĸ���
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
