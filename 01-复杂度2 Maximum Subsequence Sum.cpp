#include <iostream>

using namespace std;

const int N = 10010;

int dp[N], seq[N], start[N];

int main()
{
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++)
        cin >> seq[i];
    int ans = -1, endp;
    dp[1] = seq[1];
    start[1] = 1;

    for(int i = 2; i <= k; i++){
        if(dp[i - 1] + seq[i] >= seq[i]){
            dp[i] = dp[i - 1] + seq[i];
            start[i] = start[i - 1];
        }else
        {
            dp[i] = seq[i];
            start[i] = i;
        }
    }
    for(int i = 1; i <= k; i++){
        if(ans < dp[i]){
            ans = dp[i];
            endp = i;
        }
    }

    if(ans == -1)
        cout << 0 << " " << seq[1] << " " << seq[k];
    else
        cout << ans << " " << seq[start[endp]] << " " << seq[endp];
    cout << endl;

    return 0;
}