#include <vector>
#include <string>
#include <TCanvas.h>
#include <TPad.h>
#include <TH1F.h>
#include <TF1.h>
#include <fstream>
#include <iostream>



void FitMethod2Spring()
{
double phi1, asym1, err1, phi2, asym2, err2, phi3, asym3, err3, phi4, asym4, err4, phi5, asym5, err5, phi6, asym6, err6, phi7, asym7, err7, phi8, asym8, err8;

FILE * fp1 = fopen("bin1-Out.txt", "r");
FILE * fp2 = fopen("bin2-Out.txt", "r");
FILE * fp3 = fopen("bin3-Out.txt", "r");




int n=0;
int m=0;
int o=0;
int p=0;
int q=0;
int r=0;
int s=0;
int t=0;

    gStyle->SetPadTopMargin(0.1);
    gStyle->SetPadBottomMargin(0.15);
    gStyle->SetPadLeftMargin(0.15);
    gStyle->SetPadRightMargin(0.05);
    
////////////////////////////////////////////////////////////////////////////////
TCanvas*c01 = new TCanvas("c01", "Bin 1 Asymm", 900,700);
c01->Divide(1,1);
c01->Print("FitMethod2Bin1.pdf[");
TGraphErrors*h1 = new TGraphErrors();

for(int k=0; k<20; k++){
fscanf(fp1, "%lf %lf %lf ", &phi1, &asym1, &err1);

n = h1->GetN();

h1->SetPoint(n, phi1, asym1);
h1->SetPointError(n ,0, err1);

}
fclose(fp1);

////////////////////////////////////////////////////////////////////////////////
TCanvas*c02 = new TCanvas("c02", "Bin 2 Asymm", 900,700);
c02->Divide(1,1);
c02->Print("FitMethod2Bin2.pdf[");
TGraphErrors*h2 = new TGraphErrors();

for(int k=0; k<20; k++){
fscanf(fp2, "%lf %lf %lf ", &phi2, &asym2, &err2);

m = h2->GetN();

h2->SetPoint(m, phi2, asym2);
h2->SetPointError(m ,0, err2);

}
fclose(fp2);

////////////////////////////////////////////////////////////////////////////////
TCanvas*c03 = new TCanvas("c03", "Bin 3 Asymm", 900,700);
c03->Divide(1,1);
c03->Print("FitMethod2Bin3.pdf[");
TGraphErrors*h3 = new TGraphErrors();

for(int k=0; k<20; k++){
fscanf(fp3, "%lf %lf %lf ", &phi3, &asym3, &err3);

o = h3->GetN();

h3->SetPoint(o, phi3, asym3);
h3->SetPointError(o ,0, err3);

}
fclose(fp3);
 
TF1 *f2= new TF1("f2","[0]+([1]*sin(x))+([2]*(sin(2*x)))",0,6.4);

////////////////////////////////////////////////////////////////////////////////
c01->cd(1);
gStyle->SetOptStat(0);
h1->SetLineWidth(3);
h1->GetXaxis()->SetTitle("#Delta#phi");
h1->GetXaxis()->SetTitleSize(0.06);
h1->GetXaxis()->SetLabelSize(0.05);
h1->GetXaxis()->SetTitleOffset(0.6);
h1->GetXaxis()->SetTitleOffset(1);
h1->GetYaxis()->SetTitle("Raw Asymmetry (No Cuts) ");
h1->GetYaxis()->SetTitleSize(0.06);
h1->GetYaxis()->SetLabelSize(0.05);
h1->GetYaxis()->SetTitleOffset(1);
h1->GetYaxis()->SetRangeUser(-0.045,0.045);
h1->SetLineWidth(1.5);

h1->Fit("f2");
h1->SetLineWidth(1.5);
h1->SetMarkerStyle(20);
h1->SetMarkerColor(4);
    h1->SetMarkerSize(3);
h1->GetFunction("f2")->SetLineWidth(4);
cout << "Chi2: " << h1->GetFunction("f2")->GetChisquare();
cout << " Reduced Chi2: " << h1->GetFunction("f2")->GetChisquare()/(17);
h1->Draw("AP");
////////////////////////////////////////////////////////////////////////////////
c02->cd(1);
gStyle->SetOptStat(0);
//gStyle->SetOptFit();
h2->GetXaxis()->SetTitle("#Delta#phi");
h2->GetXaxis()->SetTitleSize(0.06);
h2->GetXaxis()->SetLabelSize(0.05);
h2->GetXaxis()->SetTitleOffset(1);
h2->GetYaxis()->SetTitle("RawAsymmetry (Mx>1)");
h2->GetYaxis()->SetTitleSize(0.06);
h2->GetYaxis()->SetLabelSize(0.05);
h2->GetYaxis()->SetTitleOffset(1);
h2->GetYaxis()->SetRangeUser(-0.045,0.045);
h2->SetLineWidth(1.5);

h2->Fit("f2");
h2->SetLineWidth(1.5);
h2->SetMarkerStyle(20);
h2->SetMarkerColor(4);
    h2->SetMarkerSize(3);
h2->GetFunction("f2")->SetLineWidth(4);
cout << "Chi2: " << h2->GetFunction("f2")->GetChisquare();
cout << " Reduced Chi2: " << h2->GetFunction("f2")->GetChisquare()/(17);
h2->Draw("AP");
////////////////////////////////////////////////////////////////////////////////
c03->cd(1);
gStyle->SetOptStat(0);
h3->GetXaxis()->SetTitle("#Delta#phi");
h3->GetXaxis()->SetTitleSize(0.06);
h3->GetXaxis()->SetLabelSize(0.05);
h3->GetXaxis()->SetTitleOffset(1);
h3->GetYaxis()->SetTitle("Raw Asymmetry (All Cuts)");
h3->GetYaxis()->SetTitleSize(0.06);
h3->GetYaxis()->SetLabelSize(0.05);
h3->GetYaxis()->SetTitleOffset(1);
h3->GetYaxis()->SetRangeUser(-0.045,0.045);
h3->SetLineWidth(1.5);

h3->Fit("f2");
h3->SetLineWidth(1.5);
h3->SetMarkerStyle(20);
h3->SetMarkerColor(4);
    h3->SetMarkerSize(3);
h3->GetFunction("f2")->SetLineWidth(4);
cout << "Chi2: " << h3->GetFunction("f2")->GetChisquare();
cout << " Reduced Chi2: " << h3->GetFunction("f2")->GetChisquare()/(17);
h3->Draw("AP");
 
}
