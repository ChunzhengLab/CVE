#include "AliAnalysisTaskChiralVorticalEffect.h"
void runAnalysis(int index=0) {
  TString mode;
  mode = "local";
  if (index==0) mode="local";
  if (index==1) mode="grid";
  if (index==2) mode="gridTest";


  cout<<"================================================"<<endl;
  cout<<"Analysis Mode is "<<mode<<"!"<<endl;
  cout<<"================================================"<<endl;

  // since we will compile a class, tell root where to look for headers  
#if !defined (__CINT__) || defined (__CLING__)
    gInterpreter->ProcessLine(".include $ROOTSYS/include");
    gInterpreter->ProcessLine(".include $ALICE_ROOT/include");
#else
    gROOT->ProcessLine(".include $ROOTSYS/include");
    gROOT->ProcessLine(".include $ALICE_ROOT/include");
#endif

  // Create the analysis manager
  AliAnalysisManager* mgr = new AliAnalysisManager("AnalysisTaskExample");
  AliAODInputHandler* aodH = new AliAODInputHandler();
  mgr->SetInputEventHandler(aodH);

  TMacro PIDadd(gSystem->ExpandPathName("$ALICE_ROOT/ANALYSIS/macros/AddTaskPIDResponse.C"));
  AliAnalysisTaskPIDResponse* PIDresponseTask = reinterpret_cast<AliAnalysisTaskPIDResponse*>(PIDadd.Exec());


  // compile the class and load the add task macro
  // here we have to differentiate between using the just-in-time compiler
  // from root6, or the interpreter of root5
#if !defined (__CINT__) || defined (__CLING__)
      gInterpreter->LoadMacro("AliAnalysisTaskChiralVorticalEffect.cxx++g");
      AliAnalysisTaskChiralVorticalEffect *task = reinterpret_cast<AliAnalysisTaskChiralVorticalEffect*>(gInterpreter->ExecuteMacro("AddTaskChiralVorticalEffect.C"));
#else
      gROOT->LoadMacro("AliAnalysisTaskChiralVorticalEffect.cxx++g");    
      gROOT->LoadMacro("AddTaskChiralVorticalEffect.C");
      AliAnalysisTaskMyTask *task = AddMyTask();
#endif

  if(!mgr->InitAnalysis()) return;
  mgr->SetDebugLevel(2);
  mgr->PrintStatus();
  mgr->SetUseProgressBar(1, 25);

  // Enable debug printouts
  if (mode=="local") {
    // if you want to run locally, we need to define some input
    TChain* chain = new TChain("aodTree");
    // add a few files to the chain (change this so that your local files are added)
    chain->Add("../AliAOD.root");
    // start the analysis locally, reading the events from the tchain
    mgr->StartAnalysis("local", chain);
  }

  if (mode=="grid" || mode=="gridTest") {
    // if we want to run on grid, we create and configure the alienHandler
    AliAnalysisAlien *alienHandler = new AliAnalysisAlien();
    // also specify the include (header) paths on grid
    alienHandler->AddIncludePath("-I. -I$ROOTSYS/include -I$ALICE_ROOT -I$ALICE_ROOT/include -I$ALICE_PHYSICS/include");
    // make sure your source files get copied to grid
    alienHandler->SetAdditionalLibs("AliAnalysisTaskChiralVorticalEffect.cxx AliAnalysisTaskChiralVorticalEffect.h");
    alienHandler->SetAnalysisSource("AliAnalysisTaskChiralVorticalEffect.cxx");
    // select the aliphysics version. all other packages
    // are LOADED AUTOMATICALLY!
    alienHandler->SetAliPhysicsVersion("vAN-20181028_ROOT6-1");
    // set the Alien API version
    alienHandler->SetAPIVersion("V1.1x");
    // select the input data
    alienHandler->SetGridDataDir("/alice/data/2010/LHC10h");
    alienHandler->SetDataPattern("ESDs/pass2/AOD160/*/AliAOD.root");
    // MC has no prefix, data has prefix 000
    alienHandler->SetRunPrefix("000");
    // runnumber
    // // alienHandler->AddRunNumber(139510); 
    // // alienHandler->AddRunNumber(139507); 
    // alienHandler->AddRunNumber(139505); 
    // alienHandler->AddRunNumber(139503); 
    // // alienHandler->AddRunNumber(139465); 
    // // alienHandler->AddRunNumber(139438); 
    // // alienHandler->AddRunNumber(139437); 
    // alienHandler->AddRunNumber(139360); 
    // // alienHandler->AddRunNumber(139329); 
    // alienHandler->AddRunNumber(139328); 

    // // alienHandler->AddRunNumber(139314); 
    // // alienHandler->AddRunNumber(139310);
    // // alienHandler->AddRunNumber(139309); 
    // // alienHandler->AddRunNumber(139173); 
    // // alienHandler->AddRunNumber(139107); 
    // alienHandler->AddRunNumber(139105); 
    // // alienHandler->AddRunNumber(139038); 
    // // alienHandler->AddRunNumber(139037); 
    // // alienHandler->AddRunNumber(139036); 
    // // alienHandler->AddRunNumber(139029); 
   
    // alienHandler->AddRunNumber(139028); 
    // alienHandler->AddRunNumber(138872); 
    // alienHandler->AddRunNumber(138871); 
    // alienHandler->AddRunNumber(138870);
    // // alienHandler->AddRunNumber(138837); 

    // // alienHandler->AddRunNumber(138732); 
    // // alienHandler->AddRunNumber(138730); 
    // // alienHandler->AddRunNumber(138666); 
    // // alienHandler->AddRunNumber(138662); 
    // // alienHandler->AddRunNumber(138653); 

    // // alienHandler->AddRunNumber(138652); 
    // // alienHandler->AddRunNumber(138638); 
    // // alienHandler->AddRunNumber(138624); 
    // // alienHandler->AddRunNumber(138621); 
    // // alienHandler->AddRunNumber(138583); 
    // // alienHandler->AddRunNumber(138582);

    // // alienHandler->AddRunNumber(138579); 
    // // alienHandler->AddRunNumber(138578); 
    // // alienHandler->AddRunNumber(138534); 
    // // alienHandler->AddRunNumber(138469); 
    // // alienHandler->AddRunNumber(138442); 
    // // alienHandler->AddRunNumber(138439); 

    // // alienHandler->AddRunNumber(138438); 
    // // alienHandler->AddRunNumber(138396); 
    // // alienHandler->AddRunNumber(138364); 
    // // alienHandler->AddRunNumber(138275); 
    // // alienHandler->AddRunNumber(138225); 
    // // alienHandler->AddRunNumber(138201);

    // // alienHandler->AddRunNumber(138197); 
    // // alienHandler->AddRunNumber(138192); 
    // // alienHandler->AddRunNumber(138190); 
    // alienHandler->AddRunNumber(137848); 
    // // alienHandler->AddRunNumber(137844); 
    // // alienHandler->AddRunNumber(137752); 

    // // alienHandler->AddRunNumber(137751); 
    //  alienHandler->AddRunNumber(137724); 
    // // alienHandler->AddRunNumber(137722); 
    //  alienHandler->AddRunNumber(137718); 
    // // alienHandler->AddRunNumber(137704); 
    //  alienHandler->AddRunNumber(137693);

    // // alienHandler->AddRunNumber(137692); 
    // // alienHandler->AddRunNumber(137691); 
    // // alienHandler->AddRunNumber(137686); 
    //  alienHandler->AddRunNumber(137685); 
    //  alienHandler->AddRunNumber(137639); 
    // // alienHandler->AddRunNumber(137638); 

    // // alienHandler->AddRunNumber(137608); 
    // // alienHandler->AddRunNumber(137595); 
    // // alienHandler->AddRunNumber(137549); 
    //  alienHandler->AddRunNumber(137546); 
    // // alienHandler->AddRunNumber(137544); 
    // // alienHandler->AddRunNumber(137541);

    // // alienHandler->AddRunNumber(137539); 
    //  alienHandler->AddRunNumber(137531); 
     alienHandler->AddRunNumber(137530); 
    // alienHandler->AddRunNumber(137443); 
    // alienHandler->AddRunNumber(137441); 
    // alienHandler->AddRunNumber(137440); 

    // alienHandler->AddRunNumber(137439); 
    // alienHandler->AddRunNumber(137434); 
    // alienHandler->AddRunNumber(137432); 
    // alienHandler->AddRunNumber(137431); 
    // alienHandler->AddRunNumber(137430); 
    // alienHandler->AddRunNumber(137243);
  
    // alienHandler->AddRunNumber(137236); 
    // alienHandler->AddRunNumber(137235); 
    // alienHandler->AddRunNumber(137232); 
    // alienHandler->AddRunNumber(137231); 
    // alienHandler->AddRunNumber(137162); 
    // alienHandler->AddRunNumber(137161); 
    

    // number of files per subjob
    alienHandler->SetSplitMaxInputFileNumber(100);
    alienHandler->SetExecutable("myTask.sh");
    // specify how many seconds your job may take
    alienHandler->SetTTL(80000);
    alienHandler->SetJDLName("myTask.jdl");

    alienHandler->SetOutputToRunNo(kTRUE);
    alienHandler->SetKeepLogs(kTRUE);
    // merging: run with kTRUE to merge on grid
    // after re-running the jobs in SetRunMode("terminate") 
    // (see below) mode, set SetMergeViaJDL(kFALSE) 
    // to collect final results
    alienHandler->SetMaxMergeStages(1);
    alienHandler->SetMergeViaJDL(kTRUE);

    // define the output folders
    alienHandler->SetGridWorkingDir("ChiralVorticalEffect");
    alienHandler->SetGridOutputDir("output");

    // connect the alien plugin to the manager
    mgr->SetGridHandler(alienHandler);

    if(mode=="gridTest") {
      // speficy on how many files you want to run
      alienHandler->SetNtestFiles(1);
      // and launch the analysis
      alienHandler->SetRunMode("test");
      mgr->StartAnalysis("grid");
    }
    if(mode=="grid"){
      // else launch the full grid analysis
      alienHandler->SetRunMode("full");
      mgr->StartAnalysis("grid");
    }
  }
}
