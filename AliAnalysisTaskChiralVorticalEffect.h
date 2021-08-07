#ifndef AliAnalysisTaskChiralVorticalEffect_cxx
#define AliAnalysisTaskChiralVorticalEffect_cxx

//class TList;
//class TH1F;
//class TH2F;
//class TProfile;
//class AliAnalysisUtils;

#include "AliAnalysisTaskSE.h"

using std::cout;
using std::endl;

class AliAnalysisTaskChiralVorticalEffect : public AliAnalysisTaskSE
{
public:
  AliAnalysisTaskChiralVorticalEffect();
  AliAnalysisTaskChiralVorticalEffect(const char *name);
  virtual ~AliAnalysisTaskChiralVorticalEffect();

  virtual void UserCreateOutputObjects();
  virtual void UserExec(Option_t *option);
  virtual void Terminate(Option_t *);

  virtual void SetHarmonic(double harmonic) { mHarmonic = harmonic; }
  virtual void SetFilterbit(unsigned int filterbit) { fFilterBit = filterbit; }
  virtual void SetPtMin(double ptMin) { fPtMin = ptMin; }
  virtual void SetPtMax(double ptMax) { fPtMax = ptMax; }
  virtual void SetEtaMax(double etaMax) { fEtaMax = etaMax; }
  virtual void SetNhitsMin(double nhitsMin) { fNhitsMin = nhitsMin; }
  virtual void SetChi2Max(double chi2Max) { fChi2Max = chi2Max; }
  virtual void SetDeDxMin(double deDxMin) { fDeDxMin = deDxMin; }
  virtual void SetDcaXyMax(double dcaXyMax) { fDcaXyMax = dcaXyMax; }
  virtual void SetDcaZMax(double dcaZMax) { fDcaZMax = dcaZMax; }

  virtual void SetV0CPAMin(double v0CPAMin) { fV0CPAMin = v0CPAMin; }
  virtual void SetV0DCAToPrimVtxMax(double v0DCAToPrimVtxMax) { fV0DCAToPrimVtxMax = v0DCAToPrimVtxMax; }
  virtual void SetV0DecayLengthMax(double v0DecayLengthMax) { fV0DecayLengthMax = v0DecayLengthMax; }
  virtual void SetV0DecayLengthMin(double v0DecayLengthMin) { fV0DecayLengthMin = v0DecayLengthMin; }
  virtual void SetV0DcaBetweenDaughtersMax(double v0DcaBetweenDaughtersMax) { fV0DcaBetweenDaughtersMax = v0DcaBetweenDaughtersMax; }
  virtual void SetV0PtMin(double v0PtMin) { fV0PtMin = v0PtMin; }
  virtual void SetV0RapidityMax(double v0RapidityMax) { fV0RapidityMax = v0RapidityMax; }

  virtual void SetDaughtersPtMax(double daughtersPtMax) { fDaughtersPtMax = daughtersPtMax; }
  virtual void SetDaughtersEtaMax(double daughtersEtaMax) { fDaughtersEtaMax = daughtersEtaMax; }
  virtual void SetDaughtersTPCNclsMin(double daughtersTPCNclsMin) { fDaughtersTPCNclsMin = daughtersTPCNclsMin; }
  virtual void SetDaughtersDCAToPrimVtxMin(double daughtersDCAToPrimVtxMin) { fDaughtersDCAToPrimVtxMin = daughtersDCAToPrimVtxMin; }
  virtual void SetDaughtersNsigma(double daughtersNsigma) { fDaughtersNsigma = daughtersNsigma; }

  virtual void SetMassMean(double massMean) { fMassMean = massMean; }
  virtual void SetLambdaMassCut(double lambdaMassCut) { fLambdaMassCut = lambdaMassCut; }

private:
  AliAODEvent*            fAOD;           //! input event
  TList*                  fOutputList;    //! output list

  double mHarmonic;
  unsigned int fFilterBit;
  double fPtMin;
  double fPtMax;
  double fEtaMax;
  double fNhitsMin;
  double fChi2Max;
  double fDeDxMin;
  double fDcaXyMax;
  double fDcaZMax;

  double fV0CPAMin;
  double fV0DCAToPrimVtxMax;
  double fV0DecayLengthMax;
  double fV0DecayLengthMin;
  double fV0DcaBetweenDaughtersMax;
  double fV0PtMin;
  double fV0RapidityMax;

  double fDaughtersPtMax;
  double fDaughtersEtaMax;
  double fDaughtersTPCNclsMin;
  double fDaughtersDCAToPrimVtxMin;
  double fDaughtersNsigma;

  double fMassMean;
  double fLambdaMassCut;

  int GetRunNumBin(int runNum);
  bool IsGoodV0(AliAODv0 *v0);
  bool IsGoodDaughterTrack(const AliAODTrack *t);

  int runNum;
  int runNumBin;
  double vtx[3];
  int vzBin;
  double cent;
  int centBin;

  //Event-wise
  TH1I *hEvtCount;
  TH1I *hRunNumBin;
  TH1D *hCent;
  TH2D *hCentCorr[2];
  TH2D *hVxy[2];
  TH1D *hVz[2];

  //Random Event Plane
  TH3D *hPsi2RDM;
  TH3D *hPsi3RDM;
  //TPC Event Plane
  TH3D *hPsi2TPC;
  TH3D *hPsi3TPC;

  // Track-wise
  TH1D *hPt[2];
  TH1D *hEta[2];
  TH1D *hPhi[2];
  TH1D *hNhits[2];
  TH1D *hDcaXy[2];
  TH1D *hDcaZ[2];
  TH2D *hPDedx;

  //V0-wise
  TH1D *hV0Pt;
  TH1D *hV0Eta;
  TH1D *hV0DcaToPrimVertex;
  TH1D *hV0CPA;
  TH1D *hV0DecayLength;

  TH1D *hLambdaPt[2];
  TH1D *hLambdaEta[2];
  TH1D *hLambdaDcaToPrimVertex[2];
  TH1D *hLambdaCPA[2];
  TH1D *hLambdaDecayLength[2];
  TH1D *hLambdaMass[2];
  TH1D *hLambdaMassCent[10];

  TH1D *hAntiLambdaPt[2];
  TH1D *hAntiLambdaEta[2];
  TH1D *hAntiLambdaDcaToPrimVertex[2];
  TH1D *hAntiLambdaCPA[2];
  TH1D *hAntiLambdaDecayLength[2];
  TH1D *hAntiLambdaMass[2];
  TH1D *hAntiLambdaMassCent[10];

  //Inclusive
  //Delta
  TProfile *pDelta_hPos_hPos;
  TProfile *pDelta_hNeg_hNeg;
  TProfile *pDelta_hPos_hNeg;
  //Gamma
  //TPC Plane
  TProfile *pGammaTPC_hPos_hPos;
  TProfile *pGammaTPC_hNeg_hNeg;
  TProfile *pGammaTPC_hPos_hNeg;
  TProfile *pCosCosTPC_hPos_hPos;
  TProfile *pCosCosTPC_hNeg_hNeg;
  TProfile *pCosCosTPC_hPos_hNeg;
  TProfile *pSinSinTPC_hPos_hPos;
  TProfile *pSinSinTPC_hNeg_hNeg;
  TProfile *pSinSinTPC_hPos_hNeg;
  //Random Plane
  TProfile *pGammaRDM_hPos_hPos;
  TProfile *pGammaRDM_hNeg_hNeg;
  TProfile *pGammaRDM_hPos_hNeg;
  TProfile *pCosCosRDM_hPos_hPos;
  TProfile *pCosCosRDM_hNeg_hNeg;
  TProfile *pCosCosRDM_hPos_hNeg;
  TProfile *pSinSinRDM_hPos_hPos;
  TProfile *pSinSinRDM_hNeg_hNeg;
  TProfile *pSinSinRDM_hPos_hNeg;
  //Diff
  TProfile *pGammaTPCVsDeltaPt_hPos_hPos[10];
  TProfile *pGammaTPCVsDeltaPt_hPos_hNeg[10];
  TProfile *pGammaTPCVsDeltaPt_hNeg_hNeg[10];

  TProfile *pGammaTPVVsMeanPt_hPos_hPos[10];
  TProfile *pGammaTPVVsMeanPt_hPos_hNeg[10];
  TProfile *pGammaTPVVsMeanPt_hNeg_hNeg[10];

  TProfile *pGammaTPCVsDeltaEta_hPos_hPos[10];
  TProfile *pGammaTPCVsDeltaEta_hPos_hNeg[10];
  TProfile *pGammaTPCVsDeltaEta_hNeg_hNeg[10];

  //pion - Inclusive
  // pi+ - h+
  TProfile *pDelta_pion_hPos;
  TProfile *pGammaTPC_pion_hPos;
  TProfile *pGammaRDM_pion_hPos;
  TProfile *pGammaTPCVsPt_pion_hPos[10];
  // pi- - h+
  TProfile *pDelta_antiPion_hPos;
  TProfile *pGammaTPC_antiPion_hPos;
  TProfile *pGammaRDM_antiPion_hPos;
  TProfile *pGammaTPCVsPt_antiPion_hPos[10];
  // pi+ - h-
  TProfile *pDelta_pion_hNeg;
  TProfile *pGammaTPC_pion_hNeg;
  TProfile *pGammaRDM_pion_hNeg;
  TProfile *pGammaTPCVsPt_pion_hNeg[10];
  // pi- - h-
  TProfile *pDelta_antiPion_hNeg;
  TProfile *pGammaTPC_antiPion_hNeg;
  TProfile *pGammaRDM_antiPion_hNeg;
  TProfile *pGammaTPCVsPt_antiPion_hNeg[10];
  //kaon - Inclusive
  // ka+ - h+
  TProfile *pDelta_kaon_hPos;
  TProfile *pGammaTPC_kaon_hPos;
  TProfile *pGammaRDM_kaon_hPos;
  TProfile *pGammaTPCVsPt_kaon_hPos[10];
  // ka- - h+
  TProfile *pDelta_antiKaon_hPos;
  TProfile *pGammaTPC_antiKaon_hPos;
  TProfile *pGammaRDM_antiKaon_hPos;
  TProfile *pGammaTPCVsPt_antiKaon_hPos[10];
  // ka+ - h-
  TProfile *pDelta_kaon_hNeg;
  TProfile *pGammaTPC_kaon_hNeg;
  TProfile *pGammaRDM_kaon_hNeg;
  TProfile *pGammaTPCVsPt_kaon_hNeg[10];
  // ka- - h-
  TProfile *pDelta_antiKaon_hNeg;
  TProfile *pGammaTPC_antiKaon_hNeg;
  TProfile *pGammaRDM_antiKaon_hNeg;
  TProfile *pGammaTPCVsPt_antiKaon_hNeg[10];
  //proton - Inclusive
  // p+ - h+
  TProfile *pDelta_proton_hPos;
  TProfile *pGammaTPC_proton_hPos;
  TProfile *pGammaRDM_proton_hPos;
  TProfile *pGammaTPCVsPt_proton_hPos[10];
  // p- - h+
  TProfile *pDelta_antiProton_hPos;
  TProfile *pGammaTPC_antiProton_hPos;
  TProfile *pGammaRDM_antiProton_hPos;
  TProfile *pGammaTPCVsPt_antiProton_hPos[10];
  // p+ - h-
  TProfile *pDelta_proton_hNeg;
  TProfile *pGammaTPC_proton_hNeg;
  TProfile *pGammaRDM_proton_hNeg;
  TProfile *pGammaTPCVsPt_proton_hNeg[10];
  // p- - h-
  TProfile *pDelta_antiProton_hNeg;
  TProfile *pGammaTPC_antiProton_hNeg;
  TProfile *pGammaRDM_antiProton_hNeg;
  TProfile *pGammaTPCVsPt_antiProton_hNeg[10];

  //pion - pion
  //pi+ - pi+
  TProfile *pDelta_pion_pion;
  TProfile *pGammaTPC_pion_pion;
  TProfile *pGammaRDM_pion_pion;
  //pi- - pi-
  TProfile *pDelta_antiPion_antiPion;
  TProfile *pGammaTPC_antiPion_antiPion;
  TProfile *pGammaRDM_antiPion_antiPion;
  //pi+ - pi-
  TProfile *pDelta_pion_antiPion;
  TProfile *pGammaTPC_pion_antiPion;
  TProfile *pGammaRDM_pion_antiPion;
  //kaon - kaon
  //ka+ - ka+
  TProfile *pDelta_kaon_kaon;
  TProfile *pGammaTPC_kaon_kaon;
  TProfile *pGammaRDM_kaon_kaon;
  //ka- - ka-
  TProfile *pDelta_antiKaon_antiKaon;
  TProfile *pGammaTPC_antiKaon_antiKaon;
  TProfile *pGammaRDM_antiKaon_antiKaon;
  //ka+ - ka-
  TProfile *pDelta_kaon_antiKaon;
  TProfile *pGammaTPC_kaon_antiKaon;
  TProfile *pGammaRDM_kaon_antiKaon;
  //proton - proton
  //p+ - p+
  TProfile *pDelta_proton_proton;
  TProfile *pGammaTPC_proton_proton;
  TProfile *pGammaRDM_proton_proton;
  //p- - p-
  TProfile *pDelta_antiProton_antiProton;
  TProfile *pGammaTPC_antiProton_antiProton;
  TProfile *pGammaRDM_antiProton_antiProton;
  //p+ - p-
  TProfile *pDelta_proton_antiProton;
  TProfile *pGammaTPC_proton_antiProton;
  TProfile *pGammaRDM_proton_antiProton;

  //pion - kaon
  // pi+ - k+
  TProfile *pDelta_pion_kaon;
  TProfile *pGammaTPC_pion_kaon;
  TProfile *pGammaRDM_pion_kaon;
  // pi- - k+
  TProfile *pDelta_antiPion_kaon;
  TProfile *pGammaTPC_antiPion_kaon;
  TProfile *pGammaRDM_antiPion_kaon;
  // pi+ - k-
  TProfile *pDelta_pion_antiKaon;
  TProfile *pGammaTPC_pion_antiKaon;
  TProfile *pGammaRDM_pion_antiKaon;
  // pi- - k-
  TProfile *pDelta_antiPion_antiKaon;
  TProfile *pGammaTPC_antiPion_antiKaon;
  TProfile *pGammaRDM_antiPion_antiKaon;
  //kaon - proton
  // k+ - p+
  TProfile *pDelta_kaon_proton;
  TProfile *pGammaTPC_kaon_proton;
  TProfile *pGammaRDM_kaon_proton;
  // k- - p+
  TProfile *pDelta_antiKaon_proton;
  TProfile *pGammaTPC_antiKaon_proton;
  TProfile *pGammaRDM_antiKaon_proton;
  // k+ - p-
  TProfile *pDelta_kaon_antiProton;
  TProfile *pGammaTPC_kaon_antiProton;
  TProfile *pGammaRDM_kaon_antiProton;
  // k- - p-
  TProfile *pDelta_antiKaon_antiProton;
  TProfile *pGammaTPC_antiKaon_antiProton;
  TProfile *pGammaRDM_antiKaon_antiProton;
  //proton - pi
  // p+ - pi+
  TProfile *pDelta_proton_pion;
  TProfile *pGammaTPC_proton_pion;
  TProfile *pGammaRDM_proton_pion;
  // p- - pi+
  TProfile *pDelta_antiProton_pion;
  TProfile *pGammaTPC_antiProton_pion;
  TProfile *pGammaRDM_antiProton_pion;
  // p+ - pi-
  TProfile *pDelta_proton_antiPion;
  TProfile *pGammaTPC_proton_antiPion;
  TProfile *pGammaRDM_proton_antiPion;
  // p- - pi-
  TProfile *pDelta_antiProton_antiPion;
  TProfile *pGammaTPC_antiProton_antiPion;
  TProfile *pGammaRDM_antiProton_antiPion;

  //lambda - h
  //lambda - h+
  TProfile *pDelta_lambda_hPos;
  TProfile *pGammaTPC_lambda_hPos;
  TProfile *pGammaRDM_lambda_hPos;
  //antiLambda - h+
  TProfile *pDelta_antiLambda_hPos;
  TProfile *pGammaTPC_antiLambda_hPos;
  TProfile *pGammaRDM_antiLambda_hPos;
  //lambda - h-
  TProfile *pDelta_lambda_hNeg;
  TProfile *pGammaTPC_lambda_hNeg;
  TProfile *pGammaRDM_lambda_hNeg;
  //antiLambda - h-
  TProfile *pDelta_antiLambda_hNeg;
  TProfile *pGammaTPC_antiLambda_hNeg;
  TProfile *pGammaRDM_antiLambda_hNeg;

  //lambda - p
  //lambda - p+
  TProfile *pDelta_lambda_proton;
  TProfile *pGammaTPC_lambda_proton;
  TProfile *pGammaRDM_lambda_proton;
  //antiLambda - p+
  TProfile *pDelta_antiLambda_proton;
  TProfile *pGammaTPC_antiLambda_proton;
  TProfile *pGammaRDM_antiLambda_proton;
  //lambda - p-
  TProfile *pDelta_lambda_antiProton;
  TProfile *pGammaTPC_lambda_antiProton;
  TProfile *pGammaRDM_lambda_antiProton;
  //antiLambda - p-
  TProfile *pDelta_antiLambda_antiProton;
  TProfile *pGammaTPC_antiLambda_antiProton;
  TProfile *pGammaRDM_antiLambda_antiProton;

  AliAnalysisTaskChiralVorticalEffect(const AliAnalysisTaskChiralVorticalEffect &);
  AliAnalysisTaskChiralVorticalEffect &operator=(const AliAnalysisTaskChiralVorticalEffect &);

  ClassDef(AliAnalysisTaskChiralVorticalEffect, 1);
};
#endif