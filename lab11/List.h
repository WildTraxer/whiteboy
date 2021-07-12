#ifndef __LIST__H__
#define __LIST__H__

// ��������� - ������� ������
struct SItem
{
	int Id;               // ���������� ����� ��������
	char Name[20];        // ��� ��������
	char Surname[20]; 
	char Otche[20];
	char Number[20]; // ����� ��������
	SItem *next;
};

namespace Petrovich
{
	// =========��������� �������======================
	// ������� �� ����� ��� �������� ������
	void OutList(SItem *Head);
	// ��������� ������� � ����� ������
	void AddItem(SItem *Head, SItem *NewItem, SItem **Teil);
	// ������� ������� ������ � ��������������� ID. ���������� 
	// ����� ���������� �������� ��� NULL, ���� ������� �� ������.
	SItem *DeleteItem(SItem *Head, int Id, SItem **Teil);
	// ������� ������� ������ � ��������������� ID. ���������� 
	// ����� ���������� �������� ��� NULL, ���� ������� �� ������.
	SItem *GetItem(SItem *Head, int Id);
	// ������ �������� ��������� ������
	void DeleteAllItem(SItem **Head, SItem **Teil);
	// ��������� ������� ������ � ���������������� �������
	void AddItemInside(SItem *Head, SItem *NewItem, SItem **Teil);
	
}
#endif
