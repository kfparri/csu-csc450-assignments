/*
* Program Name: csc450-module-07
* Author: 		Kyle Parrish
* Description:
* 	This program creates two threads, one of them counts up a variable to 20 and terminates,
* 	  the other waits until the counter is up to 20 and then starts counting it back
*/
#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>

using namespace std;

mutex mtx;
condition_variable conditionVar;
bool incrementingComplete = false;

void increment() {
	for(int i = 0; i <= 20; i++) {
		// slow down the execution just a little bit
		this_thread::sleep_for(chrono::milliseconds(500));

		// acquire a lock for counting
		// we are using lock_guard here because we are not waiting on
		//  any conditions to be set, we are simply locking the mutex
		//  to do work
		lock_guard<mutex> lock(mtx);

		cout << "Counting up: " << i << endl;
	}

	{
		// acquire a lock to change the shared variable
		lock_guard<mutex> lock(mtx);
		incrementingComplete = true;
	}

	// signal the other thread to start
	conditionVar.notify_one();
}

void decrement() {
	// get the mutex using unique_lock so we can pass it to our condition_variable
	unique_lock<mutex> lock(mtx);
	// wait for the bool to be set to true before starting work
	conditionVar.wait(lock, [] {return incrementingComplete;});

	for(int i = 20; i >= 0; i--){
		// slow down the execution just a little bit
		this_thread::sleep_for(chrono::milliseconds(500));
		cout << "Counting down: " << i << endl;
	}
}

int main() {
	thread countUpThread(increment);
	thread countDownThread(decrement);

	countUpThread.join();
	countDownThread.join();

	cout << "Job finished!" << endl;

	return 0;

}
