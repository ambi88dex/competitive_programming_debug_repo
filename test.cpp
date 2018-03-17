#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int si,sj;
int n,m;
vector<ll>dist;
vector<int>visited;
int getId(int i, int j)
{
    return m*i+j;
}


int main()
{
    int Q;
    cin >> n >> m >> Q;
    vector<string>grid(n);
    for(int i=0;i<n;i++)
    {
        cin >> grid[i];
    }
    dist.clear();
    dist.resize(n*m,-1);
    visited.resize(n*m);
    cin >> si >> sj;
    si--;sj--;
    queue<pair<int,int> >q;
    q.push(make_pair(m*si+sj,0));
    visited[q.front().first]=1;
    dist[q.front().first]=0;
    while(!q.empty())
    {
        int x=q.front().first/m;
        int y=q.front().first%m;
        if(x>0)
        {
            if(visited[m*(x-1)+y]==0)
            {
                if(!(grid[x][y]=='O' && grid[x-1][y]=='O'))
                {
                    visited[m*(x-1)+y]=1;
                    dist[m*(x-1)+y]=q.front().second+1;
                    if(grid[x-1][y]!='O')
                    {
                        q.push(make_pair(m*(x-1)+y,q.front().second+1));
                    }
                }
            }
        }
        if(x<m-1)
        {
            if(visited[m*(x+1)+y]==0)
            {
                if(!(grid[x][y]=='O' && grid[x+1][y]=='O'))
                {
                    visited[m*(x+1)+y]=1;
                    dist[m*(x+1)+y]=q.front().second+1;
                    if(grid[x+1][y]!='O')
                    {
                        q.push(make_pair(m*(x+1)+y,q.front().second+1));
                    }
                }
                
            }
        }
        if(y>0)
        {
            if(visited[m*x+y-1]==0)
            {
                if(!(grid[x][y]=='O' && grid[x][y-1]=='O'))
                {
                    visited[m*(x)+y-1]=1;
                    dist[m*(x)+y-1]=q.front().second+1;
                    if(grid[x][y-1]!='O')
                    {
                        q.push(make_pair(m*(x)+y-1,q.front().second+1));
                    }
                }
                
            }
        }
        if(y<n-1)
        {
            if(visited[m*x+y+1]==0)
            {
                if(!(grid[x][y]=='O' && grid[x][y+1]=='O'))
                {
                    visited[m*(x)+y+1]=1;
                    dist[m*(x)+y+1]=q.front().second;
                    if(grid[x][y+1]!='O')
                    {
                        q.push(make_pair(m*(x)+y+1,q.front().second+1));
                    }
                }                
            }
        }
        q.pop();
    }
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cout << dist[m*i+j] << " ";
        }
        cout << endl;
    }
    for(int i=0;i<Q;i++)
    {
        int di,dj;
        cin >> di >> dj;
        di--;dj--;
        cout << dist[m*di+dj] << endl;
    }
    return 0;
}