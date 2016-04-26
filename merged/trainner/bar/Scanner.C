 
#include <cstdlib>
#include <iostream> 
#include <map>
#include <string>
#include "TChain.h"
#include "TFile.h"
#include "TTree.h"
#include "TString.h"
#include "TObjString.h"
#include "TSystem.h"
#include "TROOT.h"
#include "TMVA/GeneticAlgorithm.h"
#include "TMVA/GeneticFitter.h"
#include "TMVA/IFitterTarget.h"
#include "TMVA/Tools.h"
#include "TMVA/Factory.h"


#include <sstream>
#include <string.h>


void Scanner(){

  ofstream myfileP;
  ofstream myfileC;
  ofstream myfileN;
  ofstream myfileS;
  ofstream myfileT;
 
  TString outfileName( "Scanner.root" );
  TFile* outputFile = TFile::Open( outfileName, "RECREATE" );


  TH1F *isoCs = new TH1F("isoCs","Charge Is",100,0,100);
  TH1F *isoPs = new TH1F("isoPs","Charge Is",100,0,100);
  TH1F *isoNs = new TH1F("isoNs","Charge Is",100,0,100);

  TH1F *isoCb = new TH1F("isoCb","Charge Is",100,0,100);
  TH1F *isoPb = new TH1F("isoPb","Charge Is",100,0,100);
  TH1F *isoNb = new TH1F("isoNb","Charge Is",100,0,100);

  
  TH1F *isoCs14 = new TH1F("isoCs14","Charge Is",100,0,100);
  TH1F *isoPs14 = new TH1F("isoPs14","Charge Is",100,0,100);
  TH1F *isoNs14 = new TH1F("isoNs14","Charge Is",100,0,100);

  TH1F *isoCb14 = new TH1F("isoCb14","Charge Is",100,0,100);
  TH1F *isoPb14 = new TH1F("isoPb14","Charge Is",100,0,100);
  TH1F *isoNb14 = new TH1F("isoNb14","Charge Is",100,0,100);




  //Input file:
  TString fname = "../CutTMVATrees_Barrel.root";
  input = TFile::Open( fname );
  
  // --- Register the regression tree
  float Sie_ie,iso_P,iso_C,iso_N,to_e,weightPT,weightXS;
  
  t_S->SetBranchAddress("Sieie",&Sie_ie);
  t_S->SetBranchAddress("isoP",&iso_P);
  t_S->SetBranchAddress("isoC",&iso_C);
  t_S->SetBranchAddress("isoN",&iso_N);
  t_S->SetBranchAddress("ToE",&to_e);
  t_S->SetBranchAddress("weightPT",&weightPT);
  t_S->SetBranchAddress("weightXS",&weightXS);


  
  t_B->SetBranchAddress("Sieie",&Sie_ie);
  t_B->SetBranchAddress("isoP",&iso_P);
  t_B->SetBranchAddress("isoC",&iso_C);
  t_B->SetBranchAddress("isoN",&iso_N);
  t_B->SetBranchAddress("ToE",&to_e);
  t_B->SetBranchAddress("weightPT",&weightPT);
  t_B->SetBranchAddress("weightXS",&weightXS);


  double totS = 0; 
  for(int i  = 0 ; i < t_S->GetEntries(); i++){
    t_S->GetEntry(i);
    totS = totS+ weightPT*weightXS;


    /*
    isoCs->Fill(iso_C,weightPT*weightXS);
    isoPs->Fill(iso_P,weightPT*weightXS);
    isoNs->Fill(iso_N,weightPT*weightXS);
    */

    
    isoCs->Fill(iso_C);
    isoPs->Fill(iso_P);
    isoNs->Fill(iso_N);


 

  }

  


  double totB = 0; 
  for(int i  = 0 ; i < t_B->GetEntries(); i++){
    t_B->GetEntry(i);
    totB = totB+ weightPT*weightXS;



    
    isoCb->Fill(iso_C,weightPT*weightXS);
    isoPb->Fill(iso_P,weightPT*weightXS);
    isoNb->Fill(iso_N,weightPT*weightXS);
    


    
    /*
    isoCb->Fill(iso_C);
    isoPb->Fill(iso_P);
    isoNb->Fill(iso_N);
    */

 }



  cout<<"Done Calculating the ACTUAL TOTALS"<<endl;
 


  

  



  TString fname2 = "../../BX50/CutTMVATrees_Barrel.root";
  input2 = TFile::Open( fname2 );
  
  input2->cd();
  
  // --- Register the regression tree
  float Sie_ie2,iso_P2,iso_C2,iso_N2,to_e2,weightPT2,weightXS2;
  int Nvtx;
  

  t_S->SetBranchAddress("Sieie",&Sie_ie2);
  t_S->SetBranchAddress("isoP",&iso_P2);
  t_S->SetBranchAddress("isoC",&iso_C2);
  t_S->SetBranchAddress("isoN",&iso_N2);
  t_S->SetBranchAddress("ToE",&to_e2);
  t_S->SetBranchAddress("weightPT",&weightPT2);
  t_S->SetBranchAddress("weightXS",&weightXS2);
  t_S->SetBranchAddress("Nvtx",&Nvtx);


  
  t_B->SetBranchAddress("Sieie",&Sie_ie2);
  t_B->SetBranchAddress("isoP",&iso_P2);
  t_B->SetBranchAddress("isoC",&iso_C2);
  t_B->SetBranchAddress("isoN",&iso_N2);
  t_B->SetBranchAddress("ToE",&to_e2);
  t_B->SetBranchAddress("weightPT",&weightPT2);
  t_B->SetBranchAddress("weightXS",&weightXS2);
  t_B->SetBranchAddress("Nvtx",&Nvtx);


  
 
  for(int i  = 0 ; i < t_S->GetEntries(); i++){
    t_S->GetEntry(i);
    
    //  if(Nvtx > 20) continue;
   
        isoCs14->Fill(iso_C2,weightPT2*weightXS2);
	isoPs14->Fill(iso_P2,weightPT2*weightXS2);
	isoNs14->Fill(iso_N2,weightPT2*weightXS2);
   



    // isoCs14->Fill(iso_C2);
    //  isoPs14->Fill(iso_P2);
    //  isoNs14->Fill(iso_N2);
  }

  


 
  for(int i  = 0 ; i < t_B->GetEntries(); i++){
    t_B->GetEntry(i);
    
    //    if(Nvtx > 20) continue;
    

    isoCb14->Fill(iso_C2,weightPT2*weightXS2);
    isoPb14->Fill(iso_P2,weightPT2*weightXS2);
    isoNb14->Fill(iso_N2,weightPT2*weightXS2);

    
    //    isoCb14->Fill(iso_C2);
    //  isoPb14->Fill(iso_P2);
    //  isoNb14->Fill(iso_N2);

  }
   
  double isoPEf[100]= {0};
  //ouble sieieEf[100]= {0};
  double isoCEf[100]= {0};  
  double isoNEf[100]= {0};
  //double toeEf[100]= {0};

  
  double isoPB[100] = {0};
  //  double sieieB[100]= {0};
  double isoCB[100]= {0};  
  double isoNB[100]= {0};
  // double toeB[100]= {0};

  
  double isoPEf2[100]= {0};
  //ouble sieieEf[100]= {0};
  double isoCEf2[100]= {0};  
  double isoNEf2[100]= {0};
  //double toeEf[100]= {0};

  
  double isoPB2[100] = {0};
  //  double sieieB[100]= {0};
  double isoCB2[100]= {0};  
  double isoNB2[100]= {0};
  // double toeB[100]= {0};








  for(int i  = 0; i < 100; i ++){
    if(i % 10 == 0) cout<<i/100.0<<"%"<<endl;
    
    double isopx = 40.0*i/100;
    double isocx = 40.0*i/100;
    double isonx = 40.0*i/100;
    


    double passisoP = 0;
    double passisoC = 0;
    double passisoN = 0;
  
    double passisoP2 = 0;
    double passisoC2 = 0;
    double passisoN2 = 0;
  


  int bin = isoPs->FindBin(isopx);
    passisoP = isoPs->Integral(0,bin)*1.0/isoPs->Integral(0,100);
    passisoC = isoCs->Integral(0,bin)*1.0/isoCs->Integral(0,100);
    passisoN = isoNs->Integral(0,bin)*1.0/isoNs->Integral(0,100);
 
            
    isoPEf[i] =passisoP ;
    isoCEf[i] =passisoC ;   
    isoNEf[i] =passisoN ;


    passisoP2 = isoPs14->Integral(0,bin)*1.0/isoPs14->Integral(0,100);
    passisoC2 = isoCs14->Integral(0,bin)*1.0/isoCs14->Integral(0,100);
    passisoN2 = isoNs14->Integral(0,bin)*1.0/isoNs14->Integral(0,100);
 
            
    isoPEf2[i] =passisoP2 ;
    isoCEf2[i] =passisoC2 ;   
    isoNEf2[i] =passisoN2 ;




    
    passisoP = isoPb->Integral(0,bin)*1.0/isoPb->Integral(0,100);
    passisoC = isoCb->Integral(0,bin)*1.0/isoCb->Integral(0,100);
    passisoN = isoNb->Integral(0,bin)*1.0/isoNb->Integral(0,100);
 
      
    isoPB[i] =1 -  passisoP;
    isoCB[i] =1 -  passisoC;   
    isoNB[i] =1  - passisoN;
   
    
    passisoP2 = isoPb14->Integral(0,bin)*1.0/isoPb14->Integral(0,100);
    passisoC2 = isoCb14->Integral(0,bin)*1.0/isoCb14->Integral(0,100);
    passisoN2 = isoNb14->Integral(0,bin)*1.0/isoNb14->Integral(0,100);
 
      
    isoPB2[i] =1 -  passisoP2;
    isoCB2[i] =1 -  passisoC2;   
    isoNB2[i] =1  - passisoN2;
   



    
    myfileP<<isoPB[i]<<" "<<isoPEf[i]<<" "<<isopx<<endl;
    myfileC<<isoCB[i]<<" "<<isoCEf[i]<<" "<<isocx<<endl;
    myfileN<<isoNB[i]<<" "<<isoNEf[i]<<" "<<isonx<<endl;
       
    
  }//eof filling up the rocs
  
  TGraph *Rp = new TGraph(100,isoPB,isoPEf);
  TGraph *Rc = new TGraph(100,isoCB,isoCEf);
  TGraph *Rn = new TGraph(100,isoNB,isoNEf);

  TGraph *Rp2 = new TGraph(100,isoPB2,isoPEf2);
  TGraph *Rc2 = new TGraph(100,isoCB2,isoCEf2);
  TGraph *Rn2 = new TGraph(100,isoNB2,isoNEf2);


  Rc->SetMarkerColor(kRed); 
  Rp->SetMarkerColor(kRed); 
  Rn->SetMarkerColor(kRed); 

  Rc->SetMarkerStyle(20); 
  Rp->SetMarkerStyle(20); 
  Rn->SetMarkerStyle(20); 



  
  Rc->SetMarkerSize(0.7); 
  Rp->SetMarkerSize(0.7); 
  Rn->SetMarkerSize(0.7); 



  
  Rc2->SetMarkerStyle(20); 
  Rp2->SetMarkerStyle(20); 
  Rn2->SetMarkerStyle(20); 





  
  Rc2->SetMarkerSize(0.7); 
  Rp2->SetMarkerSize(0.7); 
  Rn2->SetMarkerSize(0.7); 


  Rc->GetYaxis()->SetRangeUser(0,1);
  Rn->GetXaxis()->SetRangeUser(0,1);

  
  Rc2->GetYaxis()->SetRangeUser(0,1);
  Rn2->GetXaxis()->SetRangeUser(0,1);







  TMultiGraph *RC = new TMultiGraph();
  RC->Add(Rc,"p");
  RC->Add(Rc2,"p");

  
  TMultiGraph *RP = new TMultiGraph();
  RP->Add(Rp,"p");
  RP->Add(Rp2,"p");
  
  TMultiGraph *RN = new TMultiGraph();
  RN->Add(Rn,"p");
  RN->Add(Rn2,"p");

  TCanvas *c1 = new TCanvas("c1","on the Rocs",1200,600 );
  c1->Divide(2,1);
  c1->cd(1);
  RP->Draw("APL");
  RP->SetTitle("ISO gamma ROC");



  /*
  Rp->SetMarkerSize(0.5);
  Rp->SetMarkerStyle(20);
  */
  RP->GetXaxis()->SetTitle("Background Rejection");
  RP->GetYaxis()->SetTitle("Signal Efficiency");
  


  // RP->GetYaxis()->SetRangeUser(0,1.0);
  // RP->GetXaxis()->SetRangeUser(0,1.0);



  c1->cd(2);
  RN->Draw("APL");
  RN->SetTitle("ISO Neutral ROC");
  /*
  RN->SetMarkerSize(0.5);
  RN->SetMarkerStyle(20);
  */

  
  RN->GetXaxis()->SetTitle("Background Rejection");
  RN->GetYaxis()->SetTitle("Signal Efficiency");

  /*
  RN->GetYaxis()->SetRangeUser(0,1.0);
  RN->GetXaxis()->SetRangeUser(0,1.0);
  */
 


  /*  
  c1->cd(3);
  RC->Draw("APL");
  RC->SetTitle("ISO Charge ROC");
  
  RC->GetXaxis()->SetTitle("Background Rejection");
  RC->GetYaxis()->SetTitle("Signal Efficiency");
  
  */

  c1->SaveAs("ROC_barrelIsos_NoPVsel.png");


}
