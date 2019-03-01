#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <mylib.h>
#include "config.h"
#include "Mylib.h"
#include "Function_TTN.h"
#include <cmath>
#include <time.h>
using namespace std;
int main()
{
	dslop ds;
	ds.n = 5;
	ds.lop = new Lop[ds.n];
	PTRMH dsmh, result;
	PTRMH mh;
	PTRQ root = NULL, sq;
	PTRSV sv;
	PTRCT FirstMT = NULL,sCT;
	int x1=0, y1=0;
	loadWork(ds, "D15CQPU01.txt", dsmh, root, FirstMT);

	char *x = new char[100];
	char *x2= new char[100]; 
	char *masv=new char[10];
	char *filename=new char[100];
	int check, check1, choice, choice1, choice2, choice3,choice5, ids;
	Lop temp, *slop, *smh;
	sinhvien temp_sv;
	monhoc temp_mh;
	cauhoi temp_ch;
	char cf;
	check = DangNhap(ds,sv);
	if(check == 0)
		cout << "Cam on ban da su dung chuong trinh!!" << endl;
	else if(check == 2)				//Giao vien
	{
		cout << "Dang nhap thanh cong ...!!" << endl;
		//Sleep(2000);
		while(1)
		{
			choice = MenuDong(menuGV);
			Normal();
			system("cls");
			if(choice == 8 || choice == 0)
			{
				cout << "Cam on ban da sung dung chuong trinh!" << endl;
				break;
			}
			switch(choice)
			{
				case 1:						//Thao tac lop
					while(1)
					{
						choice1 = MenuDong(menu1);
						Normal();
						system("cls");
						if(choice1 == 0 || choice1 == 5)
							break;
						switch(choice1)
						{
							case 1:	// them lop
								cout<<"\t\t=============Them lop=============\n";
								check1_1:			//Them lop
								if (ds.n == MAXLOP)
								{
									cout << ER_FULL_LIST << endl;
									Sleep(1500);
									break;
								}
								while(1)
								{
									cout << "Nhap ma lop muon them: ";
									check = NhapMa(x, 10);
									viethoa(x);
									if(check == ESC)
									{
										check = checkEsc(x);
										if (check==BREAK)
											break;
										else if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t=============Them lop=============\n";
											continue;
										}
									}
									else if(check == ENTER)
									{
										//Code tim kiem kiem tra ma lop da ton tai hay chua
										slop=searchClass(ds, x);
										if (slop==NULL)
										{
											strcpy(temp.MALOP,x);
											check_tenlop1:
											cout << "Nhap ten lop: ";
											check = NhapChuoi(x, 100);
											if (check==ESC)
											{
												check = checkEsc(x);
												if (check==BREAK)
													break;
												else if (check==CONTINUE)
												{
													goto check_tenlop1;
													continue;
												}
											}
											else if (check==ENTER)
											{
												strcpy(temp.TENLOP,x);
												addClass(ds, temp);
												BaoLoi("Them lop thanh cong");
												system("cls");
												cout<<"\t\t=============Them lop=============\n";
												goto check1_1;
												continue;
											}
										}
										else
										{
											BaoLoi("Ma lop da ton tai. Xin kiem tra lai!");
											system("cls");
											cout<<"\t\t=============Them lop=============\n";
											goto check1_1;
										}
									}
									
								}
								break;
							case 2:				//Sua lop
								cout<<"\t\t=============Sua lop=============\n";
								cout<<"\t----------------Danh sach cac lop----------------\n";
								printClassList(ds);
								cout<<"----------------------------------------------------------\n";
								while(1)
								{	
									checknull2:
									cout << "Nhap ma lop muon sua: ";
									check = NhapMa(x, 10);
									viethoa(x);
									if(check == ESC)
									{
										check = checkEsc(x);
										if (check==BREAK)
											break;
										else if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t=============Sua lop=============\n";
											continue;
										}
									}
									else if(check == ENTER)
									{
										//Code tim kiem kiem tra ma lop da ton tai hay chua
										// tim kiem ma lop
										slop=searchClass(ds,x);
										if (slop!=NULL)
										{
											strcpy(temp.MALOP,x);
											check_tenlop2:
											cout << "Nhap ten lop: ";
											check = NhapChuoi(x, 100);
											if (check==ESC)
											{
												check = checkEsc(x);
												if (check==BREAK)
													break;
												else if (check==CONTINUE)
												{
													goto check_tenlop2;
													continue;
												}
											}
											else if (check==ENTER)
											{
												strcpy(slop->TENLOP,x);
												BaoLoi("Sua lop thanh cong");
												system("cls");
												cout<<"\t\t=============Sua lop=============\n";
												continue;
											}
										}
										else 
										{
											BaoLoi("Ma lop khong ton tai. Xin kiem tra lai!");
											system("cls");
											cout<<"\t\t=============Sua lop=============\n";
											goto checknull2;
										}
									}
									if(check == ESC)
									{
										if (checkEsc(x)==CONTINUE)
											continue;
										if (checkEsc(x)==BREAK)
											break;
									}
									else 	//check = ENTER
										strcpy(temp.TENLOP,x);	
								}
								break;
							case 3:				//Xoa lop
								cout<<"\t\t=============Xoa lop=============\n";
								cout<<"\t----------------Danh sach cac lop----------------\n";
								printClassList(ds);
								cout<<"----------------------------------------------------------\n";
								while(1)
								{
									checknull3:
									cout << "Nhap ma lop muon xoa: ";
									check = NhapMa(x, 10);
									viethoa(x);
									if(check == ESC)
									{
										check = checkEsc(x);
										if (check==BREAK)
											break;
										else if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t=============Xoa lop=============\n";
											continue;
										}
									}
									else if(check == ENTER)
									{
										//Code tim kiem kiem tra ma lop da ton tai hay chua
										// tim kiem ma lop
										slop=searchClass(ds,x);
										if (slop!=NULL)
										{
											cout<<"Ban co muon xoa tat ca sinh vien thuoc lop nay khong?(y/n) ";
											check=NhapMa(x,1);
											if (x[0]=='y'||x[0]=='Y')
											{
												//xoa sinh vien
												clearList(slop->Firstsv);
												deleteClass(ds, *slop);
												BaoLoi("Xoa lop thanh cong\n");
												system("cls");
												cout<<"\t\t=============Xoa lop=============\n";
												goto checknull3;
											}
											else if (x[0]=='n'||x[0]=='N')
												break;
											else
											{
												BaoLoi("Xac nhan khong phu hop. Xin kiem tra lai!");
												goto checknull3;
											}
										}
										else 
										{
											BaoLoi("Ma lop khong ton tai. Xin kiem tra lai!");
											system("cls");
											cout<<"\t\t=============Xoa lop=============\n";
											goto checknull3;
										}
									}
								}
								break;
							case 4:				//Xem danh sach lop
								cout<<"\t\t==============Danh sach cac lop==============\n";
								printClassList(ds);
								cout<<endl;
								system("pause");
								break;
						}
					}
					break;
				case 2:						//Dieu chinh danh sach sinh vien
					while(1)
					{
						choice2 = MenuDong(menu2);
						Normal();
						system("cls");
						if(choice2 == 0 || choice2 == 5)
							break;
						switch(choice2)
						{
							case 1:				//Them sinh vien
								cout<<"\t\t==============Them sinh vien==============\n";
								while(1)
								{
									checknull2_1:
									cout<<"Nhap ma lop: ";
									check= NhapMa(x, 10);
									viethoa(x);
									if(check == ESC)
									{
										check = checkEsc(x);
										if (check==BREAK)
											break;
										else if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t==============Them sinh vien==============\n";
											continue;
										}
									}
									else if(check == ENTER)
									{
										//Code tim kiem kiem tra ma lop, ma sv da ton tai hay chua
										slop=searchClass(ds,x);
										if (slop==NULL)
										{
											BaoLoi("Ma lop khong ton tai, xin liem tra lai!");
											cout<<"----------------------Danh sach cac lop-------------------\n";
											printClassList(ds);
											cout<<"----------------------------------------------------------\n";
											goto checknull2_1;
										}
										else 
										{	
											cout<<"-------------Danh sach sach sinh vien lop "<<slop->MALOP<<"-------------\n";
											selectionSort(slop->Firstsv);
											printStudentList(slop->Firstsv);
											cout<<"------------------------------------------------------------------------\n";
											check_masv_2_1:
											cout<<"Nhap ma sinh vien: ";
											check=NhapMa(x, 10);
										
											if(check == ESC)
												{
														check = checkEsc(x);
														if (check==BREAK)
															break;
														else if (check==CONTINUE)
														{
															goto check_masv_2_1;
															continue;
														}
												}
											else if (check==ENTER)//check = ENTER
											{
												sv=searchStudent(slop->Firstsv, x);
												if (sv==NULL)
												{
													check_ho1:
													strcpy(temp_sv.MASV, x);
													cout<<"Nhap ho sinh vien: ";
													check=NhapChuoi(x,51);
													if(check == ESC)
													{
															check = checkEsc(x);
															if (check==BREAK)
																break;
															else if (check==CONTINUE)
															{
																goto check_ho1;
																continue;
															}
													}
													else if (check==ENTER) 	//check = ENTER
															strcpy(temp_sv.HO,x);	
													check_ten1:
													cout<<"Nhap ten sinh vien: ";
													check=NhapChuoi(x,11);
													if(check == ESC)
													{
															check = checkEsc(x);
															if (check==BREAK)
																break;
															else if (check==CONTINUE)
															{
																goto check_ten1;
																continue;
															}
													}
													else if (check==ENTER) 	//check = ENTER
															strcpy(temp_sv.TEN,x);	
													check_pass1:
													cout<<"Nhap pass sinh vien: ";
													check=NhapMa(x, 8);
													if(check == ESC)
													{
															check = checkEsc(x);
															if (check==BREAK)
																break;
															else if (check==CONTINUE)
															{
																goto check_pass1;
																continue;
															}
													}
													else if (check==ENTER) 	//check = ENTER
															strcpy(temp_sv.password,x);	
													
													check_phai1:// nhap phai
													cout<<"Nhap phai sinh vien (Nam/Nu): ";
													check=NhapChuoi(x,3);
													viethoa(x);
													if(check == ESC)
													{
															check = checkEsc(x);
															if (check==BREAK)
																break;
															else if (check==CONTINUE)
															{
																goto check_phai1;
																continue;
															}
													}
													else if (check==ENTER) 	//check = ENTER
															strcpy(temp_sv.PHAI,x);	
													if ((stricmp(x,"NAM")!=0) && (stricmp(x,"NU")!=0))
													{
														BaoLoi("Gia tri dang nhap chi chua NAM hoac NU. Xin kiem tra lai");
														goto check_phai1;
													}
													insertOrder(slop->Firstsv,temp_sv);
													BaoLoi("Them sinh vien thanh cong");
													system("cls");
													cout<<"\t\t==============Them sinh vien==============\n";
													continue;
												}
												else
												{
													BaoLoi("Ma sinh vien da ton tai, xin kiem tra lai!");
													goto check_masv_2_1;
												}
											}
										} 	
									}
								}
								break;
							case 2:				//Sua sinh vien
							cout<<"\t\t==============Sua thong tin sinh vien==============\n";
							while(1)
							{	
								checknull2_2:
								cout << "Nhap ma lop: ";
								check = NhapMa(x, 10);
								viethoa(x);
								if(check == ESC)
								{
										check = checkEsc(x);
										if (check==BREAK)
											break;
										else if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t==============Sua thong tin sinh vien==============\n";
											goto checknull2_2;
											continue;
										}
								}
								else if(check == ENTER)
								{
									//Code tim kiem kiem tra ma lop da ton tai hay chua
									// tim kiem ma lop
									slop=searchClass(ds,x);
									//danh sach sv
									if (slop==NULL)
									{
										BaoLoi("Ma lop khong ton tai. Xin kiem tra lai!");
										cout<<"----------------------Danh sach cac lop-------------------\n";
										printClassList(ds);
										cout<<"----------------------------------------------------------\n";
										goto checknull2_2;
									}
									else 
									{	
										cout<<"-------------Danh sach sach sinh vien lop "<<slop->MALOP<<"-------------\n";
										selectionSort(slop->Firstsv);
										printStudentList(slop->Firstsv);
										cout<<"------------------------------------------------------------------------\n";
										check_masv_2_2:
										cout<<"Nhap ma sinh vien muon sua: ";
										check=NhapMa(x, 10);
										viethoa(x);
										if(check == ESC)
										{
											check = checkEsc(x);
											if (check==BREAK)
												break;
											else if (check==CONTINUE)
											{
												goto check_masv_2_2;
												continue;
											}
										}
										else if (check==ENTER)
										{
											sv=searchStudent(slop->Firstsv, x);
											if (sv!=NULL)
											{
												strcpy(temp_sv.MASV, x);
												check_ho_2_2:
												cout<<"Nhap ho sinh vien: ";
												check=NhapChuoi(x,51);
												if(check == ESC)
												{
														check = checkEsc(x);
														if (check==BREAK)
															break;
														else if (check==CONTINUE)
														{
															goto check_ho_2_2;
															continue;
														}
												}
												else if (check==ENTER) 	//check = ENTER
														strcpy(temp_sv.HO,x);	
												check_ten_2_2:
												cout<<"Nhap ten sinh vien: ";
												check=NhapChuoi(x,11);
												if(check == ESC)
												{
													check = checkEsc(x);
													if (check==BREAK)
														break;
													else if (check==CONTINUE)
													{
														goto check_ten_2_2;
														continue;
													}
												}
												else if (check==ENTER) 	//check = ENTER
														strcpy(temp_sv.TEN,x);	
												
												
												check_phai2:// nhap phai
												cout<<"Nhap phai sinh vien (Nam/Nu): ";
												check=NhapChuoi(x,3);
												if(check == ESC)
												{
													check = checkEsc(x);
													if (check==BREAK)
														break;
													else if (check==CONTINUE)
													{
														goto check_phai2;
														continue;
													}
												}
												else if (check==ENTER) 	//check = ENTER
												{
													if (stricmp(x,"NAM")!=0 &&stricmp(x,"NU")!=0)
													{
														BaoLoi("Gia tri dang nhap chi chua NAM hoac NU. Xin kiem tra lai");
														goto check_phai2;
													}
													else 
														strcpy(temp_sv.PHAI,x);	
												}
												cout<<"Ban co muon luu thong tin sinh vien khong?(y/n) ";
												check=NhapMa(x,2);
												if (x[0]=='y'||x[0]=='Y')
												{
													sv->info=temp_sv;
													BaoLoi("Sua thong tin sinh vien thanh cong");
													system("cls");
													cout<<"\t\t==============Sua thong tin sinh vien==============\n";
													continue;
												}
												else if (x[0]=='n'||x[0]=='N')
												{
													goto checknull2_2 ;
												}
												else 
												{
													cout<<"Xac nhan khong phu hop"<<endl;
													goto checknull2_2;
												}
											}
											else
											{
												BaoLoi("Khong tim thay ma sinh vien. Xin kiem tra lai");
												goto check_masv_2_2;
											}
										}
									}
								}
							}
								break;
							case 3:				//Xoa sinh vien
								cout<<"\t\t==============Xoa sinh vien==============\n";
								while(1)
								{	
									checknull2_3:
									cout << "Nhap ma lop: ";
									check = NhapMa(x, 10);
									viethoa(x);
									if(check == ESC)
									{
										check = checkEsc(x);
										if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t==============Xoa sinh vien==============\n";
											goto checknull2_3;
											continue;
										}
										if (check==BREAK)
											break;
									}
									else if(check == ENTER)
									{
										//Code tim kiem kiem tra ma lop da ton tai hay chua
										// tim kiem ma lop
										slop=searchClass(ds,x);
										if (slop==NULL)
										{
											BaoLoi("Ma lop khong ton tai. Xin kiem tra lai!");
											cout<<"----------------------Danh sach cac lop-------------------\n";
											printClassList(ds);
											cout<<"----------------------------------------------------------\n";
											
											goto checknull2_3;
										}
										else 
										{
											cout<<"-----------------Danh sach sach sinh vien lop "<<slop->MALOP<<"-----------------\n";
											selectionSort(slop->Firstsv);
											printStudentList(slop->Firstsv);
											cout<<"--------------------------------------------------------------------------------\n";
											check_masv_2_3:
											cout<<"Nhap ma sinh vien muon xoa: ";
											check=NhapMa(x, 10);
											viethoa(x);
											if(check == ESC)
											{
												check = checkEsc(x);
												if (check==BREAK)
													break;
												else if (check==CONTINUE)
												{
													goto check_masv_2_3;
													continue;
												}
											}
											else if (check==ENTER)
											{
												check=deleteStudent(slop->Firstsv,x);
												if (check==UNDONE)
													break;
												else if (check==COMPLETE)
												{
													cout<<"Ban da xoa thanh cong";
													system("cls");
													cout<<"\t\t==============Xoa sinh vien==============\n";
												}
												else if (check==FALSE)
												{
													BaoLoi("Khong tim thay ma sinh vien. Xin kiem tra lai");
													goto check_masv_2_3;
												}
											}
										}
									}
								}
								break;
							case 4:				//Xem danh sach sinh vien
								cout<<"\t\t==============Xem dsnh sach sinh vien==============\n";
								while(1)
								{
									checknull2_4:
									cout << "Nhap ma lop: ";
									check = NhapMa(x, 10);
									viethoa(x);
									if(check == ESC)
									{
										check = checkEsc(x);
										if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t==============Xem danh sach sinh vien==============\n";
											goto checknull2_4;
											continue;
										}
										if (check==BREAK)
											break;
									}
									else if(check == ENTER)
									{	
										//Code tim kiem kiem tra ma lop da ton tai hay chua
										// tim kiem ma lop
										slop=searchClass(ds,x);
										if (slop==NULL)
										{
											BaoLoi("Ma lop khong ton tai. Xin kiem tra lai!");
											system("cls");
											cout<<"\t\t==============Xem danh sach sinh vien==============\n";
											goto checknull2_4;
										}
										else 
										{
											system("cls");
											cout<<"\t\t==============Danh sach sach sinh vien lop "<<slop->MALOP<<"==============\n";
											selectionSort(slop->Firstsv);
											printStudentList(slop->Firstsv);
											system("pause");
										}
									}
								}
								break;
					}
				}
				break;
				case 3:						//Dieu chinh danh sach mon hoc
					while(1)
					{
						choice3 = MenuDong(menu3);
						Normal();
						system("cls");
						if(choice3 == 0 || choice3 == 5)
							break;
						switch(choice3)
						{
							case 1:	
								cout<<"\t\t==============Them mon hoc==============\n";
								check3_1:			//Them mon hoc
								while(1)
								{
									check_mh_3_1:
									cout << "Nhap ma mon hoc muon them: ";
									check = NhapMa(x, 10);
									viethoa(x);
									if(check == ESC)
									{
										check = checkEsc(x);
										if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t==============Them mon hoc==============\n";
											goto check_mh_3_1;		
											continue;
										}
										if (check==BREAK)
											break;
									}
									else if(check == ENTER)
									{
										//Code tim kiem kiem tra ma lop da ton tai hay chua
										mh=searchMaMH(dsmh,x);
										if (mh==NULL)
										{
											strcpy(temp_mh.MAMH,x);
											check_ten_mh_3_1:
											cout << "Nhap ten mon hoc: ";
											check = NhapChuoi(x, 100);
											if(check == ESC)
											{
												check = checkEsc(x);
												if (check==CONTINUE)
												{
													goto check_ten_mh_3_1;
													continue;
												}
												if (check==BREAK)
													break;
											}
											else if(check == ENTER)
											{
												strcpy(temp_mh.TENMH,x);
												insertFirst(dsmh,temp_mh);
												insertSQList(FirstMT,temp_mh);  
												BaoLoi(" Them mon hoc thanh cong");
												system("cls");
												cout<<"\t\t==============Them mon hoc==============\n";
												goto check3_1;
											}
										}
										else
										{
											BaoLoi("Ma mon hoc da ton tai. Xin kiem tra lai!");
											cout<<"-------------------Danh sach mon hoc-------------------\n";
											printSubjectList(dsmh);
											cout<<"-------------------------------------------------------\n";
											goto check3_1;
										}
									}
								}
								break;
							case 2:				//Sua mon hoc
								cout<<"\t\t==============Sua thong tin mon hoc==============\n";
								while(1)
								{	
									checknull3_2:
									cout << "Nhap ma mon hoc muon sua: ";
									check = NhapMa(x, 10);
									viethoa(x);
									if(check == ESC)
									{
										check = checkEsc(x);
										if (check==CONTINUE)
										{
											system ("cls");
											cout<<"\t\t==============Sua thong tin mon hoc==============\n";
											goto checknull3_2;
											continue;
										}
										if (check==BREAK)
											break;
									}
									else if(check == ENTER)
									{
										//Code tim kiem kiem tra ma lop da ton tai hay chua
										// tim kiem ma lop
										mh=searchMaMH(dsmh,x);
										if (mh!=NULL)
										{
											cout<<"-------------Chi tiet mon hoc "<<mh->info.TENMH<<"-------------\n";
											cout<<"Ma MH\t\tTen mon hoc"<<endl;
											cout<<mh->info.MAMH<<"\t\t"<<mh->info.TENMH<<endl;
											cout<<"---------------------------------------------------------------\n";
											strcpy(temp_mh.MAMH,x);
											check_ten_mh_3_2:
											cout << "Nhap ten mon hoc: ";
											check = NhapChuoi(x, 100);
											if(check == ESC)
											{
												check = checkEsc(x);
												if (check==CONTINUE)
												{
													goto check_ten_mh_3_2;
													continue;
												}
												if (check==BREAK)
													break;
											}
											else if(check == ENTER)
											{
											strcpy(temp_mh.TENMH, x);
											cout<<"Ban co muon luu thong tin mon hoc khong?(y/n)";
												check=NhapMa(x,2);
												if (x[0]=='y'||x[0]=='Y')
												{
													mh->info=temp_mh;
													BaoLoi("Sua thong tin mon hoc thanh cong");
													system ("cls");
													cout<<"\t\t==============Sua thong tin mon hoc==============\n";
													goto checknull3_2;
												}
												else if (x[0]=='n'||x[0]=='N')
												{
													break;
												}
												else 
												{
													BaoLoi("Xac nhan khong phu hop");
													goto checknull3_2;
												}
											}
											
										}
										else 
										{
											BaoLoi("Ma mon hoc khong ton tai. Xin kiem tra lai!");
											cout<<"-------------------Danh sach mon hoc-------------------\n";
											printSubjectList(dsmh);
											cout<<"-------------------------------------------------------\n";
											goto checknull3_2;
										}
									}
								}
								break;
							case 3:				//Xoa mon hoc
								cout<<"\t\t==============Xoa thong tin mon hoc==============\n";
								while(1)
								{
									checknull3_3:
									cout << "Nhap ma mon hoc muon xoa: ";
									check = NhapMa(x, 10);
									viethoa(x);
									if(check == ESC)
									{
										check = checkEsc(x);
										if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t==============Xoa thong tin mon hoc==============\n";
											goto checknull3_3;
											continue;
										}
										if (check==BREAK)
											break;
									}
									else if(check == ENTER)
									{
										//Code tim kiem kiem tra ma lop da ton tai hay chua
										// tim kiem ma lop
										mh=searchMaMH(dsmh,x);
										if (mh!=NULL)
										{
											cout<<"-------------Chi tiet mon hoc "<<mh->info.TENMH<<"-------------\n";
											cout<<"Ma MH\t\tTen mon hoc"<<endl;
											cout<<mh->info.MAMH<<"\t\t"<<mh->info.TENMH<<endl;
											cout<<"---------------------------------------------------------------\n";
											cout<<"Ban co muon xoa mon hoc nay khong?(y/n) ";
											check=NhapMa(x2,2);
											viethoa(x2);
											if (x2[0]=='Y')
											{
												check=deleteSubject(dsmh,x,FirstMT, root);
												//deleteSubjectNode(FirstMT,mh->info.MAMH);
												
												if(check==COMPLETE)
												{
													BaoLoi("Xoa mon hoc thanh cong");
													system("cls");
													cout<<"\t\t==============Xoa thong tin mon hoc==============\n";
													goto checknull3_3;
												}
												else if (check==FALSE)
													BaoLoi("Danh sach rong");
											}
											else if (x2[0]=='N')
												break;
											else
											{
												BaoLoi("Xac nhan khong phu hop.");
												goto checknull3_3;
											}
										}
										else 
										{
											BaoLoi("Ma mon hoc nay khong ton tai. Xin kiem tra lai");
											cout<<"-------------------Danh sach mon hoc-------------------\n";
											printSubjectList(dsmh);
											cout<<"-------------------------------------------------------\n";
											goto checknull3_3;
										}
									}
								}
								break;
							case 4:				//Xem danh mon hoc
								cout<<"\t\t================Danh sach mon hoc================\n";
								printSubjectList(dsmh);
								system("pause");
								break;
						}
					}
					break;
				case 4:						//Dieu chinh cau hoi thi trac nghiem
					while(1)
					{
						check_ch:
						system("cls");
						check = MenuDong(menu4);
						Normal();
						system("cls");
						if(check == 5 || check == 0)
							break;
						switch(check)
						{
							case 1:// them cau hoi
								cout<<"\t\t==============Them cau hoi==============\n";
								createAVLTree(root, dsmh, FirstMT);
								break;
							case 2:				//Sua cau hoi
								cout<<"\t\t==============Sua cau hoi==============\n";
								while(1)
								{	
									checknull4_2:
									cout<<"Nhap ma mon hoc: ";
									check=NhapMa(x,8);
									if (check==ESC)
									{
										check = checkEsc(x);
										if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t==============Sua cau hoi==============\n";
											goto checknull4_2;
											continue;
										}
										if (check==BREAK)
											break;
									}
									else
									{
										mh=searchMaMH(dsmh,x);
										if (mh==NULL)
										{
											BaoLoi("Ma mon hoc khong ton tai. Xin kiem tra lai");
											cout<<"-------------------Danh sach mon hoc-------------------\n";
											printSubjectList(dsmh);
											cout<<"-------------------------------------------------------\n";
											goto checknull4_2;
										}
										else
										{
											sCT=searchSCode(FirstMT,x);
											cout<<"\t\t--------Danh sach cau hoi thi mon "<<mh->info.TENMH<<"---------\n";
											printQuestList(root,sCT,mh->info);
											cout<<"-----------------------------------------------------------------\n";
											cout << "Nhap id cau hoi muon sua: ";
											check = NhapMa(x, 10);
											ids = atoi(x);
											if(check == ESC)
											{
												check = checkEsc(x);
												if (check==CONTINUE)
												{
													system("cls");
													cout<<"\t\t==============Sua cau hoi==============\n";
													goto checknull4_2;
													continue;
												}
												if (check==BREAK)
													break;
											}
											else if(check == ENTER)
											{
												// tim kiem ma mh
												
												sq = search(root, ids);
												if (sq != NULL)
												{
													
													
													check_nd_4_2:
													cout<<"Nhap noi dung cau hoi: ";
														check=NhapChuoi(x, 51);
														if(check == ESC)
														{
															check = checkEsc(x);
															if (check==CONTINUE)
															{
																goto check_nd_4_2;
																continue;
															}
															if (check==BREAK)
																break;
														}
														else if (check==ENTER) 	//check = ENTER
															temp_ch.noidung = x;
															
														check_lc_4_2_1:	
														cout<<"Nhap lua chon A: ";
														check=NhapChuoi(x,11);
														if(check == ESC)
														{
															check = checkEsc(x);
															if (check==CONTINUE)
															{
																goto check_lc_4_2_1;
																continue;
															}
															if (check==BREAK)
																break;
														}
														else if (check==ENTER) 	//check = ENTER
															temp_ch.A = x;	
															
														check_lc_4_2_2:
														cout<<"Nhap lua chon B: ";
														check=NhapMa(x, 8);
														if(check == ESC)
														{
															check = checkEsc(x);
															if (check==CONTINUE)
															{
																goto check_lc_4_2_2;
																continue;
															}
															if (check==BREAK)
																break;
														}
														else if (check==ENTER) 	//check = ENTER
															temp_ch.B = x;
														
														check_lc_4_2_3:
														cout<<"Nhap lua chon C: ";
														check=NhapMa(x, 8);
														if(check == ESC)
														{
															check = checkEsc(x);
															if (check==CONTINUE)
															{
																goto check_lc_4_2_3;
																continue;
															}
															if (check==BREAK)
																break;
														}
														else if (check==ENTER) 	//check = ENTER
															temp_ch.C = x;
														
														check_lc_4_2_4:
														cout<<"Nhap lua chon D: ";
														check=NhapMa(x, 8);
														if(check == ESC)
														{
															check = checkEsc(x);
															if (check==CONTINUE)
															{
																goto check_lc_4_2_4;
																continue;
															}
															if (check==BREAK)
																break;
														}
														else if (check==ENTER) 	//check = ENTER
															temp_ch.D = x;
														
														check_da_4_2:
														cout<<"Nhap dap an: ";
														check=NhapMa(x, 2);
														if(check == ESC)
														{
															check = checkEsc(x);
															if (check==CONTINUE)
															{
																goto check_da_4_2;
																continue;
															}
															if (check==BREAK)
																break;
														}
														else if (check==ENTER) 	//check = ENTER
															strcpy(temp_ch.dapan, x);
														checknu4_3:		
														cout<<"Ban co muon luu thay doi khong?(y/n)";
														check=NhapMa(x,2);
														if (x[0]=='y'||x[0]=='Y')
														{
															sq->info = temp_ch;
															BaoLoi("Chinh sua cau hoi thanh cong");
															system("cls");
															cout<<"\t\t==============Sua cau hoi==============\n";
														}
														else if (x[0]=='n'||x[0]=='N')
															break;
														else 
														{
															cout<<"Xac nhan khong phu hop"<<endl;
															goto checknu4_3;
														}
												}
												else 
												{
													BaoLoi("Id nhap vao khong ton tai. Xin kiem tra lai!");
													goto checknull4_2;
												}
										}
									}
									}
								}
								break;
							case 3:
								cout<<"\t\t==============Xoa cau hoi==============\n";
								while (1)
								{
									check_ma_mh_4_3:
									cout<<"Nhap ma mon hoc: ";
									check=NhapMa(x,8);
									if (check==ESC)
									{
										check = checkEsc(x);
										if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t===============Xoa cau hoi===============\n";
											goto check_ma_mh_4_3;
											continue;
										}
										if (check==BREAK)
											break;
									}
									else if (check==ENTER)
									{
											mh=searchMaMH(dsmh, x);
											// tim kiem cau hoi
											if (mh==NULL)
											{
												BaoLoi("Mon hoc khong ton tai. Xin kiem tra lai");
												cout<<"-------------------Danh sach mon hoc-------------------\n";
												printSubjectList(dsmh);
												cout<<"-------------------------------------------------------\n";
												goto check_ma_mh_4_3;
												continue;
											}
											else
											{
												sCT=searchSCode(FirstMT,x);
												cout<<"------------------Danh sach cau hoi thi mon"<<mh->info.TENMH<<"----------------------\n";
												printQuestList(root,sCT,mh->info);
												cout<<"--------------------------------------------------------------------------------------\n";
												
												checknull4_4:
												cout << "Nhap ID cau hoi muon xoa: ";
												check = NhapMa(x, 10);
												ids = atoi(x);
												if (check==ESC)
												{
													check = checkEsc(x);
													if (check==CONTINUE)
													{
														system("cls");
														cout<<"\t\t==============Xoa cau hoi==============\n";
														goto check_ma_mh_4_3;
														continue;
													}
													if (check==BREAK)
														break;
												}
												else if (check==ENTER)
												{
													sq = search(root, ids);
													sCT=searchSCode(FirstMT, mh->info.MAMH);
													if (sq != NULL)
													{
														cout<<"Ban co muon xoa cau hoi nay khong?(y/n) ";
														check=NhapMa(x,2);
														if (x[0]=='y'||x[0]=='Y')
														{
															
															removeAVLNode(root, ids);
															BaoLoi("Xoa cau hoi thanh cong!");
															system("cls");
															cout<<"\t\t==============Xoa cau hoi==============\n";
															goto check_ma_mh_4_3;
														}
														else if (x[0]=='n'||x[0]=='N')
															{
																goto checknull4_4;
															}
														else
														{
															BaoLoi("Xac nhan khong phu hop.");
															goto checknull4_4;
														}
													}
													else 
													{
														BaoLoi("ID cau hoi khong ton tai");
														goto checknull4_4;
													}
												}
											}
										}
									}	
								break;
							case 4: //xuat ds cau hoi
								cout<<"\t\t===============Xuat danh sach cau hoi===============\n";
								while(1)
								{
									check_ma_mh_4_4:
									cout<<"Nhap ma mon hoc: ";
									check=NhapMa(x,8);
									if (check==ESC)
									{
										check = checkEsc(x);
										if (check==CONTINUE)
										{
											system("cls");
											cout<<"\t\t===============Xuat danh sach cau hoi===============\n";
											goto check_ma_mh_4_4;
											continue;
										}
										if (check==BREAK)
											break;
									}
									else if (check==ENTER)
									{
										mh=searchMaMH(dsmh,x);
										if (mh==NULL)
										{
											BaoLoi("Ma mon hoc khong ton tai. Xin kiem tra lai");
											goto check_ma_mh_4_4;
										}
										else
										{
											sCT=searchSCode(FirstMT,x);
											if (sCT->info.n==0)
												BaoLoi("Mon hoc nay chua co cau hoi thi nao");
											else
											{
												printQuestList(root,sCT,mh->info);
												system("pause");
												system("cls");
												cout<<"\t\t===============Xuat danh sach cau hoi===============\n";
												goto check_ma_mh_4_4;
											}
												
										}
									}
								}
								break;
						}
					}
					break;
				case 5:						//Thi trac nghiem
//					createAVLTree(root);
					break;
				case 6:
					choice5 = MenuDong(menu5);
					Normal();
					system("cls");
					if(choice5 == 0 || choice5 == 5)
							break;
					switch(choice5)
					{
						case 1: // xuat ds lop
							check_file1:
							system("cls");
							cout<<"\t\t=============Xuat danh sach lop===========\n";
							cout<<"Nhap ten file can luu: ";
							check=NhapMa(filename,100);
							strcat(filename,".txt");
							if (check==ESC)
							{
								check = checkEsc(x);
								if (check==CONTINUE)
								{
									goto check_file1;
									continue;
								}
								if (check==BREAK)
									break;
							}
							else
							{
								
								saveClassList(ds, filename);
								BaoLoi("Xuat file thanh cong");
								goto check_file1;
							}
							break;
						case 2: //xuat ds sinh vien theo lop
							check_file2:
							system("cls");
							cout<<"\t\t=============Xuat danh sach sinh vien theo lop===========\n";
							cout<<"Nhap ten file can luu: ";
							check=NhapMa(filename,100);
							strcat(filename,".txt");
							if (check==ESC)
							{
								check = checkEsc(x);
								if (check==CONTINUE)
								{
									goto check_file2;
									continue;
								}
								if (check==BREAK)
									break;
							}
							else
							{
								cout<<"\t--------------------Danh sach cac lop-------------------\n";
								printClassList(ds);
								cout<<"----------------------------------------------------------\n";
								check_ma_lop:
								cout<<"Nhap ma lop: ";
								check=NhapMa(x,10);
								if (check==ESC)
								{
									check = checkEsc(x);
									if (check==CONTINUE)
									{
										goto check_ma_lop;
										continue;
									}
									if (check==BREAK)
										break;
								}
								else
								{
									slop=searchClass(ds,x);
									if (slop==NULL)
									{
										BaoLoi("Ma lop khong ton tai. Xin kiem tra lai!");
										goto check_ma_lop;
									}
									else
									{
										saveStudentList(*slop, filename);
										BaoLoi("Xuat file thanh cong");
										goto check_file2;
									}
								}
							}
							break;
						case 3: // xuat ds mon hoc
							check_file3:
							system("cls");
							cout<<"\t\t=============Xuat danh sach mon hoc===========\n";
							cout<<"Nhap ten file can luu: ";
							check=NhapMa(filename,100);
							strcat(filename,".txt");
							if (check==ESC)
							{
								check = checkEsc(x);
								if (check==CONTINUE)
								{
									goto check_file3;
									continue;
								}
								if (check==BREAK)
									break;
							}
							else
							{
								saveSubjectList(dsmh,filename);
								BaoLoi("Xuat file thanh cong");
								goto check_file3;
							}
							break;
						case 4: // xuat ds cau hoi theo mon hoc
							check_file4:
							system("cls");
							cout<<"\t\t=============Xuat danh sach cau hoi thi theo mon hoc===========\n";
							cout<<"Nhap ten file can luu: ";
							check=NhapMa(filename,100);
							strcat(filename,".txt");
							if (check==ESC)
							{
								check = checkEsc(x);
								if (check==CONTINUE)
								{
									goto check_file4;
									continue;
								}
								if (check==BREAK)
									break;
							}
							else
							{
								cout<<"\t--------------------Danh sach cau thi theo mon hoc-------------------\n";
								printSubjectList(dsmh);
								cout<<"----------------------------------------------------------\n";
								check_ma_mh:
								cout<<"Nhap ma mon hoc: ";
								check=NhapMa(x,10);
								if (check==ESC)
								{
									check = checkEsc(x);
									if (check==CONTINUE)
									{
										goto check_ma_lop;
										continue;
									}
									if (check==BREAK)
										break;
								}
								else
								{
									mh=searchMaMH(dsmh,x);
									if (slop==NULL)
									{
										BaoLoi("Ma mon hoc khong ton tai. Xin kiem tra lai!");
										goto check_ma_mh;
									}
									else
									{
										sCT=searchSCode(FirstMT,mh->info.MAMH);
										saveSQList(root, sCT,filename);
										BaoLoi("Xuat file thanh cong");
										goto check_file4;
									}
								}
							}
							break;
					}
					break;
				case 7:// in ds diem theo mon hoc cua tung lop
					cout<<"\t\t==========Danh sach diem theo mon hoc==========\n";
					while (1)
					{
						check_ma_mh_7:
						cout<<"Nhap ma mon hoc: ";
						check=NhapMa(x,8);
						if (check==ESC)
						{
							check=checkEsc(x);
							if (check==CONTINUE)
								{
									system("cls");
									cout<<"\t\t==========Danh sach diem theo mon hoc==========\n";
									goto check_ma_mh_7;
								}
							else if (check==BREAK)
								break;
						}
						else if (check==ENTER)
						{
							mh=searchMaMH(dsmh,x);
							if (mh==NULL)
							{
								BaoLoi("Mon hoc khong ton tai. Xin kiem tra lai");
								system("cls");
								cout<<"\t\t==========Danh sach diem theo mon hoc==========\n";
								goto check_ma_mh_7;
							}
							else
							{
								check_ma_lop_7:
								cout<<"Nhap ma lop: ";
								check=NhapMa(x,10);
								if (check==ESC)
								{
									check=checkEsc(x);
									if (check==CONTINUE)
										goto check_ma_lop_7;
									else if (check==BREAK)
										break;
								}
								else if (check==ENTER)
								{
									slop=searchClass(ds,x);
									if (slop==NULL)
									{
										BaoLoi("Ma lop khong ton tai, xin kieam tra lai");
										goto check_ma_lop_7;
									}
									else
									{
										printMarkSubject(*slop,mh->info);
										system("pause");
										system("cls");
										cout<<"\t\t==========Danh sach diem theo mon hoc==========\n";
										goto check_ma_mh_7;
									}
								}
							}
						}
					}
					break;
				case 8:
					break;
				
			}
		}
	}
	else if(check == 1)				//Sinh vien
	{
		char *rep;
		int socauthi=0;
		int n_max=0;
		float point = 0;
		char *dapan;
		char *check_ans;
		int *cauthi;
		float donvi=0;
		clock_t  start,end;
		while(1)
		{
			check_ttn:
			system("cls");
			cout<<"=================THI TRAC NGHIEM=================\n";
			cout<<"Nhap ma mon hoc: ";
			check1=NhapMa(x,8);
			if (check1==ESC)
			{
				if (check==CONTINUE)
				{
					goto check_ttn;
					continue;
				}
				if (check==BREAK)
					break;
			}
			else if (check1==ENTER)
			{
				mh=searchMaMH(dsmh,x);
				sCT=searchSCode(FirstMT,mh->info.MAMH);
				if (sCT==NULL)
					BaoLoi("Mon hoc nay chua co cau hoi nao");
				else 
				{
					n_max=sCT->info.n;
					if (mh==NULL)
					{
						BaoLoi("Ma mon hoc khong ton tai. Xin kiem tra lai");
						goto check_ttn;
					}
					else 
					{
						check_so_ct:
						cout<<"Nhap so cau thi: ";
						cin>>socauthi;
						if (socauthi<=0 || socauthi>n_max)
						{
							x1 = wherex(); y1 = wherey();
							gotoxy(40, y1+3);
							cout<<"So cau thi phai lon hon 0 va nho hon "<<n_max;
							Sleep(2000);
							gotoxy(40, y1+3);
							cout <<"                                                                ";
							gotoxy(x1 , y1 );
							goto check_so_ct;
						}
						donvi = 10 * 1.0 / socauthi; 
						cauthi = generateTest(FirstMT->info, socauthi);
						BaoLoi("Bat dau thi");
						start=clock();
						rep = printTest(root, cauthi, socauthi);
						for(int i = 0; i < socauthi; ++i)
						{
							check_ans = search(root, cauthi[i])->info.dapan;
							if(check_ans[0] == rep[i])
							point += donvi;
						}
						Normal();
						system("cls");
						cout << round(point)<< endl;
						break;
					}
				}
			}
		}
		delete rep;
		delete cauthi;
	}
	delete x;
	delete x2;
	clearTree(root);
	clearList(ds);
	clearList(dsmh);
	clearSubjectQuest(FirstMT);
	system("pause");
	return 0;
}

// string::pop_back

