/*program dijalankan di Dev-C++

5130411270 (MUHAMMAD HADI RIBOWO)
5130411275 (AHMAD KHOTIBUL UMAM)
5130411274 (YANTO TEBAI)

*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <iomanip>
#include <windows.h>

using namespace std;
int pil;
int add_pilih();
int add_baru();
int add_depan();
int add_belakang();
int delete_depan();
int delete_belakang();
int add_tampil();
struct mahasiswa
{
    char nim[50], nama [50];
    int nilai;
    struct mahasiswa *next;
} mhs, *baru, *awal=NULL, *akhir=NULL,*hapus,*bantu;
int clrscr()
{
    system("cls");
}
int main()
{
    do
    {
        clrscr();
        cout<<"Daftar Nilai Mahasiswa Struktur Data"<<endl<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan"<<endl;
        cout<<"6. Selesai"<<endl<<endl;
        cout<<"Pilihan Anda : ";
        cin>>pil;
        add_pilih();
    } while(pil!=6);
    return 0;
}
int add_pilih()
{
    if(pil==1)
        add_depan();
    else if(pil==2)
  add_belakang();
    else if(pil==3)
        delete_depan();
     else if(pil==4)
        delete_belakang();
      else if(pil==5)
        add_tampil();
}
int add_baru()
{
    baru=(mahasiswa*)malloc(sizeof(struct mahasiswa));
    cout<<"input nim   : ";cin>>baru->nim;
    cout<<"input nama  : ";cin>>baru->nama;
    cout<<"input nilai  : ";cin>>baru->nilai;
    baru->next=NULL;
}
int add_depan()
{
    add_baru();
    if(awal==NULL)
    {
        awal=baru;
        akhir=baru;
        akhir->next=NULL;
    }
    else
    {
        baru->next=awal;
        awal=baru;
    }
    cout<<endl<<endl;
    add_tampil();
}
int add_belakang()
{
    add_baru();
    if(awal==NULL)
    {
        awal=baru;
    }
    else
    {
        akhir->next=baru;
    }
    akhir=baru;
    akhir->next=NULL;
    cout<<endl<<endl;
    add_tampil();
}

int delete_depan()
{
    if (awal==NULL)
        cout<<"Kosong";
    else
    {
        hapus=awal;
        awal=awal->next;
        free(hapus);
    }
   cout<<endl<<endl;
    add_tampil();
}
int delete_belakang()
{
    if (awal==NULL)
        cout<<"Kosong";
    else if(awal==akhir)
    {
         hapus=awal;
         awal=awal->next;
         free(hapus);
    }
    else
    {
        hapus=awal;
        while(hapus->next!=akhir)
             hapus=hapus->next;
        akhir=hapus;
        hapus=akhir->next;
        akhir->next=NULL;
        free(hapus);
    }
    cout<<endl<<endl;
    add_tampil();
}
int add_tampil()
{
     if (awal==NULL)
          cout<<"Kosong";
     else
     {
	 	cout<<"--------------------------------------------------"<<endl;
     	cout<<"   NIM   |   Nama   |   Nilai   |   NILAI MUTU    |"<<endl;
     	cout<<"--------------------------------------------------"<<endl;
         bantu=awal;
         while(bantu!=NULL)
         {
     		cout<<" "<<setiosflags(ios::left)<<setw(7)<<bantu->nim;
      		cout<<" "<<setiosflags(ios::left)<<setw(8)<<bantu->nama;
      		cout<<" "<<setiosflags(ios::right)<<setw(8)<<bantu->nilai;
      		cout<<" "<<setiosflags(ios::right)<<setw(11);
      		char skor;
			if(bantu->nilai >= 80) 
			skor='A'; 
			else 
    		if(bantu->nilai >= 70) 
    		skor='B'; 
    		else 
        	if(bantu->nilai >= 60) 
        	skor='C'; 
        	else 
            if(bantu->nilai >=50) 
            skor='D'; 
            else 
                skor='E';
      		cout<<setprecision(2)<<skor<<endl; 
            bantu=bantu->next;
         }
     }
     getch();
}
