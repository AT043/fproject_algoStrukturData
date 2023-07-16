#include <bits/stdc++.h>

using namespace std;

int jumlahItem;
string mainChoice, gudangChoice;

//fungsi untuk generate kode barang
int kode() {
    srand((unsigned)time(NULL));
    int random = 1000 + (rand() % 2000);
    cout << random << endl;
    return random;
}

//fungsi untuk mendapatkan tanggal dengan format YYYYMMDD
int getCurrentDate() {
    // Get the current time
    time_t now = time(nullptr);

    // Convert the current time to a struct tm
    std::tm* currentTime = std::localtime(&now);

    // Extract the year, month, and day components
    int year = currentTime->tm_year + 1900;  // tm_year represents years since 1900
    int month = currentTime->tm_mon + 1;     // tm_mon represents months since January (0-11)
    int day = currentTime->tm_mday;          // tm_mday represents day of the month (1-31)

    // Combine the components into a single integer in the format YYYYMMDD
    int currentDate = year * 10000 + month * 100 + day;

    return currentDate;
}

struct Barang {
    long long kodeMsk;
    string nama;
    long long jumlah;
    int tglMsk;
    string bahan;
    string asal;
    string tujuan;
};

//data toko cabang per-wilayah gudang
struct Cabang {
    string gudangA[10];
    string gudangB[10];
    string gudangC[10];
};

Cabang cabang = { {"depok", "tangerang", "bandung", "bekasi", "cirebon", "karawang"},
                  {"solo", "semarang", "yogyakarta", "purwokerto", "cilacap"},
                  {"surabaya", "malang", "banyuwangi", "bali", "jember"} };


void border() {
    char x = '=';
    for (int i = 0; i < 36; i++) {
        cout << x;
    }
    cout << "\n";
}

//fungsi untuk menambahkan barang masuk ke gudang
void tambahBarang(vector<Barang>& gudang) {
    long long kodeMasukBarang;
    string namaBarang;
    long long jumlahBarang;
    int tglMskBarang;
    string bahanBarang;
    string asalBarang;
    string tujuanBarang;

    kodeMasukBarang = kode();
   
    cout << "Masukkan banyak barang: ";
	cin >> jumlahBarang;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	cout << "Masukkan nama barang: ";
	getline(cin, namaBarang); transform(namaBarang.begin(), namaBarang.end(), namaBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });

    tglMskBarang = getCurrentDate();
    
    cout << "Masukkan bahan barang: ";
    getline(cin, bahanBarang); transform(bahanBarang.begin(), bahanBarang.end(), bahanBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });
    cout << "Masukkan asal barang: ";
	getline(cin, asalBarang); transform(asalBarang.begin(), asalBarang.end(), asalBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });
	cout << "Masukkan tujuan barang: ";
	getline(cin, tujuanBarang); transform(tujuanBarang.begin(), tujuanBarang.end(), tujuanBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });
	
	
    Barang barang{ kodeMasukBarang, namaBarang, jumlahBarang, tglMskBarang, bahanBarang, asalBarang, tujuanBarang };
    gudang.push_back(barang);
    
	border();
    cout << "Barang berhasil ditambahkan ke gudang.\n\n";
}

void tampilkanDaftarBarang(const vector<Barang>& gudang) {
    map<string, vector<Barang>> groupedBarang;

    // Grouping data Barang berdasarkan tujuanBarang
    for (const Barang& barang : gudang) {
        groupedBarang[barang.tujuan].push_back(barang);
    }

    // Iterate over the groupedBarang map and display the grouped Barang objects
    // Loop
    for (const auto& entry : groupedBarang) {
        const string& tujuanBarang = entry.first;
        const vector<Barang>& barangGroup = entry.second;

        cout << "Tujuan Barang: " << tujuanBarang << endl;

        for (const Barang& barang : barangGroup) {
            cout << "\nkode masuk barang: " << barang.kodeMsk << "\n";
            cout << "nama barang: " << barang.nama << "\n";
            cout << "jumlah barang: " << barang.jumlah << " unit\n";
            cout << "tanggal barang masuk: " << barang.tglMsk << "\n";
            cout << "bahan barang: " << barang.bahan << "\n";
            cout << "asal barang: " << barang.asal << "\n";
            cout << "tujuan barang: " << barang.tujuan << "\n\n";
            border();
        }

        cout << endl;
    }
}

//fungsi untuk menampilkan 5 data barang paling lama di gudang
void tampilkanDaftarBarangMasuk(const vector<Barang>& gudang) {
    int index = 0;
    for (const Barang& barang : gudang) {
    	cout << "\nkode masuk barang: "<<barang.kodeMsk<<"\n";
        cout << "nama barang: " << barang.nama << "\n";
        cout << "jumlah barang: " << barang.jumlah << " unit\n";
        cout << "tanggal barang masuk: "<<barang.tglMsk<<"\n";
        cout << "bahan barang: " << barang.bahan << "\n";
        cout << "asal barang: " << barang.asal << "\n";
        cout << "tujuan barang: "<< barang.tujuan << "\n\n";
        cout << 
        index++;
        border();
        if (index == 5) {
            break;
        } else {
        	continue;
		}
        
    }
    cout << endl;
}

//fungsi untuk menemukan barang berdasarkan nama barangnya
void temukanBarang(const vector<Barang>& gudang) {
    string namaBarang;

    cout << "Masukkan nama barang yang ingin dicari: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, namaBarang); 
	transform(namaBarang.begin(), namaBarang.end(), namaBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });

    bool barangDitemukan = false;
    for (const Barang& barang : gudang) {
        if (barang.nama == namaBarang) {
            barangDitemukan = true;
            cout << "\nBarang ditemukan:\n";
            cout << "kode masuk barang: " << barang.kodeMsk << "\n";
            cout << "nama barang: " << barang.nama << "\n";
            cout << "jumlah barang: " << barang.jumlah << " unit\n";
            cout << "tanggal barang masuk: "<<barang.tglMsk<<"\n";
            cout << "bahan barang: " << barang.bahan << "\n";
            cout << "asal barang: " << barang.asal << "\n";
            cout << "tujuan barang: "<< barang.tujuan << "\n\n";
            border();
            //break;
        }
    }

    if (!barangDitemukan) {
        cout << "Barang tidak ditemukan\n";
    }
}

// Fungsi untuk menghapus barang keluar dari gudang
void hapusBarang(vector<Barang>& gudang) {
    string namaBarang;
    long long jumlahBarang;

    cout << "Masukkan nama barang yang ingin dipindah: ";
    cin.ignore();getline(cin, namaBarang); transform(namaBarang.begin(), namaBarang.end(), namaBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });
    
    cout<<"Masukkan jumlah barang yang akan dipindah: ";
    cin >> jumlahBarang;

    bool barangDitemukan = false;
    for (auto it = gudang.begin(); it != gudang.end(); ++it) {
       
        if (it->nama == namaBarang && it->jumlah >= jumlahBarang) {
            it->jumlah -= jumlahBarang;
            
            
            // Cek jika jumlahBarang == 0, maka Barang dihapus
            if (it->jumlah == 0) {
                gudang.erase(it);
                barangDitemukan = true;
            	break;
            }

        }
    }

    if (barangDitemukan) {
        cout << "Barang sedang dikirim ke toko tujuan.\n\n";
    } else {
        cout << "Barang tidak ditemukan di gudang.\n\n";
    }
}

// Fungsi untuk memindahkan barang antar gudang
void pindahkanBarang(vector<Barang>& gudangAsal, vector<Barang>& gudangTujuan) {
	
	long long kodeMasukBarang = kode();
	
    string namaBarang;

    cout << "Masukkan nama barang yang ingin dipindahkan: ";
    getline(cin, namaBarang); transform(namaBarang.begin(), namaBarang.end(), namaBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });  
    
    long long jumlahBarang;

    cout << "Masukkan jumlah barang yang ingin dipindahkan: ";
    cin >> jumlahBarang;
    
    int tglMskBarang = getCurrentDate();
    
    string bahanBarang;
    
    cout << "Masukkan bahan barang: ";
    cin.ignore();getline(cin, bahanBarang);transform(bahanBarang.begin(), bahanBarang.end(), bahanBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });
    
    string asalBarang;
    
    cout << "Masukkan asal barang: ";
    getline(cin, asalBarang);transform(asalBarang.begin(), asalBarang.end(), asalBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });
    
    string tujuanBarang;
    
    cout << "Masukkan tujuan barang: ";
    getline(cin, tujuanBarang);transform(tujuanBarang.begin(), tujuanBarang.end(), tujuanBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });

    bool barangDitemukan = false;
    for (auto it = gudangAsal.begin(); it != gudangAsal.end(); ++it) {
        if (it->nama == namaBarang && it->jumlah >= jumlahBarang) {
            it->jumlah -= jumlahBarang;
            
            // Mengecek jumlahBarang jika 0 maka data dihapus;
            if (it->jumlah == 0) {
                gudangAsal.erase(it);
            }

            // Mencari barang dengan nama yang sama di gudang tujuan;	
            bool barangDitemukanTujuan = false;
            for (Barang& barangTujuan : gudangTujuan) {
                if (barangTujuan.nama == namaBarang) {
                	barangTujuan.kodeMsk = kodeMasukBarang;
                    barangTujuan.jumlah += jumlahBarang;
                    barangTujuan.tglMsk = tglMskBarang;
                    barangTujuan.bahan = bahanBarang;
                    barangTujuan.asal = asalBarang;
                    barangTujuan.tujuan = tujuanBarang;
                    barangDitemukanTujuan = true;
                    break;
                }
            }

            // Jika barang dengan nama yang sama tidak ada di gudang tujuan, tambahkan barang baru
            if (!barangDitemukanTujuan) {
                Barang barangTujuan;
                barangTujuan.kodeMsk = kodeMasukBarang;
				barangTujuan.nama = namaBarang;
				barangTujuan.jumlah = jumlahBarang;
				barangTujuan.tglMsk = tglMskBarang;
				barangTujuan.bahan = bahanBarang;
				barangTujuan.asal = asalBarang;
				barangTujuan.tujuan = tujuanBarang;
				gudangTujuan.push_back(barangTujuan);		
            }

            barangDitemukan = true;
            break;
        }
    }

    if (barangDitemukan) {
        cout << "Barang berhasil dipindahkan antar gudang.\n\n";
    } else {
        cout << "Barang tidak ditemukan di gudang atau jumlah barang yang diminta melebihi stok.\n\n";
    }
}

void mainHeader() {
    border();
    cout << "\n ===Sistem Gudang Toko Dono===\n\n";
    border();
}

void menuChoiceHeader() {
    border();
    if (mainChoice == "1") {
        cout << "\nBuka Akses Ke Gudang \n";
    }
    else if (mainChoice == "2") {
        cout << "Data Barang Masuk\n";
    }
    else if (mainChoice == "3") {
        cout << "Pencarian Barang\n";
    }
    else if (mainChoice == "4") {
        cout << "Info Gudang dan Toko Dono\n";
    }
    else if(mainChoice == "5"){
    	cout<<"Keluar dari Aplikasi\n";
	}
    border();
}

void aksesGudangHeader() {
    border();
    if (gudangChoice == "1") {
        cout << "Anda Sedang Berada di Gudang A \"Depok\" \n";
    }
    else if (gudangChoice == "2") {
        cout << "Anda Sedang Berada di Gudang B \"Solo\" \n";
    }
    else if (gudangChoice == "3") {
        cout << "Anda Sedang Berada di Gudang C \"Surabaya\" \n";
    }
    else if (gudangChoice == "4") {
        cout << "\n";
    }
    else {
        cout << "\nWrong Input!\n";
    }
    border();
}

int main() {
    vector<Barang> gudangA;
    vector<Barang> gudangB;
    vector<Barang> gudangC;
    
    bool mainBack;
    do {
        mainHeader();
        cout << "\nKetik:\n 1 Untuk Buka Akses Gudang\n 2 Untuk Cek Barang Masuk\n 3 Untuk Cari Barang\n 4 Untuk Info Gudang\n 5 Untuk Keluar\n\n";
        border();
        cin >> mainChoice;
        border();
        system("cls");
        if (mainChoice == "1") {
            bool gudangBack;
            do {
                menuChoiceHeader();
                cout << "\nKetik:\n 1 Untuk Masuk ke Gudang A\n 2 Untuk Masuk ke Gudang B\n 3 Untuk Masuk ke Gudang C\n 4 Untuk Kembali ke Menu Awal\n\n";
                border();
                cin >> gudangChoice;
                system("cls");
                string pilihanGudangA;
                if (gudangChoice == "1") {
                    aksesGudangHeader();
                    cout << "\nKetik:\n 1 Untuk Cek Barang Gudang A\n 2 Untuk Tambah Barang Masuk\n 3 Untuk Tambah Barang Keluar\n 4 Untuk Kembali ke Menu Akses Gudang\n 5 Untuk Kembali Ke Main Menu\n\n";
                    border();
                    cin >> pilihanGudangA;
                    system("pause");
                    system("cls");
                    if (pilihanGudangA == "1") {
                        aksesGudangHeader();
                        tampilkanDaftarBarang(gudangA);
                        string barangGudangA;
                        cout << "\n";
                        border();
                        cout << "Ketik:\n 1 Untuk Cari Barang\n 2 Untuk Kembali ke Menu Gudang\n";
                        border();
                        cin >> barangGudangA;
                        system("cls");
                        if (barangGudangA == "1") {
                        	int temukanBarangA;
                        	string temukanBarangChoice;
                        	do {
                        		aksesGudangHeader();
                            	temukanBarang(gudangA);
                            	border();
                            	cout<<"ketik:\n 1 Untuk cari barang lagi\n 2 Untuk kembali ke menu gudang\n";
                            	cin>>temukanBarangChoice;
                            	if(temukanBarangChoice == "1"){
                            		temukanBarangA = 1;
                            		system("cls");
                            	} else if(temukanBarangChoice == "2"){
                            		temukanBarangA = 0;
                            		gudangBack = true;
                            		system("cls");
								}
							} while(temukanBarangA == 1);
                        	
                        }
                        else if (barangGudangA == "2") {
                            gudangBack = true;
                            system("cls");
                        }
                        system("pause");
                        system("cls");
                        gudangBack = true;
                    }
                    else if (pilihanGudangA == "2") {
                        int backTambahGudangA;

                        do {
                            string tambahGudangA;
                            aksesGudangHeader();
                            cout << "Jumlah item: ";
                            cin >> jumlahItem;
                            border();
                            cout << "\n";
                            for (int i = 0; i < jumlahItem; i++) {
                                tambahBarang(gudangA);
                                border();
                            }
                            cout << "\n";
                            border();
                            cout << "Ketik:\n 1 Untuk Tambah Barang Lagi\n 2 Untuk Kembali ke Menu Gudang A\n";
                            cin >> tambahGudangA;
                            border();
                            system("pause");
                            system("cls");
                            if (tambahGudangA == "1") {
                                system("cls");
                                backTambahGudangA = 1;
                            }
                            else if (tambahGudangA == "2") {
                                system("cls");
                                backTambahGudangA = 0;
                                mainBack = false;
                                gudangBack = true;
                            }
                            else {
                                aksesGudangHeader();
                                cout << "\nMaaf masukkan Anda Salah,\nAnda akan dialihkan ke Menu gudang\n";
                                border();
                                system("pause");
                                system("cls");
                                gudangBack = true;
                            }
                        } while (backTambahGudangA == 1);

                    }
                    else if (pilihanGudangA == "3") {
                        border();
                        cout << "\n";
                        aksesGudangHeader();
                        string tujuanBarang;
                        cout<<"\nmasukkan tujuan barang: \n";
                        cin.ignore();getline(cin, tujuanBarang);transform(tujuanBarang.begin(), tujuanBarang.end(), tujuanBarang.begin(), [](unsigned char c) {
        					return tolower(c);
    					});
                        border();
                        int size = sizeof(cabang.gudangA) / sizeof(cabang.gudangA[0]);
						bool ketemu = false;
						for (int i = 0; i < size; i++) {
    						if (tujuanBarang == cabang.gudangA[i]) {
        						ketemu = true;
        						hapusBarang(gudangA);
        						break;
    						}
						}

						int sizeB = sizeof(cabang.gudangB) / sizeof(cabang.gudangB[0]);
						bool ketemuB = false;
						for (int i = 0; i < sizeB; i++) {
    						if (tujuanBarang == cabang.gudangB[i]) {
        						ketemuB = true;
        						pindahkanBarang(gudangA, gudangB);
        						break;
    						}
						}

						int sizeC = sizeof(cabang.gudangC) / sizeof(cabang.gudangC[0]);
						bool ketemuC = false;
						for (int i = 0; i < sizeC; i++) {
    						if (tujuanBarang == cabang.gudangC[i]) {
        						ketemuC = true;
        						pindahkanBarang(gudangA, gudangC);
        						break;
    						}
						}

						if (!ketemu && !ketemuB && !ketemuC) {
    						cout << "Maaf toko/gudang Dono belum tersedia di kota tersebut\n";
						}

					border();
					system("pause");
					system("cls");
					gudangBack = true;

                    }
                    else if (pilihanGudangA == "4") {
                        system("cls");
                        gudangBack = true;
                    }
                    else if (pilihanGudangA == "5") {
                        system("cls");
                        gudangBack = false;
                        mainBack = true;
                    }
                    else {
                        aksesGudangHeader();
                        cout << "\nMaaf masukkan Anda salah,\nAnda akan dialihkan ke Menu Gudang\n";
                        border();
                        system("pause");
                        system("cls");
                        gudangBack = true;
                    }
                }
                else if (gudangChoice == "2") {
                    string pilihanGudangB;
                    border();
                    cout << "\n";
                    aksesGudangHeader();
                    cout << "\nKetik:\n 1 Untuk Cek Barang Gudang B\n 2 Untuk Tambah Barang Masuk\n 3 Untuk Tambah Barang Keluar\n 4 Untuk Kembali ke Menu Gudang\n 5 Untuk Kembali ke Main Menu\n\n";
                    border();
                    cin >> pilihanGudangB;
                    system("cls");
                    if (pilihanGudangB == "1") {
                        aksesGudangHeader();
                        tampilkanDaftarBarang(gudangB);
                        string barangGudangB;
                        cout << "\n";
                        border();
                        cout << "\nKetik: 1 Untuk Cari Barang\n 2 Untuk Kembali ke Menu Gudang\n";
                        border();
                        cin >> barangGudangB;
                        system("cls");
                        if (barangGudangB == "1") {
                            temukanBarang(gudangB);
                        }
                        else if (barangGudangB == "2") {
                            gudangBack = true;
                            system("cls");
                        }
                        system("pause");
                        system("cls");
                        gudangBack = true;
                    }
                    else if (pilihanGudangB == "2") {
                        int backTambahGudangB;
                        do {
                            string tambahGudangB;
                            aksesGudangHeader();
                            cout << "Masukkan jumlah barang masuk: ";
                            cin >> jumlahItem;
                            border();
                            cout << "\n";
                            for (int i = 0; i < jumlahItem; i++) {
                                tambahBarang(gudangB);
                                border();
                            }
                            cout << "\n";
                            border();
                            cout << "Ketik\n 1 Untuk Tambah Barang Lagi\n 2 Untuk Kembali ke Menu Gudang\n";
                            cin >> tambahGudangB;
                            border();
                            system("pause");
                            system("cls");
                            if (tambahGudangB == "1") {
                                system("cls");
                                backTambahGudangB = 1;
                            }
                            else if (tambahGudangB == "2") {
                                system("cls");
                                backTambahGudangB = 0;
                                mainBack = false;
                                gudangBack = true;
                            }
                            else {
                                aksesGudangHeader();
                                cout << "\nMaaf Masukkan Anda Salah,\nAnda akan dialihkan ke menu gudang\n";
                                border();
                                system("pause");
                                system("cls");
                            	backTambahGudangB = 0;
                                gudangBack = true;
                            }
                        } while (backTambahGudangB == 1);

                    }
                    else if (pilihanGudangB == "3") {
                        border();
                        cout << "\n";
                        aksesGudangHeader();
                        string tujuanBarang;
                        cout<<"\nmasukkan tujuan barang: \n";
                        cin.ignore();getline(cin, tujuanBarang);transform(tujuanBarang.begin(), tujuanBarang.end(), tujuanBarang.begin(), [](unsigned char c) {
        					return tolower(c);
    					});
                        border();
                        int size = sizeof(cabang.gudangB) / sizeof(cabang.gudangB[0]);
						bool ketemu = false;
						for (int i = 0; i < size; i++) {
    						if (tujuanBarang == cabang.gudangB[i]) {
        						ketemu = true;
        						hapusBarang(gudangA);
        						break;
    						}
						}

						int sizeA = sizeof(cabang.gudangA) / sizeof(cabang.gudangA[0]);
						bool ketemuA = false;
						for (int i = 0; i < sizeA; i++) {
    						if (tujuanBarang == cabang.gudangA[i]) {
        						ketemuA = true;
        						pindahkanBarang(gudangB, gudangA);
        						break;
    						}
						}

						int sizeC = sizeof(cabang.gudangC) / sizeof(cabang.gudangC[0]);
						bool ketemuC = false;
						for (int i = 0; i < sizeC; i++) {
    						if (tujuanBarang == cabang.gudangC[i]) {
        						ketemuC = true;
        						pindahkanBarang(gudangB, gudangC);
        						break;
    						}
						}

						if (!ketemu && !ketemuA && !ketemuC) {
    						cout << "Maaf toko/gudang Dono belum tersedia di kota tersebut\n";
						}
					border();
					system("pause");
					system("cls");
					gudangBack = true;

                    }
                    else if (pilihanGudangB == "4") {
                        system("cls");
                        gudangBack = true;
                    }
                    else if (pilihanGudangB == "5") {
                        system("cls");
                        gudangBack = false;
                        mainBack = true;
                    }
                    else {
                        aksesGudangHeader();
                        cout << "\nMaaf Masukkan Anda Salah, Anda akan dialihkan ke Menu gudang\n";
                        border();
                        system("pause");
                        system("cls");
                        gudangBack = true;
                    }
                }
                else if (gudangChoice == "3") {
                    border();
                    cout << "\n";
                    string pilihanGudangC;
                    aksesGudangHeader();
                    cout << "\nKetik:\n 1 Untuk Cek Barang Gudang C\n 2 Tambah Barang Masuk\n 3 Tambah Barang Keluar\n 4 Back to Akses Gudang\n 5 Back to Main Menu\n\n";
                    border();
                    cin >> pilihanGudangC;
                    system("cls");
                    if (pilihanGudangC == "1") {
                        aksesGudangHeader();
                        tampilkanDaftarBarang(gudangC);
                        string barangGudangC;
                        cout << "\n";
                        border();
                        cout << "\nKetik:\n 1 Cari Barang\n 2 Kembali\n";
                        border();
                        cin >> barangGudangC;
                        system("cls");
                        if (barangGudangC == "1") {
                            temukanBarang(gudangC);
                        }
                        else if (barangGudangC == "2") {
                            gudangBack = true;
                            system("cls");
                        }
                        system("pause");
                        system("cls");
                        gudangBack = true;
                    }
                    else if (pilihanGudangC == "2") {
                        int backTambahGudangC;

                        do {
                            string tambahGudangC;
                            aksesGudangHeader();
                            cout << "Masukkan jumlah barang masuk: ";
                            cin >> jumlahItem;
                            border();
                            cout << "\n";
                            for (int i = 0; i < jumlahItem; i++) {
                                tambahBarang(gudangC);
                                border();
                            }
                            cout << "\n";
                            border();
                            cout << "\nKetik:\n 1 Tambah Barang Lagi\n 2 Kembali\n";
                            cin >> tambahGudangC;
                            border();
                            system("pause");
                            system("cls");
                            if (tambahGudangC == "1") {
                                system("cls");
                                backTambahGudangC = 1;
                            }
                            else if (tambahGudangC == "2") {
                                system("cls");
                                backTambahGudangC = 0;
                                mainBack = false;
                                gudangBack = true;
                            }
                            else {
                                aksesGudangHeader();
                                cout << "\nMaaf masukkan Anda salah,\nAnda akan dialihkan ke Menu gudang\n";
                                border();
                                system("pause");
                                system("cls");
                                gudangBack = true;
                            }
                        } while (backTambahGudangC == 1);

                    }
                    else if (pilihanGudangC == "3") {
                        border();
                        cout << "\n";
                        aksesGudangHeader();
                        string tujuanBarang;
                        cout<<"\nmasukkan tujuan barang: \n";
                        cin.ignore();getline(cin, tujuanBarang);transform(tujuanBarang.begin(), tujuanBarang.end(), tujuanBarang.begin(), [](unsigned char c) {
        					return tolower(c);
    					});
                        border();
                        int size = sizeof(cabang.gudangC) / sizeof(cabang.gudangC[0]);
						bool ketemu = false;
						for (int i = 0; i < size; i++) {
    						if (tujuanBarang == cabang.gudangC[i]) {
        						ketemu = true;
        						hapusBarang(gudangA);
        						break;
    						}
						}

						int sizeA = sizeof(cabang.gudangA) / sizeof(cabang.gudangA[0]);
						bool ketemuA = false;
						for (int i = 0; i < sizeA; i++) {
    						if (tujuanBarang == cabang.gudangA[i]) {
        						ketemuA = true;
        						pindahkanBarang(gudangC, gudangA);
        						break;
    						}
						}

						int sizeB = sizeof(cabang.gudangB) / sizeof(cabang.gudangB[0]);
						bool ketemuB = false;
						for (int i = 0; i < sizeB; i++) {
    						if (tujuanBarang == cabang.gudangB[i]) {
        						ketemuB = true;
        						pindahkanBarang(gudangC, gudangB);
        						break;
    						}
						}

						if (!ketemu && !ketemuA && !ketemuB) {
    						cout << "Maaf toko/gudang Dono belum tersedia di kota tersebut\n";
						}

					cout << "\n";
					border();
					system("pause");
					system("cls");
					gudangBack = true;

                    }
                    else if (pilihanGudangC == "4") {
                        system("cls");
                        gudangBack = true;
                    }
                    else if (pilihanGudangC == "5") {
                        system("cls");
                        gudangBack = false;
                        mainBack = true;
                    }
                    else {
                        aksesGudangHeader();
                        cout << "\nMaaf masukkan Anda salah,\nAnda akan dialihkan ke menu gudang\n";
                        border();
                        system("pause");
                        system("cls");
                        gudangBack = true;
                    }
                }
                else if (gudangChoice == "4") {
                    system("cls");
                    gudangBack = false;
                    mainBack = true;
                }
                else {
                    aksesGudangHeader();
                    cout << "\nMaaf masukkan Anda salah,\nAnda akan dialihkan ke menu gudang\n";
                    border();
                    system("pause");
                    system("cls");
                    gudangBack = true;
                }
            } while (gudangBack == true);

        }
        else if (mainChoice == "2") {
            menuChoiceHeader();
            cout<<"\nBarang Masuk Gudang A \n\n";
            border();
            tampilkanDaftarBarangMasuk(gudangA);
            border();
            cout<<"\nBarang Masuk Gudang B \n\n";
            border();
            tampilkanDaftarBarangMasuk(gudangB);
            border();
            cout<<"\nBarang Masuk Gudang C \n\n";
            border();
            tampilkanDaftarBarangMasuk(gudangC);
            border();
            system("pause");
            system("cls");
            mainBack = true;
        }
        else if (mainChoice == "3") {
            string pilCariGudang;
            menuChoiceHeader();
            cout << "\nKetik:\n 1 Untuk Cari Barang di Gudang A\n 2 Untuk Cari Barang di Gudang B\n 3 Untuk Cari Barang di Gudang C\n\n";
            border();
            cin >> pilCariGudang;
            system("cls");
            border();
            if (pilCariGudang == "1"){
            	menuChoiceHeader();
            	temukanBarang(gudangA);
            	system("pause");
            	system("cls");
            	mainBack = true;
			} else if(pilCariGudang == "2"){
				menuChoiceHeader();
				temukanBarang(gudangB);
				system("pause");
				system("cls");
				mainBack = true;
			} else if(pilCariGudang == "3"){
				menuChoiceHeader();
				temukanBarang(gudangC);
				system("pause");
				system("cls");
				mainBack = true;
			} else {
				mainHeader();
            	cout << "\nMaaf masukkan Anda salah,\nAnda akan dialihkan ke Main Menu\n";
            	border();
            	system("pause");
            	system("cls");
            	mainBack = true;
			}
            
            
        }
        else if (mainChoice == "4") {
        	string infoGudang;
            menuChoiceHeader();
            cout<<"Ketik:\n 1 Untuk melihat info Toko Dono\n 2 Untuk melihat wilayah Gudang dan cabang Toko Dono\n 3 Untuk Kembali ke menu utama\n";
            border();
            cin>>infoGudang;
            system("cls");
            if (infoGudang == "1"){
            	menuChoiceHeader();
            	cout<<"\nInformasi lebih lanjut hubungi: \n1. 08999999999 (Toko Dono Depok)\n2. 08777777777 (Toko Dono Solo)\n3. 0855555555 (Toko Dono Surabaya)\n email: cs@tokodono.com\n\n";
            	border();
            	system("pause");
            	system("cls");
            	mainBack = true;
			} else if(infoGudang == "2"){
				menuChoiceHeader();
				cout<<"\n1. Gudang A-Depok (Depok, Tangerang, Bandung, Bekasi, Karawang)\n2. Gudang B-Solo (Solo Raya, Semarang, Purwokerto, Cilacap)\n3. Gudang C-Surabaya (Surabaya, Malang, Banyuwangi, Jember, Bali)\n";
				system("pause");
				system("cls");
				mainBack = true;
			} else if(infoGudang == "3"){
				menuChoiceHeader();
				cout<<"kembali ke menu utama\n";
				system("pause");
				system("cls");
				mainBack = true;
			}
        } else if (mainChoice == "5"){
        	string quit;
			menuChoiceHeader();
			cout<<"\nYakin ingin keluar dari aplikasi?\njika Anda keluar maka seluruh data\nakan ter-reset ulang\n\n";
			border();
			cout<<"\nKetik:\n 1 Untuk Keluar\n 2 Untuk Kembali ke menu utama\n";
			border();
			cin>>quit;
			if(quit=="1"){
				system("pause");
				return 0;
			} else if(quit=="2"){
				system("cls");
				mainBack = true;
			} else {
				cout << "\nMaaf masukkan Anda salah,\nAnda akan dialihkan ke menu utama\n";
            	border();
            	system("pause");
            	system("cls");
            	mainBack = true;
			}
		} else {
            mainHeader();
            cout << "\nMaaf masukkan Anda salah,\nAnda akan dialihkan ke menu utama\n";
            border();
            system("pause");
            system("cls");
            mainBack = true;
        }

    } while (mainBack == true);

    return 0;
}

