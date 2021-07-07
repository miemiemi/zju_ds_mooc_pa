#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector<int> preorder, inorder, postorder;

void buildTree(int pl, int pr, int il, int ir)
{
    if(il > ir)
        return;
    int root = preorder[pl];
    int k;
    for(k = 0; k < inorder.size(); k++)
        if(root == inorder[k])
            break;
    buildTree(pl + 1, pl + 1 + (k - 1 - il), il, k - 1);
    buildTree(pr - (ir - k - 1), pr, k + 1, ir);
    postorder.push_back(root);
}

int main()
{
    stack<int> stk;

    cin >> n;
    for(int i = 0; i < n * 2; i++){
        string op;
        int num;
        cin >> op;
        if(op == "Pop"){
            inorder.push_back(stk.top());
            stk.pop();
        }else{
            cin >> num;
            preorder.push_back(num);
            stk.push(num);
        }
    }

    buildTree(0, n - 1, 0, n - 1);
    cout << postorder[0];
    for(int i = 1; i < n ; i++)
        cout << " " << postorder[i];

    cout << endl;
    return 0;

}