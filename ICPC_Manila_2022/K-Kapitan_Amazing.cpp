#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;

string t1 = "QWERTYUIOP";
string t2 = "ASDFGHJKL";
string t3 = "ZXCVBNM";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string a1, a2, a3;
    vc pos;

    cin >> a1 >> a2 >> a3;
    for(int i = 0;i<a1.size();i++){
        if(a1[i]=='*') pos.push_back(t1[i]);
    }
    for(int i = 0;i<a1.size();i++){
        if(a2[i]=='*') pos.push_back(t2[i]);
    }
    for(int i = 0;i<a1.size();i++){
        if(a3[i]=='*') pos.push_back(t3[i]);
    }
    int query;
    cin >> query;
    string test;
    int pp = pos.size();
    bool flag;
    for(int k = 0; k < query;k++){
        cin >> test;
        int tt = test.size();
        int sum = 0;
        vector<bool> visited(pp,false);
        flag = true;
        for(int i=0;i<pp;i++){
            for(int j=0;j<tt;j++){
                if(pos[i]==test[j]) {
                    sum++;
                    visited[i] = true;
                }
            }
        }
        for(int i=0;i<pp;i++){
            if(visited[i] == false) {
                flag = false;
            }
        }
        if(flag && sum == tt) {
            cout << "POSSIBLE\n";
        }
        else cout << "IMPOSSIBLE\n";
    }
    return 0;
}
