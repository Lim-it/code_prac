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
typedef long long int ll;
typedef unsigned long long int  ull;

/*************************/
/******** own func *******/

bool hegemony = false;

struct ipair{
    ll val;
    int id;
    bool operator>(const ipair &y) const{
        if (val != y.val){
            if(hegemony) return val > y.val;
            else return val < y.val;
        }
        return id > y.id;
    }
    bool operator==(const ipair &y) const{
        return (id == y.id && val == y.val);
    }
    ipair(ll val, int id): val(val), id(id){};
};

struct Node {
	ipair val;
	int pri;
	Node *lc, *rc;
	Node *left, *right;
	Node(ll val, int id) : val(ipair(val, id)), pri(rand()), lc(NULL), rc(NULL), left(NULL), right(NULL){};
};

vector<Node*> neighbor;
vi collapsed;
ll cur_max = 0;
ll sum = 0;

void split(Node *root, ipair x, Node *&left, Node *&right) {
	if (!root) {
		left = right = NULL;
		return;
	}
	if (!(root->val > x)) {
		split(root->right, x, root->right, right);
		left = root;
	} else {
		split(root->left, x, left, root->left);
		right = root;
	}
}

void merge(Node *&root, Node *left, Node *right) {
	if (!left || !right) {
		root = left ? left : right;
	}
	else if (left->pri > right->pri) {
		merge(left->right, left->right, right);
		root = left;
	}
	else {
		merge(right->left, left, right->left);
		root = right;
	}
}

void insert (Node *&t, Node* it) {
    if (!t)
        t = it;
    else if (it->pri > t->pri)
        split (t, it->val, it->left, it->right),  t = it;
    else
        insert (t->val > it->val ? t->left : t->right, it);
}

void erase (Node *&t, ipair key) {
    if (t->val == key) {
        merge (t, t->left, t->right);
    }
    else
        erase (t->val > key ? t->left : t->right, key);
}

void inorder(Node* t){
    if(t == NULL) return;
    inorder(t->left);
    cout << t->val.id << '\n';
    if(t->left)
        cout << "left: " << t->left->val.id <<"     ";
    if(t->right)
        cout << "right: " << t->right->val.id;
    cout << "\ndone node\n";
    inorder(t->right);
}

Node* findmin(Node* t){
    if(t->left == NULL) return t;
    return findmin(t->left);
}

void collapse(Node*& root){
    Node* cur = findmin(root);
    erase(root, cur->val);
    ll wealth = cur->val.val;
    cout << cur->val.id << ' ' << wealth << '\n';
    collapsed[cur->val.id - 1] = 1;
    sum -= wealth;
    if(cur->lc){
        erase(root, cur->lc->val);
        cur->lc->val.val += wealth/2;
        cur->lc->left = nullptr;
        cur->lc->right = nullptr;
        cur->lc->rc = cur->rc;
        sum += wealth/2;
        insert(root, cur->lc);
    }
    if(cur->rc){
        erase(root, cur->rc->val);
        cur->rc->val.val += wealth/2;
        cur->rc->left = nullptr;
        cur->rc->right = nullptr;
        cur->rc->lc = cur->lc;
        sum += wealth/2;
        insert(root, cur->rc);
    }
    delete cur;
    return;
}

void solve(){
    int n;
    cin >> n;
    fn(i,n){
        ll wealth;
        cin >> wealth;
        Node* node = new Node(wealth, i+1);
        neighbor.pb(node);
        sum += wealth;
    }
    //link node
    neighbor[0]->rc = neighbor[1];
    for(int i=1; i<n-1; i++){
        neighbor[i]->rc = neighbor[i+1];
        neighbor[i]->lc = neighbor[i-1];
    }
    neighbor[n-1]->lc = neighbor[n-2];

    //init treap
    Node* root = neighbor[0];
    for(int i=1;i<n;i++){
        insert(root, neighbor[i]);
    }

    //collpase each
    collapsed.assign(n, 0);
    fn(i,n-1){
        if(!hegemony){
            cur_max = findmin(root)->val.val;
            if(cur_max > sum/2){ //reconstruct
                hegemony = true;
                int new_root_ind = 0;
                fn(i,n){
                    if(collapsed[i] == 0){
                        neighbor[i]->left = nullptr;
                        neighbor[i]->right = nullptr;
                        new_root_ind = i;
                    }
                }
                root = neighbor[new_root_ind];
                fn(i,n){
                    if(collapsed[i] == 0 && i != new_root_ind){
                        insert(root, neighbor[i]);
                    }
                }
            }
        }
        collapse(root);
    }
    cout << root->val.id << ' ' << root->val.val << '\n';
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
	return 0;
}
