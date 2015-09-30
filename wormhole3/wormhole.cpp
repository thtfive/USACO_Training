/*
ID: thtfive
LANG: C++
TASK: wormhole
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

bool checkpair(const vector<int> &pairs, int cur, const int N, std::vector<bool> &visited, const vector<int> &next)
{
	// cout<<"[debug]cur: "<<cur<<", next[cur]: "<<next[cur]<<endl;
	// cout<<"[debug][checkpair]next: ";
	// for (int i = 0; i < N; ++i)
	// {
	// 	cout<<i<<": "<<next[i]<<";  ";
	// }
	// cout<<endl;

	// visited[cur] = true;
	if (next[cur] < 0)
	{
		return false;
	}
	if (visited[next[cur]])
	{
		return true;
	}
	visited[next[cur]] = true;
	cur = pairs[next[cur]];
	// if (visited[cur])
	// {
		// return true;
	// }
	// visited[cur] = true;
	return checkpair(pairs, cur, N, visited, next);
}

bool checkpair(const vector<int> &pairs, const vector<int> &next, const int N)
{
	std::vector<bool> visited(N, false);
	for (int i = 0; i < N; ++i)
	{
		for (int k = 0; k < N; ++k)
		{
			visited[k] = false;
		}

		if (checkpair(pairs, i, N, visited, next))
		{
			return true;
		}
	}
	return false;
}

void formpair(vector<int> &pairs, vector<bool> &paired, int cur, const vector<int> &next, const int N, int &cnt)
{
	if (cur == N)
	{
		// cout<<"[debug]pairs: ";
		// for (int i = 0; i < pairs.size(); ++i)
		// {
		// 	cout<<pairs[i]<<" ";
		// }
		// cout<<endl;

		if (checkpair(pairs, next, N))
		{
			cnt += 1;
		}
		return;
	}

	if (paired[cur])
	{
		formpair(pairs, paired, cur + 1, next, N, cnt);
	}
	else
	{
		paired[cur] = true;
		for (int i = cur + 1; i < N; ++i)
		{
			if (!paired[i])
			{
				pairs[cur] = i;
				pairs[i] = cur;
				paired[i] = true;
				formpair(pairs, paired, cur + 1, next, N, cnt);
				paired[i] = false;
			}
		}
		paired[cur] = false;
	}
}

int main()
{
	ifstream fin("wormhole.in");
	ofstream fout("wormhole.out");

	int N;
	fin>>N;
	vector<pair<int, int> > wormholes(N);
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		fin>>x>>y;
		wormholes[i] = make_pair(x, y);
	}

	vector<int> next(N, -1);
	for (int i = 0; i < N; ++i)
	{
		int n = -1;
		for (int j = 0; j < N; ++j)
		{
			if (wormholes[j].second == wormholes[i].second && wormholes[j].first > wormholes[i].first)
			{
				if (n < 0 || wormholes[j].first < wormholes[n].first)
				{
					n = j;
				}
			}
		}
		next[i] = n;
	}

	// cout<<"[debug]next: ";
	// for (int i = 0; i < N; ++i)
	// {
	// 	cout<<i<<": "<<next[i]<<";  ";
	// }
	// cout<<endl;

	vector<int> pairs(N);
	vector<bool> paired(N, false);
	int cnt = 0;
	formpair(pairs, paired, 0, next, N, cnt);
	fout<<cnt<<endl;
	fin.close();
	fout.close();
	return 0;
}
