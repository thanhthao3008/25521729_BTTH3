#include "cNhanVienSX.h"


// Constructor mặc định
cNhanVienSX::cNhanVienSX() {
    maNV = "";
    hoTen = "";
    ngaySinh = "";
    soSanPham = 0;
    donGia = 0;
}

// Constructor đầy đủ
cNhanVienSX::cNhanVienSX(string ma, string ten, string ns, int sp, double dg) {
    maNV = ma;
    hoTen = ten;
    ngaySinh = ns;
    soSanPham = sp;
    donGia = dg;
}

// Nhập một Nhân Viên
void cNhanVienSX::Nhap() {
    cin.ignore();
    cout << "Ma NV: ";
    getline(cin, maNV);
    cout << "Ho ten: ";
    getline(cin, hoTen);
    cout << "Ngay sinh (dd/mm/yyyy): ";
    getline(cin, ngaySinh);
    cout << "So san pham: ";
    cin >> soSanPham;
    cout << "Don gia: ";
    cin >> donGia;
}

// Xuất ra thông tin một Nhân Viên
void cNhanVienSX::Xuat() const {
    cout << maNV << " | " << hoTen << " | " << ngaySinh
         << " | SP: " << soSanPham
         << " | Don gia: " << donGia
         << " | Luong: " << TinhLuong() << endl;
}

// Getter
string cNhanVienSX::getMaNV() const { return maNV; }
string cNhanVienSX::getHoTen() const { return hoTen; }
string cNhanVienSX::getNgaySinh() const { return ngaySinh; }
int cNhanVienSX::getSoSanPham() const { return soSanPham; }
double cNhanVienSX::getDonGia() const { return donGia; }

// Setter
void cNhanVienSX::setMaNV(string ma) { maNV = ma; }
void cNhanVienSX::setHoTen(string ten) { hoTen = ten; }
void cNhanVienSX::setNgaySinh(string ns) { ngaySinh = ns; }
void cNhanVienSX::setSoSanPham(int sp) { soSanPham = sp; }
void cNhanVienSX::setDonGia(double dg) { donGia = dg; }

// Lương = số SP * đơn giá
double cNhanVienSX::TinhLuong() const {
    return soSanPham * donGia;
}

// So sánh tuổi, trả về người lớn tuổi hơn (ngày sinh nhỏ hơn)
cNhanVienSX cNhanVienSX::SoSanhTuoi(const cNhanVienSX &NV)
{
    // giả sử định dạng ngày sinh: dd/mm/yyyy

    int ngay1 = stoi(ngaySinh.substr(0, 2));
    int thang1 = stoi(ngaySinh.substr(3, 2));
    int nam1 = stoi(ngaySinh.substr(6, 4));

    int ngay2 = stoi(NV.ngaySinh.substr(0, 2));
    int thang2 = stoi(NV.ngaySinh.substr(3, 2));
    int nam2 = stoi(NV.ngaySinh.substr(6, 4));

    // so sánh năm trước
    if (nam1 < nam2)
        return *this;
    if (nam1 > nam2)
        return NV;

    // nếu cùng năm → so sánh tháng
    if (thang1 < thang2)
        return *this;
    if (thang1 > thang2)
        return NV;

    // nếu cùng tháng → so sánh ngày
    if (ngay1 < ngay2)
        return *this;
    if (ngay1 > ngay2)
        return NV;

    // nếu bằng tuổi nhau thì trả về object hiện tại
    return *this;
}


