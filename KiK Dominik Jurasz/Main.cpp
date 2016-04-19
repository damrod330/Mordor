//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <cstdlib>
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int tura;                // 1 = kólko, 2 = krzy¿yk
int tablica_P[9];        // pola do gry
int wynik_Krzyzyka= 0, wynik_Kolka;  //zmienna zliczajaca pkt
String runda = "Trwa";               //zmienna okreslajaca stan gry

void sprawdz()          //funkcja sprawdzaj¹ca warunek wygranej
{
        if (tablica_P[0] == 1 &&tablica_P[1] == 1 &&tablica_P[2] == 1 ||
            tablica_P[3] == 1 &&tablica_P[4] == 1 &&tablica_P[5] == 1 ||
            tablica_P[6] == 1 &&tablica_P[7] == 1 &&tablica_P[8] == 1 ||
            tablica_P[0] == 1 &&tablica_P[3] == 1 &&tablica_P[6] == 1 ||
            tablica_P[1] == 1 &&tablica_P[4] == 1 &&tablica_P[7] == 1 ||
            tablica_P[2] == 1 &&tablica_P[5] == 1 &&tablica_P[8] == 1 ||
            tablica_P[0] == 1 &&tablica_P[4] == 1 &&tablica_P[8] == 1 ||
            tablica_P[6] == 1 &&tablica_P[4] == 1 &&tablica_P[2] == 1 )
        {
             char * wygrana = "Wygra³o kó³ko!";
             Application->MessageBox(wygrana, "Runda", MB_OK ) ;
             wynik_Kolka++;
             runda="Koniec";

                if (wynik_Kolka== 3 || wynik_Krzyzyka== 3 )     //warunek koñca gry, gra toczy siê do 3 wygranych
        {

                Application->MessageBox("Koniec Gry!", "Runda", MB_OK ) ;
                runda = "Koniec Gry!";
        }


        }
        else if(tablica_P[0] == 2 &&tablica_P[1] == 2 &&tablica_P[2] == 2 ||
            tablica_P[3] == 2 &&tablica_P[4] == 2 &&tablica_P[5] == 2 ||
            tablica_P[6] == 2 &&tablica_P[7] == 2 &&tablica_P[8] == 2 ||
            tablica_P[0] == 2 &&tablica_P[3] == 2 &&tablica_P[6] == 2 ||
            tablica_P[1] == 2 &&tablica_P[4] == 2 &&tablica_P[7] == 2 ||
            tablica_P[2] == 2 &&tablica_P[5] == 2 &&tablica_P[8] == 2 ||
            tablica_P[0] == 2 &&tablica_P[4] == 2 &&tablica_P[8] == 2 ||
            tablica_P[6] == 2 &&tablica_P[4] == 2 &&tablica_P[2] == 2 )
        {
             char * wygrana = "Wygra³ krzy¿yk!";
             Application->MessageBox(wygrana,"Runda", MB_OK );
             wynik_Krzyzyka++;
             runda="Koniec";

                if (wynik_Kolka== 3 || wynik_Krzyzyka== 3 )
        {

                Application->MessageBox("Koniec Gry!", "Runda", MB_OK ) ;
                runda ="Koniec Gry!";
        }
        }

}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        srand( time( NULL ) );
       for(int i = 0; i<9; i++)              //petla wypelniaj¹ca pola wartoscia startowa '0'
        {
             tablica_P[i] = 0;
        }
        tura = ( std::rand() % 2 ) + 1;      //losowanie kto zaczyna (kó³ko/krzy¿yk)
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image2Click(TObject *Sender)
{
        if (tablica_P[0]==0)                 //warunek, ktory sprawdza czy dane pole jest puste w momencie klikniêcia. Jestli tak
        {                                    // to jest do niego zapisywana odpowiednia wartosc w zaleznosci od tury gracza, po czym
                if (tura == 1 )              // tura jest zmieniana na przeciwn¹ np.by³o kó³ko to jest teraz krzy¿yk
                {
                        Label2->Visible = false;
                        Image2->Picture->LoadFromFile("obrazki/kolko.bmp");
                        tura = 2;
                        tablica_P[0] = 1;
                }
                else
                {
                        Label2->Visible = false;
                        Image2->Picture->LoadFromFile("obrazki/Krzyzyk.bmp");
                        tura = 1;
                        tablica_P[0] = 2;
                }
                sprawdz();
        }
        else
        {       Label2->Visible = true;
                Label2->Caption = "To pole jest ju¿ zajête!";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image3Click(TObject *Sender)
{
        if (tablica_P[1]==0 )
        {
                if (tura == 1 )
                {
                        Label2->Visible = false;
                        Image3->Picture->LoadFromFile("obrazki/kolko.bmp");
                        tura = 2;
                        tablica_P[1] = 1;
                }
                else
                {
                        Label2->Visible = false;
                        Image3->Picture->LoadFromFile("obrazki/Krzyzyk.bmp");
                        tura = 1;
                        tablica_P[1] = 2;
                }
                sprawdz();
        }
        else
        {       Label2->Visible = true;
                Label2->Caption = "To pole jest ju¿ zajête!";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image4Click(TObject *Sender)
{
        if (tablica_P[2]==0)
        {
                if (tura == 1 )
                {
                        Label2->Visible = false;
                        Image4->Picture->LoadFromFile("obrazki/kolko.bmp");
                        tura = 2;
                        tablica_P[2] = 1;
                }
                else
                {
                        Label2->Visible = false;
                        Image4->Picture->LoadFromFile("obrazki/Krzyzyk.bmp");
                        tura = 1;
                        tablica_P[2] = 2;
                }
                 sprawdz();
        }
        else
        {       Label2->Visible = true;
                Label2->Caption = "To pole jest ju¿ zajête!";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image5Click(TObject *Sender)
{
        if (tablica_P[3]==0)
        {
                if (tura == 1 )
                {
                        Label2->Visible = false;
                        Image5->Picture->LoadFromFile("obrazki/kolko.bmp");
                        tura = 2;
                        tablica_P[3] = 1;
                }
                else
                {
                        Label2->Visible = false;
                        Image5->Picture->LoadFromFile("obrazki/Krzyzyk.bmp");
                        tura = 1;
                        tablica_P[3] = 2;
                }
                 sprawdz();
        }
        else
        {       Label2->Visible = true;
                Label2->Caption = "To pole jest ju¿ zajête!";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image6Click(TObject *Sender)
{
        if (tablica_P[4]==0)
        {
                if (tura == 1 )
                {
                        Label2->Visible = false;
                        Image6->Picture->LoadFromFile("obrazki/kolko.bmp");
                        tura = 2;
                        tablica_P[4] = 1;
                }
                else
                {
                        Label2->Visible = false;
                        Image6->Picture->LoadFromFile("obrazki/Krzyzyk.bmp");
                        tura = 1;
                        tablica_P[4] = 2;
                }
                 sprawdz();
        }
        else
        {       Label2->Visible = true;
                Label2->Caption = "To pole jest ju¿ zajête!";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image7Click(TObject *Sender)
{
        if (tablica_P[5]==0)
        {
                if (tura == 1 )
                {
                        Label2->Visible = false;
                        Image7->Picture->LoadFromFile("obrazki/kolko.bmp");
                        tura = 2;
                        tablica_P[5] = 1;
                }
                else
                {
                        Label2->Visible = false;
                        Image7->Picture->LoadFromFile("obrazki/Krzyzyk.bmp");
                        tura = 1;
                        tablica_P[5] = 2;
                }
                 sprawdz();
        }
        else
        {       Label2->Visible = true;
                Label2->Caption = "To pole jest ju¿ zajête!";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image8Click(TObject *Sender)
{
        if (tablica_P[6]==0)
        {
                if (tura == 1 )
                {
                        Label2->Visible = false;
                        Image8->Picture->LoadFromFile("obrazki/kolko.bmp");
                        tura = 2;
                        tablica_P[6] = 1;
                }
                else
                {
                        Label2->Visible = false;
                        Image8->Picture->LoadFromFile("obrazki/Krzyzyk.bmp");
                        tura = 1;
                        tablica_P[6] = 2;
                }
                 sprawdz();
        }
        else
        {       Label2->Visible = true;
                Label2->Caption = "To pole jest ju¿ zajête!";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image9Click(TObject *Sender)
{
         if (tablica_P[7]==0)
        {
                if (tura == 1 )
                {
                        Label2->Visible = false;
                        Image9->Picture->LoadFromFile("obrazki/kolko.bmp");
                        tura = 2;
                        tablica_P[7] = 1;
                }
                else
                {
                        Label2->Visible = false;
                        Image9->Picture->LoadFromFile("obrazki/Krzyzyk.bmp");
                        tura = 1;
                        tablica_P[7] = 2;
                }
                 sprawdz();
        }
        else
        {       Label2->Visible = true;
                Label2->Caption = "To pole jest ju¿ zajête!";
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image10Click(TObject *Sender)
{
        if (tablica_P[8]==0)
        {
                if (tura == 1 )
                {
                        Label2->Visible = false;
                        Image10->Picture->LoadFromFile("obrazki/kolko.bmp");
                        tura = 2;
                        tablica_P[8] = 1;
                }
                else
                {
                        Label2->Visible = false;
                        Image10->Picture->LoadFromFile("obrazki/Krzyzyk.bmp");
                        tura = 1;
                        tablica_P[8] = 2;
                }
                 sprawdz();
        }
        else
        {       Label2->Visible = true;
                Label2->Caption = "To pole jest ju¿ zajête!";
        }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        if (runda == "Koniec")                       //Timer sprawdza stan rundy, jesli sie zakonczyla to resetuje plansze
        {
                SpeedButton2->Click();
                runda = "Trwa";
        }
        if (runda == "Koniec Gry!")
        {
                Close();
        }
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
       Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton2Click(TObject *Sender)
{
        Image2->Picture = NULL;               //button do resetowania w momencie, gdy wyst¹pi remis, b¹dŸ gracze chca zacz¹c runde od nowa
        Image3->Picture = NULL;
        Image4->Picture = NULL;
        Image5->Picture = NULL;
        Image6->Picture = NULL;
        Image7->Picture = NULL;
        Image8->Picture = NULL;
        Image9->Picture = NULL;
        Image10->Picture = NULL;

        for(int i = 0; i<9; i++)
        {
             tablica_P[i] = 0;
        }

        Label1->Caption = IntToStr(wynik_Kolka);
        Label3->Caption = IntToStr(wynik_Krzyzyka);
}
//---------------------------------------------------------------------------

