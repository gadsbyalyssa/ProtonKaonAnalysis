#include <vector>
#include <string>
#include <TCanvas.h>
#include <TPad.h>
#include <TH1F.h>
#include <TF1.h>
#include <fstream>
#include <iostream>



void Asymmetry2PKSpring()
{
double pTpT1, asym1, err1;

FILE * fp1 = fopen("NewAsymmetry-Out.txt", "r"); 

int n=0;

////////////////////////////////////////////////////////////////////////////////
TCanvas*c01 = new TCanvas("c01", "Full Asymm", 1600,1000);
c01->Divide(1,1);
c01->Print("FullAsymmetry2PK1.pdf[");
TCanvas*c02 = new TCanvas("c02", "Full Asymm", 1600,1000);
c02->Divide(1,1);
c02->Print("FullAsymmetry2P2.pdf[");
TCanvas*c03 = new TCanvas("c03", "Full Asymm", 1600,1000);
c03->Divide(1,1);
c03->Print("FullAsymmetry2PK3.pdf[");

const Int_t n1 = 6;
Double_t x1[n1] = {0.05, 0.15, 0.25, 0.35, 0.45, 0.55};
Double_t y1[n1] = {-0.01252543356047092, -0.012386637415425257, -0.010420244701739894, -0.04027396765130433, -0.06878339746927521, -0.02300126877105941};
Double_t ex1[n1] = {0, 0, 0, 0, 0, 0};
Double_t ey1[n1] = {0.00087543857, 0.000886703384, 0.0012465221046204268, 0.002902221909605188, 0.004493249531920615, 0.007085874489312935};

const Int_t n2 = 6;
Double_t x2[n2] = {0.05, 0.15, 0.25, 0.35, 0.45, 0.55};
Double_t y2[n2] = {-0.01491, -0.02036, -0.012853, -0.0101644, -0.03491, 0.02456 };
Double_t ex2[n2] = {0, 0, 0, 0, 0, 0};
Double_t ey2[n2] = {0.004978, 0.005449, 0.00937, 0.01848, 0.04077, 0.0176};
/*
const Int_t n3 = 5;
Double_t x3[n3] = {0.1, 0.3, 0.5, 0.7, 0.9};
Double_t y3[n3] = {-0.024378417848396363,  -0.001846455911838189, -0.017106187468694977, -0.02529605143320063, -0.02131818544515851};
Double_t ex3[n3] = {0, 0, 0, 0, 0};
Double_t ey3[n3] = {0.060498, 0.013351, 0.00929, 0.012315, 0.027537};
*/
//TGraphErrors*h1 = new TGraphErrors();
TGraphErrors*h2 = new TGraphErrors(n1,x1,y1,ex1,ey1);
h2->SetName("h2");
//TGraphErrors*h4 = new TGraphErrors(n3,x3,y3,ex3,ey3);
//h4->SetName("h4");
TGraphErrors*h7 = new TGraphErrors(n2,x2,y2,ex2,ey2);
h7->SetName("h7");

TMultiGraph*h3 = new TMultiGraph();

/*
for(int k=0; k<5; k++){ 
fscanf(fp1, "%lf %lf %lf ", &pTpT1, &asym1, &err1);

n = h1->GetN();

h1->SetPoint(n, pTpT1, asym1);
h1->SetPointError(n ,0, err1);

}
fclose(fp1);
*/
////////////////////////////////////////////////////////////////////////////////
/*c01->cd(1); 
h1->SetName("h1");
h1->GetXaxis()->SetTitle("pTpT");
h1->GetXaxis()->SetTitleSize(0.05);
h1->GetXaxis()->SetLabelSize(0.05);
h1->GetXaxis()->SetTitleOffset(1);
h1->GetYaxis()->SetTitle("Asymmetry Value");
h1->GetYaxis()->SetTitleSize(0.05);
h1->GetYaxis()->SetLabelSize(0.02);

h1->SetMarkerStyle(20);
h1->SetMarkerSize(5);
h1->SetMarkerColor(4);
h1->Draw("AP");
*/
////////////////////////////////////////////////////////////////////////////////
c02->cd(1);
h2->SetName("h2");
h2->GetXaxis()->SetTitle("pTpT");
h2->GetXaxis()->SetTitleSize(0.05);
h2->GetXaxis()->SetLabelSize(0.05);
h2->GetXaxis()->SetTitleOffset(0.8);
h2->GetYaxis()->SetTitle("Asymmetry Value");
h2->GetYaxis()->SetTitleSize(0.05);
h2->GetYaxis()->SetLabelSize(0.02);

h2->SetMarkerStyle(24);
h2->SetMarkerSize(5);
h2->SetMarkerColor(2);
h2->Draw("AP");
/*
h4->SetMarkerStyle(29);
h4->SetMarkerSize(5);
h4->SetMarkerColor(1);
*/
h7->SetMarkerStyle(33);
h7->SetMarkerSize(5);
h7->SetMarkerColor(6);

////////////////////////////////////////////////////////////////////////////////
c03->cd(1); 
//h3->Add(h1);
h3->Add(h2);
//h3->Add(h4);
h3->Add(h7);

h3->Draw("AP");
h3->GetXaxis()->SetTitle("pTpT");
h3->GetXaxis()->SetTitleSize(0.06);
h3->GetXaxis()->SetTitleOffset(0.4);
h3->GetXaxis()->SetLabelSize(0.03);
h3->GetXaxis()->SetTitleOffset(0.8);
h3->GetYaxis()->SetTitle("Asymmetry Value");
h3->GetYaxis()->SetTitleSize(0.07);
h3->GetYaxis()->SetTitleOffset(0.6);
h3->GetYaxis()->SetLabelSize(0.03);


TLegend*legend = new TLegend(0.7,0.8,1,1);

legend->AddEntry("h2", "Moments Method (New Data)","p");
//legend->AddEntry("h1", "Difference Method", "p");
legend->AddEntry("h7", "Difference Method", "p");
//legend->AddEntry("h4", "Moments Method (Mx>1) 20 bins", "p");

legend->SetBorderSize(7);
legend->Draw();
c03->Update();

c01->Print("FullAsymmetry2PK1.pdf");
c01->Print("FullAsymmetry2PK1.pdf]");
c02->Print("FullAsymmetry2PK2.pdf");
c02->Print("FullAsymmetry2PK2.pdf]");
c03->Print("FullAsymmetry2PK3.pdf");
c03->Print("FullAsymmetry2PK3.pdf]");



}
