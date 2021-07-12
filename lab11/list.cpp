#include "stdafx.h"
#include "iostream"
#include "List.h"
#include <fstream>
#include <iostream>
#include <cstringt.h>
#include <iomanip>


/////////////////////////////////////////////////////////
// ������� �� ����� ��� �������� ������
void Petrovich::OutList(SItem *Head)
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");
	using namespace std;
	SItem *current;		// ��������� �� ������� ������� ������
	if(!Head)
	{
		cout << "������ ����." << endl;
		return;
	}
	current = Head -> next ;	// ��������� �� ������� �������
	// ������� �� ����� �������� ������ �� ��� ���,
	// ���� ��������� �� ��������� ������� �� NULL.
	while (current->next)
	{
		// ����� ����������� �������� �������� ������
		cout <<setw(3)<< current->Id ;
		cout <<setw(13)<<current->Surname ;
		cout <<setw(13)<<current->Name ;
		cout <<setw(13)<<current->Otche ;
		cout <<setw(13)<< current->Number ;
		cout << endl;
		// ��������� � ���������� �������� ������.
		current = current->next;
	}
	// ����� ����������� ���������� �������� ������
	// ��������� �������� �� ��������� ������� ���� NULL.
	cout <<setw(3)<< current->Id << setw(10)<< current->Surname ;
	cout <<setw(10) << current ->Name	<< setw(10) ;
	cout << current -> Otche  <<setw(13)<< current-> Number  << endl;
}

//////////////////////////////////////////////////////////////
// ��������� ������� � ����� ������
void Petrovich::AddItem(SItem *Head, SItem *NewItem, SItem **Teil)
{
	SetConsoleCP (1251);       // ��� ������������� �����
	SetConsoleOutputCP(1251);  // ��� ������������� ������
	NewItem->next = NULL;
	(*Teil)->next = NewItem;
	*Teil = NewItem;
}
//////////////////////////////////////////////////////////////
// ������� ������� ������ � ��������������� ID. ����������
// ����� ���������� �������� ��� NULL, ���� ������� �� ������.
 SItem *Petrovich::DeleteItem(SItem *Head, int Id, SItem **Teil)
 {
	bool bFlagFind = false;
	SItem *current = Head;
	SItem *previous;
	if(!current->next)
		return NULL; // ������� ������ (������ ����)
	// ������������� ���� ������
	while (current->next)
	{
		previous = current;
		current = current->next;
		if(current->Id == Id)
		{
			if(!current->next) // ��� ����� ������ (��������� ������� - ��������� � ������)
			{
				previous->next = NULL;
				*Teil = previous;
				return current;
			}
			else
			{
				previous->next = current->next;
				return current;
			}
			break;
		}
	}
	return NULL; // ������� �� ������
 }
//////////////////////////////////////////////////////////////
// ������� ������� ������ � ��������������� ID. ���������� 
// ����� ���������� �������� ��� NULL, ���� ������� �� ������.
SItem *Petrovich::GetItem(SItem *Head, int Id)
{
	SItem *current = Head;
	SItem *previous;
	if(!current->next)
		return NULL;	// ������ ����
	// ������������� ���� ������
	while (current->next)
	{
		previous = current;
		current = current->next;
		if(current->Id == Id)
			return current;
	}
	return NULL;	// ������� �� ������
}
//////////////////////////////////////////////////////////////
// ������ �������� ��������� ������
void Petrovich::DeleteAllItem(SItem **Head, SItem **Teil)
{
	SItem *current = *Head;
	if( !current->next)
		return; // (������ ����)
	while ((*Head)->next)
	{
		*Head = current->next;
		delete current;
		current = *Head;
	}
	delete *Head;
	*Head = NULL;
	*Teil = NULL;
}



