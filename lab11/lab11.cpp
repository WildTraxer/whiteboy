// lab11.cpp: определяет точку входа для консольного приложения.
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

// элементы меню
enum menu {EXIT, NEW_ELEM, PRINT_ELEM, PRINT_ALL, SAVE_FILE,END, DELETE_ELEM, DELETE_ALL,  READ_FILE};

int Menu ();
void _tmain ()
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");

	SItem *Head = NULL;		// указатель на начало списка (голова)
	SItem *Teil;			// указатель на конец списка (хвост)
	int *Id;				// указатель на порядковый номер студента
	SItem *Buff;			// буфер
	SItem *NewItem;			// новый элемент списка
	int CmdMenu;			// команды меню
	int i;					// счетчик
	char NameFileTxt[100] ; // для текстового файла записи и чтения
	
	OutList(Head); //вывод списка

	// Создание головного элемента списка
	Head    = new SItem;
	Head->Id   = 0;
	Head->next = NULL;
	Teil = Head;

	//создаем объект file для записи в текстовый файл
	ofstream file;
	//создаем объект Writefile для записи в текстовый файл
	ofstream write_file;
	
	// для команд меню
	for (;;)
	{
	CmdMenu = Menu (); 
	switch (CmdMenu)
	{
		// выход
		case EXIT:
			return;
			break;
		// добавляет новый элемент
		case NEW_ELEM:
			NewItem = new SItem;
			cout << "Студент номер >> ";
			cin >> NewItem -> Id ;
			AddItem(Head, NewItem, &Teil);
			cout << endl;
			cout << "Введите фамилию >>";
			cin >> NewItem -> Surname ;
			cout << endl;
			cout << "Введите имя >> ";
			cin >> NewItem -> Name ;
			cout << endl;
			cout << "Введите отчество >> ";
			cin >> NewItem -> Otche ;
			cout << endl;
			cout << "Введите номер телефона >> ";
			cin >> NewItem -> Number;
			cout << endl;
		break;
		// выводит все элементы	
		case PRINT_ALL:
			OutList(Head);
		break;
		// выводит выбранный элемент
		case PRINT_ELEM:
			Id = new int;
			cout << "Номер студента >> ";
			cin >> *Id;
			Buff = GetItem(Head, *Id);
			if(Buff)
			{
			cout << "Найден элемент Id = " << setw(2) << Buff->Id;
			cout << setw(13) << Buff->Surname << setw(13) << Buff->Name;
			cout << setw(13) << Buff->Otche << setw(13)<< Buff ->Number << endl;
			}
			else
				cout << "Элемент не найден." << endl;
		break;
			// сохраняет список в текстовый файл
		case SAVE_FILE:
			cout << "Введите файл . txt для хранения списка >> ";
			cin >> NameFileTxt;              // название текстового файла
			// открываем файл и проверяем на ошибки
			file.open(NameFileTxt, ios::app);
				if (!file.is_open())
				{
					cout<<"Ошибка открытия файла \""<<NameFileTxt;
					cout<<"\""<<endl;
					cout<<"Программа работу закончила."<<endl;
					system("pause");
					return;
				}
			SItem *current;		// указатель на текущий элемент списка
			if(!Head)
			{
				cout << "Список пуст." << endl;
				return;
			}
			current = Head -> next ; // указатель на текущий элемент
			// записываем в файл элементы списка до тех пор,
			// пока указатель на следующий элемент не NULL.
			while (current->next)
			{
				// Запись содержимого текущего элемента списка
				file << current->Id << "\\\\";
				file << current->Surname << "////" ;
				file << current->Name << "////" ;
				file << current->Otche << "////" ;
				file << current->Number << "////" ;
				file << endl;
				// Переходим к следующему элементу списка.
				current = current->next;	
			}
			// Запись содержимого последнего элемента списка
			// указатель которого на следующий элемент есть NULL.
			file << current->Id<< "\\\\" << current->Surname<< "////";
			file << current->Name<< "////"<< current->Otche<< "////" <<current-> Number << "////";
			file << endl;
			file.close();
		break;
  	 }
   }
}
// Команды меню
	int Menu ()
	{
		int CmdMenu;
		 using namespace std;

		 cout << "МЕНЮ: " << endl;
		 for (;;)
		 {
			 cout << EXIT << " - выход" << endl;
			 cout << NEW_ELEM << " - новый элемент " << endl;
			 cout << PRINT_ELEM << " - вывести на экран элемент..." << endl;
			 cout << PRINT_ALL << " - вывести весь список на экран" << endl;
			 cout << SAVE_FILE << " - сохранить в файле..." << endl;
			 cout << "Номер команды меню >> " ;
			 cin >> CmdMenu;
			 if (CmdMenu <0 || CmdMenu >= END)
			 {
				 cout << " ОШИБКА - ТАКОЙ КОМАНДЫ НЕТ." << endl;
				 continue;
			 }
			 else
				 return CmdMenu;
		 }

		 return CmdMenu;
	}
