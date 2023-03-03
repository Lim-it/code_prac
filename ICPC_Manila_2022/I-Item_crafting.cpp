#include <bits/stdc++.h>

using namespace std;

#define fn(i, n) for(int i = 0; i < n; i++)
#define forn(i, j, k, in) for (int i=j ; i<k ; i+=in)
#define rforn(i, j, k, in) for (int i=j ; i>=k ; i-=in)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define in(A, B, C) assert( B <= A && A <= C)
#define mp make_pair
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi=acos(-1.0);
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef map<int,int> mapii;
typedef set<int> seti;
typedef long int li;
typedef unsigned long int uli;
typedef long long int ll;
typedef unsigned long long int  ull;
/*************************/
/******** own func *******/

struct Item{
    int id;
    vi raw_count = vi(10,0);
    vi recipe;
    bool calculated = false;
};

int upp = 100000000;

void solve(){
    int n, m;
    cin >> n >> m;

    int raw_index = 0;
    vi raw_list;
    vector<Item> items;
    vi inventory(10,0);

    fn(i,m){
        int ci;
        cin >> ci;
        Item a;
        a.id = i;
        if(ci == 0){ //raw
            int pi;
            cin >> pi;
            a.calculated = true;
            a.raw_count[raw_index] = 1;
            inventory[raw_index] = pi;
            raw_index++;
            raw_list.pb(i);
        }
        else{
            fn(j, ci){
                int rec;
                cin >> rec; rec--;
                a.recipe.pb(rec);
            }
        }
        items.pb(a);
    }
    //calculate
    fn(i,m){
        if(items[m-i-1].calculated) continue;
        for(int rec : items[m-i-1].recipe){
            fn(j,10){
                if(items[m-i-1].raw_count[j] <= upp){
                    items[m-i-1].raw_count[j] += items[rec].raw_count[j];;
                    if(items[m-i-1].raw_count[j] > upp) items[m-i-1].raw_count[j] = upp+1;
                }
            }
        }
        items[m-i-1].calculated = true;
    }
    //count
    int max_count = 0;
    fn(i, 1<<n){
        vi cur_material(10,0);
        bitset<16> b(i);
        bool check = true;
        fn(j, n){
            if(b[j] == 1){
                fn(k, 10){
                    cur_material[k] += items[j].raw_count[k];
                }
            }
        }
        fn(k, 10){
            if(cur_material[k] > inventory[k]) {
                check = false;
                break;
            }
        }
        if(check) max_count = max(max_count, (int)b.count());
    }
    cout << max_count << endl;
}

/*************************/
/******* main func *******/
int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    int tc;
	tc = 1;
	//cin >> tc;

	while(tc--){solve();}

	/*while(cin>>tc){
        if(tc==0) break;
        solve();
    }*/
	return 0;
}
