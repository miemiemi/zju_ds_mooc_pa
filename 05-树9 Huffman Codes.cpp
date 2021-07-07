#include <iostream>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int isPrefix(char *s1, char *s2) {		  
	while (s1 && s2 && *s1 == *s2)		 
		++s1, ++s2;
	if (*s1 == '\0' || *s2 == '\0')	 
		return 1;
	else
		return 0;
}

int hasPrefixCode(char s[][200], int n) { 
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (isPrefix(s[i], s[j]))						//s[i], s[j]都是字符串
				return 1;
	return 0;
}

int main()
{
    map<char, int> frequency;
    priority_queue<int, vector<int>, greater<int>> heap;
    int num;
    cin >> num;

    for(int i = 0; i < num; i++){
        char name;
        int fre;
        cin >> name >> fre;
        frequency[name] = fre;
        heap.push(fre);
    }

    int minWPL = 0;
    while (heap.size() > 1)
    {
        int min1, min2;
        min1 = heap.top(), heap.pop();
        min2 = heap.top(), heap.pop();
        minWPL += min1 + min2; 
        heap.push(min1 + min2);
    }
    int checknum;
    cin >> checknum;

    while (checknum--)
    {
        char temp;
        char s[256][200];
        int wpl = 0;
        for(int i = 0; i < num; i++){
            scanf("\n%c %s", &temp, s[i]);
            wpl += strlen(s[i]) * frequency[temp];
        }
        if (wpl == minWPL && !hasPrefixCode(s, num))		 
			puts("Yes");
		else
			puts("No");
    }
    
    return 0;
}