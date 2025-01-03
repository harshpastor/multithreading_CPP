#include <bits/stdc++.h>
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

void func(int a, int b){
    while(a<=b)cout<<a++<<' ';
    cout<<endl;
}
//1.creating an object of thread: using the first parameter as the function and rest parameters for the parameters of that function
//2. lambda function

//always use thread.join() to start the thread
int main()
{
    thread t1 = thread(func,0,1000);
    // auto lambda_func = [](int a,int b){
    //         while(b>=a){
    //             cout<<b--<<' ';
    //         }
    // };
    // thread t2 = thread(lambda_func,0,1000);
    thread t2 ([](int a,int b){
                        while(b>=a){
                            cout<<b--<<' ';
                        }
                    },0,1000);
    t1.join();
    t2.join();
    
    return 0;
}