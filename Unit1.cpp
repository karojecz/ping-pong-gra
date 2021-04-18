//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=-8;
int y=-8;
int ilosc_odbic=0;
int wygrana_prawego =0;
int wygrana_lewego=0;
AnsiString punktyLewego, odbicia;
AnsiString punktyPrawego;


//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm1::timer_pilkaTimer(TObject *Sender)
{

        ball ->Left +=x;
        ball -> Top +=y;

        //odbicie od gornej sciany
        if(ball->Top <= tlo->Top) y=-y;

        //odbicie od dolnej sciany
        if(ball->Top+ball->Height >= tlo->Height) y=-y;

        //skucha  lewo
        if(ball->Left+ball->Width >= tlo->Width) //|| ball->Left<=0//)
        {
        timer_pilka->Enabled = false;
        ball->Visible=false;

        Button1->Visible=true;
        Button2->Visible=true;

        Label1->Visible=true;
        Label2->Visible=true;
        Label3->Visible=true;


                      wygrana_lewego++ ;
        punktyLewego=IntToStr(wygrana_lewego);
        punktyPrawego=IntToStr(wygrana_prawego);
        odbicia=IntToStr(ilosc_odbic);

        Label1->Caption=" Wygrana lewego";
                Label2->Caption=" Punkty lewego: "+punktyLewego+", Punkty prawego: "+punktyPrawego;
        Label3->Caption=" Ilosc odbic: " +odbicia;
        timer_pilka->Interval=25;
        }

//skucha  prawo
        if(  ball->Left<=0)
        {
        timer_pilka->Enabled = false;
        ball->Visible=false;

        Button1->Visible=true;
        Button2->Visible=true;

        Label1->Visible=true;
        Label2->Visible=true;
        Label3->Visible=true;


                      wygrana_prawego++ ;
        punktyLewego=IntToStr(wygrana_lewego);
        punktyPrawego=IntToStr(wygrana_prawego);
        odbicia=IntToStr(ilosc_odbic);

        Label1->Caption=" Wygrana prawego";
        Label2->Caption=" Punkty lewego: "+punktyLewego+", Punkty prawego: "+punktyPrawego;
        Label3->Caption=" Ilosc odbic: " +odbicia;

        timer_pilka->Interval=25;
        }


        //odbicie od paletki prawej
        if(ball->Left + ball->Width >= paletka1->Left && ball->Top >= paletka1->Top
        -ball->Height/2 && ball->Top + ball->Height <= paletka1->Top + paletka1->Height +ball->Height/2)
        {
        if(x>0) x=-x;
        ilosc_odbic++;
        timer_pilka->Interval--;
        }

        //odbicie od paletki lewej
        if (ball->Left <= paletka2->Left && ball->Top >= paletka2->Top - ball->Height/2
        && ball->Top + ball->Height <= paletka2->Top + paletka2->Height + ball->Height/2)
        {
          x=-x;
          ilosc_odbic++;
          timer_pilka->Interval--;
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::top_paletka1Timer(TObject *Sender)
{
                if(paletka1->Top>0) paletka1->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::down_paletka1Timer(TObject *Sender)
{
     if(paletka1->Top + paletka1->Height+10 < tlo->Height)  paletka1->Top +=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
         if(Key==VK_UP) top_paletka1->Enabled=true;
         if(Key==VK_DOWN) down_paletka1->Enabled=true;

         if(Key==0x41) top_paletka2->Enabled=true;
         if(Key==0x5A) down_paletka2->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key==VK_UP) top_paletka1->Enabled=false;
         if(Key==VK_DOWN) down_paletka1->Enabled=false;

         if(Key==0x41) top_paletka2->Enabled=false;
         if(Key==0x5A) down_paletka2->Enabled=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
         ilosc_odbic=0;
 wygrana_prawego =0;
 wygrana_lewego=0;
     ball->Left=100; ball->Top=100;
     //p->Left=320;
     ball->Visible=true;

     timer_pilka->Enabled=true;
     Button1->Visible=false;
     Button2->Visible=false;
     Label1->Visible=false;
     Label2->Visible=false;
     Label3->Visible=false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::top_paletka2Timer(TObject *Sender)
{
          if(paletka2->Top>0) paletka2->Top -=10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::down_paletka2Timer(TObject *Sender)
{
        if(paletka2->Top + paletka2->Height+10 < tlo->Height)  paletka2->Top +=10;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button2Click(TObject *Sender)
{
        ball->Left=100; ball->Top=100;
        ilosc_odbic=0;
        timer_pilka->Enabled = true;
        ball->Visible=true;

        Button1->Visible=false;
        Button2->Visible=false;

        Label1->Visible=false;
        Label2->Visible=false;
        Label3->Visible=false;

}
//---------------------------------------------------------------------------






void __fastcall TForm1::Button3Click(TObject *Sender)
{
                   
timer_pilka->Enabled=true;
Button3->Visible=false;
}
//---------------------------------------------------------------------------

