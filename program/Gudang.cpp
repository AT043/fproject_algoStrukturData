#include <bits/stdc++.h>
using namespace std;

string menuChoice, gudangChoice;
int nGdgA, nGdgB, nGdgC = 0;

struct gudangA{
	//string kode_unit;
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

struct gudangB{
	//string kode_unit;
	string nama_barang[1000];
	string bahan_barang[1000];
	//string ukuran_barang[1000];
	//int berat_barang[1000];
	//string jenis_barang[1000];
	long long jumlah_barang[1000];
	//waktu_tiba;
	string asal_barang[1000];
}; gudangB gdb;

struct gudangC{
	//string kode_unit;
	string nama_barang[1000];
	string bahan_barang[1000];
	//string ukuran_barang[1000];
	//int berat_barang[1000];
	//string jenis_barang[1000];
	long long jumlah_barang[1000];
	//waktu_tiba;
	string asal_barang[1000];
}; gudangC gdc;

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
						if(nGdgA == 0) {
							cout<<"Gudang Kosong\n";
						} else {
							/*cout<<" Nama Barang  ||  Bahan Barang  ||  Jumlah Barang  ||  Asal Barang\n";
							border();*/
							for(int i=0; i<nGdgA; i++){
								cout<<"\n";
								cout<<"Nama Barang: "<<gda.nama_barang[i]<<endl;
								cout<<"Bahan Barang: "<<gda.bahan_barang[i]<<endl;
								cout<<"Jumlah Barang: "<<gda.jumlah_barang[i]<<" Unit"<<endl;
								cout<<"Asal Barang: "<<gda.asal_barang[i]<<endl;
							border();
							/*cout<<" "<<gda.nama_barang[i]<<"    ||    "<<gda.bahan_barang[i]<<"    ||    "<<gda.jumlah_barang[i]<<"    ||    "<<gda.asal_barang[i]<<endl;
							border();*/
							}
						}
						border();
						string cariBarangGdA;
						cout<<"1. Cari Barang  2. Back\n";
						border();
						cin>>cariBarangGdA;
						system("cls");
						if(cariBarangGdA=="1"){
							cout<<"Sorry, Under Construction!\n";
							border();
							gudangBack=true;
						} else if(cariBarangGdA=="2"){
							system("cls");
							gudangBack=true;
							mainBack=false;
						} else{
							cout<<"WrongInput!\n";
							system("pause");
							system("cls");
							gudangBack=false;
							mainBack=true;
						}
						/*system("Pause");
						system("cls");
						gudangBack = true;
						mainBack=false;*/
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
								nGdgA++;
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
						gudangBack = true;
						mainBack=false;
					} else if(gudangAChoice == "4"){
						system("cls");
						gudangBack = true;
						mainBack=false;
					} else if(gudangAChoice == "5"){
						system("cls");
						gudangBack=false;
						mainBack = true;
					} else {
						aksesGudangHeaderMenu();
						cout<<"Wrong Input!\n";
						border();
						system("Pause");
						system("cls");
						gudangBack=false;
						mainBack = true;
					}
				} else if(gudangChoice == "2"){
					string gudangBChoice;
					aksesGudangHeaderMenu();
					cout<<"1. Cek Barang Gudang B\n2. Tambah barang Masuk\n3. Tambah Barang Keluar\n4. Back\n5. Back to Main Menu\n";
					border();
					cout<<"Masukkan angka: ";
					cin>>gudangBChoice;
					border();
					system("cls");
					if(gudangBChoice == "1"){
						aksesGudangHeaderMenu();
						if(nGdgB==0){
							cout<<"Gudang Kosong\n";
						} else {
							for(int i=0; i<nGdgB; i++){
								cout<<"\n";
								cout<<"Nama Barang: "<<gdb.nama_barang[i]<<endl;
								cout<<"Bahan Barang: "<<gdb.bahan_barang[i]<<endl;
								cout<<"Jumlah Barang: "<<gdb.jumlah_barang[i]<<" Unit"<<endl;
								cout<<"Asal Barang: "<<gdb.asal_barang[i]<<endl;
							border();
							}
						}
						
						border();
						system("Pause");
						system("cls");
						gudangBack=true;
						mainBack = false;
					} else if(gudangBChoice == "2"){
						int tambahBarangBack;
						do{
							aksesGudangHeaderMenu();
							cout<<"Nama Barang: ";cin>>gdb.nama_barang[nGdgB];
							cout<<"\nBahan Barang: ";cin>>gdb.bahan_barang[nGdgB];
							cout<<"\nJumlah Barang: ";cin>>gdb.jumlah_barang[nGdgB];
							cout<<"\nAsal Barang: ";cin>>gdb.asal_barang[nGdgB];
							cout<<"\n";
							border();
							string tambahBarang;
							cout<<"Tambah Barang Lagi?\n1. Ya  2. Tidak\n";border();cin>>tambahBarang;
							if(tambahBarang=="1"){
								nGdgB++;
								system("cls");
								tambahBarangBack = 1;
								gudangBack=false;
								mainBack=false;
							} else if(tambahBarang=="2"){
								system("cls");
								tambahBarangBack = 0;
								gudangBack=true;
								mainBack=false;
							} else{
								system("cls");
								tambahBarangBack =0;
								gudangBack=false;
								mainBack=true;
							}
						} while(tambahBarangBack == 1);
						nGdgB++;
					} else if(gudangBChoice == "3"){
						aksesGudangHeaderMenu();
						cout<<"Under Construction!\n";
						border();
						system("Pause");
						system("cls");
						gudangBack=true;
						mainBack = false;
					} else if(gudangBChoice == "4"){
						system("cls");
						gudangBack = true;
						mainBack=false;
					} else if(gudangBChoice == "5"){
						system("cls");
						gudangBack =false;
						mainBack = true;
					} else {
						aksesGudangHeaderMenu();
						cout<<"Wrong Input!\n";
						border();
						system("Pause");
						system("cls");
						gudangBack=false;
						mainBack = true;
					}
				} else if(gudangChoice == "3"){
					string gudangCChoice;
					aksesGudangHeaderMenu();
					cout<<"1. Cek Barang Gudang C\n2. Tambah barang Masuk\n3. Tambah Barang Keluar\n4. Back\n5. Back to Main Menu\n";
					border();
					cout<<"Masukkan angka: ";
					cin>>gudangCChoice;
					border();
					system("cls");
					if(gudangCChoice == "1"){
						aksesGudangHeaderMenu();
						if(nGdgC==0){
							cout<<"Gudang Kosong\n";
						} else {
							for(int i=0; i<nGdgC; i++){
								cout<<"\n";
								cout<<"Nama Barang: "<<gdc.nama_barang[i]<<endl;
								cout<<"Bahan Barang: "<<gdc.bahan_barang[i]<<endl;
								cout<<"Jumlah Barang: "<<gdc.jumlah_barang[i]<<" Unit"<<endl;
								cout<<"Asal Barang: "<<gdc.asal_barang[i]<<endl;
							border();
							}
						}
						
						border();
						system("Pause");
						system("cls");
						gudangBack=true;
						mainBack = false;
					} else if(gudangCChoice == "2"){
						int tambahBarangBack;
						do{
							aksesGudangHeaderMenu();
							cout<<"Nama Barang: ";cin>>gdc.nama_barang[nGdgC];
							cout<<"\nBahan Barang: ";cin>>gdc.bahan_barang[nGdgC];
							cout<<"\nJumlah Barang: ";cin>>gdc.jumlah_barang[nGdgC];
							cout<<"\nAsal Barang: ";cin>>gdc.asal_barang[nGdgC];
							cout<<"\n";
							border();
							string tambahBarang;
							cout<<"Tambah Barang Lagi?\n1. Ya  2. Tidak\n";border();cin>>tambahBarang;
							if(tambahBarang=="1"){
								nGdgC++;
								system("cls");
								tambahBarangBack = 1;
								gudangBack=false;
								mainBack=false;
							} else if(tambahBarang=="2"){
								system("cls");
								tambahBarangBack = 0;
								gudangBack=true;
								mainBack=false;
							} else{
								system("cls");
								tambahBarangBack =0;
								gudangBack=false;
								mainBack=true;
							}
						} while(tambahBarangBack == 1);
						nGdgC++;
					} else if(gudangCChoice == "3"){
						aksesGudangHeaderMenu();
						cout<<"Under Construction!\n";
						border();
						system("Pause");
						system("cls");
						gudangBack=true;
						mainBack = false;
					} else if(gudangCChoice == "4"){
						system("cls");
						gudangBack = true;
						mainBack=false;
					} else if(gudangCChoice == "5"){
						system("cls");
						gudangBack =false;
						mainBack = true;
					} else {
						aksesGudangHeaderMenu();
						cout<<"Wrong Input!\n";
						border();
						system("Pause");
						system("cls");
						gudangBack=false;
						mainBack = true;
					}
				} else if(gudangChoice == "4"){
					system("cls");
					gudangBack = false; 
					mainBack = true;
				} else {
					aksesGudangHeaderMenu();
					cout<<"Wrong Input!\n";
					border();
					system("Pause");
					system("cls");
					gudangBack = false;
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
