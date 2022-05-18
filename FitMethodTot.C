#include <vector>
#include <string>
#include <TCanvas.h>
#include <TPad.h>
#include <TNamed.h>
#include <TH1F.h>
#include <TF1.h>
#include <TMath.h>
#include <fstream>
#include <iostream>
#include <cmath>



void FitMethodTot()
{
double c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, c31, c32, c33;
vector <double> c3_list, c18_list, c23_list, c33_list, c28_list ;

FILE * fp = fopen("PKTotalSkim8.txt", "r");

int j, k;
TCanvas*c01 = new TCanvas("c01", "A1", 1600,1100);
c01->Divide(1,1);
c01->Print("FitMethodPK1.pdf[");
TCanvas*c02 = new TCanvas("c02", "A2", 1600,1100);
c02->Divide(1,1);
c02->Print("FitMethodPK2.pdf[");
TCanvas*c03 = new TCanvas("c03", "A3", 1600,1100);
c03->Divide(1,1);
c03->Print("FitMethodPK3.pdf[");
TCanvas*c04 = new TCanvas("c04", "A4", 1600,1100);
c04->Divide(1,1);
c04->Print("FitMethodPK4.pdf[");
TCanvas*c05 = new TCanvas("c05", "A5", 1600,1100);
c05->Divide(1,1);
c05->Print("FitMethodPK5.pdf[");
TCanvas*c06 = new TCanvas("c06", "A6", 1600,1100);
c06->Divide(1,1);
c06->Print("FitMethodPK6.pdf[");
TCanvas*c07 = new TCanvas("c07", "A7", 1600,1100);
c07->Divide(1,1);
c07->Print("FitMethodPK7.pdf[");
TCanvas*c08 = new TCanvas("c08", "A8", 1600,1100);
c08->Divide(1,1);
c08->Print("FitMethodPK8.pdf[");


gStyle->SetErrorX(0);

TH1F*h1 = new TH1F("","",20,0,6.4);
TH1F*h2 = new TH1F("","",20,0,6.4);
TH1F*h4 = new TH1F("","",20,0,6.4); 
TH1F*h6 = new TH1F("","",20,0,6.4); 
TH1F*h7 = new TH1F("","",20,0,6.4); 
TH1F*h9 = new TH1F("","",20,0,6.4); 
TH1F*h11 = new TH1F("","",20,0,6.4); 
TH1F*h12 = new TH1F("","",20,0,6.4); 
TH1F*h14 = new TH1F("","",20,0,6.4); 
TH1F*h16 = new TH1F("","",20,0,6.4); 
TH1F*h17 = new TH1F("","",20,0,6.4); 
TH1F*h19 = new TH1F("","",20,0,6.4); 
TH1F*h21 = new TH1F("","",20,0,6.4); 
TH1F*h22 = new TH1F("","",20,0,6.4); 
TH1F*h24 = new TH1F("","",20,0,6.4); 
TH1F*h26 = new TH1F("","",20,0,6.4);


char line[450];
while (fgets(&line,450,fp) ){ 

fscanf(fp, "%lf %lf %lf %lf %lf %lf %lf ", &c1, &c2, &c3, &c4, &c5, &c6, &c7);

fscanf(fp, " %lf %lf %lf %lf %lf %lf %lf %lf %lf ", &c8, &c9, &c10, &c11, &c12, &c13, &c14, &c15, &c16);

fscanf(fp, " %lf %lf %lf %lf %lf %lf %lf %lf %lf ", &c17, &c18, &c19, &c20, &c21, &c22, &c23, &c24, &c25);

fscanf(fp, " %lf %lf %lf %lf %lf %lf %lf %lf ", &c26, &c27, &c28, &c29, &c30, &c31, &c32, &c33);

h26->Fill(c3);

c3_list.push_back(c3);
c18_list.push_back(c18);
c23_list.push_back(c23);
    c28_list.push_back(c28);
c33_list.push_back(c33);

}

fclose(fp);



/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////Asymmetry 0<pTpT<0.1
for (int i=0; i<c3_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c28_list[i]>3)
{ h1->Fill(c18_list[i]);}
else if (c3_list[i]==-1 && c33_list[i]>1 && c28_list[i]>3)
{ h2->Fill(c18_list[i]);}
}
TH1F*h3 = new TH1F("","",20,0, 6.4);

for (int i=0; i<c3_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0 && c23_list[i]<0.1){ h3->Fill(c18_list[i]);} 
}
for (int i=0; i<c3_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0 && c23_list[i]<0.1){ h4->Fill(c18_list[i]);} 
}
/////////////////////////////////////////////////////////////////////
TF1 *f1= new TF1("f1","[0]+([1]*sin(x))+([2]*(sin(2*x)))",0,6.4); 
/////////////////////////////////////////////////////////////////////
h3->Add(h2, -1.0);
h4->Add(h2, 1.0);
TH1F*h5 = (TH1F*) h3->Clone("h5");
h5->Divide(h3,h4);
/////////////////////////////////////////////////////////////////////Asymmetry 0.1<pTpT<0.2
for (int i=0; i<c3_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1)
{ h6->Fill(c18_list[i]);}
else if (c3_list[i]==-1 && c33_list[i]>1)
{ h7->Fill(c18_list[i]);}
}
TH1F*h8 = new TH1F("","",20,0, 6.4);

for (int i=0; i<c3_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.1 && c23_list[i]<0.2){ h8->Fill(c18_list[i]);} 
}
for (int i=0; i<c3_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.1 && c23_list[i]<0.2){ h9->Fill(c18_list[i]);} 
}
/////////////////////////////////////////////////////////////////////
TF1 *f1= new TF1("f1","[0]+([1]*sin(x))+([2]*(sin(2*x)))",0,6.4); 
/////////////////////////////////////////////////////////////////////
h8->Add(h7, -1.0);
h9->Add(h7, 1.0);
TH1F*h10 = (TH1F*) h8->Clone("h10");
h10->Divide(h8,h9);
/////////////////////////////////////////////////////////////////////Asymmetry 0.2<pTpT<0.3
for (int i=0; i<c3_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.2 && c23_list[i]<0.3){ h11->Fill(c18_list[i]);} 
else if (c3_list[i]==-1 && c33_list[i]>1 && c23_list[i]>0.2 && c23_list[i]<0.3){ h12->Fill(c18_list[i]);} 
}
TH1F*h13 = new TH1F("","",20,0, 6.4);

for (int i=0; i<c3_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.2 && c23_list[i]<0.3){ h13->Fill(c18_list[i]);} 
}
for (int i=0; i<c3_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.2 && c23_list[i]<0.3){ h14->Fill(c18_list[i]);} 
}
/////////////////////////////////////////////////////////////////////
TF1 *f1= new TF1("f1","[0]+([1]*sin(x))+([2]*(sin(2*x)))",0,6.4); 
/////////////////////////////////////////////////////////////////////
h13->Add(h12, -1.0);
h14->Add(h12, 1.0);
TH1F*h15 = (TH1F*) h13->Clone("h15");
h15->Divide(h13,h14);
/////////////////////////////////////////////////////////////////////Asymmetry 0.3<pTpT<0.4
for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.3 && c23_list[i]<0.4){ h16->Fill(c18_list[i]);} 
else if (c3_list[i]==-1 && c33_list[i]>1 && c23_list[i]>0.3 && c23_list[i]<0.4){ h17->Fill(c18_list[i]);} 
}
TH1F*h18 = new TH1F("","",20,0, 6.4);

for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.3 && c23_list[i]<0.4){ h18->Fill(c18_list[i]);} 
}
for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.3 && c23_list[i]<0.4){ h19->Fill(c18_list[i]);} 
}
/////////////////////////////////////////////////////////////////////
TF1 *f1= new TF1("f1","[0]+([1]*sin(x))+([2]*(sin(2*x)))",0,6.4); 
/////////////////////////////////////////////////////////////////////
h18->Add(h17, -1.0);
h19->Add(h17, 1.0);
TH1F*h20 = (TH1F*) h18->Clone("h20");
h20->Divide(h18,h19);
/////////////////////////////////////////////////////////////////////Asymmetry 0.4<pTpT<0.5
for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.4 && c23_list[i]<0.5){ h21->Fill(c18_list[i]);} 
else if (c3_list[i]==-1 && c33_list[i]>1 && c23_list[i]>0.4 && c23_list[i]<0.5){ h22->Fill(c18_list[i]);} 
}
TH1F*h23 = new TH1F("","",20,0, 6.4);

for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.4 && c23_list[i]<0.5){ h23->Fill(c18_list[i]);} 
}
for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.4 && c23_list[i]<0.5){ h24->Fill(c18_list[i]);} 
}
/////////////////////////////////////////////////////////////////////
TF1 *f1= new TF1("f1","[0]+([1]*sin(x))+([2]*(sin(2*x)))",0,6.4); 
/////////////////////////////////////////////////////////////////////
h23->Add(h22, -1.0);
h24->Add(h22, 1.0);
TH1F*h25 = (TH1F*) h23->Clone("h25");
h25->Divide(h23,h24);
/////////////////////////////////////////////////////////////////////Asymmetry 0.5<pTpT<0.6
TH1F*h31 = new TH1F("","",20,0, 6.4);
TH1F*h32 = new TH1F("","",20,0, 6.4);
TH1F*h34 = new TH1F("","",20,0, 6.4);

for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.5 && c23_list[i]<0.6){ h31->Fill(c18_list[i]);} 
else if (c3_list[i]==-1 && c33_list[i]>1 && c23_list[i]>0.5 && c23_list[i]<0.6){ h32->Fill(c18_list[i]);} 
}
TH1F*h33 = new TH1F("","",20,0, 6.4);

for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.5 && c23_list[i]<0.6){ h33->Fill(c18_list[i]);} 
}
for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.5 && c23_list[i]<0.6){ h34->Fill(c18_list[i]);} 
}
/////////////////////////////////////////////////////////////////////
TF1 *f1= new TF1("f1","[0]+([1]*sin(x))+([2]*(sin(2*x)))",0,6.4); 
/////////////////////////////////////////////////////////////////////
h33->Add(h32, -1.0);
h34->Add(h32, 1.0);
TH1F*h35 = (TH1F*) h33->Clone("h35");
h35->Divide(h33,h34);
/////////////////////////////////////////////////////////////////////Asymmetry 0.6<pTpT<0.7
TH1F*h41 = new TH1F("","",20,0, 6.4);
TH1F*h42 = new TH1F("","",20,0, 6.4);
TH1F*h44 = new TH1F("","",20,0, 6.4);

for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.6 && c23_list[i]<0.7){ h41->Fill(c18_list[i]);} 
else if (c3_list[i]==-1 && c33_list[i]>1 && c23_list[i]>0.6 && c23_list[i]<0.7){ h42->Fill(c18_list[i]);} 
}
TH1F*h43 = new TH1F("","",20,0, 6.4);

for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.6 && c23_list[i]<0.7){ h43->Fill(c18_list[i]);} 
}
for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.6 && c23_list[i]<0.7){ h44->Fill(c18_list[i]);} 
}
/////////////////////////////////////////////////////////////////////
TF1 *f1= new TF1("f1","[0]+([1]*sin(x))+([2]*(sin(2*x)))",0,6.4); 
/////////////////////////////////////////////////////////////////////
h43->Add(h42, -1.0);
h44->Add(h42, 1.0);
TH1F*h45 = (TH1F*) h43->Clone("h45");
h45->Divide(h43,h44);
/////////////////////////////////////////////////////////////////////Asymmetry 0.7<pTpT<0.8
TH1F*h51 = new TH1F("","",20,0, 6.4);
TH1F*h52 = new TH1F("","",20,0, 6.4);
TH1F*h54 = new TH1F("","",20,0, 6.4);

for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.7 && c23_list[i]<0.8){ h51->Fill(c18_list[i]);} 
else if (c3_list[i]==-1 && c33_list[i]>1 && c23_list[i]>0.7 && c23_list[i]<0.8){ h52->Fill(c18_list[i]);} 
}
TH1F*h53 = new TH1F("","",20,0, 6.4);

for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.7 && c23_list[i]<0.8){ h53->Fill(c18_list[i]);} 
}
for (int i=0; i<c33_list.size(); i++) { 
if (c3_list[i]==1 && c33_list[i]>1 && c23_list[i]>0.7 && c23_list[i]<0.8){ h54->Fill(c18_list[i]);} 
}
/////////////////////////////////////////////////////////////////////
TF1 *f1= new TF1("f1","[0]+([1]*sin(x))+([2]*(sin(2*x)))",0,6.4); 
/////////////////////////////////////////////////////////////////////
h53->Add(h52, -1.0);
h54->Add(h52, 1.0);
TH1F*h55 = (TH1F*) h53->Clone("h55");
h55->Divide(h53,h54);
/////////////////////////////////////////////////////////////////////
ofstream outputfile("FitMethodBin2.txt");
int N = h51->GetNbinsX() + 1;  
for(int i=0; i<N; ++i){
outputfile << "\t" << h26->GetBinLowEdge(i)+h26->GetBinWidth(i)/2  << "\t" << h6->GetBinContent(i) << "\t" << h7->GetBinContent(i) << endl; }
outputfile.close(); 

/////////////////////////////////////////////////////////////////////
c01->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h5->GetXaxis()->SetTitle("DeltaPhi");
h5->GetXaxis()->SetTitleSize(0.05);
h5->GetXaxis()->SetLabelSize(0.03);
h5->GetXaxis()->SetTitleOffset(1);
h5->GetYaxis()->SetTitle("Asymmetry (Mx>1 0<pTpT<0.1)");
h5->GetYaxis()->SetTitleSize(0.05);
h5->GetYaxis()->SetLabelSize(0.03);
h5->SetLineWidth(1.5);

h5->SetLineWidth(1.5);
h5->SetMarkerStyle(20);
h5->SetMarkerColor(4);
h5->Draw("P");
/////////////////////////////////////////////////////////////////////
c02->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h10->GetXaxis()->SetTitle("DeltaPhi");
h10->GetXaxis()->SetTitleSize(0.05);
h10->GetXaxis()->SetLabelSize(0.03);
h10->GetXaxis()->SetTitleOffset(1);
h10->GetYaxis()->SetTitle("Asymmetry (Mx>1 0.1<pTpT<0.2)");
h10->GetYaxis()->SetTitleSize(0.05);
h10->GetYaxis()->SetLabelSize(0.03);
h10->SetLineWidth(1.5);

h10->SetLineWidth(1.5);
h10->SetMarkerStyle(20);
h10->SetMarkerColor(4);
h10->Draw("P");
/////////////////////////////////////////////////////////////////////
c03->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h15->GetXaxis()->SetTitle("DeltaPhi");
h15->GetXaxis()->SetTitleSize(0.05);
h15->GetXaxis()->SetLabelSize(0.03);
h15->GetXaxis()->SetTitleOffset(1);
h15->GetYaxis()->SetTitle("Asymmetry (Mx>1 0.2<pTpT<0.3)");
h15->GetYaxis()->SetTitleSize(0.05);
h15->GetYaxis()->SetLabelSize(0.03);
h15->SetLineWidth(1.5);

h15->SetLineWidth(1.5);
h15->SetMarkerStyle(20);
h15->SetMarkerColor(4);
h15->Draw("P");
/////////////////////////////////////////////////////////////////////
c04->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h20->GetXaxis()->SetTitle("DeltaPhi");
h20->GetXaxis()->SetTitleSize(0.05);
h20->GetXaxis()->SetLabelSize(0.03);
h20->GetXaxis()->SetTitleOffset(1);
h20->GetYaxis()->SetTitle("Asymmetry (Mx>1 0.3<pTpT<0.4)");
h20->GetYaxis()->SetTitleSize(0.05);
h20->GetYaxis()->SetLabelSize(0.03);
h20->SetLineWidth(1.5);

h20->SetLineWidth(1.5);
h20->SetMarkerStyle(20);
h20->SetMarkerColor(4); 
h20->Draw("P");
/////////////////////////////////////////////////////////////////////
c05->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h25->GetXaxis()->SetTitle("DeltaPhi");
h25->GetXaxis()->SetTitleSize(0.05);
h25->GetXaxis()->SetLabelSize(0.03);
h25->GetXaxis()->SetTitleOffset(1);
h25->GetYaxis()->SetTitle("Asymmetry (Mx>1 0.4<pTpT<0.5)");
h25->GetYaxis()->SetTitleSize(0.05);
h25->GetYaxis()->SetLabelSize(0.03);
h25->SetLineWidth(1.5);

h25->SetLineWidth(1.5);
h25->SetMarkerStyle(20);
h25->SetMarkerColor(4); 
h25->Draw("P");
/////////////////////////////////////////////////////////////////////
c06->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h35->GetXaxis()->SetTitle("DeltaPhi");
h35->GetXaxis()->SetTitleSize(0.05);
h35->GetXaxis()->SetLabelSize(0.03);
h35->GetXaxis()->SetTitleOffset(1);
h35->GetYaxis()->SetTitle("Asymmetry (Mx>1 0.5<pTpT<0.6)");
h35->GetYaxis()->SetTitleSize(0.05);
h35->GetYaxis()->SetLabelSize(0.03);
h35->SetLineWidth(1.5);

h35->SetLineWidth(1.5);
h35->SetMarkerStyle(20);
h35->SetMarkerColor(4); 
h35->Draw("P");
/////////////////////////////////////////////////////////////////////
c07->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h45->GetXaxis()->SetTitle("DeltaPhi");
h45->GetXaxis()->SetTitleSize(0.05);
h45->GetXaxis()->SetLabelSize(0.03);
h45->GetXaxis()->SetTitleOffset(1);
h45->GetYaxis()->SetTitle("Asymmetry (Mx>1 0.6<pTpT<0.7)");
h45->GetYaxis()->SetTitleSize(0.05);
h45->GetYaxis()->SetLabelSize(0.03);
h45->SetLineWidth(1.5);

h45->SetLineWidth(1.5);
h45->SetMarkerStyle(20);
h45->SetMarkerColor(4); 
h45->Draw("P");
/////////////////////////////////////////////////////////////////////
c08->cd(1);
gStyle->SetOptStat(0);
gStyle->SetOptFit(); 
h55->GetXaxis()->SetTitle("DeltaPhi");
h55->GetXaxis()->SetTitleSize(0.05);
h55->GetXaxis()->SetLabelSize(0.03);
h55->GetXaxis()->SetTitleOffset(1);
h55->GetYaxis()->SetTitle("Asymmetry (Mx>1 0.7<pTpT<0.8)");
h55->GetYaxis()->SetTitleSize(0.05);
h55->GetYaxis()->SetLabelSize(0.03);
h55->SetLineWidth(1.5);

h55->SetLineWidth(1.5);
h55->SetMarkerStyle(20);
h55->SetMarkerColor(4); 
h55->Draw("P");
/////////////////////////////////////////////////////////////////////
    /*
c01->Print("FitMethodPK1.pdf");
c01->Print("FitMethodPK1.pdf]");
c02->Print("FitMethodPK2.pdf");
c02->Print("FitMethodPK2.pdf]");
c03->Print("FitMethodPK3.pdf");
c03->Print("FitMethodPK3.pdf]");
c04->Print("FitMethodPK4.pdf");
c04->Print("FitMethodPK4.pdf]");
c05->Print("FitMethodPK5.pdf");
c05->Print("FitMethodPK5.pdf]");
c06->Print("FitMethodPK6.pdf");
c06->Print("FitMethodPK6.pdf]");
c07->Print("FitMethodPK7.pdf");
c07->Print("FitMethodPK7.pdf]");
c08->Print("FitMethodPK8.pdf");
c08->Print("FitMethodPK8.pdf]");
*/
}

