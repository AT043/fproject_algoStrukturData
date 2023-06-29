#include <bits/stdc++.h>
using namespace std;

string menuChoice, gudangChoice;
int nGdgA = 0;

struct gudangA{
	//kode_unit;
	string nama_barang[1000];
	string bahan_barang[1000];
	//string ukuran_barang[1000];
	//int berat_barang[1000];
	//string jenis_barang[1000];
	long long jumlah_barang[1000];
	//waktu_tiba;
	string asal_barang[1000];
}; 

	gudangA gda;

/*struct gudangB{
	id_pengiriman;
	nama_barang;
	jenis_barang;
	jumlah_barang;
	waktu_tiba;
	asal_barang;
}; gudangB gdb;

struct gudangC{
	id_pengiriman;
	nama_barang;
	jenis_barang;
	jumlah_barang;
	waktu_tiba;
	asal_barang;
}; gudangC gdc;*/

void border(){
	char x[2]="=";
	for (int i=0; i<35; i++){
		cout<<x;
	}
	cout<<"\n";
}

void mainMenuHeader(){
	border();
	if(menuChoice == "1"){
		cout<<"Buka Akses Ke Gudang \n";
	} else if(menuChoice == "2"){
		cout<<"Data Barang Masuk\n";
	} else if(menuChoice == "3"){
		cout<<"Data Barang Keluar\n";
	} else if(menuChoice == "4"){
		cout<<"Pencarian Barang \n";
	} 
	border();
}

void aksesGudangHeaderMenu() {
	border();
	if(gudangChoice == "1"){
		cout<<"Anda Sedang Berada di Gudang A\n";
	} else if(gudangChoice == "2"){
		cout<<"Anda Sedang Berada di Gudang B\n";
	} else if(gudangChoice == "3"){
		cout<<"Anda Sedang Berada di Gudang C\n";
	} 
	border();
}

int main(){
	//main menu
	bool mainBack;
	do {
		border();
		cout<<"Welcome di Gudang Bang!\n";
		border();
		cout<<"Perlu apa bang/kak? \n";
		cout<<"1. Akses Gudang\n2. Cek Barang Masuk\n3. Cek barang Keluar\n4. Cari Barang\n";
		border();
		cout<<"Masukkan angka sesuai menu,\nmisal 2 untuk cek daftar barang masuk \n";
		border();
		cout<<"pilih: ";
		cin>>menuChoice;
		system("cls");
		
		//Menu Akses Gudang
		if(menuChoice=="1"){
			/*int uname, passwd;
				aksesGudangHeader();
				cout<<"1. Login \n";
				cout<<"2. mainBack \n";
				border();
				cout<<"pilih: ";
				cin>>gudangChoice;
				system("cls");
				if(gudangChoice == "1"){
					aksesGudangHeader();
					cout<<"Username: ";
					cin>>uname;
					cout<<"\n";
					cout<<"Password:";
					cin>>passwd;
					system("cls");
					
					aksesGudangHeader();
					cout<<"Under Construction!\n";
					border();
					system("Pause");
					system("cls");
					mainBack = true;
					
				} else if(gudangChoice == "2"){
					mainBack = true;
				} else {
					cout<<"Wrong Input!\n";
					system("Pause");
					mainBack = true;
				}*/
			bool gudangBack;
			do{
				mainMenuHeader();
				cout<<nGdgA<<endl;
				cout<<"1. Gudang A\n2. Gudang B\n3. Gudang C\n4. Back to Main Menu\n";
				border();
				cin>>gudangChoice;
				border();
				system("cls");
				if (gudangChoice == "1"){
					string gudangAChoice;
					aksesGudangHeaderMenu();
					cout<<"1. Cek Barang Gudang A\n2. Tambah barang Masuk\n3. Tambah Barang Keluar\n4. Back to Akses Gudang\n5. Back to Main Menu\n";
					border();
					cout<<"Masukkan angka: ";
					cin>>gudangAChoice;
					border();
					system("cls");
					if(gudangAChoice == "1"){
						aksesGudangHeaderMenu();
						for(int i=0; i<nGdgA; i++){
							cout<<"\n";
							cout<<"Nama Barang: "<<gda.nama_barang[i]<<endl;
							cout<<"Bahan Barang: "<<gda.bahan_barang[i]<<endl;
							cout<<"Jumlah Barang: "<<gda.jumlah_barang[i]<<" Unit"<<endl;
							cout<<"Asal Barang: "<<gda.asal_barang[i]<<endl;
							border();
						}
						
						border();
						system("Pause");
						system("cls");
						gudangBack = true;
					} else if(gudangAChoice == "2"){
						int tambahBarangBack;
						do{
							aksesGudangHeaderMenu();
							cout<<"Nama Barang: ";cin>>gda.nama_barang[nGdgA];
							cout<<"\nBahan Barang: ";cin>>gda.bahan_barang[nGdgA];
							cout<<"\nJumlah Barang: ";cin>>gda.jumlah_barang[nGdgA];
							cout<<"\nAsal Barang: ";cin>>gda.asal_barang[nGdgA];
							cout<<"\n";
							border();
							string tambahBarang;
							cout<<"Tambah Barang Lagi?\n1. Ya  2. Tidak\n";border();cin>>tambahBarang;
							if(tambahBarang=="1"){
								system("cls");
								tambahBarangBack = 1;
							} else if(tambahBarang=="2"){
								system("cls");
								tambahBarangBack = 0;
								gudangBack=true;
							} else{
								system("cls");
								tambahBarangBack =0;
								mainBack=true;
							}
						} while(tambahBarangBack == 1);
							
							nGdgA++;
					} else if(gudangAChoice == "3"){
						aksesGudangHeaderMenu();
						cout<<"Under Construction!\n";
						border();
						system("Pause");
						system("cls");
						mainBack = true;
					} else if(gudangAChoice == "4"){
						system("cls");
						gudangBack = true;
					} else if(gudangAChoice == "5"){
						system("cls");
						mainBack = true;
					} else {
						aksesGudangHeaderMenu();
						cout<<"Wrong Input!\n";
						border();
						system("Pause");
						system("cls");
						mainBack = true;
					}
				} else if(gudangChoice == "2"){
					string gudangBChoice;
					aksesGudangHeaderMenu();
					cout<<"1. Cek Barang Gudang B\n2. Tambah barang Masuk\n3. Tambah Barang Keluar\n4. Back\n";
					border();
					cout<<"Masukkan angka: ";
					cin>>gudangBChoice;
					border();
					system("cls");
					if(gudangBChoice == "1"){
						aksesGudangHeaderMenu();
						cout<<"Under Construction!\n";
						border();
						system("Pause");
						system("cls");
						mainBack = true;
					} else if(gudangBChoice == "2"){
						aksesGudangHeaderMenu();
						cout<<"Under Construction!\n";
						border();
						system("Pause");
						system("cls");
						mainBack = true;
					} else if(gudangBChoice == "3"){
						aksesGudangHeaderMenu();
						cout<<"Under Construction!\n";
						border();
						system("Pause");
						system("cls");
						mainBack = true;
					} else if(gudangBChoice == "4"){
						system("cls");
						gudangBack = true;
					} else {
						aksesGudangHeaderMenu();
						cout<<"Wrong Input!\n";
						border();
						system("Pause");
						system("cls");
						mainBack = true;
					}
				} else if(gudangChoice == "3"){
					string gudangCChoice;
					aksesGudangHeaderMenu();
					cout<<"1. Cek Barang Gudang C\n2. Tambah barang Masuk\n3. Tambah Barang Keluar\n4. Back\n";
					border();
					cout<<"Masukkan angka: ";
					cin>>gudangCChoice;
					border();
					system("cls");
					if(gudangCChoice == "1"){
						aksesGudangHeaderMenu();
						cout<<"Under Construction!\n";
						border();
						system("Pause");
						system("cls");
						mainBack = true;
					} else if(gudangCChoice == "2"){
						aksesGudangHeaderMenu();
						cout<<"Under Construction!\n";
						border();
						system("Pause");
						system("cls");
						mainBack = true;
					} else if(gudangCChoice == "3"){
						aksesGudangHeaderMenu();
						cout<<"Under Construction!\n";
						border();
						system("Pause");
						system("cls");
						mainBack = true;
					} else if(gudangCChoice == "4"){
						system("cls");
						gudangBack = true;
					} else {
						aksesGudangHeaderMenu();
						cout<<"Wrong Input!\n";
						border();
						system("Pause");
						system("cls");
						mainBack = true;
					}
				} else if(gudangChoice == "4"){
					system("cls");
					mainBack = true;
				} else {
					aksesGudangHeaderMenu();
					cout<<"Wrong Input!\n";
					border();
					system("Pause");
					system("cls");
					mainBack = true;
				}
				
			} while(gudangBack == true);
			
		} else if(menuChoice=="2"){
			mainMenuHeader();
			cout<<"Under Construction!\n";
			system("Pause");
			system("cls");
			mainBack = true;
		} else if(menuChoice=="3"){
			mainMenuHeader();
			cout<<"Under Construction!\n";
			system("Pause");
			system("cls");
			mainBack = true;
		} else if(menuChoice=="4"){
			mainMenuHeader();
			cout<<"Cari Barang Berdasarkan: \n";
			cout<<"1. Nama Barang\n2. Kode Unit Barang\n3. Asal Barang\n4. Tujuan Barang\n";
			border();
			system("Pause");
			system("cls");
			mainBack = true;
		} else{
			mainBack = true;
		}
	
	} while(mainBack == true);
	
}
