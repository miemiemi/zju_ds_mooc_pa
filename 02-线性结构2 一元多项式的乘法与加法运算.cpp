#include <iostream>

using namespace std;

const int N = 1010;
int A[N], B[N], sum[N], mul[N * 2];

int main()
{
    int k, exponent, coefficient;
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> coefficient >> exponent;
        A[exponent] = coefficient;
    }
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> coefficient >> exponent;
        B[exponent] = coefficient;
    }

    for(int i = 0; i < N; i++)
        sum[i] = A[i] + B[i];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            mul[i + j] += A[i] * B[j];
    
    bool flag = false;
    for(int i = N * 2 - 1; i >= 0 ; i--){
        if(mul[i] != 0){
            if(!flag){
                cout << mul[i] << " " << i;
                flag = true;
            }else
                cout << " " << mul[i] << " " << i;
        }
    }
    if(!flag)
        cout << "0 0";
    cout << endl;

    flag = false;
    for(int i = N - 1; i >= 0 ; i--){
        if(sum[i] != 0){
            if(!flag){
                cout << sum[i] << " " << i;
                flag = true;
            }else
                cout << " " << sum[i] << " " << i;
        }
    }
    if(!flag)
        cout << "0 0";
    cout << endl;

    return 0;
}