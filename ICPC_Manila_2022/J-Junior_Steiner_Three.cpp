#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<char> vc;

vi x, y;

int add(int ax, int ay, int bx, int by){
    int xdiff = abs(ax - bx);
    int ydiff = abs(ay - by);
    return xdiff + ydiff - 1;
}

int findxy(){
    int res = 10000;
    int ret;
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            int tmp = add(x[0], y[0], x[i], y[j]) + add(x[1], y[1], x[i], y[j]) + add(x[2], y[2], x[i], y[j]);
            if(tmp < res){
                res = tmp;
                ret = i*3 + j;
            }
        }
    }
    return ret;
}

void color(int ax,int ay,int bx,int by, vector<string>& g){
    if(ax == bx){
        for(int i = min(ay,by); i <= max(ay,by); i++){
            g[ax][i] = '#';
        }
    }
    else if(ay == by){
        for(int i = min(ax,bx); i <= max(ax,bx); i++){
            g[i][ay] = '#';
        }
    }
    else {
        color(ax, by, ax, ay, g);
        color(ax, by, bx, by, g);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int r, c;
    cin >>r >> c;
    vector<string> grid(r);
    for(int i =0;i<r;i++){
        cin>>grid[i];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j] == '#') {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }

    /*for(int i=0;i<3;i++)
        cout << x[i] << " " << y[i] << endl;
*/
    int ind = findxy();
    int finalx = x[ind/3];
    int finaly = y[ind%3];
    /*cout << "FINAL" << endl;
    cout << finalx << " " << finaly << endl;*/
    color(finalx, finaly, x[0], y[0], grid);
    color(finalx, finaly, x[1], y[1], grid);
    color(finalx, finaly, x[2], y[2], grid);
    for(auto s: grid) cout << s << endl;

    return 0;
}
