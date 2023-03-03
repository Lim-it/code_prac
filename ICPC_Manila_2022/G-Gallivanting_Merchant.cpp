#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    vi add;
    vi del;
    for(int i = 0;i < n; i++){
        int a, b;
        cin >> a >> b;
        if(b-a >= k) add.push_back(0);
        else{
            a=a%k; b=b%k;
            if(b >= a) {
                add.push_back(a);
                del.push_back(b + 1);
            }
            else{
                add.push_back(0);
                del.push_back(b + 1);
                add.push_back(a);
            }
        }
    }
    sort(add.begin(), add.end());

    sort(del.begin(), del.end());
/*for(auto i : add) cout << i << endl;    cout << "BOOP" << endl;
    for(auto i : del) cout << i << endl;*/
    int res = 0;
    int x = 0;
    int ai = 0, bi = 0;
    int aend = add.size(), bend = del.size();
    while(true){
        if(aend == ai && bend == bi) break;
        else if (aend == ai){
            break;
        }
        else if(bend == bi){
            x++;
            ai++;
            res = max(res,x);
        }
        else if(add[ai] == del[bi]){
            x--;
            bi++;
        }
        else if(add[ai] < del[bi]){
            x++;
            ai++;
            res = max(res,x);
        }
        else if(add[ai] > del[bi]){
            x--;
            bi++;
        }
    }
    cout << res;

    return 0;
}
