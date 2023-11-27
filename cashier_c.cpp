//Input Library
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <time.h>

using namespace std;

//Membuat Function menu, pembelian, keranjang, checkout, struk, keluar, dan tanggal sekarang
void menu();
void pembelian();
void keranjang(int variable_jumlah);
void checkout();
void struk();
void keluar();
const string currentDateTime();

//Fungsi untuk mendapatkan waktu sekarang dari library time.h dan merubah format ke Y-m-d
const string currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

//Fungsi untuk mengatur posisi menggunakan kordinat x dan y
void gotoxy(int x, int y)
{
    COORD a;
    a.X = x;
    a.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
}
// struct untuk menyimpan data pembelian
struct dataitem{
	float banyak_array;
	float nomor_item;
	float harga_item;
	float harga_tetap;
	string nama_item;
	float jumlah_item;
	float index;
}dt[9999];

// struct untuk menyimpan data total dan checkout
struct totalpembelian{
	float jumlah_semua_item;
	float jumlah_semua_harga;
	float jumlahbayar;	
}tp;

// struct menyimpan data identitas pembeli
struct identitaspembeli{
	string nama,notelp,email;
}id;

// Fungsi untuk menampilkan daftar harga dari item/buah yang tersedia
void list_item()
{
	int harga_item[10] = {20000, 34000, 20000, 38000, 23400, 22000, 29000, 16000, 30000, 24000};
	string item[10] = {"Mangga", "Apel", "Nanas", "Semangka", "Melon", "Anggur", "Durian", "Lemon", "Rambutan", "Alpukat"};
	int nomor = 1;
	gotoxy(2,7);cout << "-------------------------------------";
	gotoxy(2,8);cout << "| No";
	gotoxy(7,8);cout << "| Item";
	gotoxy(25,8);cout << "| Harga / KG";
	gotoxy(38,8);cout << "|";
	gotoxy(2,9);cout << "-------------------------------------";
	for(int i = 0; i < 10; i++)
	{
		gotoxy(2, 9 + nomor);cout<< "|";
		gotoxy(4, 9 + nomor);cout<< nomor;
		gotoxy(9, 9 + nomor);cout<< item[i];
		gotoxy(27, 9 + nomor);cout<< harga_item[i];
		gotoxy(38, 9 + nomor);cout<< "|";
		nomor++;
//		gotoxy();cout << "Harga nya Adalah : " << harga_item[i] << endl;
	}
	gotoxy(2,20);cout << "-------------------------------------";
}

//Fungsi untuk pemilihan menu
void menu()
{
	//Menu
	menu:
	system("cls");
	string menu;
	int byk_data = dt[0].banyak_array;
	gotoxy(5,10); cout << "Toko Buah";
	gotoxy(5,12); cout << "1. Pembelian";
	gotoxy(5,13); cout << "2. Daftar Keranjang";
	gotoxy(5,14); cout << "3. Checkout";
	gotoxy(5,15); cout << "4. Keluar";
	//Pemilihan Menu
	gotoxy(5,17); cout << "Pilih Nomor Menu (1/2/3/4) : "; cin >> menu;
	if(menu == "1" || menu == "Pembelian" || menu == "PEMBELIAN")
	{
		pembelian();
	}
	else if(menu == "2" || menu == "Daftar Keranjang" || menu == "DAFTAR KERANJANG")
	{
		int variable_jumlah = 0;
		keranjang(variable_jumlah);
	}
	else if(menu == "3" && byk_data != 0)
	{
		checkout();
	}
	else if(menu == "3" && byk_data == 0)
	{
		gotoxy(5,16);	cout << "Anda tidak bisa checkout ketika barang anda kosong";
		Sleep(2000);
		goto menu;
	}
	else if(menu == "4" || menu == "Keluar" || menu == "KELUAR")
	{
		keluar();
	}
	
}

//Fungsi untuk menambahkan barang belanjaan pelanggan
void pembelian()
{
	char key_press;
	system("cls");
	gotoxy(2, 5);cout << "Pembelian";
	list_item();
	gotoxy(2, 6);cout << "Ketik B untuk kembali";
	key_press = _getch();
	if(key_press == 'b')
	{
		system("cls");
		menu();
	}
	else{
		system("cls");
		gotoxy(3,6);cout<< "LIST BARANG & HARGA TOKO BUAH";
		list_item();
		char lanjut;
		int jml_variable = dt[0].banyak_array;
		int angka_item = 0;
		int spasi = 0;
		int variable_jumlah = 1;
//		if(jml_variable != 0)
//		{
//			jml_variable = jml_variable + 1;
//		}
//		cout << "JML VAL : " << jml_variable;
		while(lanjut != 'N' || lanjut != 'n')
		{
//			system("cls");
			int jml_item = 1;
			gotoxy(3,21+spasi);cout << "Pilih Item Berdasar Nomor		: "; cin >> dt[angka_item].nomor_item;
			gotoxy(3,22+spasi);cout << "Tentukan Jumlah Item			: "; cin >> jml_item;
			if(dt[angka_item].nomor_item == 1)
			{
				dt[angka_item + jml_variable].index = angka_item + jml_variable;
				dt[angka_item + jml_variable].jumlah_item = jml_item;
				dt[angka_item + jml_variable].harga_tetap = 20000;
				dt[angka_item + jml_variable].harga_item = 20000 * jml_item;
				dt[angka_item + jml_variable].nama_item = "Mangga";
			}
			else if(dt[angka_item].nomor_item == 2)
			{
				dt[angka_item + jml_variable].index = angka_item + jml_variable;
				dt[angka_item + jml_variable].jumlah_item = jml_item;
				dt[angka_item + jml_variable].harga_tetap = 34000;
				dt[angka_item + jml_variable].harga_item = 34000 * jml_item;
				dt[angka_item + jml_variable].nama_item = "Apel";
			}
			else if(dt[angka_item].nomor_item == 3)
			{
				dt[angka_item + jml_variable].index = angka_item + jml_variable;
				dt[angka_item + jml_variable].jumlah_item = jml_item;
				dt[angka_item + jml_variable].harga_tetap = 20000;
				dt[angka_item + jml_variable].harga_item = 20000 * jml_item;
				dt[angka_item + jml_variable].nama_item = "Nanas";
			}
			else if(dt[angka_item].nomor_item == 4)
			{
				dt[angka_item + jml_variable].index = angka_item + jml_variable;
				dt[angka_item + jml_variable].jumlah_item = jml_item;
				dt[angka_item + jml_variable].harga_tetap = 38000;
				dt[angka_item + jml_variable].harga_item = 38000 * jml_item;
				dt[angka_item + jml_variable].nama_item = "Semangka";
			}
			else if(dt[angka_item].nomor_item == 5)
			{
				dt[angka_item + jml_variable].index = angka_item + jml_variable;
				dt[angka_item + jml_variable].jumlah_item = jml_item;
				dt[angka_item + jml_variable].harga_tetap = 23400;
				dt[angka_item + jml_variable].harga_item = 23400 * jml_item;
				dt[angka_item + jml_variable].nama_item = "Melon";
			}
			else if(dt[angka_item].nomor_item == 6)
			{
				dt[angka_item + jml_variable].index = angka_item + jml_variable;
				dt[angka_item + jml_variable].jumlah_item = jml_item;
				dt[angka_item + jml_variable].harga_tetap = 22000;
				dt[angka_item + jml_variable].harga_item = 22000 * jml_item;
				dt[angka_item + jml_variable].nama_item = "Anggur";
			}
			else if(dt[angka_item].nomor_item == 7)
			{
				dt[angka_item + jml_variable].index = angka_item + jml_variable;
				dt[angka_item + jml_variable].jumlah_item = jml_item;
				dt[angka_item + jml_variable].harga_tetap = 29000;
				dt[angka_item + jml_variable].harga_item = 29000 * jml_item;
				dt[angka_item + jml_variable].nama_item = "Durian";
			}
			else if(dt[angka_item].nomor_item == 8)
			{
				dt[angka_item + jml_variable].index = angka_item + jml_variable;
				dt[angka_item + jml_variable].jumlah_item = jml_item;
				dt[angka_item + jml_variable].harga_tetap = 16000;
				dt[angka_item + jml_variable].harga_item = 16000 * jml_item;
				dt[angka_item + jml_variable].nama_item = "Lemon";
			}
			else if(dt[angka_item].nomor_item == 9)
			{
				dt[angka_item + jml_variable].index = angka_item + jml_variable;
				dt[angka_item + jml_variable].jumlah_item = jml_item;
				dt[angka_item + jml_variable].harga_tetap = 30000;
				dt[angka_item + jml_variable].harga_item = 30000 * jml_item;
				dt[angka_item + jml_variable].nama_item = "Rambutan";
			}
			else if(dt[angka_item].nomor_item == 10)
			{
				dt[angka_item + jml_variable].index = angka_item + jml_variable;
				dt[angka_item + jml_variable].jumlah_item = jml_item;
				dt[angka_item + jml_variable].harga_tetap = 24000;
				dt[angka_item + jml_variable].harga_item = 24000 * jml_item;
				dt[angka_item + jml_variable].nama_item = "Alpukat";
			}
			gotoxy(3,23+spasi);cout << "Apakah Anda Ingin Lanjut? (Y/N)	: "; cin >> lanjut;
			if(lanjut == 'N' || lanjut == 'n')
			{
				break;
			}
			angka_item++;
			spasi+=4;
			variable_jumlah+=1;
		}
		dt[0].banyak_array += variable_jumlah;
		keranjang(variable_jumlah);
	}
}

//Fungsi untuk menyimpan barang di keranjang belanjaan pelanggan
void keranjang(int variable_jumlah)
{
	char key_press;
	system("cls");
	int jml_variable = dt[0].banyak_array;
	cout << jml_variable;
	gotoxy(2, 5);cout << "Keranjang";
	gotoxy(2, 6);cout << "Ketik B untuk kembali ; A untuk menambahkan item ; D untuk menghapus item ; C untuk Checkout";
	gotoxy(2,7);cout << "-------------------------------------------------------------";
	gotoxy(2,8);cout << "| No";
	gotoxy(7,8);cout << "| Item";
	gotoxy(25,8);cout << "| Harga / KG";
	gotoxy(38,8);cout << "| Jumlah";
	gotoxy(46,8);cout << "| Total";
	gotoxy(62,8);cout << "|";
	gotoxy(2,9);cout << "-------------------------------------------------------------";
	int nomor = 1;
	for(int i = 0; i < jml_variable; i++)
	{
		gotoxy(2, 9 + nomor);cout<< "|";
		gotoxy(4, 9 + nomor);cout<< nomor;
		gotoxy(9, 9 + nomor);cout<< dt[i].nama_item;
		gotoxy(27, 9 + nomor);cout<< dt[i].harga_tetap;
		gotoxy(40, 9 + nomor);cout<< dt[i].jumlah_item;
		gotoxy(48, 9 + nomor);cout<< dt[i].harga_item;
		gotoxy(62, 9 + nomor);cout<< "|";
		nomor++;
	}
	//Menghitung Jumlah Keseluruhan
	int total_jml_itemnya;
	for(int i = 0; i < jml_variable; i++)
	{
		total_jml_itemnya += dt[i].jumlah_item;
	}
	tp.jumlah_semua_item = total_jml_itemnya;
	//Menghitung Total Keseluruhan
	float total_jml_harganya;
	for(int i = 0; i < jml_variable; i++)
	{
		total_jml_harganya += dt[i].harga_item;
	}
	tp.jumlah_semua_harga = total_jml_harganya;
	gotoxy(2,9+nomor);cout << "-------------------------------------------------------------";
	gotoxy(2,10+nomor);cout << "|";
	gotoxy(27,10+nomor);cout<< "Jumlah Keseluruhan";
	gotoxy(46,10+nomor);cout<< "|" << tp.jumlah_semua_item;
	gotoxy(62,10+nomor);cout<< "|";
	gotoxy(2,11+nomor);cout << "|";
	gotoxy(28,11+nomor);cout<< "Total Keseluruhan";
	gotoxy(46,11+nomor);cout<< "|" << tp.jumlah_semua_harga;
	gotoxy(62,11+nomor);cout<< "|";
	gotoxy(2,12+nomor);cout << "-------------------------------------------------------------";
	key_press = _getch();
	if(key_press == 'b')
	{
		system("cls");
		menu();
	}
	else if(key_press == 'a')
	{
		system("cls");
		pembelian();
	}
	else if(key_press == 'd')
	{
		char item_dihapus;
		gotoxy(2,13+nomor);cout << "Apakah anda yakin ingin menghapus? (Y/N) : ";
		cin >> item_dihapus;
			if(item_dihapus == 'Y' || item_dihapus == 'y')
			{
				dt[0] = dt[0+1];
			}
		cout << tp.jumlah_semua_item;
		keranjang(jml_variable);
	}
	else if(key_press == 'c')
	{
		char pilihan_checkout;
		gotoxy(2,13+nomor);cout << "Apakah anda yakin ingin checkout? (Y/N) : ";
		cin >> pilihan_checkout;
		if(pilihan_checkout == 'Y' || pilihan_checkout == 'y' && dt[0].banyak_array != 0)
		{
			checkout();
		}
		else
		{
		gotoxy(2,14+nomor);	cout << "Anda tidak bisa checkout ketika barang anda kosong";
		Sleep(3000);
		keranjang(jml_variable);
		}
	}
}

//Fungsi untuk melakukan checkout, total harga, berapa yang dibayarkan, dan kembalian
void checkout()
{
	char key_press;
	system("cls");
	gotoxy(2, 5);cout << "Checkout";
	gotoxy(2, 6);cout << "Ketik B untuk kembali";
	int jml_variable = dt[0].banyak_array;
//	cout << jml_variable;
	gotoxy(2, 5);cout << "Keranjang";
	gotoxy(2, 6);cout << "Berikut daftar keranjang yang akan di checkout";
	gotoxy(2,7);cout << "-------------------------------------------------------------";
	gotoxy(2,8);cout << "| No";
	gotoxy(7,8);cout << "| Item";
	gotoxy(25,8);cout << "| Harga / KG";
	gotoxy(38,8);cout << "| Jumlah";
	gotoxy(46,8);cout << "| Total";
	gotoxy(62,8);cout << "|";
	gotoxy(2,9);cout << "-------------------------------------------------------------";
	int nomor = 1;
	for(int i = 0; i < jml_variable; i++)
	{
		gotoxy(2, 9 + nomor);cout<< "|";
		gotoxy(4, 9 + nomor);cout<< nomor;
		gotoxy(9, 9 + nomor);cout<< dt[i].nama_item;
		gotoxy(27, 9 + nomor);cout<< dt[i].harga_tetap;
		gotoxy(40, 9 + nomor);cout<< dt[i].jumlah_item;
		gotoxy(48, 9 + nomor);cout<< dt[i].harga_item;
		gotoxy(62, 9 + nomor);cout<< "|";
		nomor++;
	}
	//Menghitung Jumlah Keseluruhan
	int total_jml_itemnya;
	for(int i = 0; i < jml_variable; i++)
	{
		total_jml_itemnya += dt[i].jumlah_item;
	}
	tp.jumlah_semua_item = total_jml_itemnya;
	//Menghitung Total Keseluruhan
	float total_jml_harganya;
	for(int i = 0; i < jml_variable; i++)
	{
		total_jml_harganya += dt[i].harga_item;
	}
	//Variable Uang Kembalian dan Jumlah Bayar
	float jumlah_bayar = 0;
	float jumlah_kembalian = 0;
	
	tp.jumlah_semua_harga = total_jml_harganya;
	gotoxy(2,9+nomor);cout << "-------------------------------------------------------------";
	gotoxy(2,10+nomor);cout << "|";
	gotoxy(27,10+nomor);cout<< "Jumlah Keseluruhan";
	gotoxy(46,10+nomor);cout<< "|" << tp.jumlah_semua_item;
	gotoxy(62,10+nomor);cout<< "|";
	gotoxy(2,11+nomor);cout << "|";
	gotoxy(28,11+nomor);cout<< "Total Keseluruhan";
	gotoxy(46,11+nomor);cout<< "|" << tp.jumlah_semua_harga;
	gotoxy(62,11+nomor);cout<< "|";
	gotoxy(2,12+nomor);cout << "-------------------------------------------------------------";
	gotoxy(2,14+nomor);cout << "Total Harga			: " << tp.jumlah_semua_harga;
	gotoxy(2,15+nomor);cout << "Apakah anda ingin melanjutkan Pembayaran?";
	gotoxy(2,16+nomor);cout << "Tekan L untuk lanjut; B untuk kembali ke menu";
	key_press = _getch();
	if(key_press == 'b')
	{
		system("cls");
		menu();
	}
	else if(key_press == 'l')
	{
		gotoxy(2,17+nomor);cout << "Uang yang diberikan		: "; cin >> jumlah_bayar;
		tp.jumlahbayar = jumlah_bayar;
		//Menghitung Kembalian
		jumlah_kembalian = jumlah_bayar - tp.jumlah_semua_harga;
		gotoxy(2,12+nomor);cout << "--------------------------";
		gotoxy(2,19+nomor);cout << "Total Kembalian		: " << jumlah_kembalian;
		char press;
		gotoxy(2,21+nomor);cout << "Tekan S untuk melihat Struk; E untuk Keluar";
		press = _getch();
		if(press == 's')
		{
			struk();
		}
	}
}

//Fungsi untuk menampilkan struk belanjaan yang sudah di checkout
void struk()
{
			system("cls");
			int jml_variable = dt[0].banyak_array;
			gotoxy(45,5); cout << "TOKO BUAH";
			gotoxy(7,8); cout << "JL. BAHARUDIN, ILHAM, SLEMAN, YOGYAKARTA, 66781";
			gotoxy(2,9);cout << "-------------------------------------------------------------";
			gotoxy(19,10); cout << currentDateTime();
			gotoxy(2,11);cout << "-------------------------------------------------------------";
			gotoxy(2,12);cout << "| No";
			gotoxy(7,12);cout << "| Item";
			gotoxy(25,12);cout << "| Harga / KG";
			gotoxy(38,12);cout << "| Jumlah";
			gotoxy(46,12);cout << "| Total";
			gotoxy(62,12);cout << "|";
			gotoxy(2,13);cout << "-------------------------------------------------------------";
			
			int nomor_a = 1;
			for(int i = 0; i < jml_variable; i++)
			{
				gotoxy(2, 14 + nomor_a);cout<< "|";
				gotoxy(4, 14 + nomor_a);cout<< nomor_a;
				gotoxy(9, 14 + nomor_a);cout<< dt[i].nama_item;
				gotoxy(27, 14 + nomor_a);cout<< dt[i].harga_tetap;
				gotoxy(40, 14 + nomor_a);cout<< dt[i].jumlah_item;
				gotoxy(48, 14 + nomor_a);cout<< dt[i].harga_item;
				gotoxy(62, 14 + nomor_a);cout<< "|";
				nomor_a++;
			}
			//Menghitung Jumlah Keseluruhan
			int total_jml_itemnya;
			for(int i = 0; i < jml_variable; i++)
			{
				total_jml_itemnya += dt[i].jumlah_item;
			}
			tp.jumlah_semua_item = total_jml_itemnya;
			//Menghitung Total Keseluruhan
			float total_jml_harganya;
			for(int i = 0; i < jml_variable; i++)
			{
				total_jml_harganya += dt[i].harga_item;
			}
			//Variable Uang Kembalian dan Jumlah Bayar
			float jumlah_bayar = 0;
			float jumlah_kembalian = 0;
			
			tp.jumlah_semua_harga = total_jml_harganya;
			gotoxy(2,15+nomor_a);cout << "-------------------------------------------------------------";
			gotoxy(2,16+nomor_a);cout << "|";
			gotoxy(27,16+nomor_a);cout<< "Jumlah Keseluruhan";
			gotoxy(46,16+nomor_a);cout<< "|" << tp.jumlah_semua_item;
			gotoxy(62,16+nomor_a);cout<< "|";
			gotoxy(2,17+nomor_a);cout << "|";
			gotoxy(28,17+nomor_a);cout<< "Total Keseluruhan";
			gotoxy(46,17+nomor_a);cout<< "|" << tp.jumlah_semua_harga;
			gotoxy(62,17+nomor_a);cout<< "|";
			gotoxy(2,18+nomor_a);cout << "|";
			gotoxy(28,18+nomor_a);cout<< "Jumlah Dibayar";
			gotoxy(46,18+nomor_a);cout<< "|" << tp.jumlahbayar;
			gotoxy(62,18+nomor_a);cout<< "|";
			gotoxy(2,19+nomor_a);cout << "|";
			gotoxy(28,19+nomor_a);cout<< "Total Kembalian";
			gotoxy(46,19+nomor_a);cout<< "|" << tp.jumlahbayar - tp.jumlah_semua_harga;
			gotoxy(62,19+nomor_a);cout<< "|";
			gotoxy(2,20+nomor_a);cout << "-------------------------------------------------------------";
			gotoxy(14,21+nomor_a);cout << "LAYANAN KONSUMEN SMS 0821 3628 6671";
			gotoxy(11,22+nomor_a);cout << "CALL - 0274 88612 - KONTAK@BAHARUDIN.CO.ID";
}
//Fungsi untuk keluar dari menu
void keluar()
{
	system("cls");
	gotoxy(5,11);cout << "Terimakasih Telah Menggunakan Layanan Ini :)";
	exit(0);
}
main()
{
	gotoxy(5,10);cout << "ISIKAN DATA SEPERLUNYA";
	gotoxy(5,12);cout << "Isikan Nama Anda			: "; getline(cin,id.nama);
	gotoxy(5,13);cout << "Isikan Nomor Telepon Anda		: "; getline(cin,id.notelp);
	gotoxy(5,14);cout << "Isikan Alamat Email Anda		: "; getline(cin,id.email);
	menu();
	return 0;
}

