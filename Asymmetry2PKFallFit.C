#include <vector>
#include <string>
#include <TCanvas.h>
#include <TPad.h>
#include <TH1F.h>
#include <TF1.h>
#include <fstream>
#include <iostream>



void Asymmetry2PKFallFit()
{

////////////////////////////////////////////////////////////////////////////////
TCanvas*c03 = new TCanvas("c03", "Full Asymm", 1600,1000);
c03->Divide(1,1);
c03->Print("AsymmetrypTpTBinning.pdf[");

const Int_t n1 = 6;
Double_t x1[n1] = {0.05, 0.15, 0.25, 0.35, 0.45, 0.55};
Double_t y1[n1] = {-0.01027,-0.015678, -0.005777, -0.2506, -0.10195, 0.2546};
Double_t ex1[n1] = {0, 0, 0, 0, 0, 0};
Double_t ey1[n1] = {0.00378534, 0.0048328, 0.0093395, 0.02081, 0.05305, 0.1573};

TF1 *f2= new TF1("f2","[0]*x+[1]",0,6.4);
TGraphErrors*h2 = new TGraphErrors(n1,x1,y1,ex1,ey1);

h2->GetXaxis()->SetTitle("pTpT");
h2->GetXaxis()->SetTitleSize(0.05);
h2->GetXaxis()->SetLabelSize(0.05);
h2->GetXaxis()->SetTitleOffset(0.8);
h2->GetYaxis()->SetTitle("Asymmetry Value");
h2->GetYaxis()->SetTitleSize(0.05);
h2->GetYaxis()->SetLabelSize(0.02);

h2->SetMarkerStyle(8);
h2->SetMarkerSize(5);
h2->SetMarkerColor(2);

TMultiGraph*h3 = new TMultiGraph();
c03->cd(1);
h3->Add(h2);

h3->Draw("AP");
h3->GetXaxis()->SetTitle("pTpT");
h3->GetXaxis()->SetTitleSize(0.07);
h3->GetXaxis()->SetTitleOffset(0.6);
h3->GetXaxis()->SetLabelSize(0.05);
h3->GetXaxis()->SetTitleOffset(0.6);
h3->GetYaxis()->SetTitle("Asymmetry Value");
h3->GetYaxis()->SetTitleSize(0.07);
h3->GetYaxis()->SetTitleOffset(0.7);
h3->GetYaxis()->SetLabelSize(0.05);
h3->GetYaxis()->SetRangeUser(-0.3,0.3);
h3->Fit("f2");
    
    gStyle->SetOptStat(0);
    gStyle->SetOptFit();
    cout << "Chi2: " << h3->GetFunction("f2")->GetChisquare();
    cout << " Reduced Chi2: " << h3->GetFunction("f2")->GetChisquare()/(17);

c03->Update();

c03->Print("AsymmetrypTpTBinning.pdf");
c03->Print("AsymmetrypTpTBinning.pdf]");



}
