#include <bits/stdc++.h>
using namespace std;

string menuChoice, gudangChoice;

void border(){
	char x[2]="=";
	for (int i=0; i<30; i++){
		cout<<x;
	}
	cout<<"\n";
}

void aksesGudangHeader(){
	border();
	cout<<"Buka Akses Ke Gudang \n";
	border();
}

void cekBarangMasukHeader(){
	border();
	cout<<"Data Barang Masuk\n";
	border();
}

void cekBarangKeluarHeader(){
	border();
	cout<<"Data Barang Keluar\n";
	border();
}

void cariBarangHeader(){
	border();
	cout<<"Pencarian Barang \n";
	border();
}

int main(){
	bool back;
	do {
		border();
		cout<<"Welcome di Gudang Bang!\n";
		border();
		cout<<"Perlu apa bang/kak? \n";
		cout<<"1. Akses Gudang\n";
		cout<<"2. Cek Barang Masuk\n";
		cout<<"3. Cek barang Keluar\n";
		cout<<"4. Cari Barang\n";
		border();
		cout<<"Masukkan angka sesuai menu,\nmisal 2 untuk cek daftar barang masuk \n";
		border();
		cout<<"pilih: ";
		cin>>menuChoice;
		system("cls");
		
		if(menuChoice=="1"){
			int uname, passwd;
				aksesGudangHeader();
				cout<<"1. Login \n";
				cout<<"2. Back \n";
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
					back = true;
					
				} else if(gudangChoice == "2"){
					back = true;
				} else {
					cout<<"Wrong Input!\n";
					system("Pause");
					back = true;
				}
		} else if(menuChoice=="2"){
			cekBarangMasukHeader();
			cout<<"Under Construction!\n";
			system("Pause");
			system("cls");
			back = true;
		} else if(menuChoice=="3"){
			cekBarangKeluarHeader();
			cout<<"Under Construction!\n";
			system("Pause");
			system("Pause");
			system("cls");
			back = true;
		} else if(menuChoice=="4"){
			cariBarangHeader();
			cout<<"Under Construction!\n";
			system("Pause");
			system("cls");
			back = true;
		} else{
			back = true;
		}
	
		/*switch(menuChoice){
			case 1:
				int uname, passwd;
				aksesGudangHeader();
				cout<<"1. Login \n";
				cout<<"2. Back \n";
				border();
				cout<<"pilih: ";
				cin>>gudangChoice;
				system("cls");
				if(gudangChoice == 1){
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
					back = true;
					
				} else if(gudangChoice == 2){
					back = true;
				} else {
					cout<<"Wrong Input!\n";
					system("Pause");
					back = true;
				}
				break;
			case 2:
				cekBarangMasukHeader();
				cout<<"Under Construction!\n";
				system("Pause");
				system("cls");
				back = true;
				break;
			case 3:
				cekBarangKeluarHeader();
				cout<<"Under Construction!\n";
				system("Pause");
				system("Pause");
				system("cls");
				back = true;
				break;
			case 4:
				cariBarangHeader();
				cout<<"Under Construction!\n";
				system("Pause");
				system("cls");
				back = true;
				break;
			default:
				back = true;
		}*/
	} while(back == true);
	
}
