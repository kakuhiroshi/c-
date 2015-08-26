#include "stoffer.h"
#include<algorithm>
#include<iostream>

using namespace std;

void disp(char *str){
	while(*str != '\0'){
		cout<<(*str);
		str++;
	}
	cout<<endl;
}

void permutation(char *p){
	if(p == NULL){
		return;
	}
	permutation(p,p);
}

void permutation(char *str, char *first){
	if(*first == '\0'){
		disp(str);
	}else{
		for(char *p = first; *p != '\0'; p++){
			swap(*p, *first);
			permutation(str, first + 1);
			swap(*p, *first);
		}
	}
}

bool check(int *first, int *last, int val){
	int times = 0;
	while(first < last){
		if(*first == val)
			times++;
		first++;
	}
	return times > ((last - first) >> 1);
}

bool morethanhalf(int *first, int *last, int& val){
	bool isexsit = false;
	if(first == NULL || last == NULL || first >= last)
		return isexsit;
	int *cur = first;
	val = *cur;
	int times = 1;
	cur++;
	while(cur < last){
		if(*cur == val)
			times++;
		else{
			if(times > 1)
				times--;
			else
				val = *cur;
		}
		cur++;
	}
	isexsit = check(first, last, val);
	return isexsit;
}
