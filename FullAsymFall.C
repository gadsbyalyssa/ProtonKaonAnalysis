#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include "TBrowser.h"
#include "TH2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <TH1F.h>
#include <TMath.h>
#include <fstream>
#include <iostream>

void FullAsymFall(){
     Float_t runnum, evnum, helicity,  e_p, eta1, eta, e_phi, Q2, W, phi2, phi1, x, y, zeta, xF, pT1, pT2, Delta_phi, z1, z2, xF1, xF2, pTpT, Mx1, Mx2, Delta_eta, p1_p, p2_p, vz_e,vz_p1,vz_p2, eta2, Mx;


    FILE *fp = fopen("PKFall2018Skim4.txt","r");
    TFile *hfile = hfile = TFile::Open("PKplus2.root","RECREATE");

    TTree *outTree = new TTree("T","kinematics tree");


    outTree->Branch("runnum",&runnum,"runnum/F");
    outTree->Branch("evnum",&evnum,"evnum/F");
    outTree->Branch("helicity", &helicity,"helicity/F");
    outTree->Branch("e_p",&e_p,"e_p/F");
    outTree->Branch("eta1",&eta1,"eta1/F");
    outTree->Branch("eta",&eta,"eta/F");
    outTree->Branch("e_phi",&e_phi,"e_phi/F");
    outTree->Branch("Q2",&Q2,"Q2/F");
    outTree->Branch("W",&W,"W/F");
    outTree->Branch("phi2",&phi2,"phi2/F");
    outTree->Branch("phi1",&phi1,"phi1/F");
    outTree->Branch("x",&x,"x/F");
    outTree->Branch("y",&y,"y/F");
    outTree->Branch("zeta",&zeta,"zeta/F");
    outTree->Branch("xF",&xF,"xF/F");
    outTree->Branch("pT1",&pT1,"pT1/F");
    outTree->Branch("pT2",&pT2,"pT2/F");
    outTree->Branch("Delta_phi",&Delta_phi,"Delta_phi/F");
    outTree->Branch("z1",&z1,"z1/F");
    outTree->Branch("z2",&z2,"z2/F");
    outTree->Branch("xF1",&xF1,"xF1/F");
    outTree->Branch("xF2",&xF2,"xF2/F");
    outTree->Branch("pTpT",&pTpT,"pTpT/F");
    outTree->Branch("Mx1",&Mx1,"Mx1/F");
    outTree->Branch("Mx2",&Mx2,"Mx2/F");
    outTree->Branch("Delta_eta",&Delta_eta,"Delta_eta/F");
    outTree->Branch("p1_p",&p1_p,"p1_p/F");
    outTree->Branch("p2_p",&p2_p,"p2_p/F");
    outTree->Branch("vz_e",&vz_e,"vz_e/F");
    outTree->Branch("vz_p1",&vz_p2,"vz_p1/F");
    outTree->Branch("eta1",&eta1,"vz_p2/F");
    outTree->Branch("eta2",&eta2,"eta2/F");
    outTree->Branch("Mx",&Mx,"Mx/F");



    for(int k=0; k<1859448; k++){

    fscanf(fp, "%f %f %f %f %f %f %f ", &runnum, &evnum, &helicity, &e_p, &eta1, &eta, &e_phi);

    fscanf(fp, " %f %f %f %f %f %f %f %lf ", &Q2, &W, &phi2, &phi1, &x, &y, &zeta, &xF);

    fscanf(fp, " %f %f %f %f %f %f %f %f %f ", &pT1, &pT2, &Delta_phi, &z1, &z2, &xF1, &xF2, &pTpT, &Mx1);

    fscanf(fp, " %f %f %f %f %f %f %f %f %f ", &Mx2, &Delta_eta, &p1_p, &p2_p, &vz_e, &vz_p1, &vz_p2, &eta2, &Mx);

    outTree->Fill();

    }

//outTree->Print();
outTree->Write();
fclose(fp);
hfile->Write();
///////////////////////////////////////////////////////////////
TCut NegHeli = ("helicity == -1");
TCut PosHeli = ("helicity == 1");
TCut Mxg1 = ("");
TCut Mxg2 = ("Mx>1");
TCut Mxg3 = ("Mx>1 && y<0.75 && xF1<0 && xF2>0 && -8<vz_e&&vz_e<2 && 1.15<p2_p&&p2_p<3 && 0.4<p1_p && e_p>2.35 && vz_p2<13 && vz_p1<13");
///////////////////////////////////////////////////////////////
TH1F*h26 = new TH1F("h26","h26",20, 0, 6.4);
outTree->Draw("Delta_phi>>h26");
///////////////////////////////////////////////////////////////
TCanvas*c01 = new TCanvas("c01", "PKplus", 1600,1100);
c01->Divide(2,1);
TH1F*h1 = new TH1F("h1","h1",20, 0, 6.4);
c01->cd(1);
h1->GetXaxis()->SetTitle("");
h1->GetXaxis()->SetTitleSize(0.03);
h1->GetXaxis()->SetLabelSize(0.02);
h1->GetXaxis()->SetTitleOffset(1);
h1->GetYaxis()->SetTitle("Counts");
h1->GetYaxis()->SetTitleSize(0.035);
h1->GetYaxis()->SetLabelSize(0.02);
h1->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h1", PosHeli && Mxg1);
///////////////////////////////////////////////////////////////
TH1F*h2 = new TH1F("h2","h2",20, 0, 6.4);
c01->cd(2);
h2->GetXaxis()->SetTitle("");
h2->GetXaxis()->SetTitleSize(0.03);
h2->GetXaxis()->SetLabelSize(0.02);
h2->GetXaxis()->SetTitleOffset(1);
h2->GetYaxis()->SetTitle("Counts");
h2->GetYaxis()->SetTitleSize(0.035);
h2->GetYaxis()->SetLabelSize(0.02);
h2->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h2", NegHeli && Mxg1);

ofstream outputfile1("FitMethodBin1.txt");
int N = h1->GetNbinsX() + 1; 
for(int i=0; i<N; ++i){
outputfile1 << "\t" << h26->GetBinLowEdge(i)+h26->GetBinWidth(i)/2  << "\t" << h1->GetBinContent(i) << "\t" << h2->GetBinContent(i) << endl; }
outputfile1.close();
///////////////////////////////////////////////////////////////
TCanvas*c02 = new TCanvas("c02", "PKplus", 1600,1100);
c02->Divide(2,1);
TH1F*h3 = new TH1F("h3","h3",20, 0, 6.4);
c02->cd(1);
h3->GetXaxis()->SetTitle("");
h3->GetXaxis()->SetTitleSize(0.03);
h3->GetXaxis()->SetLabelSize(0.02);
h3->GetXaxis()->SetTitleOffset(1);
h3->GetYaxis()->SetTitle("Counts");
h3->GetYaxis()->SetTitleSize(0.035);
h3->GetYaxis()->SetLabelSize(0.02);
h3->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h3", PosHeli && Mxg2);
///////////////////////////////////////////////////////////////
TH1F*h4 = new TH1F("h4","h4",20, 0, 6.4);
c02->cd(2);
h4->GetXaxis()->SetTitle("");
h4->GetXaxis()->SetTitleSize(0.03);
h4->GetXaxis()->SetLabelSize(0.02);
h4->GetXaxis()->SetTitleOffset(1);
h4->GetYaxis()->SetTitle("Counts");
h4->GetYaxis()->SetTitleSize(0.035);
h4->GetYaxis()->SetLabelSize(0.02);
h4->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h4", NegHeli && Mxg2);


ofstream outputfile2("FitMethodBin2.txt");
for(int i=0; i<N; ++i){
outputfile2 << "\t" << h26->GetBinLowEdge(i)+h26->GetBinWidth(i)/2  << "\t" << h3->GetBinContent(i) << "\t" << h4->GetBinContent(i) << endl; }
outputfile2.close();
///////////////////////////////////////////////////////////////
TCanvas*c03 = new TCanvas("c03", "PKplus", 1600,1100);
c03->Divide(2,1);
TH1F*h5 = new TH1F("h5","h5",20, 0, 6.4);
c03->cd(1);
h5->GetXaxis()->SetTitle("");
h5->GetXaxis()->SetTitleSize(0.03);
h5->GetXaxis()->SetLabelSize(0.02);
h5->GetXaxis()->SetTitleOffset(1);
h5->GetYaxis()->SetTitle("Counts");
h5->GetYaxis()->SetTitleSize(0.035);
h5->GetYaxis()->SetLabelSize(0.02);
h5->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h5", PosHeli && Mxg3);
///////////////////////////////////////////////////////////////
TH1F*h6 = new TH1F("h6","h6",20, 0, 6.4);
c03->cd(2);
h6->GetXaxis()->SetTitle("");
h6->GetXaxis()->SetTitleSize(0.03);
h6->GetXaxis()->SetLabelSize(0.02);
h6->GetXaxis()->SetTitleOffset(1);
h6->GetYaxis()->SetTitle("Counts");
h6->GetYaxis()->SetTitleSize(0.035);
h6->GetYaxis()->SetLabelSize(0.02);
h6->GetYaxis()->SetTitleOffset(0.9);
outTree->Draw("Delta_phi>>h6", NegHeli && Mxg3);

ofstream outputfile3("FitMethodBin3.txt");
for(int i=0; i<N; ++i){
outputfile3 << "\t" << h26->GetBinLowEdge(i)+h26->GetBinWidth(i)/2  << "\t" << h5->GetBinContent(i) << "\t" << h6->GetBinContent(i) << endl; }
outputfile3.close();



}







