// veritabaniproje.cpp : Defines the entry point for the console application.
//

//oDEV 2
//ogrenci1 No:1030516163
//ogrenci1 �smi ve Soyadi:H�SEY�N H�RKAN KARAMAN
//ogrenci2 No:1030516153
//ogrenci2 �smi ve Soyadi:AL� FURKAN GEZER
//ogrenci3 No:1030516177
//ogrenci3 �smi ve Soyadi:SEM�H CAN BOZOK
//ogrenci4 No:1030516296
//ogrenci4 �smi ve Soyadi:EKREM K�RSAD DAL
//DERS KODU:BZ205
//DOSYA �SM�:veritabaniproje


//Kullanilacak kutuphaneler tanimladik.
#include "stdafx.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))//Array boyutunu d�nderen tan�mlama,array boyutunu ��renmek i�in tan�mlad�k,kullan�rsak diye.

using namespace std;



class Node//Dugum sinifimizi tanimladik.
{
public:
	
	int numara;//Ogrencinin numarasi
	string ograd;//Ogrencinin adi
	string ogrSoy;//Ogrencinin soyadi
	string ogrBol;//Ogrencinin bolumu
	Node* next;//bir sonraki dugumun adres bilgisi
	
};



class List//Baglanti Liste Sinifimizi tanimliyoruz.
{
public:
	List(void) { head = NULL; }  //constructor
	~List(void);//destructor

	bool IsEmpty() { return head == NULL; }//eger bo�sa head,ba� null a esittir.
	Node* InsertNode(int index, int no,string ad, string soyad, string bolum);//Dugum eklemek icin no,ad,soyad,bolum bilgilerini kullaniyoruz.
	int FindNode(int no);//Dugum bulmak icin findnode da numara aldik.
	int DeleteNode(int no);//Dugum silmek icin de deleteNode da int turunde tuttugumuz numarayi aldik.
	void DisplayList(void);//Listeyi yazdiran fonksiyon.
	Node* bas();//Listenin basini donduren fonksiyon ilerde kullanmak icin.
	int nodonder(int no);//Numara bilgisi girilen kisinin listede var oldugunu teyit edip,bulup numarasini donduruyor.
	Node* soydonder(string soy);//soyadi  girilen kisinin soyadina gore dugumu bulup dugumu donderiyor.
	int boyutdonder();	//boyun d�nderen fonksiyon	*****************************************//YEN� FONKS�YON
	void KabarcikSiralama(Node* a[],int N);//Kabarcik siralamasi i�in kullan�lan fonksiyon.	****	//YEN� FONKS�YON
	void ArayaSokma(int c[], int n);//araya sokma s�ralamas� i�in kullan�lan fonksiyon.		****	//YEN� FONKS�YON
	Node* noyadonder(int no);//numaras� girilen ��rencinin d���m�n� d�nderen fonksiyon.		****	//YEN� FONKS�YON
	void lsd_string_radix(string b[], int boyut, int maxkarakter);//stringte soyadlar� g�derip s�raya dizen yani (Radiks Sort) yapan fonksiyonumuz.****	//YEN� FONKS�YON
	void sort(string a[], int W);//****//YEN� FONKS�YON	
private:
	Node* head;//Bas dugumumuz
	friend class Stack;//inherit yaptik
};
//Dugum ekleme
Node* List::InsertNode(int index,int no, string ad, string soyad, string bolum) {//fonksiyona,d��ar�dan ogrencinin indexini,ad�n�,soyad�n�,bolum bilgilerini al�yoruz;  
	if (index < 0) return NULL;//e�er indeximiz s�f�ra e�itse NULL de�er d�nderiyoruz.

	int currIndex = 1;//ilk ba�tan ba�lamak i�in currIndex yani �imdiki Index'i 1 yap�yoruz.
	Node* currNode = head;//yeni d���m tan�mlay�p bunu ba� d���m yap�yoruz.
	while (currNode && index>currIndex) {//d���m�m�z mevcut ve index'imiz �imdiki Index'ten b�y�k oldu�u s�rece
		currNode = currNode->next;//�imdiki d���m�m�z�n bir sonraki d���me ait olan adresini ,d���m�m�ze at�yoruz yani d���m ilerletiyoruz.
		currIndex++;//d���m�ze ait currIndex de�erimizi de art�r�yoruz.
	}
	if (index > 0 && currNode == NULL) return NULL;//e�er index de�erimiz 0 dan b�y�k ve d���m de�erimiz null'a e�itse sona gelmi�iz demektir o zaman NULL d�nderiyoruz.

	Node* newNode = new Node;//yeni d���m tan�ml�yoruz.
	
	newNode->numara = no;//yukar�da al�nan no'yu yeni d���m�n numaras�na at�yoruz.
	newNode->ograd = ad;//yukar�da al�nan ad'� yeni d���m�n ad'�na at�yoruz.
	newNode->ogrSoy = soyad;//yukar�da al�nan soyad'� yeni d���m�n soyad de�erine at�yoruz.
	newNode->ogrBol = bolum;//yukar�da al�nan bolum bilgisini yeni d���m�n bolum k�sm�na at�yoruz.
	if (index == 0) {//e�er d���m�m�z ba� d���mse,ba�a eklenecekse;
		newNode->next = head;//head te bulunan adres bilgisi yeni d���m�n adres k�sm�na at�l�r.
		head = newNode;//yeni d���m�n adresi de head'e at�l�r.
	}
	else {
		newNode->next = currNode->next;//e�er d���m ortaya ya da sona eklenecekse �imdiki d���m�n adresi,eklenen d���me at�l�r.
		currNode->next = newNode;//yeni d���m�n adres bilgisi de �imdiki d���me atan�r.
	}
	//cout << currNode->numara << "\n" << currNode->ograd << "\n" << currNode->ogrSoy << "\n" << currNode->ogrBol << "\n" << endl;
	cout << "Ekleme Basarili" << endl;//Ekleme ba�ar�l� ise Ekleme Ba�ar�l� mesaj� ��kar�l�r.
	return newNode;//yeni d���m fonksiyon taraf�ndan d�nd�r�l�r.
}

//Dugum bulma
int List::FindNode(int no) {//D���m bulmak i�in int t�r�nde no de�i�keni al�n�r.            
	Node* currNode = head;//�imdiki d���m ba� olarak tan�mlan�r.
	int currIndex = 1;//�imdiki d���m�n index de�eri 1 olarak atan�r.
	while (currNode&&currNode->numara != no) {//�imdiki d���m oldu�u s�rece ve �imdiki d���m�n numaras� fonksiyonun ald��� numara e�it olmad��� s�rece
		currNode = currNode->next;//d���m� bir ilerletip
		currIndex++;//index de�eri art�r�l�r taki currNode'un no de�eri fonksiyon a g�nderilen no de�erine e�it olana kadar.
	}
	if (currNode)//e�er D���m�m�z bulunuyorsa yani varsa
	{
		cout << fixed << setprecision(0)<< currNode->numara << "\n" << currNode->ograd << "\n" << currNode->ogrSoy << "\n" << currNode->ogrBol << endl;//d���me ait olan bilgiler yazd�r�l�r.
		return currIndex;//bulunan d���m�m�z�n index de�eri d�nderilir.
	}
	return 0;//e�er d���m�m�z yoksa 0 de�eri d�nderilir.
}

//Dugum Silme
int List::DeleteNode(int no) {//silmek i�in no al�n�r.
	Node* prevNode = NULL;//�nceki d���m de�erni null;
	Node* currNode = head;//�imdiki d���m de�eri ba� olarak atan�r.
	int currIndex = 1;//�imdiki d���m�n index de�eri 1 olarak atan�r.
	while (currNode&&currNode->numara != no) {//�imdiki d���m var oldu�u s�rece ve numaras� yukar�da al�nan no'ya e�it olmad��� s�rece;
		prevNode = currNode;//�imdi�i d���m �nceki d���me atan�r.
		currNode = currNode->next;//�imdiki d���m�n bir sonraki d���m�n adres bilgisi atanarak ilerletilir.
		currIndex++;//�imdiki d���m�n index de�eri bir art�r�l�r.
	}
	if (currNode) {//e�er �imdiki d���m�m�z mevcutsa
		if (prevNode) {//�nceki d���m varsa yani ortaya ya da sona ekliyceksek
			prevNode->next = currNode->next;//�imdiki d���m�n adresi �ncekini atan�r.
			delete currNode;//�imdiki d���m silinir.
		}
		else {//ba�taysa
			head = currNode->next;//�imdiki d���m�n adres bilgisi head'e atan�r.
			delete currNode;//�imdiki d���m silinir.
		}
		return currIndex;//silinen d���m�n index de�eri d�nderilir.
	}
	return 0;//e�er i�lem ba�ar�l� olmazsa 0 d�nderilir.
}


//Butun Elemanlari Yazdirma
void List::DisplayList()//listeyi yazd�rma fonksiyonu
{
	int num = 0;//d���m say�s�n�, eleman say�s�n� saymak i�in numara tan�mlan�r int t�r�nde;
	Node* currNode = head;//yeni d���m tan�mlan�p head'e e�itlenir.
	while (currNode != NULL) //�imdiki d���m sona ula�mad��� s�rece
	{			
		cout << fixed<<setprecision(0)<< currNode->numara << endl;//Ogrencinin numarasi tam sayi seklinde yazdiriliyor.
		cout << currNode->ograd << endl;		//ograd� 
		cout << currNode->ogrSoy << endl;		//ogrSoyad�
		cout << currNode->ogrBol << endl;		//ogrBolum bilgisi yazd�r�l�r.
		cout << "\n" << endl;
		
		currNode = currNode->next;		//d���m� bir ad�m ilerletilir.
		num++;		//numara yani d���m,eleman say�s� 1 art�r�l�r.
	}
	
	cout<<"Number of nodes in the list(Listedeki bulunan itemlerin sayisi): "<<  num << endl;
}

//Listeyi yoketme
List::~List(void) {
	Node* currNode = head, *nextNode = NULL;//�imdiki d���m ba� olarak tan�mlan�r.bir sonraki d���m null olarak tan�mlan�r.
	while (currNode != NULL)//�imdiki d���m sona gelmedi�i s�rece
	{
		nextNode = currNode->next;//�imdiki d���m�n adres bilgisi nextNode dedi�imiz d���me atan�r.
		//destroy the current node//simdiki nodu yok ettik.
		delete currNode;//d���m silinir;
		currNode = nextNode;//nextNode da art�k �imdiki d���m olarak atan�r b�ylece liste yok olana kadar silme ger�ekle�ecektir.
	}
}

//Listenin headini donderen fonksiyon
Node* List::bas()
{
	return head;//basi donder;
}
//Numara Donduren Fonksiyon
int List::nodonder(int no)//numara donderme fonksiyonu i�in int t�r�nde numara de�i�keni al�n�r.
{
	Node* currNode = head;//�imdiki d���m ba� olarak tan�mlan�r.
	int currIndex = 1;//�imdiki d���m�n index de�eri 1 olarak belirlenir.
	while (currNode&&currNode->numara != no) {//alinan numara,dugumlerde bulunana kadar araniyor boylece dugum bulunup butun bilgiler donderilebilinir.
		currNode = currNode->next;//�imdiki d���m�n numara de�eri yukar�da gelen no ya e�it olana kadar d���m atlan�r.
		currIndex++;//index de�eri art�r�l�r.
	}
	if (currNode)//e�er �imdiki d���m mevcutsa
	{		
		return currNode->numara;//Biz burada sadece numaraya ihtiyac duyduk.//numara de�eri d�nderilir.
	}
	return 0;//e�er d���m yoksa return 0;
}
//Girilen soyada gore dugum donduren fonksiyon
Node* List::soydonder(string soy) {//girilen soyada g�re listede ya da y���nda bulunan node'u yani d���m� d�nderir.B�ylece b�t�n bilgilerine eri�ebiliriz.
	Node* currNode = head;//�imdiki d���m ba� olarak tan�mlan�r.
	int currIndex = 1;//index de�eri 1 olarak belirlenir.
	while (currNode&&currNode->ogrSoy !=soy) {//yukaridan alinan soyadi bilgisi listedeki dugumde bulunan soyadina esit olmadigi surece dugum atliyoruz ta ki bulana kadar.
		currNode = currNode->next;//yukar�da al�nan soyada �imdiki d���m�m�z�n soyad de�eri e�it olana kadar d���m ilerletilir
		currIndex++;//index de�eri art�r�l�r e�it olunca ��k�l�r.
	}
	if (currNode->ogrSoy==soy)//alinan soyad bulunana esitse dugumu donduruyor.
	{		
		return currNode;//dugum donduruluyor boylece o ogrencinin numarasindan bolumune kadar bilgilerine erisim saglanabilir.
	}
	return NULL;//e�er d���m bulunmad�ysa return NULL yapt�k.


}

int List::boyutdonder()
{
	int num = 0;//d���m say�s�n�, eleman say�s�n� saymak i�in numara tan�mlan�r int t�r�nde;
	Node* currNode = head;//yeni d���m tan�mlan�p head'e e�itlenir.
	while (currNode != NULL) //�imdiki d���m sona ula�mad��� s�rece
	{
	
		currNode = currNode->next;		//d���m� bir ad�m ilerletilir.
		num++;		//numara yani d���m,eleman say�s� 1 art�r�l�r.
	}

	return num;

}

void List::KabarcikSiralama(Node* a[], int N)
{
	Node* ge�ici;//ge�ici temp d���m� tan�mlad�k.
	int k, hareket;//k ve hareket dedi�imiz de�i�kenlerimizi d�ng� i�in tan�mlad�k.
	for (hareket = 0; hareket < N - 1; hareket++)//hareket de�i�kenini kullanarak,ana for d�ng�m�z� tan�mlad�k.
	{
		for (k = 0; k < N - 1 - hareket; k++)//k de�i�kenini her bir ad� kar��la�t�rmak i�in for d�ng�s�nde kulland�k.
		{
			if (a[k]->ograd > a[k + 1]->ograd)//d���m�n ad�,bir sonraki d���m�n ad�ndan b�y�kse
			{
				ge�ici = a[k];//swap i�lemi yap�caz bunun i�in,a[k] de�erini ge�ici bir d���me at�yoruz.
				a[k] = a[k + 1];//a[k+1] de bulunan de�eri,a[k] at�yoruz.
				a[k + 1] = ge�ici;//ge�ici d���mde bulunan de�eri a[k+1]'e at�yoruz.Bu �ekilde takas i�lemini tamamlam�� oluyoruz.
			}//Sonu�ta bubble sort'un can al�c� k�sm�n� yukardaki if in i� k�sm�nda ger�ekle�tirmi� oluyoruz.
		}
	}
	for (int i = 0; i < N; i++)//yazd�rma d�ng�s�
	{
		cout << a[i]->numara << endl;//d���me ait olan,numara,ad,soyad,bolum bilgilerini yazd�r�yoruz.
		cout << a[i]->ograd << endl;
		cout << a[i]->ogrSoy << endl;
		cout << a[i]->ogrBol << endl;
		cout << "\n" << endl;

	}	
	
}

Node* List::noyadonder(int no)//Numaras� girilen ��renci i�in d���m d�nderen fonksiyon.
{
	Node* currNode = head;//�imdiki d���m ba� olarak tan�mlan�r.
	int currIndex = 1;//�imdiki d���m�n index de�eri 1 olarak belirlenir.
	while (currNode&&currNode->numara != no) {//alinan numara,dugumlerde bulunana kadar araniyor boylece dugum bulunup butun bilgiler donderilebilinir.
		currNode = currNode->next;//�imdiki d���m�n numara de�eri yukar�da gelen no ya e�it olana kadar d���m atlan�r.
		currIndex++;//index de�eri art�r�l�r.
	}
	if (currNode)//e�er �imdiki d���m mevcutsa
	{
		return currNode;//Biz burada d���m d�nderdik.
	}
	return 0;//e�er d���m yoksa return 0;

}

//ARAYA SOKMA(INSERTION) ���N

void List::ArayaSokma(int c[], int n)
{
	int  k;//k ve ekle olmak �zere 2 de�i�ken belirlenir.	
	int ekle;//ekle de�i�keni tan�mlan�r.
	
	for (int i = 1; i < n; i++)//araya sokma i�in ilk for d�ng�s�
	{
		ekle = c[i];//c nin ilk eleman� ekle de�i�kenine atan�r.
		for (k = (i - 1);( k >= 0) && (ekle <= c[k]); k--)//ikinci for d�ng�s�
			c[k + 1] = c[k];//as�l s�raya koyma burada ger�ekle�ir.c nin k. indisindeki de�eri,k+1 e atan�r.
		c[k + 1] = ekle;//ekle de bulunan eleman c nin k+1 inci indeksine atan�r.
	}
	
	for (int z = 0; z < n; z++)//yazd�rma d�ng�s�
	{
		Node* dugum = noyadonder(c[z]);//numaras� girilen ogrencinin d���m� �a�r�larak di�er bilgilere ula��l�r.
		cout << dugum->numara << endl;//bilgiler yazd�r�l�r.
		cout << dugum->ograd << endl;
		cout << dugum->ogrSoy << endl;
		cout << dugum->ogrBol << endl;
		cout << "\n" << endl;

	}
}



void List::lsd_string_radix(string b[], int boyut, int maxkarakter)
{
	string *temp = new string[boyut];//temp dedi�imiz dinamik dizi olu�turuyoruz pointer sayesinde;
	

	for (int i = maxkarakter - 1; i >= 0; i--)//ana for d�ng�m�z.maksimum karakter say�s�ndan ba�layarak azalarak d�ng� devam ediyor.
	{
		
		int count[27] = { 0 };//ingiliz alfabesi temel al�nd���ndan count 27 olmal�.

		for (int j = 0; j < boyut; j++)//i�erde bulunan 1.for d�ng�s�
			count[static_cast<int>(b[j][i]) - 96]++;//static cast int sayesinde asci den int e �evriliyor.ve saya� 1 art�r�l�yor.

		for (int j = 2; j < 26; j++)//geri kalanlar aras�nda 2 den 26 ya kadar,count dizisinde j inci terim e j-1 inci terimler toplan�yor.
			count[j] += count[j - 1];
		
		for (int j = 0; j < boyut; j++)//tekrardan saya�ta asciden int a d�n���m yap�l�yor.
			temp[count[static_cast<int>(b[j][i]) - 97]++] = b[j];//temp dizisinde saklan�yor bu sefer.
		
		for (int j = 0; j < boyut; j++)//temp dizisinde bulunan string de�i�kenler s�ralanm�� olarak tekrardan fonksiyona gelen b dizisine atan�yor.
			b[j] = temp[j];//tekrar atanma,s�ralanm�� bir �ekilde.
		
	}


}

//BAgLANTILI L�STE TABANLI GERcEKLEsT�RME YIgIN(TEMEL �sLEMLER + EK FONKS�YONLAR)
class Stack :public List {
public:
	Stack(){}//constructor
	~Stack(){}//destructor
	int Top() {
		if (head == NULL) {//e�er ba� null a e�itse y���n bo� demektir.
			cout << "Error: the stack is empty" << endl;
			return -1;
		}
		else
		{
			cout << fixed << setprecision(0) << head->numara << "\n" << head->ograd << "\n" << head->ogrSoy << "\n" << head->ogrBol << endl;
			return head->numara;//e�er y���n varsa o zaman ba��n yani y���n�n en �st�nde bulunan eleman�n ,d���m�n numaras� d�nderilir.
		}
			
	}//stack te Top fonksiyonu
	void Push(const int x, int no, string ad, string soyad, string bolum) {InsertNode(0,no,ad,soyad,bolum); }//stacke ogrenci eklememizi eleman eklememize yarayan fonksiyon.Temel liste fonk.kullaniliyor.
	int Pop() {
		if (head == NULL) {//e�er y���n bo� ise return -1;
			cout << "Error: the stack is empty." << endl;//hata mesaj� g�sterilir.
			return -1;
		}
		else {
			int val = head->numara;//y���n bo� de�ilse,y���n�n en �st�nde bulunan d���m�n
			string ad = head->ograd;//head'in de�erleri ad,soyad ve bolum bilgileri de�i�kenlere atan�r.
			string soyad = head->ogrSoy;
			string bolum = head->ogrBol;
			cout << val << "\n" << ad << "\n" << soyad << "\n" << bolum << endl;//de�i�kenlerin de�erleri atan�r.
			DeleteNode(val);//yazd�r�lan d���m�n bilgileri yazd�r�l�p d���m silinmek i�in d���m silme metodu �a�r�l�r.
			return val;//d���m d�nderilir.
		}
	}//stack te ustte bulunan elemani siliyoruz.stackte silme yapmamiza yariyan fonksiyon.
	void DisplayStack() { DisplayList(); }//yigini yazdirma
	Node* headgetir() {
		if (head == NULL) {//e�er stack bo�sa hata mesaj� g�sterilir.
			cout << "Error: the stack is empty" << endl;
			return NULL;
		}
		else
		{			
			return head;//e�er y���n bo� de�ilse o zaman y���n�n ba� d���m� d�nderilir.
		}
	}//stack in basini donduren fonksiyon;
	
	
	


};


//ANA KISIM
int main()
{
	List list;//bagli liste(diferansiyel dersi)
	Stack stack;//yigin(veri tabani dersi)
	Stack grupB;//grup b ve a ayirmak icin
	Stack grupA;
	int index = 0;//index eklemelerde kullanmak icin;
	

	int selection;
	do
	{//Programin Menu listesini olusturuyoruz.
		cout << "  Veri Yapilari Projesi\n";
		cout << "  ====================================\n";
		cout << "  1.  Baglantili Listede Ekleme\n";
		cout << "  2.  Baglantili Listede Bulma\n";
		cout << "  3.  Baglantili Listede Silme\n";
		cout << "  4.  Baglantili Listeyi Yazdirma\n";
		cout << "  5.  Yiginda Ekleme\n";
		cout << "  6.  Yiginda Silme\n";
		cout << "  7.  Yiginda Son Ogrencinin Bilgileri\n";
		cout << "  8.  Yiginda Bulunan Elemanlari Listele\n";		
		cout << "  9.  Veritabani dersini alan ogrencilerin listesini olustur!\n";
		cout << "  10. Diferansiyel Denklemler Dersini alan ogrencilerin listesini olustur!\n";
		cout << "  ====================================\n";		
		cout << "\n";
		cout << "  11.  Her iki dersi de alan ogrencileri listeleme\n";
		cout << "  12.  Sadece Diferansiyel dersini alan ogrencileri listeleme\n";
		cout << "  13.  Veri Tabani Dersini 2 gruba ayirma(A grubu numarasi cift,B grubu numarasi tek)\n";
		cout << "  14.  Diferansiyel Denklemler ve Veritabani derslerinden en az birini alan ve bilgisayar muhendisligi bolumu ogrencisi olan ogrencileri listeleme \n";
		cout << "  15.  Her iki dersi alan fakat soyadlari ayni adlari farkli olan ogrencileri bulma\n";
		cout << "  16.  Kabarcik siralama algoritmasini kullanarak her iki dersi de alan ogrencileri adlarina gore sirala\n";
		cout << "  17.  Radiks siralama algoritmasini kullanarak sadece Diferansiyel Denklemler dersini alan ogrencileri soyadlarina gore sirala\n";
		cout << "  18.	Araya sokma siralama algoritmasini kullanarak Veritabani dersini alanlari numaralarina gore sirala\n";
		cout << "  19.  Cikis\n";
		cout << "  ====================================\n";
		cout << "  Seciminizi Girin: ";
		cin >> selection;
		cout << endl;

		switch (selection)//Menu olusturmak icin switch case yapisi kullandik.
		{
		//////////////BAgLANTILI L�STE �SLEMLER�
		case 1:
		{
			cout << "Baglantili listeye ekleme\n";
			cout << "\n";	
			int no1;
			cout << "Ogrenci numarasini girin:" << endl;			
			cin >> no1;//ogrencinin numarasini aldik.
			string ad1;
			cout << "Adinizi girin:" << endl;			
			cin >> ad1;//ogrencinin adini aldik.
			string soyad1;
			cout << "Soyadinizi girin:" << endl;			
			cin >> soyad1;//ogrencinin soyadini  aldik.
			string bolum1;
			cout << "Bolumunuzu girin." << endl;			
			cin >> bolum1;//ogrencinin bolum bilgisini aldik.
			Node* newNode=list.InsertNode(index, no1, ad1, soyad1, bolum1);//Ekleme fonksiyonunu cagirdik.
			index++;//index arttirdik.
			break;//case den ciktik.
		}
		
		case 2:
		{
			cout << "Baglantili listede Bulma\n";
			cout << "\n";
			cout << "Aranan ogr'nin numarasini giriniz:\n" << endl;
			int arano;
			cin >> arano;
			list.FindNode(arano);//aranan ogrencinin numarasi alinarak gerekli bilgiler ekrana yansitiliyor.
			break;//caseden ciktik.
		}		
		
		case 3:
		{
				cout << "Baglantili Listede Silme\n";
				cout << "\n";
				int arano;
				cout << "Silinecek ogr'nin numarasini giriniz:\n" << endl;				
				cin >> arano;
				list.DeleteNode(arano);//Silinecek ogrencinin numarasini alarak silip ekrana bilgilerini yazdirdik.
				break;
		}
		case 4:
		{				
				cout << "Baglantili Listeyi Yazdirma\n";
				cout << "\n";
				list.DisplayList();//Listeyi ekrana yazdirma fonksiyonunu cagirdik.
				break;
		}
		//////////////YIGIN �SLEMLER�
		case 5:
		{
			
				cout << "Yiginda Ekleme\n";
				cout << "\n";				
				cout << "Ogr No giriniz:\n";
				int ogrNo;
				cin >> ogrNo;
				cout << "Ogr Adi giriniz:\n";
				string ogrAd;
				cin >> ogrAd;
				cout << "Ogr Soyadi giriniz:\n";
				string ogrSoy;
				cin >> ogrSoy;
				cout << "Ogr bolum giriniz:\n";
				string ogrBolum;
				cin >> ogrBolum;
				stack.Push(0,ogrNo,ogrAd,ogrSoy,ogrBolum);//Yukarida bilgilerini aldigimiz ogrenciyi yigina ekliyoruz,ekleme fonksiyonunu cagiriyoruz.				
				break;
		}
		case 6:
		{			
				cout << "Yiginda Silme(PoP)\n";
				cout << "\n";
				stack.Pop();//Yigindan eleman silmek icin,temel yigin fonksiyonu olan pop() gerceklestiriyoruz.
				break;
		}
		case 7:
		{			
				cout << " Yiginda Son Ogrencinin Bilgileri\n";
				cout << "\n";
				stack.Top();//Yiginin en ustunde bulunan ogrencinin bilgilerini Top() fonksiyonu ile yazdiriyoruz.
				break;
		}
		case 8:
		{			
				cout << " Yiginda Bulunan Elemanlari Listele\n";
				cout << "\n";
				stack.DisplayStack();//Yiginda bulunan elemanlari ekrana yazdirmak icin DisplayStack() temel fonksiyonunu cagirdik.
				break;
		}
		//////////////////////////////////////////////////////////////
		////////////////OTOMAT�K SINIF L�STES� OLUsTUMA//////////////
		case 9:	
		{
				cout << "Veritabani dersini alan ogrencilerin listesini olustur(yigin)\n";
				stack.Push(0, 1041, "Ali", "Keser", "Computer Eng.");
				stack.Push(0, 1042, "Mehmet", "Emin", "Computer Eng.");
				stack.Push(0, 1043, "Hasan", "Karaca", "Computer Eng.");
				stack.Push(0, 1420, "Racquel", "Pepper", "Electric Eng.");
				stack.Push(0, 1450, "Keturah", "Hudak", "Biologic Eng.");/////////////2 dersi de alan
				stack.Push(0, 1360, "Lala", "Daub", "Biologic Eng.");/////////////2 dersi de alan
				stack.Push(0, 1270, "Leyla", "Bulan", "Computer Eng.");///////Soyadlari ayni adlari farkli olanlar
				stack.Push(0, 1290, "Zehra", "Bulan", "Computer Eng.");///////Soyadlari ayni adlari farkli olanlar
				break;
		}
		
		case 10:
		{
				cout << "Diferansiyel dersini alan ogrencilerin listesini olustur(baglantili liste)\n";
				list.InsertNode(0, 1050,"Elif","kara","Computer Eng.");
				list.InsertNode(1, 1310,"Buse","ak","Computer Eng.");
				list.InsertNode(2, 1250,"Ayse","beli","Computer Eng.");
				list.InsertNode(3, 1280, "Lee", "penrouse", "Electric Eng.");
				list.InsertNode(4, 1360, "Lala", "Daub", "Biologic Eng.");/////////////2 dersi de alan
				list.InsertNode(5, 1450, "Keturah", "Hudak", "Biologic Eng.");/////////////2 dersi de alan
				list.InsertNode(6, 1290, "Zehra", "Bulan", "Computer Eng.");///////Soyadlari ayni adlari farkli olanlar
				list.InsertNode(7, 1270, "Leyla", "Bulan", "Computer Eng.");///////Soyadlari ayni adlari farkli olanlar
				break;
		}
		//////////////////////////////////////////////////////////////////
		
		case 11:
		{
				cout << "Her iki dersi de alan ogrencileri listeleme\n";								
				Node* currNode =list.bas();//CurrNode,listenin basindan baslayacak bir dugum tanimladik.				
				while (currNode != NULL)//currNode bos olmadigi surece,sona gelmedi�i s�rece
				{					
					if (list.nodonder(currNode->numara)==stack.nodonder(currNode->numara))//eger simdiki dugumun numarasi hem listede hem stack te mevcutsa her iki dersten de ders aliniyor demektir.
						//no donder fonksiyonu ile numaraya ait olan dugum bulunup,eleman bulunup ozellikleri karsilastiriliyor esit mi diye degil mi diye.Esitse dugume ait olan bilgiler yazdiriliyor.
						{
							cout << fixed << setprecision(0) << currNode->numara << "\n" << currNode->ograd << "\n" << currNode->ogrSoy << "\n" << currNode->ogrBol << endl;
							//fixed ve setprecision ile ogrencinin numarasini ondalikli olmayacak sekilde tam sayi gibi yazdiriyoruz.
						}										
					currNode = currNode->next;//bir sonraki dugume gecis yaptiriyoruz.					
				}				
				break;
		}
		
		case 12:
		{
				cout << "Sadece Diferansiyel dersini alan ogrencileri listeleme\n";
				
				Node* currNode = list.bas();//baglantili listenin basindan baslamak icin basa esit olan bir dugum tanimladik.
				while (currNode != NULL)//dugum bos olmadigi surece yani sona gelmedigi surece
				{
					if(list.nodonder(currNode->numara)!=stack.nodonder(currNode->numara))//nodonder fonksiyonu kullanarak ogrencilere ait bilgilere ulasiyoruz.Daha sonra
					{//yiginda bulunan numara listede bulunmuyorsa yani diferansiyel dersini aliyorsa yazdiriliyor.
						cout << fixed << setprecision(0) << currNode->numara << "\n" << currNode->ograd << "\n" << currNode->ogrSoy << "\n" << currNode->ogrBol << endl;
					}						
					currNode = currNode->next;//dugum ilerletiyoruz.
				}			
				break;
		}
		case 13:
		{			
				cout << "Veri Tabani Dersini 2 gruba ayirma(A grubu numarasi cift, B grubu numarasi tek) \n";
				Node* currNode = stack.headgetir();//headgetir() ile yiginin basina eit olan bir dugum tanimliyoruz.
					while (currNode != NULL)//dugum bos olmadigi surece,sona gelmedi�i s�rece
					{
						if (int(currNode->numara) % (2)==0)//eger ki ogrencinin numarasi mod(2)=0 ise cift demektir.A grubuna stack ine push yapiyoruz.
						{
							
							grupA.Push(0, currNode->numara, currNode->ograd, currNode->ogrSoy, currNode->ogrBol);
							
						}
						else//degilse tek demektir.B grubuna push yapiyoruz.
						{
							grupB.Push(0, currNode->numara, currNode->ograd, currNode->ogrSoy, currNode->ogrBol);
						}
						currNode = currNode->next;//dugumu ilerletiyoruz.
					}

					cout << "Grup A(numarasi cift olanlar)" << endl;
					grupA.DisplayStack();//cift olanlari yazdiriyoruz.
					cout << "Grup B(numarasi tek olanlar)" << endl;
					grupB.DisplayStack();//Tek olanlari yazdiriyoruz.
				break;
		}
		case 14:
		{			
				cout << "Diferansiyel Denklemler ve Veritabani derslerinden en az birini alan ve bilgisayar muhendisligi bolumu ogrencisi olan ogrencileri listeleme\n (Derslerde yandal ve cift anadal ile ders alan farkli bolum ogrencileri ve diger bolumlerden ogrenciler bulunabilmektedir.)\n ";
				Node* currNode = list.bas();//listenin basina esit olan bir dugum tanimladik.
				Node* currrNode = stack.headgetir();///*****3 R L� NODE var D�KKAT!!!!!///////////stack'in basina esit olan bir dugum tanimladik.
				while (currNode != NULL|| currrNode !=NULL)//Ayri ayri yapsak//liste veya yigin sona gelmedigi surece
				{					
						if ((currNode->ogrBol).find("Computer") != string::npos || (currrNode->ogrBol).find("Computer")!=string::npos)
							//listede(diferansiyel dersi) bulunan ogrenciler veya yiginda(veritabani dersi) bulunan ogrencilerin bolum bilgisinde computer cumlesi gecip gecmedigi kontrol ediliyor.
							//Boylece yandal veya cift anadal ogrencisi olsa bile sarti saglamis oluyor.
						{
							if (currNode->numara && currNode->ogrBol=="Computer Eng.")//listede bulunan elemanin numarasi mevcut ve bolum bilgisi kisminda Computer Eng ibaresi geciyorsa;
							{
								cout << fixed << setprecision(0) << currNode->numara << "\n" << currNode->ograd << "\n" << currNode->ogrSoy << "\n" << currNode->ogrBol << endl;//ogrenciye ait bilgiler yazdiriliyor.

							}
							if (currrNode->numara && currrNode->ogrBol == "Computer Eng.")//yiginda bulunan elemanin numarasi mevcut yani o dersi aliyorsa bolum bilgisi kisminda Computer Eng ibaresi geciyorsa;
							{
								cout << fixed << setprecision(0) << currrNode->numara << "\n" << currrNode->ograd << "\n" << currrNode->ogrSoy << "\n" << currrNode->ogrBol << endl;//ogrenciye ait bilgiler yazdiriliyor.

							}
						}									
					
					currNode = currNode->next;//listedeki dugumler ilerletiliyor sonuna kadar gezmek icin;
					currrNode = currrNode->next;//yiginda bulunan dugumler ilerletiliyor sonuna kadar gezmek icin;					
				}
				break;
		}
		case 15:
		{
			
				cout << "Her iki dersi alan fakat soyadlari ayni adlari farkli olan ogrencileri bulma\n";
				Node* currNode = list.bas();//listenin basini atiyoruz.
				Node* currrNode = stack.headgetir();//stack in basini atiyoruz.
				while (currNode != NULL)//listeden kontrole basliyacagiz.//liste sonuna gelinmedigi surece;
				{					
						if (list.nodonder(currNode->numara) == stack.nodonder(currNode->numara))//eger listede bulunan numara yigindada bulunuyorsa mevcutsa,her iki dersi de aliyorsa;
						{
							Node* curl = stack.soydonder(currNode->ogrSoy);//soydonder() fonksiyonu ile o numaraya ait ogrencinin stack te bulunan bilgileri curl dugumune atiliyor karsilastirmak icin;
							if (currNode->ogrSoy == curl->ogrSoy)	//eger ki ogrencilerin soyadlari esitse;
								if (currNode->ograd != curl->ograd)//ama adlari farkliysa
								{
									cout << fixed << setprecision(0) << currNode->numara << "\n" << currNode->ograd << "\n" << currNode->ogrSoy << "\n" << currNode->ogrBol << endl;//listede ki ogrenciyi
									cout << fixed << setprecision(0) << curl->numara << "\n" << curl->ograd << "\n" << curl->ogrSoy << "\n" << curl->ogrBol << endl;//yigindaki ogrenciyi yazdiralim ki soyadlarinin ayni adlarinin farkli oldugu gorunsun diye.
								}							
						}
						currNode = currNode->next;//listeyi ilerletiyoruz,bir sonraki dugume geciyoruz kontrol icin ve sonuna kadar tekrarliyoruz.
				}
				break;
		}
		case 16:
		{
			cout << "Kabarcik siralama algoritmasini kullanarak her iki dersi de alan ogrencileri adlarina gore sirala\n";
			Node* currNode = list.bas();//CurrNode,listenin basindan baslayacak bir dugum tanimladik.
			int i = 0;//i de�i�keni tan�ml�yoruz.
			int sayac = 0;
			int s = list.boyutdonder();
			int b = stack.boyutdonder();
			int N = (int)(s+b);				
			Node* a[1024];//node* t�r�nde dizi tan�ml�yoruz.50 lik tan�mlayal�m ki dolmas�n;
			while (currNode != NULL)//currNode bos olmadigi surece,sona gelmedi�i s�rece
			{
				if (list.nodonder(currNode->numara) == stack.nodonder(currNode->numara))//eger simdiki dugumun numarasi hem listede hem stack te mevcutsa her iki dersten de ders aliniyor demektir.
																						//no donder fonksiyonu ile numaraya ait olan dugum bulunup,eleman bulunup ozellikleri karsilastiriliyor esit mi diye degil mi diye.Esitse dugume ait olan bilgiler yazdiriliyor.
				{					
					a[i] = currNode;	//diziye �art� sa�layan d���m� at�yoruz.				
					i++;				//dizide bir sonrakine ge�i� yap�yoruz.	
				}
				sayac++;
				currNode = currNode->next;//bir sonraki dugume gecis yaptiriyoruz.					
			}					
			list.KabarcikSiralama(a, i);//kabacik siralamasi i�in fonksiyonu �a��r�yoruz.
			break;
		}
		case 17:
		{
			cout << "Radiks siralama algoritmasini kullanarak sadece Diferansiyel Denklemler dersini alan ogrencileri soyadlarina gore sirala\n";

			Node* currNode = list.bas();//baglantili listenin basindan baslamak icin basa esit olan bir dugum tanimladik.
			int i = 0;//i de�i�keni yazd�rma ve radix i�in.
			int num = 0;//numara de�i�keni boyut i�in tan�mland�.			
			string c[20];//fonksiyona d�nderilecek string t�r�nde dizimiz.			
			while (currNode != NULL)//dugum bos olmadigi surece yani sona gelmedigi surece
			{
				if (list.nodonder(currNode->numara) != stack.nodonder(currNode->numara))//nodonder fonksiyonu kullanarak ogrencilere ait bilgilere ulasiyoruz.Daha sonra
				{//yiginda bulunan numara listede bulunmuyorsa yani diferansiyel dersini aliyorsa yazdiriliyor.
					//b[i] = currNode;
					c[i] = currNode->ogrSoy;
					//d[i] = currNode->ogrSoy;
					num++;//num sayac�m�z� art�r�yoruz,boyut ve yazd�rma d�ng�s� i�in.
					i++;					
				}
				currNode = currNode->next;//dugum ilerletiyoruz.
			}
			
			
			list.lsd_string_radix(c,num, 2);//dizi,dizideki eleman say�s�,dizideki en k���k eleman�n karakter say�s�,en b�y�k yaz�l�nca hata ��kar�yor.
			//list.sort(c, 2);//Deneme
			for (int i = 0; i <num; i++)//Radix Sortla s�ralanm�� dizimiz d�n�yor.
			{
				Node* dugum = list.soydonder(c[i]);
				cout << dugum->numara << endl;
				cout << dugum->ograd << endl;
				cout << dugum->ogrSoy << endl;
				cout << dugum->ogrBol << endl;
				cout << "\n" << endl;

			}
			
			
			break;
		}
		case 18:
		{
			cout << "Araya sokma siralama algoritmasini kullanarak Veritabani dersini alanlari numaralarina gore sirala" << endl;
			Node* currNode = stack.bas();//currNode ba�tan ba�lat�l�r.
			int i = 0;		//i=0 de�i�keni atan�r.	
			int d[100];//int dizimiz tan�ml�ycaz araya sokma fonk.g�ndermek i�in.
			while (currNode != NULL)//currNode sona ula�mad��� s�rece.
			{
				d[i] = currNode->numara;//dizimize d���m�n numara bilgisi g�nderilir.
				i++;//i de�eri 1 art�r�l�r.
				currNode = currNode->next;//d���m bir ad�m ilerletilir.
			}
			stack.ArayaSokma(d, i);//en son araya sokma fonk. �a�r�l�r.Fonksiyonda sonu�lar yazd�r�l�r.
			break;//case biter,break diyerek switch yap�s� sonland�r�l�r.
		}

		case 19:
		{			
				cout << "Goodbye(Gule Gule!).\n";//Gule gule diyerek programi kapatiyoruz.
				return 0;//bunun icin return 0 kullandik;
				break;
		}

		default: {cout << selection << "is not a valid menu item(gecerli bir menu item degil!).\n";//gecerli bir case numarasi girilmezse hata gosteriyoruz.
			selection=NULL;
			cout << "Gecersiz secim, yeniden seciniz.\n";
			cin >> selection;
			cout << endl;
				 }
		}

	} while (selection != 0);//0 dan farkli oldugu surece program calismaya devam ediyor.
    return 0;
}

