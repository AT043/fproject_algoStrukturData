#include <bits/stdc++.h>
using namespace std;

int ketemu=1;
string mainChoice, gudangChoice, menuGudangA, menuGudangB, menuGudangC;

struct Barang{
	string nama;
	long long jumlah;
	string bahan;
	//string ukuran_barang[1000];
	//int berat_barang[1000];
	//string jenis_barang[1000];
	//waktu_tiba;
	string asal;
}; Barang barang;

void border(){
	char x[2]="=";
	for (int i=0; i<36; i++){
		cout<<x;
	}
	cout<<"\n";
}

// Fungsi untuk menambahkan barang ke gudang
void tambahBarang(vector<Barang>& gudang) {
    string namaBarang;
    long long jumlahBarang;
    string bahanBarang;
    string asalBarang;

    cout << "Masukkan nama barang: ";
    cin >> namaBarang;
    cout << "Masukkan jumlah barang: ";
    cin >> jumlahBarang;
    cout<< "Masukkan bahan barang: ";
    cin>> bahanBarang;
    cout<< "Masukkan asal barang: ";
    cin>> asalBarang;

    Barang barang{namaBarang, jumlahBarang, bahanBarang, asalBarang};
    gudang.push_back(barang);

    cout << "Barang berhasil ditambahkan ke gudang.\n\n";
}

// Fungsi untuk menampilkan daftar barang di sebuah gudang
void tampilkanDaftarBarang(const vector<Barang>& gudang) {
    for (const Barang& barang : gudang) {
        cout <<"nama barang: "<<barang.nama <<"\n"; 
		cout <<"jumlah barang: "<<barang.jumlah << " unit\n";
		cout <<"bahan barang: "<<barang.bahan << "\n";
		cout <<"asal barang: "<<barang.asal << "\n";
		border();
    }
	cout<<endl;
}

void tampilkanDaftarBarangMasuk(const vector<Barang>& gudang){
	int last_five=0;
	for (const Barang& barang : gudang) {
        cout <<"nama barang: "<<barang.nama <<"\n"; 
		cout <<"jumlah barang: "<<barang.jumlah << " unit\n";
		cout <<"bahan barang: "<<barang.bahan << "\n";
		cout <<"asal barang: "<<barang.asal << "\n";
		border();
		if(last_five>5){
			break;
		}last_five++;
    }
	cout<<endl;
}

void temukanBarang(vector<Barang>& gudang) {
    string namaBarang;

    cout << "Masukkan nama barang yang ingin dicari: ";
    cin >> namaBarang;

    bool barangDitemukan = false;
    for (auto it = gudang.begin(); it != gudang.end(); ++it) {
        if (it->nama == namaBarang) {
            barangDitemukan = true;
            break;
        }
    }

    if (barangDitemukan) {
        cout << "Barang berhasil berada di gudang.\n\n";
        int ketemu+=1;
    } else {
        cout << "Barang tidak ditemukan di gudang.\n\n";
        int ketemu-=1;
    }
}

void mainHeader(){
	border();
	cout<<"\n ===Sistem Gudang Dono Furniture===\n\n";
	border();
}

void menuChoiceHeader(){
	border();
	if(mainChoice == "1"){
		cout<<"\nBuka Akses Ke Gudang \n";
	} else if(mainChoice == "2"){
		cout<<"Data Barang Masuk\n";
	} else if(mainChoice == "3"){
		cout<<"Data Barang Keluar\n";
	} else if(mainChoice == "4"){
		cout<<"Pencarian Barang \n";
	} 
	border();
}

void aksesGudangHeader() {
	border();
	if(gudangChoice == "1"){
		cout<<"Anda Sedang Berada di Gudang A\n";
	} else if(gudangChoice == "2"){
		cout<<"Anda Sedang Berada di Gudang B\n";
	} else if(gudangChoice == "3"){
		cout<<"Anda Sedang Berada di Gudang C\n";
	} else if(gudangChoice == "4"){
		cout<<"\n";	
	}else {
		cout<<"\nWrong Input!\n";
	}
	border();
}

int main(){
	
	vector<Barang> gudangA;
	vector<Barang> gudangB;
	vector<Barang> gudangC;
	
	bool mainBack;
	do{
		mainHeader();
		cout<<"\n1. Akses Gudang\n2. Cek Barang Masuk\n3. Cek Barang Keluar\n4. Cari Barang\n";
		border();
		cout<<"Masukkan pilihan angka\nmisal pilih 2 untuk lihat barang masuk\n";
		border();
		cin>>mainChoice;
		border();
		system("cls");
		if(mainChoice == "1"){
			bool gudangBack;
			do{
				menuChoiceHeader();
				cout<<"\n1. Gudang A\n2. Gudang B\n3. Gudang C\n4. Back\n";
				border();
				cin>>gudangChoice;
				system("cls");
				string pilihanGudangA;
				if(gudangChoice == "1"){
				 	aksesGudangHeader();
					cout<<"\n1. Cek Barang Gudang A\n2. Tambah Barang Masuk\n3. Tambah Barang Keluar\n4. Back to Akses Gudang\n5. Back to Main Menu\n";
					cout<<"\n";border();
					cin>>pilihanGudangA;
					system("pause");
					system("cls");
					if(pilihanGudangA == "1"){
						aksesGudangHeader();
						tampilkanDaftarBarang(gudangA);
						cout<<"\n";border();
						system("pause");
						system("cls");
						gudangBack = true;
						
					} else if(pilihanGudangA == "2"){
						int backTambahGudangA;
						int jumlahItem;
						do{
							string tambahGudangA;
							aksesGudangHeader();
							cout<<"Jumlah item: ";
							cin>>jumlahItem;
							for(int i=0; i<jumlahItem; i++){
								tambahBarang(gudangA);
								border();
							}
							cout<<"\n";border();
							cout<<"pilih: 1. Tambah Barang Lagi  2. Kembali\n";
							cin>>tambahGudangA;
							border();
							system("pause");
							system("cls");
							if(tambahGudangA == "1"){
								system("cls");
								backTambahGudangA = 1;
							} else if(tambahGudangA == "2"){
								system("cls");
								backTambahGudangA == 0;
								mainBack = false;
								gudangBack = true;
							} else {
								aksesGudangHeader();
								cout<<"\nSorry wrong input, you will be\ndirected to akses gudang menu\n";
								border();
								system("pause");
								system("cls");
								gudangBack = true;
							}
						} while(backTambahGudangA== 1);
						
					} else if(pilihanGudangA == "3"){
						border(); cout<<"\n";
						aksesGudangHeader();
						
						cout<<"\n";border();
						system("pause");
						system("cls");
						gudangBack = true;
					} else if(pilihanGudangA == "4"){
						system("cls");
						gudangBack = true;
					} else if(pilihanGudangA == "5"){
						system("cls");
						gudangBack = false;
						mainBack = true;
					} else {
						aksesGudangHeader();
						cout<<"\nSorry wrong input, you will be\ndirected to akses gudang menu\n";
						border();
						system("pause");
						system("cls");
						gudangBack = true;
					}
				} else if(gudangChoice == "2"){
					string pilihanGudangB;
					border(); cout<<"\n";
					aksesGudangHeader();
					cout<<"\n1. Cek Barang Gudang A\n2. Tambah Barang Masuk\n3. Tambah Barang Keluar\n4. Back to Akses Gudang\n5. Back to Main Menu\n";
					cout<<"\n";border();
					cin>>pilihanGudangB;
					system("cls");
					aksesGudangHeader();
					cout<<"\n1. Cek Barang Gudang A\n2. Tambah Barang Masuk\n3. Tambah Barang Keluar\n4. Back to Akses Gudang\n5. Back to Main Menu\n";
					cout<<"\n";border();
					cin>>pilihanGudangA;
					system("pause");
					system("cls");
					
				} else if(gudangChoice == "3"){
					border();cout<<"\n";
					aksesGudangHeader();
					cout<<"\n1. Cek Barang Gudang A\n2. Tambah Barang Masuk\n3. Tambah Barang Keluar\n4. Back to Akses Gudang\n5. Back to Main Menu\n";
					cout<<"\n";border();
				} else if(gudangChoice == "4"){
					system("cls");
					gudangBack = false;
					mainBack = true;	
				} else {
					aksesGudangHeader();
					cout<<"\nSorry wrong input, you will be\ndirected to akses gudang menu\n";
					border();
					system("pause");
					system("cls");
					gudangBack = true;
				}
			} while(gudangBack == true);
			
		} else if(mainChoice == "2"){
			menuChoiceHeader();
			tampilkanDaftarBarangMasuk(gudangA);
			border();
			system("pause");
			system("cls");
			mainBack = true;
		} else if(mainChoice == "3"){
			menuChoiceHeader();
		} else if(mainChoice == "4"){
			menuChoiceHeader();
			temukanBarang(gudangA);
			border();
			system("pause");
			system("cls");
			mainBack = true;
		} else {
			mainHeader();
			cout<<"\nSorry wrong input, you will be\ndirected to main menu\n";
			border();
			system("pause");
			system("cls");
			mainBack = true;
		}
		
	} while(mainBack == true);
		
}
