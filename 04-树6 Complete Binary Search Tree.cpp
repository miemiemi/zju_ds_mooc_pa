#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, k;
int tree[N], val[N];
//完全二叉树按照堆存

//得到中序序列后还原二叉树
void dfs(int u)
{
    if(u * 2 <= n)
        dfs(u * 2);
    tree[u] = val[k++];
    if(u * 2 + 1 <= n)
        dfs(u * 2 + 1);
}


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> val[i];
    
    sort(val + 1, val + n + 1);
    k = 1;
    dfs(1);

    cout << tree[1];
    for(int i = 2; i <= n; i++)
        cout << " " << tree[i];
    cout << endl;

    return 0;
}