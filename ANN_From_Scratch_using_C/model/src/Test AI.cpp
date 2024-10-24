#include <iostream>
#include <vector>

using namespace std;

// Hàm khởi tạo ma trận
vector<vector<int>> khoiTaoMaTran(string tenMaTran) {
  int soHang, soCot;
  cout << "Nhap so hang cua ma tran " << tenMaTran << ": ";
  cin >> soHang;
  cout << "Nhap so cot cua ma tran " << tenMaTran << ": ";
  cin >> soCot;

  vector<vector<int>> maTran(soHang, vector<int>(soCot));
  cout << "Nhap gia tri cho ma tran " << tenMaTran << ":\n";
  for (int i = 0; i < soHang; ++i) {
    for (int j = 0; j < soCot; ++j) {
      cin >> maTran[i][j];
    }
  }

  return maTran;
}

// Hàm thêm padding vào ma trận
vector<vector<int>> themPadding(const vector<vector<int>> &maTran, int padding) {
  int soHang = maTran.size() + 2 * padding;
  int soCot = maTran[0].size() + 2 * padding;

  vector<vector<int>> maTranPadding(soHang, vector<int>(soCot, 0));
  for (int i = 0; i < maTran.size(); ++i) {
    for (int j = 0; j < maTran[0].size(); ++j) {
      maTranPadding[i + padding][j + padding] = maTran[i][j];
    }
  }

  return maTranPadding;
}

// Hàm tính tích chập
vector<vector<int>> tinhTichChap(const vector<vector<int>> &maTran,
                                  const vector<vector<int>> &kernel,
                                  int stride) {
  int soHangKetQua = (maTran.size() - kernel.size()) / stride + 1;
  int soCotKetQua = (maTran[0].size() - kernel[0].size()) / stride + 1;

  vector<vector<int>> ketQua(soHangKetQua, vector<int>(soCotKetQua));

  for (int i = 0; i < soHangKetQua; ++i) {
    for (int j = 0; j < soCotKetQua; ++j) {
      int sum = 0;
      for (int k = 0; k < kernel.size(); ++k) {
        for (int l = 0; l < kernel[0].size(); ++l) {
          sum += maTran[i * stride + k][j * stride + l] * kernel[k][l];
        }
      }
      ketQua[i][j] = sum;
    }
  }

  return ketQua;
}

// Hàm in ma trận
void inMaTran(const vector<vector<int>> &maTran) {
  for (const auto &hang : maTran) {
    for (int giaTri : hang) {
      cout << giaTri << " ";
    }
    cout << endl;
  }
}

int main() {
  // Khởi tạo ma trận đầu vào
  vector<vector<int>> maTranDauVao = khoiTaoMaTran("dau vao");

  // Khởi tạo kernel
  vector<vector<int>> kernel = khoiTaoMaTran("kernel");

  // Nhập kích thước padding và stride
  int padding, stride;
  cout << "Nhap kich thuoc padding: ";
  cin >> padding;
  cout << "Nhap stride: ";   
  cin >> stride;

  // Thêm padding vào ma trận đầu vào
  vector<vector<int>> maTranPadding = themPadding(maTranDauVao, padding);

  // Tính tích chập
  vector<vector<int>> ketQua =
      tinhTichChap(maTranPadding, kernel, stride);

  // In kết quả
  cout << "Ma tran ket qua:\n";
  inMaTran(ketQua);

  return 0;
}