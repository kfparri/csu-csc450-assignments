package csc450.module08;

/**
 * This program uses two threads, one to count up to 20 and
 *  a second one to count down from 20 using locks and conditions
 * 
 * @author		Kyle Parrish
 * @version		1.0.0
 */

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ThreadConcurrency {
	// define the lock, condition and flag to signal when the first thread is complete
	private static final Lock lock = new ReentrantLock();
	private static final Condition incrementCompleteCondition = lock.newCondition();
	private static boolean incrementComplete = false;
		
	/**
	 * Increment a number from 0 to 20.  Once complete send a signal
	 *   to the second thread to start counting down
	 */
	private static void increment() {
		for(int i = 0; i <= 20; i++) {
			try {
				// slow the program down a little
				Thread.sleep(500);
				
				lock.lock();
				System.out.println("Counting up: " + i);
			} catch (InterruptedException e) {
				Thread.currentThread().interrupt();
			} finally {
				lock.unlock();
			}
		}
		
		lock.lock();
		try {
			incrementComplete = true;
			incrementCompleteCondition.signal();
		} finally {
			lock.unlock();
		}
	}
	
	/**
	 * Wait until the signal has been given to start counting, then start 
	 *   counting down to 0
	 */
	private static void decrement() {
		lock.lock();
		try {
			while(!incrementComplete) {
				incrementCompleteCondition.await();
			}
		} catch (InterruptedException e) {
			Thread.currentThread().interrupt();
		} finally {
			lock.unlock();
		}
		
		for(int i = 20; i >= 0; i--) {
			try {
				Thread.sleep(500);
				System.out.println("Counting down: " + i);
			} catch(InterruptedException e) {
				Thread.currentThread().interrupt();
			}
		}
	}
	
	/**
	 * Main function to create two threads and start them
	 * @param args
	 */
	public static void main(String[] args) {
		Thread countUpThread = new Thread(() -> increment());
		Thread countDownThread = new Thread(() -> decrement());
		
		countUpThread.start();
		countDownThread.start();

		System.out.println("Program finished!");
	}
}
