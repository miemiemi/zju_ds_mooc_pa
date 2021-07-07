#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    while (k--)
    {
        vector<int> seq(n + 1);
        for(int i = 1; i < n + 1; i++)
           cin >> seq[i];

        stack<int> s;
        int index = 1;
        for(int i = 1; i < n + 1; i++){
            s.push(i);

            if(s.size() > m)
                break;
            while (!s.empty() && seq[index] == s.top()){
                s.pop();
                index++;
            }
        }

        if(s.empty())
            puts("YES");
        else
            puts("NO");
    }

    return 0;
    
}