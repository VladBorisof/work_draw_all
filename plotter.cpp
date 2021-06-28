//инструмент
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


/*void plotter_int_rab() {

  auto kstar_cuau = new Particles("rab_kstar_cuau", 5, n_kstar_cuau, kRed, 21);
  kstar_cuau->get_inte_rab();
  kstar_cuau->int_format_graph(7, 10, 0.9);
  kstar_cuau->int_format_graph_sys(5, 10, 0.9);

  auto kstar_uu = new Particles("rab_kstar_uu", 4, n_kstar_uu, kGreen+2, 22);
  kstar_uu->get_int_rab();
  kstar_uu->int_format_graph(7, 10, 0.9);
  kstar_uu->int_format_graph_sys(5, 10, 0.9);

  auto kstar_cucu = new Particles("rab_kstar_cucu", 5, n_kstar_cucu, kBlue, 23);
  kstar_cucu->get_int_rab();
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


}*/

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
    auto unity_level = new TLine();
    unity_level->SetLineWidth(10);
    unity_level->SetLineColor(1);
    unity_level->SetLineStyle(7);

    TString abcd[] = {"(a)", "(b)", "(c)", "(d)"};
    TString centrality[] = {"0-20%", "20-40%", "40-60%", "60-80%"};
    TLatex *label_fig[2];

    TString x_title = "p_{T} [GeV/c]";
    TString y_title= "R_{AB}";
    auto kstar_cuau = new Particles("rab_kstar_cuau", 5, n_kstar_cuau, kRed, 21);
    kstar_cuau->rab_format_graph(5, 5, 0.8);
    kstar_cuau->rab_format_graph_sys(0.09, 5, 0.3);
    kstar_cuau->type_c_format(7.6, 0.05);

    auto legend = new TLegend(0.1, 0.1, 0.5, 0.5);
    Format_Legend(legend, 42, 0.06, 2, 0, "");

    auto c1 = new TCanvas("c1", "c1", 4000, 4000);
    Format_Canvas(c1, 2, 2, 0);

    for (int i = 0; i < 4; ++i) {
        c1->cd(i+1);
        double par_sp1[] = {0.13, 0.0, 0.13, 0.0};
        SetMarginPad(par_sp1);

        double param_pad[] = {1., 7.1, 0.01, 1.99, 0.99, 0.9, 0.06, 0.06, 0, 504, 505, 1};
        Format_Pad(param_pad, x_title, y_title);

        legend->AddEntry(kstar_cuau->graph_legend(10), "K*^{0}#rightarrow K^{#pm}#pi^{#mp}" , "p");
        if (i == 2) legend->Draw();

        Double_t param_lat[] = {1.15, 0.2, 62, 0.08, 2};
        kstar_cuau->latex_draw(param_lat, abcd[i]);

        Double_t param_lat_name[] = {1.15, 1.8, 62, 0.06, 2};
        if (i == 0) kstar_cuau->latex_draw(param_lat_name, "Cu+Au, #sqrt{s_{NN}}=200 GeV");

        Double_t param_lat_eta[] = {1.15, 1.6, 62, 0.06, 2};
        if (i == 0) kstar_cuau->latex_draw(param_lat_eta, "|#eta|<0.35");

        Double_t param_lat_cen[] = {5.45, 1.8, 62, 0.07, 2};
        if (i ==0) {
            param_lat_cen[0] += 0.25;
            kstar_cuau->latex_draw(param_lat_cen, centrality[i]);
        } else {kstar_cuau->latex_draw(param_lat_cen, centrality[i]);}

        unity_level->DrawLine(param_pad[0], 1, param_pad[1], 1);

        kstar_cuau->draw_all(i);
    }

    c1->Print("ppg_plots/rab_cuau.png");


}

void plotter_rab_for_ppg_uu() {
    auto unity_level = new TLine();
    unity_level->SetLineWidth(10);
    unity_level->SetLineColor(1);
    unity_level->SetLineStyle(7);

    TLatex *label_fig[2];

    TString x_title = "p_{T} [GeV/c]";
    TString y_title= "R_{AB}";
    auto kstar_uu = new Particles("rab_kstar_uu", 4, n_kstar_uu, kGreen + 2, 22);
    kstar_uu->rab_format_graph(7, 8, 0.99);
    kstar_uu->rab_format_graph_sys(0.05, 10, 0.3);
    kstar_uu->type_c_format(4, 0.05);

    auto legend = new TLegend(0.4, 1.05, 0.15, 0.9);
    Format_Legend(legend, 42, 0.06, 0, 0, "");

    auto c1 = new TCanvas("c1", "c1", 4000, 4000);
    Format_Canvas(c1, 2, 2, 0);


    legend->AddEntry(kstar_uu->graph_legend(10), "K*^{0}#rightarrow K^{#pm}#pi^{#mp}", "p");
    for (int i = 0; i < 4; ++i) {
        c1->cd(i + 1);
        double par_sp_uu[] = {0.12, 0., 0.12, 0.0};
        SetMarginPad(par_sp_uu);

        double param_pad[] = {0.95, 4.2, 0.01, 1.99, 0.87, 0.85, 0.065, 0.06, 0, 504, 504, 1};
        Format_Pad(param_pad, x_title, y_title);

        if (i == 2) legend->Draw();

        Double_t param_lat[] = {1.15, 0.2, 62, 0.08, 2};
        kstar_uu->latex_draw(param_lat, abcd[i]);

        Double_t param_lat_name[] = {1.15, 1.8, 62, 0.06, 2};
        if (i == 0) kstar_uu->latex_draw(param_lat_name, "U+U, #sqrt{s_{NN}}=193 GeV");

        Double_t param_lat_eta[] = {1.15, 1.6, 62, 0.06, 2};
        if (i == 0) kstar_uu->latex_draw(param_lat_eta, "|#eta|<0.35");


        Double_t param_lat_cen[] = {3.36, 1.8, 62, 0.07, 2};
        if (i ==0 || i==3) {
            param_lat_cen[0] += 0.13;
            kstar_uu->latex_draw(param_lat_cen, centrality[1][i]);
        } else {kstar_uu->latex_draw(param_lat_cen, centrality[1][i]);}

        unity_level->DrawLine(param_pad[0], 1, param_pad[1], 1);

        kstar_uu->draw_all(i);



    }

    c1->Print("ppg_plots/rab_uu.png");

}

void plotter_rab_for_ppg_heau() {

    auto unity_level = new TLine();
    unity_level->SetLineWidth(10);
    unity_level->SetLineColor(1);
    unity_level->SetLineStyle(7);

    TLatex *label_fig[2];

    TString x_title = "p_{T} [GeV/c]";
    TString y_title = "R_{AB}";
    auto kstar_heau = new Particles("rab_kstar_heau", 5, n_kstar_heau, kRed, 21);
    kstar_heau->rab_format_graph(5.5, 8, 0.9);
    kstar_heau->rab_format_graph_sys(0.06, 10, 0.4);
    kstar_heau->type_c_format(6.1, 0.05);


    auto legend = new TLegend(0.4, 1.05, 0.15, 0.9);
    Format_Legend(legend, 42, 0.06, 0, 0, "");

    auto c1 = new TCanvas("c1", "c1", 4000, 4000);
    Format_Canvas(c1, 2, 2, 0);


    legend->AddEntry(kstar_heau->graph_legend(7), "K*^{0}#rightarrow K^{#pm}#pi^{#mp}", "p");
    for (int i = 0; i < 4; ++i) {
        c1->cd(i + 1);
        double par_sp_heau[] = {0.12, 0., 0.12, 0.0};
        SetMarginPad(par_sp_heau);


        double param_pad[] = {0.95, 6.3, 0.01, 1.99, 0.87, 0.85, 0.065, 0.06, 0, 504, 504, 1};
        Format_Pad(param_pad, x_title, y_title);

        if (i == 2) legend->Draw();

        Double_t param_lat[] = {1.15, 0.2, 62, 0.08, 2};
        kstar_heau->latex_draw(param_lat, abcd[i]);

        Double_t param_lat_name[] = {1.15, 1.8, 62, 0.06, 2};
        if (i == 0) kstar_heau->latex_draw(param_lat_name, "He+Au, #sqrt{s_{NN}}=200 GeV");

        Double_t param_lat_eta[] = {1.15, 1.6, 62, 0.06, 2};
        if (i == 0) kstar_heau->latex_draw(param_lat_eta, "|#eta|<0.35");



        Double_t param_lat_cen[] = {4.88, 1.8, 62, 0.07, 2};
        if (i == 0 ) {
            param_lat_cen[0] += 0.2;
            kstar_heau->latex_draw(param_lat_cen, centrality[2][i]);
        } else { kstar_heau->latex_draw(param_lat_cen, centrality[2][i]); }

        unity_level->DrawLine(param_pad[0], 1, param_pad[1], 1);

        kstar_heau->draw_all(i);

    }
    c1->Print("ppg_plots/rab_heau.png");
}

void plotter_rab_for_ppg_pau() {

    auto unity_level = new TLine();
    unity_level->SetLineWidth(10);
    unity_level->SetLineColor(1);
    unity_level->SetLineStyle(7);

    TLatex *label_fig[2];

    TString x_title = "p_{T} [GeV/c]";
    TString y_title = "R_{AB}";
    auto kstar_pau = new Particles("rab_kstar_pau", 5, n_kstar_pau,kBlue, 33);
    kstar_pau->rab_format_graph(5.5, 8, 0.9);
    kstar_pau->rab_format_graph_sys(0.06, 10, 0.5);
    kstar_pau->type_c_format(5.95, 0.05);


    auto legend = new TLegend(0.4, 1.05, 0.15, 0.9);
    Format_Legend(legend, 42, 0.06, 0, 0, "");

    auto c1 = new TCanvas("c1", "c1", 4000, 4000);
    Format_Canvas(c1, 2, 2, 0);


    legend->AddEntry(kstar_pau->graph_legend(10), "K*^{0}#rightarrow K^{#pm}#pi^{#mp}", "p");
    for (int i = 0; i < 4; ++i) {
        c1->cd(i + 1);
        double par_sp_pau[] = {0.12, 0., 0.12, 0.0};
        SetMarginPad(par_sp_pau);


        double param_pad[] = {0.95, 6.1, 0.01, 1.99, 0.87, 0.85, 0.065, 0.06, 0, 504, 504, 1};
        Format_Pad(param_pad, x_title, y_title);

        if (i == 2) legend->Draw();

        Double_t param_lat[] = {1.15, 0.2, 62, 0.08, 2};
        kstar_pau->latex_draw(param_lat, abcd[i]);

        Double_t param_lat_name[] = {1.15, 1.8, 62, 0.06, 2};
        if (i == 0) kstar_pau->latex_draw(param_lat_name, "p+Au, #sqrt{s_{NN}}=200 GeV");

        Double_t param_lat_eta[] = {1.15, 1.6, 62, 0.06, 2};
        if (i == 0) kstar_pau->latex_draw(param_lat_eta, "|#eta|<0.35");



        Double_t param_lat_cen[] = {4.75, 1.8, 62, 0.07, 2};

        if (i == 0 || i==3) {
            param_lat_cen[0] += 0.2;
            kstar_pau->latex_draw(param_lat_cen, centrality[3][i]);
        }else { kstar_pau->latex_draw(param_lat_cen, centrality[3][i]); }

        unity_level->DrawLine(param_pad[0], 1, param_pad[1], 1);

        kstar_pau->draw_all(i);

    }
    c1->Print("ppg_plots/rab_pau.png");


}

void plotter_rab_for_ppg_pal() {

    auto unity_level = new TLine();
    unity_level->SetLineWidth(10);
    unity_level->SetLineColor(1);
    unity_level->SetLineStyle(7);

    TLatex *label_fig[2];

    TString x_title = "p_{T} [GeV/c]";
    TString y_title = "R_{AB}";
    auto kstar_pal = new Particles("rab_kstar_pal", 5, n_kstar_pal,kBlue, 33);
    kstar_pal->rab_format_graph(5.5, 8, 0.9);
    kstar_pal->rab_format_graph_sys(0.06, 10, 0.5);
    kstar_pal->type_c_format(4, 0.05);


    auto legend = new TLegend(0.4, 1.05, 0.15, 0.9);
    Format_Legend(legend, 42, 0.06, 0, 0, "");

    auto c1 = new TCanvas("c1", "c1", 4000, 4000);
    Format_Canvas(c1, 2, 2, 0);


    legend->AddEntry(kstar_pal->graph_legend(10), "K*^{0}#rightarrow K^{#pm}#pi^{#mp}", "p");
    for (int i = 0; i < 4; ++i) {
        c1->cd(i + 1);
        double par_sp_pal[] = {0.12, 0., 0.12, 0.0};
        SetMarginPad(par_sp_pal);


        double param_pad[] = {0.95, 4.2, 0.01, 1.99, 0.87, 0.85, 0.065, 0.06, 0, 504, 504, 1};
        Format_Pad(param_pad, x_title, y_title);

        if (i == 2) legend->Draw();

        Double_t param_lat[] = {1.15, 0.2, 62, 0.08, 2};
        kstar_pal->latex_draw(param_lat, abcd[i]);

        Double_t param_lat_name[] = {1.15, 1.8, 62, 0.06, 2};
        if (i == 0) kstar_pal->latex_draw(param_lat_name, "p+Al, #sqrt{s_{NN}}=200 GeV");

        Double_t param_lat_eta[] = {1.15, 1.6, 62, 0.06, 2};
        if (i == 0) kstar_pal->latex_draw(param_lat_eta, "|#eta|<0.35");



        Double_t param_lat_cen[] = {3.35, 1.8, 62, 0.07, 2};

        if (i == 0 || i==3) {
            param_lat_cen[0] += 0.13;
            kstar_pal->latex_draw(param_lat_cen, centrality[3][i]);
        }else { kstar_pal->latex_draw(param_lat_cen, centrality[3][i]); }

        unity_level->DrawLine(param_pad[0], 1, param_pad[1], 1);

        kstar_pal->draw_all(i);

    }
    c1->Print("ppg_plots/rab_pal.png");


}

void plotter_rab_for_ppg_small_systems() {

    auto unity_level = new TLine();
    unity_level->SetLineWidth(10);
    unity_level->SetLineColor(1);
    unity_level->SetLineStyle(7);


    TString x_title = "p_{T} [GeV/c]";
    TString y_title = "R_{AB}";

    auto kstar_pal = new Particles("rab_kstar_pal", 4, n_kstar_pal,kGreen, 107);
    kstar_pal->rab_format_graph(4, 4, 0.7);
    kstar_pal->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_pal->type_c_format(8, 0.05);

    auto kstar_pau = new Particles("rab_kstar_pau", 4, n_kstar_pau,kBlue, 108);
    kstar_pau->rab_format_graph(4, 4, 0.5);
    kstar_pau->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_pau->type_c_format(7.92, 0.05);

    auto kstar_dau = new Particles("rab_kstar_dau", 4, n_kstar_dau, kRed, 91);
    kstar_dau->rab_format_graph(4, 4, 0.5);
    kstar_dau->rab_format_graph_sys(0.05, 10, 0.3);
    kstar_dau->type_c_format(7.84, 0.05);

    auto kstar_heau = new Particles("rab_kstar_heau", 5, n_kstar_heau, kBlack, 95);
    kstar_heau->rab_format_graph(4, 4, 0.5);
    kstar_heau->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_heau->type_c_format(7.76, 0.05);




    auto legend = new TLegend(0.4, 0.8, 0.15, 1.03);
    Format_Legend(legend, 62, 0.05, 0, 0, "");

    auto c1 = new TCanvas("c1", "c1", 4000, 4000);
    Format_Canvas(c1, 2, 2, 0);




    legend->AddEntry(kstar_pal->graph_legend(8), "p+Al", "p");
    legend->AddEntry(kstar_pau->graph_legend(8), "p+Au", "p");
    legend->AddEntry(kstar_dau->graph_legend(8), "d+Au", "p");
    legend->AddEntry(kstar_heau->graph_legend(8), "^{3}He+Au", "p");

    TString centr1[] = {"0-20%","20-40%", "Peripheral", "MinBias"};
    Double_t x_for_centr1[] = {7, 6.8, 6.3, 6.7};

    for (int i = 0; i < 4; ++i) {
        c1->cd(i + 1);
        double par_sp_pal[] = {0.13, 0., 0.13, 0.0};
        SetMarginPad(par_sp_pal);



        double param_pad[] = {0.8, 8.2, 0.01, 2.6, 1, 1.15, 0.055, 0.06, 0, 504, 506, 1};
        Format_Pad(param_pad, x_title, y_title);

        if (i == 1) legend->Draw();

        Double_t param_lat[] = {7.2, 0.1, 62, 0.08, 2};
        kstar_pal->latex_draw(param_lat, abcd[i]);

        Double_t param_lat_name[] = {1.4, 2.4, 62, 0.049, 2};
        if (i == 0) kstar_pal->latex_draw(param_lat_name, "K*^{0}, #sqrt{s_{NN}}=200 GeV, |#eta|<0.35");



        Double_t param_lat_name1[] = {x_for_centr1[i], 2.4, 62, 0.049, 2};
        kstar_pau->latex_draw(param_lat_name1, centr1[i] );


        unity_level->DrawLine(param_pad[0], 1, param_pad[1], 1);




        kstar_heau->draw_all(i);

        kstar_dau->draw_all(i);

        kstar_pal->draw_all(i);
        kstar_pau->draw_all(i);


    }


    c1->Print("ppg_plots/rab_small_systems5.png");

}


void plotter_rab_heau_kstar_phi_pi0() {

    auto unity_level = new Particles();
    auto unity = new Particles();


    TString x_title = "p_{T} [GeV/c]";
    TString y_title = "R_{AB}";

    auto kstar_heau = new Particles("rab_kstar_heau", 4, n_kstar_heau,kGreen, 107);
    kstar_heau->rab_format_graph(4, 4, 0.7);
    kstar_heau->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_heau->type_c_format(8, 0.05);

    auto kstar_phi_heau = new Particles("rab_phi_heau", 4, n_phi_heau,kBlue, 108);
    kstar_phi_heau->rab_format_graph(4, 4, 0.5);
    kstar_phi_heau->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_phi_heau->type_c_format(7.92, 0.05);

    auto kstar_pi0_heau = new Particles("rab_pi0_heau", 4, n_pi0_heau, kRed, 91);
    kstar_pi0_heau->set_sys_errors();
    kstar_pi0_heau->rab_format_graph(4, 4, 0.5);
    kstar_pi0_heau->rab_format_graph_sys(0.05, 10, 0.3);
    kstar_pi0_heau->type_c_format(7.84, 0.05);




    auto legend = new TLegend(0.4, 0.8, 0.15, 1.03);
    Format_Legend(legend, 62, 0.05, 0, 0, "");

    auto c1 = new TCanvas("c1", "c1", 4000, 4000);
    Format_Canvas(c1, 2, 2, 0);




    legend->AddEntry(kstar_heau->graph_legend(8), "K*^{0}", "p");
    legend->AddEntry(kstar_phi_heau->graph_legend(8), "phi", "p");
    legend->AddEntry(kstar_pi0_heau->graph_legend(8), "pi0", "p");

    TString centr1[] = {"0-20%","20-40%", "Peripheral", "MinBias"};
    Double_t x_for_centr1[] = {7, 6.8, 6.18, 6.63};

    for (int i = 0; i < 4; ++i) {
        c1->cd(i + 1);
        double par_sp_pal[] = {0.13, 0., 0.13, 0.0};
        SetMarginPad(par_sp_pal);

        double param_pad[] = {0.8, 8.2, 0.01, 1.9, 1, 1.15, 0.055, 0.06, 0, 504, 506, 1};
        Format_Pad(param_pad, x_title, y_title);

        if (i == 1) legend->Draw();

        Double_t param_lat[] = {7.2, 0.1, 62, 0.08, 2};
        kstar_heau->latex_draw(param_lat, abcd[i]);

        Double_t param_lat_name[] = {1, 1.75, 62, 0.049, 2};
        if (i == 0) kstar_heau->latex_draw(param_lat_name, "He+Au, #sqrt{s_{NN}}=200 GeV, |#eta|<0.35");



        Double_t param_lat_name1[] = {x_for_centr1[i], 1.75, 62, 0.049, 2};
        kstar_phi_heau->latex_draw(param_lat_name1, centr1[i] );


        double params[5] = {0.8, 8.5, 7, 1, 10};
        unity->unity_level(params);




        kstar_heau->draw_all(i);
        kstar_phi_heau->draw_all(i);
        kstar_pi0_heau->draw_all(i);

    }


    c1->Print("ppg_plots/rab_heau_phiHeAu_piHeAu.png");

}

void plotter_rab_pau_kstar_phi_pi0() {

    auto unity_level = new Particles();
    auto unity = new Particles();


    TString x_title = "p_{T} [GeV/c]";
    TString y_title = "R_{AB}";

    auto kstar_pau = new Particles("rab_kstar_pau", 4, n_kstar_pau, kGreen, 107);
    kstar_pau->rab_format_graph(4, 4, 0.7);
    kstar_pau->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_pau->type_c_format(4.85, 0.05);

    auto kstar_phi_pau = new Particles("rab_phi_pau", 4, n_phi_pau, kBlue, 108);
    kstar_phi_pau->rab_format_graph(4, 4, 0.5);
    kstar_phi_pau->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_phi_pau->type_c_format(4.79, 0.05);

    auto kstar_pi0_pau = new Particles("rab_pi0_pau", 4, n_pi0_pau, kRed, 91);
    kstar_pi0_pau->set_sys_errors();
    kstar_pi0_pau->rab_format_graph(4, 4, 0.5);
    kstar_pi0_pau->rab_format_graph_sys(0.05, 10, 0.3);
    kstar_pi0_pau->type_c_format(4.73, 0.05);


    auto legend = new TLegend(0.4, 0.8, 0.15, 1.03);
    Format_Legend(legend, 62, 0.05, 0, 0, "");

    auto c1 = new TCanvas("c1", "c1", 4000, 4000);
    Format_Canvas(c1, 2, 2, 0);


    legend->AddEntry(kstar_pau->graph_legend(8), "K*^{0}", "p");
    legend->AddEntry(kstar_phi_pau->graph_legend(8), "phi", "p");
    legend->AddEntry(kstar_pi0_pau->graph_legend(8), "pi0", "p");

    TString centr1[] = {"0-20%", "20-40%", "Peripheral", "MinBias"};
    Double_t x_for_centr1[] = {4.32, 4.2, 3.86, 4.1};

    for (int i = 0; i < 4; ++i) {
        c1->cd(i + 1);
        double par_sp_pal[] = {0.13, 0., 0.13, 0.0};
        SetMarginPad(par_sp_pal);


        double param_pad[] = {0.8, 5, 0.01, 1.95, 1, 1.15, 0.055, 0.06, 0, 504, 506, 1};
        Format_Pad(param_pad, x_title, y_title);

        if (i == 1) legend->Draw();

        Double_t param_lat[] = {7.2, 0.1, 62, 0.08, 2};
        kstar_pau->latex_draw(param_lat, abcd[i]);

        Double_t param_lat_name[] = {0.9, 1.8, 62, 0.049, 2};
        if (i == 0) kstar_pau->latex_draw(param_lat_name, "p+Au, #sqrt{s_{NN}}=200 GeV, |#eta|<0.35");


        Double_t param_lat_name1[] = {x_for_centr1[i], 1.8, 62, 0.049, 2};
        kstar_phi_pau->latex_draw(param_lat_name1, centr1[i]);


        double params[5] = {0.8, 5.2, 7, 1, 10};
        unity->unity_level(params);


        kstar_pau->draw_all(i);
        kstar_phi_pau->draw_all(i);
        kstar_pi0_pau->draw_all(i);

    }
    c1->Print("ppg_plots/rab_pau_phipAu_pipau.png");
}


void plotter_rab_pal_kstar_phi_pi0() {

    auto unity_level = new Particles();
    auto unity = new Particles();


    TString x_title = "p_{T} [GeV/c]";
    TString y_title = "R_{AB}";

    auto kstar_pal = new Particles("rab_kstar_pal", 4, n_kstar_pal, kGreen, 107);
    kstar_pal->rab_format_graph(4, 4, 0.7);
    kstar_pal->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_pal->type_c_format(4.15, 0.05);

    auto kstar_phi_pal = new Particles("rab_phi_pal", 4, n_phi_pal, kBlue, 108);
    kstar_phi_pal->rab_format_graph(4, 4, 0.5);
    kstar_phi_pal->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_phi_pal->type_c_format(4.09, 0.05);

    auto kstar_pi0_pal = new Particles("rab_pi0_pal", 4, n_pi0_pal-2, kRed, 91);
    kstar_pi0_pal->set_sys_errors();
    kstar_pi0_pal->rab_format_graph(4, 4, 0.5);
    kstar_pi0_pal->rab_format_graph_sys(0.05, 10, 0.3);
    kstar_pi0_pal->type_c_format(4.03, 0.05);


    auto legend = new TLegend(0.4, 0.8, 0.15, 1.03);
    Format_Legend(legend, 62, 0.05, 0, 0, "");

    auto c1 = new TCanvas("c1", "c1", 4000, 4000);
    Format_Canvas(c1, 2, 2, 0);


    legend->AddEntry(kstar_pal->graph_legend(8), "K*^{0}", "p");
    legend->AddEntry(kstar_phi_pal->graph_legend(8), "phi", "p");
    legend->AddEntry(kstar_pi0_pal->graph_legend(8), "pi0", "p");

    TString centr1[] = {"0-20%", "20-40%", "Peripheral", "MinBias"};
    Double_t x_for_centr1[] = {3.73, 3.63, 3.35, 3.53};

    for (int i = 0; i < 4; ++i) {
        c1->cd(i + 1);
        double par_sp_pal[] = {0.13, 0., 0.13, 0.0};
        SetMarginPad(par_sp_pal);


        double param_pad[] = {0.8, 4.3, 0.01, 1.9, 1, 1.15, 0.055, 0.06, 0, 504, 506, 1};
        Format_Pad(param_pad, x_title, y_title);

        if (i == 1) legend->Draw();

        Double_t param_lat[] = {3.84, 0.1, 62, 0.08, 2};
        kstar_pal->latex_draw(param_lat, abcd[i]);

        Double_t param_lat_name[] = {0.9, 1.76, 62, 0.049, 2};
        if (i == 0) kstar_pal->latex_draw(param_lat_name, "p+Al, #sqrt{s_{NN}}=200 GeV, |#eta|<0.35");


        Double_t param_lat_name1[] = {x_for_centr1[i], 1.76, 62, 0.049, 2};
        kstar_phi_pal->latex_draw(param_lat_name1, centr1[i]);


        double params[5] = {0.8, 4.5, 7, 1, 10};
        unity->unity_level(params);


        kstar_pal->draw_all(i);
        kstar_phi_pal->draw_all(i);
        kstar_pi0_pal->draw_all(i);

    }

    c1->Print("ppg_plots/rab_pal_phipAl_pipal_1.png");
}

void plotter_rab_cuau_kstar_phi_pi0_eta() {

    auto unity_level = new Particles();
    auto unity = new Particles();


    TString x_title = "p_{T} [GeV/c]";
    TString y_title = "R_{AB}";

    auto kstar_cuau = new Particles("rab_kstar_cuau", 4, n_kstar_cuau, kGreen, 107);
    kstar_cuau->rab_format_graph(4, 4, 0.7);
    kstar_cuau->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_cuau->type_c_format(7.4, 0.05);

    auto kstar_phi_cuau = new Particles("rab_phi_cuau", 4, n_phi_cuau, kBlue, 108);
    kstar_phi_cuau->rab_format_graph(4, 4, 0.5);
    kstar_phi_cuau->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_phi_cuau->type_c_format(7.34, 0.05);

    auto kstar_pi0_cuau = new Particles("rab_pi0_cuau", 4, n_pi0_cuau, kRed, 91);
    kstar_pi0_cuau->rab_format_graph(4, 4, 0.5);
    kstar_pi0_cuau->rab_format_graph_sys(0.05, 10, 0.3);
    kstar_pi0_cuau->type_c_format(7.28, 0.05);

    auto kstar_eta_cuau = new Particles("rab_eta_cuau", 4, n_eta_cuau-2, kBlack, 95);
    kstar_pi0_cuau->set_sys_errors();
    kstar_eta_cuau->rab_format_graph(4, 4, 0.5);
    kstar_eta_cuau->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_eta_cuau->type_c_format(7.23, 0.05);


    auto legend = new TLegend(0.4, 0.78, 0.15, 1.01);
    Format_Legend(legend, 62, 0.05, 0, 0, "");

    auto c1 = new TCanvas("c1", "c1", 4000, 4000);
    Format_Canvas(c1, 2, 2, 0);


    legend->AddEntry(kstar_cuau->graph_legend(8), "K*^{0}", "p");
    legend->AddEntry(kstar_phi_cuau->graph_legend(8), "phi", "p");
    legend->AddEntry(kstar_pi0_cuau->graph_legend(8), "pi0", "p");
    legend->AddEntry(kstar_eta_cuau->graph_legend(8), "eta", "p");

    TString centr1[] = {"0-20%", "20-40%", "Peripheral", "MinBias"};
    Double_t x_for_centr1[] = {6.49, 6.3, 5.8, 6.18};

    for (int i = 0; i < 4; ++i) {
        c1->cd(i + 1);
        double par_sp_pal[] = {0.13, 0., 0.13, 0.0};
        SetMarginPad(par_sp_pal);


        double param_pad[] = {0.8, 7.6, 0.01, 1.9, 1, 1.15, 0.055, 0.06, 0, 504, 506, 1};
        Format_Pad(param_pad, x_title, y_title);

        if (i == 1) legend->Draw();

        Double_t param_lat[] = {6.7, 0.1, 62, 0.08, 2};
        kstar_cuau->latex_draw(param_lat, abcd[i]);

        Double_t param_lat_name[] = {0.9, 1.76, 62, 0.049, 2};
        if (i == 0) kstar_cuau->latex_draw(param_lat_name, "Cu+Au, #sqrt{s_{NN}}=200 GeV, |#eta|<0.35");


        Double_t param_lat_name1[] = {x_for_centr1[i], 1.76, 62, 0.049, 2};
        kstar_phi_cuau->latex_draw(param_lat_name1, centr1[i]);


        double params[5] = {0.8, 7.6, 7, 1, 10};
        unity->unity_level(params);


        kstar_cuau->draw_all(i);
        kstar_phi_cuau->draw_all(i);
        kstar_pi0_cuau->draw_all(i);
        kstar_eta_cuau->draw_all(i);

    }

    c1->Print("ppg_plots/rab_cuau_phi_pi_eta.png");
}

void plotter_rab_uu_kstar_phi_pi0_eta() {

    auto unity_level = new Particles();
    auto unity = new Particles();


    TString x_title = "p_{T} [GeV/c]";
    TString y_title = "R_{AB}";

    auto kstar_uu = new Particles("rab_kstar_uu", 4, n_kstar_uu, kGreen, 107);
    kstar_uu->rab_format_graph(4, 4, 0.7);
    kstar_uu->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_uu->type_c_format(7.8, 0.05);

    auto kstar_phi_uu = new Particles("rab_phi_uu", 4, n_phi_uu, kBlue, 108);
    kstar_phi_uu->rab_format_graph(4, 4, 0.5);
    kstar_phi_uu->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_phi_uu->type_c_format(7.9, 0.05);

    auto kstar_pi0_uu = new Particles("rab_pi0_uu", 4, n_pi0_uu, kRed, 91);
    kstar_pi0_uu->rab_format_graph(4, 4, 0.5);
    kstar_pi0_uu->rab_format_graph_sys(0.05, 10, 0.3);
    kstar_pi0_uu->type_c_format(8, 0.05);

    auto kstar_eta_uu = new Particles("rab_eta_uu", 4, n_eta_uu, kBlack, 95);
    kstar_pi0_uu->set_sys_errors();
    kstar_eta_uu->rab_format_graph(4, 4, 0.5);
    kstar_eta_uu->rab_format_graph_sys(0.06, 10, 0.3);
    kstar_eta_uu->type_c_format(8.1, 0.05);


    auto legend = new TLegend(0.4, 0.78, 0.15, 1.01);
    Format_Legend(legend, 62, 0.05, 0, 0, "");

    auto c1 = new TCanvas("c1", "c1", 4000, 4000);
    Format_Canvas(c1, 2, 2, 0);


    legend->AddEntry(kstar_uu->graph_legend(8), "K*^{0}", "p");
    legend->AddEntry(kstar_phi_uu->graph_legend(8), "phi", "p");
    legend->AddEntry(kstar_pi0_uu->graph_legend(8), "pi0", "p");
    legend->AddEntry(kstar_eta_uu->graph_legend(8), "eta", "p");

    TString centr1[] = {"0-20%", "20-40%", "Peripheral", "MinBias"};
    Double_t x_for_centr1[] = {7.05, 6.85, 6.3, 6.68};

    for (int i = 0; i < 4; ++i) {
        c1->cd(i + 1);
        double par_sp_pal[] = {0.13, 0., 0.13, 0.0};
        SetMarginPad(par_sp_pal);


        double param_pad[] = {0.8, 8.3, 0.01, 1.9, 1, 1.15, 0.055, 0.06, 0, 504, 506, 1};
        Format_Pad(param_pad, x_title, y_title);

        if (i == 1) legend->Draw();

        Double_t param_lat[] = {7.6, 0.1, 62, 0.06, 2};
        kstar_uu->latex_draw(param_lat, abcd[i]);

        Double_t param_lat_name[] = {0.9, 1.76, 62, 0.049, 2};
        if (i == 0) kstar_uu->latex_draw(param_lat_name, "U+U, #sqrt{s_{NN}}=200 GeV, |#eta|<0.35");


        Double_t param_lat_name1[] = {x_for_centr1[i], 1.76, 62, 0.049, 2};
        kstar_phi_uu->latex_draw(param_lat_name1, centr1[i]);


        double params[5] = {0.8, 8.3, 7, 1, 10};
        unity->unity_level(params);


        kstar_uu->draw_all(i);
        kstar_phi_uu->draw_all(i);
        kstar_pi0_uu->draw_all(i);
        kstar_eta_uu->draw_all(i);

    }

    c1->Print("ppg_plots/rab_uu_phi_pi_eta.png");
}

void plotter_integrated_rab() {
  // 2 - 5 GeV/c
  auto kstar_cuau = new Particles("rab_kstar_cuau", 5, n_kstar_cuau, kGreen, 107);
  kstar_cuau->get_integrated_rab(0,8);

  auto kstar_uu = new Particles("rab_kstar_uu", 4, n_kstar_uu, kRed, 107);
  kstar_uu->get_integrated_rab(2, 9);
}

void plotter() {
    plotter_rab_uu_kstar_phi_pi0_eta();
    // join_plot();
}


