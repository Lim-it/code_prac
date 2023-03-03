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

vi ans;
vvi mat;
vector<vector<pii>> adj;
bool flag;

void dfs(int c, int x, int h){
    ans[c] = x;
    for(auto i : adj[c]){
        if(ans[i.first] == -1){
            dfs(i.first, (x+i.second) % h, h);
        }
        else if((x + i.second) % h != ans[i.first]){
            flag = false;
        }
    }
}

int mulmod(int a, int b){return (1LL * a * b)%MOD;}
int powmod(int  a, int b){
    ll res = 1;
    a %= MOD;
    while(b){
        if(b&1)
            res = mulmod(res, a);
        b = b >> 1;
        a = mulmod(a,a);
    }
    return res;
}

void solve(){
    int n, m, h;
    cin >> n >> m >> h;
    mat.assign(n, vi(m,0));
    adj.assign(n,vector<pii>());
    ans.assign(n,-1);
    flag = true;
    fn(i,n){
        fn(j,m){
            cin>>mat[i][j];
        }
    }

    int comp = 0;
    int empty_column = 0;
    fn(j, m){
        int last = -1;
        bool all_empty = true;
        fn(i, n){
            if(mat[i][j] != -1){
                if(last != -1) {
                    adj[last].pb({i, (mat[i][j] - mat[last][j] + h) % h});
                    adj[i].pb({last, (mat[last][j] - mat[i][j] + h) % h});
                }
                last = i;
                all_empty = false;
            }
        }
        empty_column += all_empty;
    }
    fn(i,n){
        if (ans[i] == -1) {
            comp++;
            dfs(i, 0, h);
        }
    }
    //cout << "test" << comp << ' ' << empty_column << '\n';
    cout << powmod(h, comp - 1 + empty_column) * flag << "\n";
}

/*************************/
/******* main func *******/
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int tc;
	//tc = 1;
	cin >> tc;

	while(tc--){
		solve();
	}
	return 0;
}
