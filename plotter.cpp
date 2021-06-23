//
// Created by vlad on 16.12.2020.
//
#include "particles_data.h"
#include "Particles.cpp"

void plotter_rab() {

  Color_t kstar_colors[] = {};

  auto levelwide = new TLine();
  levelwide->SetLineWidth(10);
  levelwide->SetLineColor(1);
  levelwide->SetLineStyle(7);

  auto kstar_cuau = new Particles("rab_kstar_cuau", 5, n_kstar_cuau, kRed, 21);
  kstar_cuau->rab_format_graph(7, 15, 0.9);
  kstar_cuau->rab_format_graph_sys(0.06, 15, 0.9);
  kstar_cuau->type_c_format(7.6, 0.05);

  auto kstar_uu = new Particles("rab_kstar_uu", 4, n_kstar_uu, kGreen + 2, 22);
  kstar_uu->rab_format_graph(7, 15, 0.9);
  kstar_uu->rab_format_graph_sys(0.05, 15, 0.9);
  kstar_uu->type_c_format(7.7, 0.05);

  auto kstar_cucu = new Particles("rab_kstar_cucu", 5, n_kstar_cucu, kBlue, 23);
  kstar_cucu->rab_format_graph(7, 5, 0.9);
  kstar_cucu->rab_format_graph_sys(0.05, 5, 0.9);
  kstar_cucu->type_c_format(7.8, 0.05);


  auto c2 = new TCanvas("c2", "c2", 30, 30, 8000, 4000);
  Format_Canvas(c2, 2, 1, 0);

  TString most_center = "(0-20%)";
  TString peripheral[3] = {"(60-80%)", "(40-80%)", "(60-93%)"};

  double par[4] = {0.1, 0.0, 0.1, 0.0};
  double param_pad[] = {0.8, 8.1, 0.2, 2.1, 0.98, 0.9, 0.05, 0.05};
  TString pad_title_x = "p_{T}, (GeV/c)";
  TString pad_title_y = "R_{AB}";
  TLegend *legend[2];
  legend[0] = new TLegend(0.15, 0.75, 0.3, 0.97);
  Format_Legend(legend[0], 42, 0.04, 0, 0, "");
  legend[1] = new TLegend(0.15, 0.75, 0.3, 0.97);
  Format_Legend(legend[1], 42, 0.04, 0, 0, "");


  c2->cd(1);
  SetMarginPad(par);
  Format_Pad(param_pad, pad_title_x, pad_title_y);
  levelwide->DrawLine(param_pad[0], 1, param_pad[1], 1);

  kstar_cuau->draw_all(0);
  kstar_uu->draw_all(0);
  kstar_cucu->draw_all(0);


  legend[0]->AddEntry(kstar_cucu->graph_legend(10), "K*^{0} in Cu+Cu " + most_center + "PRC90.054905", "p");
  legend[0]->AddEntry(kstar_cuau->graph_legend(10), "K*^{0} in Cu+Au " + most_center, "p");
  legend[0]->AddEntry(kstar_uu->graph_legend(10), "K*^{0} in U+U " + most_center, "p");
  legend[0]->Draw();

  auto tex0 = new TLatex(3, 1.95, "central collisions");
  Format_Latex(tex0, 62, 0.045, 2);
  tex0->Draw();

  DrawLogo(0.55, 0.6, 0.99, 0.9);


  c2->cd(2);
  SetMarginPad(par);
  Format_Pad(param_pad, pad_title_x, pad_title_y);

  levelwide->DrawLine(param_pad[0], 1, param_pad[1], 1);

  kstar_cuau->draw_all(3);
  kstar_uu->draw_all(2);
  kstar_cucu->draw_all(3);


  legend[1]->AddEntry(kstar_cucu->graph_legend(10), "K*^{0} in Cu+Cu " + peripheral[2] + "PRC90.054905", "p");
  legend[1]->AddEntry(kstar_cuau->graph_legend(10), "K*^{0} in Cu+Au " + peripheral[0], "p");
  legend[1]->AddEntry(kstar_uu->graph_legend(10), "K*^{0} in U+U " + peripheral[1], "p");
  legend[1]->Draw();

  tex0 = new TLatex(3, 1.95, "peripheral collisions");
  Format_Latex(tex0, 62, 0.045, 2);
  tex0->Draw();

  DrawLogo(0.55, 0.6, 0.99, 0.9);


  c2->Print("rab.png");

}

void plotter_small() {

  auto levelwide = new TLine();
  levelwide->SetLineWidth(10);
  levelwide->SetLineColor(1);
  levelwide->SetLineStyle(7);

  auto kstar_heau = new Particles("rab_kstar_heau", 5, n_kstar_heau, kRed, 34);
  kstar_heau->rab_format_graph(10, 15, 0.9);
  kstar_heau->rab_format_graph_sys(0.06, 15, 0.9);
  kstar_heau->type_c_format(7.6, 0.05);

  auto kstar_dau = new Particles("rab_kstar_dau", 4, n_kstar_dau, kBlue, 33);
  kstar_dau->rab_format_graph(10, 10, 0.9);
  kstar_dau->rab_format_graph_sys(0.05, 10, 0.9);
  kstar_dau->type_c_format(7.7, 0.05);

  auto c2 = new TCanvas("c2", "c2", 30, 30, 8000, 4000);
  Format_Canvas(c2, 2, 1, 0);

  TString most_center = "(0-20%)";
  TString peripheral[3] = {"(60-80%)", "(40-80%)", "(60-93%)"};

  double par[4] = {0.1, 0.0, 0.1, 0.0};
  double param_pad[] = {0.8, 8.1, 0.2, 2.1, 0.98, 0.9, 0.05, 0.05};
  TString pad_title_x = "p_{T}, (GeV/c)";
  TString pad_title_y = "R_{AB}";
  TLegend *legend[2];
  for (int i = 0; i < 2; ++i) {
    legend[i] = new TLegend(0.15, 0.8, 0.3, 0.97);
    Format_Legend(legend[i], 42, 0.04, 0, 0, "");
  }


  c2->cd(1);
  SetMarginPad(par);
  Format_Pad(param_pad, pad_title_x, pad_title_y);
  levelwide->DrawLine(param_pad[0], 1, param_pad[1], 1);

  kstar_heau->draw_all(0);

  kstar_dau->draw_all(0);


  legend[0]->AddEntry(kstar_dau->graph_legend(10), "K*^{0} in d+Au " + most_center + "PRC90.054905", "p");
  legend[0]->AddEntry(kstar_heau->graph_legend(10), "K*^{0} in ^{3}He+Au " + most_center, "p");
  legend[0]->Draw();

  auto tex0 = new TLatex(3, 1.95, "central collisions");
  Format_Latex(tex0, 62, 0.045, 2);
  tex0->Draw();

  DrawLogo(0.55, 0.6, 0.99, 0.9);


  c2->cd(2);
  SetMarginPad(par);
  Format_Pad(param_pad, pad_title_x, pad_title_y);

  levelwide->DrawLine(param_pad[0], 1, param_pad[1], 1);

  kstar_heau->draw_all(3);

  kstar_dau->draw_all(3);

  legend[1]->AddEntry(kstar_dau->graph_legend(10), "K*^{0} in d+Au " + peripheral[0] + "PRC90.054905", "p");
  legend[1]->AddEntry(kstar_heau->graph_legend(10), "K*^{0} in ^{3}He+Au " + peripheral[2], "p");
  legend[1]->Draw();

  tex0 = new TLatex(3, 1.95, "peripheral collisions");
  Format_Latex(tex0, 62, 0.045, 2);
  tex0->Draw();

  DrawLogo(0.55, 0.6, 0.99, 0.9);


  c2->Print("rab_small.png");
}


void plotter_int_rab() {

  auto kstar_cuau = new Particles("rab_kstar_cuau", 5, n_kstar_cuau, kRed, 21);
  kstar_cuau->get_integrated_rab();
  kstar_cuau->int_format_graph(7, 10, 0.9);
  kstar_cuau->int_format_graph_sys(5, 10, 0.9);

  auto kstar_uu = new Particles("rab_kstar_uu", 4, n_kstar_uu, kGreen+2, 22);
  kstar_uu->get_integrated_rab();
  kstar_uu->int_format_graph(7, 10, 0.9);
  kstar_uu->int_format_graph_sys(5, 10, 0.9);

  auto kstar_cucu = new Particles("rab_kstar_cucu", 5, n_kstar_cucu, kBlue, 23);
  kstar_cucu->get_integrated_rab();
  kstar_cucu->int_format_graph(7, 10, 0.9);
  kstar_cucu->int_format_graph_sys(5, 10, 0.9);

  auto c2 = new TCanvas("c2", "c2", 30, 30, 4000, 4000);
  Format_Canvas(c2, 1, 1, 0);

  double par[4] = {0.1, 0.0, 0.1, 0.0};
  SetMarginPad(par);
  double param_pad[] = {0.1, 349, 0.2, 2.1, 0.9, 0.9, 0.05, 0.05};
  TString pad_title_x = "N_{part}";
  TString pad_title_y = "#LTR_{AB}#GT";

  Format_Pad(param_pad, pad_title_x, pad_title_y);

  kstar_cuau->int_draw_all();
  kstar_uu->int_draw_all();
  kstar_cucu->int_draw_all();

  c2->Print("int_rab.png");


}

struct coeff_scale_sp {
    double coeff[5];
    TString name_coeff[5];
};

void plotter_spectra_for_ppg_heavy() {
  // general declaration
  TString sp_pad_title_x = "p_{T} [GeV/c]";
  TString sp_pad_title_y = "1/2#pi 1/p_{T} d^{2}N/dydp_{T} [(GeV/c)^{-2}]";
  TLatex *phenix[2] ;
  phenix[0] = new TLatex(1.9, 100, "PHENIX");
  phenix[1] = new TLatex(1.5, 100, "PHENIX");
  TLatex *name_fig[2];
  TLegend *leg[2];


  // special for Cu+Au spectra declaration
  auto kstar_cuau_sp = new Particles("rab_kstar_cuau", 5, n_kstar_cuau, kRed, 21);
  coeff_scale_sp coeff_for_cuau{{1, 1e-1, 1e-2, 1e-3, 1e2},
                          {"10^{0}", "10^{-1}", "10^{-2}", "10^{-3}", "10^{2}"}};

  kstar_cuau_sp->sp_scale(coeff_for_cuau.coeff);
  kstar_cuau_sp->sp_format_graph(5, 15, 0.9);
  kstar_cuau_sp->sp_format_graph_sys(0.1, 5, 0.5);
  name_fig[0] = new TLatex(1.9, 1e3, "K*^{0} in CuAu, #sqrt{s_{NN}} = 200 GeV");
  Format_Latex(name_fig[0], 62, 0.045, 2);
  leg[0] = new TLegend(0.65, 0.2, 0.95, 0.6);
  Format_Legend(leg[0], 62, 0.04, 0, 0, "");
  TString name_cen_cuau[] = {"  0-20%", "20-40%", "40-60%", "60-80%", "  0-93%"};
  double par_sp_cuau[] = {0.15, 0.0, 0.1, 0.};
  double param_pad_sp_cuau[] = {1.1, 6.5, 1.1e-11, 1e5-1, 0.95, 1.4, 0.05, 0.05, 1, 504, 504};
  double koeff_levy_cuau[5] = {2-0.1, 5.75+0.1, 0.0455202, 10.0277, 0.252345};
  Color_t color_cuau[] = {kAzure, kAzure+1, kAzure+2, kAzure+3, kBlack};

  // special for U+U spectra declaration
  auto kstar_uu = new Particles("rab_kstar_uu", 4, n_kstar_uu, kBlue, 22);
  coeff_scale_sp coeff_for_uu{{1e-3, 1e-4, 1e-5, 1e-1},
                              {"10^{-3}", "10^{-4}", "10^{-5}", "10^{-1}"}};
  kstar_uu->sp_scale(coeff_for_uu.coeff);
  kstar_uu->sp_format_graph(5, 15, 0.9);
  kstar_uu->sp_format_graph_sys(0.08, 5, 0.5);

  name_fig[1] = new TLatex(1.5, 1e3, "K*^{0} in UU, #sqrt{s_{NN}} = 193 GeV, |#eta|<0.35");
  Format_Latex(name_fig[1], 62, 0.045, 2);
  leg[1] = new TLegend(0.65, 0.6, 0.95, 0.9);
  Format_Legend(leg[1], 62, 0.04, 0, 0, "");
  TString name_cen_uu[] = {"  0-20%", "20-40%", "40-60%", "  0-80%"};
  double par_sp_uu[] = {0., 0., 0.1, 0.0};
  double param_pad_sp_uu[] = {1.1, 6.5, 1.1e-11, 1e5-1, 0.95, 1.4, 0.05, 0.05, 1, 504, 504};
  double koeff_levy_uu[] = {1.55-0.1, 3.7+0.1, 0.0455202, 10.0277, 0.252345};


  auto c1 = new TCanvas("c1", "c1", 4000, 2000);
  Format_Canvas(c1, 2, 1, 0);
  c1->cd(1);
  SetMarginPad(par_sp_cuau);
  Format_Pad(param_pad_sp_cuau, sp_pad_title_x, sp_pad_title_y);
  for (int j = 0; j < 5; ++j) {
    kstar_cuau_sp->sp_draw(j);
    kstar_cuau_sp->sp_fit(koeff_levy_cuau, j);
    kstar_cuau_sp->sp_draw_sys(j);
    leg[0]->AddEntry(kstar_cuau_sp->graph_for_legend(5, j), name_cen_cuau[j] + "x" + coeff_for_cuau.name_coeff[j], "p");
  }

  phenix[0]->Draw();
  name_fig[0]->Draw();


  c1->cd(2);
  SetMarginPad(par_sp_uu);
  Format_Pad(param_pad_sp_uu, sp_pad_title_x, sp_pad_title_y);
  for (int j = 0; j < 4; ++j) {
    kstar_uu->sp_draw(j);
    kstar_uu->sp_fit(koeff_levy_uu, j);
    kstar_uu->sp_draw_sys(j);
    leg[1]->AddEntry(kstar_uu->graph_for_legend(5, j), name_cen_uu[j] + "x" + coeff_for_uu.name_coeff[j], "p");
  }
  leg[0]->Draw();
  leg[1]->Draw();
  name_fig[1]->Draw();
  phenix[1]->Draw();

  c1->Print("spectra_cuau_uu.png");

  //
  auto levelwide = new TLine();
  levelwide->SetLineWidth(10);
  levelwide->SetLineColor(1);
  levelwide->SetLineStyle(7);

  // special for Cu+Au ratio
  kstar_cuau_sp->get_levy_data(10, 15, 0.9);
  double param_pad_ratio_cuau[] = {1.1, 7.1, 0.01, 1.99, 0.95, 1.4, 0.05, 0.05, 0, 504, 504};

  // special for U+U ratio
  kstar_uu->get_levy_data(10, 15, 0.9);
  double param_pad_ratio_uu[] = {1.1, 4.2, 0.01, 1.99, 0.95, 1.4, 0.05, 0.05, 0, 504, 504};

  auto c2 = new TCanvas("c2", "c2", 4000, 2000);
  Format_Canvas(c2, 2, 1, 1);
  c2->cd(1);
  SetMarginPad(par_sp_cuau);
  Format_Pad(param_pad_ratio_cuau, sp_pad_title_x, "ratio");
  for (int j = 0; j < 5; ++j) {
    kstar_cuau_sp->data_levy_draw(j);
  }
  levelwide->DrawLine(param_pad_ratio_cuau[0], 1, param_pad_ratio_cuau[1], 1);

  c2->cd(2);
  SetMarginPad(par_sp_uu);
  Format_Pad(param_pad_ratio_uu, sp_pad_title_x, "ratio");
  for (int j = 0; j < 4; ++j) {
    kstar_uu->data_levy_draw(j);
  }
  levelwide->DrawLine(param_pad_ratio_uu[0], 1, param_pad_ratio_uu[1], 1);

  c2->Print("ratio_cuau_uu.png");


}


void plotter_spectra_for_ppg_small() {
  // general declaration
  Particles *kstar_small[3];
  TString sp_pad_title_x = "p_{T} [GeV/c]";
  TString sp_pad_title_y = "1/2#pi 1/p_{T} d^{2}N/dydp_{T} [(GeV/c)^{-2}]";
  auto phenix = new TLatex(1.5, 100, "PHENIX");
  TLatex *name_fig[3];
  TLegend *leg[3];
  coeff_scale_sp coeff_scale_small[3];
  double par_sp_small[3][4] = {
          {0.15, 0., 0.1, 0.},
          {0., 0., 0.1, 0.},
          {0., 0., 0.1, 0.}
  };
  double param_pad_sp_small[3][11] = {
          {1.1, 6.2, 1.1e-11, 1e5-1, 0.95, 1.4, 0.05, 0.05, 1, 504, 504},
          {1.1, 6.2, 1.1e-11, 1e5-1, 0.95, 1.4, 0.05, 0.05, 1, 504, 504},
          {1.1, 6.2, 1.1e-11, 1e5-1, 0.95, 1.4, 0.05, 0.05, 1, 504, 504}
  };
  TString name_cen_small[3][5] = {
          {"0-20%", "20-40%", "40-60%", "0-80%"},
          {"0-20%", "20-40%", "40-60%", "0-80%"},
          {"0-20%", "20-40%", "40-60%", "0-80%"}
  };

  name_fig[0] = new TLatex(1.5, 1e3, "K*^{0} in pAl, #sqrt{s_{NN}} = 200 GeV, |#eta|<0.35");
  name_fig[1] = new TLatex(1.5, 1e3, "K*^{0} in pAu, #sqrt{s_{NN}} = 200 GeV, |#eta|<0.35");
  name_fig[2] = new TLatex(1.5, 1e3, "K*^{0} in ^{3}HeAu, #sqrt{s_{NN}} = 200 GeV, |#eta|<0.35");


  kstar_small[0] = new Particles("rab_kstar_pal", 4, n_kstar_pal, kMagenta);
  coeff_scale_small[0] = {{1, 1e-1, 1e-2, 1e2},
                          {"", "", "", "", ""}};
  kstar_small[0]->sp_scale(coeff_scale_small[0].coeff);
  kstar_small[0]->sp_format_graph(5, 15, 0.9);
  kstar_small[0]->sp_format_graph_sys(0.1, 5, 0.5);
  leg[0] = new TLegend(0.7, 0.7, 0.95, 0.95);
  Format_Legend(leg[0], 42, 0.04, 0, 0, "");


  kstar_small[1] = new Particles("rab_kstar_pau", 4, n_kstar_pau, kViolet);
  coeff_scale_small[1] = {{1, 1e-1, 1e-2, 1e2},
                          {}};
  kstar_small[1]->sp_scale(coeff_scale_small[1].coeff);
  kstar_small[1]->sp_format_graph(5, 15, 0.9);
  kstar_small[1]->sp_format_graph_sys(0.1, 5, 0.5);
  leg[1] = new TLegend(0.7, 0.7, 0.95, 0.95);
  Format_Legend(leg[1], 42, 0.04, 0, 0, "");


  kstar_small[2] = new Particles("rab_kstar_heau", 5, n_kstar_heau, kBlue);
  coeff_scale_small[2] = {{1, 1e-1, 1e-2, 1e-3,1e2},
                          {}};
  kstar_small[2]->sp_scale(coeff_scale_small[2].coeff);
  kstar_small[2]->sp_format_graph(5, 15, 0.9);
  kstar_small[2]->sp_format_graph_sys(0.1, 5, 0.5);
  leg[2] = new TLegend(0.7, 0.7, 0.95, 0.95);
  Format_Legend(leg[2], 42, 0.04, 0, 0, "");


  double koeff_levy_small[3][5] = {
          {1.55-0.03, 3.1+0.03, 0.0455202, 10.0277, 0.252345},
          {1.55-0.03, 4.4+0.03, 0.0455202, 10.0277, 0.252345},
          {1.55-0.1, 5.8+0.1, 0.0455202, 10.0277, 0.252345}
  };

  auto c1 = new TCanvas("c1", "c1", 4000, 2000);
  Format_Canvas(c1, 3, 1, 1);

  c1->cd(1);
  SetMarginPad(par_sp_small[0]);
  Format_Pad(param_pad_sp_small[0], sp_pad_title_x, sp_pad_title_y);
  for (int i = 0; i < 4; ++i) {
    kstar_small[0]->sp_draw(i);
    kstar_small[0]->sp_fit(koeff_levy_small[0], i);
    kstar_small[0]->sp_draw_sys(i);
    leg[0]->AddEntry(kstar_small[0]->graph_for_legend(5, i), name_cen_small[0][i] /*+ coeff_scale_small[0].name_coeff[i]*/, "p");
  }
  leg[0]->Draw();


  c1->cd(2);
  SetMarginPad(par_sp_small[1]);
  Format_Pad(param_pad_sp_small[1], sp_pad_title_x, sp_pad_title_y);
  for (int i = 0; i < 4; ++i) {
    kstar_small[1]->sp_draw(i);
    kstar_small[1]->sp_fit(koeff_levy_small[1], i);
    kstar_small[1]->sp_draw_sys(i);
    leg[1]->AddEntry(kstar_small[1]->graph_for_legend(5, i), name_cen_small[1][i] + coeff_scale_small[1].name_coeff[i], "p");
  }
  leg[1]->Draw();


  c1->cd(3);
  SetMarginPad(par_sp_small[2]);
  Format_Pad(param_pad_sp_small[2], sp_pad_title_x, sp_pad_title_y);
  for (int i = 0; i < 5; ++i) {
    kstar_small[2]->sp_draw(i);
    kstar_small[2]->sp_fit(koeff_levy_small[2], i);
    kstar_small[2]->sp_draw_sys(i);
    leg[2]->AddEntry(kstar_small[2]->graph_for_legend(5, i), name_cen_small[2][i] + coeff_scale_small[2].name_coeff[i], "p");
  }
  leg[2]->Draw();

  c1->Print("spectra_small.png");

}


void join_plot() {
  TImage *img1 = TImage::Open("spectra_cuau_uu.png");
  TImage *img2 = TImage::Open("ratio_cuau_uu.png");
  auto cc = new TCanvas("cc", "cc", 2000, 2000);
  cc->Divide(0, 2);
  cc->cd(1);
  gPad->SetBottomMargin(0.01);
  img1->Draw();
  cc->cd(2);
  gPad->SetTopMargin(0.01);
  img2->Draw();

  cc->Print("all.png");
}

void plotter_spectra() {
  auto kstar_cuau_sp = new Particles("rab_kstar_cuau", 5, n_kstar_cuau, kRed, 21);
  double koeff_scale[5] = {1, 1e-1, 1e-2, 1e-3, 1e2};
  kstar_cuau_sp->sp_scale(koeff_scale);
  kstar_cuau_sp->sp_format_graph(10, 15, 0.9);

  auto c1 = new TCanvas("c1", "c1", 4000, 4000);
  Format_Canvas(c1, 2, 1, 0);

  c1->cd(1);
  double par_sp[] = {0.1, 0.0, 0.0, 0.0};
  SetMarginPad(par_sp);
  TString sp_pad_title_x = "p_{T} (GeV/c)";
  TString sp_pad_title_y = "1/2#pi 1/p_{T} d^{2}N/dydp_{T} (GeV/c)^{-2}";
  double param_pad_sp[] = {1., 7.1, 1.1e-11, 95, 0.8, 0.9, 0.05, 0.05, 1, 504, 503};
  Format_Pad(param_pad_sp, sp_pad_title_x, sp_pad_title_y);

  double koeff_levy[5] = {1.2, 7.0, 0.0455202, 10.0277, 0.252345};
  for (int j = 0; j < 5; ++j) {
    kstar_cuau_sp->sp_draw(j);
    kstar_cuau_sp->sp_fit(koeff_levy, j);
  }
  c1->Update();

  c1->cd(2);
  double par_sp1[] = {0.1, 0.0, 0.15, 0.0};
  SetMarginPad(par_sp1);
  double param_pad_sp1[] = {1., 7.1, 0, 1.99, 0.8, 1, 0.05, 0.09, 0, 504, 505};
  Format_Pad(param_pad_sp1, sp_pad_title_x, "ratio");
  kstar_cuau_sp->get_levy_data(10, 15, 0.9);
  for (int i = 0; i < 5; ++i) {
    kstar_cuau_sp->data_levy_draw(i);
  }
  c1->Update();

  c1->Print("sp.png");
}


void plotter_rab_for_ppg_cuau() {
  auto unity = new Particles();

  TString x_title = "p_{T} [GeV/c]";
  TString y_title= "R_{AB}";
  auto kstar_cuau = new Particles("rab_kstar_cuau", 5, n_kstar_cuau, kRed, 21);
  kstar_cuau->rab_format_graph(5, 5, 0.8);
  kstar_cuau->rab_format_graph_sys(0.09, 5, 0.3);
  kstar_cuau->type_c_format(7.6, 0.05);

  auto legend = new TLegend(0.15, 0.9, 0.4, 0.97);
  Format_Legend(legend, 42, 0.04, 0, 0, "");
  legend->AddEntry(kstar_cuau->graph_legend(7), "K*^{0}#rightarrow K^{#pm}#pi^{#mp}" , "p");

  auto c1 = new TCanvas("c1", "c1", 4000, 4000);
  Format_Canvas(c1, 2, 2, 0);

  for (int i = 0; i < 4; ++i) {
    c1->cd(i+1);
    double par_sp1[] = {0.13, 0.0, 0.13, 0.0};
    SetMarginPad(par_sp1);

    double param_pad[] = {1., 7.1, 0.01, 1.99, 0.99, 0.9, 0.06, 0.06, 0, 504, 505, 1};
    Format_Pad(param_pad, x_title, y_title);
    double param_unity[] = {param_pad[0], param_pad[1], 7, 1, 10};

    if (i == 1) legend->Draw();

    Double_t param_lat[] = {1.15, 0.2, 62, 0.08, 2};
    kstar_cuau->latex_draw(param_lat, abcd[i]);

    Double_t param_lat_name[] = {1.15, 1.8, 62, 0.06, 2};
    if (i == 0) kstar_cuau->latex_draw(param_lat_name, "Cu+Au, #sqrt{s_{NN}}=200 GeV");

    Double_t param_lat_eta[] = {1.15, 1.6, 62, 0.06, 2};
    if (i == 0) kstar_cuau->latex_draw(param_lat_eta, "|#eta|<0.35");

    Double_t param_lat_cen[] = {5.45, 1.8, 62, 0.07, 2};
    if (i ==0) {
      param_lat_cen[0] += 0.25;
      kstar_cuau->latex_draw(param_lat_cen, centrality[0][i]);
    } else {
      kstar_cuau->latex_draw(param_lat_cen, centrality[0][i]);
    }

    unity->unity_level(param_unity);

    kstar_cuau->draw_all(i);
  }

  c1->Print("ppg_plots/rab_cuau.png");


}

void plotter_rab_for_ppg_uu() {

}

void plotter_rab_for_ppg_heau() {

}

void plotter_rab_for_ppg_pau() {

}

void plotter_rab_for_ppg_pal() {

}




void plotter() {
  plotter_rab_for_ppg_cuau();
  //plotter_rab();
}


