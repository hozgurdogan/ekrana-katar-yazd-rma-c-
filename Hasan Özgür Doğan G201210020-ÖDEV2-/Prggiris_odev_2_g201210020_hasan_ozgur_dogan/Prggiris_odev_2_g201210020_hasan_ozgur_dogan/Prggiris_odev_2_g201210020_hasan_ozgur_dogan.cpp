/**************************
**	SAKARYA UNIVERSITY
**	BILGISAYAR MUHENDISLIGI BOLUMU
**	PROGRAMLAMAYA GIRIS
**
**	ÖÐRENCÝ ADI......:Hasan Ozgur Dogan
**	ÖÐRENCÝ NUMARASI.:G201210020
**	DERS GRUBU…………………:B gurubu 2.ögretim
**************************/




#include <iostream>
#include <windows.h>
#include <winnt.h>
#include <stdio.h>
#include <time.h>
using namespace std;

using namespace std;

enum RENKLER //enum olarak renkler tanimlaniyor...
{
	LIGHTBLUE = 9,
	LIGHTGREEN = 10,
	LIGHTCYAN = 11,
	LIGHTRED = 12,
	LIGHTMAGENTA = 13,
	YELLOW = 14,

};


class Karakter {

public://karakterlerin Ozelikleri tanimlaniyor....
	char harf;
	int renk;

};
class Katar //katar calssi tanimliyoruz...
{

public:
	char	DUZCIZGI = 205;
	char	SOLUSTKOSE = 201;
	char	SAGUSTKOSE = 187;
	char	DIKEYCIZGI = 186;
	char	ASAGIAYRAC = 203;
	char	SOLALTKOSE = 200;
	char	SAGALTKOSE = 188;
	char	YUKARIAYRAC = 202;


	int karaktersayisi;


	Katar()//kurucu fonkisyon olaraktan karakter saiyisini 0 yapiyoruz....
	{

		karaktersayisi = 0;

	}
	void karakterEkle()//kulanici 1 bastigi zaman kakrater ekle metod blogu devreye giriyor...
	{





		if (karaktersayisi < 50)//max karakter sayisi 50 oldugundan 50 uzeri eklemelerde bu bologa giremez ve karater ekleme olayi gerceklesemez...
		{
			karakterler[karaktersayisi].harf = (char)(rand() % 26 + 65); // ascII tablosu yarrdimi ile nesneler dizisinin harf uzantisina o anki karakter saiyisna denk gelen indisine rast gele A-Z arasi harf atiyoruz...
			karakterler[karaktersayisi].renk = rand() % 6 + 9; //her harfe belirtilen renkler arasindan 

			karaktersayisi = karaktersayisi + 1; //her karakter ekle secenegi icin karakter saiyisini 1 artiyor.


		}


	}

	void karakterCikar()
	{

		if (karaktersayisi == 0)
		{
			//cout << "CIKARMA ISLEMI YAPILAMZ...";

		}
		else
		{
			karakterler[karaktersayisi].harf = '\0';
			karakterler[karaktersayisi].renk = rand() % 6 + 9;
			karaktersayisi--;
		}







	}

	void yazdir() //ekrana yazdýrma metodu ...
	{

		if (karaktersayisi == 0)
		{

			cout << endl << SOLUSTKOSE << DUZCIZGI << SAGUSTKOSE << endl; cout << DIKEYCIZGI << " " << DIKEYCIZGI << endl;
			cout << SOLALTKOSE << DUZCIZGI << SAGALTKOSE << endl;

		}


		else
		{



			if (karaktersayisi <= 50)   //bu blok sadece karakter sayisi 50ey ve 50nin altinda oldugunda aktiflesiyor.
			{
				if (karaktersayisi == 1)	//ilk kutunun sol ust koseye sahip olmasýndan kaynaklý ozel bi durum iceriyor..
				{

					cout << SOLUSTKOSE << DUZCIZGI << DUZCIZGI << SAGUSTKOSE << endl;
					cout << DIKEYCIZGI;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), karakterler[0].renk);
					cout << karakterler[0].harf;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
					cout << " " << DIKEYCIZGI << endl;
					cout << SOLALTKOSE << DUZCIZGI << DUZCIZGI << SAGALTKOSE;
				}

				else if (karaktersayisi != 1)
				{

					cout << SOLUSTKOSE << DUZCIZGI << DUZCIZGI;
					for (int i = 0; i < karaktersayisi - 1; i++)
					{
						cout << ASAGIAYRAC << DUZCIZGI << DUZCIZGI;
					}

					cout << SAGUSTKOSE << endl;

					if (karaktersayisi != 1)
					{

						for (int k = 0; k < karaktersayisi; k++)
						{
							cout << DIKEYCIZGI;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), karakterler[k].renk);

							cout << karakterler[k].harf;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
							cout << " ";
						}




					}

					cout << DIKEYCIZGI << endl;
					cout << SOLALTKOSE << DUZCIZGI << DUZCIZGI;

					for (int q = 0; q < karaktersayisi - 1; q++)
					{
						cout << YUKARIAYRAC << DUZCIZGI << DUZCIZGI;
					}


					cout << SAGALTKOSE;





				}



			}



			else
			{
				cout << endl << "EKLEME YAPILAMAZ..." << endl;

			}


		}

	}



private:


	Karakter karakterler[50];
};

int main()
{




	srand(time(0));

	Katar ktr1;
	Karakter karkter1;

	string secim = "0";
	do//menü iþlemleri.... // cikis icin 3 basilan menu görevi goren bi do while döngüsü....
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << endl << "Eklemek icin 1'e basiniz:" << endl
			<< "Cikarmak icin 2 'ye basiniz: " << endl
			<< "Cikiss yapmak icin 3 'e basiniz:";
		cin >> secim;
		if (secim == "1" && ktr1.karaktersayisi == 50)	//kakrater saiyisi 50 olunca ve hala karater eklenmek istendiginde bu bloga girip ekleme islemþ yapilmamsini sagliyor.
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

			cout << "EKLEME YAPILAMAZ..." << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		}
		else if (secim == "1")//  bu secenek karater eklenmesini sagliyor
		{
			cout << endl << "ONCEKI DURUM eleman sayisi:" << ktr1.karaktersayisi << endl;

			ktr1.yazdir();
			ktr1.karakterEkle();
			cout << endl << "SONRAKI DURUM eleman sayisi:" << ktr1.karaktersayisi << endl;
			ktr1.yazdir();

		}
		else if (secim == "2")	//karakter cikarmak islemleri...
		{
			if (ktr1.karaktersayisi > 0)
			{
				cout << endl << "ONCEKI DURUM eleman sayisi:" << ktr1.karaktersayisi << endl;
				ktr1.yazdir();
				ktr1.karakterCikar();
				cout << endl << "SONRAKI DURUM eleman sayisi:" << ktr1.karaktersayisi << endl;
				ktr1.yazdir();
			}
			else //karater sayisi sýfýrdan kucuk olmasi durumunu onlemek amaciyla acilmis bi else blogu
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				cout << endl << "CIKARMA YAPILAMAZ..." << endl;
			}
		}

	} while (secim != "3");



}