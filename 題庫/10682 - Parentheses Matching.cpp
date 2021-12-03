#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

map<char, char> parens = {{'{', '}'}, {'[', ']'}, {'(', ')'}, {'<', '>'}};

int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.ignore(1, '\n');
    for (int cnt = 1; cnt <= t; ++cnt)
    {
        bool valid = true;
        stack<char> st;
        string str;
        getline(cin, str);
        for (auto c : str)
            if (c == '{' || c == '[' || c == '(' || c == '<')
                st.push(c);
            else if (c == '}' || c == ']' || c == ')' || c == '>')
                if (st.empty() || (c != parens[st.top()]))
                {
                    valid = false;
                    break;
                }
                else
                    st.pop();
        if (!st.empty())
            valid = false;

        cout << "Case " << cnt << ": " << ((valid) ? "Yes" : "No") << endl;
    }
}
