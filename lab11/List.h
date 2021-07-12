#ifndef __LIST__H__
#define __LIST__H__

// Структура - элемент списка
struct SItem
{
	int Id;               // порядковый номер студента
	char Name[20];        // ФИО студента
	char Surname[20]; 
	char Otche[20];
	char Number[20]; // номер телефона
	SItem *next;
};

namespace Petrovich
{
	// =========ПРОТОТИПЫ ФУНКЦИЙ======================
	// Выводит на экран все элементы списка
	void OutList(SItem *Head);
	// Добавляет элемент в конец списка
	void AddItem(SItem *Head, SItem *NewItem, SItem **Teil);
	// Удаляет элемент списка с идентификатором ID. Возвращает 
	// адрес удаленного элемента или NULL, если элемент не найден.
	SItem *DeleteItem(SItem *Head, int Id, SItem **Teil);
	// Находит элемент списка с идентификатором ID. Возвращает 
	// адрес найденного элемента или NULL, если элемент не найден.
	SItem *GetItem(SItem *Head, int Id);
	// Вставляет элемент списка в лексиграфическом порядке
	void AddItemInside(SItem *Head, SItem *NewItem, SItem **Teil);
	
}
#endif
