#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n, e;
    cin >> n >> e;

    vector<int> adj_list[n];

    while(e--)
    {
        int a, b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    vector<int> v;
    int q;
    cin >> q;

    while(q--)
    {
        int a;
        cin >> a;
        for(auto nodes : adj_list[a])
        {
            v.push_back(nodes);
        }

        if(v.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            sort(v.begin(), v.end(), greater<int>());
            for(int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << endl;
    
            v.clear();
        }


    }

    
    return 0;
}
