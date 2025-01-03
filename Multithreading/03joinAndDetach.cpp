#include <iostream>
#include <chrono>
#include <algorithm>
#include <thread>
using namespace std;
using namespace std::chrono;
//to sleep: this_thread::sleep_for(seconds(s))
void run(int x){
    while(x-->0)cout<<x<<' ';
    std::this_thread::sleep_for(seconds(3));
    cout<<"exiting\n";
}

int main(){
    thread t1([](int x){
        while(x-->0)cout<<x<<' ';
    std::this_thread::sleep_for(seconds(3));
    cout<<"\nexiting t1";
    },10);
    thread t2([](int x){
        while(x-->0)cout<<x<<' ';
    std::this_thread::sleep_for(seconds(1));
    cout<<"\nexiting t2";
    },10);
    t1.join();
    t2.join();
    cout<<"\n1"<<endl;
    return 0;

}