// lab11.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include "iostream"
#include "conio.h"
#include "List.h"
#include <fstream>
#include <iostream>
#include <cstringt.h>
#include <iomanip>

using namespace std;
using namespace Petrovich;

// �������� ����
enum menu {EXIT, NEW_ELEM, PRINT_ELEM, PRINT_ALL, SAVE_FILE,END, DELETE_ELEM, DELETE_ALL,  READ_FILE};

int Menu ();
void _tmain ()
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");

	SItem *Head = NULL;		// ��������� �� ������ ������ (������)
	SItem *Teil;			// ��������� �� ����� ������ (�����)
	int *Id;				// ��������� �� ���������� ����� ��������
	SItem *Buff;			// �����
	SItem *NewItem;			// ����� ������� ������
	int CmdMenu;			// ������� ����
	int i;					// �������
	char NameFileTxt[100] ; // ��� ���������� ����� ������ � ������
	
	OutList(Head); //����� ������

	// �������� ��������� �������� ������
	Head    = new SItem;
	Head->Id   = 0;
	Head->next = NULL;
	Teil = Head;

	//������� ������ file ��� ������ � ��������� ����
	ofstream file;
	//������� ������ Writefile ��� ������ � ��������� ����
	ofstream write_file;
	
	// ��� ������ ����
	for (;;)
	{
	CmdMenu = Menu (); 
	switch (CmdMenu)
	{
		// �����
		case EXIT:
			return;
			break;
		// ��������� ����� �������
		case NEW_ELEM:
			NewItem = new SItem;
			cout << "������� ����� >> ";
			cin >> NewItem -> Id ;
			AddItem(Head, NewItem, &Teil);
			cout << endl;
			cout << "������� ������� >>";
			cin >> NewItem -> Surname ;
			cout << endl;
			cout << "������� ��� >> ";
			cin >> NewItem -> Name ;
			cout << endl;
			cout << "������� �������� >> ";
			cin >> NewItem -> Otche ;
			cout << endl;
			cout << "������� ����� �������� >> ";
			cin >> NewItem -> Number;
			cout << endl;
		break;
		// ������� ��� ��������	
		case PRINT_ALL:
			OutList(Head);
		break;
		// ������� ��������� �������
		case PRINT_ELEM:
			Id = new int;
			cout << "����� �������� >> ";
			cin >> *Id;
			Buff = GetItem(Head, *Id);
			if(Buff)
			{
			cout << "������ ������� Id = " << setw(2) << Buff->Id;
			cout << setw(13) << Buff->Surname << setw(13) << Buff->Name;
			cout << setw(13) << Buff->Otche << setw(13)<< Buff ->Number << endl;
			}
			else
				cout << "������� �� ������." << endl;
		break;
			// ��������� ������ � ��������� ����
		case SAVE_FILE:
			cout << "������� ���� . txt ��� �������� ������ >> ";
			cin >> NameFileTxt;              // �������� ���������� �����
			// ��������� ���� � ��������� �� ������
			file.open(NameFileTxt, ios::app);
				if (!file.is_open())
				{
					cout<<"������ �������� ����� \""<<NameFileTxt;
					cout<<"\""<<endl;
					cout<<"��������� ������ ���������."<<endl;
					system("pause");
					return;
				}
			SItem *current;		// ��������� �� ������� ������� ������
			if(!Head)
			{
				cout << "������ ����." << endl;
				return;
			}
			current = Head -> next ; // ��������� �� ������� �������
			// ���������� � ���� �������� ������ �� ��� ���,
			// ���� ��������� �� ��������� ������� �� NULL.
			while (current->next)
			{
				// ������ ����������� �������� �������� ������
				file << current->Id << "\\\\";
				file << current->Surname << "////" ;
				file << current->Name << "////" ;
				file << current->Otche << "////" ;
				file << current->Number << "////" ;
				file << endl;
				// ��������� � ���������� �������� ������.
				current = current->next;	
			}
			// ������ ����������� ���������� �������� ������
			// ��������� �������� �� ��������� ������� ���� NULL.
			file << current->Id<< "\\\\" << current->Surname<< "////";
			file << current->Name<< "////"<< current->Otche<< "////" <<current-> Number << "////";
			file << endl;
			file.close();
		break;
  	 }
   }
}
// ������� ����
	int Menu ()
	{
		int CmdMenu;
		 using namespace std;

		 cout << "����: " << endl;
		 for (;;)
		 {
			 cout << EXIT << " - �����" << endl;
			 cout << NEW_ELEM << " - ����� ������� " << endl;
			 cout << PRINT_ELEM << " - ������� �� ����� �������..." << endl;
			 cout << PRINT_ALL << " - ������� ���� ������ �� �����" << endl;
			 cout << SAVE_FILE << " - ��������� � �����..." << endl;
			 cout << "����� ������� ���� >> " ;
			 cin >> CmdMenu;
			 if (CmdMenu <0 || CmdMenu >= END)
			 {
				 cout << " ������ - ����� ������� ���." << endl;
				 continue;
			 }
			 else
				 return CmdMenu;
		 }

		 return CmdMenu;
	}
