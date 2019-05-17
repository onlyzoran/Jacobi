//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        StringGrid1->ColCount = (int)(CSpinEdit1->Value) + 1;
        StringGrid1->RowCount = (int)(CSpinEdit1->Value) + 1;
        for(int i = 0; i < StringGrid1->ColCount - 1; i++)
        {
                StringGrid1->Cells[i][0] = "x" + IntToStr(i + 1);
        }
        StringGrid1->Cells[StringGrid1->ColCount - 1][0] = "y";
        PageControl1->ActivePageIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CSpinEdit1Change(TObject *Sender)
{
        StringGrid1->ColCount = (int)(CSpinEdit1->Value) + 1;
        StringGrid1->RowCount = (int)(CSpinEdit1->Value) + 1;
        for(int i = 0; i < StringGrid1->ColCount - 1; i++)
        {
                StringGrid1->Cells[i][0] = "x" + IntToStr(i + 1);
        }
        StringGrid1->Cells[StringGrid1->ColCount - 1][0] = "y";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
        CSpinEdit1->Value = 3;
        StringGrid1->ColCount = (int)(CSpinEdit1->Value) + 1;
        StringGrid1->RowCount = (int)(CSpinEdit1->Value) + 1;
        for(int i = 0; i < StringGrid1->ColCount - 1; i++)
        {
                StringGrid1->Cells[i][0] = "x" + IntToStr(i + 1);
        }
        StringGrid1->Cells[StringGrid1->ColCount - 1][0] = "y";
        StringGrid1->Cells[0][1] = 3.6;
        StringGrid1->Cells[1][1] = 1.8;
        StringGrid1->Cells[2][1] = -4.7;
        StringGrid1->Cells[3][1] = 3.8;
        StringGrid1->Cells[0][2] = 2.7;
        StringGrid1->Cells[1][2] = -3.6;
        StringGrid1->Cells[2][2] = 1.9;
        StringGrid1->Cells[3][2] = 0.4;
        StringGrid1->Cells[0][3] = 1.5;
        StringGrid1->Cells[1][3] = 4.5;
        StringGrid1->Cells[2][3] = 3.3;
        StringGrid1->Cells[3][3] = -1.6;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        bool fullStringGrid1 = true;
        for(int i = 1; i < StringGrid1->RowCount; i++)
        {
                for(int j = 0; j < StringGrid1->ColCount; j++)
                {
                        if(StringGrid1->Cells[j][i] == "")
                        {
                                fullStringGrid1 = false;
                        }
                }
        }
        if(fullStringGrid1 == true)
        {
	        StringGrid2->ColCount = StringGrid1->ColCount - 1;
	        StringGrid2->RowCount = StringGrid1->RowCount - 1;
	        for(int i = 0; i < (StringGrid1->RowCount - 1); i++)
	        {
	                for(int j = 0; j < (StringGrid1->ColCount - 1); j++)
	                {
	                        StringGrid2->Cells[j][i] = StringGrid1->Cells[i][j + 1];
	                }
	        }
	        StringGrid3->ColCount = StringGrid2->ColCount;
	        StringGrid3->RowCount = StringGrid2->RowCount;
	        for(int i = 0; i < StringGrid3->RowCount; i++)
	        {
	                for(int k = 0; k < StringGrid3->ColCount; k++)
	                {
	                        float s = 0;
	                        for(int j = 0; j < StringGrid3->ColCount; j++)
	                        {
	                                s = s + StringGrid2->Cells[j][i] * StringGrid1->Cells[k][j + 1];
	                        }
	                        StringGrid3->Cells[k][i] = FloatToStrF(s, ffGeneral, 4, 2);
	                }
	        }
	        StringGrid4->RowCount = StringGrid3->RowCount;
	        for(int i = 0; i < StringGrid4->RowCount; i++)
	        {
	                float s = 0;
	                for(int j = 0; j < StringGrid3->ColCount; j++)
	                {
	                        s = s + StringGrid2->Cells[j][i] * StringGrid1->Cells[StringGrid1->ColCount - 1][j + 1];
	                }
	                StringGrid4->Cells[0][i] = FloatToStrF(s, ffGeneral, 4, 2);
	        }
	        float ax[20][20];
	        float ay[20];
	        int n = StringGrid3->RowCount;
	        for(int i = 0; i < n; i++)
	        {
	                for(int j = 0; j < n; j++)
	                {
	                        ax[i][j] = StrToFloat(StringGrid3->Cells[j][i]);
	                }
	                ay[i] = StrToFloat(StringGrid4->Cells[0][i]);
	        }
	        float b[20][20];
	        Memo1->Lines->Clear();
	        for(int i = 0; i < n; i++)
	        {
	                b[i][0] = ay[i] / ax[i][i];
	                String str = "x" + (IntToStr)(i + 1) + " = " + FloatToStrF(b[i][0], ffGeneral, 4, 0);
	                for(int j = 0; j < n; j++)
	                {
	                        if(i != j)
	                        {
	                                b[i][j + 1] = ax[i][j] / ax[i][i];
	                                if(b[i][j + 1] > 0)
	                                {
	                                        str = str + "+";
	                                }
	                                str = str + FloatToStrF(b[i][j + 1], ffGeneral, 4, 0) + "x" + (j + 1);
	                        }
	                }
	                Memo1->Lines->Add(str);
	                str = "";
	        }
	        float x[20];
	        for(int i = 0; i < 20; i++)
	        {
	                x[i] = 0;
	        }
	        StringGrid5->ColCount = n * 2 + 1;
	        StringGrid5->RowCount = 1;
	        for(int i = 1; i <= n; i++)
	        {
	                StringGrid5->Cells[i][0] = "x" + IntToStr(i);
	                StringGrid5->Cells[i + n][0] = "e" + IntToStr(i);
	        }
	        float e[20][20];
	        int notend = 0;
                int ni;
	        for(ni = 1; notend < n; ni++)
	        {
	                StringGrid5->RowCount++;
	                StringGrid5->Cells[0][ni] = ni;
	                for(int i = 0; i < n; i++)
	                {
	                        x[i] = b[i][0];
	                        for(int j = 0; j < n; j++)
	                        {
	                                if(i != j)
	                                {
	                                        x[i] = x[i] - b[i][j + 1] * x[j];
	                                }
	                        }
	                        StringGrid5->Cells[i + 1][ni] = FloatToStrF(x[i], ffGeneral, 4, 2);
	                }
	                if(ni > 1)
	                {
	                        notend = 0;
	                        for(int i = 0; i < n; i++)
	                        {
	                                StringGrid5->Cells[i + n + 1][ni] = FloatToStrF(StrToFloat(StringGrid5->Cells[i + 1][ni] - StringGrid5->Cells[i + 1][ni - 1]), ffGeneral, 8, 6);
	                                if(fabs(StrToFloat(StringGrid5->Cells[i + n + 1][ni])) <= StrToFloat(Edit1->Text))
	                                {
	                                        notend++;
	                                        Edit2->Text = ni;
	                                }
	                        }
	                }
	        }
                StringGrid5->FixedRows = 1;
                StringGrid6->ColCount = n;
                for(int i = 1; i <= n; i++)
	        {
	                StringGrid6->Cells[i - 1][0] = "x" + IntToStr(i);
	        }
                for(int i = 0; i < n; i++)
	        {
	                StringGrid6->Cells[i][1] = StringGrid5->Cells[i + 1][ni - 1];
	        }
        }
        else
        {
                Application->MessageBox("Заполните содержимое ячеек таблицы", "Ошибка!", MB_OK | MB_ICONWARNING);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Form1->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        for(int i = 0; i < CSpinEdit1->Value; i++)
        {
                StringGrid1->Rows[i + 1]->Clear();
                StringGrid2->Rows[i]->Clear();
                StringGrid3->Rows[i]->Clear();
                StringGrid4->Rows[i]->Clear();
        }
        Memo1->Clear();
        for(int i = 0; i <= StringGrid5->RowCount; i++)
        {
                StringGrid5->Rows[i]->Clear();
        }
        StringGrid6->Rows[0]->Clear();
        StringGrid6->Rows[1]->Clear();
        Edit2->Text = "";
}
//---------------------------------------------------------------------------


