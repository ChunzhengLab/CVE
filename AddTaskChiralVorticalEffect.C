// #if !defined(__CINT__) || defined(__MAKECINT__)
// #include "TString.h"
// #include "TObjArray.h"

// #include "AliLog.h"

// #include "AliAnalysisManager.h"
// #include "AliAnalysisDataContainer.h"

// #include "AliAnalysisTaskChiralVorticalEffect.h"
// #endif
AliAnalysisTaskChiralVorticalEffect* AddTaskChiralVorticalEffect(double harmonic = 2.,
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
    // get the manager via the static access member. since it's static, you don't need
    // to create an instance of the class here to call the function
    AliAnalysisManager *mgr = AliAnalysisManager::GetAnalysisManager();
    if (!mgr) {
        Error("AddTaskChiralVorticalEffect", "No analysis manager to connect to.");
        return 0x0;
    }
    // get the input event handler, again via a static method. 
    // this handler is part of the managing system and feeds events
    // to your task
    if (!mgr->GetInputEventHandler()) {
        Error("AddTaskChiralVorticalEffect", "This task requires an input event handler");
        return 0x0;
    }
    
    // now we create an instance of your task
    AliAnalysisTaskChiralVorticalEffect* task = new AliAnalysisTaskChiralVorticalEffect(Form("taskChiralVorticalEffect_%s", uniqueID.Data()));
    if (!task) {
        Error("AddTaskChiralVorticalEffect", "No such class here");
        return 0x0;
    }
    task->SelectCollisionCandidates(AliVEvent::kMB);
    // task->SetHarmonic(harmonic);
    // task->SetFilterbit(filterBit);
    // task->SetPtMin(ptMin);
    // task->SetPtMax(ptMax);
    // task->SetEtaMax(etaMax);
    // task->SetNhitsMin(nhitsMin);
    // task->SetChi2Max(chi2Max);
    // task->SetDeDxMin(deDxMin);
    // task->SetDcaXyMax(dcaXyMax);
    // task->SetDcaZMax(dcaZMax);
    // task->SetV0CPAMin(v0CPAMin);
    // task->SetV0DCAToPrimVtxMax(v0DCAToPrimVtxMax);
    // task->SetV0DecayLengthMax(v0DecayLengthMax);
    // task->SetV0DecayLengthMin(v0DecayLengthMin);
    // task->SetV0DcaBetweenDaughtersMax(v0DcaBetweenDaughtersMax);
    // task->SetV0PtMin(v0PtMin);
    // task->SetV0RapidityMax(v0RapidityMax);
    // task->SetDaughtersPtMax(daughtersPtMax);
    // task->SetDaughtersEtaMax(daughtersEtaMax);
    // task->SetDaughtersTPCNclsMin(daughtersTPCNclsMin);
    // task->SetDaughtersDCAToPrimVtxMin(daughtersDCAToPrimVtxMin);
    // task->SetDaughtersNsigma(daughtersNsigma);
    // task->SetMassMean(massMean);
    // task->SetLambdaMassCut(lambdaMassCut);
    
    // add your task to the manager
    mgr->AddTask(task);

    // Create containers for input/output
    AliAnalysisDataContainer* cinput = mgr->GetCommonInputContainer();
    AliAnalysisDataContainer* cout = mgr->CreateContainer("output", TList::Class(), AliAnalysisManager::kOutputContainer, Form("AnalysisResults.root:%s", uniqueID.Data()));
    // Connect input/output
    mgr->ConnectInput (task, 0, cinput);
    mgr->ConnectOutput(task, 1, cout);
    // in the end, this macro returns a pointer to your task. this will be convenient later on
    // when you will run your analysis in an analysis train on grid

    // Return task pointer at the end
    return task;
}
