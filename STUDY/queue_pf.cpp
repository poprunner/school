/*
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

using Graph = map<string, set<string>>;
using Path = list<string>;

set<Path> find_sbp(Graph &g, string cur, string dst, int lim) // cur : current
{
    Path pa{cur};                    // == pa.push_back(cur)
    pair<string, Path> sPp{cur, pa}; // sPp : string-Path pair

    queue<pair<string, Path>> qu;
    qu.push(sPp);

    set<Path> sol;

    while (!qu.empty())
    {
        pair<string, Path> prc_sPp = qu.front(); // prc_sPp == processing sPp
        qu.pop();
        string now = prc_sPp.first;
        Path now_pa = prc_sPp.second;

        for (auto &i : g[now])
            if (find(now_pa.begin(), now_pa.end(), i) == now_pa.end())
            {
                Path tmp_now_pa = now_pa;
                tmp_now_pa.push_back(i);
                if (i == dst)
                {
                    if (tmp_now_pa.size() < lim)
                        sol.insert(tmp_now_pa);
                }
                else
                {
                    pair<string, Path> tmp{i, tmp_now_pa};
                    qu.push(tmp);
                }
            }
    }

    return sol;
}

int main()
{
    Graph st_graph;

    ifstream fin;
    fin.open("station.txt");
    string dep, arv;
    while (fin >> dep)
    {
        fin >> arv;
        st_graph[dep].insert(arv);
        st_graph[arv].insert(dep);
    }
    fin.close();

    set<Path> sbp;
    sbp = find_sbp(st_graph, "a", "f", 100);
    for (auto &i : sbp)
    {
        for (auto &j : i)
            cout << j << "-->";
        cout << endl;
    }
}
*/

#include <iostream>
#include <fstream>
#include <set>
#include <queue>
#include <utility>
#include <list>
#include <map>
#include <algorithm>

using namespace std;

using graph = map<string, set<string>>;
using path = list<string>;

set<path> sbp(graph &g, string cur, string dst, int lim)
{
    path pa;
    pa.push_back(cur);

    pair<string, path> cur_pa;
    cur_pa = make_pair(cur, pa);

    queue<pair<string, path>> qu;
    qu.push(cur_pa);

    set<path> sol;

    while (!qu.empty())
    {
        pair<string, path> prc_str_pa = qu.front();
        qu.pop();

        string prc_cur = prc_str_pa.first;
        path prc_pa = prc_str_pa.second;

        for (auto &i : g[prc_cur])
        {
            if (find(prc_pa.begin(), prc_pa.end(), i) == prc_pa.end())
            {
                path tmp_pa = prc_pa;
                tmp_pa.push_back(i);

                if (i == dst)
                {
                    if (tmp_pa.size() < lim)
                    {
                        sol.insert(tmp_pa);
                    }
                }
                else
                {
                    pair<string, path> new_str_pa;
                    new_str_pa = make_pair(i, tmp_pa);
                    qu.push(new_str_pa);
                }
            }
        }
    }

    return sol;
}

int main()
{
    ifstream fin;
    fin.open("station.txt");

    graph g;
    string dep, arv;
    while (fin >> dep)
    {
        fin >> arv;
        g[dep].insert(arv);
        g[arv].insert(dep);
    }

    fin.close();

    set<path> sol;
    sol = sbp(g, "a", "b", 10);

    for (auto &i : sol)
    {
        for (auto &j : i)
        {
            cout << j << "-->";
        }
        cout << endl;
    }
}