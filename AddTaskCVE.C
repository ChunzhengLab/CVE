#if !defined(__CINT__) || defined(__MAKECINT__)
#include "TString.h"
#include "TObjArray.h"

#include "AliLog.h"

#include "AliAnalysisManager.h"
#include "AliAnalysisDataContainer.h"

#include "AliAnalysisTaskCVE.h"
#endif
AliAnalysisTaskCVE* AddTaskCVE(double harmonic = 2.,
                               unsigned int filterBit = 1,
                               double ptMin = 0.2,
                               double ptMax = 5.,
                               double etaMax = 0.8,
                               double nhitsMin = 80,
                               double chi2Max = 4.,
                               double deDxMin = 10,
                               double dcaXyMax = 3.,
                               double dcaZMax = 3.,
                               double v0CPAMin = 0.995,
                               double v0DCAToPrimVtxMax = 1.5,
                               double v0DecayLengthMax = 100.,
                               double v0DecayLengthMin = 3.,
                               double v0DcaBetweenDaughtersMax = 1.,
                               double v0PtMin = 0.5,
                               double v0RapidityMax = 0.5,
                               double daughtersPtMax = 20.,
                               double daughtersEtaMax = 0.8,
                               double daughtersTPCNclsMin = 70,
                               double daughtersDCAToPrimVtxMin = 0.02,
                               double daughtersNsigma = 3.,
                               double massMean = 1.115683,
                               double lambdaMassCut = 0.01,
                               TString uniqueID = "def")
{
    AliAnalysisManager *mgr = AliAnalysisManager::GetAnalysisManager();
    if (!mgr) {
        Error("AddTaskCVE", "No analysis manager to connect to.");
        return NULL;
    }
    if (!mgr->GetInputEventHandler()) {
        Error("AddTaskCVE", "This task requires an input event handler");
        return NULL;
    }

    AliAnalysisTaskCVE* taskD = new AliAnalysisTaskCVE(Form("taskCVE_%s", uniqueID.Data()));
    taskD->SetHarmonic(harmonic);
    taskD->SetFilterbit(filterBit);
    taskD->SetPtMin(ptMin);
    taskD->SetPtMax(ptMax);
    taskD->SetEtaMax(etaMax);
    taskD->SetNhitsMin(nhitsMin);
    taskD->SetChi2Max(chi2Max);
    taskD->SetDeDxMin(deDxMin);
    taskD->SetDcaXyMax(dcaXyMax);
    taskD->SetDcaZMax(dcaZMax);
    taskD->SetV0CPAMin(v0CPAMin);
    taskD->SetV0DCAToPrimVtxMax(v0DCAToPrimVtxMax);
    taskD->SetV0DecayLengthMax(v0DecayLengthMax);
    taskD->SetV0DecayLengthMin(v0DecayLengthMin);
    taskD->SetV0DcaBetweenDaughtersMax(v0DcaBetweenDaughtersMax);
    taskD->SetV0PtMin(v0PtMin);
    taskD->SetV0RapidityMax(v0RapidityMax);
    taskD->SetDaughtersPtMax(daughtersPtMax);
    taskD->SetDaughtersEtaMax(daughtersEtaMax);
    taskD->SetDaughtersTPCNclsMin(daughtersTPCNclsMin);
    taskD->SetDaughtersDCAToPrimVtxMin(daughtersDCAToPrimVtxMin);
    taskD->SetDaughtersNsigma(daughtersNsigma);
    taskD->SetMassMean(massMean);
    taskD->SetLambdaMassCut(lambdaMassCut);
    
    mgr->AddTask(taskD);

    AliAnalysisDataContainer* cinput = mgr->GetCommonInputContainer();
    AliAnalysisDataContainer* cout = mgr->CreateContainer(Form("output_%s", uniqueID.Data()), TList::Class(), AliAnalysisManager::kOutputContainer, Form("AnalysisResults.root:%s", uniqueID.Data()));
    mgr->ConnectInput (taskD, 0, cinput);
    mgr->ConnectOutput(taskD, 1, cout);
  
    // Return task pointer at the end
    return taskD;
}
