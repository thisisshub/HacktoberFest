#include "../libraries/mixin.h"
// dfs best usage is for "search" or to find if exist


class bfs // diagraph
{
private:
    lld dir = 0;
    bool flag = 0;
public :

    struct Node
    {
        vector <lld> to;
        lld val = -1;
        bool visited = false;

    } typedef n;

    vector <n> arr;
    queue <int> q;

    dfs(int n = 0)
    {
        arr.resize(n);
    }

    void setDir(lld num)
    {
        this->dir = num;
    }

    lld getDir()
    {
        return this->dir;
    }

    void _init()
    {
        lld n,m,t,f;
        cin>>n>>m;
        arr.clear();
        arr.resize(n+5);
        flag = 0;
        for(int i = 0 ; i<n; ++i)
            cin>>arr[i].val;
        for(int i = 0 ; i<m; ++i)
        {
            cin>>f>>t;
            arr[f].to.push_back(t);
        }
    }

    void _insert(lld f,lld t)
    {
        arr[f].to.push_back(t);
    }

    bool _find(int start,lld dir)
    {
        setDir(dir);
        _find_bfs(start);
        return flag;
    }

    void _find_bfs(int start)
    {
        auto dir = getDir();
        q.push(start);
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            if(arr[now].visited || flag)
                continue ;
            arr[now].visited = true;
            if(arr[now].val == dir)
            {
                flag = true;
                return;
            }
            for(auto &i : arr[now].to)
            {
                if(arr[i].val == dir)
                {
                    flag = true;
                }
                q.push(i);
            }

        }
    }
};

std::ostream& operator<<(std::ostream& os, const bfs::n& node)
{
    os<<"val : "<<node.val;
    ENDLINE
    os<<"to : ";
    if(!node.to.size())
        os << "No members";
    else
        for(auto &i : node.to)
        {
            os << i << " ";
        }
    return os<<"\n";
}


int main()
{
    bfs a;
    a._init();
    printArr(a.arr);
    cout<<a._find(0,2);
}
