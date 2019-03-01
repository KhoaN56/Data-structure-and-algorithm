#pragma once
#include <iostream>
#define TRUE 1
#define FALSE 0
#define EMPTY 0
#define COMPLETE 1
#define UNDONE 2
#define CONTINUE 3
#define BREAK 2
#define WHITE 15
#define MAXLOP 100
#define STACKSIZE 500
#define MAXCAUTHI 100
using namespace std;

const int dong = 2;
const int cot = 2;
const int Up = 72;
const int Down = 80;
const int SPACE = 32;
const int ENTER = 13;
const int ESC = 27;
const int BSPACE = 8;
const string ER_FULL_LIST = "Danh sach day!!";
int maxid;

struct monhoc
{
	char MAMH[7];
	char TENMH[50];
};
struct nodeMH
{
	monhoc info;
	struct nodeMH *next;
};
typedef nodeMH *PTRMH;

struct diem
{
	char Mamh[7];
	float mark;	
};
struct nodediem
{
	diem info;
	struct nodediem *next;
};
typedef nodediem *PTRD;
struct chitietdethi
{
	char MAMH[7];
	int socauthi;
	int *idcauthi;
	char *cautraloi;
	char *dapan;
};

struct nodechitietdethi
{
	chitietdethi info;
	struct nodechitietdethi *next;
};
typedef nodechitietdethi *PTRCTDT;
struct sinhvien
{
	char password[8];
	char MASV[11];
	char HO[51];
	char TEN[11];
	char PHAI[5];
	int *ctdethi;
	
};
struct nodesv
{
	sinhvien info;
	nodediem *Firstdiem;
	nodechitietdethi *Firstctdt;
	struct nodesv *next;
};
typedef nodesv *PTRSV;


struct Lop
{
	char MALOP[11];
	char TENLOP[100];
	PTRSV Firstsv;
};
struct dslop
{
	int n;
	Lop *lop;
};

struct cauhoi
{
	char mamh[7];
	string noidung;
	string A;
	string B;
	string C;
	string D;
	char dapan[1];
};

struct nodecauhoi
{
	int id;		//khoa
	int bf;
	cauhoi info;
	struct nodecauhoi *left, *right;
};
typedef nodecauhoi *PTRQ;

struct dscauthi
{
	int n;
	int *id;
};

struct nodedscauthi
{
	char MAMH[7];
	dscauthi info;
	struct nodedscauthi *next;
};
typedef nodedscauthi *PTRCT;

char menuGV [8][50] = {"1. Dieu chinh danh sach lop                  ",
					   "2. Dieu chinh danh sach sinh vien            ",
					   "3. Dieu chinh danh sach mon hoc              ",
					   "4. Dieu chinh cau hoi thi trac nghiem        ",
					   "5. Thi trac nghiem                           ",
					   "6. Xuat danh sach ra file                    ",
					   "7. Xem danh sach diem thi                    ",
					   "8. Thoat                                     "
					   };
char menu1 [5][50] = {"1. Them lop                                     ",
						"2. Sua lop                                      ",
						"3. Xoa lop                                      ",
						"4. Xem danh sach lop                            ",
						"5. Quay lai menu chinh                          "
					   };
char menu2 [5][50] = {"1. Them sinh vien                               ",
						"2. Sua sinh vien                                ",
						"3. Xoa sinh vien                                ",
						"4. Xem danh sach sinh vien                      ",
						"5. Quay lai menu chinh                          "
					   };  
char menu3 [5][50] = {"1. Them mon hoc                                 ",
						"2. Sua mon hoc                                  ",
						"3. Xoa mon hoc                                  ",
						"4. Xem danh sach mon hoc                        ",
						"5. Quay lai menu chinh                          "
					   };
char menu4 [5][50] = {"1. Them cau hoi                                  ",
					  "2. Sua cau hoi                                   ",
					  "3. Xoa cau hoi                                   ",
					  "4. Xem danh sach cau hoi                         ",
					  "5. Quay lai menu chinh                           "
					  };
char menu5 [5][50] = {"1. Xuat danh sach lop                            ",
					  "2. Xuat danh sach sinh vien theo lop             ",
					  "3. Xuat danh sach mon hoc                        ",
					  "4. Xuat danh sach cau hoi thi theo mon           ",
					  "5. Quay lai menu chinh                           "
					  };
