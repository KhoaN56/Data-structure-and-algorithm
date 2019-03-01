#pragma once
using namespace std;
//------Class List Proccessing-------
int Full_List(dslop ds);
int Empty_List(dslop ds);
void addClass(dslop &ds, Lop Class);
void deleteClass(dslop &ds, Lop Class);
void moveToLast(dslop &ds, int i);
void moveOut(dslop &ds, int i);
//------Student List Proccessing------
int emptyList(PTRSV First);
int countStudent(PTRSV First);
void insertFirst(PTRSV &First, sinhvien x);
void insertAfter(PTRSV p, sinhvien x);
void insertOrder(PTRSV &First, sinhvien sv);
PTRSV searchStudent(PTRSV First, char *masv);
void selectionSort(PTRSV &First);
char *makeString(sinhvien sv);
int deleteFirst(PTRSV &First);
int deleteAfter(PTRSV p);
int deleteStudent(PTRSV &First, char *masv);
//------Mark Proccessing------
int emptyList(PTRD First);
int countMark(PTRD First);
void insertFirst(PTRD &First, diem x);
void insertAfter(PTRD p, diem x);
PTRD searchMark(PTRD First, monhoc MH);
void deleteSubjectNode(PTRCT &First, char *mamh);
//------Subject Proccessing------
int emptyList(PTRMH First);
int countSubject(PTRMH FirstMH);
void insertFirst(PTRMH &First, monhoc x);
void insertAfter(PTRMH p, monhoc x);
PTRMH searchMaMH(PTRMH First, char *mamh);
int deleteSubject(PTRMH &First, char *mamh, PTRCT &FirstMT, PTRQ &root);
void saveSubjectList(PTRMH First, char *filename);
//------Quest tree proccessing (AVL tree)------
int nodeHeight(PTRQ p);
PTRQ search(PTRQ root, int id);
PTRQ rotateLeft(PTRQ root);
PTRQ rotateRight(PTRQ ya);
void insertAVLTree(PTRQ &pavltree, int x, cauhoi a);
void balanceLeft(PTRQ &root, int lh);
void balanceRight(PTRQ &root, int rh);
void removeAVLNode(PTRQ &root, int x);
void removeCase3(PTRQ &r, int x, PTRQ &rp);
int createAVLTree(PTRQ &root, PTRMH dsmh,PTRCT First);
PTRCTDT searchDList(PTRCTDT First, char *mamh);
void addDetailTest(PTRCTDT First, chitietdethi x);
void printDetailTest(PTRCTDT p, PTRQ root);
void saveQuestList(PTRQ root, char *filename);
void loadQuestList(PTRQ &root, char *filename);
int countNode(PTRQ root);
void saveSQList(PTRQ root, PTRCT p, char *filename);
int deleteID(PTRCT &p, int id);
//------Multiple choice test------
int *generateTest(dscauthi ds, int socauthi);
char *printTest(PTRQ root, int *cauthi, int socauthi);
int chooseAnswer(string td[], PTRQ p, int &testtime, int cau);
//------List of subject quest proccessing------
void insertSQList(PTRCT &First, monhoc mh);
void addID(dscauthi &ds, int id);
void moveOut(dscauthi &ds, int i);
void moveToLast(dscauthi &ds, int i);
PTRCT searchSCode(PTRCT First, char *mamh);
//------Display Result------
void printString(char *x);
void printInfo(PTRSV p);
void printStudentList(PTRSV First);
void printSubjectList(PTRMH First);
void printClassList(dslop ds);
void printMarkSubject(Lop Class, monhoc MH);
//------Others------
void viethoa(char *x);
void stoc(string s, char *c);
void ctos(char *c, string &s);
int checkEsc (char *x);
void HighLight ();
void Normal();
int MenuDong(char td [][50]);
int NhapMa(char *x, int n_max);
int NhapChuoi(char *x, int n_max);
int NhapPass( char *x, int n_max);
void Console_VeKhung(int ToaDoX, int ToaDoY, int Dai, int Rong);
void Console_VeKhung_clean(int ToaDoX, int ToaDoY, int Dai, int Rong);
void BaoLoi(char *S);
void moveToLast(dslop &ds, int i);
int DangNhap(dslop DSlop, PTRSV &sv);
//------Save file------
void saveClassList(dslop ds, char *filename);
void saveStudentList(Lop Class, char *filename);
void saveMarkList(Lop Class, monhoc MH, char *filename);
void saveWork(dslop ds, char *filename, PTRMH FirstMH);
//------Load files------
void loadClassList(dslop &ds, char *filename);
void loadStudentList(Lop &Class, char *filename);
void loadMarkList(Lop Class, monhoc MH, char *filename);
void loadWork(dslop &ds, char *filename, PTRMH &FirstMH, PTRQ &root, PTRCT &FirstMT);
//------Clear Lists------
void clearList(PTRSV &First);
void clearList(PTRD &First);
void clearList(PTRMH &First);
void clearList(dslop &ds);
void clearTree(PTRQ &root);

int Full_List(dslop ds)
{
	return (ds.n == MAXLOP ? TRUE : FALSE);
}
int Empty_List(dslop ds)
{
	return (ds.n == 0 ? TRUE : FALSE);
}
//------Student List Proccessing------
int emptyList(PTRSV First)
{
	return(First == NULL ? TRUE : FALSE);
}

void insertFirst(PTRSV &First, sinhvien x)
{
   PTRSV p;
   p = new nodesv;
   p->info = x;
   p->next = First;
   First = p;
}
void insertAfter(PTRSV p, sinhvien x)
{
   PTRSV q;
   if(p == NULL)
		cout << "khong them phan tu vao danh sach duoc";
   else
   {
   		q = new nodesv;
    	q->info = x;
    	q->next = p->next;
    	p->next = q;
   }
}

void insertOrder(PTRSV &First, sinhvien sv)
{
	PTRSV after, before, p;
	p = new nodesv;
	p->info = sv;
	for(after = First; after != NULL && stricmp(makeString(after->info), makeString(sv)) < 0; before = after, after = after->next);
	if(after == First)
	{
		p->next = First;
		First = p;
	}
	else
	{
		p->next = after;
		before->next = p;
	}
}

PTRSV searchStudent(PTRSV First, char *masv)
{
	for(PTRSV p = First; p != NULL; p = p->next)
		if(stricmp(p->info.MASV, masv) == 0)	return p;
	return NULL;
}

void selectionSort(PTRSV &First)
{
	PTRSV p, q, pmin;
	sinhvien min;
	for(p = First; p->next != NULL; p = p->next)
	{
		min = p->info;
		pmin = p;
		for(q = p->next; q != NULL; q = q->next)
		{
			if(stricmp(makeString(q->info), makeString(min)) < 0)
			{
				min = q->info;
				pmin = q;
			}
		}
		pmin->info = p->info;
		p->info = min;
	}
}

char *makeString(sinhvien sv)
{
	char *info = new char[50];
	strcpy(info, sv.TEN);
	strcat(info, sv.HO);
	strcat(info, sv.MASV);
	return info;
}

int deleteFirst(PTRSV &First)
{
	if(First == NULL)
		return FALSE;
	else
	{
		PTRSV p = First;
		First = p->next;
		delete p;
	}
	return COMPLETE;
}

int deleteAfter(PTRSV p)
{
	if(p == NULL || p->next == NULL)
		return FALSE;
	else
	{
		PTRSV q = p->next;
		p->next = q->next;
		delete q;
	}
	return COMPLETE;
}

int deleteStudent(PTRSV &First, char *masv)
{
	PTRSV p;
	char cf;
	if(First == NULL)
	{
		cout << "Danh sach rong!!" << endl;
		return FALSE;
	}
	if(stricmp(First->info.MASV,masv) == 0)
	{
		cout<<"-----------Thong tin sinh vien-----------\n";
		printInfo(First);
		cout<<"-----------------------------------------\n";
		cout << "Ban muon xoa sinh vien nay khong?(y/n) ";
		cin >> cf;
		if(cf == 'y' || cf == 'Y')
		{
			p = First;
			First = p->next;
			delete p->Firstdiem;
			delete p;
			return COMPLETE;
		}
		else 
			return UNDONE;
	}
	for(p = First; p->next != NULL && stricmp(p->next->info.MASV, masv) != 0; p = p->next);
	if(p->next != NULL)
	{
		printInfo(p->next);
		cout << "Ban muon xoa sinh vien nay khong?(y/n) ";
		cin >> cf;
		if(cf == 'y' || cf == 'Y')
		{
			PTRSV q = p->next;
			p->next = q->next;
			clearList(q->Firstdiem);
			delete q;
			return COMPLETE;
		}
		else
			return UNDONE;
	}
	return FALSE;
}

void saveStudentList(Lop Class, char *filename)
{
	ofstream ofs;
	PTRSV p;
	p = new nodesv;
	ofs.open(filename, ios_base::out);
	ofs << Class.TENLOP << endl;
	ofs << Class.MALOP << endl;
	ofs << "Si so: "<<countStudent(Class.Firstsv) << endl;
	for(p = Class.Firstsv;p != NULL; p = p->next)
		ofs << p->info.MASV << ", " << p->info.HO << " " << p->info.TEN << ", "
		<< p->info.PHAI<< endl;
	ofs.close();
}

void loadStudentList(Lop &Class, char *filename)
{
	ifstream ifs;
	PTRSV p;
	char malop[11];
	char buffer[100];
	ifs.open(filename, ios_base::in);
	if(ifs.fail() == true)
	{
		cout << "Ten file chua dung, moi nhap lai!!" << endl;
		system("pause");
	}
	ifs.getline(malop, 11, '\n');
	if(stricmp(Class.MALOP, malop) == 0)
	{
		Class.Firstsv = new nodesv;
		ifs.getline(buffer, 100, ',');
		strncpy(Class.Firstsv->info.MASV, buffer, strlen(buffer));
		ifs >> Class.Firstsv->info.HO;
		ifs.getline(buffer, 100, ',');
		strncpy(Class.Firstsv->info.TEN, buffer, strlen(buffer));
		ifs.getline(buffer, 100, ',');
		strncpy(Class.Firstsv->info.PHAI, buffer, strlen(buffer));
		ifs >> Class.Firstsv->info.password;
		ifs.getline(buffer, 100, ',');
		p = Class.Firstsv->next;
		while(buffer[0] != '#')
		{
			p = new nodesv;
			strncpy(p->info.MASV, buffer, strlen(buffer));
			ifs >> p->info.HO;
			ifs.getline(buffer, 100, ',');
			strncpy(p->info.TEN, buffer, strlen(buffer));
			ifs.getline(buffer, 100, ',');
			strncpy(p->info.PHAI, buffer, strlen(buffer));
			ifs >> p->info.password;
			ifs.getline(buffer, 100, ',');
			p = p->next;
		}
		p = NULL;
	}
	else
	{
		cout << "Khong tim thay danh sach sinh vien cua lop!" << endl;
		Sleep(2000);
	}
}

int countStudent(PTRSV First)
{
	PTRSV p;
	int i = 0;
	if(First == NULL)
	{
		cout << "Danh sach rong!";
		Sleep(2000);
		return 0;
	}
	for(p = First; p != NULL; p = p->next , ++i);
	return i;
}

void printStudentList(PTRSV First)
{
	PTRSV p;
	int i = 1;
	int y;
	if(First == NULL)
	{
		cout << "Danh sach rong!!" << endl;
		Sleep(2000);
		return;
	}
//	Console_VeKhung(4, 2, 52, 12);
	y=wherey()+1;
	gotoxy(5, y);
	cout <<  "STT";
	gotoxy(15, y);
	cout << "Ho va ten";
	gotoxy(34, y);
	cout << "Ma sinh vien";
	gotoxy(48, y);
	cout << "Phai" << endl;
	for(p = First; p != NULL; p = p->next, ++i)
	{
		if(i < 10)
			gotoxy(6, y + i);
		else
			gotoxy(5, y + i);
		cout << i;
		gotoxy(10, y + i);
		printString(p->info.HO);
		cout << " ";
		printString(p->info.TEN);
		gotoxy(35, y + i);
		printString(p->info.MASV);
		gotoxy(49, y + i);
		viethoa(p->info.PHAI);
		printString(p->info.PHAI);
		cout << endl;
	}
//	Console_VeKhung_clean(4, 2, 52, 12);
}

void printInfo(PTRSV p)
{
	cout <<"Ma so sv: "<<p->info.MASV << endl;
	cout <<"Ho va ten: "<<p->info.HO << " " << p->info.TEN << endl;
	cout <<"Phai: "<<p->info.PHAI << endl;
}

//------Mark Proccessing------
int emptyList(PTRD First)
{
	return(First == NULL ? TRUE : FALSE);
}

void insertFirst(PTRD &First, diem x)
{
   PTRD p;
   p = new nodediem;
   p->info = x;
   p->next = First;
   First = p;
}
void insertAfter(PTRD p, diem x)
{
   PTRD q;
   if(p == NULL)
		cout << "khong them phan tu vao danh sach duoc";
   else
   { 
    	q = new nodediem;
    	q->info = x;
      	q->next = p->next;
      	p->next = q;
   }
}

void saveMarkList(Lop Class, monhoc MH, char *filename)				//undone
{
	ofstream ofs;
	PTRSV p;
	ofs.open(filename, ios_base::out);
	ofs << Class.MALOP << endl;
	ofs << MH.MAMH << endl;
	for(p = Class.Firstsv; p != NULL; p = p -> next)
		ofs << p->info.MASV << " " << searchMark(p->Firstdiem, MH)->info.mark << endl;
	ofs << "#END";
	ofs.close();
}

void loadMarkList(Lop Class, monhoc MH, char *filename)
{
	ifstream ifs;
	PTRSV p;
	char code[11];
	char MaMH[9];
	ifs.open(filename, ios_base::in);
	if(ifs.fail() == true)
	{
		cout << "Ten file chua dung!!" << endl;
		system("pause");
	}
	ifs >> code;
	ifs >> MaMH;
	if(stricmp(Class.MALOP, code) == 0 && stricmp(MaMH, MH.MAMH) == 0)
	{
		ifs >> code;
		while(code[0] != '#')
		{
			p = searchStudent(Class.Firstsv, code);
			ifs >> searchMark(p->Firstdiem, MH)->info.mark;
			ifs >> code;
		}
	}
	else
	{
		cout << "File khong phu hop!" << endl;
		system("pause");
	}
	ifs.close();
}

PTRD searchMark(PTRD First, monhoc MH)
{
	for(PTRD p = First; p != NULL; p = p->next)
		if(stricmp(p->info.Mamh, MH.MAMH) == 0)
			return p;
	return NULL;
}

int countMark(PTRD First)
{
	PTRD p;
	int i = 0;
	if(First == NULL)
	{
		cout << "Danh sach diem rong!";
		Sleep(2000);
		return 0;
	}
	for(p = First; p !=NULL ; p = p->next, ++i);
	return i;
}

void printMarkSubject(Lop Class, monhoc MH)
{
	if(Class.Firstsv == NULL)
	{
		cout << "Danh sach sinh vien rong!!" << endl;
		Sleep(2000);
		return;
	}
	int i = 1;
	PTRD q;
	PTRSV p;
	cout<<"------------------------------------------------------------------------------------------\n";
	cout << "\t\tDanh sach diem thi mon " << MH.TENMH << " lop " << Class.MALOP << endl << endl;
	gotoxy(5, wherey());
	cout <<  "STT";
	gotoxy(15, wherey());
	cout << "Ho va ten";
	gotoxy(34, wherey());
	cout << "Ma sinh vien";
	gotoxy(52, wherey());
	cout << "Diem thi"<<endl;
	for(p = Class.Firstsv; p != NULL; p = p->next, ++i)
	{
		if(i < 10)
			gotoxy(6, wherey());
		else
			gotoxy(5, wherey());
		cout << i;
		gotoxy(10,wherey());
		printString(p->info.HO);
		cout << " ";
		printString(p->info.TEN);
		gotoxy(35, wherey());
		printString(p->info.MASV);
		q = searchMark(p->Firstdiem, MH);
		if(q == NULL)
		{
			gotoxy(52, wherey());
			cout << "Chua thi";
		}
		else
		{
			gotoxy(56, wherey());
			cout <<  q->info.mark;
		}
		cout<<endl;
	}
	cout<<"------------------------------------------------------------------------------------------\n";
}

//------Subject Proccessing------
int emptyList(PTRMH First)
{
	return (First == NULL ? TRUE : FALSE);
}

void insertFirst(PTRMH &First, monhoc x)
{
   PTRMH p;
   p = new nodeMH;
   p->info = x;
   p->next = First;
   First = p;
}
void insertAfter(PTRMH p, monhoc x)
{
   PTRMH q;
   if(p == NULL)
		cout << "Khong them phan tu vao danh sach duoc!" << endl;
   else
   { 
    	q = new nodeMH;
    	q->info = x;
      	q->next = p->next;
      	p->next = q;
   }
}

PTRMH searchMaMH(PTRMH First, char *mamh)
{
	for(PTRMH p = First; p != NULL; p=p->next)
		if(stricmp(p->info.MAMH, mamh) == 0)
			return p;
	return NULL;
}

int countSubject(PTRMH FirstMH)
{
	PTRMH p;
	int i = 0;
	if(FirstMH == NULL)
	{
		cout << "Danh sach mon hoc rong!";
		Sleep(2000);
		return 0;
	}
	for(p = FirstMH; p != NULL; p = p->next , ++i);
	return i;
}

void printSubjectList(PTRMH First)
{
	if(First == NULL)
	{
		cout << "Danh sach rong!!" << endl;
		Sleep(1500);
		return;
	}
	PTRMH p;
	int i = 1;
	int y=wherey();
	gotoxy(5, y);
	cout << "STT";
	gotoxy(20, y);
	cout << "Ten mon hoc";
	gotoxy(50, y);
	cout << "Ma mon hoc" << endl;
	for(p = First; p != NULL; p = p->next, ++i)
	{
		if(i < 10)
			gotoxy(6, wherey() );
		else
			gotoxy(5, wherey());
		cout << i;
		gotoxy(13, wherey());
		printString(p->info.TENMH);
		gotoxy(53, wherey());
		printString(p->info.MAMH);
		cout << endl;
	}
}

int deleteSubject(PTRMH &First, char *mamh, PTRCT &FirstMT, PTRQ &root)
{
	if(First == NULL)
	{
		return FALSE;
	}
	PTRMH p, q;
	char cf;
	if(stricmp(First->info.MAMH, mamh) == 0)
	{
		p = First;
		First = p->next;
		delete p;
		PTRCT a;
		a = searchSCode(FirstMT, mamh);
		int i;
		for(i = 0; i < a->info.n; ++i)
		removeAVLNode(root, a->info.id[i]);
		deleteSubjectNode(FirstMT, mamh);
		saveQuestList(root, "temptree.txt");
		clearTree(root);
		loadQuestList(root,"temptree.txt");
		return COMPLETE;
	}
	for(p = First; p != NULL && stricmp(p->info.MAMH, mamh) != 0; q = p, p = p->next);
	if(p != NULL)
	{
		q->next = p->next;
		delete p;
		PTRCT a;
		a = searchSCode(FirstMT, mamh);
		int i;
		for(i = 0; i < a->info.n; ++i)
		removeAVLNode(root, a->info.id[i]);
		deleteSubjectNode(FirstMT, mamh);
		saveQuestList(root, "temptree.txt");
		clearTree(root);
		loadQuestList(root,"temptree.txt");
		return COMPLETE;
	}
}
void saveSubjectList(PTRMH First, char *filename)
{
	PTRMH p;
	ofstream ofs;
	ofs.open(filename, ios_base::out);
	ofs << "Danh sach mon hoc" << endl;
	for(p = First; p != NULL; p = p->next)
		ofs << p->info.MAMH << "\t" << p->info.TENMH << endl;
	ofs << "#END.";
	ofs.close();
}
void deleteSubjectNode(PTRCT &First, char *mamh)
{
	PTRCT p, q;
	for(p = First; p != NULL && stricmp(p->MAMH, mamh);q = p, p = p->next);
	if(p == NULL)
	{
		return;
	}
	q->next = p->next;
	delete p->info.id;
	delete p;
}
//------Quest tree proccessing------

int nodeHeight(PTRQ p)
{
	if(p == NULL)
		return 0;
	return max(nodeHeight(p->left), nodeHeight(p->right)) + 1;
}

PTRQ search(PTRQ root, int id)
{
	PTRQ p = root;
	while(p != NULL && id != p->id)
		if(id < p->id)
			p = p->left;
		else
			p = p->right;
	if(p == NULL)
	{
		return NULL;
	}
	return p;
}

PTRQ rotateLeft(PTRQ root)
{
	PTRQ p;
	if(root == NULL)
	{
		cout << "Cay rong!" << endl;
		Sleep(2000);
		return 0;
	}
	else
	{
		if(root->right == NULL)
		{
			cout << "Khong the xoay trai vi cay khong co nut con ben phai!!" << endl;
			Sleep(3000);
		}
		else
		{
			p = root->right;
			root->right = p->left;
			p->left = root;
		}
	}
	return p;
}

PTRQ rotateRight(PTRQ ya)
{
	PTRQ s;
	if(ya == NULL)
	{
		cout << "Cay rong!!" << endl;
		Sleep(2000);
		return 0;
	}
	else
	{
		if(ya->left == NULL)
		{
			cout << "Khong the xoay phai vi cay khong co nut con ben trai!!" << endl;
			Sleep(3000);
		}
		else
		{
			s = ya->left;
			ya->left = s->right;
			s->right = ya;
		}
	}
	return s;
}

void insertAVLTree(PTRQ &pavltree, int x, cauhoi a)
{
   	PTRQ fp, p, q,    	// fp la nut cha cua p, q la con cua p
           fya, ya,     	/* ya la nut truoc gan nhat co the mat can bang
                           	   fya la nut cha cua ya */
           s;           	// s la nut con cua ya theo huong mat can bang
   	int imbal;           	/* imbal =  1 neu bi lech ve nhanh trai
                                 	   	  = -1 neu bi lech ve nhanh phai */
   	// Khoi dong cac gia tri
   	fp = NULL;	p = pavltree;
   	fya = NULL;	ya = p;
	// tim nut fp, ya va fya, nut moi them vao la nut la con cua nut fp
   	while(p != NULL)
   	{
      	if (x == p->id)  // bi trung khoa
         	return;
      	if (x < p->id)
	 		q = p->left;
      	else
         	q = p->right;
      	if(q != NULL)
         	if(q->bf != 0) // truong hop chi so can bang cua q la 1 hay -1
         	{ 
				fya = p;
            	ya = q;
         	}
      	fp = p;
      	p = q;
   	}
	// Them nut moi (nut la) la con cua nut fp
	q = new nodecauhoi;	// cap phat vung nho
	q->id =x;  q->info = a;  q->bf = 0;
	q->left = NULL;  q->right = NULL;
    if(x < fp->id)
    	fp->left = q;
	else
    	fp->right = q;
   	/*Hieu chinh chi so can bang cua tat ca cac nut giua ya va q, neu bi lech
      ve phia trai thi chi so can bang cua tat ca cac nut giua ya va q deu la
      1, neu bi lech ve phia phai thi chi so can bang cua tat ca cac nut giua
      ya va q deu la -1 */
   	if(x < ya->id)
      	p = ya->left;
   	else
     	p = ya->right;
   	s = p;     // s la con nut ya
   	while(p != q)
   	{ 
   		if(x < p->id)
      	{ 
			p->bf = 1;
        	p = p->left;
      	}
      	else
      	{  	
		  	p->bf = -1;
	 		p = p->right;
      	}
   	}
   	// xac dinh huong lech
   	if(x < ya->id)
    	imbal = 1;
   	else
    	imbal = -1;

   	if(ya->bf == 0)
   	{ 
   		ya->bf = imbal;
      	return;
   	}
   	if(ya->bf != imbal)
   	{ 
	   	ya->bf = 0;
      	return;
   	}

   	if(s->bf == imbal)   // Truong hop xoay don
   	{ 
	   	if(imbal == 1)    // xoay phai 
        	p = rotateRight(ya);
      	else              // xoay trai 
         	p = rotateLeft(ya);
      	ya->bf = 0;
     	s->bf = 0;
   	}
   	else                 // Truong hop xoay kep
   	{ 
	   	if(imbal == 1)    // xoay kep trai-phai 
     	{
			ya->left = rotateLeft(s);
         	p = rotateRight(ya);
      	}
      	else              // xoay kep phai-trai - 
      	{
		  	ya->right = rotateRight(s);
	 		p = rotateLeft(ya);
      	}
      	if(p->bf == 0)    // truong hop p la nut moi them vao
     	{
		 	ya->bf = 0;
         	s->bf = 0;
      	}
      	else
         	if(p->bf == imbal)
         	{
			 	ya->bf = -imbal;
            	s->bf = 0;
         	}
         	else
         	{ 
			 	ya->bf = 0;
            	s->bf = imbal;
         	}
      	p->bf = 0;
   	}
   	if(fya == NULL)
      	pavltree = p;
   	else
      	if(ya == fya->right)
         	fya->right = p;
      	else
         	fya->left = p;
}

int createAVLTree(PTRQ &root, PTRMH dsmh, PTRCT First)
{
	cauhoi x;
	char buffer[2000], cf;
	char *y=new char[8];
	int check;
	PTRMH mh;
	PTRCT sCT;
	while (1)
	{
	check_ma_mh:
	cout << "Nhap ma mon hoc: ";
	check=NhapMa(y,8);
	if(check == ESC)
	{
		check_esc:
		cout << "Ban muon ngung nhap cau hoi thi?(y/n) ";
		cin >> cf;
		if(cf == 'y'||cf=='Y')
			break;
		else if (cf=='n'||cf=='N')
			{
				system("cls");
				cout<<"\t\t==============Them cau hoi==============\n";
				goto check_ma_mh;
				continue;
			}
		else
		{
			BaoLoi("Xac nhan khong phu hop");
			goto check_esc;
		}
	}
	else 	//check = ENTER
	{
		mh=searchMaMH(dsmh,y);
		if (mh==NULL)
		{
			BaoLoi("Mon hoc khong ton tai, xin kiem tra lai");
			cout<<"-------------------Danh sach mon hoc-------------------\n";
			printSubjectList(dsmh);
			cout<<"-------------------------------------------------------\n";
			goto check_ma_mh;
		}
		else
		{
			strcpy(x.mamh,mh->info.MAMH);
			check_nd_4_1:
			cout << "Nhap noi dung cau hoi: ";
			check=NhapChuoi(buffer, 2000);
			if(check == ESC)
			{
				check = checkEsc(y);
				if (check==BREAK)
					break;
				else if (check==CONTINUE)
				{
					goto check_nd_4_1;
					continue;
				}
			}
			else if (check==ENTER)
			{
				x.noidung = buffer;
				check_da_4_1_A:
				cout << "Nhap noi dung lua chon A: ";
				check=NhapChuoi(buffer, 2000);
				if(check == ESC)
				{
					check = checkEsc(y);
					if (check==BREAK)
						break;
					else if (check==CONTINUE)
					{
						goto check_da_4_1_A;
						continue;
					}
				}
				else
					x.A = buffer;
					
				check_da_4_1_B:
				cout << "Nhap noi dung lua chon B: ";
				check=NhapChuoi(buffer, 2000);
				if(check == ESC)
				{
					check = checkEsc(y);
					if (check==BREAK)
						break;
					else if (check==CONTINUE)
					{
						goto check_da_4_1_B;
						continue;
					}
				}
				else
					x.B = buffer;
				
				check_da_4_1_C:
				cout << "Nhap noi dung lua chon C: ";
				check=NhapChuoi(buffer, 2000);
				if(check == ESC)
				{
					check = checkEsc(y);
					if (check==BREAK)
						break;
					else if (check==CONTINUE)
					{
						goto check_da_4_1_C;
						continue;
					}
				}
				else
					x.C = buffer;
				
				check_da_4_1_D:
				cout << "Nhap noi dung lua chon D: ";
				check=NhapChuoi(buffer, 2000);
				if(check== ESC)
				{
						check = checkEsc(y);
					if (check==BREAK)
						break;
					else if (check==CONTINUE)
					{
						goto check_da_4_1_D;
						continue;
					}
				}
				else
					x.D = buffer;
				
				check_da_4_1:
				cout << "Nhap dap an: ";
				check=NhapChuoi(buffer, 1);
				viethoa(buffer);
				if(check == ESC)
				{
						check = checkEsc(y);
					if (check==BREAK)
						break;
					else if (check==CONTINUE)
					{
						goto check_da_4_1;
						continue;
					}
				}
				else if (check==ENTER)
				{
					if (buffer[0]!='A'&& buffer[0]!='B'&& buffer[0]!='C'&& buffer[0]!='D')
						{
							BaoLoi("Dap an chi chua ki tu A, B, C, hoac D. Xin kiem tra lai!");
							goto check_da_4_1;
						}
					else
						strcpy(x.dapan,buffer);
					if(root == NULL)
					{
						root = new nodecauhoi;
						root->bf = 0;	root->info = x;
						root->id = 1;
						root->left = NULL;	root->right = NULL;
						maxid = 1;
					}
					else
					{
						insertAVLTree(root, ++maxid, x);
						sCT=searchSCode(First,mh->info.MAMH);
						addID(sCT->info, maxid);
						BaoLoi("Them cau hoi thanh cong");
						system("cls");
						cout<<"\t\t==============Them cau hoi==============\n";
						goto check_ma_mh;
					}
				}
			}
		}
		
		delete y;
		
	}
	}
}

void removeCase3(PTRQ &r, int x, PTRQ &rp)
{
	if(r->left != NULL)
		removeCase3(r->left, x, rp);
	else
	{
		rp->id = r->id;
//		rp->bf = r->bf;
		rp->info = r->info;
		rp = r;
		r = rp->right;
	}	
}

void balanceLeft(PTRQ &root, int lh)
{
	int rh = nodeHeight(root->right);
	if (abs(lh - rh) > 1)		//Cay mat can bang
	{
		if(root->right->bf == root->bf)		//Lech phai phai
			root = rotateLeft(root->right);
		else					//Lech phai trai
		{
			root->right = rotateRight(root->right);
			root = rotateLeft(root->right);
		}
	}
	
}

void balanceRight(PTRQ &root, int rh)
{
	int lh = nodeHeight(root->left);
	if (abs(lh - rh) > 1)		//Cay mat can bang
	{
		if(root->left->bf == root->bf)		//Lech trai trai
			root = rotateRight(root->left);
		else					//Lech trai phai
		{
			root->left = rotateLeft(root->left);
			root = rotateRight(root->left);
		}
	}
	
}

void removeAVLNode(PTRQ &root, int x)
{
	if(root == NULL)
	{
		cout << "Khong the xoa nut rong!!";
		Sleep(2000);
		return;
	}
	else
	{
		if(x < root->id)
		{
			if(root->left == NULL)
				return;
			int ah, bh = nodeHeight(root->left);		//bh la chieu cao truoc khi xoa node
			removeAVLNode(root->left, x);			//ah la chieu cao sau khi xoa node
			ah = nodeHeight(root->left);
			if(ah < bh)
				balanceLeft(root, ah);
			root->bf = nodeHeight(root->left) - nodeHeight(root->right);		//cap nhat he so can bang cua node
			//code can bang cay con nhanh trai neu chieu cao cua no bi giam
		}
		else if(x > root->id)
		{
			if(root->right == NULL)
				return;
			int ah, bh = nodeHeight(root->right);
			removeAVLNode(root->right, x);
			ah = nodeHeight(root->right);
			if(ah < bh)
				balanceRight(root, ah);
			root->bf = nodeHeight(root->left) - nodeHeight(root->right);		//cap nhat he so can bang cua node
			//code can bang cay con nhanh phai neu chieu cao cua no bi giam
		}
		else		//x = root->id
		{
			PTRQ rp;
			rp = root;
			if(rp->right == NULL)	root = rp->left;		//root la nut la hoac la nut chi co cay con ben trai
			else if(rp->left == NULL)	root = rp->right;	//root chi co cay con ben phai
			else
			{
				removeCase3(rp->right, x, rp);			//root co 2 cay con
				removeAVLNode(root->right, root->id);		/*Chay vao kiem tra lai phan node 
														cuc trai bi xoa thay the de can bang lai*/
			}
			delete rp;
		}
	}
}

int countNode(PTRQ root)
{
   	PTRQ Stack[STACKSIZE];
   	PTRQ p=root;
   	int i = 0;
   	int sp=-1;	// Khoi tao Stack rong
   	do
   	{ 
	   	while(p != NULL)
		{	
			Stack[++sp]= p;
	 		p = p->left;
      	}
      	if (sp != -1)
      	{
			p = Stack[sp--];
			++i;
			p = p->right;
      	}
      	else 
			break;
   }while(1);
   return i;
}

char *printTest(PTRQ root, int *cauthi, int socauthi)
{
	PTRQ quest;
	string choices[4];
	char *choice = new char[socauthi];
	int i = 0, testtime = 30, check;
	while(i < socauthi && testtime > 0)
	{
		quest = search(root, cauthi[i]);
		choices[0] = quest->info.A;
		choices[1] = quest->info.B;
		choices[2] = quest->info.C;
		choices[3] = quest->info.D;
//		stoc(quest->info.A, choices[0]);
//		stoc(quest->info.B, choices[1]);
//		stoc(quest->info.C, choices[2]);
//		stoc(quest->info.D, choices[3]);
		check = chooseAnswer(choices, quest, testtime, i+1);
		switch(check)
		{
			case 1:
				choice[i++] = 'A';
				break;
			case 2:
				choice[i++] = 'B';
				break;
			case 3:
				choice[i++] = 'C';
				break;
			case 4:
				choice[i++] = 'D';
				break;
		}
	}
	return choice;
}

void clearTree(PTRQ &root)
{
	if(root != NULL)    
   	{  
		clearTree(root->left);
      	clearTree(root->right);
     	delete root;
   	}
}
PTRCTDT searchDList(PTRCTDT First, char *mamh)
{
	if(First == NULL)
		return NULL;
	PTRCTDT p;
	for(p = First; p != NULL && stricmp(p->info.MAMH, mamh) != 0; p = p->next);
	return p;
}

void addDetailTest(PTRCTDT First, chitietdethi x)
{
	if(First == NULL)
	{
		First = new nodechitietdethi;
		First->info = x;
		First->next = NULL;
		return;
	}
	PTRCTDT p, q;
	p = searchDList(First, x.MAMH);
	if(p == NULL)
	{
		for(q = First; q->next != NULL; q = q->next);
		p = new nodechitietdethi;
		p->info = x;
		q->next = p;
	}
	else
		p->info = x;
}
void printDetailTest(PTRCTDT p, PTRQ root)
{
	int i;
	PTRQ q;
	for(i = 0; i < p->info.socauthi; ++i)
	{
		q = search(root, p->info.idcauthi[i]);
		gotoxy(3, wherey()+1);
		cout << i << ". " << q->info.noidung;
		gotoxy(5, wherey()+1);
		cout << q->info.A;
		gotoxy(5, wherey()+1);
		cout << q->info.B;
		gotoxy(5, wherey()+1);
		cout << q->info.C;
		gotoxy(5, wherey()+1);
		cout << q->info.D;
		gotoxy(3, wherey()+1);
		cout << "Cau tra loi: " << p->info.cautraloi[i];
		gotoxy(3, wherey()+1);
		cout << "Dap an: " << p->info.dapan[i];
	}
}
void loadQuestList(PTRQ &root, char *filename)
{
	int maxnode, i, id;
	char buffer[2000];
	cauhoi quest;
	ifstream ifs;
	ifs.open(filename, ios_base::in);
	ifs.getline(buffer, 100, '\n');
	maxnode = atoi(buffer);
	for(i = 0; i < maxnode; ++i)					//Doc cay nhi phan
	{
		ifs.getline(buffer, 100, '\n');
		id = atoi(buffer);
		ifs.getline(quest.mamh, 100, '\n');
		ifs.getline(buffer, 2000, '\n');
		quest.noidung = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.A = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.B = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.C = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.D = buffer;
		ifs.getline(quest.dapan, 100, '\n');
		if(i == 0)
		{
			root = new nodecauhoi;
			root->id = id;
			root->bf = 0;
			root->info = quest;
			root->left = NULL;
			root->right = NULL;
		}
		else
			insertAVLTree(root, id, quest);
	}
	ifs.close();
}
void saveSQList(PTRQ root, PTRCT p, char *filename)
{
	PTRQ q;
	ofstream ofs;
	ofs.open(filename, ios_base::out);
	ofs << "Danh sach cau hoi thi theo mon" << endl;
	ofs << p->MAMH << endl;
	ofs << "So cau hoi: " << p->info.n << endl;
	for(int i; i < p->info.n; ++i)
	{
		q = search(root, p->info.id[i]);
		ofs << q->id << endl;
		ofs << q->info.mamh << endl;
		ofs << q->info.noidung << endl;
		ofs << q->info.A << endl;
		ofs << q->info.B << endl;
		ofs << q->info.C << endl;
		ofs << q->info.D << endl;
	}
	ofs.close();
}
int deleteID(PTRCT &p, int id)
{
	int i;
	for(i = 0; i < p->info.n && id != p->info.id[i]; ++i);
	if(i == p->info.n)
		return FALSE;
	else
	{
		moveToLast(p->info,i);
		--p->info.n;
		return COMPLETE;
	}
}
//------Multiple choice test------
int *generateTest(dscauthi ds, int socauthi)
{
	int *dethi = new int[socauthi];
	int a, i, x;
	for(i = 0; i < socauthi; ++i)
	{
		a = rand() % ds.n;
		dethi[i] = ds.id[a];
		x = ds.id[a];	
		ds.id[a] = ds.id[ds.n - 1];
		ds.id[ds.n--] = x;
	}
	return dethi;
}

//------List of subject quest proccessing------

PTRCT searchSCode(PTRCT First, char *mamh)
{
	if(First == NULL)
	{
		cout << "Danh sach rong!!" << endl;
		return First;
	}
	PTRCT p;
	for(p = First; p != NULL && stricmp(p->MAMH, mamh) != 0; p = p->next);
		return p;
}

void insertSQList(PTRCT &First, monhoc mh)
{
	if(First == NULL)
	{
		First = new nodedscauthi;
		strcpy(First->MAMH, mh.MAMH);
		First->info.id = new int [MAXCAUTHI];
		First->next = NULL;
		return;
	}
	PTRCT p, q;
	for(p = First; p->next != NULL; p = p->next);
	q = new nodedscauthi;
	strcpy(q->MAMH, mh.MAMH);
	q->next = NULL;
	p->next = q;
}

void addID(dscauthi &ds, int id)
{
	if(ds.n == MAXCAUTHI)
	{
		cout << "Danh sach day, khong the them duoc!!" << endl;
		Sleep(2000);
		return;
	}
	int i;
	for (i = 0; i < ds.n; ++i)
	{
		if(id < ds.id[i])
		{
			moveOut(ds, i-1);
			ds.id[i] = id;
			break;
		}
	}
	if(i == ds.n)		//Cuoi danh sach
	{
		moveOut(ds, i-2);
		ds.id[i] = id;
	}
}

void moveOut(dscauthi &ds, int i)
{
	int x, y;
	for(int j = ds.n; j > i + 1; --j)
	{
		ds.id[j] = ds.id[j - 1];
	}
	++ds.n;
}

void moveToLast(dscauthi &ds, int i)
{
	int x;
	for(; i < ds.n - 1; ++i)
	{
		x = ds.id[i];
		ds.id[i] = ds.id[i+1];
		ds.id[i+1] = x;
	}
}

void clearSubjectQuest(PTRCT &First)
{
	PTRCT p;
	while(First != NULL)
	{
		p = First;
		First = p->next;
		delete p->info.id;
		delete p;
	}
}
int printQuestList(PTRQ root, PTRCT p, monhoc mh)
{
	if(root == NULL)		//Cay rong
	{
		return FALSE;
	}
	PTRQ q;
	int y=wherey()+1;
	
	gotoxy(5, y);
	cout << "ID";
	gotoxy(25, y);
	cout << "Cau hoi thi"<<endl;
	for(int i = 0; i < p->info.n; ++i)
	{
		q = search(root, p->info.id[i]);
		gotoxy(5, wherey());
		cout << p->info.id[i];
		gotoxy(15, wherey());
		cout << q->info.noidung<<endl;
	}
	return COMPLETE;
}
//------Others------

int c_a_r(char td [][50])
{
	int i;
	for(i = 0; td[i][0] != NULL; ++i);
	return i;
}

void viethoa(char *x)
{
	char a;
	for (int i = 0; i < strlen(x); ++i)
	{
		a = x[i];
		if (a >= 97 && a <= 122)
		{
			x[i] = a - 32;
		}
		else
			x[i] = a;
	}
}

void ctos(char *c, string &s)
{
	int i = 0;
	while(i < strlen(c))
	{
		s[i] = c[i];
		++i;
	}
}

void stoc(string s, char *c)
{
	int i = 0;
	while(i < s.length())
	{
		c[i] = s[i];
		++i;
	}
	c[i++] = '\0';
}

int checkEsc (char *x)
{
	int check;
	check2_esc:
	cout << "Ban muon quay lai menu?(y/n) ";
	check = NhapMa(x, 1);
	if(check == ESC)
		return CONTINUE;
	else if(check == ENTER)
	{
		if(x[0] == 'y' || x[0] == 'Y')
		{
		
			return BREAK;
		}
		else if(x[0] == 'n' || x[0] == 'N')
		{
			
			return CONTINUE;
		}
		else
		{
			BaoLoi("Xac nhan khong phu hop");
			goto check2_esc;
		}
	}
	else 
	{
		BaoLoi("Xac nhan khong phu hop");
		goto check2_esc;
	}
	
}

void printString(char *x)
{
	int i = 0;
	if(x == NULL)
		return;
	while(i < strlen(x))
	{
		cout << x[i];
		++i;
	}
}

void saveWork(dslop ds, char *filename, PTRMH FirstMH, PTRQ root)
{
	ofstream ofs;
	PTRSV p;
	PTRD q;
	PTRMH s;
	PTRQ Stack[STACKSIZE];
   	PTRQ qn=root;
   	int sp=-1;	// Khoi tao Stack rong
	ofs.open(filename, ios_base::out);
	if(ofs.fail()==true)
	{
		cout << "Khong mo duoc file" << endl;
		Sleep(3000);
		return;
	}
	ofs << ds.n << endl;
	for(int i = 0; i < ds.n; ++i)
	{
		ofs << ds.lop[i].TENLOP << endl;
		ofs << ds.lop[i].MALOP << endl;
		ofs << countStudent(ds.lop[i].Firstsv) << endl;
		for(p = ds.lop[i].Firstsv; p != NULL; p=p->next)
		{
			ofs << p->info.MASV << ",";
			ofs << p->info.password << ",";
			ofs << p->info.HO << ",";
			ofs << p->info.TEN << ",";
			ofs << p->info.PHAI << ",";
			ofs << countMark(p->Firstdiem) << ",";
			for(q = p->Firstdiem; q != NULL; q=q->next)
			{
				ofs << q->info.Mamh << ",";
				if(q->next == NULL)
					ofs << q->info.mark << "." << endl;
				else
					ofs << q->info.mark << ",";
			}
		}
	}
	ofs << countSubject(FirstMH) << endl;
	for(s = FirstMH; s != NULL; s = s->next)
	{
		ofs << s->info.TENMH << ",";
		ofs << s->info.MAMH << endl;
	}
	ofs << maxid << endl;
   	do
   	{ 
	   	while(qn != NULL)
		{	
			Stack[++sp]= qn;
	 		qn = qn->left;
      	}
      	if (sp != -1)
      	{
			qn = Stack[sp--];
			ofs << qn->id << endl;
			ofs << qn->info.mamh << endl;
			ofs << qn->info.noidung << endl;
			ofs << qn->info.A << endl;
			ofs << qn->info.B << endl;
			ofs << qn->info.C << endl;
			ofs << qn->info.D << endl;
			ofs << qn->info.dapan << endl;
			qn = qn->right;
      	}
      	else 
			break;
   }while(1);
	ofs.close();
}

void loadWork(dslop &ds, char *filename, PTRMH &FirstMH, PTRQ &root, PTRCT &FirstMT)
{
	ifstream ifs;
	PTRSV p, pr;
	PTRD q, qr;
	PTRMH s, sr;
	PTRCT ql, qlr;
	PTRCTDT ct, ctr;
	cauhoi quest;
	dscauthi qlist;
	int i, j, k, z, maxsv, maxdiem, maxmh, id;
	char buffer[2000];
	ifs.open(filename, ios_base::in);
	if(ifs.fail() == true)
	{
		cout << "Khong mo duoc file" << endl;
		Sleep(3000);
		return;
	}
	ifs.getline(buffer, 100, '\n');
	ds.n = atoi(buffer);
	for(i = 0; i < ds.n; ++i)
	{
		ifs.getline(ds.lop[i].TENLOP, 100, '\n');
		ifs.getline(ds.lop[i].MALOP, 11, '\n');
		ifs.getline(buffer, 100, '\n');
		maxsv = atoi(buffer);
		for(j = 0; j < maxsv; ++j)
		{
			p = new nodesv;
			ifs.getline(p->info.MASV, 11, ',');
			ifs.getline(p->info.password, 32, ',');
			ifs.getline(p->info.HO, 51, ',');
			ifs.getline(p->info.TEN, 11, ',');
			ifs.getline(p->info.PHAI, 5, ',');
			ifs >> maxdiem;
			if(maxdiem != 0)
				ifs.getline(buffer, 10, ',');
			else
				ifs.getline(buffer, 100, '\n');
			for(k = 0; k < maxdiem; ++k)
			{
				q = new nodediem;
				ct = new nodechitietdethi;
				ifs.getline(q->info.Mamh, 9, ',');
				strcpy(ct->info.MAMH, q->info.Mamh);
				if(k == maxdiem - 1)
				{
					ifs.getline(buffer, 100, ',');
					q->info.mark = atoi(buffer);
					ifs.getline(buffer, 100, ',');
					ct->info.socauthi = atoi(buffer);
					ct->info.idcauthi = new int[ct->info.socauthi];
					ct->info.cautraloi = new char[ct->info.socauthi];
					for(z = 0; z < ct->info.socauthi; ++z)
					{
						ifs.getline(buffer, 100, ',');
						ct->info.idcauthi[z] = atoi(buffer);
						if(z == ct->info.socauthi - 1)
						{
							ifs.getline(buffer, 100, '\n');
							ct->info.cautraloi[z] = buffer[0];
							break;
						}
						else	
							ifs.getline(buffer, 100, ',');
						ct->info.cautraloi[z] = buffer[0];
					}
					for(qr = p->Firstdiem; qr->next != NULL; qr = qr->next);
					qr->next = q;
					q->next = NULL;
					for(ctr = p->Firstctdt; ctr->next != NULL; ctr = ctr->next);
					qr->next = q;
					ctr->next = NULL;
					break;
				}
				ifs.getline(buffer, 100, ',');
				q->info.mark = atoi(buffer);
				ifs.getline(buffer, 100, ',');
				ct->info.socauthi = atoi(buffer);
				ct->info.idcauthi = new int[ct->info.socauthi];
				ct->info.cautraloi = new char[ct->info.socauthi];
				for(z = 0; z < ct->info.socauthi; ++z)
				{
					ifs.getline(buffer, 100, ',');
					ct->info.idcauthi[z] = atoi(buffer);
					ifs.getline(buffer, 100, ',');
					ct->info.cautraloi[z] = buffer[0];
				}
				if(k == 0)
				{
					p->Firstdiem = q;
					p->Firstctdt = ct;
				}
				else
				{
					for(qr = p->Firstdiem; qr->next != NULL; qr = qr->next);
					for(ctr = p->Firstctdt; ctr->next != NULL; ctr = ctr->next);
					qr->next = q;
					ctr->next = ct;
				}
				q->next = NULL;
				ct->next = NULL;
			}
			if(k == 0)
			{
				p->Firstdiem = NULL;
				p->Firstctdt = NULL;
			}
			if(j == 0)
				ds.lop[i].Firstsv = p;
			else
			{
				for(pr = ds.lop[i].Firstsv; pr->next != NULL; pr = pr->next);
				pr->next = p;
			}
			p->next = NULL;
		}
	}
	ifs.getline(buffer, 100, '\n');
	maxmh = atoi(buffer);
	for(i = 0; i < maxmh; ++i)
	{
		s = new nodeMH;
		ql = new nodedscauthi;
		ql->info.id = new int[MAXCAUTHI];
		ql->info.n = 0;
		ifs.getline(s->info.TENMH, 50, ',');
		ifs.getline(s->info.MAMH, 7, '\n');
		strcpy(ql->MAMH, s->info.MAMH);
		
		if(i == 0)
		{
			FirstMH = s;
			FirstMT = ql;
		}
		else
		{
			for(sr = FirstMH; sr->next != NULL; sr = sr->next);
			for(qlr = FirstMT; qlr->next != NULL; qlr = qlr->next);
			sr->next = s;
			qlr->next = ql;
		}
		s->next = NULL;
		ql->next = NULL;
	}
	ifs.getline(buffer, 100, '\n');
	maxid = atoi(buffer);
	ql = FirstMT;
	for(i = 0; i < maxid; ++i)					//Doc cay nhi phan
	{
		ifs.getline(buffer, 100, '\n');
		id = atoi(buffer);
		ifs.getline(quest.mamh, 100, '\n');
		ifs.getline(buffer, 2000, '\n');
		quest.noidung = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.A = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.B = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.C = buffer;
		ifs.getline(buffer, 2000, '\n');
		quest.D = buffer;
		ifs.getline(quest.dapan, 100, '\n');
		if(i == 0)
		{
			root = new nodecauhoi;
			root->id = id;
			root->bf = 0;
			root->info = quest;
			root->left = NULL;
			root->right = NULL;
		}
		else
			insertAVLTree(root, id, quest);
		ql = searchSCode(FirstMT, quest.mamh);
		addID(ql->info, id);
	}
	
	ifs.close();
}
void Normal () {
	SetColor(WHITE);
	SetBGColor(0);
}

void HighLight () {
	SetColor(15);
	SetBGColor(1);
}

int MenuDong(char td [][50]) {
	Normal();
	system("cls");
	cout << "\t\t==============THI TRAC NGHIEM==============";
	int chon =0, so_item;
	int i;
	so_item = c_a_r(td);
	for ( i=0; i< so_item ; i++) {
		gotoxy(cot, dong +i);
		cout << td[i];
	}
	HighLight();
	gotoxy(cot,dong+chon);
	cout << td[chon];
	char kytu;
	do {
		kytu = getch();
		if (kytu == 0) kytu = getch();
		switch (kytu) {
			case Up :
				if (chon+1 >1) {
					Normal();
					gotoxy(cot,dong+chon);
					cout << td[chon];
					chon --;
					HighLight();
					gotoxy(cot,dong+chon);
					cout << td[chon];

				}
				break;
			case Down :
				if (chon + 1 <so_item) {
					Normal();
					gotoxy(cot,dong+chon);
					cout << td[chon];
					chon ++;
					HighLight();
					gotoxy(cot,dong+chon);
					cout << td[chon];
				}
				break;
			case 13 :
				return chon+1;
			case 27:
				system("cls");
				return 0;
		}  // end switch
	} while (1);
}

void BaoLoi(char *S){
	int x = wherex(), y = wherey();
	int x1 = wherex(), y1 = wherey() + 3;
	gotoxy(40, y1);
	cout<<S;
	Sleep(2000);
	gotoxy(40, y1);
	cout <<"                                                                ";
	gotoxy(x , y );
}

int NhapMa(char *x, int n_max)
{
	char c;
	int i = 0;
	int x1 = 0,y1 = 0, x2 = 0,y2 = 0;
	char answer;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";	
			cout<<endl;		
			return ESC;
		}
		else if (c == ENTER)
		{
			if (i == 0){
				BaoLoi("Ban chua nhap chuoi, moi nhap lai!!");
				Sleep(2000);
				continue;
			}
			x[i] = '\0';
			cout << endl;
			return ENTER;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (c == SPACE){
			BaoLoi("Chuoi can nhap khong duoc chua khoang trang. Xin kiem tra lai");
			continue;		
		}
		else if (i == n_max){
			x1 = wherex();	y1 = wherey();
			x2 = wherex() + 5;	y2 = wherey() + 5;
			gotoxy(x2, y2);
			cout<<"Chuoi can nhap chi chua toi da " << n_max << " ki tu";
			Sleep(1500);
			gotoxy(x2, y2);
			cout <<"                                                                ";
			gotoxy(x1 , y1 );
			continue;
		}
		else if (c < 0){
			c = getch();
			if (c >= 0)
				continue;
		}
		else 
		{
			if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))// nhap chu, so
				x[i] = c;
			else 
			{
				BaoLoi("Chuoi chi chua chu hoac so. Xin kiem tra lai!");
				continue;			
			}
		}
		if(c != 0){
		x[i] = c;
		cout << x[i];
		}
		++i;
	}
}

int NhapChuoi(char *x, int n_max)
{
	char c;
	int i = 0;
	int x1 = 0,y1 = 0, x2 = 0,y2 = 0;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";
			cout<<endl;		
			return ESC;
		}
		else if (c == ENTER)
		{
			if (i == 0)
			{
				BaoLoi("Ban chua nhap chuoi, moi nhap lai!!");
				continue;
			}
			x[i] = '\0';
			cout << endl;
			return ENTER;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (i == n_max){
			x1 = wherex();	y1 = wherey();
			x2 = wherex()+5;	y2 = wherey()+5;
			gotoxy(x2,y2);
			cout<<"Chuoi can nhap chi chua toi da " << n_max << " ki tu";
			Sleep(1500);
			gotoxy(x2, y2);
			cout <<"                                                                ";
			gotoxy(x1, y1 );
			continue;
		}
		else if (i == 0 && c == SPACE)
		{
			BaoLoi("Ki tu dau tien khong duoc la khoang trang. Xin kiem tra lai!");
			continue;
		}
		else if (c < 0){
			c = getch();
			if(c >= 0)
			continue;
		}
		else 
		{
			if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == SPACE)// nhap chu
				x[i] = c;
			else 
			{
				BaoLoi("Chuoi chi chua chu cai va dau cach. Xin kiem tra lai!");
				continue;			
			}
		}
		if (c != 0)
			cout<< x[i];
		++i;
	}
}

int NhapPass( char *x, int n_max){
	char c;
	int i = 0;
	int x1 = 0,y1 = 0, x2 = 0,y2 = 0;
	while(1)
	{
		c = getch();
		if (c == ESC)
		{
			x = "";
			cout<<endl;		
			break;
		}
	
		else if (c == ENTER)
		{
			if (i == 0){
				BaoLoi("Muc nay khong duoc de trong. Xin kiem tra lai");
				continue;
			}
			x[i] = '\0';
			cout << endl;
			break;
		}
		else if (c == BSPACE)
		{
			if (i == 0)	continue;
			else 
			{
				--i;
				cout << c << " " << c;
				x[i] = NULL;
				continue;
			}
		}
		else if (c == SPACE){
			BaoLoi("Mat khau khong duoc chua khoang trang. Xin kiem tra lai!");
			continue;		
		}
		else if (i==n_max){
			x1=wherex();	y1=wherey();
			x2=wherex()+5;	y2=wherey()+5;
			gotoxy(x2,y2);
			cout<<"Chuoi can nhap chi chua toi da " << n_max << " ki tu";
			Sleep(2000);
			gotoxy(x2,y2);
			cout <<"                                                                ";
			gotoxy(x1 , y1 );
			continue;
		}
		else if (c < 0)
		{
			c = getch();
			if(c >= 0)
				continue;
		}
		else 
		{
			if (c >= 33 && c <= 126)// nhap chu, so, ki tu dac biet
				x[i] = c;
			else 
			{
				BaoLoi("Chuoi chi chua chu hoac so. Xin kiem tra lai!");	
				continue;			
			}
		}
		if(c != 0)
		{
			x[i] = c;
			cout<<"*";
		}
		++i;
	}
}

int DangNhap(dslop DSlop, PTRSV &sv)
{
	char *ID = new char [10];
	char *pass = new char [8];
	int i = 0;
	PTRSV p;
	while(1)
	{
		system("cls");
		cout<<"=======================DANG NHAP======================="<<endl;
		cout<<"Ten dang nhap: ";
		i = NhapMa(ID, 10);
		if(i == ESC)
		{
			xoadong(2, 2);
			cout << "Ban co muon thoat chuong trinh khong?(y/n) ";
			i = NhapMa(ID, 2);
			if(i == ESC || ID[0] == 'n' || ID[0] == 'N')
				continue;
			else if(ID[0] == 'y' || ID[0] == 'Y')
				return 0;
		}
		else if(i == ENTER)
		{
			if(strlen(ID) == 0)
			{
				cout << "Ban chua nhap ID! Moi nhap lai!" << endl;
				Sleep(2000);
				continue;
			}
			
		}
		cout<<"Nhap mat khau: ";
		i = NhapPass(pass, 8);
		if(i == ESC)
		{
			xoadong(2, 2);
			cout << "Ban co muon thoat chuong trinh khong?(y/n) ";
			i = NhapMa(ID, 2);
			if(i == ESC || ID[0] == 'n' || ID[0] == 'N')
				return 0;
			else if(ID[0] == 'y' || ID[0] == 'Y')
				break;
		}
		if(stricmp(ID, "GV") == 0 || stricmp(ID, "gv") == 0)
		{
			if(stricmp(pass, "GV") == 0 || stricmp(pass, "gv") == 0)
			{
				return 2;
			}
			else
			{
				cout << "Mat khau chua dung, moi nhap lai!!" << endl;
				Sleep(2000);
				continue;
			}
		}
		else
		{
			for(i = 0; i < DSlop.n; i++)
			{
				p = searchStudent(DSlop.lop[i].Firstsv, ID);
				if(p != NULL)	break;
			}
			if(p == NULL)
			{
				cout << "ID khong dung, moi nhap lai!!" << endl;
				Sleep(2000);
				continue;
			}
			else
				if(stricmp(pass, p->info.password) == 0)
				{
					sv=p;
					return 1;
				}
				else
				{
					cout << "Mat khau khong dung! Moi nhap lai!" << endl;
					Sleep(2000);
					continue;
				}
		}
	}
	delete ID;
	delete pass;
}

int chooseAnswer(string td[], PTRQ p, int &testtime, int cau) {
	int row=4;
	Normal();
	system("cls");
	cout << "\t\t==============THI TRAC NGHIEM==============" << endl;
	int chon =0, so_item;
	int i = 0;
	int posy[4];
	cout << "\n\n " << cau << ". " << p->info.noidung << endl;
	gotoxy(cot, row + i);
	for (; i < 4 ; i++) {
		posy[i] = wherey();
		gotoxy(cot, posy[i]);
		cout << td[i] << endl;
	}
	HighLight();
	gotoxy(cot,row+chon);
	cout << td[chon];
	char kytu;
	do {
		if(kbhit())
		{
		kytu = getch();
		if (kytu == 0) kytu = getch();
		switch (kytu) {
			case Up :
				if (chon+1 >1) {
					Normal();
					gotoxy(cot, posy[chon]);
					cout << td[chon];
					chon --;
					HighLight();
					gotoxy(cot, posy[chon]);
					cout << td[chon];
				}
				break;
			case Down :
				if (chon + 1 < 4) {
					Normal();
					gotoxy(cot, posy[chon]);
					cout << td[chon];
					chon ++;
					HighLight();
					gotoxy(cot, posy[chon]);
					cout << td[chon];
				}
				break;
			case 13 :
				return chon+1;
			case 27:
				system("cls");
				return 0;
		}  // end switch
		}
		else
		{
			gotoxy(1, 2);
			Normal();
			cout << "        ";
			gotoxy(1, 2);
			cout << "\t\t\t\t\t\t\t" << testtime--;
			Sleep(1000);
		}
	} while (testtime>=0);
}

void Console_VeKhung(int ToaDoX, int ToaDoY, int Dai, int Rong) {
	// Tren 
	gotoxy(ToaDoX, ToaDoY); cout << char(201);// Goc Trai tren cung
	gotoxy(Dai + ToaDoX, ToaDoY); cout << char(187);// Goc Phai tren cung
													// Duoi
	gotoxy(ToaDoX, Rong + ToaDoY); cout << char(200);// Goc Trai duoi cung
	gotoxy(Dai + ToaDoX, Rong + ToaDoY); cout << char(188);// Goc Phai duoi cung
														   // In Dong Ngang:
	for (int i = 1; i<Dai; i++) {
		gotoxy(i + ToaDoX, ToaDoY); cout << char(205);//Tren
		gotoxy(i + ToaDoX, Rong + ToaDoY); cout << char(205);//Duoi
	}// for Dong
	 // In Cot Dung:
	for (int i = 1; i<Rong; i++) {
		gotoxy(ToaDoX, i + ToaDoY); cout << char(186);// Cot Trai
		gotoxy(Dai + ToaDoX, i + ToaDoY); cout << char(186);// Cot Phai
	}// for Cot
}
void Console_VeKhung_clean(int ToaDoX, int ToaDoY, int Dai, int Rong) {
	// Tren 
	gotoxy(ToaDoX, ToaDoY); cout << " ";// Goc Trai tren cung
	gotoxy(Dai + ToaDoX, ToaDoY); cout << " ";// Goc Phai tren cung
													// Duoi
	gotoxy(ToaDoX, Rong + ToaDoY); cout << " ";// Goc Trai duoi cung
	gotoxy(Dai + ToaDoX, Rong + ToaDoY); cout << " ";// Goc Phai duoi cung
														   // In Dong Ngang:
	for (int i = 1; i<Dai; i++) {
		gotoxy(i + ToaDoX, ToaDoY); cout << " ";//Tren
		gotoxy(i + ToaDoX, Rong + ToaDoY); cout << " ";//Duoi
	}// for Dong
	 // In Cot Dung:
	for (int i = 1; i<Rong; i++) {
		gotoxy(ToaDoX, i + ToaDoY); cout << " ";// Cot Trai
		gotoxy(Dai + ToaDoX, i + ToaDoY); cout << " ";// Cot Phai
	}// for Cot
}

//------Class List Proccessing-------

Lop *searchClass(dslop ds, char *x)
{
	int i;
	Lop *result;
	for(i = 0; i < ds.n && stricmp(x, ds.lop[i].MALOP) != 0; ++i);
	return (i==ds.n?result=NULL:result=&ds.lop[i]);
}

void addClass(dslop &ds, Lop Class)
{
	int i;
	for (i = 0; i < ds.n; ++i)
	{
		if(stricmp(Class.MALOP, ds.lop[i].MALOP) > 0)
		{
			moveOut(ds, i);
			ds.lop[i + 1] = Class;
			break;
		}
	}
	if(i == ds.n)		//Cuoi danh sach
	{
		moveOut(ds, -1);
		ds.lop[0] = Class;
	}
}

void moveOut(dslop &ds, int i)
{
	int x, y;
	for(int j = ds.n; j > i + 1; --j)
	{
		ds.lop[j] = ds.lop[j - 1];
	}
	++ds.n;
}

void saveClassList(dslop ds, char *filename)
{
	ofstream ofs;
	int i;
	ofs.open(filename, ios_base::out);
	ofs << ds.n << endl;
	for(i = 0; i < ds.n; ++i)
		ofs << ds.lop[i].MALOP << " " << ds.lop[i].TENLOP << endl;
	ofs.close();
}

void loadClassList(dslop &ds, char *filename)
{
	ifstream ifs;
	int i;
	ifs.open(filename, ios_base::in);
	if(ifs.fail() == true)
		cout << "Ten file chua dung" << endl;
	ifs >> ds.n;
	for(i = 0; i < ds.n; ++i)
		ifs >> ds.lop[i].MALOP >> ds.lop[i].TENLOP;
	ifs.close();
}

void printClassList(dslop ds)
{
	
	int i;
	int y=wherey();
	gotoxy(5, y);
	cout << "STT";
	gotoxy(20, y);
	cout << "Ten lop";
	gotoxy(45, y);
	cout << "Ma lop" << endl;
	for (i = 0; i < ds.n; ++i)
	{
		if(i < 10)
			gotoxy(6, wherey());
		else
			gotoxy(5, wherey());
		cout << i + 1;
		gotoxy(13, wherey());
		cout << ds.lop[i].TENLOP;
		gotoxy(43, wherey());
		cout << ds.lop[i].MALOP<<endl;
	}
}

void deleteClass(dslop &ds, Lop Class)
{
	for(int i = 0; i < ds.n; ++i)
	{
		if(stricmp(ds.lop[i].MALOP, Class.MALOP) == 0)
		{
			moveToLast(ds, i);
			break;
		}
	}
	--ds.n;
}
void moveToLast(dslop &ds, int i)
{
	Lop Class;
	for(; i < ds.n - 1; ++i)
	{
		Class = ds.lop[i];
		ds.lop[i] = ds.lop[i+1];
		ds.lop[i+1] = Class;
	}
}

//------Clear Lists------
void clearList(PTRSV &First)
{
	PTRSV p;
	while(First != NULL)
	{
		p = First;
		clearList(First->Firstdiem);
		First = First->next;
		delete p;
	}
}
void clearList(PTRD &First)
{
	PTRD p;
	while(First != NULL)
	{
		p = First;
		First = First->next;
		delete p;
	}
}
void clearList(PTRMH &First)
{
	PTRMH p;
	while(First != NULL)
	{
		p = First;
		First = First->next;
		delete p;
	}
}
void clearList(dslop &ds)
{
	for(int i = 0; i < ds.n; ++i)
	{
		clearList(ds.lop[i].Firstsv);
	}
	delete ds.lop;
}
void xoadong_d(int y, int n_row)
{
	int i=0;
	gotoxy (0,y);
	for(i=0;i<n_row;i++)
	{
		cout<<"                                                                     "<<endl;
	}
	gotoxy (0,y);
}
void saveQuestList(PTRQ root, char *filename)
{
	PTRQ Stack[STACKSIZE];
   	PTRQ p=root;
   	int maxnode = countNode(root);
   	int sp=-1;	// Khoi tao Stack rong
   	ofstream ofs;
   	ofs.open(filename, ios_base::out);
	ofs << maxnode << endl;
   	do
   	{ 
	   	while(p != NULL)
		{	
			Stack[++sp]= p;
	 		p = p->left;
      	}
      	if (sp != -1)
      	{
			p = Stack[sp--];
			ofs << p->id << endl;
			ofs << p->info.mamh << endl;
			ofs << p->info.noidung << endl;
			ofs << p->info.A << endl;
			ofs << p->info.B << endl;
			ofs << p->info.C << endl;
			ofs << p->info.D << endl;
			ofs << p->info.dapan << endl;
			p = p->right;
      	}
      	else 
			break;
   }while(1);
   ofs.close();
}
