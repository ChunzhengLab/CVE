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

void DrawGamma()
{
  //input file
  TFile *inputFile = new TFile("MergedAll_AnalysisResults.root");
  TList *inputList = (TList *)inputFile->Get("output");
  TProfile *pDelta_hPos_hPos = (TProfile *)inputList->FindObject("pDelta_hPos_hPos");
  TProfile *pDelta_hNeg_hNeg = (TProfile *)inputList->FindObject("pDelta_hNeg_hNeg");
  TProfile *pDelta_hPos_hNeg = (TProfile *)inputList->FindObject("pDelta_hPos_hNeg");

  TProfile *pGammaRDM_hPos_hPos = (TProfile *)inputList->FindObject("pGammaRDM_hPos_hPos");
  TProfile *pGammaRDM_hNeg_hNeg = (TProfile *)inputList->FindObject("pGammaRDM_hNeg_hNeg");
  TProfile *pGammaRDM_hPos_hNeg = (TProfile *)inputList->FindObject("pGammaRDM_hPos_hNeg");

  TProfile *pGammaTPC_hPos_hPos = (TProfile *)inputList->FindObject("pGammaTPC_hPos_hPos");
  TProfile *pGammaTPC_hNeg_hNeg = (TProfile *)inputList->FindObject("pGammaTPC_hNeg_hNeg");
  TProfile *pGammaTPC_hPos_hNeg = (TProfile *)inputList->FindObject("pGammaTPC_hPos_hNeg");

  TProfile *pGammaTPCVsDeltaPt_hPos_hPos_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsDeltaPt_hPos_hPos_cent3");
  TProfile *pGammaTPCVsDeltaPt_hPos_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsDeltaPt_hPos_hNeg_cent3");
  TProfile *pGammaTPCVsDeltaPt_hNeg_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsDeltaPt_hNeg_hNeg_cent3");

  TProfile *pGammaTPVVsMeanPt_hPos_hPos_cent3 = (TProfile *)inputList->FindObject("pGammaTPVVsMeanPt_hPos_hPos_cent3");
  TProfile *pGammaTPVVsMeanPt_hPos_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPVVsMeanPt_hPos_hNeg_cent3");
  TProfile *pGammaTPVVsMeanPt_hNeg_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPVVsMeanPt_hNeg_hNeg_cent3");

  TProfile *pGammaTPCVsDeltaEta_hPos_hPos_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsDeltaEta_hPos_hPos_cent3");
  TProfile *pGammaTPCVsDeltaEta_hPos_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsDeltaEta_hPos_hNeg_cent3");
  TProfile *pGammaTPCVsDeltaEta_hNeg_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsDeltaEta_hNeg_hNeg_cent3");

  
  double xbins[11] = {0., 5., 10., 20., 30., 40., 50., 60., 70., 80., 90.};
  TProfile *pDelta_hPos_hPos_reBin = (TProfile *)pDelta_hPos_hPos->Rebin(10, "pDelta_hPos_hPos_rebin", xbins);
  TProfile *pDelta_hNeg_hNeg_reBin = (TProfile *)pDelta_hNeg_hNeg->Rebin(10, "pDelta_hNeg_hNeg_rebin", xbins);
  TProfile *pDelta_hPos_hNeg_reBin = (TProfile *)pDelta_hPos_hNeg->Rebin(10, "pDelta_hPos_hNeg_rebin", xbins);

  TProfile *pGammaRDM_hPos_hPos_reBin = (TProfile *)pGammaRDM_hPos_hPos->Rebin(10, "pGammaRDM_hPos_hPos_rebin", xbins);
  TProfile *pGammaRDM_hNeg_hNeg_reBin = (TProfile *)pGammaRDM_hNeg_hNeg->Rebin(10, "pGammaRDM_hNeg_hNeg_rebin", xbins);
  TProfile *pGammaRDM_hPos_hNeg_reBin = (TProfile *)pGammaRDM_hPos_hNeg->Rebin(10, "pGammaRDM_hPos_hNeg_rebin", xbins);

  TProfile *pGammaTPC_hPos_hPos_reBin = (TProfile *)pGammaTPC_hPos_hPos->Rebin(10, "pGammaTPC_hPos_hPos_rebin", xbins);
  TProfile *pGammaTPC_hNeg_hNeg_reBin = (TProfile *)pGammaTPC_hNeg_hNeg->Rebin(10, "pGammaTPC_hNeg_hNeg_rebin", xbins);
  TProfile *pGammaTPC_hPos_hNeg_reBin = (TProfile *)pGammaTPC_hPos_hNeg->Rebin(10, "pGammaTPC_hPos_hNeg_rebin", xbins);

  pDelta_hPos_hPos_reBin->SetLineColor(kRed);
  pDelta_hPos_hPos_reBin->SetMarkerColor(kRed);
  pDelta_hPos_hPos_reBin->SetMarkerStyle(22);
  pDelta_hNeg_hNeg_reBin->SetLineColor(kBlue);
  pDelta_hNeg_hNeg_reBin->SetMarkerColor(kBlue);
  pDelta_hNeg_hNeg_reBin->SetMarkerStyle(23);
  pDelta_hPos_hNeg_reBin->SetLineColor(kBlack);
  pDelta_hPos_hNeg_reBin->SetMarkerColor(kBlack);
  pDelta_hPos_hNeg_reBin->SetMarkerStyle(21);
  pGammaRDM_hPos_hPos_reBin->SetLineColor(kRed);
  pGammaRDM_hPos_hPos_reBin->SetMarkerColor(kRed);
  pGammaRDM_hPos_hPos_reBin->SetMarkerStyle(22);
  pGammaRDM_hNeg_hNeg_reBin->SetLineColor(kBlue);
  pGammaRDM_hNeg_hNeg_reBin->SetMarkerColor(kBlue);
  pGammaRDM_hNeg_hNeg_reBin->SetMarkerStyle(23);
  pGammaRDM_hPos_hNeg_reBin->SetLineColor(kBlack);
  pGammaRDM_hPos_hNeg_reBin->SetMarkerColor(kBlack);
  pGammaRDM_hPos_hNeg_reBin->SetMarkerStyle(21);
  pGammaTPC_hPos_hPos_reBin->SetLineColor(kRed);
  pGammaTPC_hPos_hPos_reBin->SetMarkerColor(kRed);
  pGammaTPC_hPos_hPos_reBin->SetMarkerStyle(22);
  pGammaTPC_hNeg_hNeg_reBin->SetLineColor(kBlue);
  pGammaTPC_hNeg_hNeg_reBin->SetMarkerColor(kBlue);
  pGammaTPC_hNeg_hNeg_reBin->SetMarkerStyle(23);
  pGammaTPC_hPos_hNeg_reBin->SetLineColor(kBlack);
  pGammaTPC_hPos_hNeg_reBin->SetMarkerColor(kBlack);
  pGammaTPC_hPos_hNeg_reBin->SetMarkerStyle(21);

  pGammaTPCVsDeltaPt_hPos_hPos_cent3->SetLineColor(kRed);
  pGammaTPCVsDeltaPt_hPos_hPos_cent3->SetMarkerStyle(22);
  pGammaTPCVsDeltaPt_hPos_hPos_cent3->SetMarkerColor(kRed);
  pGammaTPCVsDeltaPt_hPos_hNeg_cent3->SetLineColor(kBlack);
  pGammaTPCVsDeltaPt_hPos_hNeg_cent3->SetMarkerStyle(22);
  pGammaTPCVsDeltaPt_hPos_hNeg_cent3->SetMarkerColor(kBlack);
  pGammaTPCVsDeltaPt_hNeg_hNeg_cent3->SetLineColor(kBlue);
  pGammaTPCVsDeltaPt_hNeg_hNeg_cent3->SetMarkerStyle(22);
  pGammaTPCVsDeltaPt_hNeg_hNeg_cent3->SetMarkerColor(kBlue);

  pGammaTPVVsMeanPt_hPos_hPos_cent3->SetLineColor(kRed);
  pGammaTPVVsMeanPt_hPos_hPos_cent3->SetMarkerColor(kRed);
  pGammaTPVVsMeanPt_hPos_hNeg_cent3->SetLineColor(kBlack);
  pGammaTPVVsMeanPt_hPos_hNeg_cent3->SetMarkerColor(kBlack);
  pGammaTPVVsMeanPt_hNeg_hNeg_cent3->SetLineColor(kBlue);
  pGammaTPVVsMeanPt_hNeg_hNeg_cent3->SetMarkerColor(kBlue);

  pGammaTPCVsDeltaEta_hPos_hPos_cent3->SetLineColor(kRed);
  pGammaTPCVsDeltaEta_hPos_hPos_cent3->SetMarkerColor(kRed);
  pGammaTPCVsDeltaEta_hPos_hNeg_cent3->SetLineColor(kBlack);
  pGammaTPCVsDeltaEta_hPos_hNeg_cent3->SetMarkerColor(kBlack);
  pGammaTPCVsDeltaEta_hNeg_hNeg_cent3->SetLineColor(kBlue);
  pGammaTPCVsDeltaEta_hNeg_hNeg_cent3->SetMarkerColor(kBlue);

  TH3D *hPsiTPC = (TH3D *)inputList->FindObject("hPsiTPC");
  TH2D *hPsiTPC_cent_psi = (TH2D *)hPsiTPC->Project3D("yz");
  TH2D *hPsiTPC_runNum_psi = (TH2D *)hPsiTPC->Project3D("xz");

  TFile *pubFile = new TFile("HEPData-ins1121161-v1-root.root", "READ");
  TDirectory *pubFolder_2 = pubFile->GetDirectory("Table 2");
  TDirectory *pubFolder_3 = pubFile->GetDirectory("Table 3");
  TDirectory *pubFolder_5 = pubFile->GetDirectory("Table 5");
  TDirectory *pubFolder_8 = pubFile->GetDirectory("Table 8");
  TDirectory *pubFolder_9 = pubFile->GetDirectory("Table 9");
  TDirectory *pubFolder_10 = pubFile->GetDirectory("Table 10");

  TGraphAsymmErrors *gPubGammaTPC_oppo = NULL;
  TGraphAsymmErrors *gPubGammaTPC_same = NULL;
  pubFolder_2->GetObject("Graph1D_y1", gPubGammaTPC_oppo);
  pubFolder_2->GetObject("Graph1D_y2", gPubGammaTPC_same);
  gPubGammaTPC_oppo->SetMarkerStyle(4);
  gPubGammaTPC_same->SetMarkerStyle(4);

  TGraphAsymmErrors *gPubGammaVZERO_oppo = NULL;
  TGraphAsymmErrors *gPubGammaVZERO_same = NULL;
  pubFolder_3->GetObject("Graph1D_y1", gPubGammaVZERO_oppo);
  pubFolder_3->GetObject("Graph1D_y2", gPubGammaVZERO_same);
  gPubGammaVZERO_oppo->SetMarkerStyle(4);
  gPubGammaVZERO_same->SetMarkerStyle(4);

  TGraphAsymmErrors *gPubDelta_oppo = NULL;
  TGraphAsymmErrors *gPubDelta_same = NULL;
  pubFolder_5->GetObject("Graph1D_y1", gPubDelta_oppo);
  pubFolder_5->GetObject("Graph1D_y2", gPubDelta_same);
  gPubDelta_oppo->SetMarkerStyle(4);
  gPubDelta_same->SetMarkerStyle(4);

  TGraphAsymmErrors *gPubDeltaPt_oppo = NULL;
  TGraphAsymmErrors *gPubDeltaPt_same = NULL;
  pubFolder_8->GetObject("Graph1D_y1", gPubDeltaPt_oppo);
  pubFolder_8->GetObject("Graph1D_y2", gPubDeltaPt_same);
  gPubDeltaPt_oppo->SetMarkerStyle(4);
  gPubDeltaPt_oppo->SetLineStyle(1);
  gPubDeltaPt_same->SetMarkerStyle(4);
  gPubDeltaPt_same->SetLineStyle(7);

  TGraphAsymmErrors *gPubMeanPt_oppo = NULL;
  TGraphAsymmErrors *gPubMeanPt_same = NULL;
  pubFolder_9->GetObject("Graph1D_y1", gPubMeanPt_oppo);
  pubFolder_9->GetObject("Graph1D_y2", gPubMeanPt_same);
  gPubMeanPt_oppo->SetMarkerStyle(4);
  gPubMeanPt_oppo->SetLineStyle(1);
  gPubMeanPt_same->SetMarkerStyle(4);
  gPubMeanPt_same->SetLineStyle(7);

  TGraphAsymmErrors *gPubDeltaEta_oppo = NULL;
  TGraphAsymmErrors *gPubDeltaEta_same = NULL;
  pubFolder_10->GetObject("Graph1D_y1", gPubDeltaEta_oppo);
  pubFolder_10->GetObject("Graph1D_y2", gPubDeltaEta_same);
  gPubDeltaEta_oppo->SetMarkerStyle(4);
  gPubDeltaEta_oppo->SetLineStyle(1);
  gPubDeltaEta_same->SetMarkerStyle(4);
  gPubDeltaEta_same->SetLineStyle(7);

  gStyle->SetOptStat(kFALSE);
  TH2D *dummy_0 = new TH2D("", "", 1, 0, 82, 1, -0.002, 0.01);
  dummy_0->GetXaxis()->SetLimits(0, 72.);
  TH2D *dummy_1 = new TH2D("", "", 1, 0, 82, 1, -0.0006, 0.0005);
  dummy_1->GetXaxis()->SetLimits(0, 72.);
  TH2D *dummy_2 = new TH2D("", "", 1, 0, 82, 1, -0.0006, 0.0005);
  dummy_2->GetXaxis()->SetLimits(0, 72.);
  TH2D *dummy_3 = new TH2D("", "", 1, 0, 82, 1, -0.0006, 0.0005);
  dummy_3->GetXaxis()->SetLimits(0, 72.);

  TH2D *dummy_4 = new TH2D("", "", 1, 0, 2., 1, -0.0006, 0.00035);
  TH2D *dummy_5 = new TH2D("", "", 1, 0, 2., 1, -0.0006, 0.00035);
  TH2D *dummy_6 = new TH2D("", "", 1, 0, 1.6, 1, -0.0006, 0.00035);

  TH2D* dummy_7 = new TH2D("","", 1, 0.5, 3, 1, -0.0003, 0.0003);
  TH2D* dummy_8 = new TH2D("","", 1, 0.5, 3, 1, -0.0008, 0.0008);
  // TH2D* dummy_9 = new TH2D("","", 1, 0, 82, 1, -0.0006, 0.0005);
  // dummy_9->GetXaxis()->SetLimits(0,72.);
  // TH2D* dummy_10 = new TH2D("","", 1, 0, 82, 1, -0.0006, 0.0005);
  // dummy_10->GetXaxis()->SetLimits(0,72.);
  // TH2D* dummy_11 = new TH2D("","", 1, 0, 82, 1, -0.0006, 0.0005);
  // dummy_11->GetXaxis()->SetLimits(0,72.);
  // TH2D* dummy_12 = new TH2D("","", 1, 0, 82, 1, -0.0006, 0.0005);
  // dummy_12->GetXaxis()->SetLimits(0,72.);
  // TH2D* dummy_13 = new TH2D("","", 1, 0, 82, 1, -0.0006, 0.0005);
  // dummy_13->GetXaxis()->SetLimits(0,72.);
  // TH2D* dummy_14 = new TH2D("","", 1, 0, 82, 1, -0.0006, 0.0005);
  // dummy_14->GetXaxis()->SetLimits(0,72.);
  // TH2D* dummy_15 = new TH2D("","", 1, 0, 82, 1, -0.0006, 0.0005);
  // dummy_15->GetXaxis()->SetLimits(0,72.);
  // TH2D* dummy_16 = new TH2D("","", 1, 0, 82, 1, -0.0006, 0.0005);
  // dummy_16->GetXaxis()->SetLimits(0,72.);
  // TH2D* dummy_17 = new TH2D("","", 1, 0, 82, 1, -0.0006, 0.0005);
  // dummy_17->GetXaxis()->SetLimits(0,72.);
  // TH2D* dummy_18 = new TH2D("","", 1, 0, 82, 1, -0.0006, 0.0005);
  // dummy_18->GetXaxis()->SetLimits(0,72.);
  // TH2D* dummy_19 = new TH2D("","", 1, 0, 82, 1, -0.0006, 0.0005);
  // dummy_19->GetXaxis()->SetLimits(0,72.);

  TCanvas *plotTPC = new TCanvas("plotTPC", "plotTPC", 1200, 400);
  plotTPC->Divide(3, 1);
  dummy_0->SetTitle("#delta = <cos(#phi_{#alpha} - #phi_{#beta})>");
  plotTPC->cd(1);
  dummy_0->Draw("SAME");
  gPubDelta_oppo->Draw("SAME");
  gPubDelta_same->Draw("SAME");
  pDelta_hPos_hPos_reBin->Draw("SAME");
  pDelta_hNeg_hNeg_reBin->Draw("same");
  pDelta_hPos_hNeg_reBin->Draw("same");

  plotTPC->cd(2);
  dummy_2->SetTitle("#gamma_{RDM} = <cos(#phi_{#alpha} + #phi_{#beta} - 2#Psi_{Random})>");
  dummy_2->Draw();
  gPubGammaVZERO_oppo->Draw("same");
  gPubGammaVZERO_same->Draw("same");
  pGammaRDM_hPos_hPos_reBin->Draw("same");
  pGammaRDM_hNeg_hNeg_reBin->Draw("same");
  pGammaRDM_hPos_hNeg_reBin->Draw("same");

  plotTPC->cd(3);
  dummy_3->SetTitle("#gamma_{TPC} = <cos(#phi_{#alpha} + #phi_{#beta} - 2#Psi_{TPC})>");
  dummy_3->Draw();
  gPubGammaTPC_oppo->Draw("same");
  gPubGammaTPC_same->Draw("same");
  pGammaTPC_hPos_hPos_reBin->Draw("same");
  pGammaTPC_hNeg_hNeg_reBin->Draw("same");
  pGammaTPC_hPos_hNeg_reBin->Draw("same");

  TCanvas *plotDiff = new TCanvas("Diff", "Diff", 1200, 400);
  plotDiff->Divide(3, 1);
  dummy_4->SetTitle("#Deltap_{T}");
  plotDiff->cd(1);
  dummy_4->Draw("SAME");
  gPubDeltaPt_oppo->Draw("SAME");
  gPubDeltaPt_same->Draw("SAME");
  pGammaTPCVsDeltaPt_hPos_hPos_cent3->Draw("SAME");
  pGammaTPCVsDeltaPt_hPos_hNeg_cent3->Draw("SAME");
  pGammaTPCVsDeltaPt_hNeg_hNeg_cent3->Draw("SAME");

  dummy_5->SetTitle("Mean p_{T}");
  plotDiff->cd(2);
  dummy_5->Draw("SAME");
  gPubMeanPt_oppo->Draw("SAME");
  gPubMeanPt_same->Draw("SAME");
  pGammaTPVVsMeanPt_hPos_hPos_cent3->Draw("SAME");
  pGammaTPVVsMeanPt_hPos_hNeg_cent3->Draw("SAME");
  pGammaTPVVsMeanPt_hNeg_hNeg_cent3->Draw("SAME");

  dummy_6->SetTitle("#Delta#eta");
  plotDiff->cd(3);
  dummy_6->Draw("SAME");
  gPubDeltaEta_oppo->Draw("SAME");
  gPubDeltaEta_same->Draw("SAME");
  pGammaTPCVsDeltaEta_hPos_hPos_cent3->Draw("SAME");
  pGammaTPCVsDeltaEta_hPos_hNeg_cent3->Draw("SAME");
  pGammaTPCVsDeltaEta_hNeg_hNeg_cent3->Draw("SAME");


  TProfile *pGammaTPCVsPt_pion_hPos_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_pion_hPos_cent1");
  TProfile *pGammaTPCVsPt_pion_hNeg_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_pion_hNeg_cent1");
  TProfile *pGammaTPCVsPt_pion_hPos_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_pion_hPos_cent2");
  TProfile *pGammaTPCVsPt_pion_hNeg_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_pion_hNeg_cent2");
  TProfile *pGammaTPCVsPt_pion_hPos_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_pion_hPos_cent3");
  TProfile *pGammaTPCVsPt_pion_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_pion_hNeg_cent3");
  TProfile *pGammaTPCVsPt_pion_hPos_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_pion_hPos_cent4");
  TProfile *pGammaTPCVsPt_pion_hNeg_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_pion_hNeg_cent4");

  TProfile *pGammaTPCVsPt_kaon_hPos_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_kaon_hPos_cent1");
  TProfile *pGammaTPCVsPt_kaon_hNeg_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_kaon_hNeg_cent1");
  TProfile *pGammaTPCVsPt_kaon_hPos_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_kaon_hPos_cent2");
  TProfile *pGammaTPCVsPt_kaon_hNeg_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_kaon_hNeg_cent2");
  TProfile *pGammaTPCVsPt_kaon_hPos_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_kaon_hPos_cent3");
  TProfile *pGammaTPCVsPt_kaon_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_kaon_hNeg_cent3");
  TProfile *pGammaTPCVsPt_kaon_hPos_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_kaon_hPos_cent4");
  TProfile *pGammaTPCVsPt_kaon_hNeg_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_kaon_hNeg_cent4");

  TProfile *pGammaTPCVsPt_proton_hPos_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_proton_hPos_cent1");
  TProfile *pGammaTPCVsPt_proton_hNeg_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_proton_hNeg_cent1");
  TProfile *pGammaTPCVsPt_proton_hPos_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_proton_hPos_cent2");
  TProfile *pGammaTPCVsPt_proton_hNeg_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_proton_hNeg_cent2");
  TProfile *pGammaTPCVsPt_proton_hPos_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_proton_hPos_cent3");
  TProfile *pGammaTPCVsPt_proton_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_proton_hNeg_cent3");
  TProfile *pGammaTPCVsPt_proton_hPos_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_proton_hPos_cent4");
  TProfile *pGammaTPCVsPt_proton_hNeg_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_proton_hNeg_cent4");

  TProfile *pGammaTPCVsPt_antiPion_hPos_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiPion_hPos_cent1");
  TProfile *pGammaTPCVsPt_antiPion_hNeg_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiPion_hNeg_cent1");
  TProfile *pGammaTPCVsPt_antiPion_hPos_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiPion_hPos_cent2");
  TProfile *pGammaTPCVsPt_antiPion_hNeg_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiPion_hNeg_cent2");
  TProfile *pGammaTPCVsPt_antiPion_hPos_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiPion_hPos_cent3");
  TProfile *pGammaTPCVsPt_antiPion_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiPion_hNeg_cent3");
  TProfile *pGammaTPCVsPt_antiPion_hPos_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiPion_hPos_cent4");
  TProfile *pGammaTPCVsPt_antiPion_hNeg_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiPion_hNeg_cent4");

  TProfile *pGammaTPCVsPt_antiKaon_hPos_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiKaon_hPos_cent1");
  TProfile *pGammaTPCVsPt_antiKaon_hNeg_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiKaon_hNeg_cent1");
  TProfile *pGammaTPCVsPt_antiKaon_hPos_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiKaon_hPos_cent2");
  TProfile *pGammaTPCVsPt_antiKaon_hNeg_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiKaon_hNeg_cent2");
  TProfile *pGammaTPCVsPt_antiKaon_hPos_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiKaon_hPos_cent3");
  TProfile *pGammaTPCVsPt_antiKaon_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiKaon_hNeg_cent3");
  TProfile *pGammaTPCVsPt_antiKaon_hPos_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiKaon_hPos_cent4");
  TProfile *pGammaTPCVsPt_antiKaon_hNeg_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiKaon_hNeg_cent4");
  
  TProfile *pGammaTPCVsPt_antiProton_hPos_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiProton_hPos_cent1");
  TProfile *pGammaTPCVsPt_antiProton_hNeg_cent1 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiProton_hNeg_cent1");
  TProfile *pGammaTPCVsPt_antiProton_hPos_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiProton_hPos_cent2");
  TProfile *pGammaTPCVsPt_antiProton_hNeg_cent2 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiProton_hNeg_cent2");
  TProfile *pGammaTPCVsPt_antiProton_hPos_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiProton_hPos_cent3");
  TProfile *pGammaTPCVsPt_antiProton_hNeg_cent3 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiProton_hNeg_cent3");
  TProfile *pGammaTPCVsPt_antiProton_hPos_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiProton_hPos_cent4");
  TProfile *pGammaTPCVsPt_antiProton_hNeg_cent4 = (TProfile *)inputList->FindObject("pGammaTPCVsPt_antiProton_hNeg_cent4");


  TProfile* pGammaTPCVsPt_pion_same_1020 = new TProfile("pGammaTPCVsPt_pion_same_1020","",6,0.,3.);
  TProfile* pGammaTPCVsPt_pion_oppo_1020 = new TProfile("pGammaTPCVsPt_pion_oppo_1020","",6,0.,3.);
  TProfile* pGammaTPCVsPt_kaon_same_1020 = new TProfile("pGammaTPCVsPt_kaon_same_1020","",6,0.,3.);
  TProfile* pGammaTPCVsPt_kaon_oppo_1020 = new TProfile("pGammaTPCVsPt_kaon_oppo_1020","",6,0.,3.);
  TProfile* pGammaTPCVsPt_proton_same_1020 = new TProfile("pGammaTPCVsPt_proton_same_1020","",6,0.,3.);
  TProfile* pGammaTPCVsPt_proton_oppo_1020 = new TProfile("pGammaTPCVsPt_proton_oppo_1020","",6,0.,3.);

  TProfile* pGammaTPCVsPt_pion_same_3040 = new TProfile("pGammaTPCVsPt_pion_same_3040","",6,0.,3.);
  TProfile* pGammaTPCVsPt_pion_oppo_3040 = new TProfile("pGammaTPCVsPt_pion_oppo_3040","",6,0.,3.);
  TProfile* pGammaTPCVsPt_kaon_same_3040 = new TProfile("pGammaTPCVsPt_kaon_same_3040","",6,0.,3.);
  TProfile* pGammaTPCVsPt_kaon_oppo_3040 = new TProfile("pGammaTPCVsPt_kaon_oppo_3040","",6,0.,3.);
  TProfile* pGammaTPCVsPt_proton_same_3040 = new TProfile("pGammaTPCVsPt_proton_same_3040","",6,0.,3.);
  TProfile* pGammaTPCVsPt_proton_oppo_3040 = new TProfile("pGammaTPCVsPt_proton_oppo_3040","",6,0.,3.);

  pGammaTPCVsPt_pion_same_1020->Add(pGammaTPCVsPt_pion_hPos_cent1);
  pGammaTPCVsPt_pion_same_1020->Add(pGammaTPCVsPt_pion_hPos_cent2);
  pGammaTPCVsPt_pion_same_1020->Add(pGammaTPCVsPt_antiPion_hNeg_cent1);
  pGammaTPCVsPt_pion_same_1020->Add(pGammaTPCVsPt_antiPion_hNeg_cent2);
  pGammaTPCVsPt_pion_oppo_1020->Add(pGammaTPCVsPt_pion_hNeg_cent1);
  pGammaTPCVsPt_pion_oppo_1020->Add(pGammaTPCVsPt_pion_hNeg_cent2);
  pGammaTPCVsPt_pion_oppo_1020->Add(pGammaTPCVsPt_antiPion_hPos_cent1);
  pGammaTPCVsPt_pion_oppo_1020->Add(pGammaTPCVsPt_antiPion_hPos_cent2);

  pGammaTPCVsPt_pion_same_3040->Add(pGammaTPCVsPt_pion_hPos_cent3);
  pGammaTPCVsPt_pion_same_3040->Add(pGammaTPCVsPt_pion_hPos_cent4);
  pGammaTPCVsPt_pion_same_3040->Add(pGammaTPCVsPt_antiPion_hNeg_cent3);
  pGammaTPCVsPt_pion_same_3040->Add(pGammaTPCVsPt_antiPion_hNeg_cent4);
  pGammaTPCVsPt_pion_oppo_3040->Add(pGammaTPCVsPt_pion_hNeg_cent3);
  pGammaTPCVsPt_pion_oppo_3040->Add(pGammaTPCVsPt_pion_hNeg_cent4);
  pGammaTPCVsPt_pion_oppo_3040->Add(pGammaTPCVsPt_antiPion_hPos_cent3);
  pGammaTPCVsPt_pion_oppo_3040->Add(pGammaTPCVsPt_antiPion_hPos_cent4);



  pGammaTPCVsPt_kaon_same_1020->Add(pGammaTPCVsPt_kaon_hPos_cent1);
  pGammaTPCVsPt_kaon_same_1020->Add(pGammaTPCVsPt_kaon_hPos_cent2);
  pGammaTPCVsPt_kaon_same_1020->Add(pGammaTPCVsPt_antiKaon_hNeg_cent1);
  pGammaTPCVsPt_kaon_same_1020->Add(pGammaTPCVsPt_antiKaon_hNeg_cent2);
  pGammaTPCVsPt_kaon_oppo_1020->Add(pGammaTPCVsPt_kaon_hNeg_cent1);
  pGammaTPCVsPt_kaon_oppo_1020->Add(pGammaTPCVsPt_kaon_hNeg_cent2);
  pGammaTPCVsPt_kaon_oppo_1020->Add(pGammaTPCVsPt_antiKaon_hPos_cent1);
  pGammaTPCVsPt_kaon_oppo_1020->Add(pGammaTPCVsPt_antiKaon_hPos_cent2);

  pGammaTPCVsPt_kaon_same_3040->Add(pGammaTPCVsPt_kaon_hPos_cent3);
  pGammaTPCVsPt_kaon_same_3040->Add(pGammaTPCVsPt_kaon_hPos_cent4);
  pGammaTPCVsPt_kaon_same_3040->Add(pGammaTPCVsPt_antiKaon_hNeg_cent3);
  pGammaTPCVsPt_kaon_same_3040->Add(pGammaTPCVsPt_antiKaon_hNeg_cent4);
  pGammaTPCVsPt_kaon_oppo_3040->Add(pGammaTPCVsPt_kaon_hNeg_cent3);
  pGammaTPCVsPt_kaon_oppo_3040->Add(pGammaTPCVsPt_kaon_hNeg_cent4);
  pGammaTPCVsPt_kaon_oppo_3040->Add(pGammaTPCVsPt_antiKaon_hPos_cent3);
  pGammaTPCVsPt_kaon_oppo_3040->Add(pGammaTPCVsPt_antiKaon_hPos_cent4);


  pGammaTPCVsPt_proton_same_1020->Add(pGammaTPCVsPt_proton_hPos_cent1);
  pGammaTPCVsPt_proton_same_1020->Add(pGammaTPCVsPt_proton_hPos_cent2);
  pGammaTPCVsPt_proton_same_1020->Add(pGammaTPCVsPt_antiProton_hNeg_cent1);
  pGammaTPCVsPt_proton_same_1020->Add(pGammaTPCVsPt_antiProton_hNeg_cent2);
  pGammaTPCVsPt_proton_oppo_1020->Add(pGammaTPCVsPt_proton_hNeg_cent1);
  pGammaTPCVsPt_proton_oppo_1020->Add(pGammaTPCVsPt_proton_hNeg_cent2);
  pGammaTPCVsPt_proton_oppo_1020->Add(pGammaTPCVsPt_antiProton_hPos_cent1);
  pGammaTPCVsPt_proton_oppo_1020->Add(pGammaTPCVsPt_antiProton_hPos_cent2);

  pGammaTPCVsPt_proton_same_3040->Add(pGammaTPCVsPt_proton_hPos_cent3);
  pGammaTPCVsPt_proton_same_3040->Add(pGammaTPCVsPt_proton_hPos_cent4);
  pGammaTPCVsPt_proton_same_3040->Add(pGammaTPCVsPt_antiProton_hNeg_cent3);
  pGammaTPCVsPt_proton_same_3040->Add(pGammaTPCVsPt_antiProton_hNeg_cent4);
  pGammaTPCVsPt_proton_oppo_3040->Add(pGammaTPCVsPt_proton_hNeg_cent3);
  pGammaTPCVsPt_proton_oppo_3040->Add(pGammaTPCVsPt_proton_hNeg_cent4);
  pGammaTPCVsPt_proton_oppo_3040->Add(pGammaTPCVsPt_antiProton_hPos_cent3);
  pGammaTPCVsPt_proton_oppo_3040->Add(pGammaTPCVsPt_antiProton_hPos_cent4);


  double xxbins[6] = {0., 0.5, 1., 1.5, 2., 3.};
  TProfile* pGammaTPCVsPt_pion_same_1020_rebin = (TProfile*)pGammaTPCVsPt_pion_same_1020->Rebin(5,"pGammaTPCVsPt_pion_same_1020_rebin",xxbins);
  TProfile* pGammaTPCVsPt_pion_oppo_1020_rebin = (TProfile*)pGammaTPCVsPt_pion_oppo_1020->Rebin(5,"pGammaTPCVsPt_pion_oppo_1020_rebin",xxbins);

  TProfile* pGammaTPCVsPt_pion_same_3040_rebin = (TProfile*)pGammaTPCVsPt_pion_same_3040->Rebin(5,"pGammaTPCVsPt_pion_same_3040_rebin",xxbins);
  TProfile* pGammaTPCVsPt_pion_oppo_3040_rebin = (TProfile*)pGammaTPCVsPt_pion_oppo_3040->Rebin(5,"pGammaTPCVsPt_pion_oppo_3040_rebin",xxbins);


  TProfile* pGammaTPCVsPt_kaon_same_1020_rebin = (TProfile*)pGammaTPCVsPt_kaon_same_1020->Rebin(5,"pGammaTPCVsPt_kaon_same_1020_rebin",xxbins);
  TProfile* pGammaTPCVsPt_kaon_oppo_1020_rebin = (TProfile*)pGammaTPCVsPt_kaon_oppo_1020->Rebin(5,"pGammaTPCVsPt_kaon_oppo_1020_rebin",xxbins);

  TProfile* pGammaTPCVsPt_kaon_same_3040_rebin = (TProfile*)pGammaTPCVsPt_kaon_same_3040->Rebin(5,"pGammaTPCVsPt_kaon_same_3040_rebin",xxbins);
  TProfile* pGammaTPCVsPt_kaon_oppo_3040_rebin = (TProfile*)pGammaTPCVsPt_kaon_oppo_3040->Rebin(5,"pGammaTPCVsPt_kaon_oppo_3040_rebin",xxbins);


  TProfile* pGammaTPCVsPt_proton_same_1020_rebin = (TProfile*)pGammaTPCVsPt_proton_same_1020->Rebin(5,"pGammaTPCVsPt_proton_same_1020_rebin",xxbins);
  TProfile* pGammaTPCVsPt_proton_oppo_1020_rebin = (TProfile*)pGammaTPCVsPt_proton_oppo_1020->Rebin(5,"pGammaTPCVsPt_proton_oppo_1020_rebin",xxbins);

  TProfile* pGammaTPCVsPt_proton_same_3040_rebin = (TProfile*)pGammaTPCVsPt_proton_same_3040->Rebin(5,"pGammaTPCVsPt_proton_same_3040_rebin",xxbins);
  TProfile* pGammaTPCVsPt_proton_oppo_3040_rebin = (TProfile*)pGammaTPCVsPt_proton_oppo_3040->Rebin(5,"pGammaTPCVsPt_proton_oppo_3040_rebin",xxbins);


  TCanvas *plotPIDDiff = new TCanvas("DiffPID", "DiffPID", 1000, 400);
  plotPIDDiff->Divide(2, 1);
  dummy_7->SetTitle("cent 10-30%");
  plotPIDDiff->cd(1);
  dummy_7->Draw("SAME");
  pGammaTPCVsPt_pion_same_1020_rebin->SetLineColor(kBlue);
  pGammaTPCVsPt_pion_same_1020_rebin->SetMarkerColor(kBlue);
  pGammaTPCVsPt_pion_same_1020_rebin->SetMarkerStyle(kFullCircle);
  pGammaTPCVsPt_pion_same_1020_rebin->Draw("SAME");

  pGammaTPCVsPt_kaon_same_1020_rebin->SetLineColor(kGreen);
  pGammaTPCVsPt_kaon_same_1020_rebin->SetMarkerColor(kGreen);
  pGammaTPCVsPt_kaon_same_1020_rebin->SetMarkerStyle(kFullCircle);
  pGammaTPCVsPt_kaon_same_1020_rebin->Draw("SAME");

  pGammaTPCVsPt_proton_same_1020_rebin->SetLineColor(kRed);
  pGammaTPCVsPt_proton_same_1020_rebin->SetMarkerColor(kRed);
  pGammaTPCVsPt_proton_same_1020_rebin->SetMarkerStyle(kFullCircle);
  pGammaTPCVsPt_proton_same_1020_rebin->Draw("SAME");

  pGammaTPCVsPt_pion_oppo_1020_rebin->Draw("SAME");
  pGammaTPCVsPt_kaon_oppo_1020_rebin->Draw("SAME");
  pGammaTPCVsPt_proton_oppo_1020_rebin->Draw("SAME");


  pGammaTPCVsPt_pion_oppo_1020_rebin->SetLineColor(kBlue);
  pGammaTPCVsPt_pion_oppo_1020_rebin->SetMarkerColor(kBlue);
  pGammaTPCVsPt_pion_oppo_1020_rebin->SetMarkerStyle(kOpenSquare);
  pGammaTPCVsPt_pion_oppo_1020_rebin->Draw("SAME");

  pGammaTPCVsPt_kaon_oppo_1020_rebin->SetLineColor(kGreen);
  pGammaTPCVsPt_kaon_oppo_1020_rebin->SetMarkerColor(kGreen);
  pGammaTPCVsPt_kaon_oppo_1020_rebin->SetMarkerStyle(kOpenSquare);
  pGammaTPCVsPt_kaon_oppo_1020_rebin->Draw("SAME");

  pGammaTPCVsPt_proton_oppo_1020_rebin->SetLineColor(kRed);
  pGammaTPCVsPt_proton_oppo_1020_rebin->SetMarkerColor(kRed);
  pGammaTPCVsPt_proton_oppo_1020_rebin->SetMarkerStyle(kOpenSquare);
  pGammaTPCVsPt_proton_oppo_1020_rebin->Draw("SAME");

  dummy_8->SetTitle("cent 30-50%");
  plotPIDDiff->cd(2);
  dummy_8->Draw("SAME");
  pGammaTPCVsPt_pion_same_3040_rebin->SetLineColor(kBlue);
  pGammaTPCVsPt_pion_same_3040_rebin->SetMarkerColor(kBlue);
  pGammaTPCVsPt_pion_same_3040_rebin->SetMarkerStyle(kFullCircle);
  pGammaTPCVsPt_pion_same_3040_rebin->Draw("SAME");

  pGammaTPCVsPt_kaon_same_3040_rebin->SetLineColor(kGreen);
  pGammaTPCVsPt_kaon_same_3040_rebin->SetMarkerColor(kGreen);
  pGammaTPCVsPt_kaon_same_3040_rebin->SetMarkerStyle(kFullCircle);
  pGammaTPCVsPt_kaon_same_3040_rebin->Draw("SAME");

  pGammaTPCVsPt_proton_same_3040_rebin->SetLineColor(kRed);
  pGammaTPCVsPt_proton_same_3040_rebin->SetMarkerColor(kRed);
  pGammaTPCVsPt_proton_same_3040_rebin->SetMarkerStyle(kFullCircle);
  pGammaTPCVsPt_proton_same_3040_rebin->Draw("SAME");

  pGammaTPCVsPt_pion_oppo_3040_rebin->SetLineColor(kBlue);
  pGammaTPCVsPt_pion_oppo_3040_rebin->SetMarkerColor(kBlue);
  pGammaTPCVsPt_pion_oppo_3040_rebin->SetMarkerStyle(kOpenSquare);
  pGammaTPCVsPt_pion_oppo_3040_rebin->Draw("SAME");

  pGammaTPCVsPt_kaon_oppo_3040_rebin->SetLineColor(kGreen);
  pGammaTPCVsPt_kaon_oppo_3040_rebin->SetMarkerColor(kGreen);
  pGammaTPCVsPt_kaon_oppo_3040_rebin->SetMarkerStyle(kOpenSquare);
  pGammaTPCVsPt_kaon_oppo_3040_rebin->Draw("SAME");

  pGammaTPCVsPt_proton_oppo_3040_rebin->SetLineColor(kRed);
  pGammaTPCVsPt_proton_oppo_3040_rebin->SetMarkerColor(kRed);
  pGammaTPCVsPt_proton_oppo_3040_rebin->SetMarkerStyle(kOpenSquare);
  pGammaTPCVsPt_proton_oppo_3040_rebin->Draw("SAME");
}
