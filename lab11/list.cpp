#include "stdafx.h"
#include "iostream"
#include "List.h"
#include <fstream>
#include <iostream>
#include <cstringt.h>
#include <iomanip>


/////////////////////////////////////////////////////////
// Выводит на экран все элементы списка
void Petrovich::OutList(SItem *Head)
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");
	using namespace std;
	SItem *current;		// указатель на текущий элемент списка
	if(!Head)
	{
		cout << "Список пуст." << endl;
		return;
	}
	current = Head -> next ;	// указатель на текущий элемент
	// Выводим на экран элементы списка до тех пор,
	// пока указатель на следующий элемент не NULL.
	while (current->next)
	{
		// Вывод содержимого текущего элемента списка
		cout <<setw(3)<< current->Id ;
		cout <<setw(13)<<current->Surname ;
		cout <<setw(13)<<current->Name ;
		cout <<setw(13)<<current->Otche ;
		cout <<setw(13)<< current->Number ;
		cout << endl;
		// Переходим к следующему элементу списка.
		current = current->next;
	}
	// Вывод содержимого последнего элемента списка
	// указатель которого на следующий элемент есть NULL.
	cout <<setw(3)<< current->Id << setw(10)<< current->Surname ;
	cout <<setw(10) << current ->Name	<< setw(10) ;
	cout << current -> Otche  <<setw(13)<< current-> Number  << endl;
}

//////////////////////////////////////////////////////////////
// Добавляет элемент в конец списка
void Petrovich::AddItem(SItem *Head, SItem *NewItem, SItem **Teil)
{
	SetConsoleCP (1251);       // Для перекодировки ввода
	SetConsoleOutputCP(1251);  // Для перекодировки вывода
	NewItem->next = NULL;
	(*Teil)->next = NewItem;
	*Teil = NewItem;
}
//////////////////////////////////////////////////////////////
// Находит элемент списка с идентификатором ID. Возвращает 
// адрес найденного элемента или NULL, если элемент не найден.
SItem *Petrovich::GetItem(SItem *Head, int Id)
{
	SItem *current = Head;
	SItem *previous;
	if(!current->next)
		return NULL;	// список пуст
	// Просматриваем весь список
	while (current->next)
	{
		previous = current;
		current = current->next;
		if(current->Id == Id)
			return current;
	}
	return NULL;	// элемент не найден
}



