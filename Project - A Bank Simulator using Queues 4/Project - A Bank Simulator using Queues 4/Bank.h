#pragma once
#include<iomanip>
#include<Windows.h>	
clock_t start, end; // to know the daliy after using time() 
typedef unsigned short ushort;

unsigned short sec = 0;
using std::cout;
using std::cin;
class Bank
{
	ushort tellers;
	ushort  coust;
	short counter_cout;
	short counter_tellers;
	ushort* arrival = NULL;
	ushort* service = NULL;
	ushort* leave = NULL;
	ushort* wait = NULL;

	int num = 0;
	bool if_needsort = 0;
	Queue Waitting;
	// the main function in system that shoud run after take info about coustomer from use
	void timer();
	// to refrsh the screen to make it like dynmical screen
	void gotoxy() const;
	// to display the bank coustomer finel result 
	void display() const ;
	void check();
	void sort_time();
	int Bigleave();
public:
	Bank(ushort tell, ushort cou);
	// take info about customer 
	void Enter_coust();
	// to make it sort 
	~Bank();
};
Bank::Bank(ushort tell, ushort cou)
{
	tellers = tell;
	this->coust = cou;
	this->counter_cout = cou;
	this->counter_tellers = tell;
	arrival = new ushort[cou];
	service = new ushort[cou];
	leave = new ushort[cou];
	wait = new ushort[cou];

}
Bank::~Bank()
{

	delete[] arrival;
	delete[] service;
	delete[] leave;
	delete[] wait;

}
inline void Bank::Enter_coust()
{

	int i = 0;
	for (i; i < counter_cout; i++)
	{
		if (counter_tellers == 0)
			break;
		cout << "\t\tcustomer " << i + 1 << ":\n";
		cout << "Arrival Time : ";
		cin >> arrival[i];
		cout << "service Time  : ";
		cin >> service[i];
		leave[i] = arrival[i] + service[i];
		wait[i] = 0;

		counter_tellers--;

	}
	num = i;
	
	while (i < counter_cout) {
		Waitting.Add(i);
		cout << "\t\tcustomerx " << i + 1 << ":\n";
		cout << "Arrival Time : ";
		cin >> arrival[i];
		cout << "service Time  : ";
		cin >> service[i];
		leave[i] = arrival[i] + service[i];
		wait[i] = 0;
		i++;
	}
	while (num != coust) {
		for (int x = 0; x < num; x++)
		{
			if (leave[x] < arrival[num] && !Waitting.ISempty()) {
				Waitting.pop_front();
			}

		}
		num++;
	}
	check();
	if (if_needsort)
	{
		char ch;
		cout << "\t \nsome thing wrong in arrive time of coustomer\n "
			<< "Do you went re-store the app or \" or try solve the problem by change the coustomer arrvial order ?\" "
			<< "\n press'y' for first option or any key for second option ?\n ";
		cin >> ch;
		if (ch == 'y')
		{
			system("cls");
			num = 0;
			counter_cout = coust;
			counter_tellers = tellers;
			if_needsort = 0;
			for (int i = 0; i < coust; i++)
			{
				arrival[i]=0;
				wait[i] = 0;
				leave[i] = 0;
				service[i] = 0;

			}
			while (!Waitting.ISempty())
			{
				Waitting.pop_front();
			}
			Enter_coust();
		}
		else sort_time();
	}
	start = clock();
	timer();
	end = clock();
	display();

}
inline void Bank::timer()
{
	int bigLV = Bigleave();
	while (true) {
		if (this->counter_cout == 0)
			break;
		if (sec == bigLV)
			break;
		gotoxy();
		Sleep(1000);
		sec++;
		for (int i = 0; i < num + 1; i++)
		{
			if (sec == arrival[i] && wait[i] == 0)
				cout << "coustomer " << i + 1 << "  is arrivel in " << sec << "\n";
			if (sec == leave[i]) {
				cout << "coustomer " << i + 1 << "  is leave in " << sec << "\n";
				counter_tellers++;
				this->counter_cout--;
				if (!Waitting.ISempty()) {
					int number = Waitting.front_();
					Waitting.pop_front();
					cout << "coustoum " << number + 1 << " is go to window" << i + 1 << "\n";
					wait[number] = leave[i] - arrival[number];
					arrival[number] = sec;
					leave[number] = arrival[number] + service[number];
					num++;
				}
			}

		}
	}
}
inline void Bank::gotoxy() const
{
	cout << "timer:" << sec << "\r";

}
inline void Bank::display() const
{
	cout << std::setfill('*') << std::left << std::setw(50) << "\t\t\t      ";
	for (int w = 0; w < coust; w++)
	{
		cout << std::setfill(' ') << std::setw(20) << "\n\t\t wait : " << wait[w] << " waitandservice : "
			<< service[w] + wait[w] << std::endl;

	}
}
inline void Bank::check()
{
	for (int i = 0; i < coust - 1; i++)
	{
		if (arrival[i] > arrival[i + 1]) {
			if_needsort = 1;
			break;
		}
	}
}
inline void Bank::sort_time()
{
	int co = coust;
	while (co--)
	{


		for (int i = 0; i < coust - 1; i++)
		{
			if (arrival[i] >= arrival[i + 1])
			{
				int temp = arrival[i];
				arrival[i] = arrival[i + 1];
				arrival[i + 1] = temp;
				temp = service[i];
				service[i] = service[i + 1];
				service[i + 1] = temp;
			}

		}

		for (int i = 0; i < coust ; i++)
		{
			leave[i] = service[i] + arrival[i];


		}
	}
	if_needsort = 0;



}
inline int Bank::Bigleave()
{
	// i put this function if happen any Error in the time function to break loop  
	int count = arrival[0];
	for (int i = 0; i < coust; i++)
	{
		count +=service[i];
	}
	return count;
}