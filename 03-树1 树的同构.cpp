#include <iostream>
#include <cstring>

using namespace std;

const int N = 11;
struct TreeNode
{
    char Element;
    int Left;
    int Right;
};

TreeNode t1[N], t2[N];

int BuildTree(TreeNode T[])
{
    bool hasfather[N];
    memset(hasfather, false, sizeof(hasfather));

    int root = -1;

    int num;
    scanf("%d\n",&num);
    char data, lc, rc;
    for(int i = 0; i < num; i++)
    {
        scanf("%c %c %c\n", &T[i].Element, &lc, &rc);
        if(lc != '-'){
            T[i].Left = lc - '0';
            hasfather[T[i].Left] = true;
        }
        else
            T[i].Left = -1;

        if(rc != '-'){
            T[i].Right = rc - '0';
            hasfather[T[i].Right] = true;
        }
        else
            T[i].Right = -1;
    }
    for(int i = 0; i < num; i++)
        if(!hasfather[i])
            root = i;
    return root;
}

bool Isomorphic(int R1, int R2)
{
    if(R1 == -1 && R2 == -1)
        return true;
    if((R1 == -1 && R2 != -1) || (R1 != -1 && R2 == -1))
        return false;
    if(t1[R1].Element != t2[R2].Element)
        return false;
    if((t1[R1].Left == -1)&&(t2[R2].Left== -1))    
        return Isomorphic(t1[R1].Right, t2[R2].Right);
    if ( ((t1[R1].Left != -1)&&(t2[R2].Left!= -1))&&((t1[t1[R1].Left].Element)==(t2[t2[R2].Left].Element)) )
        return Isomorphic( t1[R1].Left, t2[R2].Left) && Isomorphic(t1[R1].Right, t2[R2].Right);
    else
        return Isomorphic( t1[R1].Left, t2[R2].Right) && Isomorphic(t1[R1].Right, t2[R2].Left);
    
}


int main()
{   
    int R1, R2;
    R1 = BuildTree(t1);
    R2 = BuildTree(t2);

    if(Isomorphic(R1, R2))
        puts("Yes");
    else
        puts("No");
    
    return 0;

}