//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TImage *BG;
        TEdit *Edit;
        TLabel *Label1;
        TLabel *MoneyLabel;
        TTimer *Timer1;
        TLabel *Zegar;
        TTimer *Timer2;
        TLabel *Kolor;
        TLabel *Wybrano;
        TButton *Koniec;
        TImage *Add2;
        TImage *Add10;
        TImage *Half;
        TImage *Random;
        TImage *Max;
        TImage *Clear;
        TImage *Czerwone;
        TImage *Zielone;
        TImage *Czarne;
        TImage *Image1;
        TImage *Image2;
        TImage *Image3;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Timer2Timer(TObject *Sender);
        void __fastcall KoniecClick(TObject *Sender);
        void __fastcall Add2Click(TObject *Sender);
        void __fastcall Add10Click(TObject *Sender);
        void __fastcall Image1Click(TObject *Sender);
        void __fastcall RandomClick(TObject *Sender);
        void __fastcall Image2Click(TObject *Sender);
        void __fastcall Image3Click(TObject *Sender);
        void __fastcall Image4Click(TObject *Sender);
        void __fastcall Image5Click(TObject *Sender);
        void __fastcall Image6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
