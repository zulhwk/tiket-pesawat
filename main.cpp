#include <iostream>
#include <windows.h>
#include <conio.h> //mengambil library GETCH
#include <stdlib.h> //mengambil library system("CLS");
#include <cstring>
#include <string>
#include <mysql.h>

using namespace std;

int menu_utama(MYSQL* koneksi);

void pendaftaran_pelanggan (MYSQL* koneksi)
{
    int cek_fungsi;
    string id_pelanggan, nama_pelanggan, alamat, no_hp, pasport;
    cout << endl;
    cout << "\t\t   PENDAFTARAN PELANGGAN   " << endl;
    cout << "\t\t---------------------------" << endl;
    cout << endl;
    cin.ignore();
    cout << "\t\tMasukan ID PELANGGAN : ";
    getline(cin, id_pelanggan);
    cout << "\t\tMasukan Nama Pelanggan : ";
    getline(cin, nama_pelanggan);
    cout << "\t\tMasukan Alamat : ";
    getline(cin, alamat);
    cout << "\t\tMasukan No Telp : ";
    getline(cin, no_hp);
    cout << "\t\tMasukan Pasport : ";
    getline(cin, pasport);

    string insert_data = "INSERT INTO pelanggan (id_pelanggan, nama_pelanggan, alamat, no_hp, pasport) VALUES ('"+id_pelanggan+"','"+nama_pelanggan+"','"+alamat+"','"+no_hp+"','"+pasport+"')";

    const char* rubah_data = insert_data.c_str();

    cek_fungsi = mysql_query(koneksi,rubah_data);

    if (!cek_fungsi)
    {
        cout << endl;
        cout << "\t\tDATA BERHASIL DISIMPAN...";
        cout << endl;
        cout << "\t\tTEKAN ENTER UNTUK KEMBALI KE MENU...";
        getch();
        menu_utama(koneksi);
    }
    else
    {
        cout << "\t\tADA QUERY YANG BERMASALAH...";
        cout << "\t\tTEKAN ENTER UNTUK EXIT PROGRAM...";
        getch();

    }

}


void pemesanan_tiket (MYSQL* koneksi)
{
    MYSQL_ROW baris;
    MYSQL_RES* hasil;
    int cek_fungsi;
    string id_pelanggan, nama_pelanggan, alamat, no_hp, pasport;
    string id_transaksi, id_penerbangan;
    cout << endl;
    cout << "\t\t   PEMESANAN TIKET PESAWAT   " << endl;
    cout << "\t\t-----------------------------" << endl;
    cout << endl;
    cout << endl;

    cout << "\t\tDATA PENERBANGAN" << endl;
    cout << "\t\t----------------" << endl;

    string perintah = "SELECT *FROM data_penerbangan";

    const char* rubah_data1 = perintah.c_str();
    int cek_fungsi1;
    cek_fungsi1 = mysql_query(koneksi, rubah_data1);
    int jumlah = 0;
    if(!cek_fungsi1)
    {
        hasil=mysql_store_result(koneksi);
        cout << endl;
        cout << "\t\t===================================================================" << endl;
        cout << "\t\t" << "NO \t || ID PELANGGAN || TUJUAN \t\t || HARGA \t ||" << endl;
        cout << "\t\t===================================================================" << endl;
        cout << endl;
        while(baris=mysql_fetch_row(hasil))
        {

            jumlah++;
            cout << "\t\t" << jumlah  << ".\t " << "||  " << baris [0] << " \t || " << baris[1] << " \t " << "|| " << baris[2] << endl;
        }
        cout << endl;
        cout << "\t\t===================================================================" << endl;
    }
    else
    {
        cout << "DATA KOSONG...";
    }

    cin.ignore();
    cout << "\t\tMasukan ID Transaksi : ";
    getline(cin, id_transaksi);
    cout << "\t\tMasukan ID Pelanggan : ";
    getline(cin, id_pelanggan);
    cout << "\t\tMasukan ID Penerbangan : ";
    getline(cin, id_penerbangan);

    string insert_data = "INSERT INTO transaksi_tiket (id_transaksi, id_penerbangan, id_pelanggan) VALUES ('"+id_transaksi+"','"+id_penerbangan+"','"+id_pelanggan+"')";

    const char* rubah_data = insert_data.c_str();

    cek_fungsi = mysql_query(koneksi,rubah_data);

    if (!cek_fungsi)
    {
        cout << endl;
        cout << "\t\tPEMESANAN BERHASIL DI PROSES...";
        cout << endl;
        cout << "\t\tTEKAN ENTER UNTUK KEMBALI KE MENU...";
        getch();
        menu_utama(koneksi);
    }
    else
    {
        cout << "\t\tADA QUERY YANG BERMASALAH...";
        cout << "\t\tTEKAN ENTER UNTUK EXIT PROGRAM...";
        getch();

    }

}

void cari_data_user (MYSQL* koneksi)
{
    MYSQL_ROW baris;
    MYSQL_RES* hasil;
    string id_pelanggan;
    int cek_fungsi;
    cout << endl;
    cout << "\t\tMasukan ID Pelanggan : ";
    cin >> id_pelanggan;
    cout << endl;

    string perintah = "SELECT *FROM pelanggan WHERE id_pelanggan = '"+id_pelanggan+"'";

    const char* rubah_data = perintah.c_str();

    cek_fungsi = mysql_query(koneksi, rubah_data);


    if(!cek_fungsi)
    {
        hasil=mysql_store_result(koneksi);
        cout << endl;
        cout << "\t\t=========================================================================================" << endl;
        cout << "\t\t" << "ID PELANGGAN || NAMA PELANGGAN  || ALAMAT \t\t || NO HP\t || PASPORT    ||" << endl;
        cout << "\t\t=========================================================================================" << endl;
        cout << endl;
        while(baris=mysql_fetch_row(hasil))
        {
            cout << "\t\t" << baris [0] << "\t     || " << baris[1] << "\t|| " << baris[2] << "\t || " << baris[3] << "\t || " << baris[4] << endl;
        }
        cout << endl;
        cout << "\t\tTEKAN ENTER UNTUK KEMBALI KE MENU...";
        getch();
        menu_utama(koneksi);
    }
    else
    {
        cout << "\t\tDATA KOSONG...";

    }
}

void lihat_semua_data (MYSQL* koneksi)
{
    MYSQL_ROW baris;
    MYSQL_RES* hasil;
    int cek_fungsi;


    string perintah = "SELECT *FROM pelanggan";

    const char* rubah_data = perintah.c_str();

    cek_fungsi = mysql_query(koneksi, rubah_data);


    if(!cek_fungsi)
    {
        hasil=mysql_store_result(koneksi);
        cout << endl;
        cout << "\t\t=========================================================================================" << endl;
        cout << "\t\t" << "ID PELANGGAN || NAMA PELANGGAN  || ALAMAT \t\t || NO HP\t || PASPORT    ||" << endl;
        cout << "\t\t=========================================================================================" << endl;
        cout << endl;
        while(baris=mysql_fetch_row(hasil))
        {
            cout << "\t\t" << baris [0] << "\t     || " << baris[1] << "\t|| " << baris[2] << "\t || " << baris[3] << "\t || " << baris[4] << endl;
        }
        cout << endl;
        cout << "\t\tTEKAN ENTER UNTUK KEMBALI KE MENU...";
        getch();
        menu_utama(koneksi);
    }
    else
    {
        cout << "\t\tDATA KOSONG...";
    }
}

void hapus_data_pelanggan (MYSQL* koneksi)
{
    system("CLS");
    string id_pelanggan;
    int cek_fungsi;
    cout << endl;
    cout << "\t\tMasukan ID Pelanggan yang ingin dihapus : ";
    cin >> id_pelanggan;
    cout << endl;

    string perintah = "DELETE FROM pelanggan WHERE id_pelanggan = '"+id_pelanggan+"'";

    const char* rubah_data = perintah.c_str();

    cek_fungsi = mysql_query(koneksi,rubah_data);

    if (!cek_fungsi)
    {
        cout << endl;
        cout << "\t\tDATA TERSEBUT BERHASIL DI HAPUS...";
        cout << endl;
        cout << "\t\tTEKAN ENTER UNTUK KEMBALI KE MENU...";
        getch();
        menu_utama(koneksi);
    }
    else
    {
        cout << "\t\tADA QUERY YANG BERMASALAH...";
        cout << "\t\tTEKAN ENTER UNTUK EXIT PROGRAM...";
        getch();
        menu_utama(koneksi);
    }

}

void data_pelanggan (MYSQL* koneksi)
{
    system("CLS");
    int pilih_menu;
    cout << endl;
    cout << "\t\t  DATA PELANGGAN  " << endl;
    cout << "\t\t------------------" << endl;
    cout << endl;
    cout << "\t\t1. Cari Data Berdasarkan ID Pelanggan " << endl;
    cout << "\t\t2. Lihat Semua Data Pelanggan " << endl;
    cout << "\t\t3. Hapus Data Pelanggan " << endl;
    cout << endl;
    cout << "\t\tPilih menu : ";
    cin >> pilih_menu;
    switch (pilih_menu)
    {
    case 1:
        system("CLS");
        cari_data_user(koneksi);
        break;
    case 2:
        system("CLS");
        lihat_semua_data(koneksi);
        break;
    case 3:
        system("CLS");
        hapus_data_pelanggan(koneksi);
        break;
    default:
        system("CLS");
        cout << "\t\tSALAH MASUKAN PILIHAN...";

    }
}

void tambah_jadwal (MYSQL* koneksi)
{
    int cek_fungsi;
    string id_penerbangan, tujuan, harga;
    cout << endl;
    cout << "\t\t   PENAMBAHAN JADWAL PESAWAT   " << endl;
    cout << "\t\t-------------------------------" << endl;
    cout << endl;
    cin.ignore();
    cout << "\t\tMasukan ID Penerbangan : ";
    getline(cin, id_penerbangan);
    cout << "\t\tTujuan : ";
    getline(cin, tujuan);
    cout << "\t\tHarga : ";
    getline(cin, harga);

    string insert_data = "INSERT INTO data_penerbangan (id_penerbangan, tujuan, harga) VALUES ('"+id_penerbangan+"','"+tujuan+"','"+harga+"')";

    const char* rubah_data = insert_data.c_str();

    cek_fungsi = mysql_query(koneksi,rubah_data);

    if (!cek_fungsi)
    {
        cout << endl;
        cout << "\t\tDATA BERHASIL DISIMPAN...";
        cout << endl;
        cout << "\t\tTEKAN ENTER UNTUK KEMBALI KE MENU...";
        getch();
        menu_utama(koneksi);
    }
    else
    {
        cout << "\t\tADA QUERY YANG BERMASALAH...";
        cout << "\t\tTEKAN ENTER UNTUK EXIT PROGRAM...";
        getch();

    }
}

void cek_detail_tiket (MYSQL* koneksi)
{
    MYSQL_ROW baris;
    MYSQL_RES* hasil;
    string id_transaksi;
    int cek_fungsi;
    cout << endl;
    cout << "\t\tMasukan ID Pesanan/Transaksi : ";
    cin >> id_transaksi;
    cout << endl;

    string perintah = "SELECT pelanggan.id_pelanggan, pelanggan.nama_pelanggan, data_penerbangan.id_penerbangan, transaksi_tiket.id_transaksi FROM pelanggan INNER JOIN transaksi_tiket ON pelanggan.id_pelanggan = transaksi_tiket.id_pelanggan INNER JOIN data_penerbangan ON transaksi_tiket.id_penerbangan = data_penerbangan.id_penerbangan WHERE transaksi_tiket.id_transaksi = '"+id_transaksi+"'";

    const char* rubah_data = perintah.c_str();

    cek_fungsi = mysql_query(koneksi, rubah_data);


    if(!cek_fungsi)
    {
        hasil=mysql_store_result(koneksi);
        cout << endl;
        cout << "\t\t=========================================================================================" << endl;
        cout << "\t\t" << " ID PELANGGAN || NAMA PELANGGAN || ID PENERBANGAN  || ID TRANSAKSI   ||  " << endl;
        cout << "\t\t=========================================================================================" << endl;
        cout << endl;
        while(baris=mysql_fetch_row(hasil))
        {
            cout << "\t\t" << baris [0] << "\t     || " << baris[1] << "\t|| " << baris[2] << "\t || " << baris[3] << endl;
        }
        cout << endl;
        cout << "\t\tTEKAN ENTER UNTUK KEMBALI KE MENU...";
        getch();
        menu_utama(koneksi);
    }
    else
    {
        cout << "\t\tDATA KOSONG...";

    }

}

int menu_utama (MYSQL* koneksi)
{
    int pilih_menu;
    system("CLS");
    cout << endl;
    cout << "\t\t  PEMESANAN TIKET PESAWAT  " << endl;
    cout << "\t\t---------------------------" << endl;
    cout << endl;
    cout << "\t\t1. Pendaftaran Pelanggan " << endl;
    cout << "\t\t2. Pemesanan Tiket Pesawat " << endl;
    cout << "\t\t3. Penambahan Jadwal Pesawat " << endl;
    cout << "\t\t4. Data Pelanggan " << endl;
    cout << "\t\t5. CEK DETAIL TIKET PELANGGAN" << endl;
    cout << "\t\t6. EXIT PROGRAM" << endl;
    cout << endl;
    cout << "\t\tPilih menu : ";
    cin >> pilih_menu;
    switch (pilih_menu)
    {
    case 1:
        system("CLS");
        pendaftaran_pelanggan(koneksi);
        break;
    case 2:
        system("CLS");
        pemesanan_tiket(koneksi);
        break;
    case 3:
        system("CLS");
        tambah_jadwal(koneksi);
        break;
    case 4:
        system("CLS");
        data_pelanggan(koneksi);
        break;
    case 5:
        system("CLS");
        cek_detail_tiket(koneksi);
        break;
    default:
        system("CLS");
        cout << "\t\tSALAH MASUKAN PILIHAN...";

    }

}




int main()
{
    MYSQL* koneksi;
    koneksi = mysql_init(0);
    koneksi = mysql_real_connect(koneksi, "localhost","root","","tiket_pesawat", 0, NULL, 0);


    if (koneksi)
    {
        cout << "\t\tDATABASE SUDAH CONNECT..." << endl;
        menu_utama(koneksi);
    }
    else
    {
        cout << "\t\tDATABASE TIDAK TERKONEKSI..." << endl;
    }
    return 0;
}
