#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//Cau truc Danh muc xe
struct Xe
{
	char BienSo[20];
	char TenXe[20];
	char NgayDangKiem[15];
	float GiaThue;//Giá thuê 1 ngày
};

//C?u trúc khách hàng 
struct KhachHang
{
	char MaKH[20];
	char HoTen[30];
	char NgaySinh[30];
	char SDT[30];
	char SoCCCD[30];
};
//Struct cho thuê xe
struct ThueXe
{
	char MaKH[20];
	char BienSo[20];
	char NgayThue[15];
	char NgaytTraDuKien[15];
	char NgayTraThucTe[15];
};
//Node và SList cho danh muc xe 
struct SNode_Xe
{
	Xe Info;
	SNode_Xe* Next;
};
struct SList_Xe
{
	SNode_Xe* Head;
	SNode_Xe* Tail;
};
//SNode và SList cho Khách Hàng 
struct SNode_KH
{
	KhachHang Info;
	SNode_KH* Next;
};
struct SList_KH
{
	SNode_KH* Head;
	SNode_KH* Tail;
};
//SNode và SList cho Thuê xe
struct SNode_ThueXe
{
	ThueXe Info;
	SNode_ThueXe* Next;
};
struct Slist_ThueXe
{
	SNode_ThueXe* Head;
	SNode_ThueXe* Tail;
};
//Các hàm c? b?n 
//Kh?i t?o hàm
template<typename SList >//Dùng để làm việc với nhìu kiểu dư liệu khác nhau
void initSList(SList& sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}
//Kiểm tra danh sách rỗng
template<typename SList>
int isEmpty(SList sl)
{
	if (sl.Head == NULL)
		return 1;//danh sách rỗng
	else
		return 0;//Danh sách có ít nhất 1 phân tử 
}
// Các hàm dành cho Danh mục xe
SNode_Xe* createSNode_DanhMucXe(Xe x)
{
	SNode_Xe* p = new SNode_Xe;
	if (p == NULL)
	{
		printf("\nLoi cap phat bo nho!");
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
//======================================================================
int insertTail_DanhMucXe(SList_Xe& sl, SNode_Xe* p)
{
	if (p == NULL) return 0;
	if (isEmpty(sl))
	{
		sl.Head = sl.Tail = p;
	}
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;
}
//=========================================================================
void showItem_DanhMucXe(Xe &x)
{
	printf("%15s%20s%15s%10.2f", x.BienSo, x.TenXe, x.NgayDangKiem, x.GiaThue);
}
//==========================================================================
void showSList_DanhMucXe(SList_Xe sl)
{
	printf("\n%-5s%-15s%-20s%-15s%-10s", "STT", "Bien So", "Ten Xe", "Ngay Dang Kiem", "Gia Thue");
	int stt = 1;
	for (SNode_Xe* p = sl.Head; p != NULL; p = p->Next)
	{
		printf("\n%-5d", stt++);
		showItem_DanhMucXe(p->Info);
	}
}
// Các hàm dành cho Khách hàng
SNode_KH* createSNode_KhachHang(KhachHang x)
{
	SNode_KH* p = new SNode_KH;
	if (p == NULL)
	{
		printf("\nLoi cap phat bo nho!");
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
int insertTail_KhachHang(SList_KH& sl, SNode_KH* p)
{
	if (p == NULL) return 0;
	if (isEmpty(sl))
	{
		sl.Head = sl.Tail = p;
	}
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;
}
//===============================================================
void showItem_KhachHang(KhachHang &x)
{
	printf("%10s%20s%15s%15s%15s", x.MaKH, x.HoTen, x.NgaySinh, x.SDT, x.SoCCCD);
}
//===============================================================
void showSList_KhachHang(SList_KH sl)
{
	printf("\n%-5s%-10s%-20s%-15s%-15s%-15s%", "STT", "Ma KH", "Ho va Ten", "Ngay Sinh", "SDT", "CCCD");
	int stt = 1;
	for (SNode_KH* p = sl.Head; p != NULL; p = p->Next)
	{
		printf("\n%-5d", stt++);
		showItem_KhachHang(p->Info);
	}
}
// Các hàm dành cho Thuê xe
SNode_ThueXe* createSNode_ThueXe(ThueXe x)
{
	SNode_ThueXe* p = new SNode_ThueXe;
	if (p == NULL)
	{
		printf("\nLoi cap phat bo nho!");
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}
//===================================================
int insertTail_ThueXe(Slist_ThueXe& sl, SNode_ThueXe* p)
{
	if (p == NULL) return 0;
	if (isEmpty(sl))
	{
		sl.Head = sl.Tail = p;
	}
	else
	{
		sl.Tail->Next = p;
		sl.Tail = p;
	}
	return 1;
}

void showItem_ThueXe(ThueXe &x)
{
	printf("%10s%15s%15s%15s%15s", x.MaKH, x.BienSo, x.NgayThue, x.NgaytTraDuKien, x.NgayTraThucTe);
}
//======================================================
void showSList_ThueXe(Slist_ThueXe sl)
{
	printf("\n%-5s%-10s%-15s%-15s%-15s%-20s", "STT", "Ma KH", "Bien So", "Ngay Thue", "Ngay Tra Du Kien ", "Ngay Tra Thuc Te");
	int stt = 1;
	for (SNode_ThueXe* p = sl.Head; p != NULL; p = p->Next)
	{
		printf("\n%-5d", stt++);
		showItem_ThueXe(p->Info);
	}
}
//======================================================
void inputDanhMucXe_FromFile(FILE* fi, Xe& x)
{
	if (fi == NULL) return; // thêm kiểm tra
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%f\n", x.BienSo, x.TenXe, x.NgayDangKiem, &x.GiaThue);
}
void createSListDanhMucXe_FromTextFile(SList_Xe& sl, const char inputFilename[])
{
	initSList(sl);
	FILE* fi = fopen(inputFilename, "r");
	if (fi == NULL)
	{
		printf("Loi mo file %s", inputFilename);
		return;
	}
	int n;
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		Xe x;
		inputDanhMucXe_FromFile(fi, x);
		SNode_Xe* p = createSNode_DanhMucXe(x);
		insertTail_DanhMucXe(sl, p);
	}
	fclose(fi);
}
//=========================================================
void inputKhachHang_FromFile(FILE* fi, KhachHang& kh)
{
	if (fi == NULL) return;
	fscanf(fi, "%29[^#]%*c%29[^#]%*c%29[^#]%*c%29[^#]%*c%29[^\n]\n", &kh.MaKH, &kh.HoTen, &kh.NgaySinh, &kh.SDT, &kh.SoCCCD);
}
void createSListKhachHang_FromTextFile(SList_KH& sl, const char inputFilename[])
{
	initSList(sl);
	FILE* fi = fopen(inputFilename, "r");
	if (fi == NULL)
	{
		printf("Loi mo file %s", inputFilename);
		return;
	}
	int n;
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		KhachHang kh;
		inputKhachHang_FromFile(fi, kh);
		SNode_KH* p = createSNode_KhachHang(kh);
		insertTail_KhachHang(sl, p);
	}
	fclose(fi);
}
//========================================================
void inputThueXe_FromFile(FILE* fi, ThueXe& t)
{
	if (fi == NULL) return;
	fscanf(fi, "%[^#]%*c%[^#]%*c%[^#]%*c%[^#]%*c%[^\n]\n", t.MaKH, t.BienSo, t.NgayThue, t.NgaytTraDuKien, t.NgayTraThucTe);
}
void createSListThueXe_FromTextFile(Slist_ThueXe& sl, const char inputFilename[])
{
	initSList(sl);
	FILE* fi = fopen(inputFilename, "r");
	if (fi == NULL)
	{
		printf("Loi mo file %s", inputFilename);
		return;
	}
	int n;
	fscanf(fi, "%d\n", &n);
	for (int i = 0; i < n; i++)
	{
		ThueXe t;
		inputThueXe_FromFile(fi, t);
		SNode_ThueXe* p = createSNode_ThueXe(t);
		insertTail_ThueXe(sl, p);
	}
	fclose(fi);
}
//=====================================================================
void swap_KhachHang(KhachHang& a, KhachHang& b)
{
	KhachHang temp = a;
	a = b;
	b = temp;
}
int getNamSinh(char NgaySinh[])
{
	int ngay, thang, nam;
	sscanf(NgaySinh, "%d/%d/%d", &ngay, &thang, &nam);
	return nam;
}
void sort_KhachHang_GiamDan_TheoNamSinh(SList_KH& sl)
{
	for (SNode_KH* p = sl.Head; p != NULL; p = p->Next)
	{
		for (SNode_KH* q = p->Next; q != NULL; q = q->Next)
		{
			if (getNamSinh(p->Info.NgaySinh) < getNamSinh(q->Info.NgaySinh))
			{
				swap_KhachHang(p->Info, q->Info);
			}
		}
	}
}
//=========================================================
// Menu chương trình
void showMenu() {
	printf("\n================ MENU ================");
	printf("\n***********************************************");
	printf("\n*****CN0.  Thoat Chuong Trinh          *****\n");
	printf("*****CN1.  Du Lieu quan ly cho thue xe*****\n");
	printf("*****CN2.  Thoat chuong trinh          *****\n");
	printf("*****CN3.  Hahaha                     *****\n");
	printf("\n***********************************************");
	printf("\n======================================");
}
void process()
{
	FILE* fi;
	int select,choice;
	SList_Xe SListDanhMucXe;
	SList_KH SListkh;
	Slist_ThueXe SListThue;

	initSList(SListDanhMucXe);
	initSList(SListkh);
	initSList(SListThue);

	do {
		showMenu();
		printf("\nNhap lua chon: ");
		scanf("%d", &select);
		switch (select)
		{
		case 0:
			printf("Thoat chuong trinh...\n");
			break;
		case 1:
			do{
				printf("\n 1. Danh muc xe:");
				printf("\n 2. Khach hang:");
				printf("\n 3. Thue xe:");
				printf("\n 0. Quay lai menu chinh");
				printf("\n Nhap lua chon: ");
				scanf("%d", &choice);
			switch (choice)
			{
			
			case 1:
				createSListDanhMucXe_FromTextFile(SListDanhMucXe, "danhmucxe.txt.txt");
				printf("\nDoc danh sach danh muc xe thanh cong!");
				showSList_DanhMucXe(SListDanhMucXe); // Hiển thị luôn
				break;
			case 2:
				createSListKhachHang_FromTextFile(SListkh, "khachhang.txt.txt");
				printf("\nDoc danh sach khach hang thanh cong!");
				showSList_KhachHang(SListkh);
				break;
			case 3:
				createSListThueXe_FromTextFile(SListThue, "thuexe.txt.txt");
				printf("\nDoc danh sach thue xe thanh cong!");
				showSList_ThueXe(SListThue);
				break;
			case 0:
				printf("Quay ve menu chinh...\n");
				break;
			default:
				printf("Lua chon khong hop le!\n");
				}
			}while (choice != 0);
			break;
		case 2:
			printf("\n");
			break;
		default:
			printf("\nLua chon khong hop le, vui long nhap lai!");
			break;
		}
	} while (select != 0);
}

// Main
int main()
{
	process();
	return 0;
}