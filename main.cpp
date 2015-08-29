#include<iostream>
#include"binary_tree.h"
#include"stoffer.h"
#include"my_algorithm.h"

using namespace std;

void help(){
	cout<<"help doc here."<<endl;
}

void _test29(){
	int arr[] = {1,2,3,4,5,1,1,1,1,1,1};
	int val = 0;
	if(morethanhalf(arr, arr+sizeof(arr)/sizeof(int), val))
		cout<<"\t<val occurs more than half times: [val = " <<val<<"]>"<<endl;
	else
		cout<<"\tno val occurs more than half times."<<endl;
}

void _test(int pno){
	cout<<"_test:\t<problem "<<pno<<" run test. ***start***>"<<endl;
	switch(pno){
		case -1: _test_binary_search(); break;
		case 29: _test29(); break;
		default:cout<<"no _test"<<pno<<"()"<<endl; break;
	}
	cout<<"_test:\t<problem "<<pno<<" run test. ***end***>"<<endl;
}

int main(int argc, char **args){

	for(int i = 0; i < argc; i++){
		if(args[i][0]=='-'){
			switch(args[i][1]){
				case 'p':{
					i++;
					_test(atoi(args[i]));
					break;
				}
				case 'h':
					help();
					return 0;
				default:
					help();
					return 0;
			}
		}	
	}

	return 1;
}

