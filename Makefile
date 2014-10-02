all: testSorts.o bubbleSort.o selectionSort.o utility.o
		g++ testSorts.o bubbleSort.o selectionSort.o utility.o -o sorts
testSorts.o: testSorts.cpp
		@g++ -c testSorts.cpp
bubbleSort.o: bubbleSort.cpp bubbleSort.h
		@g++ -c bubbleSort.cpp
selectionSort.o: selectionSort.cpp selectionSort.h
		@g++ -c selectionSort.cpp
utility.o: utility.cpp utility.h
		@g++ -c utility.cpp

clean:
		@rm -f *.o sorts
