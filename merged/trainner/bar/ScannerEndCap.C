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


void ScannerEndCap(){

  double IsoPcutL = 6.4;
  double IsoPcutM = 5.6;
  double IsoPcutT = 4.4;
  
  
  double IsoCcutL = 4.0;
  double IsoCcutM = 3.2;
  double IsoCcutT = 2.8;


  
  double IsoNcutL = 4.8;
  double IsoNcutM = 4;
  double IsoNcutT = 3.2;

   //donne siesie
  double SieiecutL = 0.01014;
  double SieiecutM = 0.00988;
  double SieiecutT = 0.00967;


  double HoEcutL = 0.084;
  double HoEcutM = 0.063;
  double HoEcutT = 0.021;

  //OLD ENDCAP CUTS 
  /*
  double OisCL = 2.6;
  double OisCM = 1.5; 
  double OisCT = 0.7; 
  
  double OisPL = 1.3; 
  double OisPM = 0.7; 
  double OisPT = 0.5; 

  double OisNL = 3.5; 
  double OisNM = 1.0; 
  double OisNT = 0.4; 


  double OtL = 0.05; 
  double OtM = 0.05; 
  double OtT = 0.05; 

  double OsL = 0.012; 
  double OsM = 0.011; 
  double OsT = 0.011; 
  */



  double Xark[2],Yark[2]; 
  Xark[0] = OisPL; 
  Xark[1] = OisPL;

  Yark[0] = 0; 
  Yark[1] = 1;
  TGraph *OPL = new TGraph(2,Xark,Yark);
  Xark[0] = OisPM; 
  Xark[1] = OisPM;
  TGraph *OPM = new TGraph(2,Xark,Yark);

  Xark[0] = OisPT; 
  Xark[1] = OisPT;
  TGraph *OPT = new TGraph(2,Xark,Yark);
  


  //

  Xark[0] = OisCL; 
  Xark[1] = OisCL;
  TGraph *OCL = new TGraph(2,Xark,Yark);

  Xark[0] = OisCM; 
  Xark[1] = OisCM;
  TGraph *OCM = new TGraph(2,Xark,Yark);

  Xark[0] = OisCT; 
  Xark[1] = OisCT;
  TGraph *OCT = new TGraph(2,Xark,Yark);

  //****************

  
  Xark[0] = OisNL; 
  Xark[1] = OisNL;
  TGraph *ONL = new TGraph(2,Xark,Yark);

  Xark[0] = OisNM; 
  Xark[1] = OisNM;
  TGraph *ONM = new TGraph(2,Xark,Yark);

  Xark[0] = OisNT; 
  Xark[1] = OisNT;
  TGraph *ONT = new TGraph(2,Xark,Yark);


  //****************

  
  Xark[0] = OtL; 
  Xark[1] = OtL;
  TGraph *OTL = new TGraph(2,Xark,Yark);

  Xark[0] = OtM; 
  Xark[1] = OtM;
  TGraph *OTM = new TGraph(2,Xark,Yark);

  Xark[0] = OtT; 
  Xark[1] = OtT;
  TGraph *OTT = new TGraph(2,Xark,Yark);

  //***************************  
  Xark[0] = OsL; 
  Xark[1] = OsL;
  TGraph *OSL = new TGraph(2,Xark,Yark);

  Xark[0] = OsM; 
  Xark[1] = OsM;
  TGraph *OSM = new TGraph(2,Xark,Yark);

  Xark[0] = OsT; 
  Xark[1] = OsT;
  TGraph *OST = new TGraph(2,Xark,Yark);





  ofstream myfileE; 
  myfileE.open("Cuts_EffBck.txt");


  TString outfileName( "N1Plots.root" );
  TFile* outputFile = TFile::Open( outfileName, "RECREATE" );


  TH1F *isoPS  = new TH1F("isoPS","Iso gamma ",4000,0,400);
  TH1F *isoCS = new TH1F("isoCS","Iso ch Hadron ",4000,0,400);
  TH1F *isoNS = new TH1F("isoNS","Iso neutral ",4000,0,400);
  TH1F *SieieS = new TH1F("SieieS","Sieie ",4000,0,2);
  TH1F *HoES = new TH1F("HoES","HoE ",4000,0,2);

  TH1F *isoPB  = new TH1F("isoPB","Iso gamma ",4000,0,400);
  TH1F *isoCB = new TH1F("isoCB","Iso ch Hadron ",4000,0,400);
  TH1F *isoNB = new TH1F("isoNB","Iso neutral ",4000,0,400);
  TH1F *SieieB = new TH1F("SieieB","Sieie ",4000,0,2);
  TH1F *HoEB = new TH1F("HoEB","HoE ",4000,0,2);





 
  TH1F *isoPn1SL = new TH1F("isoPn1SL","Iso gamma N_1 plot Loose",4000,0,400);
  TH1F *isoCn1SL = new TH1F("isoCn1SL","Iso ch Hadron N_1 plot Loose",4000,0,400);
  TH1F *isoNn1SL = new TH1F("isoNn1SL","Iso neutral Hadron N_1 plot Loose",4000,0,400);
  TH1F *Sieien1SL = new TH1F("Sieien1SL","Sieie N_1 plot Loose",4000,0,2);
  TH1F *HoEn1SL = new TH1F("HoEn1SL","HoE N_1 plot Loose",4000,0,2);

  TH1F *isoPn1BL = new TH1F("isoPn1BL","Iso gamma N_1 plot Loose",4000,0,400);
  TH1F *isoCn1BL = new TH1F("isoCn1BL","Iso ch Hadron N_1 plot Loose",4000,0,400);
  TH1F *isoNn1BL = new TH1F("isoNn1BL","Iso neutral Hadron N_1 plot Loose",4000,0,400);
  TH1F *Sieien1BL = new TH1F("Sieien1BL","Sieie N_1 plot Loose",4000,0,2);
  TH1F *HoEn1BL = new TH1F("HoEn1BL","HoE N_1 plot Loose",4000,0,2);

  TH1F *isoPn1ST = new TH1F("isoPn1ST","Iso gamma N_1 plot",4000,0,400);
  TH1F *isoCn1ST = new TH1F("isoCn1ST","Iso ch Hadron N_1 plot",4000,0,400);
  TH1F *isoNn1ST = new TH1F("isoNn1ST","Iso neutral Hadron N_1 plot",4000,0,400);
  TH1F *Sieien1ST = new TH1F("Sieien1ST","Sieie N_1 plot",4000,0,2);
  TH1F *HoEn1ST = new TH1F("HoEn1ST","HoE N_1 plot",4000,0,2);

  TH1F *isoPn1BT = new TH1F("isoPn1BT","Iso gamma N_1 plot",4000,0,400);
  TH1F *isoCn1BT = new TH1F("isoCn1BT","Iso ch Hadron N_1 plot",4000,0,400);
  TH1F *isoNn1BT = new TH1F("isoNn1BT","Iso neutral Hadron N_1 plot",4000,0,400);
  TH1F *Sieien1BT = new TH1F("Sieien1BT","Sieie N_1 plot",4000,0,2);
  TH1F *HoEn1BT = new TH1F("HoEn1BT","HoE N_1 plot",4000,0,2);

  TH1F *isoPn1BM = new TH1F("isoPn1BM","Iso gamma N_1 plot",4000,0,400);
  TH1F *isoCn1BM = new TH1F("isoCn1BM","Iso ch Hadron N_1 plot",4000,0,400);
  TH1F *isoNn1BM = new TH1F("isoNn1BM","Iso neutral Hadron N_1 plot",4000,0,400);
  TH1F *Sieien1BM = new TH1F("Sieien1BM","Sieie N_1 plot",4000,0,2);
  TH1F *HoEn1BM = new TH1F("HoEn1BM","HoE N_1 plot",4000,0,2);

  TH1F *isoPn1SM = new TH1F("isoPn1SM","Iso gamma N_1 plot",4000,0,400);
  TH1F *isoCn1SM = new TH1F("isoCn1SM","Iso ch Hadron N_1 plot",4000,0,400);
  TH1F *isoNn1SM = new TH1F("isoNn1SM","Iso neutral Hadron N_1 plot",4000,0,400);
  TH1F *Sieien1SM = new TH1F("Sieien1SM","Sieie N_1 plot",4000,0,2);
  TH1F *HoEn1SM = new TH1F("HoEn1SM","HoE N_1 plot",4000,0,2);
 


  //Input file:
  TString fname = "../CutTMVATrees_Barrel.root";
  input = TFile::Open( fname );
  
  // --- Register the regression tree
  float Sie_ie,iso_P,iso_C,iso_N,to_e,weight;

  //Signal Tree
  t_S->SetBranchAddress("Sieie",&Sie_ie);
  t_S->SetBranchAddress("isoP",&iso_P);
  t_S->SetBranchAddress("isoC",&iso_C);
  t_S->SetBranchAddress("isoN",&iso_N);
  t_S->SetBranchAddress("ToE",&to_e);
  t_S->SetBranchAddress("weighT",&weight);


  //Background Tree
  t_B->SetBranchAddress("Sieie",&Sie_ie);
  t_B->SetBranchAddress("isoP",&iso_P);
  t_B->SetBranchAddress("isoC",&iso_C);
  t_B->SetBranchAddress("isoN",&iso_N);
  t_B->SetBranchAddress("ToE",&to_e);
  t_B->SetBranchAddress("weighT",&weight);

  double LoosSEf = 0; 
  double TightSEf = 0; 
  double MediumSEf = 0; 

  
  double LoosBckR = 0; 
  double TightBckR = 0; 
  double MediumBckR = 0; 

  
  double totS = 0; 
  for(int i  = 0 ; i < t_S->GetEntries(); i++){
    t_S->GetEntry(i);

    isoPS->Fill(iso_P,weight);
    isoCS->Fill(iso_C,weight);
    isoNS->Fill(iso_N,weight);
    SieieS->Fill(Sie_ie,weight);
    HoES->Fill(to_e,weight);

    
    
    totS = totS+ weight; 

    //Calculating the Efficiencies for the Loose Set of Cuts 
    if((iso_P < IsoPcutL)&&(iso_N < IsoNcutL)&&(iso_C < IsoCcutL)&&(to_e<HoEcutL)&&(Sie_ie < SieiecutL )){
      LoosSEf = LoosSEf + weight;
    }
    
    if((iso_P < IsoPcutM)&&(iso_N < IsoNcutM)&&(iso_C < IsoCcutM)&&(to_e<HoEcutM)&&(Sie_ie < SieiecutM )){
       MediumSEf = MediumSEf + weight;
    }
    
    if((iso_P < IsoPcutT)&&(iso_N < IsoNcutT)&&(iso_C < IsoCcutT)&&(to_e<HoEcutT)&&(Sie_ie < SieiecutT )){
        TightSEf = TightSEf + weight;
    }
    
  }

  double totB = 0; 
  for(int i  = 0 ; i < t_B->GetEntries(); i++){
    t_B->GetEntry(i);
    totB = totB+ weight; 

    
    isoPB->Fill(iso_P,weight);
    isoCB->Fill(iso_C,weight);
    isoNB->Fill(iso_N,weight);
    SieieB->Fill(Sie_ie,weight);
    HoEB->Fill(to_e,weight);



        //Calculating the Efficiencies for the Loose Set of Cuts 
    if((iso_P < IsoPcutL)&&(iso_N < IsoNcutL)&&(iso_C < IsoCcutL)&&(to_e<HoEcutL)&&(Sie_ie < SieiecutL )){
      LoosBckR = LoosBckR + weight;
    }
    
    if((iso_P < IsoPcutM)&&(iso_N < IsoNcutM)&&(iso_C < IsoCcutM)&&(to_e<HoEcutM)&&(Sie_ie < SieiecutM )){
       MediumBckR = MediumBckR + weight;
    }
    
    if((iso_P < IsoPcutT)&&(iso_N < IsoNcutT)&&(iso_C < IsoCcutT)&&(to_e<HoEcutT)&&(Sie_ie < SieiecutT )){
        TightBckR = TightBckR + weight;
    }


  }// Eoff Back ground tree for Sig Back 


  cout<<"|        |        Efficiencies | Background Rejection                 |"<<endl;
  cout<<endl;
  cout<<"| Loose  |        "<<LoosSEf/totS  <<" | "<<LoosBckR/totB <<" |"<<endl;
  cout<<endl;
  cout<<"| Medium |        "<<MediumSEf/totS  <<" | "<<MediumBckR/totB <<" |"<<endl;
  cout<<endl;  
  cout<<"| Tight  |        "<<TightSEf/totS  <<" | "<<TightBckR/totB <<" |"<<endl;



  int intggr =  isoPS->Integral();
  isoPS->Scale(1./intggr);
  
  intggr =isoCS->Integral();
  isoCS->Scale(1./intggr);
  intggr =isoNS->Integral();
  isoNS->Scale(1./intggr);
  intggr =SieieS->Integral();
  SieieS->Scale(1./intggr);
  intggr =HoES->Integral();
  HoES->Scale(1./intggr);
  

  intggr =  isoPB->Integral();
  isoPB->Scale(1./intggr);
  intggr =isoCB->Integral();
  isoCB->Scale(1./intggr);
  intggr =isoNB->Integral();
  isoNB->Scale(1./intggr);
  intggr =SieieB->Integral();
  SieieB->Scale(1./intggr);
  intggr =HoEB->Integral();
  HoEB->Scale(1./intggr);
  
  double Xarm[2],Yarm[2],Xarl[2],Yarl[2],Xart[2],Yart[2];

  Xarm[0] = IsoPcutM;  
  Xarm[1] = IsoPcutM;
  Yarm[0] = 0.0;
  Yarm[1] = 1.0; 

  
  Xarl[0] = IsoPcutL;  
  Xarl[1] = IsoPcutL;
  Yarl[0] = 0.0;
  Yarl[1] = 1.0; 
  
  
  Xart[0] = IsoPcutT;  
  Xart[1] = IsoPcutT;
  Yart[0] = 0.0;
  Yart[1] = 1.0; 

  




  //Drawing the Befor any cuts Weighted Distr. 

  TCanvas *c55 = new TCanvas("c55","Un Cut Distr.",1200,700);
  c55->Divide(3,2); 

  c55->cd(1);
  isoPS->Draw();
  isoPS->SetLineColor(kRed);
  isoPS->GetXaxis()->SetRangeUser(0,10);
  isoPS->GetXaxis()->SetTitle("Iso P");
  isoPB->Draw("same");

  TGraph *PT = new TGraph(2,Xart,Yart);
  PT->Draw("same");
  PT->SetLineColor(kBlack);
  
  TGraph *PL = new TGraph(2,Xarl,Yarl);
  
  PL->Draw("same");
  PL->SetLineColor(kBlue);
  

  TGraph *PM = new TGraph(2,Xarm,Yarm);
  PM->Draw("same");  
  PM->SetLineColor(kRed);
   
  OPM->Draw("same");
  OPM->SetLineColor(kRed);
  OPM->SetLineStyle(10);
  
  OPL->Draw("same");
  OPL->SetLineColor(kBlue);
  OPL->SetLineStyle(10);
 
  OPT->Draw("same");
  OPT->SetLineColor(kBlack);
  OPT->SetLineStyle(10);
  
  c55->cd(2);
  isoCS->Draw();
  isoCS->SetLineColor(kRed);
  isoCS->GetXaxis()->SetRangeUser(0,15);
  isoCS->GetXaxis()->SetTitle("Iso C");
  isoCB->Draw("same");
  
  Xarm[0] = IsoCcutM;  
  Xarm[1] = IsoCcutM;

  
  Xarl[0] = IsoCcutL;  
  Xarl[1] = IsoCcutL;


  Xart[0] = IsoCcutT;  
  Xart[1] = IsoCcutT;


  
  TGraph *CT = new TGraph(2,Xart,Yart);
  CT->Draw("same");
  CT->SetLineColor(kBlack);
  
  TGraph *CL = new TGraph(2,Xarl,Yarl);
  
  CL->Draw("same");
  CL->SetLineColor(kBlue);
  

  TGraph *CM = new TGraph(2,Xarm,Yarm);
  CM->Draw("same");  
  CM->SetLineColor(kRed);

  OCM->Draw("same");
  OCM->SetLineColor(kRed);
  OCM->SetLineStyle(10);
  
  OCL->Draw("same");
  OCL->SetLineColor(kBlue);
  OCL->SetLineStyle(10);
 
  OCT->Draw("same");
  OCT->SetLineColor(kBlack);
  OCT->SetLineStyle(10);
  




  
  c55->cd(3);
  isoNS->Draw();
  isoNS->SetLineColor(kRed);
  isoNS->GetXaxis()->SetRangeUser(0,22); 
  isoNS->GetXaxis()->SetTitle("Iso Neutral");
  isoNB->Draw("same");

  
  Xarm[0] = IsoNcutM;  
  Xarm[1] = IsoNcutM;

  
  Xarl[0] = IsoNcutL;  
  Xarl[1] = IsoNcutL;


  Xart[0] = IsoNcutT;  
  Xart[1] = IsoNcutT;


  
  TGraph *NT = new TGraph(2,Xart,Yart);
  NT->Draw("same");
  NT->SetLineColor(kBlack);
  
  TGraph *NL = new TGraph(2,Xarl,Yarl);
  
  NL->Draw("same");
  NL->SetLineColor(kBlue);
  

  TGraph *NM = new TGraph(2,Xarm,Yarm);
  NM->Draw("same");  
  NM->SetLineColor(kRed);

  
  ONM->Draw("same");
  ONM->SetLineColor(kRed);
  ONM->SetLineStyle(10);
  
  ONL->Draw("same");
  ONL->SetLineColor(kBlue);
  ONL->SetLineStyle(10);
 
  ONT->Draw("same");
  ONT->SetLineColor(kBlack);
  ONT->SetLineStyle(10);
  



  
  c55->cd(4); 
  SieieS->Draw();
  SieieS->SetLineColor(kRed);
  //SieieS->GetXaxis()->SetRangeUserB(0,0.1);
  SieieS->GetXaxis()->SetRangeUser(0,0.03);
  SieieS->GetXaxis()->SetTitle("Sieie");
  SieieB->Draw("same");

  
  Xarm[0] = SieiecutM;  
  Xarm[1] = SieiecutM;

  
  Xarl[0] = SieiecutL;  
  Xarl[1] = SieiecutL;


  Xart[0] = SieiecutT;  
  Xart[1] = SieiecutT;




  
  TGraph *ST = new TGraph(2,Xart,Yart);
  ST->Draw("same");
  ST->SetLineColor(kBlack);
  
  TGraph *SL = new TGraph(2,Xarl,Yarl);
  
  SL->Draw("same");
  SL->SetLineColor(kBlue);
  

  TGraph *SM = new TGraph(2,Xarm,Yarm);
  SM->Draw("same");  
  SM->SetLineColor(kRed);

  
  OSM->Draw("same");
  OSM->SetLineColor(kRed);
  OSM->SetLineStyle(10);
  
  OSL->Draw("same");
  OSL->SetLineColor(kBlue);
  OSL->SetLineStyle(10);
 
  OST->Draw("same");
  OST->SetLineColor(kBlack);
  OST->SetLineStyle(10);
  



  
  c55->cd(5);
  HoES->Draw();
  HoES->SetLineColor(kRed);
  HoES->GetXaxis()->SetTitle("H over E");
  HoES->GetXaxis()->SetRangeUser(0,0.04);
  HoEB->Draw("same");


  
  Xarm[0] = HoEcutM;  
  Xarm[1] = HoEcutM;

  
  Xarl[0] = HoEcutL;  
  Xarl[1] = HoEcutL;


  Xart[0] = HoEcutT;  
  Xart[1] = HoEcutT;


  
  TGraph *HT = new TGraph(2,Xart,Yart);
  HT->Draw("same");
  HT->SetLineColor(kBlack);
  
  TGraph *HL = new TGraph(2,Xarl,Yarl);
  
  HL->Draw("same");
  HL->SetLineColor(kBlue);
  

  TGraph *HM = new TGraph(2,Xarm,Yarm);
  HM->Draw("same");  
  HM->SetLineColor(kRed);

  
  OTM->Draw("same");
  OTM->SetLineColor(kRed);
  OTM->SetLineStyle(10);
  
  OTL->Draw("same");
  OTL->SetLineColor(kBlue);
  OTL->SetLineStyle(10);
 
  OTT->Draw("same");
  OTT->SetLineColor(kBlack);
  OTT->SetLineStyle(10);
  




  c55->Update();

c55->SaveAs("BeforeCutsNormalisedDisrt.png");

  
  

  //Signal Tree
  for(int jentry = 0; jentry < t_S->GetEntries(); jentry++){
    t_S->GetEntry(jentry);	  

    //here we apply the N-1 other cuts and then plot the variable of interest and the corresponding slected cuts on that variable effeiceincies are also calculated  
   
    //Loose Cuts
    if((iso_P < IsoPcutL)&&(iso_N < IsoNcutL)&&(iso_C < IsoCcutL)&&(to_e<HoEcutL)){
      Sieien1SL->Fill(Sie_ie,weight);
    }

    if((iso_P < IsoPcutL)&&(iso_N < IsoNcutL)&&(iso_C < IsoCcutL)&&(Sie_ie<SieiecutL)){
      HoEn1SL->Fill(to_e,weight);
    }

     if((iso_P < IsoPcutL)&&(iso_N < IsoNcutL)&&(to_e<HoEcutL)&&(Sie_ie<SieiecutL)){
      isoCn1SL->Fill(iso_C,weight);
    }

     
     if((iso_P < IsoPcutL)&&(iso_C < IsoCcutL)&&(to_e<HoEcutL)&&(Sie_ie<SieiecutL)){
      isoNn1SL->Fill(iso_N,weight);
    }


     if((iso_C < IsoCcutL)&&(iso_N < IsoNcutL)&&(to_e<HoEcutL)&&(Sie_ie<SieiecutL)){
      isoPn1SL->Fill(iso_P,weight);
    }


     
    //Medium Cuts
    if((iso_P < IsoPcutM)&&(iso_N < IsoNcutM)&&(iso_C < IsoCcutM)&&(to_e<HoEcutM)){
      Sieien1SM->Fill(Sie_ie,weight);
    }

    if((iso_P < IsoPcutM)&&(iso_N < IsoNcutM)&&(iso_C < IsoCcutM)&&(Sie_ie<SieiecutM)){
      HoEn1SM->Fill(to_e,weight);
    }

     if((iso_P < IsoPcutM)&&(iso_N < IsoNcutM)&&(to_e<HoEcutM)&&(Sie_ie<SieiecutM)){
      isoCn1SM->Fill(iso_C,weight);
    }

     
     if((iso_P < IsoPcutM)&&(iso_C < IsoCcutM)&&(to_e<HoEcutM)&&(Sie_ie<SieiecutM)){
      isoNn1SM->Fill(iso_N,weight);
    }


     if((iso_C < IsoCcutM)&&(iso_N < IsoNcutM)&&(to_e<HoEcutM)&&(Sie_ie<SieiecutM)){
      isoPn1SM->Fill(iso_P,weight);
    }




     
    //Tight  Cuts
    if((iso_P < IsoPcutT)&&(iso_N < IsoNcutT)&&(iso_C < IsoCcutT)&&(to_e<HoEcutT)){
      Sieien1ST->Fill(Sie_ie,weight);
    }

    if((iso_P < IsoPcutT)&&(iso_N < IsoNcutT)&&(iso_C < IsoCcutT)&&(Sie_ie<SieiecutT)){
      HoEn1ST->Fill(to_e,weight);
    }

     if((iso_P < IsoPcutT)&&(iso_N < IsoNcutT)&&(to_e<HoEcutT)&&(Sie_ie<SieiecutT)){
      isoCn1ST->Fill(iso_C,weight);
    }

     
     if((iso_P < IsoPcutT)&&(iso_C < IsoCcutT)&&(to_e<HoEcutT)&&(Sie_ie<SieiecutT)){
      isoNn1ST->Fill(iso_N,weight);
    }


     if((iso_C < IsoCcutT)&&(iso_N < IsoNcutT)&&(to_e<HoEcutT)&&(Sie_ie<SieiecutT)){
      isoPn1ST->Fill(iso_P,weight);
    }



  }//EOF loop on the  signal Tree 



  //Background tree 
    for(int jentry = 0; jentry < t_B->GetEntries(); jentry++){
    t_B->GetEntry(jentry);	  

    //here we apply the N-1 other cuts and then plot the variable of interest and the corresponding slected cuts on that variable effeiceincies are also calculated  
   
    //Loose Cuts
    if((iso_P < IsoPcutL)&&(iso_N < IsoNcutL)&&(iso_C < IsoCcutL)&&(to_e<HoEcutL)){
      Sieien1BL->Fill(Sie_ie,weight);
    }

    if((iso_P < IsoPcutL)&&(iso_N < IsoNcutL)&&(iso_C < IsoCcutL)&&(Sie_ie<SieiecutL)){
      HoEn1BL->Fill(to_e,weight);
    }

     if((iso_P < IsoPcutL)&&(iso_N < IsoNcutL)&&(to_e<HoEcutL)&&(Sie_ie<SieiecutL)){
      isoCn1BL->Fill(iso_C,weight);
    }

     
     if((iso_P < IsoPcutL)&&(iso_C < IsoCcutL)&&(to_e<HoEcutL)&&(Sie_ie<SieiecutL)){
      isoNn1BL->Fill(iso_N,weight);
    }


     if((iso_C < IsoCcutL)&&(iso_N < IsoNcutL)&&(to_e<HoEcutL)&&(Sie_ie<SieiecutL)){
      isoPn1BL->Fill(iso_P,weight);
    }


     
    //Medium Cuts
    if((iso_P < IsoPcutM)&&(iso_N < IsoNcutM)&&(iso_C < IsoCcutM)&&(to_e<HoEcutM)){
      Sieien1BM->Fill(Sie_ie,weight);
    }

    if((iso_P < IsoPcutM)&&(iso_N < IsoNcutM)&&(iso_C < IsoCcutM)&&(Sie_ie<SieiecutM)){
      HoEn1BM->Fill(to_e,weight);
    }

     if((iso_P < IsoPcutM)&&(iso_N < IsoNcutM)&&(to_e<HoEcutM)&&(Sie_ie<SieiecutM)){
      isoCn1BM->Fill(iso_C,weight);
    }

     
     if((iso_P < IsoPcutM)&&(iso_C < IsoCcutM)&&(to_e<HoEcutM)&&(Sie_ie<SieiecutM)){
      isoNn1BM->Fill(iso_N,weight);
    }


     if((iso_C < IsoCcutM)&&(iso_N < IsoNcutM)&&(to_e<HoEcutM)&&(Sie_ie<SieiecutM)){
      isoPn1BM->Fill(iso_P,weight);
    }




     
    //Tight  Cuts
    if((iso_P < IsoPcutT)&&(iso_N < IsoNcutT)&&(iso_C < IsoCcutT)&&(to_e<HoEcutT)){
      Sieien1BT->Fill(Sie_ie,weight);
    }

    if((iso_P < IsoPcutT)&&(iso_N < IsoNcutT)&&(iso_C < IsoCcutT)&&(Sie_ie<SieiecutT)){
      HoEn1BT->Fill(to_e,weight);
    }

     if((iso_P < IsoPcutT)&&(iso_N < IsoNcutT)&&(to_e<HoEcutT)&&(Sie_ie<SieiecutT)){
      isoCn1BT->Fill(iso_C,weight);
    }

     
     if((iso_P < IsoPcutT)&&(iso_C < IsoCcutT)&&(to_e<HoEcutT)&&(Sie_ie<SieiecutT)){
      isoNn1BT->Fill(iso_N,weight);
    }


     if((iso_C < IsoCcutT)&&(iso_N < IsoNcutT)&&(to_e<HoEcutT)&&(Sie_ie<SieiecutT)){
      isoPn1BT->Fill(iso_P,weight);
     }
     
     

    }//EOF loop on the  signal Tree 

    
    //Now let's Normalize the N-1 Variable Plots 


    double intgr = isoPn1SL->Integral();
    isoPn1SL->Scale(1.0/intgr);


    intgr = isoCn1SL->Integral();
    isoCn1SL->Scale(1.0/intgr);
 
    intgr = isoNn1SL->Integral();
    isoNn1SL->Scale(1.0/intgr);
 

    intgr = Sieien1SL->Integral();
    Sieien1SL->Scale(1.0/intgr);
   
    intgr = HoEn1SL->Integral();
    HoEn1SL->Scale(1.0/intgr);


    //-------------------------------


    intgr = isoPn1BL->Integral();
    isoPn1BL->Scale(1.0/intgr);


    intgr = isoCn1BL->Integral();
    isoCn1BL->Scale(1.0/intgr);
 
    intgr = isoNn1BL->Integral();
    isoNn1BL->Scale(1.0/intgr);
 

    intgr = Sieien1BL->Integral();
    Sieien1BL->Scale(1.0/intgr);
   
    intgr = HoEn1BL->Integral();
    HoEn1BL->Scale(1.0/intgr);

    //-------------------------------


    intgr = isoPn1BM->Integral();
    isoPn1BM->Scale(1.0/intgr);


    intgr = isoCn1BM->Integral();
    isoCn1BM->Scale(1.0/intgr);
 
    intgr = isoNn1BM->Integral();
    isoNn1BM->Scale(1.0/intgr);
 

    intgr = Sieien1BM->Integral();
    Sieien1BM->Scale(1.0/intgr);
   
    intgr = HoEn1BM->Integral();
    HoEn1BM->Scale(1.0/intgr);

    //-------------------------------
 

    intgr = isoPn1SM->Integral();
    isoPn1SM->Scale(1.0/intgr);


    intgr = isoCn1SM->Integral();
    isoCn1SM->Scale(1.0/intgr);
 
    intgr = isoNn1SM->Integral();
    isoNn1SM->Scale(1.0/intgr);
 

    intgr = Sieien1SM->Integral();
    Sieien1SM->Scale(1.0/intgr);
   
    intgr = HoEn1SM->Integral();
    HoEn1SM->Scale(1.0/intgr);

       //-------------------------------
 

    intgr = isoPn1ST->Integral();
    isoPn1ST->Scale(1.0/intgr);


    intgr = isoCn1ST->Integral();
    isoCn1ST->Scale(1.0/intgr);
 
    intgr = isoNn1ST->Integral();
    isoNn1ST->Scale(1.0/intgr);
 

    intgr = Sieien1ST->Integral();
    Sieien1ST->Scale(1.0/intgr);
   
    intgr = HoEn1ST->Integral();
    HoEn1ST->Scale(1.0/intgr);

    
    //-------------------------------
 

    intgr = isoPn1BT->Integral();
    isoPn1BT->Scale(1.0/intgr);


    intgr = isoCn1BT->Integral();
    isoCn1BT->Scale(1.0/intgr);
 
    intgr = isoNn1BT->Integral();
    isoNn1BT->Scale(1.0/intgr);
 

    intgr = Sieien1BT->Integral();
    Sieien1BT->Scale(1.0/intgr);
   
    intgr = HoEn1BT->Integral();
    HoEn1BT->Scale(1.0/intgr);

    

 
    
    double Xar[2];
    double Yar[2];


    TCanvas *c1  = new TCanvas("c1","N-1 Plots Tight",1000,700);
    c1->Divide(3,2);



    
    c1->cd(1);
    
    Xar[0] = IsoPcutT;  
    Xar[1] = IsoPcutT;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArPT = new TGraph(2,Xar,Yar);
    
    isoPn1ST->Draw();
    isoPn1ST->SetLineColor(kRed);
    isoPn1ST->GetXaxis()->SetTitle("Iso gamma");
    isoPn1ST->GetXaxis()->SetRangeUser(0,10);
    isoPn1BT->Draw("same");
    ArPT->Draw("same");
    ArPT->SetLineColor(kRed);

    
    OPT->Draw("same");
    OPT->SetLineColor(kBlack);
    OPT->SetLineStyle(10);
  




    c1->cd(2);

    Xar[0] = IsoCcutT;  
    Xar[1] = IsoCcutT;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArCT = new TGraph(2,Xar,Yar);



    isoCn1ST->Draw();    
    isoCn1ST->SetLineColor(kRed);
    isoCn1ST->GetXaxis()->SetTitle("Iso charge");
    isoCn1ST->GetXaxis()->SetRangeUser(0,15);
    isoCn1BT->Draw("same");
    
    ArCT->Draw("same");
    ArCT->SetLineColor(kRed);
    
    
    OCT->Draw("same");
    OCT->SetLineColor(kBlack);
    OCT->SetLineStyle(10);
  
    
    c1->cd(3);

    
    Xar[0] = IsoNcutT;  
    Xar[1] = IsoNcutT;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArNT = new TGraph(2,Xar,Yar);


    isoNn1ST->Draw();        
    isoNn1ST->SetLineColor(kRed);
    isoNn1ST->GetXaxis()->SetTitle("Iso Neutral");
    isoNn1ST->GetXaxis()->SetRangeUser(0,22); 

    isoNn1BT->Draw("same");

    ArNT->Draw("same");
    ArNT->SetLineColor(kRed);
    
    ONT->Draw("same");
    ONT->SetLineColor(kBlack);
    ONT->SetLineStyle(10);
  
    
    
    c1->cd(4); 

    
    Xar[0] = SieiecutT;  
    Xar[1] = SieiecutT;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArST = new TGraph(2,Xar,Yar);


    Sieien1ST->Draw();            
    Sieien1ST->SetLineColor(kRed);
    Sieien1ST->GetXaxis()->SetTitle("Sieie");
    Sieien1ST->GetXaxis()->SetRangeUser(0,0.03);
    Sieien1BT->Draw("same");


    ArST->Draw("same");
    ArST->SetLineColor(kRed);

    
    OST->Draw("same");
    OST->SetLineColor(kBlack);
    OST->SetLineStyle(10);
  
    
    c1->cd(5);
    Xar[0] = HoEcutT;  
    Xar[1] = HoEcutT;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArHT = new TGraph(2,Xar,Yar);


    HoEn1ST->Draw();
    HoEn1ST->SetLineColor(kRed);
    HoEn1ST->GetXaxis()->SetTitle("H over E");
    HoEn1ST->GetXaxis()->SetRangeUser(0,0.1);
    HoEn1BT->Draw("same");

    ArHT->Draw("same");
    ArHT->SetLineColor(kRed);

    
    OTT->Draw("same");
    OTT->SetLineColor(kBlack);
    OTT->SetLineStyle(10);
  


    c1->Update();
    c1->SaveAs("N_1_Tight.png");




    TCanvas *c2  = new TCanvas("c2","N-1 PlotsMEDium",1000,700);
    c2->Divide(3,2);



    
    c2->cd(1);
    
    Xar[0] = IsoPcutM;  
    Xar[1] = IsoPcutM;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArPM = new TGraph(2,Xar,Yar);
    
    isoPn1SM->Draw();
    isoPn1SM->SetLineColor(kRed);
    isoPn1SM->GetXaxis()->SetTitle("Iso gamma");
    isoPn1SM->GetXaxis()->SetRangeUser(0,10);
    isoPn1BM->Draw("same");
    ArPM->Draw("same");
    ArPM->SetLineColor(kRed);

    
    OPM->Draw("same");
    OPM->SetLineColor(kBlack);
    OPM->SetLineStyle(10);
  


    c2->cd(2);

    Xar[0] = IsoCcutM;  
    Xar[1] = IsoCcutM;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArCM = new TGraph(2,Xar,Yar);



    isoCn1SM->Draw();    
    isoCn1SM->SetLineColor(kRed);
    isoCn1SM->GetXaxis()->SetTitle("Iso charge");
    isoCn1SM->GetXaxis()->SetRangeUser(0,15);
    isoCn1BM->Draw("same");
    
    ArCM->Draw("same");
    ArCM->SetLineColor(kRed);

    
    OCM->Draw("same");
    OCM->SetLineColor(kBlack);
    OCM->SetLineStyle(10);
  
    c2->cd(3);

    
    Xar[0] = IsoNcutM;  
    Xar[1] = IsoNcutM;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArNM = new TGraph(2,Xar,Yar);


    isoNn1SM->Draw();        
    isoNn1SM->SetLineColor(kRed);
    isoNn1SM->GetXaxis()->SetTitle("Iso Neutral");
    isoNn1SM->GetXaxis()->SetRangeUser(0,22); 
    isoNn1BM->Draw("same");

    ArNM->Draw("same");
    ArNM->SetLineColor(kRed);
    
    ONM->Draw("same");
    ONM->SetLineColor(kBlack);
    ONM->SetLineStyle(10);
  
   
    
    
    c2->cd(4); 

    
    Xar[0] = SieiecutM;  
    Xar[1] = SieiecutM;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArSM = new TGraph(2,Xar,Yar);


    Sieien1SM->Draw();            
    Sieien1SM->SetLineColor(kRed);
    Sieien1SM->GetXaxis()->SetTitle("Sieie");
    Sieien1SM->GetXaxis()->SetRangeUser(0,0.03);
    Sieien1BM->Draw("same");


    ArSM->Draw("same");
    ArSM->SetLineColor(kRed);

    
    OSM->Draw("same");
    OSM->SetLineColor(kBlack);
    OSM->SetLineStyle(10);
  
    
    c2->cd(5);
    Xar[0] = HoEcutT;  
    Xar[1] = HoEcutT;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArHM = new TGraph(2,Xar,Yar);


    HoEn1SM->Draw();
    HoEn1SM->SetLineColor(kRed);
    HoEn1SM->GetXaxis()->SetTitle("H over E");
    HoEn1SM->GetXaxis()->SetRangeUser(0,0.1);
	HoEn1BM->Draw("same");

    ArHM->Draw("same");
    ArHM->SetLineColor(kRed);

    
    OTM->Draw("same");
    OTM->SetLineColor(kBlack);
    OTM->SetLineStyle(10);
  


    c2->Update();
    c2->SaveAs("N_1_Medium.png");

    //----------------------------------------------------------


    TCanvas *c3  = new TCanvas("c3","N-1 Plots LOOSE",1000,700);
    c3->Divide(3,2);
    
    c3->cd(1);
    Xar[0] = IsoPcutL;  
    Xar[1] = IsoPcutL;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArPL = new TGraph(2,Xar,Yar);
    isoPn1SL->Draw();
    isoPn1SL->SetLineColor(kRed);
    isoPn1SL->GetXaxis()->SetTitle("Iso gamma");
     isoPn1SL->GetXaxis()->SetRangeUser(0,10);
    isoPn1BL->Draw("same");
    ArPL->Draw("same");
    ArPL->SetLineColor(kRed);

    
    OPL->Draw("same");
    OPL->SetLineColor(kBlack);
    OPL->SetLineStyle(10);
  


    c3->cd(2);
    Xar[0] = IsoCcutL;  
    Xar[1] = IsoCcutL;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArCL = new TGraph(2,Xar,Yar);
    isoCn1SL->Draw();    
    isoCn1SL->SetLineColor(kRed);
    isoCn1SL->GetXaxis()->SetTitle("Iso charge");
    isoCn1SL->GetXaxis()->SetRangeUser(0,15);
    isoCn1BL->Draw("same");
    
    ArCL->Draw("same");
    ArCL->SetLineColor(kRed);
    
    OCL->Draw("same");
    OCL->SetLineColor(kBlack);
    OCL->SetLineStyle(10);
  
    
    c3->cd(3);

    
    Xar[0] = IsoNcutL;  
    Xar[1] = IsoNcutL;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArNL = new TGraph(2,Xar,Yar);


    isoNn1SL->Draw();        
    isoNn1SL->SetLineColor(kRed);
    isoNn1SL->GetXaxis()->SetTitle("Iso Neutral");
    isoNn1SL->GetXaxis()->SetRangeUser(0,22); 
    isoNn1BL->Draw("same");

    ArNL->Draw("same");
    ArNL->SetLineColor(kRed);

    
    ONL->Draw("same");
    ONL->SetLineColor(kBlack);
    ONL->SetLineStyle(10);
  
    
    c3->cd(4); 

    
    Xar[0] = SieiecutL;  
    Xar[1] = SieiecutL;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArSL = new TGraph(2,Xar,Yar);


    Sieien1SL->Draw();            
    Sieien1SL->SetLineColor(kRed);
    Sieien1SL->GetXaxis()->SetTitle("Sieie");
    Sieien1SL->GetXaxis()->SetRangeUser(0,0.03);
    Sieien1BL->Draw("same");


    ArSL->Draw("same");
    ArSL->SetLineColor(kRed);
    
    OSL->Draw("same");
    OSL->SetLineColor(kBlack);
    OSL->SetLineStyle(10);
  

    
    c3->cd(5);
    Xar[0] = HoEcutL;  
    Xar[1] = HoEcutL;
    Yar[0] = 0.0;
    Yar[1] = 1.0; 

    TGraph *ArHL = new TGraph(2,Xar,Yar);


    HoEn1SL->Draw();
    HoEn1SL->SetLineColor(kRed);
    HoEn1SL->GetXaxis()->SetTitle("H over E");
    HoEn1SL->GetXaxis()->SetRangeUser(0,0.1);
    HoEn1BL->Draw("same");

    ArHL->Draw("same");
    ArHL->SetLineColor(kRed);

    
    OTL->Draw("same");
    OTL->SetLineColor(kBlack);
    OTL->SetLineStyle(10);
  


    c3->Update();
    c3->SaveAs("N_1_Loose.png");








    //Writting down the files 

    outputFile->cd(); 
    isoPn1SL->Write();
    isoCn1SL->Write();
    isoNn1SL->Write();
    Sieien1SL->Write();
    HoEn1SL->Write();
    
    isoPn1BL->Write();
    isoCn1BL->Write();
    isoNn1BL->Write();
    Sieien1BL->Write();
    HoEn1BL->Write();
    
    isoPn1ST->Write();
    isoCn1ST->Write();
    isoNn1ST->Write();
    Sieien1ST->Write();
    HoEn1ST->Write();
    
    isoPn1BT->Write();
    isoCn1BT->Write();
    isoNn1BT->Write();
    Sieien1BT->Write();
    HoEn1BT->Write();
    
    isoPn1BM->Write();
    isoCn1BM->Write();
    isoNn1BM->Write();
    Sieien1BM->Write();
    HoEn1BM->Write(); 
    
    isoPn1SM->Write();
    isoCn1SM->Write();
    isoNn1SM->Write();
    Sieien1SM->Write();
    HoEn1SM->Write();
    
    ///END OF MACRO


    cout<<"|Loose |Medium| Tight |"<<endl;
    cout<<"T "<<"|"<<HoEcutL<<"|"<<HoEcutM <<"|"<<HoEcutT <<endl;
    cout<<"S "<<"|"<<SieiecutL  <<"|"<<SieiecutM <<"|"<<SieiecutT<<endl;
    cout<<"C "<<"|"<<IsoCcutL  <<"|"<<IsoCcutM <<"|"<<IsoCcutT<<endl;
    cout<<"N "<<"|"<< IsoNcutL <<"|"<<IsoNcutM <<"|"<<IsoNcutT<<endl;
    cout<<"P "<<"|"<<IsoPcutL<<"|"<<IsoPcutM <<"|"<<IsoPcutT <<"|"<<endl;



}
