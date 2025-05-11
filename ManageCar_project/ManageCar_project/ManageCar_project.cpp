#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>


typedef struct {
	int day;
	int month;
	int year;
} Date;

struct Xe {
	char BienSo[20];
	char TenXe[20];
	Date NgayDangKiem;
	float GiaThue;
};

struct KhachHang {
	char MaKH[20];
	char HoTen[30];
	Date NgaySinh;
	char SDT[30];
	char SoCCCD[30];
};

struct ThueXe {
	char MaDon[20];
	char MaKH[20];
	char BienSo[20];
	Date NgayThue;
	Date NgayTraDuKien;
	Date NgayTraThucTe;
	char TrangThai[20];//1.Da tra 2.Dang cho thue
};


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
template<typename SList >//Dùng để làm việc với nhìu kiểu dư liệu khác nhau
void initSList(SList& sl)
{
	sl.Head = NULL;
	sl.Tail = NULL;
}

template<typename SList>
int isEmpty(SList sl)
{
	if (sl.Head == NULL)
		return 1;
	else
		return 0;
}
void printDate(Date d) {
	printf("%02d/%02d/%04d", d.day, d.month, d.year);
}

void readDate(Date* d) {
	scanf("%d/%d/%d", &d->day, &d->month, &d->year);
}
void printHeader_DanhMucXe() {
	printf("\n%-5s%-15s%-20s%-20s%-10s",
		"STT", "BienSo", "Ten Xe", "Ngay Dang Kiem", "Gia Thue");
}

void printHeader_KhachHang() {
	printf("\n%-5s%-10s%-25s%-20s%-10s%-10s%",
		"STT", "MaKH", "Ho va Ten", "Ngay Sinh", "SDT", "CCCD");
}

void printHeader_ThueXe() {
	printf("\n%-5s%-10s%-10s%-15s%-15s%-15s%-15s%-15s",
		"STT", "MaDon", "MaKH", "Bien So",
		"Ngay Thue", "Ngay Tra DK", "Ngay Tra TT", "Trang Thai");
}

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
void showItem_DanhMucXe(Xe& x) {
	printf("%0s   %-15s", x.BienSo, x.TenXe);
	printf("%-10s", " ");printDate(x.NgayDangKiem);
	printf("%20.2f", x.GiaThue);
}
void showSList_DanhMucXe(SList_Xe sl) {
	printHeader_DanhMucXe();
	int stt = 1;
	for (SNode_Xe* p = sl.Head; p; p = p->Next) {
		printf("\n%-5d", stt++);
		showItem_DanhMucXe(p->Info);
	}
}
void inputDanhMucXe_FromFile(FILE* fi, Xe& x) {
	if (!fi) return;

	fscanf(fi, "%[^#]%*c%[^#]%*c", x.BienSo, x.TenXe);

	fscanf(fi, "%d/%d/%d%*c%f\n",
		&x.NgayDangKiem.day,
		&x.NgayDangKiem.month,
		&x.NgayDangKiem.year,
		&x.GiaThue);
}

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

void showItem_KhachHang(KhachHang& x) {
	printf("%0s  %-19s", x.MaKH, x.HoTen);
	printf("%-8s", " "); printDate(x.NgaySinh);
	printf(" %15s %15s", x.SDT, x.SoCCCD);
}
void showSList_KhachHang(SList_KH sl) {
	printHeader_KhachHang();
	int stt = 1;
	for (SNode_KH* p = sl.Head; p; p = p->Next) {
		printf("\n%-5d", stt++);
		showItem_KhachHang(p->Info);
	}
}

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

void showItem_ThueXe(ThueXe& x) {
	printf("%0s%10s%15s", x.MaDon, x.MaKH, x.BienSo);
	printf("%5s", " "); printDate(x.NgayThue);
	printf("%5s", " "); printDate(x.NgayTraDuKien);
	printf("%5s", " "); printDate(x.NgayTraThucTe);
	printf("     %-30s", x.TrangThai);
}

void showSList_ThueXe(Slist_ThueXe sl) {
	printHeader_ThueXe();
	int stt = 1;
	for (SNode_ThueXe* p = sl.Head; p; p = p->Next) {
		printf("\n%-5d", stt++);
		showItem_ThueXe(p->Info);
	}
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

void inputKhachHang_FromFile(FILE* fi, KhachHang& kh) {
	if (!fi) return;
	fscanf(fi,
		"%19[^#]#%29[^#]#%d/%d/%d#%29[^#]#%29[^\n]\n",
		kh.MaKH,
		kh.HoTen,
		&kh.NgaySinh.day,
		&kh.NgaySinh.month,
		&kh.NgaySinh.year,
		kh.SDT,
		kh.SoCCCD);
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

void inputThueXe_FromFile(FILE* fi, ThueXe& t) {
	if (!fi) return;
	fscanf(fi,
		"%19[^#]#%19[^#]#%19[^#]#%d/%d/%d#%d/%d/%d#%d/%d/%d#%19[^\n]\n",
		t.MaDon,
		t.MaKH,
		t.BienSo,
		&t.NgayThue.day, &t.NgayThue.month, &t.NgayThue.year,
		&t.NgayTraDuKien.day, &t.NgayTraDuKien.month, &t.NgayTraDuKien.year,
		&t.NgayTraThucTe.day, &t.NgayTraThucTe.month, &t.NgayTraThucTe.year,
		t.TrangThai);
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
void swap_KhachHang(KhachHang& a, KhachHang& b)
{
	KhachHang temp = a;
	a = b;
	b = temp;
}
int getNamSinh(const KhachHang& kh) {
	return kh.NgaySinh.year;
}
void sort_KhachHang_GiamDan_TheoNamSinh(SList_KH& sl)
{
	for (SNode_KH* p = sl.Head; p; p = p->Next) {
		for (SNode_KH* q = p->Next; q; q = q->Next) {
			if (p->Info.NgaySinh.year < q->Info.NgaySinh.year) {
				swap_KhachHang(p->Info, q->Info);
			}

		}
	}
}
//Chuyen doi chuoi thanh so nguyen
int getSoTuMaKH(const char* maKH) {
	return atoi(maKH + 2);
}

//tăng dần
void sort_KhachHang_TheoMaKH(SList_KH& sl) {
	for (SNode_KH* p = sl.Head; p; p = p->Next) {
		for (SNode_KH* q = p->Next; q; q = q->Next) {
			if (getSoTuMaKH(p->Info.MaKH) > getSoTuMaKH(q->Info.MaKH)) {
				swap_KhachHang(p->Info, q->Info);
			}
		}
	}
}


// 1) Nhập Xe từ bàn phím
void inputDanhMucXe_FromKeyboard(Xe& x) {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
	printf("Nhap BienSo: ");
	fgets(x.BienSo, sizeof x.BienSo, stdin);
	x.BienSo[strcspn(x.BienSo, "\n")] = 0;

	printf("Nhap TenXe: ");
	fgets(x.TenXe, sizeof x.TenXe, stdin);
	x.TenXe[strcspn(x.TenXe, "\n")] = 0;

	printf("Nhap NgayDangKiem (dd/mm/yyyy): ");
	readDate(&x.NgayDangKiem);

	printf("Nhap GiaThue: ");
	scanf("%f", &x.GiaThue);
}

// 2) Thêm Xe và cập nhật file
void addDanhMucXe_UpdateCount(SList_Xe& sl, const char filename[]) {
	createSListDanhMucXe_FromTextFile(sl, filename);
	FILE* fi = fopen(filename, "r");
	int n = 0;
	if (fi) { fscanf(fi, "%d", &n); fclose(fi); }

	Xe x; inputDanhMucXe_FromKeyboard(x);
	insertTail_DanhMucXe(sl, createSNode_DanhMucXe(x));

	n++;

	FILE* fo = fopen(filename, "w");
	if (!fo) { printf("Loi mo file %s de ghi!\n", filename); return; }
	fprintf(fo, "%d\n", n);
	for (SNode_Xe* p = sl.Head; p; p = p->Next) {
		fprintf(fo,
			"%s#%s#%02d/%02d/%04d#%.2f\n",
			p->Info.BienSo,
			p->Info.TenXe,
			p->Info.NgayDangKiem.day,
			p->Info.NgayDangKiem.month,
			p->Info.NgayDangKiem.year,
			p->Info.GiaThue
		);
	}
	fclose(fo);
	printf("Da them xe va cap nhat file (%d ban ghi)\n", n);
}


// 3) Nhập KhachHang từ bàn phím
void inputKhachHang_FromKeyboard(KhachHang& kh) {
	int c; while ((c = getchar()) != '\n' && c != EOF);
	printf("Nhap MaKH: ");
	fgets(kh.MaKH, sizeof kh.MaKH, stdin);
	kh.MaKH[strcspn(kh.MaKH, "\n")] = 0;

	printf("Nhap HoTen: ");
	fgets(kh.HoTen, sizeof kh.HoTen, stdin);
	kh.HoTen[strcspn(kh.HoTen, "\n")] = 0;

	printf("Nhap NgaySinh (dd/mm/yyyy): ");
	readDate(&kh.NgaySinh);

	printf("Nhap SDT: ");
	fgets(kh.SDT, sizeof kh.SDT, stdin);
	kh.SDT[strcspn(kh.SDT, "\n")] = 0;
	while ((c = getchar()) != '\n' && c != EOF);
	printf("Nhap SoCCCD: ");
	fgets(kh.SoCCCD, sizeof kh.SoCCCD, stdin);
	kh.SoCCCD[strcspn(kh.SoCCCD, "\n")] = 0;
}

// 4) Thêm KhachHang và cập nhật file
void addKhachHang_UpdateCount(SList_KH& sl, const char filename[]) {
	createSListKhachHang_FromTextFile(sl, filename);
	FILE* fi = fopen(filename, "r");
	int n = 0;
	if (fi) { fscanf(fi, "%d", &n); fclose(fi); }

	KhachHang kh; inputKhachHang_FromKeyboard(kh);
	insertTail_KhachHang(sl, createSNode_KhachHang(kh));

	n++;

	FILE* fo = fopen(filename, "w");
	if (!fo) { printf("Loi mo file %s de ghi!\n", filename); return; }
	fprintf(fo, "%d\n", n);
	for (SNode_KH* p = sl.Head; p; p = p->Next) {
		fprintf(fo,
			"%s#%s#%02d/%02d/%04d#%s#%s\n",
			p->Info.MaKH,
			p->Info.HoTen,
			p->Info.NgaySinh.day,
			p->Info.NgaySinh.month,
			p->Info.NgaySinh.year,
			p->Info.SDT,
			p->Info.SoCCCD
		);
	}
	fclose(fo);
	printf("Da them khach hang va cap nhat file (%d ban ghi)\n", n);
}


// 5) Nhập ThueXe từ bàn phím
void inputThueXe_FromKeyboard(ThueXe& t) {
	int c;

	while ((c = getchar()) != '\n' && c != EOF);

	printf("Nhap MaDon: ");
	fgets(t.MaDon, sizeof t.MaDon, stdin);
	t.MaDon[strcspn(t.MaDon, "\n")] = 0;

	printf("Nhap MaKH: ");
	fgets(t.MaKH, sizeof t.MaKH, stdin);
	t.MaKH[strcspn(t.MaKH, "\n")] = 0;

	printf("Nhap BienSo: ");
	fgets(t.BienSo, sizeof t.BienSo, stdin);
	t.BienSo[strcspn(t.BienSo, "\n")] = 0;

	printf("Nhap NgayThue (dd/mm/yyyy): ");
	readDate(&t.NgayThue);

	printf("Nhap NgayTraDuKien (dd/mm/yyyy): ");
	readDate(&t.NgayTraDuKien);

	printf("Nhap NgayTraThucTe (dd/mm/yyyy): ");
	readDate(&t.NgayTraThucTe);

	while ((c = getchar()) != '\n' && c != EOF);
	printf("Nhap TrangThai: ");
	fgets(t.TrangThai, sizeof t.TrangThai, stdin);
	t.TrangThai[strcspn(t.TrangThai, "\n")] = 0;

}


// 6) Thêm ThueXe và cập nhật file
void addThueXe_UpdateCount(Slist_ThueXe& sl, const char filename[]) {
	createSListThueXe_FromTextFile(sl, filename);
	FILE* fi = fopen(filename, "r");
	int n = 0;
	if (fi) { fscanf(fi, "%d", &n); fclose(fi); }

	ThueXe t;
	inputThueXe_FromKeyboard(t);
	insertTail_ThueXe(sl, createSNode_ThueXe(t));
	n++;

	FILE* fo = fopen(filename, "w");
	if (!fo) {
		printf("Loi mo file %s de ghi!\n", filename);
		return;
	}

	fprintf(fo, "%d\n", n);
	for (SNode_ThueXe* p = sl.Head; p; p = p->Next) {
		fprintf(fo,
			"%s#%s#%s#%02d/%02d/%04d#%02d/%02d/%04d#%02d/%02d/%04d#%s\n",
			p->Info.MaDon,
			p->Info.MaKH,
			p->Info.BienSo,
			p->Info.NgayThue.day, p->Info.NgayThue.month, p->Info.NgayThue.year,
			p->Info.NgayTraDuKien.day, p->Info.NgayTraDuKien.month, p->Info.NgayTraDuKien.year,
			p->Info.NgayTraThucTe.day, p->Info.NgayTraThucTe.month, p->Info.NgayTraThucTe.year,
			p->Info.TrangThai
		);
	}
	fclose(fo);
	printf("Da them thue xe va cap nhat file (%d ban ghi)\n", n);
}

void timTheoMaKH(const SList_KH& sl) {
	char key[20];
	printf("Nhap MaKH can tim: ");
	scanf("%19s", key);

	printHeader_KhachHang();
	int stt = 1, found = 0;
	for (SNode_KH* p = sl.Head; p; p = p->Next) {
		if (strcmp(p->Info.MaKH, key) == 0) {
			printf("\n%-5d", stt++);
			showItem_KhachHang(p->Info);
			found++;
		}
	}
	if (!found) printf("\nKhong tim thay MaKH %s!", key);
	printf("\n");
}

void timTheoHoTen(const SList_KH& sl) {
	char key[30];
	int c; while ((c = getchar()) != '\n' && c != EOF);
	printf("Nhap chuoi HoTen can tim: ");
	fgets(key, sizeof key, stdin);
	key[strcspn(key, "\n")] = 0;

	printHeader_KhachHang();
	int stt = 1, found = 0;
	for (SNode_KH* p = sl.Head; p; p = p->Next) {
		if (strstr(p->Info.HoTen, key)) {
			printf("\n%-5d", stt++);
			showItem_KhachHang(p->Info);
			found++;
		}
	}
	if (!found) printf("\nKhong tim thay HoTen chua \"%s\"!", key);
	printf("\n");
}

void timTheoNamSinh(const SList_KH& sl) {
	int year;
	printf("Nhap NamSinh can tim (yyyy): ");
	scanf("%d", &year);

	printHeader_KhachHang();
	int stt = 1, found = 0;
	for (SNode_KH* p = sl.Head; p; p = p->Next) {
		if (p->Info.NgaySinh.year == year) {
			printf("\n%-5d", stt++);
			showItem_KhachHang(p->Info);
			found++;
		}
	}
	if (!found) printf("\nKhong tim thay khach hang co NamSinh %d!", year);
	printf("\n");
}


void timKhachHangTheoBienSo(const SList_KH slKh, const Slist_ThueXe slThue) {
	char bienSoCanTim[20];
	printf("Nhap BienSo can tim khach hang: ");
	scanf("%19s", bienSoCanTim);

	printHeader_KhachHang();
	int stt = 1;

	// Duyệt từng khách hàng
	for (SNode_KH* pKh = slKh.Head; pKh; pKh = pKh->Next) {
		// Tìm xem khách này có đơn thuê với Biển số cần tìm
		for (SNode_ThueXe* pTh = slThue.Head; pTh; pTh = pTh->Next) {
			if (strcmp(pTh->Info.BienSo, bienSoCanTim) == 0
				&& strcmp(pTh->Info.MaKH, pKh->Info.MaKH) == 0) {
				// In và chuyển sang khách tiếp theo
				printf("\n%-5d", stt++);
				showItem_KhachHang(pKh->Info);
				break;
			}
		}
	}

	// Nếu không có STT nào tăng, nghĩa là không tìm thấy
	if (stt == 1) {
		printf("\nKhong tim thay khach hang nao thue xe BienSo %s!\n", bienSoCanTim);
	}
	printf("\n");
}


// Helper: chuyển Date -> time_t
static time_t _to_time_t(Date d) {
	struct tm tm = { 0 };
	tm.tm_mday = d.day;
	tm.tm_mon = d.month - 1;//tính từ tháng 1
	tm.tm_year = d.year - 1900;//tính từ năm 1900
	return mktime(&tm);
}

// Helper: trả về số ngày từ d1 đến d2 (có thể âm nếu d2 trước d1)
static int daysBetween(Date d1, Date d2) {
	time_t t1 = _to_time_t(d1);
	time_t t2 = _to_time_t(d2);
	return (int)(difftime(t2, t1) / (24 * 3600));
}

float tinhTienThue(const ThueXe& t, const SList_Xe& slXe) {
	float gia = 0;
	for (SNode_Xe* p = slXe.Head; p; p = p->Next) {
		if (strcmp(p->Info.BienSo, t.BienSo) == 0) {
			gia = p->Info.GiaThue;
			break;
		}
	}
	if (gia <= 0) {
		printf("Loi: Khong tim thay gia thue cho xe %s\n", t.BienSo);
		return 0;
	}

	if (strcmp(t.TrangThai, "Dang cho thue") == 0) {
		printf("Don %s hien dang cho thue, chua the tinh tien.\n", t.MaDon);
		return 0;
	}
	if (strcmp(t.TrangThai, "Da tra") != 0) {
		printf("Don %s co trang thai \"%s\", khong the tinh tien.\n",
			t.MaDon, t.TrangThai);
		return 0;
	}

	//Tính số ngày thường và ngày trễ
	int ngayThuong = daysBetween(t.NgayThue, t.NgayTraDuKien);
	if (ngayThuong < 0) ngayThuong = 0;

	int ngayTre = daysBetween(t.NgayTraDuKien, t.NgayTraThucTe);
	if (ngayTre < 0) ngayTre = 0;

	float tienThuong = ngayThuong * gia;
	float tienTre = ngayTre * gia * 1.2f;  // phụ phí 20%
	return tienThuong + tienTre;
}

void thanhToanTheoMaDon(const Slist_ThueXe& slThue, const SList_Xe& slXe) {
	char maDon[20];
	printf("Nhap MaDon: ");
	scanf("%19s", maDon);

	SNode_ThueXe* node = NULL;
	for (SNode_ThueXe* p = slThue.Head; p; p = p->Next) {
		if (strcmp(p->Info.MaDon, maDon) == 0) {
			node = p;
			break;
		}
	}

	if (!node) {
		printf("Khong tim thay MaDon %s\n", maDon);
		return;
	}

	float tien = tinhTienThue(node->Info, slXe);

	printf("Don %s (MaKH=%s, BienSo=%s) phai tra: %.2f\\n",
		node->Info.MaDon,
		node->Info.MaKH,
		node->Info.BienSo,
		tien);
}
// Hàm tìm và in thông tin khách hàng phải trả nhiều nhất
void timKhachTienPhaiTraLonNhat(const Slist_ThueXe& slThue,
	const SList_Xe& slXe,
	const SList_KH& slKh) {
	float maxFee = -1.0f;
	char maKHMax[20] = "";

	// Duyệt qua các đơn đã trả để tìm max
	for (SNode_ThueXe* p = slThue.Head; p; p = p->Next) {
		if (strcmp(p->Info.TrangThai, "Da tra") != 0)
			continue;
		float fee = tinhTienThue(p->Info, slXe);
		if (fee > maxFee) {
			maxFee = fee;
			strcpy(maKHMax, p->Info.MaKH);
		}
	}

	if (maxFee < 0) {
		printf("Chua co don hang 'Da tra' de tinh tien.\n");
		return;
	}

	printf("\n--- Khach hang phai tra nhieu nhat: %.2f ---\n", maxFee);
	printHeader_KhachHang();
	for (SNode_KH* q = slKh.Head; q; q = q->Next) {
		if (strcmp(q->Info.MaKH, maKHMax) == 0) {
			printf("\n");
			showItem_KhachHang(q->Info);
			printf("\n");
			break;
		}
	}
}

// Hàm tìm và in thông tin khách hàng phải trả ít nhất
void timKhachTienPhaiTraItNhat(const Slist_ThueXe& slThue,
	const SList_Xe& slXe,
	const SList_KH& slKh) {
	float minFee = 1e30f;
	char maKHMin[20] = "";

	// Duyệt qua các đơn đã trả để tìm min
	for (SNode_ThueXe* p = slThue.Head; p; p = p->Next) {
		if (strcmp(p->Info.TrangThai, "Da tra") != 0)
			continue;
		float fee = tinhTienThue(p->Info, slXe);
		if (fee < minFee) {
			minFee = fee;
			strcpy(maKHMin, p->Info.MaKH);
		}
	}

	if (minFee > 1e20f) {
		printf("Chua co don hang 'Da tra' de tinh tien.\n");
		return;
	}

	printf("\n--- Khach hang phai tra it nhat: %.2f ---\n", minFee);
	printHeader_KhachHang();
	for (SNode_KH* q = slKh.Head; q; q = q->Next) {
		if (strcmp(q->Info.MaKH, maKHMin) == 0) {
			printf("\n");
			showItem_KhachHang(q->Info);
			printf("\n");
			break;
		}
	}
}
void timKhachGiaThueNgayLonNhat(const Slist_ThueXe& slThue,
	const SList_Xe& slXe,
	const SList_KH& slKh) {
	float maxPrice = -1.0f;
	char maKH_max[20] = "";
	//Tìm giá thuê ngày cao nhất và lưu MaKH tương ứng
	for (SNode_ThueXe* p = slThue.Head; p; p = p->Next) {
		// Lấy giá thuê từ DanhMucXe
		float gia = 0;
		for (SNode_Xe* q = slXe.Head; q; q = q->Next) {
			if (strcmp(q->Info.BienSo, p->Info.BienSo) == 0) {
				gia = q->Info.GiaThue;
				break;
			}
		}
		if (gia > maxPrice) {
			maxPrice = gia;
			strcpy(maKH_max, p->Info.MaKH);
		}
	}
	if (maxPrice < 0) {
		printf("Khong co ban ghi thue xe de tim gia thue ngay lon nhat.\\n");
		return;
	}

	printf("\\n--- Khach hang co gia thue/ngay cao nhat: %.2f ---\\n", maxPrice);
	printHeader_KhachHang();
	for (SNode_KH* r = slKh.Head; r; r = r->Next) {
		if (strcmp(r->Info.MaKH, maKH_max) == 0) {
			printf("\\n");
			showItem_KhachHang(r->Info);
			printf("\\n");
			break;
		}
	}
}


void timKhachGiaThueNgayItNhat(const Slist_ThueXe& slThue,
	const SList_Xe& slXe,
	const SList_KH& slKh) {
	float minPrice = 1e30f;
	char maKH_min[20] = "";
	//Tìm giá thuê ngày thấp nhất và lưu MaKH tương ứng
	for (SNode_ThueXe* p = slThue.Head; p; p = p->Next) {
		float gia = 0;
		for (SNode_Xe* q = slXe.Head; q; q = q->Next) {
			if (strcmp(q->Info.BienSo, p->Info.BienSo) == 0) {
				gia = q->Info.GiaThue;
				break;
			}
		}
		if (gia < minPrice) {
			minPrice = gia;
			strcpy(maKH_min, p->Info.MaKH);
		}
	}
	if (minPrice > 1e20f) {
		printf("Khong co ban ghi thue xe de tim gia thue ngay it nhat.\\n");
		return;
	}
	printf("\\n--- Khach hang co gia thue/ngay thap nhat: %.2f ---\\n", minPrice);
	printHeader_KhachHang();
	for (SNode_KH* r = slKh.Head; r; r = r->Next) {
		if (strcmp(r->Info.MaKH, maKH_min) == 0) {
			printf("\\n");
			showItem_KhachHang(r->Info);
			printf("\\n");
			break;
		}
	}
}
void inThongTinKhachVaSoLanThue(const SList_KH& slKh, const Slist_ThueXe& slThue) {
	printHeader_KhachHang();
	printf("%10s\n", "SoLanThue");

	int stt = 1;
	for (SNode_KH* pKh = slKh.Head; pKh; pKh = pKh->Next) {
		int cnt = 0;
		for (SNode_ThueXe* pTh = slThue.Head; pTh; pTh = pTh->Next) {
			if (strcmp(pTh->Info.MaKH, pKh->Info.MaKH) == 0) {
				cnt++;
			}
		}

		printf("\n%-5d", stt++);

		showItem_KhachHang(pKh->Info);

		printf("%10d", cnt);
	}
	printf("\n");
}

// 1) Cập nhật Xe theo BienSo và lưu vào file
void capNhatXeTheoBienSo_UpdateFile(SList_Xe& slXe, const char* filename) {
	char bienSoOld[20];
	int choice, c;
	// Xóa newline còn sót trước khi dùng fgets
	while ((c = getchar()) != '\n' && c != EOF);

	printf("Nhap BienSo cua xe can cap nhat: ");
	fgets(bienSoOld, sizeof bienSoOld, stdin);
	bienSoOld[strcspn(bienSoOld, "\n")] = 0;

	SNode_Xe* p = slXe.Head;
	while (p && strcmp(p->Info.BienSo, bienSoOld) != 0)
		p = p->Next;
	if (!p) {
		printf("Khong tim thay xe co BienSo %s\n", bienSoOld);
		return;
	}

	do {
		printf("\n--- Cap nhat Xe (BienSo=%s) ---\n", bienSoOld);
		printf("1. Bien So\n");
		printf("2. Ten Xe\n");
		printf("3. Ngay Dang Kiem\n");
		printf("4. Gia Thue\n");
		printf("0. Ket thuc\n");
		printf("Chon (0-4): ");
		scanf("%d", &choice);
		while ((c = getchar()) != '\n' && c != EOF);

		switch (choice) {
		case 1:
			printf("Nhap BienSo moi: ");
			fgets(p->Info.BienSo, sizeof p->Info.BienSo, stdin);
			p->Info.BienSo[strcspn(p->Info.BienSo, "\n")] = 0;
			strcpy(bienSoOld, p->Info.BienSo);
			break;
		case 2:
			printf("Nhap TenXe moi: ");
			fgets(p->Info.TenXe, sizeof p->Info.TenXe, stdin);
			p->Info.TenXe[strcspn(p->Info.TenXe, "\n")] = 0;
			break;
		case 3:
			printf("Nhap Ngay Dang Kiem moi (dd/mm/yyyy): ");
			readDate(&p->Info.NgayDangKiem);
			break;
		case 4:
			printf("Nhap Gia Thue moi: ");
			scanf("%f", &p->Info.GiaThue);
			while ((c = getchar()) != '\n' && c != EOF);
			break;
		case 0:
			printf("Ket thuc cap nhat Xe.\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
		}
	} while (choice != 0);

	// Lưu lại file
	FILE* fo = fopen(filename, "w");
	if (!fo) {
		printf("Loi mo file %s de ghi!\n", filename);
		return;
	}
	// Đếm số bản ghi
	int n = 0;
	for (SNode_Xe* q = slXe.Head; q; q = q->Next) n++;
	fprintf(fo, "%d\n", n);

	// Ghi từng xe
	for (SNode_Xe* q = slXe.Head; q; q = q->Next) {
		fprintf(fo,
			"%s#%s#%02d/%02d/%04d#%.2f\n",
			q->Info.BienSo,
			q->Info.TenXe,
			q->Info.NgayDangKiem.day,
			q->Info.NgayDangKiem.month,
			q->Info.NgayDangKiem.year,
			q->Info.GiaThue
		);
	}
	fclose(fo);
	printf("Da cap nhat va luu file %s\n", filename);
}

// 2) Cập nhật KhachHang theo MaKH và lưu vào file
void capNhatKhachHangTheoMaKH_UpdateFile(SList_KH& slKh, const char* filename) {
	char maOld[20];
	int choice, c;
	while ((c = getchar()) != '\n' && c != EOF);

	printf("Nhap MaKH cua khach hang can cap nhat: ");
	fgets(maOld, sizeof maOld, stdin);
	maOld[strcspn(maOld, "\n")] = 0;

	SNode_KH* p = slKh.Head;
	while (p && strcmp(p->Info.MaKH, maOld) != 0)
		p = p->Next;
	if (!p) {
		printf("Khong tim thay KhachHang MaKH=%s\n", maOld);
		return;
	}

	do {
		printf("\n--- Cap nhat KhachHang (MaKH=%s) ---\n", maOld);
		printf("1. MaKH\n");
		printf("2. Ho va Ten\n");
		printf("3. Ngay Sinh\n");
		printf("4. SDT\n");
		printf("5. So CCCD\n");
		printf("0. Ket thuc\n");
		printf("Chon (0-5): ");
		scanf("%d", &choice);
		while ((c = getchar()) != '\n' && c != EOF);

		switch (choice) {
		case 1:
			printf("Nhap MaKH moi: ");
			fgets(p->Info.MaKH, sizeof p->Info.MaKH, stdin);
			p->Info.MaKH[strcspn(p->Info.MaKH, "\n")] = 0;
			strcpy(maOld, p->Info.MaKH);
			break;
		case 2:
			printf("Nhap Ho va Ten moi: ");
			fgets(p->Info.HoTen, sizeof p->Info.HoTen, stdin);
			p->Info.HoTen[strcspn(p->Info.HoTen, "\n")] = 0;
			break;
		case 3:
			printf("Nhap Ngay Sinh moi (dd/mm/yyyy): ");
			readDate(&p->Info.NgaySinh);
			break;
		case 4:
			printf("Nhap SDT moi: ");
			fgets(p->Info.SDT, sizeof p->Info.SDT, stdin);
			p->Info.SDT[strcspn(p->Info.SDT, "\n")] = 0;
			break;
		case 5:
			printf("Nhap So CCCD moi: ");
			fgets(p->Info.SoCCCD, sizeof p->Info.SoCCCD, stdin);
			p->Info.SoCCCD[strcspn(p->Info.SoCCCD, "\n")] = 0;
			break;
		case 0:
			printf("Ket thuc cap nhat KhachHang.\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
		}
	} while (choice != 0);

	// Lưu file
	FILE* fo = fopen(filename, "w");
	if (!fo) {
		printf("Loi mo file %s de ghi!\n", filename);
		return;
	}
	int n = 0;
	for (SNode_KH* q = slKh.Head; q; q = q->Next) n++;
	fprintf(fo, "%d\n", n);

	for (SNode_KH* q = slKh.Head; q; q = q->Next) {
		fprintf(fo,
			"%s#%s#%02d/%02d/%04d#%s#%s\n",
			q->Info.MaKH,
			q->Info.HoTen,
			q->Info.NgaySinh.day,
			q->Info.NgaySinh.month,
			q->Info.NgaySinh.year,
			q->Info.SDT,
			q->Info.SoCCCD
		);
	}
	fclose(fo);
	printf("Da cap nhat va luu file %s\n", filename);
}

// 3) Cập nhật ThueXe theo MaDon và lưu vào file
void capNhatThueXeTheoMaDon_UpdateFile(Slist_ThueXe& slThue, const char* filename) {
	char maOld[20];
	int choice, c;
	while ((c = getchar()) != '\n' && c != EOF);

	printf("Nhap MaDon cua ban ghi thue can cap nhat: ");
	fgets(maOld, sizeof maOld, stdin);
	maOld[strcspn(maOld, "\n")] = 0;

	SNode_ThueXe* p = slThue.Head;
	while (p && strcmp(p->Info.MaDon, maOld) != 0)
		p = p->Next;
	if (!p) {
		printf("Khong tim thay ThueXe MaDon=%s\n", maOld);
		return;
	}

	do {
		printf("\n--- Cap nhat ThueXe (MaDon=%s) ---\n", maOld);
		printf("1. MaDon\n2. MaKH\n3. BienSo\n4. Ngay Thue\n");
		printf("5. Ngay Tra Du Kien\n6. Ngay Tra Thuc Te\n7. Trang Thai\n");
		printf("0. Ket thuc\n");
		printf("Chon (0-7): ");
		scanf("%d", &choice);
		while ((c = getchar()) != '\n' && c != EOF);

		switch (choice) {
		case 1:
			printf("Nhap MaDon moi: ");
			fgets(p->Info.MaDon, sizeof p->Info.MaDon, stdin);
			p->Info.MaDon[strcspn(p->Info.MaDon, "\n")] = 0;
			strcpy(maOld, p->Info.MaDon);
			break;
		case 2:
			printf("Nhap MaKH moi: ");
			fgets(p->Info.MaKH, sizeof p->Info.MaKH, stdin);
			p->Info.MaKH[strcspn(p->Info.MaKH, "\n")] = 0;
			break;
		case 3:
			printf("Nhap BienSo moi: ");
			fgets(p->Info.BienSo, sizeof p->Info.BienSo, stdin);
			p->Info.BienSo[strcspn(p->Info.BienSo, "\n")] = 0;
			break;
		case 4:
			printf("Nhap Ngay Thue moi (dd/mm/yyyy): ");
			readDate(&p->Info.NgayThue);
			break;
		case 5:
			printf("Nhap Ngay Tra Du Kien moi (dd/mm/yyyy): ");
			readDate(&p->Info.NgayTraDuKien);
			break;
		case 6:
			printf("Nhap Ngay Tra Thuc Te moi (dd/mm/yyyy): ");
			readDate(&p->Info.NgayTraThucTe);
			break;
		case 7:
			printf("Nhap Trang Thai moi: ");
			fgets(p->Info.TrangThai, sizeof p->Info.TrangThai, stdin);
			p->Info.TrangThai[strcspn(p->Info.TrangThai, "\n")] = 0;
			break;
		case 0:
			printf("Ket thuc cap nhat ThueXe.\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
		}
	} while (choice != 0);

	// Lưu file
	FILE* fo = fopen(filename, "w");
	if (!fo) {
		printf("Loi mo file %s de ghi!\n", filename);
		return;
	}
	int n = 0;
	for (SNode_ThueXe* q = slThue.Head; q; q = q->Next) n++;
	fprintf(fo, "%d\n", n);

	for (SNode_ThueXe* q = slThue.Head; q; q = q->Next) {
		fprintf(fo,
			"%s#%s#%s#%02d/%02d/%04d#%02d/%02d/%04d#%02d/%02d/%04d#%s\n",
			q->Info.MaDon,
			q->Info.MaKH,
			q->Info.BienSo,
			q->Info.NgayThue.day, q->Info.NgayThue.month, q->Info.NgayThue.year,
			q->Info.NgayTraDuKien.day, q->Info.NgayTraDuKien.month, q->Info.NgayTraDuKien.year,
			q->Info.NgayTraThucTe.day, q->Info.NgayTraThucTe.month, q->Info.NgayTraThucTe.year,
			q->Info.TrangThai
		);
	}
	fclose(fo);
	printf("Da cap nhat va luu file %s\n", filename);
}



// 1) Xóa Xe theo BienSo và cập nhật file
void xoaXeTheoBienSo_UpdateFile(SList_Xe& sl, const char* bienSo, const char* filename) {
	SNode_Xe* p = sl.Head, * prev = NULL;
	// tìm node cần xóa
	while (p && strcmp(p->Info.BienSo, bienSo) != 0) {
		prev = p;
		p = p->Next;
	}
	if (!p) {
		printf("Khong tim thay xe co BienSo %s de xoa.\n", bienSo);
		return;
	}
	// bỏ khỏi danh sách
	if (!prev) sl.Head = p->Next;
	else       prev->Next = p->Next;
	if (p == sl.Tail) sl.Tail = prev;
	delete p;
	printf("Da xoa xe co BienSo %s.\n", bienSo);

	// đếm số bản ghi còn lại
	int n = 0;
	for (SNode_Xe* q = sl.Head; q; q = q->Next) n++;

	// ghi danh sách ra file
	FILE* fo = fopen(filename, "w");
	if (!fo) {
		printf("Loi mo file %s de ghi!\n", filename);
		return;
	}
	fprintf(fo, "%d\n", n);
	for (SNode_Xe* q = sl.Head; q; q = q->Next) {
		fprintf(fo,
			"%s#%s#%02d/%02d/%04d#%.2f\n",
			q->Info.BienSo,
			q->Info.TenXe,
			q->Info.NgayDangKiem.day,
			q->Info.NgayDangKiem.month,
			q->Info.NgayDangKiem.year,
			q->Info.GiaThue
		);
	}
	fclose(fo);
	printf("Da cap nhat file %s\n", filename);
}

// 2) Xóa KhachHang theo MaKH và cập nhật file
void xoaKhachHangTheoMaKH_UpdateFile(SList_KH& sl, const char* maKH, const char* filename) {
	SNode_KH* p = sl.Head, * prev = NULL;
	while (p && strcmp(p->Info.MaKH, maKH) != 0) {
		prev = p;
		p = p->Next;
	}
	if (!p) {
		printf("Khong tim thay Khach hang MaKH=%s de xoa.\n", maKH);
		return;
	}
	if (!prev) sl.Head = p->Next;
	else       prev->Next = p->Next;
	if (p == sl.Tail) sl.Tail = prev;
	delete p;
	printf("Da xoa Khach hang MaKH=%s.\n", maKH);

	int n = 0;
	for (SNode_KH* q = sl.Head; q; q = q->Next) n++;

	FILE* fo = fopen(filename, "w");
	if (!fo) {
		printf("Loi mo file %s de ghi!\n", filename);
		return;
	}
	fprintf(fo, "%d\n", n);
	for (SNode_KH* q = sl.Head; q; q = q->Next) {
		fprintf(fo,
			"%s#%s#%02d/%02d/%04d#%s#%s\n",
			q->Info.MaKH,
			q->Info.HoTen,
			q->Info.NgaySinh.day,
			q->Info.NgaySinh.month,
			q->Info.NgaySinh.year,
			q->Info.SDT,
			q->Info.SoCCCD
		);
	}
	fclose(fo);
	printf("Da cap nhat file %s\n", filename);
}

// 3) Xóa ThueXe theo MaDon và cập nhật file
void xoaThueXeTheoMaDon_UpdateFile(Slist_ThueXe& sl, const char* maDon, const char* filename) {
	SNode_ThueXe* p = sl.Head, * prev = NULL;
	while (p && strcmp(p->Info.MaDon, maDon) != 0) {
		prev = p;
		p = p->Next;
	}
	if (!p) {
		printf("Khong tim thay Don MaDon=%s de xoa.\n", maDon);
		return;
	}
	if (!prev) sl.Head = p->Next;
	else       prev->Next = p->Next;
	if (p == sl.Tail) sl.Tail = prev;
	delete p;
	printf("Da xoa Don MaDon=%s.\n", maDon);

	int n = 0;
	for (SNode_ThueXe* q = sl.Head; q; q = q->Next) n++;

	FILE* fo = fopen(filename, "w");
	if (!fo) {
		printf("Loi mo file %s de ghi!\n", filename);
		return;
	}
	fprintf(fo, "%d\n", n);
	for (SNode_ThueXe* q = sl.Head; q; q = q->Next) {
		fprintf(fo,
			"%s#%s#%s#%02d/%02d/%04d#%02d/%02d/%04d#%02d/%02d/%04d#%s\n",
			q->Info.MaDon,
			q->Info.MaKH,
			q->Info.BienSo,
			q->Info.NgayThue.day, q->Info.NgayThue.month, q->Info.NgayThue.year,
			q->Info.NgayTraDuKien.day, q->Info.NgayTraDuKien.month, q->Info.NgayTraDuKien.year,
			q->Info.NgayTraThucTe.day, q->Info.NgayTraThucTe.month, q->Info.NgayTraThucTe.year,
			q->Info.TrangThai
		);
	}
	fclose(fo);
	printf("Da cap nhat file %s\n", filename);
}

void showTrangThaiXe(const SList_Xe& slXe, const Slist_ThueXe& slThue) {
	printf("\n%-5s%-15s%-20s%-20s%-10s%-15s",
		"STT", "BienSo", "TenXe", "NgayDangKiem", "GiaThue", "TrangThai");
	int stt = 1;

	for (SNode_Xe* pXe = slXe.Head; pXe; pXe = pXe->Next) {
		bool isRented = false;
		for (SNode_ThueXe* pTh = slThue.Head; pTh; pTh = pTh->Next) {
			if (strcmp(pTh->Info.BienSo, pXe->Info.BienSo) == 0
				&& strcmp(pTh->Info.TrangThai, "Dang cho thue") == 0) {
				isRented = true;
				break;
			}
		}

		printf("\n%-5d", stt++);
		printf("%0s%15s", pXe->Info.BienSo, pXe->Info.TenXe);
		printf("%15s", " "); printDate(pXe->Info.NgayDangKiem);
		printf("%20.2f", pXe->Info.GiaThue);
		printf("  %-15s", isRented ? "Dang cho thue" : "Trong");
	}
	printf("\n");
}

float thongKeDoanhThuTheoNgay(Date d,
	const Slist_ThueXe& slThue,
	const SList_Xe& slXe)
{
	float total = 0.0f;
	for (SNode_ThueXe* p = slThue.Head; p; p = p->Next) {
		if (strcmp(p->Info.TrangThai, "Da tra") == 0
			&& p->Info.NgayTraThucTe.day == d.day
			&& p->Info.NgayTraThucTe.month == d.month
			&& p->Info.NgayTraThucTe.year == d.year)
		{
			total += tinhTienThue(p->Info, slXe);
		}
	}
	return total;
}

float thongKeDoanhThuTheoThang(int month, int year,
	const Slist_ThueXe& slThue,
	const SList_Xe& slXe)
{
	float total = 0.0f;
	for (SNode_ThueXe* p = slThue.Head; p; p = p->Next) {
		if (strcmp(p->Info.TrangThai, "Da tra") == 0
			&& p->Info.NgayTraThucTe.month == month
			&& p->Info.NgayTraThucTe.year == year)
		{
			total += tinhTienThue(p->Info, slXe);
		}
	}
	return total;
}

float thongKeDoanhThuTheoNam(int year,
	const Slist_ThueXe& slThue,
	const SList_Xe& slXe)
{
	float total = 0.0f;
	for (SNode_ThueXe* p = slThue.Head; p; p = p->Next) {
		if (strcmp(p->Info.TrangThai, "Da tra") == 0
			&& p->Info.NgayTraThucTe.year == year)
		{
			total += tinhTienThue(p->Info, slXe);
		}
	}
	return total;
}

float thongKeDoanhThuTuNgayDenNgay(Date d1, Date d2,
	const Slist_ThueXe& slThue,
	const SList_Xe& slXe)
{
	time_t t1 = _to_time_t(d1);
	time_t t2 = _to_time_t(d2);
	//khi người dùng nhập ngược
	if (t1 > t2) {
		time_t tmp = t1;
		t1 = t2;
		t2 = tmp;
	}

	float total = 0.0f;
	for (SNode_ThueXe* p = slThue.Head; p; p = p->Next) {
		if (strcmp(p->Info.TrangThai, "Da tra") != 0) continue;
		time_t ta = _to_time_t(p->Info.NgayTraThucTe);
		if (ta >= t1 && ta <= t2) {
			total += tinhTienThue(p->Info, slXe);
		}
	}
	return total;
}



//=========================================================
// Menu chương trình
void showMenu() {
	printf("\n========================================\n");
	printf("           CHUONG TRINH QUAN LY         \n");
	printf("========================================\n");
	printf(" 1. Xuat du lieu\n");
	printf(" 2. Nhap du lieu\n");
	printf(" 3. Tim kiem\n");
	printf(" 4. Cap nhat\n");
	printf(" 5. Xoa du lieu\n");
	printf(" 6. Sap xep\n");
	printf(" 7. Tinh tien\n");
	printf(" 8. Thong ke doanh thu\n");
	printf(" 0. Thoat chuong trinh\n");
	printf("========================================\n");
	printf(" Nhap lua chon (0-8): ");
}

void process()
{
	FILE* fi;
	int select, choice;
	SList_Xe SListDanhMucXe;
	SList_KH SListkh;
	Slist_ThueXe SListThue;

	initSList(SListDanhMucXe);
	initSList(SListkh);
	initSList(SListThue);

	createSListDanhMucXe_FromTextFile(SListDanhMucXe, "danhmucxe.txt");
	createSListKhachHang_FromTextFile(SListkh, "khachhang.txt");
	createSListThueXe_FromTextFile(SListThue, "thuexe.txt");
	do {
		showMenu();
		printf("\nNhap lua chon: ");
		scanf("%d", &select);
		switch (select)
		{
		case 0:
			printf("Thoat chuong trinh...\n");
			break;
		case 1: {
			do {
				printf("\n===== QUAN LY DU LIEU =====\n");
				printf("1. Danh muc xe\n");
				printf("2. Khach hang\n");
				printf("3. Thue xe\n");
				printf("4. Thong ke so lan thue cua Khach hang\n");
				printf("5. Xem trang thai xe\n");
				printf("0. Quay lai menu chinh\n");
				printf("Nhap lua chon: ");
				scanf("%d", &choice);
				switch (choice) {
				case 1:
					printf("\n--- Danh muc xe ---\n");
					showSList_DanhMucXe(SListDanhMucXe);
					break;
				case 2:
					printf("\n--- Dan sach khach hang ---\n");
					showSList_KhachHang(SListkh);
					break;
				case 3:
					printf("\n--- Dan sach thue xe ---\n");
					showSList_ThueXe(SListThue);
					break;
				case 4:
					printf("\n--- Thong ke so lan thue cua Khach hang ---\n");
					inThongTinKhachVaSoLanThue(SListkh, SListThue);
					break;
				case 5:
					printf("\n--- Trang thai xe (Trong / Dang cho thue) ---\n");
					showTrangThaiXe(SListDanhMucXe, SListThue);
					break;
				case 0:
					// Quay lai menu chinh
					break;
				default:
					printf("Lua chon khong hop le!\n");
				}
			} while (choice != 0);
		} break;



		case 2: {
			do {
				printf("\n===== MENU THEM MOI =====\n");
				printf("1. Them xe\n");
				printf("2. Them khach hang\n");
				printf("3. Them thue xe\n");
				printf("0. Tro ve menu chinh\n");
				printf("Chon (0-3): ");
				scanf("%d", &choice);
				switch (choice) {
				case 1:
					addDanhMucXe_UpdateCount(SListDanhMucXe, "danhmucxe.txt");
					break;
				case 2:
					addKhachHang_UpdateCount(SListkh, "khachhang.txt");
					break;
				case 3:
					addThueXe_UpdateCount(SListThue, "thuexe.txt");
					break;
				case 0:

					break;
				default:
					printf("Lua chon khong hop le, vui long thu lai.\n");
				}
			} while (choice != 0);
		} break;
		case 3: {
			do {
				printf("\n===== MENU TIM KIEM KHACH HANG =====\n");
				printf("1. Tim theo MaKH\n");
				printf("2. Tim theo HoTen\n");
				printf("3. Tim theo NamSinh\n");
				printf("4. Khach hang tra nhieu nhat\n");
				printf("5. Khach hang tra it nhat\n");
				printf("6. Khach hang co gia thue/ngay cao nhat\n");
				printf("7. Khach hang co gia thue/ngay thap nhat\n");
				printf("8. Tim ban ghi thue xe theo BienSo\n");
				printf("0. Tro ve menu chinh\n");
				printf("Chon (0-8): ");
				scanf("%d", &choice);
				switch (choice) {
				case 1:
					timTheoMaKH(SListkh);
					break;
				case 2:
					timTheoHoTen(SListkh);
					break;
				case 3:
					timTheoNamSinh(SListkh);
					break;
				case 4:
					timKhachTienPhaiTraLonNhat(SListThue, SListDanhMucXe, SListkh);
					break;
				case 5:
					timKhachTienPhaiTraItNhat(SListThue, SListDanhMucXe, SListkh);
					break;
				case 6:
					timKhachGiaThueNgayLonNhat(SListThue, SListDanhMucXe, SListkh);
					break;
				case 7:
					timKhachGiaThueNgayItNhat(SListThue, SListDanhMucXe, SListkh);
					break;
				case 8:
					timKhachHangTheoBienSo(SListkh, SListThue);
					break;
				case 0:
					// trở về menu chính
					break;
				default:
					printf("Lua chon khong hop le! Vui long chon lai.\n");
				}
			} while (choice != 0);
		} break;
		case 4: {
			do {
				printf("\n--- CAP NHAT DU LIEU ---\n");
				printf("1. Cap nhat Xe\n");
				printf("2. Cap nhat Khach hang\n");
				printf("3. Cap nhat Thue xe\n");
				printf("0. Quay lai menu chinh...\n");
				printf("Chon (0-3): ");
				scanf("%d", &choice);
				while (getchar() != '\n');  // flush

				switch (choice) {
				case 1:
					capNhatXeTheoBienSo_UpdateFile(SListDanhMucXe, "danhmucxe.txt");
					break;
				case 2:
					capNhatKhachHangTheoMaKH_UpdateFile(SListkh, "khachhang.txt");
					break;
				case 3:
					capNhatThueXeTheoMaDon_UpdateFile(SListThue, "thuexe.txt");
					break;
				case 0:
					// quay lai menu chinh
					break;
				default:
					printf("Lua chon khong hop le!\n");
				}
			} while (choice != 0);
		} break;
		case 5: {
			char key[20];
			do {
				printf("\n===== XOA DU LIEU =====\n");
				printf("1. Xoa xe theo BienSo\n");
				printf("2. Xoa khach hang theo MaKH\n");
				printf("3. Xoa thue xe theo MaDon\n");
				printf("0. Quay lai menu chinh\n");
				printf("Chon (0-3): ");
				scanf("%d", &choice);
				while (getchar() != '\n');  // flush

				switch (choice) {
				case 1:
					printf("Nhap BienSo can xoa: ");
					scanf("%19s", key);
					xoaXeTheoBienSo_UpdateFile(SListDanhMucXe, key, "danhmucxe.txt");
					break;
				case 2:
					printf("Nhap MaKH can xoa: ");
					scanf("%19s", key);
					xoaKhachHangTheoMaKH_UpdateFile(SListkh, key, "khachhang.txt");
					break;
				case 3:
					printf("Nhap MaDon can xoa: ");
					scanf("%19s", key);
					xoaThueXeTheoMaDon_UpdateFile(SListThue, key, "thuexe.txt");
					break;
				case 0:
					// quay lai menu chinh
					break;
				default:
					printf("Lua chon khong hop le!\n");
				}
			} while (choice != 0);
		} break;




		case 6: {

			do {
				printf("\n--- SAP XEP KHACH HANG ---\n");
				printf("1. Giam dan theo NamSinh\n");
				printf("2. Tang dan theo MaKH\n");
				printf("0. Quay lai menu chinh\n");
				printf("Chon (0-2): ");
				scanf("%d", &choice);
				switch (choice) {
				case 1:
					sort_KhachHang_GiamDan_TheoNamSinh(SListkh);
					printf("\n--- Danh sach Khach hang giam dan theo NamSinh ---\n");
					showSList_KhachHang(SListkh);
					break;
				case 2:
					sort_KhachHang_TheoMaKH(SListkh);
					printf("\n--- Danh sach Khach hang tang dan theo MaKH ---\n");
					showSList_KhachHang(SListkh);
					break;
				case 0:
					// Quay lai menu chinh
					break;
				default:
					printf("Lua chon khong hop le!\n");
				}
			} while (choice != 0);
		} break;
		case 7: {
			thanhToanTheoMaDon(SListThue, SListDanhMucXe);
			break;
		}
		case 8: {
			int choice1;
			do {
				printf("\n===== THONG KE DOANH THU =====\n");
				printf("1. Theo ngay\n");
				printf("2. Theo thang\n");
				printf("3. Theo nam\n");
				printf("4. Tu ngay den ngay\n");
				printf("0. Quay lai menu chinh\n");
				printf("Chon (0-4): ");
				scanf("%d", &choice1);
				while (getchar() != '\n');

				switch (choice1) {
				case 1: {
					Date d;
					printf("Nhap ngay (dd/mm/yyyy): ");
					readDate(&d);
					printf("Doanh thu ngay %02d/%02d/%04d: %.2f\n",
						d.day, d.month, d.year,
						thongKeDoanhThuTheoNgay(d, SListThue, SListDanhMucXe));
					break;
				}
				case 2: {
					char key[10];
					int month, year;
					printf("Nhap thang va nam (mm/yyyy): ");
					scanf("%9s", key);
					if (sscanf(key, "%d/%d", &month, &year) != 2) {
						printf("Dinh dang khong hop le! Vui long nhap mm/yyyy.\n");
					}
					else {
						float doanhThu = thongKeDoanhThuTheoThang(month, year,
							SListThue, SListDanhMucXe);
						printf("Doanh thu thang %02d/%04d: %.2f\n",
							month, year, doanhThu);
					}
					break;
				}
				case 3: {
					int year;
					printf("Nhap nam (yyyy): ");
					scanf("%d", &year);
					while (getchar() != '\n');
					printf("Doanh thu nam %04d: %.2f\n",
						year,
						thongKeDoanhThuTheoNam(year, SListThue, SListDanhMucXe));
					break;
				}
				case 4: {
					Date d1, d2;
					printf("Nhap tu ngay (dd/mm/yyyy): ");
					readDate(&d1);
					printf("Nhap den ngay (dd/mm/yyyy): ");
					readDate(&d2);
					printf("Doanh thu tu %02d/%02d/%04d den %02d/%02d/%04d: %.2f\n",
						d1.day, d1.month, d1.year,
						d2.day, d2.month, d2.year,
						thongKeDoanhThuTuNgayDenNgay(d1, d2, SListThue, SListDanhMucXe));
					break;
				}
				case 0:
					// quay lai menu chinh
					break;
				default:
					printf("Lua chon khong hop le! Vui long chon lai.\n");
				}
			} while (choice1 != 0);
		} break;


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