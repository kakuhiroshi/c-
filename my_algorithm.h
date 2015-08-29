#ifndef MY_ALGORITHM_H
#define MY_ALGORITHM_H

template<class ElementIterator, class Element>
int b_search(ElementIterator first, ElementIterator last, Element value);

template<class T>
void __test(T test_val, T true_val, const char* file, unsigned int line);

void _test_binary_search();

#endif
