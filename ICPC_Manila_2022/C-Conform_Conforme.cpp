#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, k;
    cin>>n>>k;
    vi a(n,0);
    int t = 0;
    unordered_map<int,int> f;
    for(int i=0;i<n;i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    vi last(n,0);
    bool flag;
    while(t < k){
        for(int i = 0;i <n;i++){
            a[i] = f[a[i]];
        }
        f.clear();
        for(int i = 0;i < n;i++){
            f[a[i]]++;
        }
        t++;
        flag = true;
        for(int i = 0; i < n; i++){
            if(last[i] != a[i]) flag = false;
        }
        if(t == k || flag) {
            for(auto i : a) cout << i << ' ' ;
            break;
        }

        for(int i = 0; i < n; i++){
            last[i] = a[i];
        }
    }


    return 0;
}
