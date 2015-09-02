main:main.cpp binary_tree.cpp stoffer.cpp my_algorithm.cpp
	g++ -g main.cpp binary_tree.cpp stoffer.cpp my_algorithm.cpp -o main
clean:
	rm main.[io] main
install:
debug:
	g++ -g main.cpp binary_tree.cpp stoffer.cpp my_algorithm.cpp -o main

