#include <iostream>
#include <queue>


using namespace std;

const int N = 11;

int lc[N], rc[N];
bool st[N];     //false

void bfs(int root)
{
    if(root == -1)
        return;
    bool flag = false;
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        if(lc[temp] != -1)
            q.push(lc[temp]);
        if(rc[temp] != -1)
            q.push(rc[temp]);
        if(lc[temp] == -1 && rc[temp] == -1){
            if(!flag){
                printf("%d", temp);
                flag = true;
            }else
                printf(" %d", temp);
        }
    }
    
}

int main()
{
    int n;
    scanf("%d\n", &n);
    char left,right;
    for(int i = 0; i < n; i++){
        scanf("%c %c\n", &left, &right);
        if(left == '-')
            lc[i] = -1;
        else{
            lc[i] = left - '0';
            st[lc[i]] = true;
        }

        if(right == '-')
            rc[i] = -1;
        else{
            rc[i] = right - '0';
            st[rc[i]] = true;
        }
    }

    int root = -1;
    for(int i = 0; i < n; i++)
        if(!st[i])
            root = i;
    
    bfs(root);
    return 0;
}