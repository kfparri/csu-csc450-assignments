package csc450.module08;

import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

public class ThreadConcurrency {
	private static final Lock lock = new ReentrantLock();
	private static final Condition incrementCompleteCondition = lock.newCondition();
	private static boolean incrementComplete = false;
	
	public static void main(String[] args) {
		Thread countUpThread = new Thread(() -> increment());
		Thread countDownThread = new Thread(() -> decrement());
		
		countUpThread.start();
		countDownThread.start();

		System.out.println("Program finished!");
	}

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
}
