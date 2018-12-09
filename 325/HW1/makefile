all : insertsort insertTime insertTimeWorst insertTimeBest mergesort mergeTime mergeTimeWorst mergeTimeBest

insertsort : insertsort.o
	g++ -g -std=c++0x insertsort.o -o insertsort

insertTime : insertTime.o
	g++ -g -std=c++0x insertTime.o -o insertTime

insertTimeWorst : insertTimeWorst.o
	g++ -g -std=c++0x insertTimeWorst.o -o insertTimeWorst

insertTimeBest : insertTimeBest.o
	g++ -g -std=c++0x insertTimeBest.o -o insertTimeBest

mergesort : mergesort.o
	g++ -g -std=c++0x mergesort.o -o mergesort

mergeTime : mergeTime.o
	g++ -g -std=c++0x mergeTime.o -o mergeTime

mergeTimeWorst : mergeTimeWorst.o
	g++ -g -std=c++0x mergeTimeWorst.o -o mergeTimeWorst

mergeTimeBest : mergeTimeBest.o
	g++ -g -std=c++0x mergeTimeBest.o -o mergeTimeBest

insertsort.o: insertsort.cpp
	g++ -c -g -std=c++0x insertsort.cpp

insertTime.o: insertTime.cpp
	g++ -c -g -std=c++0x insertTime.cpp

insertTimeWorst.o: insertTimeWorst.cpp
	g++ -c -g -std=c++0x insertTimeWorst.cpp

insertTimeBest.o: insertTimeBest.cpp
	g++ -c -g -std=c++0x insertTimeBest.cpp

mergesort.o: mergesort.cpp
	g++ -c -g -std=c++0x mergesort.cpp

mergeTime.o: mergeTime.cpp
	g++ -c -g -std=c++0x mergeTime.cpp

mergeTimeWorst.o: mergeTimeWorst.cpp
	g++ -c -g -std=c++0x mergeTimeWorst.cpp

mergeTimeBest.o: mergeTimeBest.cpp
	g++ -c -g -std=c++0x mergeTimeBest.cpp

.PHONY : clean memCheckInsertSort memCheckInsertTime memCheckInsertTimeWorst memCheckInsertTimeBest memCheckMergeSort memCheckMergeTime memCheckMergeTimeWorst memCheckMergeTimeBest

memCheckInsertSort:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes insertsort

memCheckInsertTime:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes insertTime

memCheckInsertTimeWorst:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes insertTimeWorst

memCheckInsertTimeBest:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes insertTimeBest

memCheckMergeSort:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes mergesort

memCheckMergeTime:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes mergeTime

memCheckMergeTimeWorst:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes mergeTimeWorst

memCheckMergeTimeBest:
	valgrind --tool=memcheck --leak_check=yes --show-reachable=yes --track-fds=yes mergeTimeBest

clean:
	-rm *.o
	-rm insertsort
	-rm insertTime
	-rm insertTimeWorst
	-rm insertTimeBest
	-rm mergesort
	-rm mergeTime
	-rm mergeTimeWorst
	-rm mergeTimeBest