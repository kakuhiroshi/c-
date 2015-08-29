#include"my_algorithm.h"
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

template<class T>
void __test(T test_val, T true_val, const char* file, unsigned int line){
	if(test_val != true_val)
		cout<< "[error: "<<file<<"("<<line<<")]"<<endl;
}

template<class ElementIterator, class Element>
int b_search(ElementIterator first, ElementIterator last, Element value){
	if(first == nullptr || last == nullptr || first >= last)	
		return -1;
	ElementIterator mid;
	while(first < last){
		mid = first +(last - first) / 2;
		if(*mid < value)
			first = mid + 1;
		else if(*mid == value)
			return (mid - first);
		else
			last = mid;
	}
	return -1;
}

void _test_binary_search(){
	int *arr = new int[10];	
	fill(arr, arr + 10, 10);
	__test(b_search(arr, arr + 10, 10), 5, __FILE__, __LINE__);
	__test(b_search(arr, arr + 10, 5), -1, __FILE__, __LINE__);
	__test(b_search(arr, arr + 10, 15), -1, __FILE__, __LINE__);
}



