#include <bits/stdc++.h>
using namespace std;
#include <chrono>
#include <thread>
using namespace std::chrono;
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef set<int> st;

void getv(vi &vec,int n){for(int i=0;i<n;i++)cin>>vec[i]; }
void getvl(vl &vec,int n){ for (int i=0;i<n;i++)cin>>vec[i]; }


ll sum(ll start, ll end){
    ll sum = 0;
    while(start++ <=end)cout<<start<<' ';
    // while(start <=end)sum+=start++;
    return sum;
}
int main()
{
    int s = 0,e=1000;
    std::thread t1(sum,s,e);
    std::thread t2(sum,1001,2000);
    auto startTime = high_resolution_clock::now();
    // cout<<sum(0,5609)<<endl;
    auto endTime = high_resolution_clock::now();
    auto diff = duration_cast<microseconds>(endTime - startTime);
    t1.join();
    cout<<diff.count()<<endl;
    cout<<endl;
    auto time = system_clock::to_time_t(system_clock::now());
    
    cout<<ctime(&time);
    // cout<<typeid(time).name();
    t2.join();
    return 0;
}