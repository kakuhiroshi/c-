#include<condition_variable>
#include<thread>
#include<mutex>
#include<iostream>
#include<string>
#include<chrono>
#include<iomanip>
using namespace std;

const int capcity = 10;
int stock[capcity];
int put_pos = 0;
int get_pos = 0;
int cur_size = 0;

mutex mtx;
condition_variable not_full;
condition_variable not_empty;

void line(int ntap){
    for(int i=0;i<ntap; i++)
        cout<<"--------";
    cout<<"-"<<endl;
}

void status(){
    line(capcity);
    for(int i=0;i<capcity;i++)
        cout<<"|"<<setw(7)<<right<<stock[i];
    cout<<"|"<<endl;
    line(capcity);
}

void produce(int i){
	unique_lock<mutex> lck(mtx);
	while(cur_size == capcity)
		not_full.wait(lck);
	stock[put_pos] = i;
	put_pos = (put_pos + 1) % capcity;
	cur_size++;
    cout<<"produce: "<<i<<"\tcursize:"<<cur_size<<"\tput_pos:"<<put_pos<<"\tget_pos:"<<get_pos<<endl;
    status();
	not_empty.notify_all();
}

int consume(){
	unique_lock<mutex> lck(mtx);
	while(cur_size == 0)
		not_empty.wait(lck);
	int val = stock[get_pos];
	stock[get_pos] = 0;
	get_pos = (get_pos + 1) % capcity;
	cur_size--;
    cout<<"consume..."<<"\tcursize: "<<cur_size<<"\tput_pos:"<<put_pos<<"\tget_pos:"<<get_pos<<endl;
    status();
	not_full.notify_all();
	return val;
}



int task_amounts = 1000;
void producer(){
	for(int i=0;i<task_amounts;i++){
		produce(i+1);
	}
}

void consumer(){
    int cnt = 0;
    while(cnt<task_amounts){
        consume();
        this_thread::sleep_for(chrono::duration<int,ratio<1,1000>>(10));
        cnt++;
    }
}

int main(){
	thread t1(producer);
	thread t2(consumer);
	t1.join();
	t2.join();
	return 1;
}
		
