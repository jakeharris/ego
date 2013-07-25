CC = g++

test_queue: testqueue.cpp queue.cpp node.cpp
	$(CC) testqueue.cpp -o test_queue

clean:
	rm -Rf *.o test_*
