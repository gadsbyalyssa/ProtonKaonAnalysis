#include <vector>
#include <string>
#include <TCanvas.h>
#include <TPad.h>
#include <TH1F.h>
#include <TF1.h>
#include <fstream>
#include <iostream>



void Asymmetry2PKFall()
{

////////////////////////////////////////////////////////////////////////////////
TCanvas*c03 = new TCanvas("c03", "Full Asymm", 1600,1000);
c03->Divide(1,1);
c03->Print("FullAsymmetry2PK3.pdf[");

const Int_t n1 = 6;
Double_t x1[n1] = {0.05, 0.15, 0.25, 0.35, 0.45, 0.55};
Double_t y1[n1] = {-0.01448027001210511,-0.014319812040954056, -0.012046525666751323, 0.016198365401310963, -0.0465595001749183, -0.07951837857719678};
Double_t ex1[n1] = {0, 0, 0, 0, 0, 0};
Double_t ey1[n1] = {0.00087543857, 0.000886703384, 0.0012465221046204268, 0.0018805910306408712, 0.002902221909605188, 0.004493249531920615};

const Int_t n2 = 5;
Double_t x2[n2] = {0.05, 0.15, 0.25, 0.35, 0.45};
Double_t y2[n2] = {-0.01373, -0.01518, -0.010927, 0.015887, -0.063507 };
Double_t ex2[n2] = {0, 0, 0, 0, 0};
Double_t ey2[n2] = {0.005241, 0.005683, 0.009488, 0.01848, 0.04077};

const Int_t n3 = 6;
Double_t x3[n3] = {0.05, 0.15, 0.25, 0.35, 0.45, 0.55};
Double_t y3[n3] = {-0.014705050435864257, -0.01996717169818551, -0.01074723952261063, -0.0170808283315638, -0.011057980142055652, -0.09643827566078832};
Double_t ex3[n3] = {0, 0, 0, 0, 0, 0};
Double_t ey3[n3] = {0.00087543857, 0.000886703384, 0.0012465221046204268, 0.001902221909605188, 0.002493249531920615, 0.007085874489312935};

const Int_t n4 = 6;
Double_t x4[n4] = {0.05, 0.15, 0.25, 0.35, 0.45, 0.55};
Double_t y4[n4] = {-0.01491, -0.02036, -0.012853, -0.0101644, -0.03491, 0.02456 };
Double_t ex4[n4] = {0, 0, 0, 0, 0, 0};
Double_t ey4[n4] = {0.004978, 0.005449, 0.00937, 0.01848, 0.04077, 0.0176};

//TGraphErrors*h1 = new TGraphErrors();
TGraphErrors*h2 = new TGraphErrors(n1,x1,y1,ex1,ey1);
h2->SetName("h2");
TGraphErrors*h4 = new TGraphErrors(n3,x3,y3,ex3,ey3);
h4->SetName("h4");
TGraphErrors*h7 = new TGraphErrors(n2,x2,y2,ex2,ey2);
h7->SetName("h7");
TGraphErrors*h1 = new TGraphErrors(n4,x4,y4,ex4,ey4);
h1->SetName("h1");

TMultiGraph*h3 = new TMultiGraph();

////////////////////////////////////////////////////////////////////////////
 
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

////////////////////////////////////////////////////////////////////////////////
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

h4->SetMarkerStyle(29);
h4->SetMarkerSize(5);
h4->SetMarkerColor(1);

h7->SetMarkerStyle(33);
h7->SetMarkerSize(5);
h7->SetMarkerColor(6);

////////////////////////////////////////////////////////////////////////////////
c03->cd(1); 
h3->Add(h1);
h3->Add(h2);
h3->Add(h4);
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


TLegend*legend = new TLegend(0.1,0.8,0.5,1);

legend->AddEntry("h2", "Moments Method (Fall 2018)","p");
legend->AddEntry("h7", "Difference Method (Fall 2018)", "p");
legend->AddEntry("h4", "Moments Method (Spring 2019)", "p");
legend->AddEntry("h1", "Difference Method (Spring 2019)", "p");

legend->SetBorderSize(7);
legend->Draw();
c03->Update();

c03->Print("FullAsymmetry2PK3.pdf");
c03->Print("FullAsymmetry2PK3.pdf]");



}
