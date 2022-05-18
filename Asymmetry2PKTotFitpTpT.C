#include <vector>
#include <string>
#include <TCanvas.h>
#include <TPad.h>
#include <TH1F.h>
#include <TF1.h>
#include <fstream>
#include <iostream>



void Asymmetry2PKTotFitpTpT()
{

////////////////////////////////////////////////////////////////////////////////
TCanvas*c03 = new TCanvas("c03", "Full Asymm", 1000,700);
c03->Divide(1,1);
c03->Print("AsymmetrypTpTBinning.pdf[");

const Int_t n1 = 5;
Double_t x1[n1] = {0.05, 0.15, 0.25, 0.35, 0.45};
    Double_t y1[n1] = {-0.013357, -0.012618, -0.0040033, -0.016483, -0.083751};
Double_t ex1[n1] = {0, 0, 0, 0, 0};
Double_t ey1[n1] = {0.00262711, 0.00337627, 0.0066033, 0.015088, 0.0400387};

TF1 *f2= new TF1("f2","[0]*x+[1]",0,6.4);
TGraphErrors*h3 = new TGraphErrors(n1,x1,y1,ex1,ey1);


h3->SetMarkerStyle(8);
h3->SetMarkerSize(3);
h3->SetMarkerColor(2);
h3->SetLineColor(2);
h3->GetXaxis()->SetTitle("p_{#perp} Kaon*p_{#perp} Proton");
h3->GetXaxis()->SetTitleSize(0.08);
h3->GetXaxis()->SetTitleOffset(0.6);
h3->GetXaxis()->SetLabelSize(0.05);
h3->GetYaxis()->SetTitle("Raw Asymmetry");
h3->GetYaxis()->SetTitleSize(0.1);
h3->GetYaxis()->SetTitleOffset(0.6);
h3->GetYaxis()->SetLabelSize(0.05);
h3->GetYaxis()->SetRangeUser(-0.1,0.01);
    h3->SetTitle("");
    h3->Draw("AP");
    
    gStyle->SetOptStat(0);
    gStyle->SetOptFit();
    cout << "Chi2: " << h3->GetFunction("f2")->GetChisquare();
    cout << " Reduced Chi2: " << h3->GetFunction("f2")->GetChisquare()/(17);

c03->Update();

c03->Print("AsymmetrypTpTBinning.pdf");
c03->Print("AsymmetrypTpTBinning.pdf]");



}
