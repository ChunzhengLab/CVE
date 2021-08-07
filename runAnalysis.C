#include "AliAnalysisTaskChiralVorticalEffect.h"
void runGrid(int index=0)
{
  TString mode;
  if (index==0) mode="test";
  if (index==1) mode="full";
  if (index==2) mode="term";
  mode = "test";
  // // Load common libraries
  // gSystem->Load("libTree.so");
  // gSystem->Load("libGeom.so");
  // gSystem->Load("libVMC.so");
  // gSystem->Load("libPhysics.so");
  // gSystem->Load("libSTEERBase");
  // gSystem->Load("libESD");
  // gSystem->Load("libAOD");
  // gSystem->Load("libANALYSIS");
  // gSystem->Load("libANALYSISalice");

  // since we will compile a class, tell root where to look for headers  
  #if !defined (__CINT__) || defined (__CLING__)
      gInterpreter->ProcessLine(".include $ROOTSYS/include");
      gInterpreter->ProcessLine(".include $ALICE_ROOT/include");
  #endif


  // Create the analysis manager
  AliAnalysisManager* mgr = new AliAnalysisManager("AnalysisTaskExample");
  AliAODInputHandler* iH = new AliAODInputHandler();
  mgr->SetInputEventHandler(iH);

  TMacro PIDadd(gSystem->ExpandPathName("$ALICE_ROOT/ANALYSIS/macros/AddTaskPIDResponse.C"));
  AliAnalysisTaskPIDResponse* PIDresponseTask = reinterpret_cast<AliAnalysisTaskPIDResponse*>(PIDadd.Exec());
  // Task
  // compile the class and load the add task macro
  // here we have to differentiate between using the just-in-time compiler
  // from root6, or the interpreter of root5
#if !defined (__CINT__) || defined (__CLING__)
    gInterpreter->LoadMacro("AliAnalysisTaskCVE.cxx++g");
    AliAnalysisTaskCVE *task = reinterpret_cast<AliAnalysisTaskCVE*>(gInterpreter->ExecuteMacro("AddTaskCVE.C"));
#endif

    if(!mgr->InitAnalysis()) return;
    mgr->SetDebugLevel(2);
    mgr->PrintStatus();
    mgr->SetUseProgressBar(1, 25);

  // // Create containers for input/output
  // AliAnalysisDataContainer* cinput  = mgr->GetCommonInputContainer();
  // AliAnalysisDataContainer* coutput = mgr->CreateContainer("output", TList::Class(), 
  //                                                          AliAnalysisManager::kOutputContainer, 
  //                                                          mgr->GetCommonFileName());
  // // Connect input/output
  // mgr->ConnectInput (task, 0, cinput);
  // mgr->ConnectOutput(task, 1, coutput);

  // Enable debug printouts
  if (mode=="test") {
    // if you want to run locally, we need to define some input
    TChain* chain = new TChain("aodTree");
    // add a few files to the chain (change this so that your local files are added)
    chain->Add("./AliAOD.root");
    // start the analysis locally, reading the events from the tchain
    mgr->StartAnalysis("local", chain);
  }
};
