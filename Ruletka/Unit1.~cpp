//---------------------------------------------------------------------------
#include <time.h>
#include <cstdlib>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//moje zmienne
int czas, czasPocz = 20, r, licznik = 0, money = 1000, bet = 0, ile = 0;
String wylosowana, wybrana;
bool wylosowano = false, select = true;;

//moje funkcje
void Postaw(int ile)
{
if (ile<=money && ile>0)
        {
        money = money - ile;
        bet = ile;
        }
else
        bet = 0;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
srand (time(NULL));
MoneyLabel->Caption = IntToStr(money) +"z³";
wybrana = "null";
czas = czasPocz +1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//timer interpretuje wylosowana liczbê i przypisuje do niej kolor
if (wylosowano)
        {
        select = true;
        Timer1->Interval = 2500;
        Zegar->Caption = "Wylosowano: "+IntToStr(r);
        wylosowano = false;

        if (r == 0)
                {
                wylosowana = "zielone";
                }
        else if(r<=16)
                {
                 wylosowana = "czerwone";
                }
        else
                {
                wylosowana = "czarne";
                }

        //porównanie wylosowanego koloru z wybranym przez u¿ytkownika
        //przegrana
        if (wylosowana != wybrana && wybrana!="null")
                {
                Wybrano -> Caption = "Przegra³es: "+ IntToStr(bet) + "z³!";
                wybrana ="null";
                }
        //wygrana
        else if(wylosowana == wybrana && wybrana!="null")
                {
                //wygrana zielone
                if (r==0)
                        {
                        bet = bet *36;
                        }
                //wygrana czarne/czerwone
                else
                        {
                        bet = bet *2;
                        }
                money = money + bet;
                Wybrano ->Caption = "Wygrales: " + IntToStr(bet) + "z³!";
                MoneyLabel->Caption = IntToStr(money) +"z³";
                wybrana ="null";
                }
        else
                {
                Wybrano ->Caption = "Niczego nie postawi³es";
                }
        }

//timer odliczajacy czas do losowania
else
        {
        Timer1->Interval = 1000;
        czas--;
        Kolor->Color = clBtnFace;
        Zegar->Caption = "Losowanie za: "+IntToStr(czas)+"s";
        if(czas <=0)
                {
                Timer1->Enabled = false;
                czas = czasPocz;
                Timer2->Enabled = true;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
//timer odpowiadaj¹cy za losowanie
if(Timer2->Interval <=500 || licznik < 15)
        {
        select = false;
        
        r = rand()%36;
        Timer2->Interval += 10+ licznik;
        Zegar->Caption = "Trwa losowanie: "+ IntToStr(r);
        //zmiana kolorów t³a
        if (r == 0)
                {
                Kolor->Color = clGreen;
                }
        else if(r<=16)
                {
                Kolor->Color = clRed;
                }
        else
                {
                Kolor->Color = clBlack;
                }
        licznik++;
        }
//reset timera do ustawieñ pocz¹tkowych
else
        {
        licznik = 0;
        Timer2->Interval = 50;
        Timer2->Enabled = false;
        wylosowano = true;
        Timer1->Enabled = true;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::KoniecClick(TObject *Sender)
{
Close();        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Add2Click(TObject *Sender)
{
try{
int x = StrToInt(Edit->Text);
x += 2;
Edit -> Text = IntToStr(x);
MoneyLabel->Caption = IntToStr(money) +"z³";
}
catch(...)
{
Wybrano->Caption = "Z³y zapis";
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Add10Click(TObject *Sender)
{
try
{
int x = StrToInt(Edit->Text);
x += 10;
Edit -> Text = IntToStr(x);
MoneyLabel->Caption = IntToStr(money) +"z³";
}
catch(...)
{
Wybrano->Caption = "Z³y zapis";
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1Click(TObject *Sender)
{
try{
int x = StrToInt(Edit->Text);
x = x/2;
Edit -> Text = IntToStr(x);
MoneyLabel->Caption = IntToStr(money) +"z³";
}
catch(...)
{
Wybrano->Caption = "Z³y zapis";
}       
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RandomClick(TObject *Sender)
{
try
{
        Edit -> Text = 1+ rand()%money;
        MoneyLabel->Caption = IntToStr(money) +"z³";
}
catch(...)
        {
        Wybrano->Caption = "Z pustego nawet Salomon nie...";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image2Click(TObject *Sender)
{
Edit -> Text = IntToStr(money);
MoneyLabel->Caption = IntToStr(money) +"z³";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3Click(TObject *Sender)
{
Edit -> Text = "0";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Image4Click(TObject *Sender)
{
try
{
        if(select)
                {
                Postaw(StrToInt(Edit->Text));
                if(bet>0)
                        {
                        wybrana="czerwone";
                        MoneyLabel->Caption = IntToStr(money) +"z³";
                        Wybrano->Caption = "Postawiono: "+ IntToStr(bet) + "z³ na " +wybrana;
                        select = false;
                        }
                else
                        {
                        Wybrano->Caption = "Podano z³¹ ilosc pieniêdzy!";
                        MoneyLabel->Caption = IntToStr(money) +"z³";
                        }
                }
        }
catch(...)
        {
        Wybrano->Caption = "Z³y zapis";
        }

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image5Click(TObject *Sender)
{
try
{
        if(select)
                {
                Postaw(StrToInt(Edit->Text));
                if(bet>0)
                        {
                        wybrana="zielone";
                        MoneyLabel->Caption = IntToStr(money) +"z³";
                        Wybrano->Caption = "Postawiono: "+ IntToStr(bet) + "z³ na " +wybrana;
                        select = false;
                        }
                else
                        {
                        Wybrano->Caption = "Podano z³¹ ilosc pieniêdzy!";
                        MoneyLabel->Caption = IntToStr(money) +"z³";
                        }
                }
        }
catch(...)
        {
        Wybrano->Caption = "Z³y zapis";
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6Click(TObject *Sender)
{
try
{
        if(select)
                {
                Postaw(StrToInt(Edit->Text));
                if(bet>0)
                        {
                        wybrana="czarne";
                        MoneyLabel->Caption = IntToStr(money) +"z³";
                        Wybrano->Caption = "Postawiono: "+ IntToStr(bet) + "z³ na " +wybrana;
                        select = false;
                        }
                else
                        {
                        Wybrano->Caption = "Podano z³¹ ilosc pieniêdzy!";
                        MoneyLabel->Caption = IntToStr(money) +"z³";
                        }
                }
        }
catch(...)
        {
        Wybrano->Caption = "Z³y zapis";
        }

}
//---------------------------------------------------------------------------




