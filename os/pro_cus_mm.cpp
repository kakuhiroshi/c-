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

mutex producer_mtx;
mutex consumer_mtx;
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
    cout<<endl;
}

void produce(int i, int id){
	unique_lock<mutex> lck(mtx);
	while(cur_size == capcity)
		not_full.wait(lck);
	stock[put_pos] = i;
	put_pos = (put_pos + 1) % capcity;
	cur_size++;
    cout<<"[producer: "<<id<<"] produce: "<<i<<"\tcursize:";
    cout<<cur_size<<"\tput_pos:"<<put_pos<<"\tget_pos:"<<get_pos<<endl;
    status();
	not_empty.notify_all();
}

int consume(int i, int id){
	unique_lock<mutex> lck(mtx);
	while(cur_size == 0)
		not_empty.wait(lck);
	int val = stock[get_pos];
	stock[get_pos] = 0;
	get_pos = (get_pos + 1) % capcity;
	cur_size--;
    cout<<"[consumer: "<<id<<"] consume: "<<i<<"\tcursize: ";
    cout<<cur_size<<"\tput_pos:"<<put_pos<<"\tget_pos:"<<get_pos<<endl;
    status();
	not_full.notify_all();
	return val;
}



int task_amounts = 100;
int pro_cnt = 0;
int con_cnt = 0;

void producer(int i){
    while(true){
		producer_mtx.lock();
		if(pro_cnt < task_amounts){
            //this_thread::sleep_for(chrono::seconds(10));
			produce(pro_cnt + 1,i);
			pro_cnt++;
		}
        else{
            mtx.lock();
            cout<<"< Producer "<<i<<" is exiting... >"<<endl;
            mtx.unlock();
            producer_mtx.unlock();
            break;
        }
		producer_mtx.unlock();
	}
}

void consumer(int i){
    while(true){
        consumer_mtx.lock();
        if(con_cnt < task_amounts){
            //this_thread::sleep_for(chrono::seconds(20));
            consume(con_cnt + 1,i);
            con_cnt++;
        }
        else{
            mtx.lock();
            cout<<"< Consumer "<<i<<" is exiting... >"<<endl;
            mtx.unlock();
            consumer_mtx.unlock();
            break;
        }
        consumer_mtx.unlock();
    }
}

int main(){
	thread p1(producer,1);
	thread p2(producer,2);
    thread p3(producer,3);
    thread p4(producer,4);

	thread c1(consumer,1);
    thread c2(consumer,2);
	
	p1.join();
	p2.join();
    p3.join();
    p4.join();
    
	c1.join();
    c2.join();
    return 1;
}
		
