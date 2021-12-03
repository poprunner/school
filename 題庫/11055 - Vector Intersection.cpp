// my vector version 1.0
/*
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N, M;
    while (cin >> N && N != 0)
    {
        int x;
        vector<int> v, w;
        for (int i = 0; i < N; ++i)
        {
            cin >> x;
            v.push_back(x);
        }
        cin >> M;
        for (int i = 0; i < M; ++i)
        {
            cin >> x;
            w.push_back(x);
        }
        sort(v.begin(), v.end());
        sort(w.begin(), w.end());
        int i = 0, j = 0;
        bool empty = true;
        while (i < v.size() && j < w.size())
        {
            if (v[i] == w[j])
            {
                if (!empty)
                    cout << " ";
                cout << v[i];
                ++i, ++j;
                empty = false;
            }
            else if (v[i] < w[j])
                ++i;
            else
                ++j;
        }
        if (empty)
            cout << "empty";
        cout << endl;
    }
}
*/

// map version  // TLE
/*
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    int n, m;
    while (cin >> n && n != 0)
    {
        map<int, int> N;
        while (n > 0)
        {
            int i;
            cin >> i;
            if (N.count(i) == 0)
                N[i] = 1;
            else
                N[i]++;
            --n;
        }
        cin >> m;
        map<int, int> M;
        while (m > 0)
        {
            int i;
            cin >> i;
            if (M.count(i) == 0)
                M[i] = 1;
            else
                M[i]++;
            --m;
        }

        bool isempty = true;
        for (auto &v : M)
        {
            if (N.count(v.first))
            {
                int small = (v.second < N[v.first]) ? v.second : N[v.first];
                while (small > 0)
                {
                    if (isempty)
                    {
                        isempty = false;
                        cout << v.first;
                    }
                    else
                        cout << " " << v.first;
                    --small;
                }
            }
        }
        if (isempty)
        {
            cout << "empty\n";
        }
        else
        {
            cout << "\n";
        }
    }
}
*/

// vector version
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    std::ios_base::sync_with_stdio(false);
    int n, m;
    while (cin >> n && n != 0)
    {
        vector<int> N(n);
        for (int i = 0; i < n; i++)
        {
            cin >> N[i];
        }
        cin >> m;
        vector<int> M(m);
        for (int i = 0; i < m; i++)
        {
            cin >> M[i];
        }

        sort(N.begin(), N.end());
        sort(M.begin(), M.end());

        int i = 0, j = 0;
        bool isempty = true;
        while (i < m && j < n)
        {
            if (M[i] == N[j])
            {
                if (isempty)
                {
                    cout << M[i];
                    isempty = false;
                }
                else
                {
                    cout << " " << M[i];
                }
                ++i;
                ++j;
            }
            else if (M[i] > N[j])
            {
                ++j;
            }
            else
            {
                ++i;
            }
        }
        if (isempty)
            cout << "empty";
        cout << "\n";
    }
}
*/

// my vector version 2.0

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int N, M;
    while (cin >> N && N != 0)
    {
        vector<int> v(N); // 直接呼叫元素者 v[i] 必須先指定大小 v(N)
        for (int i = 0; i < N; ++i)
            cin >> v[i];
        cin >> M;
        vector<int> w(M);
        for (int i = 0; i < M; ++i)
            cin >> w[i];
        sort(v.begin(), v.end());
        sort(w.begin(), w.end());
        int i = 0, j = 0;
        bool empty = true;
        while (i < v.size() && j < w.size())
        {
            if (v[i] == w[j])
            {
                if (empty)
                {
                    cout << v[i];
                    empty = false;
                }
                else
                    cout << " " << v[i];
                ++i, ++j;
            }
            else if (v[i] < w[j])
                ++i;
            else
                ++j;
        }
        if (empty)
            cout << "empty";
        cout << endl;
    }
}
