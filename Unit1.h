//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <fstream.h>
#include <string>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TTimer *timer_pilka;
        TShape *tlo;
        TImage *ball;
        TImage *paletka1;
        TTimer *top_paletka1;
        TTimer *down_paletka1;
        TButton *Button1;
        TImage *paletka2;
        TTimer *top_paletka2;
        TTimer *down_paletka2;
        TLabel *Label1;
        TLabel *Label2;
        TButton *Button2;
        TLabel *Label3;
        TButton *Button3;
        void __fastcall timer_pilkaTimer(TObject *Sender);
        void __fastcall top_paletka1Timer(TObject *Sender);
        void __fastcall down_paletka1Timer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall top_paletka2Timer(TObject *Sender);
        void __fastcall down_paletka2Timer(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
