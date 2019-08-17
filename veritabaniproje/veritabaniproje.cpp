// veritabaniproje.cpp : Defines the entry point for the console application.
//

//oDEV 2
//ogrenci1 No:1030516163
//ogrenci1 Ýsmi ve Soyadi:HÜSEYÝN HÜRKAN KARAMAN
//ogrenci2 No:1030516153
//ogrenci2 Ýsmi ve Soyadi:ALÝ FURKAN GEZER
//ogrenci3 No:1030516177
//ogrenci3 Ýsmi ve Soyadi:SEMÝH CAN BOZOK
//ogrenci4 No:1030516296
//ogrenci4 Ýsmi ve Soyadi:EKREM KÜRSAD DAL
//DERS KODU:BZ205
//DOSYA ÝSMÝ:veritabaniproje


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

#define ARRAY_SIZE(array) (sizeof((array))/sizeof((array[0])))//Array boyutunu dönderen tanýmlama,array boyutunu öðrenmek için tanýmladýk,kullanýrsak diye.

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

	bool IsEmpty() { return head == NULL; }//eger boþsa head,baþ null a esittir.
	Node* InsertNode(int index, int no,string ad, string soyad, string bolum);//Dugum eklemek icin no,ad,soyad,bolum bilgilerini kullaniyoruz.
	int FindNode(int no);//Dugum bulmak icin findnode da numara aldik.
	int DeleteNode(int no);//Dugum silmek icin de deleteNode da int turunde tuttugumuz numarayi aldik.
	void DisplayList(void);//Listeyi yazdiran fonksiyon.
	Node* bas();//Listenin basini donduren fonksiyon ilerde kullanmak icin.
	int nodonder(int no);//Numara bilgisi girilen kisinin listede var oldugunu teyit edip,bulup numarasini donduruyor.
	Node* soydonder(string soy);//soyadi  girilen kisinin soyadina gore dugumu bulup dugumu donderiyor.
	int boyutdonder();	//boyun dönderen fonksiyon	*****************************************//YENÝ FONKSÝYON
	void KabarcikSiralama(Node* a[],int N);//Kabarcik siralamasi için kullanýlan fonksiyon.	****	//YENÝ FONKSÝYON
	void ArayaSokma(int c[], int n);//araya sokma sýralamasý için kullanýlan fonksiyon.		****	//YENÝ FONKSÝYON
	Node* noyadonder(int no);//numarasý girilen öðrencinin düðümünü dönderen fonksiyon.		****	//YENÝ FONKSÝYON
	void lsd_string_radix(string b[], int boyut, int maxkarakter);//stringte soyadlarý göderip sýraya dizen yani (Radiks Sort) yapan fonksiyonumuz.****	//YENÝ FONKSÝYON
	void sort(string a[], int W);//****//YENÝ FONKSÝYON	
private:
	Node* head;//Bas dugumumuz
	friend class Stack;//inherit yaptik
};
//Dugum ekleme
Node* List::InsertNode(int index,int no, string ad, string soyad, string bolum) {//fonksiyona,dýþarýdan ogrencinin indexini,adýný,soyadýný,bolum bilgilerini alýyoruz;  
	if (index < 0) return NULL;//eðer indeximiz sýfýra eþitse NULL deðer dönderiyoruz.

	int currIndex = 1;//ilk baþtan baþlamak için currIndex yani þimdiki Index'i 1 yapýyoruz.
	Node* currNode = head;//yeni düðüm tanýmlayýp bunu baþ düðüm yapýyoruz.
	while (currNode && index>currIndex) {//düðümümüz mevcut ve index'imiz þimdiki Index'ten büyük olduðu sürece
		currNode = currNode->next;//þimdiki düðümümüzün bir sonraki düðüme ait olan adresini ,düðümümüze atýyoruz yani düðüm ilerletiyoruz.
		currIndex++;//düðümüze ait currIndex deðerimizi de artýrýyoruz.
	}
	if (index > 0 && currNode == NULL) return NULL;//eðer index deðerimiz 0 dan büyük ve düðüm deðerimiz null'a eþitse sona gelmiþiz demektir o zaman NULL dönderiyoruz.

	Node* newNode = new Node;//yeni düðüm tanýmlýyoruz.
	
	newNode->numara = no;//yukarýda alýnan no'yu yeni düðümün numarasýna atýyoruz.
	newNode->ograd = ad;//yukarýda alýnan ad'ý yeni düðümün ad'ýna atýyoruz.
	newNode->ogrSoy = soyad;//yukarýda alýnan soyad'ý yeni düðümün soyad deðerine atýyoruz.
	newNode->ogrBol = bolum;//yukarýda alýnan bolum bilgisini yeni düðümün bolum kýsmýna atýyoruz.
	if (index == 0) {//eðer düðümümüz baþ düðümse,baþa eklenecekse;
		newNode->next = head;//head te bulunan adres bilgisi yeni düðümün adres kýsmýna atýlýr.
		head = newNode;//yeni düðümün adresi de head'e atýlýr.
	}
	else {
		newNode->next = currNode->next;//eðer düðüm ortaya ya da sona eklenecekse þimdiki düðümün adresi,eklenen düðüme atýlýr.
		currNode->next = newNode;//yeni düðümün adres bilgisi de þimdiki düðüme atanýr.
	}
	//cout << currNode->numara << "\n" << currNode->ograd << "\n" << currNode->ogrSoy << "\n" << currNode->ogrBol << "\n" << endl;
	cout << "Ekleme Basarili" << endl;//Ekleme baþarýlý ise Ekleme Baþarýlý mesajý çýkarýlýr.
	return newNode;//yeni düðüm fonksiyon tarafýndan döndürülür.
}

//Dugum bulma
int List::FindNode(int no) {//Düðüm bulmak için int türünde no deðiþkeni alýnýr.            
	Node* currNode = head;//Þimdiki düðüm baþ olarak tanýmlanýr.
	int currIndex = 1;//þimdiki düðümün index deðeri 1 olarak atanýr.
	while (currNode&&currNode->numara != no) {//þimdiki düðüm olduðu sürece ve þimdiki düðümün numarasý fonksiyonun aldýðý numara eþit olmadýðý sürece
		currNode = currNode->next;//düðümü bir ilerletip
		currIndex++;//index deðeri artýrýlýr taki currNode'un no deðeri fonksiyon a gönderilen no deðerine eþit olana kadar.
	}
	if (currNode)//eðer Düðümümüz bulunuyorsa yani varsa
	{
		cout << fixed << setprecision(0)<< currNode->numara << "\n" << currNode->ograd << "\n" << currNode->ogrSoy << "\n" << currNode->ogrBol << endl;//düðüme ait olan bilgiler yazdýrýlýr.
		return currIndex;//bulunan düðümümüzün index deðeri dönderilir.
	}
	return 0;//eðer düðümümüz yoksa 0 deðeri dönderilir.
}

//Dugum Silme
int List::DeleteNode(int no) {//silmek için no alýnýr.
	Node* prevNode = NULL;//önceki düðüm deðerni null;
	Node* currNode = head;//þimdiki düðüm deðeri baþ olarak atanýr.
	int currIndex = 1;//þimdiki düðümün index deðeri 1 olarak atanýr.
	while (currNode&&currNode->numara != no) {//þimdiki düðüm var olduðu sürece ve numarasý yukarýda alýnan no'ya eþit olmadýðý sürece;
		prevNode = currNode;//þimdiði düðüm önceki düðüme atanýr.
		currNode = currNode->next;//þimdiki düðümün bir sonraki düðümün adres bilgisi atanarak ilerletilir.
		currIndex++;//þimdiki düðümün index deðeri bir artýrýlýr.
	}
	if (currNode) {//eðer þimdiki düðümümüz mevcutsa
		if (prevNode) {//önceki düðüm varsa yani ortaya ya da sona ekliyceksek
			prevNode->next = currNode->next;//þimdiki düðümün adresi öncekini atanýr.
			delete currNode;//þimdiki düðüm silinir.
		}
		else {//baþtaysa
			head = currNode->next;//þimdiki düðümün adres bilgisi head'e atanýr.
			delete currNode;//þimdiki düðüm silinir.
		}
		return currIndex;//silinen düðümün index deðeri dönderilir.
	}
	return 0;//eðer iþlem baþarýlý olmazsa 0 dönderilir.
}


//Butun Elemanlari Yazdirma
void List::DisplayList()//listeyi yazdýrma fonksiyonu
{
	int num = 0;//düðüm sayýsýný, eleman sayýsýný saymak için numara tanýmlanýr int türünde;
	Node* currNode = head;//yeni düðüm tanýmlanýp head'e eþitlenir.
	while (currNode != NULL) //þimdiki düðüm sona ulaþmadýðý sürece
	{			
		cout << fixed<<setprecision(0)<< currNode->numara << endl;//Ogrencinin numarasi tam sayi seklinde yazdiriliyor.
		cout << currNode->ograd << endl;		//ogradý 
		cout << currNode->ogrSoy << endl;		//ogrSoyadý
		cout << currNode->ogrBol << endl;		//ogrBolum bilgisi yazdýrýlýr.
		cout << "\n" << endl;
		
		currNode = currNode->next;		//düðümü bir adým ilerletilir.
		num++;		//numara yani düðüm,eleman sayýsý 1 artýrýlýr.
	}
	
	cout<<"Number of nodes in the list(Listedeki bulunan itemlerin sayisi): "<<  num << endl;
}

//Listeyi yoketme
List::~List(void) {
	Node* currNode = head, *nextNode = NULL;//þimdiki düðüm baþ olarak tanýmlanýr.bir sonraki düðüm null olarak tanýmlanýr.
	while (currNode != NULL)//þimdiki düðüm sona gelmediði sürece
	{
		nextNode = currNode->next;//þimdiki düðümün adres bilgisi nextNode dediðimiz düðüme atanýr.
		//destroy the current node//simdiki nodu yok ettik.
		delete currNode;//düðüm silinir;
		currNode = nextNode;//nextNode da artýk þimdiki düðüm olarak atanýr böylece liste yok olana kadar silme gerçekleþecektir.
	}
}

//Listenin headini donderen fonksiyon
Node* List::bas()
{
	return head;//basi donder;
}
//Numara Donduren Fonksiyon
int List::nodonder(int no)//numara donderme fonksiyonu için int türünde numara deðiþkeni alýnýr.
{
	Node* currNode = head;//þimdiki düðüm baþ olarak tanýmlanýr.
	int currIndex = 1;//þimdiki düðümün index deðeri 1 olarak belirlenir.
	while (currNode&&currNode->numara != no) {//alinan numara,dugumlerde bulunana kadar araniyor boylece dugum bulunup butun bilgiler donderilebilinir.
		currNode = currNode->next;//þimdiki düðümün numara deðeri yukarýda gelen no ya eþit olana kadar düðüm atlanýr.
		currIndex++;//index deðeri artýrýlýr.
	}
	if (currNode)//eðer þimdiki düðüm mevcutsa
	{		
		return currNode->numara;//Biz burada sadece numaraya ihtiyac duyduk.//numara deðeri dönderilir.
	}
	return 0;//eðer düðüm yoksa return 0;
}
//Girilen soyada gore dugum donduren fonksiyon
Node* List::soydonder(string soy) {//girilen soyada göre listede ya da yýðýnda bulunan node'u yani düðümü dönderir.Böylece bütün bilgilerine eriþebiliriz.
	Node* currNode = head;//þimdiki düðüm baþ olarak tanýmlanýr.
	int currIndex = 1;//index deðeri 1 olarak belirlenir.
	while (currNode&&currNode->ogrSoy !=soy) {//yukaridan alinan soyadi bilgisi listedeki dugumde bulunan soyadina esit olmadigi surece dugum atliyoruz ta ki bulana kadar.
		currNode = currNode->next;//yukarýda alýnan soyada þimdiki düðümümüzün soyad deðeri eþit olana kadar düðüm ilerletilir
		currIndex++;//index deðeri artýrýlýr eþit olunca çýkýlýr.
	}
	if (currNode->ogrSoy==soy)//alinan soyad bulunana esitse dugumu donduruyor.
	{		
		return currNode;//dugum donduruluyor boylece o ogrencinin numarasindan bolumune kadar bilgilerine erisim saglanabilir.
	}
	return NULL;//eðer düðüm bulunmadýysa return NULL yaptýk.


}

int List::boyutdonder()
{
	int num = 0;//düðüm sayýsýný, eleman sayýsýný saymak için numara tanýmlanýr int türünde;
	Node* currNode = head;//yeni düðüm tanýmlanýp head'e eþitlenir.
	while (currNode != NULL) //þimdiki düðüm sona ulaþmadýðý sürece
	{
	
		currNode = currNode->next;		//düðümü bir adým ilerletilir.
		num++;		//numara yani düðüm,eleman sayýsý 1 artýrýlýr.
	}

	return num;

}

void List::KabarcikSiralama(Node* a[], int N)
{
	Node* geçici;//geçici temp düðümü tanýmladýk.
	int k, hareket;//k ve hareket dediðimiz deðiþkenlerimizi döngü için tanýmladýk.
	for (hareket = 0; hareket < N - 1; hareket++)//hareket deðiþkenini kullanarak,ana for döngümüzü tanýmladýk.
	{
		for (k = 0; k < N - 1 - hareket; k++)//k deðiþkenini her bir adý karþýlaþtýrmak için for döngüsünde kullandýk.
		{
			if (a[k]->ograd > a[k + 1]->ograd)//düðümün adý,bir sonraki düðümün adýndan büyükse
			{
				geçici = a[k];//swap iþlemi yapýcaz bunun için,a[k] deðerini geçici bir düðüme atýyoruz.
				a[k] = a[k + 1];//a[k+1] de bulunan deðeri,a[k] atýyoruz.
				a[k + 1] = geçici;//geçici düðümde bulunan deðeri a[k+1]'e atýyoruz.Bu þekilde takas iþlemini tamamlamýþ oluyoruz.
			}//Sonuçta bubble sort'un can alýcý kýsmýný yukardaki if in iç kýsmýnda gerçekleþtirmiþ oluyoruz.
		}
	}
	for (int i = 0; i < N; i++)//yazdýrma döngüsü
	{
		cout << a[i]->numara << endl;//düðüme ait olan,numara,ad,soyad,bolum bilgilerini yazdýrýyoruz.
		cout << a[i]->ograd << endl;
		cout << a[i]->ogrSoy << endl;
		cout << a[i]->ogrBol << endl;
		cout << "\n" << endl;

	}	
	
}

Node* List::noyadonder(int no)//Numarasý girilen öðrenci için düðüm dönderen fonksiyon.
{
	Node* currNode = head;//þimdiki düðüm baþ olarak tanýmlanýr.
	int currIndex = 1;//þimdiki düðümün index deðeri 1 olarak belirlenir.
	while (currNode&&currNode->numara != no) {//alinan numara,dugumlerde bulunana kadar araniyor boylece dugum bulunup butun bilgiler donderilebilinir.
		currNode = currNode->next;//þimdiki düðümün numara deðeri yukarýda gelen no ya eþit olana kadar düðüm atlanýr.
		currIndex++;//index deðeri artýrýlýr.
	}
	if (currNode)//eðer þimdiki düðüm mevcutsa
	{
		return currNode;//Biz burada düðüm dönderdik.
	}
	return 0;//eðer düðüm yoksa return 0;

}

//ARAYA SOKMA(INSERTION) ÝÇÝN

void List::ArayaSokma(int c[], int n)
{
	int  k;//k ve ekle olmak üzere 2 deðiþken belirlenir.	
	int ekle;//ekle deðiþkeni tanýmlanýr.
	
	for (int i = 1; i < n; i++)//araya sokma için ilk for döngüsü
	{
		ekle = c[i];//c nin ilk elemaný ekle deðiþkenine atanýr.
		for (k = (i - 1);( k >= 0) && (ekle <= c[k]); k--)//ikinci for döngüsü
			c[k + 1] = c[k];//asýl sýraya koyma burada gerçekleþir.c nin k. indisindeki deðeri,k+1 e atanýr.
		c[k + 1] = ekle;//ekle de bulunan eleman c nin k+1 inci indeksine atanýr.
	}
	
	for (int z = 0; z < n; z++)//yazdýrma döngüsü
	{
		Node* dugum = noyadonder(c[z]);//numarasý girilen ogrencinin düðümü çaðrýlarak diðer bilgilere ulaþýlýr.
		cout << dugum->numara << endl;//bilgiler yazdýrýlýr.
		cout << dugum->ograd << endl;
		cout << dugum->ogrSoy << endl;
		cout << dugum->ogrBol << endl;
		cout << "\n" << endl;

	}
}



void List::lsd_string_radix(string b[], int boyut, int maxkarakter)
{
	string *temp = new string[boyut];//temp dediðimiz dinamik dizi oluþturuyoruz pointer sayesinde;
	

	for (int i = maxkarakter - 1; i >= 0; i--)//ana for döngümüz.maksimum karakter sayýsýndan baþlayarak azalarak döngü devam ediyor.
	{
		
		int count[27] = { 0 };//ingiliz alfabesi temel alýndýðýndan count 27 olmalý.

		for (int j = 0; j < boyut; j++)//içerde bulunan 1.for döngüsü
			count[static_cast<int>(b[j][i]) - 96]++;//static cast int sayesinde asci den int e çevriliyor.ve sayaç 1 artýrýlýyor.

		for (int j = 2; j < 26; j++)//geri kalanlar arasýnda 2 den 26 ya kadar,count dizisinde j inci terim e j-1 inci terimler toplanýyor.
			count[j] += count[j - 1];
		
		for (int j = 0; j < boyut; j++)//tekrardan sayaçta asciden int a dönüþüm yapýlýyor.
			temp[count[static_cast<int>(b[j][i]) - 97]++] = b[j];//temp dizisinde saklanýyor bu sefer.
		
		for (int j = 0; j < boyut; j++)//temp dizisinde bulunan string deðiþkenler sýralanmýþ olarak tekrardan fonksiyona gelen b dizisine atanýyor.
			b[j] = temp[j];//tekrar atanma,sýralanmýþ bir þekilde.
		
	}


}

//BAgLANTILI LÝSTE TABANLI GERcEKLEsTÝRME YIgIN(TEMEL ÝsLEMLER + EK FONKSÝYONLAR)
class Stack :public List {
public:
	Stack(){}//constructor
	~Stack(){}//destructor
	int Top() {
		if (head == NULL) {//eðer baþ null a eþitse yýðýn boþ demektir.
			cout << "Error: the stack is empty" << endl;
			return -1;
		}
		else
		{
			cout << fixed << setprecision(0) << head->numara << "\n" << head->ograd << "\n" << head->ogrSoy << "\n" << head->ogrBol << endl;
			return head->numara;//eðer yýðýn varsa o zaman baþýn yani yýðýnýn en üstünde bulunan elemanýn ,düðümün numarasý dönderilir.
		}
			
	}//stack te Top fonksiyonu
	void Push(const int x, int no, string ad, string soyad, string bolum) {InsertNode(0,no,ad,soyad,bolum); }//stacke ogrenci eklememizi eleman eklememize yarayan fonksiyon.Temel liste fonk.kullaniliyor.
	int Pop() {
		if (head == NULL) {//eðer yýðýn boþ ise return -1;
			cout << "Error: the stack is empty." << endl;//hata mesajý gösterilir.
			return -1;
		}
		else {
			int val = head->numara;//yýðýn boþ deðilse,yýðýnýn en üstünde bulunan düðümün
			string ad = head->ograd;//head'in deðerleri ad,soyad ve bolum bilgileri deðiþkenlere atanýr.
			string soyad = head->ogrSoy;
			string bolum = head->ogrBol;
			cout << val << "\n" << ad << "\n" << soyad << "\n" << bolum << endl;//deðiþkenlerin deðerleri atanýr.
			DeleteNode(val);//yazdýrýlan düðümün bilgileri yazdýrýlýp düðüm silinmek için düðüm silme metodu çaðrýlýr.
			return val;//düðüm dönderilir.
		}
	}//stack te ustte bulunan elemani siliyoruz.stackte silme yapmamiza yariyan fonksiyon.
	void DisplayStack() { DisplayList(); }//yigini yazdirma
	Node* headgetir() {
		if (head == NULL) {//eðer stack boþsa hata mesajý gösterilir.
			cout << "Error: the stack is empty" << endl;
			return NULL;
		}
		else
		{			
			return head;//eðer yýðýn boþ deðilse o zaman yýðýnýn baþ düðümü dönderilir.
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
		//////////////BAgLANTILI LÝSTE ÝSLEMLERÝ
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
		//////////////YIGIN ÝSLEMLERÝ
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
		////////////////OTOMATÝK SINIF LÝSTESÝ OLUsTUMA//////////////
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
				while (currNode != NULL)//currNode bos olmadigi surece,sona gelmediði sürece
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
					while (currNode != NULL)//dugum bos olmadigi surece,sona gelmediði sürece
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
				Node* currrNode = stack.headgetir();///*****3 R LÝ NODE var DÝKKAT!!!!!///////////stack'in basina esit olan bir dugum tanimladik.
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
			int i = 0;//i deðiþkeni tanýmlýyoruz.
			int sayac = 0;
			int s = list.boyutdonder();
			int b = stack.boyutdonder();
			int N = (int)(s+b);				
			Node* a[1024];//node* türünde dizi tanýmlýyoruz.50 lik tanýmlayalým ki dolmasýn;
			while (currNode != NULL)//currNode bos olmadigi surece,sona gelmediði sürece
			{
				if (list.nodonder(currNode->numara) == stack.nodonder(currNode->numara))//eger simdiki dugumun numarasi hem listede hem stack te mevcutsa her iki dersten de ders aliniyor demektir.
																						//no donder fonksiyonu ile numaraya ait olan dugum bulunup,eleman bulunup ozellikleri karsilastiriliyor esit mi diye degil mi diye.Esitse dugume ait olan bilgiler yazdiriliyor.
				{					
					a[i] = currNode;	//diziye þartý saðlayan düðümü atýyoruz.				
					i++;				//dizide bir sonrakine geçiþ yapýyoruz.	
				}
				sayac++;
				currNode = currNode->next;//bir sonraki dugume gecis yaptiriyoruz.					
			}					
			list.KabarcikSiralama(a, i);//kabacik siralamasi için fonksiyonu çaðýrýyoruz.
			break;
		}
		case 17:
		{
			cout << "Radiks siralama algoritmasini kullanarak sadece Diferansiyel Denklemler dersini alan ogrencileri soyadlarina gore sirala\n";

			Node* currNode = list.bas();//baglantili listenin basindan baslamak icin basa esit olan bir dugum tanimladik.
			int i = 0;//i deðiþkeni yazdýrma ve radix için.
			int num = 0;//numara deðiþkeni boyut için tanýmlandý.			
			string c[20];//fonksiyona dönderilecek string türünde dizimiz.			
			while (currNode != NULL)//dugum bos olmadigi surece yani sona gelmedigi surece
			{
				if (list.nodonder(currNode->numara) != stack.nodonder(currNode->numara))//nodonder fonksiyonu kullanarak ogrencilere ait bilgilere ulasiyoruz.Daha sonra
				{//yiginda bulunan numara listede bulunmuyorsa yani diferansiyel dersini aliyorsa yazdiriliyor.
					//b[i] = currNode;
					c[i] = currNode->ogrSoy;
					//d[i] = currNode->ogrSoy;
					num++;//num sayacýmýzý artýrýyoruz,boyut ve yazdýrma döngüsü için.
					i++;					
				}
				currNode = currNode->next;//dugum ilerletiyoruz.
			}
			
			
			list.lsd_string_radix(c,num, 2);//dizi,dizideki eleman sayýsý,dizideki en küçük elemanýn karakter sayýsý,en büyük yazýlýnca hata çýkarýyor.
			//list.sort(c, 2);//Deneme
			for (int i = 0; i <num; i++)//Radix Sortla sýralanmýþ dizimiz dönüyor.
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
			Node* currNode = stack.bas();//currNode baþtan baþlatýlýr.
			int i = 0;		//i=0 deðiþkeni atanýr.	
			int d[100];//int dizimiz tanýmlýycaz araya sokma fonk.göndermek için.
			while (currNode != NULL)//currNode sona ulaþmadýðý sürece.
			{
				d[i] = currNode->numara;//dizimize düðümün numara bilgisi gönderilir.
				i++;//i deðeri 1 artýrýlýr.
				currNode = currNode->next;//düðüm bir adým ilerletilir.
			}
			stack.ArayaSokma(d, i);//en son araya sokma fonk. çaðrýlýr.Fonksiyonda sonuçlar yazdýrýlýr.
			break;//case biter,break diyerek switch yapýsý sonlandýrýlýr.
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

