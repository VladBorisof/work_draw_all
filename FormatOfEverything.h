//
// Created by vlad on 28.09.2019.
//

#ifndef FORMATOFEVERYTHING_H
#define FORMATOFEVERYTHING_H

#include "TGraphErrors.h"
#include "TROOT.h"
#include "TCanvas.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"
#include "TH3.h"
#include "TF1.h"
#include "TPaveLabel.h"
#include "TPaveText.h"
#include <iostream>
#include <fstream>
#include <TLatex.h>
#include <TLegend.h>
#include <TStyle.h>
#include <TMarker.h>
#include <TPolyLine.h>
#include <TVectorT.h>
#include <TASImage.h>
#include "TRandom.h"
#include "TFile.h"
#include "TRandomGen.h"
#include "TObject.h"
#include "TPad.h"
#include "TVirtualPad.h"

using namespace std;

void CreateCanvasSpectr();

void Format_Legend(TLegend *leg, int font, Float_t size, Float_t line_wd, Float_t style, TString name);

void Format_Graph(TGraphErrors *gr, Style_t mark_style, Size_t mark_size, Color_t mark_col, Style_t line_style,
                  Width_t line_wd, Color_t line_col, Float_t alpha);

void Format_Latex(TLatex *lat, int font, Float_t size, Float_t line_wd);

void Format_TypeC(TGraph *gr, int mark_style, Float_t mark_size, Color_t mark_col, int line_style, Float_t line_wd,
                  Color_t line_col, Float_t alpha);

void Format_Marker(TMarker *mk, Float_t mark_size, Color_t mark_col, Float_t alpha);

void Format_Canvas(TCanvas *c2, int divide_x, int divide_y, int mar);

void Format_Pad(double *param, const char *title_x, const char *title_y);

void Format_Function(TF1 *f, int Mstyle, int Msize, Color_t Mcolor, int Lwidth, Color_t Lcolor, double_t Malpha,
                     double_t Lalpha);

void Format_LevyFun(TF1 *levy, double par0, double par1, double par2, int ln_st, double ln_wd, Color_t color);

void SetMarginPad(double *param);

void DrawLogo(double x0, double y0, double x1, double y1);


void CoutArray(int n, double *Y, double *YE) {
  cout << "{";
  for (int m = 0; m < n; ++m) {
    if (m < n - 1) cout << Y[m] << ", ";
    else cout << Y[m];
  }
  cout << "};" << endl;
  cout << "{";
  for (int m = 0; m < n; ++m) {
    if (m < n - 1) cout << YE[m] << ", ";
    else cout << YE[m];
  }
  cout << "};" << endl;
}

void CoutArrayPy(int n, double *Y, double *YE) {
  cout << "[";
  for (int m = 0; m < n; ++m) {
    if (m < n - 1) cout << Y[m] << ", ";
    else cout << Y[m];
  }
  cout << "]," << endl;
  cout << "[";
  for (int m = 0; m < n; ++m) {
    if (m < n - 1) cout << YE[m] << ", ";
    else cout << YE[m];
  }
  cout << "]," << endl;
}

void CoutArrayPy(int n, double *Y) {
  cout << "[";
  for (int m = 0; m < n; ++m) {
    if (m < n - 1) cout << Y[m] << ", ";
    else cout << Y[m];
  }
  cout << "]," << endl;
}

void CoutArray(int n, double *Y) {
  cout << "{";
  for (int m = 0; m < n; ++m) {
    if (m < n - 1) cout << Y[m] << ", ";
    else cout << Y[m];
  }
  cout << "};" << endl;
}

void CoutArrayAN(int n, double *Y) {
  for (int m = 0; m < n; ++m) {
    if (m < n - 1) cout << Y[m] << " & ";
    else cout << Y[m];
  }
  cout << endl;
}

void Debugger(string str, double n) {
  cout << "Local debugger\n";
  cout << str << " " << n << endl;
}

void CoutDebugger(string str) {
  cout << "Local debugger\n" << "!!!" << str << "!!!\n";
}


void DrawLogo(double x0 = 0., double y0 = 0., double x1 = 0., double y1 = 0.) {

  TImage *img = TImage::Open("~/Yandex.Disk/Format/logo_prelim.png");

  TPad *l = new TPad("l", "l", x0, y0, x1, y1);
  l->SetFillStyle(0);
  l->SetFillColorAlpha(0, 0);
  l->Draw();
  l->cd();
  img->Draw();
}

void SetMarginPad(double *param) {
  gPad->SetLeftMargin(param[0]);
  gPad->SetRightMargin(param[1]);
  gPad->SetBottomMargin(param[2]);
  gPad->SetTopMargin(param[3]);
}

void Format_Function(TF1 *f, int Mstyle, int Msize, Color_t Mcolor, int Lwidth, Color_t Lcolor, double_t Malpha,
                     double_t Lalpha) {
  f->SetMarkerStyle(Mstyle);
  f->SetMarkerSize(Msize);
  f->SetMarkerColorAlpha(Mcolor, Malpha);
  f->SetLineWidth(Lwidth);
  f->SetLineColorAlpha(Lcolor, Lalpha);
}

void Format_Graph(TGraphErrors *gr, Style_t mark_style = 0, Size_t mark_size = 0, Color_t mark_col = 0,
                  Style_t line_style = 0, Width_t line_wd = 0, Color_t line_col = 0, Float_t alpha = 0) {
  gr->SetMarkerStyle(mark_style);
  gr->SetMarkerSize(mark_size);
  gr->SetMarkerColorAlpha(mark_col, alpha);
  gr->SetLineStyle(line_style);
  gr->SetLineWidth(line_wd);
  gr->SetLineColorAlpha(line_col, alpha);
}

void Format_Latex(TLatex *lat, int font = 0, Float_t size = 0, Float_t line_wd = 0) {
  lat->SetTextFont(font);
  lat->SetTextSize(size);
  lat->SetLineWidth(line_wd);
}

void
Format_Legend(TLegend *leg, int font = 0, Float_t size = 0, Float_t line_wd = 0, Float_t style = 0, TString name = "") {
  leg->SetHeader(name, "");
  leg->SetTextFont(font);
  leg->SetTextSize(size);
  leg->SetLineWidth(line_wd);
  leg->SetFillStyle(style);
}

void Format_TypeC(TGraph *gr, int mark_style = 0, Float_t mark_size = 0, Color_t mark_col = 0, int line_style = 0,
                  Float_t line_wd = 0, Color_t line_col = 0, Float_t alpha = 0) {
  gr->SetMarkerStyle(mark_style);
  gr->SetMarkerSize(mark_size);
  gr->SetMarkerColorAlpha(mark_col, alpha);
  gr->SetLineStyle(line_style);
  gr->SetLineWidth(line_wd);
  gr->SetLineColorAlpha(line_col, alpha);
  gr->SetFillColorAlpha(mark_col, alpha);
}

void Format_Marker(TMarker *mk, Float_t mark_size = 0, Color_t mark_col = 0, Float_t alpha = 0) {
  mk->SetMarkerSize(mark_size);
  mk->SetMarkerColorAlpha(mark_col, alpha);
}

void Format_Canvas(TCanvas *c2, int divide_x, int divide_y, int mar = 0) {
  if (mar == 1) c2->Divide(divide_x, divide_y, 0, 0);
  else c2->Divide(divide_x, divide_y);
  for (int centr = 0; centr < divide_x * divide_y; centr++) {
    c2->cd(centr + 1);
    c2->SetFillColor(0);
    c2->SetBorderMode(0);
    c2->SetBorderSize(1);
    c2->SetFrameBorderMode(2);
    gPad->SetTicks();
  }

  gStyle->SetEndErrorSize(16);
  gStyle->SetLineWidth(8);


}

void Format_Pad(double *param, const char *title_x, const char *title_y) {
  /* param -
   * 0 - x_low
   * 1 - x_up
   * 2 - y_minimum
   * 3 - y_maximum
   * 4 - x_SetTitleOffset
   * 5 - y_SetTitleOffset
   * 6 - SetTitleSize
   * 7 - SetLabelSize - numbers
   * 8 - if SetLogy
   * 9 - x_SetNdivisions
   * 10 - y_SetNdivisions
   * 11 - CenterTitle
   * */
  TH1F *second = new TH1F("", "", 100, param[0], param[1]);
  gPad->SetFillColorAlpha(0, 0);
  if (param[8] == 1) gPad->SetLogy();
  second->SetMinimum(param[2]);
  second->SetMaximum(param[3]);
  second->SetStats(0);
  second->SetTitle("");

  second->GetXaxis()->SetTitle(title_x);
  second->GetXaxis()->SetLabelFont(2);
  second->GetXaxis()->SetTitleFont(2);
  second->GetXaxis()->SetLabelSize(param[7]);
  second->GetXaxis()->SetTickSize(0.02);
  second->GetXaxis()->SetTitleSize(param[6]);
  second->GetXaxis()->SetTitleOffset(param[4]);
  if (param[11] == 1) second->GetXaxis()->CenterTitle();

  second->GetXaxis()->SetNdivisions(param[9]);
  second->GetYaxis()->SetNdivisions(param[10]);

  second->GetYaxis()->SetTitle(title_y);
  second->GetYaxis()->SetLabelFont(2);
  second->GetYaxis()->SetTitleFont(2);
  second->GetYaxis()->SetLabelSize(param[7]);
  second->GetYaxis()->SetTickSize(0.02);
  second->GetYaxis()->SetTitleSize(param[6]);
  second->GetYaxis()->SetTitleOffset(param[5]);
  if (param[11] == 1) second->GetYaxis()->CenterTitle();
  second->Draw();
}

void CreateCanvasSpectr() {
  auto c1 = new TCanvas("c1", "K*->K+pi- 12CuAu200", 29, 30, 1000, 800);
  gStyle->SetOptStat(0);
  c1->SetFillColor(0);
  c1->SetBorderMode(0);
  c1->SetBorderSize(2);
  c1->SetLogy();
  //  c1->SetLeftMargin(0.1394148);
  //  c1->SetRightMargin(0.003442341);
  //  c1->SetTopMargin(0.003690037);
  c1->SetFrameBorderMode(0);
  gPad->SetTicks();

  auto first = new TH1F("", "", 100, 1.0, 6.5);//8.0);
  first->SetMinimum(1e-10);
  first->SetMaximum(1e2);
  first->SetStats(0);
  first->GetXaxis()->SetTitle(" p_{T}(GeV/c)");
  first->GetXaxis()->SetLabelFont(62);
  first->GetXaxis()->SetTitleOffset(1.2);
  first->GetXaxis()->SetTitleFont(62);
  first->GetYaxis()->SetTitle("1/2#pi 1/p_{T} d^{2}N/dydp_{T}, (GeV/c)^{-2}");
  first->GetYaxis()->SetNdivisions(1004);
  first->GetYaxis()->SetLabelFont(62);
  //first->GetYaxis()->SetTitleSize(0.1);
  first->GetYaxis()->SetTitleOffset(1.2);
  first->GetYaxis()->SetTitleFont(62);
  first->Draw();
}

void Format_LevyFun(TF1 *levy, double par0, double par1, double par2, int ln_st, double ln_wd, Color_t color) {
  levy->SetParameter(0, par0);  //dN/dy
  levy->SetParameter(1, par1);  //n
  levy->SetParameter(2, par2); //C
  levy->SetLineStyle(ln_st);
  levy->SetLineWidth(ln_wd);
  levy->SetLineColor(color);
}


#endif //WORKUU_FORMATOFEVERYTHING_H
