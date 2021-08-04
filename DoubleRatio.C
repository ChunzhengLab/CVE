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

void DoubleRatio()
{
  //input file
  TFile *inputFile = new TFile("MergedAll_AnalysisResults.root");
  TList *inputList = (TList *)inputFile->Get("output");
  //N(S)
  TH1D* hNDeltaSPsi2[10];
  //N(S_sf)
  TH1D* hNDeltaSPsi2_sf[10];
  //N(SVert)
  TH1D* hNDeltaSVertPsi2[10];
  //N(SVert_sf)
  TH1D* hNDeltaSVertPsi2_sf[10];

  //N(S)
  TH1D* hNDeltaSPsi3[10];
  //N(S_sf)
  TH1D* hNDeltaSPsi3_sf[10];
  //N(SVert)
  TH1D* hNDeltaSVertPsi3[10];
  //N(SVert_sf)
  TH1D* hNDeltaSVertPsi3_sf[10];

  for (int i = 0; i < 10; i++) {

  //N(S)
    hNDeltaSPsi2[i] = (TH1D*)inputList->FindObject(Form("hNDeltaSPsi2_cent%i",i));
  //N(S_sf)
    hNDeltaSPsi2_sf[i] = (TH1D*)inputList->FindObject(Form("hNDeltaSPsi2_sf_cent%i",i));
  //N(SVert)
    hNDeltaSVertPsi2[i] = (TH1D*)inputList->FindObject(Form("hNDeltaSVertPsi2_cent%i",i));
  //N(SVert_sf)
    hNDeltaSVertPsi2_sf[i] = (TH1D*)inputList->FindObject(Form("hNDeltaSVertPsi2_sf_cent%i",i));

  //N(S)
    hNDeltaSPsi3[i] = (TH1D*)inputList->FindObject(Form("hNDeltaSPsi3_cent%i",i));
  //N(S_sf)
    hNDeltaSPsi3_sf[i] = (TH1D*)inputList->FindObject(Form("hNDeltaSPsi3_sf_cent%i",i));
  //N(SVert)
    hNDeltaSVertPsi3[i] = (TH1D*)inputList->FindObject(Form("hNDeltaSVertPsi3_cent%i",i));
  //N(SVert_sf)
    hNDeltaSVertPsi3_sf[i] = (TH1D*)inputList->FindObject(Form("hNDeltaSVertPsi3_sf_cent%i",i));

    hNDeltaSPsi2[i]->Divide(hNDeltaSPsi2_sf[i]);
    hNDeltaSVertPsi2[i]->Divide(hNDeltaSVertPsi2_sf[i]);
    
    hNDeltaSPsi3[i]->Divide(hNDeltaSPsi3_sf[i]);
    hNDeltaSVertPsi3[i]->Divide(hNDeltaSVertPsi3_sf[i]);

    hNDeltaSPsi2[i]->Divide(hNDeltaSVertPsi2[i]);
    hNDeltaSPsi3[i]->Divide(hNDeltaSVertPsi3[i]);
  }
  
  TCanvas *c = new TCanvas();
  c->Divide(3,3);
  c->cd(1);
  hNDeltaSPsi2[0]->Draw();
  c->cd(2);
  hNDeltaSPsi2[1]->Draw();
  c->cd(3);
  hNDeltaSPsi2[2]->Draw();
  c->cd(4);
  hNDeltaSPsi2[3]->Draw();
  c->cd(5);
  hNDeltaSPsi2[4]->Draw();
  c->cd(6);
  hNDeltaSPsi2[5]->Draw();
  c->cd(7);
  hNDeltaSPsi2[6]->Draw();
  c->cd(8);
  hNDeltaSPsi2[7]->Draw();

  // TCanvas *c1 = new TCanvas();
  // c1->Divide(3,3);
  // c1->cd(1);
  // hNDeltaSPsi3[0]->Draw();
  // c1->cd(2);
  // hNDeltaSPsi3[1]->Draw();
  // c1->cd(3);
  // hNDeltaSPsi3[2]->Draw();
  // c1->cd(4);
  // hNDeltaSPsi3[3]->Draw();
  // c1->cd(5);
  // hNDeltaSPsi3[4]->Draw();
  // c1->cd(6);
  // hNDeltaSPsi3[5]->Draw();
  // c1->cd(7);
  // hNDeltaSPsi3[6]->Draw();
  // c1->cd(8);
  // hNDeltaSPsi3[7]->Draw();
}
