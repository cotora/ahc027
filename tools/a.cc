#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <cassert>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
//#include <atcoder/all>
#endif

using namespace std;
//using namespace atcoder;
#define INF 2e9
#define repi(n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define uset unordered_set
#define umap unordered_map
typedef long long ll;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<ll> vl;
typedef vector< vector<ll> > vvl;
typedef vector<bool> vb;
typedef vector< vector<bool> > vvb;
typedef vector<double> vd;
typedef vector< vector<double> > vvd;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct Edge{
    int to;
    ll w;
    Edge(int to,ll w):to(to),w(w){}
};

using Graph=vector<vector<Edge>>;

template <typename T>
bool chmin(T &x,T y){
    if(x>y){
        x=y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T &x,T y){
    if(x<y){
        x=y;
        return true;
    }
    return false;
}

template <typename T>
string toBinary(T x){
    string res="";
    while(x!=0){
        if(x&1){
            res="1"+res;
        }
        else{
            res="0"+res;
        }
        x=x>>1;
    }
    return res;
}

int toDecimal(string s){
    int res=0;
    int d=1;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='1'){
            res+=d;
        }
        d*=2;
    }
    return res;
}

//O(logn)
ll pow_origin(ll x,ll n){
    ll ret=1;
    while(n>0){
        if(n&1)ret=ret*x;
        x=x*x;
        n>>=1;
    }
    return ret;
}

template <typename T>
void printVector(vector<T> &x){
    for(auto i : x)cout<<i<<" ";
    cout<<endl;
}

template <typename T>
void printVector2d(vector< vector<T> > &x){
    for(auto &i : x){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void printYesOrNo(bool x){
    cout<<(x ? "Yes" : "No")<<endl;
}

struct Solve{
    int n;
    vvb seen;
    vi dx{0,1,0,-1};
    vi dy{1,0,-1,0};
    string move="RDLU";
    string ans="";
    vvi h,v;
    vvl d;

    Solve(int n,vvi h,vvi v,vvl d) : n(n),h(h),v(v),d(d){
        seen.resize(n,vb(n,false));
    }

    void dfs(int x,int y){
        //cout<<x<<" "<<y<<endl;
        seen[x][y]=true;

        for(int i=0;i<4;i++){
            int mx=x+dx[i];
            int my=y+dy[i];
            if(mx>=0 && mx<n && my>=0 && my<n && !seen[mx][my]){
                if((dx[i]==0 && v[x][min(y,my)]==0) || (dy[i]==0 && h[min(x,mx)][y]==0)){
                    ans+=move[i];
                    dfs(mx,my);
                    ans+=move[(i+2)%4];
                }
            }
        }
    }

    string init_ans(){
        dfs(0,0);
        return ans;
    }
};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<fixed<<setprecision(15);
    int n;
    cin>>n;
    vvi h(n,vi(n));
    vvi v(n,vi(n));
    vvl d(n,vl(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            h[i][j]=c-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            v[i][j]=c-'0';
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>d[i][j];
        }
    }

    Solve g=Solve(n,h,v,d);
    cout<<g.init_ans()<<endl;

    return 0;
}