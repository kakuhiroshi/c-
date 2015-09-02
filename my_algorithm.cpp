#include"my_algorithm.h"
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

template<class T>
void __test(T test_val, T true_val, const char* file, unsigned int line, int status){
	if(test_val != true_val)
		cout<< "[error: "<<file<<"("<<line<<"):"<<status<<"]"<<endl;
}

template<class ElementIterator, class Element>
int b_search(ElementIterator first, ElementIterator last, Element value){
	if(first == nullptr || last == nullptr || first >= last)	
		return -1;
	ElementIterator low, mid, high;
	low = first;
	high = last;
	while(low < high){
		mid = low +(high - low) / 2;
		if(*mid < value)
			low = mid + 1;
		else if(*mid == value)
			return (mid - first);
		else
			high = mid;
	}
	return -1;
}

void _test_binary_search(){
	int *arr = new int[10];	
	fill(arr, arr + 10, 10);
	__test(b_search(arr, arr + 10, 10), 5, __FILE__, __LINE__, 10);
	__test(b_search(arr, arr + 10, 5), -1, __FILE__, __LINE__, 5);
	__test(b_search(arr, arr + 10, 15), -1, __FILE__, __LINE__, 15);
	
	for(int i = 0; i < 10; i++){
		arr[i] = 10 * i;
	}
	for(int i = 0; i < 10; i++){
		__test(b_search(arr, arr + 10, 10 * i), i, __FILE__, __LINE__, i);
		__test(b_search(arr, arr + 10, 10 * i - 5), -1, __FILE__, __LINE__, i - 5);
	}	
	__test(b_search(arr, arr + 10, 10 * 10 - 5), -1, __FILE__, __LINE__, 10 * 10 - 5);
	__test(b_search(arr, arr + 10, 10 * 10), -1, __FILE__, __LINE__, 10 * 10);
	delete [] arr;
}
		
