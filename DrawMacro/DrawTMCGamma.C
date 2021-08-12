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

void DrawTMCGamma()
{
  //input file
  TFile *inputFile = new TFile("MergedAll_AnalysisResults.root");
  TList *inputList = (TList *)inputFile->Get("output");
  TProfile *pDelta_hPos_hPos_sumPx[10];
  TProfile *pDelta_hPos_hNeg_sumPx[10]; 
  TProfile *pDelta_hNeg_hNeg_sumPx[10]; 

  TH1D *hDelta_same_sumPx[10];
  TH1D *hDelta_oppo_sumPx[10]; 

  for (int i = 0; i < 10; i++) {
    pDelta_hPos_hNeg_sumPx[i] = (TProfile *)inputList->FindObject(Form("pDelta_hPos_hNeg_sumPt_cent%i",i));
    pDelta_hPos_hPos_sumPx[i] = (TProfile *)inputList->FindObject(Form("pDelta_hPos_hPos_sumPt_cent%i",i));
    pDelta_hNeg_hNeg_sumPx[i] = (TProfile *)inputList->FindObject(Form("pDelta_hNeg_hNeg_sumPt_cent%i",i));
    pDelta_hPos_hPos_sumPx[i]->Rebin();
    pDelta_hPos_hNeg_sumPx[i]->Rebin();
    pDelta_hNeg_hNeg_sumPx[i]->Rebin();
    pDelta_hPos_hPos_sumPx[i]->Add(pDelta_hNeg_hNeg_sumPx[i],-1);

    hDelta_same_sumPx[i] = pDelta_hPos_hPos_sumPx[i]->ProjectionX();
    hDelta_oppo_sumPx[i] = pDelta_hPos_hNeg_sumPx[i]->ProjectionX();
  }
  hDelta_same_sumPx[3]->Draw();
  hDelta_oppo_sumPx[3]->SetLineColor(kRed);
  hDelta_oppo_sumPx[3]->Draw("SAME");

  // //input file
  // TFile *inputFile = new TFile("MergedAll_AnalysisResults.root");
  // TList *inputList = (TList *)inputFile->Get("output");
  // TProfile *pGamma_hPos_hPos_sumPy[10];
  // TProfile *pGamma_hPos_hNeg_sumPy[10]; 
  // TProfile *pGamma_hNeg_hNeg_sumPy[10]; 

  // TH1D *hGamma_same_sumPy[10];
  // TH1D *hGamma_oppo_sumPy[10]; 

  // for (int i = 0; i < 10; i++) {
  //   pGamma_hPos_hPos_sumPy[i] = (TProfile *)inputList->FindObject(Form("pGamma_hPos_hPos_sumPy_cent%i",i));
  //   pGamma_hPos_hNeg_sumPy[i] = (TProfile *)inputList->FindObject(Form("pGamma_hPos_hNeg_sumPy_cent%i",i));
  //   pGamma_hNeg_hNeg_sumPy[i] = (TProfile *)inputList->FindObject(Form("pGamma_hNeg_hNeg_sumPy_cent%i",i));
  //   pGamma_hPos_hPos_sumPy[i]->Rebin(2);
  //   pGamma_hPos_hNeg_sumPy[i]->Rebin(2);
  //   pGamma_hNeg_hNeg_sumPy[i]->Rebin(2);
  //   pGamma_hPos_hPos_sumPy[i]->Add(pGamma_hNeg_hNeg_sumPy[i],-1);

  //   hGamma_same_sumPy[i] = pGamma_hPos_hPos_sumPy[i]->ProjectionX();
  //   hGamma_oppo_sumPy[i] = pGamma_hPos_hNeg_sumPy[i]->ProjectionX();
  // }
  // hGamma_same_sumPy[3]->Draw();
  // hGamma_oppo_sumPy[3]->SetLineColor(kRed);
  // hGamma_oppo_sumPy[3]->Draw("SAME");
}
