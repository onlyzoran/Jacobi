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
        StringGrid1->Cells[0][1] = 8;
        StringGrid1->Cells[1][1] = 1;
        StringGrid1->Cells[2][1] = -4;
        StringGrid1->Cells[3][1] = 6;
        StringGrid1->Cells[0][2] = 2;
        StringGrid1->Cells[1][2] = -6;
        StringGrid1->Cells[2][2] = 1;
        StringGrid1->Cells[3][2] = -9;
        StringGrid1->Cells[0][3] = -1;
        StringGrid1->Cells[1][3] = 1;
        StringGrid1->Cells[2][3] = 4;
        StringGrid1->Cells[3][3] = 5;
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
                int varN = (int)(CSpinEdit1->Value);
                //Приведение начало
                float massA[20][20];
                float massB[20];
                for(int i = 0; i < varN; i++)
	        {
                        for(int j = 0; j < varN; j++)
	                {
                                massA[i][j] = (StrToFloat)(StringGrid1->Cells[j][i + 1]);
                        }
                        massB[i] = (StrToFloat)(StringGrid1->Cells[varN][i + 1]);;
                }
                float massAP[20][20];
                for(int i = 0; i < varN; i++)
	        {
                        massAP[i][0] = massB[i] / massA[i][i];
	                String str = "x" + (IntToStr)(i + 1) + " = " + FloatToStr(massAP[i][0]);
	                for(int j = 0; j < varN; j++)
	                {
	                        if(i != j)
	                        {
                                        massAP[i][j] = massA[i][j] / massA[i][i] * -1;
	                                if((massAP[i][j]) > 0)
	                                {
	                                        str = str + "+";
	                                }
	                                str = str + FloatToStrF(massAP[i][j], ffGeneral, 4, 2) + "x" + (j + 1);
	                        }
	                }
	                Memo1->Lines->Add(str);
	                str = "";
	        }
                //Приведение конец
                //Приведение в матричной форме начало
                float massAPa[20][20];
                float massAPb[20];
                StringGrid3->ColCount = varN;
	        StringGrid3->RowCount = varN;
                StringGrid4->RowCount = varN;
                for(int i = 0; i < varN; i++)
	        {
                        massAPb[i] = massB[i] / massA[i][i];
                        StringGrid4->Cells[0][i] = FloatToStrF(massAPb[i], ffGeneral, 4, 2);
                        massAPa[i][i] = 0;
	                for(int j = 0; j < varN; j++)
	                {
	                        if(i != j)
	                        {
                                        massAPa[i][j] = massA[i][j] / massA[i][i] * -1;
	                        }
                                StringGrid3->Cells[j][i] = massAPa[i][j];
	                }
	        }
                //Приведение в матричной форме конец
                //Итерации начало
                int numIter = 1;
                StringGrid5->ColCount = varN * 2 + 2;
	        StringGrid5->RowCount = 1;
                for(int i = 0; i < varN; i++)
                {
	                StringGrid5->Cells[i + 1][0] = "x" + IntToStr(i + 1);
	                StringGrid5->Cells[i + varN + 1][0] = "e" + IntToStr(i + 1);
                }
                StringGrid5->Cells[varN * 2 + 1][0] = "eMax";
                float massX[100][20];
                float massE[100][20];
                float massEMax[100];
                for(int i = 0; i < varN; i++)
                {
                        massX[0][i] = massAPb[i];
                        StringGrid5->RowCount++;
                        StringGrid5->Cells[0][1] = 1;
                        StringGrid5->Cells[i + 1][1] = massX[0][i];
                        massE[0][i] = massX[0][i];
                        StringGrid5->Cells[i + varN + 1][1] = massE[0][i];
                }
                massEMax[0] = massE[0][0];
                for(int i = 1; i < varN; i++)
                {
                        if(massEMax[0] < massE[0][i])
                        {
                                massEMax[0] = massE[0][i];
                        }
                }
                StringGrid5->Cells[varN * 2 + 1][1] = massEMax[0];
                float eMax = massEMax[0];
                StringGrid5->FixedRows = 1;
                for(int i = 1; eMax > StrToFloat(Edit1->Text); i++)
                {
                        StringGrid5->RowCount++;
                        StringGrid5->Cells[0][i + 1] = i + 1;
                        for(int j = 0; j < varN; j++)
                        {
                                massX[i][j] = massX[0][j];
                                for(int k = 0; k < varN; k++)
                                {
                                        if(j != k)
                                        {
                                                massX[i][j] = massX[i][j] + massAPa[j][k] * massX[i - 1][k];
                                        }
                                }
                                StringGrid5->Cells[j + 1][i + 1] = massX[i][j];
                                massE[i][j] = fabs(massX[i][j] - massX[i - 1][j]);
                                StringGrid5->Cells[j + varN + 1][i + 1] = massE[i][j];
                        }
                        massEMax[i] = massE[i][0];
                        for(int i = 1; i < varN; i++)
                        {
                                if(massEMax[i] < massE[i][i])
                                {
                                        massEMax[i] = massE[i][i];
                                }
                        }
                        StringGrid5->Cells[varN * 2 + 1][i + 1] = massEMax[i];
                        eMax = massEMax[i];
                        numIter++;
                }
                Edit2->Text = numIter;
                for(int j = 0; j < varN; j++)
                {
                        StringGrid6->Cells[j][1] = massX[numIter - 1][j];
                }
                //Итерации конец
	        //StringGrid2->ColCount = StringGrid1->ColCount - 1;
	        //StringGrid2->RowCount = StringGrid1->RowCount - 1;
	        for(int i = 0; i < (StringGrid1->RowCount - 1); i++)
	        {
	                for(int j = 0; j < (StringGrid1->ColCount - 1); j++)
	                {
	                        //StringGrid2->Cells[j][i] = StringGrid1->Cells[i][j + 1];
	                }
	        }
	        //StringGrid3->ColCount = StringGrid2->ColCount;
	        //StringGrid3->RowCount = StringGrid2->RowCount;
	        for(int i = 0; i < StringGrid3->RowCount; i++)
	        {
	                for(int k = 0; k < StringGrid3->ColCount; k++)
	                {
	                        float s = 0;
	                        for(int j = 0; j < StringGrid3->ColCount; j++)
	                        {
	                                //s = s + StringGrid2->Cells[j][i] * StringGrid1->Cells[k][j + 1];
	                        }
	                        //StringGrid3->Cells[k][i] = FloatToStrF(s, ffGeneral, 4, 2);
	                }
	        }
	        //StringGrid4->RowCount = StringGrid3->RowCount;
	        //for(int i = 0; i < StringGrid4->RowCount; i++)
	        {
	                //float s = 0;
	                //for(int j = 0; j < StringGrid3->ColCount; j++)
	                {
	                        //s = s + StringGrid2->Cells[j][i] * StringGrid1->Cells[StringGrid1->ColCount - 1][j + 1];
	                }
	                //StringGrid4->Cells[0][i] = FloatToStrF(s, ffGeneral, 4, 2);
	        }
	        //float ax[20][20];
	        //float ay[20];
	        //int n = StringGrid3->RowCount;
	        //for(int i = 0; i < n; i++)
	        {
	                //for(int j = 0; j < n; j++)
	                {
	                        //ax[i][j] = StrToFloat(StringGrid3->Cells[j][i]);
	                }
	                //ay[i] = StrToFloat(StringGrid4->Cells[0][i]);
	        }
	        //float b[20][20];
	        //Memo1->Lines->Clear();
	        //for(int i = 0; i < n; i++)
	        {
	                //b[i][0] = ay[i] / ax[i][i];
	                //String str = "x" + (IntToStr)(i + 1) + " = " + FloatToStrF(b[i][0], ffGeneral, 4, 0);
	                //for(int j = 0; j < n; j++)
	                {
	                        //if(i != j)
	                        {
	                                //b[i][j + 1] = ax[i][j] / ax[i][i];
	                                //if(b[i][j + 1] > 0)
	                                {
	                                        //str = str + "+";
	                                }
	                                //str = str + FloatToStrF(b[i][j + 1], ffGeneral, 4, 0) + "x" + (j + 1);
	                        }
	                }
	                //Memo1->Lines->Add(str);
	                //str = "";
	        }
	        //float x[20];
	        //for(int i = 0; i < 20; i++)
	        {
	                //x[i] = 0;
	        }
	        //for(int i = 1; i <= n; i++)
	        {
	                //StringGrid5->Cells[i][0] = "x" + IntToStr(i);
	                //StringGrid5->Cells[i + n][0] = "e" + IntToStr(i);
	        }
	        //float e[20][20];
	        //int notend = 0;
                //int ni;
	        //for(ni = 1; notend < n; ni++)
	        {
	                //StringGrid5->RowCount++;
	                //StringGrid5->Cells[0][ni] = ni;
	                //for(int i = 0; i < n; i++)
	                {
	                        //x[i] = b[i][0];
	                        //for(int j = 0; j < n; j++)
	                        {
	                                //if(i != j)
	                                {
	                                        //x[i] = x[i] - b[i][j + 1] * x[j];
	                                }
	                        }
	                        //StringGrid5->Cells[i + 1][ni] = FloatToStrF(x[i], ffGeneral, 4, 2);
	                }
	                //if(ni > 1)
	                {
	                        //notend = 0;
	                        //for(int i = 0; i < n; i++)
	                        {
	                                //StringGrid5->Cells[i + n + 1][ni] = FloatToStrF(StrToFloat(StringGrid5->Cells[i + 1][ni] - StringGrid5->Cells[i + 1][ni - 1]), ffGeneral, 8, 6);
	                                //if(fabs(StrToFloat(StringGrid5->Cells[i + n + 1][ni])) <= StrToFloat(Edit1->Text))
	                                {
	                                        //notend++;
	                                        //Edit2->Text = ni;
	                                }
	                        }
	                }
	        }
                //StringGrid5->FixedRows = 1;
                StringGrid6->ColCount = varN;
                for(int i = 1; i <= varN; i++)
	        {
	                StringGrid6->Cells[i - 1][0] = "x" + IntToStr(i);
	        }
                for(int i = 0; i < varN; i++)
	        {
	                //StringGrid6->Cells[i][1] = StringGrid5->Cells[i + 1][ni - 1];
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


