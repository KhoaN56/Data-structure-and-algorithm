#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
using namespace std;

// Ham thay doi kich co cua khung cmd voi tham so truyen vao la chieu cao, chieu rong.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Ham to mau.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Ham dich chuyen con tro den toa do x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = {x, y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Ham xoa man hinh.
void xoamanhinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Ham viet hoa
string viethoa(string x)
{
	string result;
	for (unsigned int i = 0; i <= x.length() - 1; ++i)
	{
		int a = x[i];
		if (a >= 97 && a <= 122)
		{
			result.push_back(a - 32);
		}
		else
			result.push_back(a);
	}
	return result;
}

//Ham xoa dong (y la dong can xoa, x la so dong tiep theo can xoa )
void xoadong(int y, int x)
{
	gotoxy(1, y);
	for (int j = 1; j <= x; ++j)
	{
		for (int i = 1; i <= 100; ++i)
		{
			cout << " ";
		}
		gotoxy(1, y + j);
	}
	gotoxy(1, y);
}

//Ham lay y ki tu tu vi tri x trong chuoi a
string Filter(string a, int x, int y)
{
	int dem = 0;
	string result;
	for (int i = x - 1;; ++i)
	{
		result.push_back(a[i]);
		++dem;
		if (dem == y)
			break;
	}
	return result;
}



// Ham lay Key tu ban phim
/* GetAsyncKeyState(VK_ESCAPE) => bat su kien phim Esc */

// Ham tu viet
void ToMau(int x, int y, char *a, int color) // x, y la toa do con tro can nhay den de viet, a la chuoi can truyen vao, color la mau truyen vao.
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}
