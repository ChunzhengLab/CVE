void runGrid(int index=0)
{
  TString mode;
  if (index==0) mode="test";
  if (index==1) mode="full";
  if (index==2) mode="term";
  // Load common libraries
  gSystem->Load("libTree.so");
  gSystem->Load("libGeom.so");
  gSystem->Load("libVMC.so");
  gSystem->Load("libPhysics.so");
  gSystem->Load("libSTEERBase");
  gSystem->Load("libESD");
  gSystem->Load("libAOD");
  gSystem->Load("libANALYSIS");
  gSystem->Load("libANALYSISalice");

  // Use AliRoot includes to compile our task
  gROOT->ProcessLine(".include $ALICE_ROOT/include");
  gROOT->ProcessLine(".include $ALICE_PHYSICS/include");
  gROOT->SetStyle("Plain");

  // Create and configure the alien handler plugin
  // gROOT->LoadMacro("CreateAlienHandler.C");
  AliAnalysisGrid* alienHandler = CreateAlienHandler(mode);  
  if (!alienHandler) return;

  // Create the analysis manager
  AliAnalysisManager* mgr = new AliAnalysisManager("MyAnalysis");

  // Connect plugin to the analysis manager
  mgr->SetGridHandler(alienHandler);

  AliVEventHandler* iH = new AliAODInputHandler();
  // AliAODInputHandler* iH = new AliAODInputHandler();
  // AliESDInputHandler* iH = new AliESDInputHandler(); 
  // esdH->SetInactiveBranches("Calo FMD");
  mgr->SetInputEventHandler(iH);
  
  // MultSelection
  // gROOT->LoadMacro("$ALICE_PHYSICS/OADB/COMMON/MULTIPLICITY/macros/AddTaskMultSelection.C");
  // AliMultSelectionTask* multSel = AddTaskMultSelection();

  // gROOT->LoadMacro("$ALICE_PHYSICS/OADB/macros/AddTaskPhysicsSelection.C");
  // AliPhysicsSelectionTask* physSelTask = AddTaskPhysicsSelection(0,1);

  // PID
  gROOT->LoadMacro("$ALICE_ROOT/ANALYSIS/macros/AddTaskPIDResponse.C");
  AliAnalysisTaskPIDResponse* pid = AddTaskPIDResponse();

  // Task
  gROOT->LoadMacro("AliAnalysisTaskCVE.cxx++g");
  AliAnalysisTaskCVE* task = new AliAnalysisTaskCVE("MyTask");
  // task->SelectCollisionCandidates(AliVEvent::kSemiCentral+AliVEvent::kCentral+AliVEvent::kMB);
  task->SelectCollisionCandidates(AliVEvent::kMB);
  // task->SelectCollisionCandidates(AliVEvent::kINT7);
  mgr->AddTask(task);

  // Create containers for input/output
  AliAnalysisDataContainer* cinput  = mgr->GetCommonInputContainer();
  AliAnalysisDataContainer* coutput = mgr->CreateContainer("output", TList::Class(), 
                                                           AliAnalysisManager::kOutputContainer, 
                                                           mgr->GetCommonFileName());
  // Connect input/output
  mgr->ConnectInput (task, 0, cinput);
  mgr->ConnectOutput(task, 1, coutput);

  // Enable debug printouts
  if (mode=="test") mgr->SetDebugLevel(1);
  else mgr->SetDebugLevel(0);
  if (!mgr->InitAnalysis()) return;
  mgr->PrintStatus();

  // Start analysis in grid.
  if (mode=="test") mgr->StartAnalysis("local");
  else mgr->StartAnalysis("grid");
};

AliAnalysisGrid* CreateAlienHandler(TString mode)
{
  // Check if user has a valid token, otherwise make one. This has limitations.
  // One can always follow the standard procedure of calling alien-token-init then
  //   source /tmp/gclient_env_$UID in the current shell.
  //   if (!AliAnalysisGrid::CreateToken()) return NULL;
  AliAnalysisAlien* plugin = new AliAnalysisAlien();

  // Overwrite all generated files, datasets and output results from a previous session
  plugin->SetOverwriteMode();
  // plugin->SetOverwriteMode(kFALSE);
  // Set the run mode (can be "full", "test", "offline", "submit" or "terminate")
  if (mode=="test") plugin->SetRunMode("test");
  else if (mode=="full") plugin->SetRunMode("full");
  else if (mode=="term") plugin->SetRunMode("terminate");
  plugin->SetOutputToRunNo(kTRUE);
  // merging
  plugin->SetMergeViaJDL(kTRUE);
  plugin->SetMaxMergeStages(2);
  // Set versions of used packages
  plugin->SetAPIVersion("V1.1x");
  // plugin->SetAliPhysicsVersion("vAN-20190723_ROOT6-1");
  plugin->SetAliPhysicsVersion("v5-09-50-01-1");
  // Declare input data to be processed.

  // Method 1: Create automatically XML collections using alien 'find' command.
  // Define production directory LFN

  // plugin->SetGridDataDir("/alice/data/2013/LHC13c");
  // plugin->SetDataPattern("ESDs/pass2/AOD/*/AliAOD.root");
  // plugin->SetRunPrefix("000");
  // plugin->AddRunNumber(195677);
  // plugin->AddRunNumber(195675);
  // plugin->AddRunNumber(195673);
  // plugin->AddRunNumber(195644);
  // plugin->AddRunNumber(195635);
  // plugin->AddRunNumber(195633);
  // plugin->AddRunNumber(195596);
  // plugin->AddRunNumber(195593);
  // plugin->AddRunNumber(195592);
  // plugin->AddRunNumber(195568);
  // plugin->AddRunNumber(195567);
  // plugin->AddRunNumber(195566);
  // plugin->AddRunNumber(195531);
  // plugin->AddRunNumber(195529);
  // LHC15o_pass2_lowIR
  // plugin->SetGridDataDir("/alice/data/2015/LHC15o");
  // plugin->SetDataPattern("*/pass2_lowIR/AOD194/*/AliAOD.root");
  // plugin->SetRunPrefix("000");
  // plugin->AddRunNumber(244917);
  // plugin->AddRunNumber(244918);
  // plugin->AddRunNumber(244975);
  // plugin->AddRunNumber(244980);
  // plugin->AddRunNumber(244982);
  // plugin->AddRunNumber(244983);
  // plugin->AddRunNumber(245061);
  // plugin->AddRunNumber(245064);
  // plugin->AddRunNumber(245066);
  // plugin->AddRunNumber(245068);
  // plugin->AddRunNumber(246390);
  // plugin->AddRunNumber(246391);
  // plugin->AddRunNumber(246392);

  // LHC15o_pass1_CentralBarrelTracking_hadronPID
  // plugin->SetDataPattern("*/pass1/AOD194/*/AliAOD.root");
  // plugin->SetRunPrefix("000");
  // plugin->AddRunNumber(246994);
  // plugin->AddRunNumber(246991);
  // plugin->AddRunNumber(246989);
  // plugin->AddRunNumber(246984);
  // plugin->AddRunNumber(246982);
  // plugin->AddRunNumber(246948);
  // plugin->AddRunNumber(246945);
  // plugin->AddRunNumber(246928);
  // plugin->AddRunNumber(246851);
  // plugin->AddRunNumber(246847);
  // plugin->AddRunNumber(246846);
  // plugin->AddRunNumber(246845);
  // plugin->AddRunNumber(246844);
  // plugin->AddRunNumber(246810);
  // plugin->AddRunNumber(246809);
  // plugin->AddRunNumber(246808);
  // plugin->AddRunNumber(246807);
  // plugin->AddRunNumber(246805);
  // plugin->AddRunNumber(246804);
  // plugin->AddRunNumber(246766);
  // plugin->AddRunNumber(246765);
  // plugin->AddRunNumber(246763);
  // plugin->AddRunNumber(246760);
  // plugin->AddRunNumber(246759);
  // plugin->AddRunNumber(246758);
  // plugin->AddRunNumber(246757);
  // plugin->AddRunNumber(246751);
  // plugin->AddRunNumber(246750);
  // plugin->AddRunNumber(246495);
  // plugin->AddRunNumber(246493);
  // plugin->AddRunNumber(246488);
  // plugin->AddRunNumber(246487);
  // plugin->AddRunNumber(246434);
  // plugin->AddRunNumber(246431);
  // plugin->AddRunNumber(246424);
  // plugin->AddRunNumber(246276);
  // plugin->AddRunNumber(246275);
  // plugin->AddRunNumber(246272);
  // plugin->AddRunNumber(246271);
  // plugin->AddRunNumber(246225);
  // plugin->AddRunNumber(246222);
  // plugin->AddRunNumber(246217);
  // plugin->AddRunNumber(246185);
  // plugin->AddRunNumber(246182);
  // plugin->AddRunNumber(246181);
  // plugin->AddRunNumber(246180);
  // plugin->AddRunNumber(246178);
  // plugin->AddRunNumber(246153);
  // plugin->AddRunNumber(246152);
  // plugin->AddRunNumber(246151);
  // plugin->AddRunNumber(246148);
  // plugin->AddRunNumber(246115);
  // plugin->AddRunNumber(246113);
  // plugin->AddRunNumber(246089);
  // plugin->AddRunNumber(246087);
  // plugin->AddRunNumber(246053);
  // plugin->AddRunNumber(246052);
  // plugin->AddRunNumber(246049);
  // plugin->AddRunNumber(246048);
  // plugin->AddRunNumber(246042);
  // plugin->AddRunNumber(246037);
  // plugin->AddRunNumber(246036);
  // plugin->AddRunNumber(246012);
  // plugin->AddRunNumber(246003);
  // plugin->AddRunNumber(246001);
  // plugin->AddRunNumber(245963);
  // plugin->AddRunNumber(245954);
  // plugin->AddRunNumber(245952);
  // plugin->AddRunNumber(245949);
  // plugin->AddRunNumber(245923);
  // plugin->AddRunNumber(245833);
  // plugin->AddRunNumber(245831);
  // plugin->AddRunNumber(245829);
  // plugin->AddRunNumber(245705);
  // plugin->AddRunNumber(245702);
  // plugin->AddRunNumber(245692);
  // plugin->AddRunNumber(245683);

  //10h
  plugin->SetGridDataDir("/alice/data/2010/LHC10h");
  plugin->SetDataPattern("ESDs/pass2/AOD160/*/AliAOD.root");
  plugin->SetRunPrefix("000");
   //plugin->AddRunNumber(139510); 
   //plugin->AddRunNumber(139507); 
   plugin->AddRunNumber(139505); 
   plugin->AddRunNumber(139503); 
   //plugin->AddRunNumber(139465); 
   //plugin->AddRunNumber(139438); 
   //plugin->AddRunNumber(139437); 
   plugin->AddRunNumber(139360); 
   //plugin->AddRunNumber(139329); 
   plugin->AddRunNumber(139328); 

  //  plugin->AddRunNumber(139314); 
  //  plugin->AddRunNumber(139310);
  //  plugin->AddRunNumber(139309); 
  //  plugin->AddRunNumber(139173); 
  //  plugin->AddRunNumber(139107); 
    plugin->AddRunNumber(139105); 
  //  plugin->AddRunNumber(139038); 
  //  plugin->AddRunNumber(139037); 
  //  plugin->AddRunNumber(139036); 
  //  plugin->AddRunNumber(139029); 
   
   plugin->AddRunNumber(139028); 
   plugin->AddRunNumber(138872); 
   plugin->AddRunNumber(138871); 
   plugin->AddRunNumber(138870);
  // plugin->AddRunNumber(138837); 

  // plugin->AddRunNumber(138732); 
  // plugin->AddRunNumber(138730); 
  // plugin->AddRunNumber(138666); 
  // plugin->AddRunNumber(138662); 
  // plugin->AddRunNumber(138653); 

  // plugin->AddRunNumber(138652); 
  // plugin->AddRunNumber(138638); 
  // plugin->AddRunNumber(138624); 
  // plugin->AddRunNumber(138621); 
  // plugin->AddRunNumber(138583); 
  // plugin->AddRunNumber(138582);

  // plugin->AddRunNumber(138579); 
  // plugin->AddRunNumber(138578); 
  // plugin->AddRunNumber(138534); 
  // plugin->AddRunNumber(138469); 
  // plugin->AddRunNumber(138442); 
  // plugin->AddRunNumber(138439); 

  // plugin->AddRunNumber(138438); 
  // plugin->AddRunNumber(138396); 
  // plugin->AddRunNumber(138364); 
  // plugin->AddRunNumber(138275); 
  // plugin->AddRunNumber(138225); 
  // plugin->AddRunNumber(138201);

  // plugin->AddRunNumber(138197); 
  // plugin->AddRunNumber(138192); 
  // plugin->AddRunNumber(138190); 
   plugin->AddRunNumber(137848); 
  // plugin->AddRunNumber(137844); 
  // plugin->AddRunNumber(137752); 

  // plugin->AddRunNumber(137751); 
   plugin->AddRunNumber(137724); 
  // plugin->AddRunNumber(137722); 
   plugin->AddRunNumber(137718); 
  // plugin->AddRunNumber(137704); 
   plugin->AddRunNumber(137693);

  // plugin->AddRunNumber(137692); 
  // plugin->AddRunNumber(137691); 
  // plugin->AddRunNumber(137686); 
   plugin->AddRunNumber(137685); 
   plugin->AddRunNumber(137639); 
  // plugin->AddRunNumber(137638); 

  // plugin->AddRunNumber(137608); 
  // plugin->AddRunNumber(137595); 
  // plugin->AddRunNumber(137549); 
   plugin->AddRunNumber(137546); 
  // plugin->AddRunNumber(137544); 
  // plugin->AddRunNumber(137541);

  // plugin->AddRunNumber(137539); 
   plugin->AddRunNumber(137531); 
   plugin->AddRunNumber(137530); 
  // plugin->AddRunNumber(137443); 
  // plugin->AddRunNumber(137441); 
  // plugin->AddRunNumber(137440); 

  // plugin->AddRunNumber(137439); 
  // plugin->AddRunNumber(137434); 
  // plugin->AddRunNumber(137432); 
  // plugin->AddRunNumber(137431); 
  // plugin->AddRunNumber(137430); 
  // plugin->AddRunNumber(137243);
  
  // plugin->AddRunNumber(137236); 
  // plugin->AddRunNumber(137235); 
  // plugin->AddRunNumber(137232); 
  // plugin->AddRunNumber(137231); 
  // plugin->AddRunNumber(137162); 
  // plugin->AddRunNumber(137161); 

  // Method 2: Declare existing data files (raw collections, xml collections, root file)
  // If no path mentioned data is supposed to be in the work directory (see SetGridWorkingDir())
  // XML collections added via this method can be combined with the first method if
  // the content is compatible (using or not tags)
  // plugin->AddDataFile("/alice/cern.ch/user/q/qshou/ach_vn/LHC15o_pass1/v2/000246185.xml");

  plugin->SetAdditionalRootLibs("libVMC.so libPhysics.so libTree.so libMinuit.so libProof.so libANALYSIS.so libANALYSISalice.so libANALYSISaliceBase.so libPWGPP.so libSTEERBase.so libOADB.so libESD.so libAOD.so");
  plugin->AddIncludePath("-I. -I$ROOTSYS/include -I$ALICE_ROOT -I$ALICE_ROOT/include  -I$ALICE_ROOT/macros -I$ALICE_ROOT/ANALYSIS -I$ALICE_PHYSICS/include -g");
  // Plugin test mode works only providing a file containing test file locations, used in "local" mode also
  // File should contain path name to a local directory containg *ESDs.root etc
  plugin->SetFileForTestMode("test_PbPb2TeV.list");
  // plugin->SetFileForTestMode("test_pPb5TeV.list");
  // Set number of test files (used in test mode only)
  plugin->SetNtestFiles(3);

  // Define alien work directory where all files will be copied. Relative to alien $HOME.
  plugin->SetGridWorkingDir("Processing");
  // Declare alien output directory. Relative to working directory.
  plugin->SetGridOutputDir("output");
  // Declare the analysis source files names separated by blancs. To be compiled runtime
  // using ACLiC on the worker nodes.
  plugin->SetAnalysisSource("AliAnalysisTaskCVE.cxx");
  // Declare all libraries (other than the default ones for the framework. These will be
  // loaded by the generated analysis macro. Add all extra files (task .cxx/.h) here.
  plugin->SetAdditionalLibs("AliAnalysisTaskCVE.h AliAnalysisTaskCVE.cxx");
  // No need for output file names. Procedure is automatic.
  plugin->SetDefaultOutputs(kFALSE);
  plugin->SetOutputFiles("AnalysisResults.root");
  // No need define the files to be archived. Note that this is handled automatically by the plugin.
  // plugin->SetOutputArchive("log_archive.zip:stdout,stderr");
  // Set a name for the generated analysis macro (default MyAnalysis.C) Make this unique !
  plugin->SetAnalysisMacro("MyAnalysis.C");
  // Optionally set maximum number of input files/subjob (default 100, put 0 to ignore). The optimum for an analysis
  // is correlated with the run time - count few hours TTL per job, not minutes !
  plugin->SetSplitMaxInputFileNumber(100);
  // Optionally set number of failed jobs that will trigger killing waiting sub-jobs.
  plugin->SetMaxInitFailed(50);
  // Optionally resubmit threshold.
  plugin->SetMasterResubmitThreshold(100);
  // Optionally set time to live (default 30000 sec)
  plugin->SetTTL(80000);
  // Optionally set input format (default xml-single)
  plugin->SetInputFormat("xml-single");
  // Optionally modify the name of the generated JDL (default analysis.jdl)
  plugin->SetJDLName("Task.jdl");
  // Optionally modify job price (default 1)
  plugin->SetPrice(1); 
  // Optionally modify split mode (default 'se')    
  plugin->SetSplitMode("se");
  // Optionally turn off testing copying
  plugin->SetCheckCopy(kFALSE);

  return plugin;
}
