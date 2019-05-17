//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
#include "CSPIN.h"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TStringGrid *StringGrid1;
        TCSpinEdit *CSpinEdit1;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit1;
        TPopupMenu *PopupMenu1;
        TMenuItem *N11;
        TButton *Button1;
        TStringGrid *StringGrid2;
        TStringGrid *StringGrid3;
        TStringGrid *StringGrid4;
        TMemo *Memo1;
        TStringGrid *StringGrid5;
        TButton *Button2;
        TButton *Button3;
        TEdit *Edit2;
        TLabel *Label3;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TStringGrid *StringGrid6;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TGroupBox *GroupBox5;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox7;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall CSpinEdit1Change(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 