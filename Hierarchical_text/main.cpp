#include"Text.h"
#include <iostream>
#include <fstream>

using namespace std;

TMem TTextLink::mem;
void main()
{
	setlocale(LC_CTYPE, "Russian");
	TTextLink::InitMem();
	TText text;
	text.Read("text.txt");
	text.Print();
	std::cout << '\n';
	std::cout << std::endl << "Список свободных : ";
	TTextLink::PrintFree(text);
	cout << "\n" << "Очистим" << endl;
	TTextLink::clean(text);
	std::cout << std::endl << "Обновленный список свободных : " << std::endl;
	TTextLink::PrintFree(text);
	char str[] = "par1";
	cout << "Удалим строки ниже par1 по указателю pDown" <<endl;
	for (text.Reset(); !text.IsEmpty(); text.GoNext())
	{
		if (!strcmp(text.GetCurr()->str, str))
		{
			text.DelDownLine();
			break;
		}
	}
	std::cout << '\n';
	text.Print();
	std::cout << std::endl << "Список свободных : ";
	TTextLink::PrintFree(text);
	cout << "\n" << "Очистим" << endl;
	TTextLink::clean(text);
	std::cout << std::endl << "Обновленный список свободных : " << std::endl;
	TTextLink::PrintFree(text);
	cout << "Вставим строку ниже par1" << "\n" << endl;
	for (text.Reset(); !text.IsEmpty(); text.GoNext())
	{
		if (!strcmp(text.GetCurr()->str, str))
		{
			text.InsDownLine("add_line");
			break;
		}
	}
	std::cout << '\n';
	text.Print();
	std::cout << std::endl << "Список свободных : ";
	TTextLink::PrintFree(text);
	cout << "\n" << "Очистим" << endl;
	TTextLink::clean(text);
	std::cout << std::endl << "Обновленный список свободных : " << std::endl;
	TTextLink::PrintFree(text);
	cout << "Удалим строки ниже par1 по указателю pNext" << endl;
	for (text.Reset(); !text.IsEmpty(); text.GoNext())
	{
		if (!strcmp(text.GetCurr()->str, str))
		{
			text.DelNextLine();
			break;
		}
	}
	std::cout << '\n';
	text.Print();
	std::cout << std::endl << "Список свободных: ";
	TTextLink::PrintFree(text);
	cout << "\n"<<"Очистим" << endl;
	TTextLink::clean(text);
	std::cout << std::endl << "Обновленный список свободных : ";
	TTextLink::PrintFree(text);
	text.SaveS("read.txt");
}