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
	std::cout << std::endl << "������ ��������� : ";
	TTextLink::PrintFree(text);
	cout << "\n" << "�������" << endl;
	TTextLink::clean(text);
	std::cout << std::endl << "����������� ������ ��������� : " << std::endl;
	TTextLink::PrintFree(text);
	char str[] = "par1";
	cout << "������ ������ ���� par1 �� ��������� pDown" <<endl;
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
	std::cout << std::endl << "������ ��������� : ";
	TTextLink::PrintFree(text);
	cout << "\n" << "�������" << endl;
	TTextLink::clean(text);
	std::cout << std::endl << "����������� ������ ��������� : " << std::endl;
	TTextLink::PrintFree(text);
	cout << "������� ������ ���� par1" << "\n" << endl;
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
	std::cout << std::endl << "������ ��������� : ";
	TTextLink::PrintFree(text);
	cout << "\n" << "�������" << endl;
	TTextLink::clean(text);
	std::cout << std::endl << "����������� ������ ��������� : " << std::endl;
	TTextLink::PrintFree(text);
	cout << "������ ������ ���� par1 �� ��������� pNext" << endl;
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
	std::cout << std::endl << "������ ���������: ";
	TTextLink::PrintFree(text);
	cout << "\n"<<"�������" << endl;
	TTextLink::clean(text);
	std::cout << std::endl << "����������� ������ ��������� : ";
	TTextLink::PrintFree(text);
	text.SaveS("read.txt");
}