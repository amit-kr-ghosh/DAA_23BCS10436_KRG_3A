#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s) {
    unordered_map<char,int> freq;
    for(char c : s) freq[c]++;

    priority_queue<pair<int,char>> pq;
    for(auto &p : freq) pq.push({p.second, p.first});

    string ans = "";
    pair<int,char> prev = {0, '#'};  

    while(!pq.empty()) {
        auto cur = pq.top(); 
        pq.pop();

        ans += cur.second;
        cur.first--;

        if(prev.first > 0) pq.push(prev);

        prev = cur;
    }

    for(int i = 1; i < ans.size(); i++)
        if(ans[i] == ans[i-1]) return "-1";

    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << reorganizeString(s);
}
