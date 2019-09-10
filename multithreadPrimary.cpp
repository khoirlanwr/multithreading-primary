// Compile using g++ multithreadPrimary.cpp -std=c++11 -pthread
#include <iostream> 
#include <thread> 

using namespace std; 


#define PRIME 		1
#define NOT_PRIME 	2


void print(int *array_data, int MAX_NUM)
{	
	for(int i=0; i<MAX_NUM; i++) 
		if (array_data[i] != 0)
			cout << array_data[i] << " ";

	cout << endl;
}


void threadFunction(int _start, int __MAX_NUM, int* array_data) 
{ 
	int i=_start, j, flag;
		
	while(i < __MAX_NUM) 
	{
		flag = PRIME;
		
		if (i < 2) 
			printf(" %d is Not prime number\n", i);

		else 
		{
			for(j=2; j <= i/2; j++) 
			{
				if (i % j == 0)
				{
					printf(" %d is Not prime number\n", i);
					flag = NOT_PRIME;
					break;		
				}
			}

			if (flag == PRIME) {
				printf(" %d is Prime number\n", i);
				array_data[i] = i;
			}

		}

		i += 3;
	}
}

int main() 
{ 
	int MAX_NUM;

	cout << "MAX_NUM: ";
	cin >> MAX_NUM;

	int *array_data = new int[MAX_NUM]();


	thread th1(threadFunction, 0, MAX_NUM, array_data); 
	thread th2(threadFunction, 1, MAX_NUM, array_data);
	thread th3(threadFunction, 2, MAX_NUM, array_data);



	// Wait for the threads to finish 
	th1.join(); 
	th2.join();
	th3.join();

	print(array_data, MAX_NUM);

	return 0; 
} 
// join functions
// it blocks the current thread until the execution of the thread is completed on which join() is called.
// If you do not specify join() or dettach() on the thread then it will result in runtime error as the main/current thread will complete its execution and the other thread created will be still running.
