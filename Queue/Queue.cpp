#include "iostream"
#include "locale"
#include "conio.h"
using namespace std;
/**
@brief ����� �������
@detailed ����� �������� ����:
�������� ��������-element,��������� �� �������� ������� �������-next,
��������� �� ������-Begin � ���������-End �������� �������
*/
class Queue
{
int element;
Queue* next;
Queue* Begin;
Queue* End;
public:
Queue();
void add();;
int getBeginElement();
void del();
void print();
};
/**
@brief  ����������� ��� ����������
*/
Queue::Queue()
{   
	End=0;
	Begin=0;
}
/**
@brief ����� ���������� �������� � ����� ������� 
*/
void Queue::add()
{   
	Queue* tmp;
	tmp=(Queue*)malloc(1*sizeof(Queue));
	cout<<"������� ������� "<<"\n";
	cin>>tmp->element;
	if (!Begin)
	{   
		Begin=tmp;
		End=tmp;
		tmp->next=0;
	}
	else
	{
		End->next=tmp;
		End=tmp;
	    tmp->next=0;
	}
}


/**
@brief ����� ��������� �������� ������� �������� �������
*/
int Queue::getBeginElement()
{
   return Begin->element;
}

/**
@brief ����� �������� �������� �� ������ �������
*/
void Queue::del()
{
	Queue* tmp=Begin->next;
	free(Begin);
	Begin=tmp;
}
/**
@brief ����� ������ �������
*/
void Queue::print()
{
	if (!Begin) 
	{
		cout<<"������� �����";
		return;
	}
	for (Queue* tmp=Begin; tmp!=0;tmp=tmp->next)
	{
		cout<<tmp->element<<"\n";
	}
}
/**
@brief ������� main()
@detailed ����������� ������� Q �� n ���������
� ��������� �� �����.(n �������� � ����������)
*/
void main()
{
   setlocale(LC_ALL,"rus");
   Queue Q;
   int n;
   cout<<"������� ����� ��������� � �������";
   cin>>n;
   for (int i=0;i<n;i++)
   {
	   Q.add();
   }
   cout<<"\n�������� �������:\n";
   Q.print();
   getch();
}

