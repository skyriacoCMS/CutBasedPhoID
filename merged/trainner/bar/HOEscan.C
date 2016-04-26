#include <cstdlib>
#include <TMath.h>


void HOEscan(){


  TFile *f1 = new TFile("../../CutTMVABarrel_200.root");


  float ToE,Sie,IsoP,IsoC,IsoN,weighT,Ppt; 

  ofstream myfile; 
  myfile.open("99per.txt");

  t_S->SetBranchAddress("Ppt",&Ppt);
  t_S->SetBranchAddress("ToE",&ToE);
  t_S->SetBranchAddress("Sieie",&Sie);
  t_S->SetBranchAddress("isoP",&IsoP);
  t_S->SetBranchAddress("isoC",&IsoC);
  t_S->SetBranchAddress("isoN",&IsoN);
  t_S->SetBranchAddress("weighT",&weighT);

  cout<<t_S->GetEntries()<<endl;
  double totS = 0; 
  double cutH = 0; 
  for(int i = 0; i < t_S->GetEntries(); i++){
    t_S->GetEntry(i);

    if(Ppt < 15  ) continue;
    if(Ppt > 200 ) continue;

    totS = totS + weighT;

    //cout<<" totals  "<<totS<<endl;
    if(ToE < 0.05) cutH = cutH + weighT ;
  }

  cout<<cutH/totS<<endl;


}
