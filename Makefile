all: testSorts.o bubbleSort.o utility.o
		g++ testSorts.o bubbleSort.o utility.o -o sorts
testSorts.o: testSorts.cpp
		@g++ -c testSorts.cpp
bubbleSort.o: bubbleSort.cpp bubbleSort.h
		@g++ -c bubbleSort.cpp
utility.o: utility.cpp utility.h
		@g++ -c utility.cpp
