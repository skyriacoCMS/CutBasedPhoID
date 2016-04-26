#define SP15_cxx
#include "SP15.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <iomanip>
#include <cstdlib>
#include <iostream>
#include <TMath.h>
#include <vector>
#include <TVector3.h>
#include <TProfile.h>




void SP15::Loop()
{
  TFile *f1 = new TFile("20pt_50ns.root","recreate");
  TTree *t1 = new TTree("t1","EventsTree");

  TH1D *MatchPhos = new TH1D("MatchPhos","# of matched photons in event",5,0,5);


  float gedPhEta,gedPhSCEta,gedPhPt,gedPhPhi,gedPhoIso,gedChgIso,gedNeuIso,gedPhTower,gedPhSieie,Rh,gedGenPt,gedPhweightXS; 
  int gedPhPixSeed,NVtx,gedPhisPrompt,hascorrectPrimV; 
  

  //integer Branches
  t1->Branch("NVtx",&NVtx,"NVtx/I");
  t1->Branch("gedPhPixSeed",&gedPhPixSeed,"gedPhPixSeed/I");
  t1->Branch("gedPhisPrompt",&gedPhisPrompt,"gedPhisPrompt/I");
  t1->Branch("hascorrectPrimV",&hascorrectPrimV,"hascorrectPrimV/I");

  //Float Branches
  t1->Branch("Rh",&Rh,"Rh/F");
  t1->Branch("gedPhSCEta",&gedPhSCEta,"gedPhSCEta/F");
  t1->Branch("gedPhEta",&gedPhEta,"gedPhEta/F");
  t1->Branch("gedPhPhi",&gedPhPhi,"gedPhPhi/F");
  t1->Branch("gedPhPt",&gedPhPt,"gedPhPt/F");
  t1->Branch("gedPhSieie",&gedPhSieie,"gedPhSieie/F");
  t1->Branch("gedPhTower",&gedPhTower,"gedPhTower/F");
  t1->Branch("gedPhoIso",&gedPhoIso,"gedPhoIso/F");
  t1->Branch("gedChgIso",&gedChgIso,"gedChgIso/F");
  t1->Branch("gedNeuIso",&gedNeuIso,"gedNeuIso/F");
  t1->Branch("gedGenPt",&gedGenPt,"gedGenPt/F");
  t1->Branch("gedPhweightXS",&gedPhweightXS,"gedPhweightXS/F");

   if (fChain == 0) return;
   Long64_t nentries = fChain->GetEntriesFast();
   Long64_t nbytes = 0, nb = 0;


   double weightt1 = 1; //7180*0.038/(nentries*0.000103507);
   cout<<"weight of  this sample "<<weightt1<<endl;  
   cout<<"total entries:"<<nentries<<endl;


   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
      if(jentry % 1000 == 0 ) cout<<jentry<<endl;
      int mPHOS = 0;
      int mto1st = 0;
      for(uint ipho = 0; ipho < (*phoEt).size(); ipho++){
	double pEta = (*phoEta)[ipho]; 
	double pPhi = (*phoPhi)[ipho]; 
	Rh = rho;                                                              
        NVtx = nVtx;                                                            
        gedPhPt = (*phoEt)[ipho];                                               
        gedPhEta = pEta;
	gedPhSCEta = (*phoSCEta)[ipho];
        gedPhPhi = pPhi;                                                        
        gedPhSieie = (*phoSigmaIEtaIEtaFull5x5)[ipho];                                 
        gedPhTower = (*phoHoverE)[ipho];                                      
        gedPhoIso = (*phoPFPhoIso)[ipho];                                       
        gedChgIso = (*phoPFChIso)[ipho];                                        
        gedNeuIso = (*phoPFNeuIso)[ipho];                                       
        gedPhPixSeed  = (*phohasPixelSeed)[ipho];                               
        gedPhweightXS = weightt1;       
	int pass = 0;
	int phoispr = 0; 
	double genPt = -1;
	for(uint imc = 0; imc < (*mcPID).size(); imc++){
	  if((*mcPt)[imc] < 15 ) continue;	  
	  if((*mcStatus)[imc] != 1)continue; 
	  if((*mcPID)[imc] != 22)continue;
	  if(TMath::Abs((*mcMomPID)[imc]) >  21 )continue;
	  pass++;
	  double meta = (*mcEta)[imc];
	  double mphi = (*mcPhi)[imc];	  
	  TVector3 mcphoton;
	  TVector3 recoPHOTOn;
	  mcphoton.SetPtEtaPhi(1.0,meta,mphi);
	  recoPHOTOn.SetPtEtaPhi(1.0,pEta,pPhi);			       
	  double DR = mcphoton.DrEtaPhi(recoPHOTOn);
	  double dp = fabs((*mcPt)[imc] - (*phoEt)[ipho] )/(*mcPt)[imc];
	  if(DR < 0.2 && dp < 0.2  ){
	    mPHOS++;
	    if(pass == 1 ){ 
	      genPt = (*mcPt)[imc];
	      phoispr = 1;
	    }
	  }
	}//EOF MC Particles loop 
	gedPhisPrompt = phoispr;
	gedGenPt = genPt; 
	t1->Fill();	
      }//EOF Photon Loop
      MatchPhos->Fill(mPHOS);
   }//EOF EVENT LOOP 
   MatchPhos->Write();
   t1->Write();
}



