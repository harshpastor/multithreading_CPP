//mutex is used to avoid race condition
// mutex are like doors that only let restricted entries based on current entries 
//Defn: mutex is a sychronised primitive that protects shared data from simultaneous access by multiple threads

#include <bits/stdc++.h>
// #include<mutex>
using namespace std;
using namespace std::chrono;
int x = 0;
std:: mutex m;
void func(){
    m.lock();
    x+=2;
    cout<<x<<endl;
    m.unlock();
    return;
}
void func2(){
    m.lock();
    x--;
    cout<<x<<' ';

    m.unlock();
    return;
}



int main()
{
    // for(int i = 0;i<100000;i++){
    thread t2= thread(func);
    thread t1= thread(func);
    t2.join();
    t1.join();
    // }
    cout<<x;    
    return 0;
}