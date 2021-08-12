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

void DrawSumPxyqn()
{
  //input file
  TFile *inputFile = new TFile("MergedAll_AnalysisResults.root");
  TList *inputList = (TList *)inputFile->Get("output");
  TH3D *pCent_qn_sumPx = (TH3D *)inputList->FindObject("pCent_qn_sumPx");
  TH3D *pCent_qn_sumPy = (TH3D *)inputList->FindObject("pCent_qn_sumPy");

  TH1* pCent_qn_sumPx_pz[6];

  pCent_qn_sumPx->GetXaxis()->SetRange(4,5);
  pCent_qn_sumPx->GetYaxis()->SetRange(1,3);
  pCent_qn_sumPx_pz[0] = pCent_qn_sumPx->Project3D("z");
  pCent_qn_sumPx_pz[0]->SetName("pCent_qn_sumPx_pz_0");

  pCent_qn_sumPx->GetYaxis()->SetRange(4,6);
  pCent_qn_sumPx_pz[1] = pCent_qn_sumPx->Project3D("z");
  pCent_qn_sumPx_pz[1]->SetName("pCent_qn_sumPx_pz_1");

  pCent_qn_sumPx->GetYaxis()->SetRange(7,9);
  pCent_qn_sumPx_pz[2] = pCent_qn_sumPx->Project3D("z");
  pCent_qn_sumPx_pz[2]->SetName("pCent_qn_sumPx_pz_2");

  pCent_qn_sumPx->GetYaxis()->SetRange(10,12);
  pCent_qn_sumPx_pz[3] = pCent_qn_sumPx->Project3D("z");
  pCent_qn_sumPx_pz[3]->SetName("pCent_qn_sumPx_pz_3");

  pCent_qn_sumPx->GetYaxis()->SetRange(13,15);
  pCent_qn_sumPx_pz[4] = pCent_qn_sumPx->Project3D("z");
  pCent_qn_sumPx_pz[4]->SetName("pCent_qn_sumPx_pz_4");

  TCanvas *c = new TCanvas();
  c->Divide(5);
  for (int i = 0; i < 5; i++) {
    c->cd(i+1);
    pCent_qn_sumPx_pz[i]->SetTitle(Form("qn %i",i));
    pCent_qn_sumPx_pz[i]->Draw();
  }
}
