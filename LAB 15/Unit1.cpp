//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=10;
int y=10;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{ Form1->DoubleBuffered=true;
}
void f(int x,int y,TImage*Image)
{
Image->Picture->LoadFromFile("fg.bmp");
Image->Canvas->Rectangle(x+1,y-6,x+11,y+13);
Image->Canvas->Rectangle(x+10,y-6,x+20,y+13);
Image->Canvas->Rectangle(x+19,y-6,x+29,y+13);
Image->Canvas->Brush->Color=clBlue;
Image->Canvas->FloodFill(x+2,y-2,clWhite,fsSurface);
Image->Canvas->FloodFill(x+11,y-2,clWhite,fsSurface);
Image->Canvas->FloodFill(x+20,y-2,clWhite,fsSurface);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
 {Image2->Picture->LoadFromFile("fg.bmp");
Image2->Canvas->Rectangle(x+1,y-6,x+11,y+13);
Image2->Canvas->Rectangle(x+10,y-6,x+20,y+13);
Image2->Canvas->Rectangle(x+19,y-6,x+29,y+13);
Image2->Canvas->Brush->Color=clBlue;
Image2->Canvas->FloodFill(12,11,clWhite,fsSurface);
Image2->Canvas->FloodFill(21,11,clWhite,fsSurface);
Image2->Canvas->FloodFill(30,11,clWhite,fsSurface);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  f(x,y,Image2);
  x++;
  if(x==119)
  x=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key==32)
Timer1->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
 Image1->Picture->LoadFromFile("6.bmp");
 Timer1->Enabled=false;
 Image2->Visible=false;
 Image3->Visible=false;
}
//---------------------------------------------------------------------------

