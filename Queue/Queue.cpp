#include "iostream"
#include "locale"
#include "conio.h"
using namespace std;
/**
@brief Класс очередь
@detailed Класс содержит поля:
значения элемента-element,указатель на следющий элемент очереди-next,
указатель на первый-Begin и последний-End элементы очереди
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
@brief  конструктор без параметров
*/
Queue::Queue()
{   
	End=0;
	Begin=0;
}
/**
@brief метод добавления элемента в конец очереди 
*/
void Queue::add()
{   
	Queue* tmp;
	tmp=(Queue*)malloc(1*sizeof(Queue));
	cout<<"введите элемент "<<"\n";
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
@brief метод получения значения первого элемента очереди
*/
int Queue::getBeginElement()
{
   return Begin->element;
}

/**
@brief метод удаления элемента из начала очереди
*/
void Queue::del()
{
	Queue* tmp=Begin->next;
	free(Begin);
	Begin=tmp;
}
/**
@brief метод печати очереди
*/
void Queue::print()
{
	if (!Begin) 
	{
		cout<<"Очередь пуста";
		return;
	}
	for (Queue* tmp=Begin; tmp!=0;tmp=tmp->next)
	{
		cout<<tmp->element<<"\n";
	}
}
/**
@brief Функция main()
@detailed Формируется очередь Q из n элементов
и выводится на экран.(n вводится с клавиатуры)
*/
void main()
{
   setlocale(LC_ALL,"rus");
   Queue Q;
   int n;
   cout<<"Введите число элементов в очереди";
   cin>>n;
   for (int i=0;i<n;i++)
   {
	   Q.add();
   }
   cout<<"\nЭлементы очереди:\n";
   Q.print();
   getch();
}

