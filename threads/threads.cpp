#include<iostream>
#include<thread>
using namespace std;
using namespace std::chrono_literals;

bool finish = false;	

void Plus()
{
	while (!finish)
	{
		cout << "+ ";
		this_thread::sleep_for(1s);
	}
}
void Minus()
{
	while (!finish)
	{
		cout << "- ";
		this_thread::sleep_for(1s);
	}
}
void main()
{
	setlocale(LC_ALL, "");
	cout << "Hello Threads" << endl;
	std::thread plus_thread(Plus);
	std::thread minus_thread(Minus);
	cin.get();
	finish = true;

	if(plus_thread.joinable())plus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
	if(minus_thread.joinable())minus_thread.join();
}