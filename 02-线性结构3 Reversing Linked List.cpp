#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 100010;

// 偷！

int n, m;
int h, ne[N], e[N];


int main()
{
    scanf("%d%d%d", &h, &n, &m);

    for(int i = 0; i < n; i++){
        int address, data, next;
        scanf("%d%d%d", &address, &data, &next);
        e[address] = data;
        ne[address] = next;
    }

    vector<int> v;
    for(int i = h; i != -1; i = ne[i]) v.push_back(i);

    for(int i = 0; i + m - 1 < v.size(); i += m)
        reverse(v.begin() + i, v.begin() + i + m);

    for(int i = 0; i < v.size(); i++){
        printf("%05d %d", v[i], e[v[i]]);
        if (i == v.size() - 1)
            printf(" -1\n");
        else
            printf(" %05d\n",v[i+1]);
    }
    return 0;
    
}