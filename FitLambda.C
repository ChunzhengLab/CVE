#include "TFile.h"
#include "TList.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TProfile.h"
#include "TGraph.h"
#include "TGraphErrors.h"
#include "TDirectory.h"
#include "TString.h"
#include "TStyle.h"
#include "TGraphAsymmErrors.h"
#include "TF1.h"

#include "TSpectrum.h"

void FitLambda()
{
  Double_t par[5];

  Double_t *p;//peak position
  double a1,a2;
  double c1,c2;

  //input file
  TFile *inputFile = new TFile("MergedAll_AnalysisResults.root");
  TList *inputList = (TList *)inputFile->Get("output");
  TH1D *hLambdaMass_bfMassCut = (TH1D *)inputList->FindObject("hLambdaMass_bfMassCut");
  TH1D *hAntiLambdaMass_bfMassCut = (TH1D *)inputList->FindObject("hAntiLambdaMass_bfMassCut");


  //先预拟合
  TSpectrum *s= new TSpectrum(1);
  s->Search(hLambdaMass_bfMassCut);
  p = s->GetPositionX();
  s->Print();

  TF1 *s1 = new TF1("signal","gaus",1.11,1.12);
  TF1 *b1 = new TF1("background","pol2",1.1,1.25);

  TF1 *total= new TF1("total","gaus(0)+pol2(3)",1.08,1.25);
  total->SetLineColor(kMagenta);
  total->SetLineWidth(2);

  hLambdaMass_bfMassCut->Fit(s1,"R0");
  hLambdaMass_bfMassCut->Fit(b1,"R+0");
  s1->GetParameters(&par[0]);
  b1->GetParameters(&par[3]);

  total->SetParameters(par);
  hLambdaMass_bfMassCut->Fit(total,"R+");

  s1->SetParameters(&par[0]);
  b1->SetParameters(&par[3]);
  b1->SetLineColor(kRed);
  b1->SetLineStyle(kDashed);
  b1->Draw("Lsame");
       
  hLambdaMass_bfMassCut->Draw();

}
