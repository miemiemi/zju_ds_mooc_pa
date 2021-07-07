#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    cin >> num;
    
    vector<int> seq;
    while (num--){
        int N;
        cin >> N;
        seq.push_back(N);
    }
    int sum = 0, ans = 0;
    for(int i = 0; i < seq.size(); i++){
        sum += seq[i];
        if(sum < 0)
            sum = 0;
        if(sum > ans)
            ans = sum;
    }
    cout << ans << endl;
    return 0;
}