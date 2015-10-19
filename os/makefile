CC = g++
STD = -std=c++11
COMPILE = ${CC} -c ${STD}

all:pcss pcmm

pcmm:pro_cus_mm.cpp
	g++ -std=c++11 pro_cus_mm.cpp -o pcmm

pcss:pro_cus_ss.cpp
	g++ -std=c++11 pro_cus_ss.cpp -o pcss

.PHONY:clean

clean:
	test -f pcss && rm pcss
	test -f pcmm && rm pcmm
	rm *.o
