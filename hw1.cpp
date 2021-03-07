
#include <iostream>
#include <string>
#include <pthread.h>
#include <stdlib.h>
using namespace std;
int random(int &v2,int &v1)
{
	v1 = rand() % 50;
	v2 = rand() % 2;
	
}
int seats[2][50];
int turn=1;
int capacity=0;
void* threadfunc1(void*)
{
	while(capacity<100)
	{
		if (turn == 1)
		{
			
			int b = rand() % 50;
			int a = rand() % 2;

			if (seats[a][b] == 0)
			{
				cout << "Agency 1 Entered Critical Region"<<endl;
				seats[a][b] = 1;
				if (a == 0)
				{
					cout << "Seat number " << b + 1 << "reserved by Agency 1" << endl;
				}
				else
				{
					cout << "Seat number " << b + 51 << "reserved by Agency 1" << endl;

				}
				capacity++;
				cout << "Agency 1 exit Critical Region" << endl;
				turn=0;

			}
			turn = 0;

		}
		

	}
	

}
void* threadfunc2(void*)
{
	while(capacity<100)
	{
		if (turn == 0)
		{
			
			int b = rand() % 50;
			int a = rand() % 2;
			if (seats[a][b] == 0)
			{
				cout << "Agency 2 Entered Critical Region" << endl;
				seats[a][b] = 2;
				if (a == 0)
				{
					cout << "Seat number " << b + 1 << "reserved by Agency 2" << endl;
				}
				else
				{
					cout << "Seat number " << b + 51 << "reserved by Agency 2" << endl;

				}
				capacity++;
				cout << "Agency 2 exit Critical Region" << endl;
				turn = 1;

			}
			turn = 1;

		}
		
	}
	


}
int main()
{
	srand(time(NULL));
	cout<<"welcome to plane"<<endl;
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 50;j++)
		{
				seats[i][j] = 0;
		}
	}
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, threadfunc1, NULL);
	pthread_create(&thread2, NULL, threadfunc2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	cout << "no places left" << endl;
	for (int i = 0;i < 2;i++)
	{
		cout << endl;
		for (int j = 0;j < 50;j++)
		{
				cout << seats[i][j];
				
		}
	}

	return 0;
}