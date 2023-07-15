#include <bits/stdc++.h>

using namespace std;

int jumlahItem;
string mainChoice, gudangChoice;

int kode() {
    srand((unsigned)time(NULL));
    int random = 1000 + (rand() % 2000);
    cout << random << endl;
    return random;
}

int time(){
	time_t my_time = time(NULL);
	cout<<ctime(&my_time);
	return 0;
}

struct Barang {
    long long kodeMsk;
    string nama;
    long long jumlah;
    long long tglMsk;
    string bahan;
    string asal;
};

struct Cabang {
    string gudangA[10];
    string gudangB[10];
    string gudangC[10];
};

Cabang cabang = { {"depok", "jakarta", "bandung", "bekasi", "cirebon", "karawang", "lampung"},
                  {"solo", "semarang", "yogyakarta", "purwokerto", "cilacap"},
                  {"surabaya", "malang", "banyuwangi", "bali", "jember"} };

void border() {
    char x = '=';
    for (int i = 0; i < 36; i++) {
        cout << x;
    }
    cout << "\n";
}

void tambahBarang(vector<Barang>& gudang) {
    long long kodeMasukBarang;
    string namaBarang;
    long long jumlahBarang;
    long long tglMskBarang;
    string bahanBarang;
    string asalBarang;

    kodeMasukBarang = kode();
    cout << "Masukkan nama barang: ";
   
    cin.ignore();getline(cin, namaBarang); transform(namaBarang.begin(), namaBarang.end(), namaBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });
    cout << "Masukkan jumlah barang: ";
    cin >> jumlahBarang; 
    
    tglMskBarang = time();
    
    cout << "Masukkan bahan barang: ";
    cin.ignore();getline(cin, bahanBarang); transform(bahanBarang.begin(), bahanBarang.end(), bahanBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });
    cout << "Masukkan asal barang: ";
	getline(cin, asalBarang); transform(asalBarang.begin(), asalBarang.end(), asalBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });
	
    Barang barang{ kodeMasukBarang, namaBarang, jumlahBarang, tglMskBarang, bahanBarang, asalBarang };
    gudang.push_back(barang);

    cout << "Barang berhasil ditambahkan ke gudang.\n\n";
}

void tampilkanDaftarBarang(const vector<Barang>& gudang) {
    for (const Barang& barang : gudang) {
        cout << "kode masuk barang: " << barang.kodeMsk << "\n";
        cout << "nama barang: " << barang.nama << "\n";
        cout << "jumlah barang: " << barang.jumlah << " unit\n";
        cout << "tanggal barang masuk: "<<barang.tglMsk<<"\n";
        cout << "bahan barang: " << barang.bahan << "\n";
        cout << "asal barang: " << barang.asal << "\n";
        border();
    }
    cout << endl;
}

void tampilkanDaftarBarangMasuk(const vector<Barang>& gudang) {
    int last_five = 0;
    for (const Barang& barang : gudang) {
    	cout << "kode masuk barang: "<<barang.kodeMsk<<"\n";
        cout << "nama barang: " << barang.nama << "\n";
        cout << "jumlah barang: " << barang.jumlah << " unit\n";
        cout << "tanggal barang masuk: "<<barang.tglMsk<<"\n";
        cout << "bahan barang: " << barang.bahan << "\n";
        cout << "asal barang: " << barang.asal << "\n";
        last_five++;
        border();
        if (last_five == 5) {
            break;
        } else {
        	continue;
		}
        
    }
    cout << endl;
}

void temukanBarang(const vector<Barang>& gudang) {
    string namaBarang;

    cout << "Masukkan nama barang yang ingin dicari: ";
    cin.ignore();getline(cin, namaBarang); transform(namaBarang.begin(), namaBarang.end(), namaBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });

    bool barangDitemukan = false;
    for (const Barang& barang : gudang) {
        if (barang.nama == namaBarang) {
            barangDitemukan = true;
            cout << "Barang ditemukan:\n";
            cout << "kode masuk barang: " << barang.kodeMsk << "\n";
            cout << "nama barang: " << barang.nama << "\n";
            cout << "jumlah barang: " << barang.jumlah << " unit\n";
            cout << "tanggal barang masuk: "<<barang.tglMsk<<"\n";
            cout << "bahan barang: " << barang.bahan << "\n";
            cout << "asal barang: " << barang.asal << "\n";
            border();
            //break;
        }
    }

    if (!barangDitemukan) {
        cout << "Barang tidak ditemukan\n";
    }
}

// Fungsi untuk menghapus barang dari gudang
void hapusBarang(vector<Barang>& gudang) {
    string namaBarang;
    long long jumlahBarang;

    cout << "Masukkan nama barang yang ingin dihapus: ";
    cin.ignore();getline(cin, namaBarang); transform(namaBarang.begin(), namaBarang.end(), namaBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });
    
    cout<<"Masukkan jumlah barang yang akan dipindah: ";
    cin >> jumlahBarang;

    bool barangDitemukan = false;
    for (auto it = gudang.begin(); it != gudang.end(); ++it) {
       
        if (it->nama == namaBarang && it->jumlah >= jumlahBarang) {
            it->jumlah -= jumlahBarang;
            
            
            // Check if jumlah becomes zero and erase the element
            if (it->jumlah == 0) {
                gudang.erase(it);
                barangDitemukan = true;
            	break;
            }

        }
    }

    if (barangDitemukan) {
        cout << "Barang sedang dikirim ke tempat tujuan.\n\n";
    } else {
        cout << "Barang tidak ditemukan di gudang.\n\n";
    }
}

// Fungsi untuk memindahkan barang antar gudang
void pindahkanBarang(vector<Barang>& gudangAsal, vector<Barang>& gudangTujuan) {
	
	long long kodeMasukBarang = kode();
	
    string namaBarang;

    cout << "Masukkan nama barang yang ingin dipindahkan: ";
    cin>>namaBarang;
    /*cin.ignore();getline(cin, namaBarang);transform(namaBarang.begin(), namaBarang.end(), namaBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });*/
    
    long long jumlahBarang;

    cout << "Masukkan jumlah barang yang ingin dipindahkan: ";
    cin >> jumlahBarang;
    
    long long tglMskBarang = time();
    
    string bahanBarang;
    
    cout << "Masukkan bahan barang: ";
    cin >> bahanBarang;
    /*cin.ignore();getline(cin, bahanBarang);transform(bahanBarang.begin(), bahanBarang.end(), bahanBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });*/
    
    string asalBarang;
    
    cout << "Masukkan asal barang: ";
    cin>>asalBarang;
    /*getline(cin, asalBarang);transform(asalBarang.begin(), asalBarang.end(), asalBarang.begin(), [](unsigned char c) {
        return tolower(c);
    });*/

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
				barangTujuan.bahan = bahanBarang;
				barangTujuan.asal = asalBarang;
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
    cout << "\n ===Sistem Gudang Dono Furniture===\n\n";
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
        cout << "Info Dono Furniture\n";
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
        cout << "\n1. Akses Gudang\n2. Cek Barang Masuk\n3. Cari Barang\n4. Info Gudang\n5. Keluar\n";
        border();
        cout << "Masukkan pilihan angka\nmisal pilih 2 untuk lihat barang masuk\n";
        border();
        cin >> mainChoice;
        border();
        system("cls");
        if (mainChoice == "1") {
            bool gudangBack;
            do {
                menuChoiceHeader();
                cout << "\n1. Gudang A\n2. Gudang B\n3. Gudang C\n4. Back\n";
                border();
                cin >> gudangChoice;
                system("cls");
                string pilihanGudangA;
                if (gudangChoice == "1") {
                    aksesGudangHeader();
                    cout << "\n1. Cek Barang Gudang A\n2. Tambah Barang Masuk\n3. Tambah Barang Keluar\n4. Back to Akses Gudang\n5. Back to Main Menu\n";
                    cout << "\n";
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
                        cout << "1. Cari Barang \n2. Kembali\n";
                        border();
                        cin >> barangGudangA;
                        if (barangGudangA == "1") {
                            temukanBarang(gudangA);
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
                            cout << "pilih: 1. Tambah Barang Lagi  2. Kembali\n";
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
                                cout << "\nSorry wrong input, you will be\ndirected to akses gudang menu\n";
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
                        cout<<"masukkan tujuan barang: \n";
                        border();
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
    						cout << "Tujuan barang tidak valid\n";
						}

					cout << "\n";
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
                        cout << "\nSorry wrong input, you will be\ndirected to akses gudang menu\n";
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
                    cout << "\n1. Cek Barang Gudang B\n2. Tambah Barang Masuk\n3. Tambah Barang Keluar\n4. Back to Akses Gudang\n5. Back to Main Menu\n";
                    cout << "\n";
                    border();
                    cin >> pilihanGudangB;
                    system("cls");
                    if (pilihanGudangB == "1") {
                        aksesGudangHeader();
                        tampilkanDaftarBarang(gudangB);
                        string barangGudangB;
                        cout << "\n";
                        border();
                        cout << "1. Cari Barang \n2. Kembali\n";
                        border();
                        cin >> barangGudangB;
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
                            cout << "Jumlah item: ";
                            cin >> jumlahItem;
                            border();
                            cout << "\n";
                            for (int i = 0; i < jumlahItem; i++) {
                                tambahBarang(gudangB);
                                border();
                            }
                            cout << "\n";
                            border();
                            cout << "pilih: 1. Tambah Barang Lagi  2. Kembali\n";
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
                                cout << "\nSorry wrong input, you will be\ndirected to akses gudang menu\n";
                                border();
                                system("pause");
                                system("cls");
                                gudangBack = true;
                            }
                        } while (backTambahGudangB == 1);

                    }
                    else if (pilihanGudangB == "3") {
                        border();
                        cout << "\n";
                        aksesGudangHeader();
                        string tujuanBarang;
                        cout<<"masukkan tujuan barang: \n";
                        border();
                        cin.ignore();getline(cin, tujuanBarang);transform(tujuanBarang.begin(), tujuanBarang.end(), tujuanBarang.begin(), [](unsigned char c) {
        					return tolower(c);
    					});
                        border();
                        int size = sizeof(cabang.gudangB) / sizeof(cabang.gudangB[0]);
						bool ketemu = false;
						for (int i = 0; i < size; i++) {
    						if (tujuanBarang == cabang.gudangB[i]) {
        						ketemu = true;
        						cout << "yeay";
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
    						cout << "Tujuan barang tidak valid\n";
						}

					cout << "\n";
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
                        cout << "\nSorry wrong input, you will be\ndirected to akses gudang menu\n";
                        border();
                        system("pause");
                        system("cls");
                        gudangBack = true;
                    }
                }
                else if (gudangChoice == "3") {
                    border();
                    cout << "\n";
                    aksesGudangHeader();
                    cout << "\n1. Cek Barang Gudang A\n2. Tambah Barang Masuk\n3. Tambah Barang Keluar\n4. Back to Akses Gudang\n5. Back to Main Menu\n";
                    cout << "\n";
                    border();
                }
                else if (gudangChoice == "4") {
                    system("cls");
                    gudangBack = false;
                    mainBack = true;
                }
                else {
                    aksesGudangHeader();
                    cout << "\nSorry wrong input, you will be\ndirected to akses gudang menu\n";
                    border();
                    system("pause");
                    system("cls");
                    gudangBack = true;
                }
            } while (gudangBack == true);

        }
        else if (mainChoice == "2") {
            menuChoiceHeader();
            cout<<"Barang Masuk Gudang A \n";
            tampilkanDaftarBarangMasuk(gudangA);
            border();
            cout<<"Barang Masuk Gudang B \n";
            tampilkanDaftarBarangMasuk(gudangB);
            border();
            cout<<"Barang Masuk Gudang C \n";
            tampilkanDaftarBarangMasuk(gudangC);
            border();
            system("pause");
            system("cls");
            mainBack = true;
        }
        else if (mainChoice == "3") {
            string pilCariGudang;
            menuChoiceHeader();
            cout << "Pilih Daftar Gudang: \n1. Gudang A Depok \n2. Gudang B Bandung \n3. Gudang C Solo\n";
            border();
            cin >> pilCariGudang;
            border();
            system("cls");
            if (pilCariGudang == "1") {
                temukanBarang(gudangA);
            }
            else if (pilCariGudang == "2") {
                temukanBarang(gudangB);
            }
            else if (pilCariGudang == "3") {
                temukanBarang(gudangC);
            }
            else {
                menuChoiceHeader();
                cout << "Sorry Wrong Input, you will be directed to main menu\n";
                system("pause");
                system("cls");
                mainBack = true;
            }
            border();
            system("pause");
            system("cls");
            mainBack = true;
        }
        else if (mainChoice == "4") {
        	string infoGudang;
            menuChoiceHeader();
            cout<<"\n1. Info Dono Furniture\n2. Info Gudang dan cabang\n3. Keluar\n";
            border();
            cin>>infoGudang;
            system("cls");
            if (infoGudang == "1"){
            	cout<<"Happy Birthday!\n";
            	border();
            	system("pause");
            	system("cls");
            	mainBack = true;
			} else if(infoGudang == "2"){
				cout<<"\n1. Gudang A-Depok (Depok, Jakarta, Bandung, Bekasi, Karawang, Lampung)\n2. Gudang B-Solo (Solo Raya, Semarang, Purwokerto, Cilacap)\n3. Gudang C-Surabaya (Surabaya, Malang, Banyuwangi, Jember, Bali)\n";
				system("pause");
				system("cls");
				mainBack = true;
			} else if(infoGudang == "3"){
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
			cout<<"1. Keluar  2. Kembali ke Menu utama\n";
			border();
			cin>>quit;
			if(quit=="1"){
				system("pause");
				return 0;
			} else if(quit=="2"){
				system("cls");
				mainBack = true;
			} else {
				cout << "\nSorry wrong input, you will be\ndirected to main menu\n";
            	border();
            	system("pause");
            	system("cls");
            	mainBack = true;
			}
		} else {
            mainHeader();
            cout << "\nSorry wrong input, you will be\ndirected to main menu\n";
            border();
            system("pause");
            system("cls");
            mainBack = true;
        }

    } while (mainBack == true);

    return 0;
}


