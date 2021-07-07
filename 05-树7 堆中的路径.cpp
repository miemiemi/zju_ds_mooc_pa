#include <iostream>

using namespace std;

const int N = 1010;
int heap[N];
int heapsize;

void insert(int X)
{   
    int i;

    for(i = ++heapsize; heap[i / 2] > X; i /= 2)
        heap[i] = heap[i / 2];
    
    heap[i] = X;
}


int main()
{
    int n, m;
    cin >> n >> m;
    heap[0] = -10001;
    for(int i = 1; i <= n; i++){
        int temp;
        cin >> temp;
        insert(temp);
    }
        
    while (m--)
    {
        int index;
        cin >> index;
        cout << heap[index];

        for(int i = index / 2; i > 0; i /= 2)
            cout << " " << heap[i];
        cout << endl;
    }
    
    return 0;
}