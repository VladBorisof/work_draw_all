//
// Created by vlad on 22.12.2020.
//

#include "particles_data.h"


class Particles {
private:

    int _n;
    int _cen;
    Color_t color;
    Style_t mark_style;
    double pt[20];
    double npart[5];
    double typec[5];
    double rab[3][5][20];
    double yields[3][5][20];
    double int_rab[3][10];

    TGraphErrors *graph[5];
    TGraphErrors *graph_sys[5];
    TGraphErrors *pline[5];

    TF1 *levy[5];
    TGraphErrors *sp_graph_ratio[5];
    TGraphErrors *sp_graph[5];
    TGraphErrors *sp_graph_sys[5];
    double ratio_levy[5][20];

    TGraphErrors *int_graph;
    TGraphErrors *int_graph_sys;
    TGraphErrors *int_pline;

public:
    Particles(const TString& part="", int c = 0, int n = 0, Color_t col = 0, Style_t mark = 0);
    ~Particles();

    void get_rab_kstar_cuau();
    void get_rab_kstar_uu();
    void get_rab_kstar_cucu();
    void get_rab_kstar_heau();
    void get_rab_kstar_dau();
    void get_rab_kstar_pau();
    void get_rab_kstar_pal();

    void set_independent_var(int i);

    void get_rab_phi_cuau();
    void get_rab_phi_uu();
    void get_rab_phi_heau();
    void get_rab_phi_pau();
    void get_rab_phi_pal();

    void set_independent_var_phi(int i);

    void get_rab_pi0_cuau();
    void get_rab_pi0_uu();
    void get_rab_pi0_heau();
    void get_rab_pi0_pau();
    void get_rab_pi0_pal();

    void set_independent_var_pi0(int i);

    void get_integrated_rab();
    void int_format_graph(Float_t mark_size, Width_t line_wd, Float_t alpha);
    void int_format_graph_sys(double xe, Width_t line_wd, Float_t alpha);

    void int_draw_all();
    void int_draw();
    void int_draw_sys();

    void latex_draw(double *param, const TString& text);

    // for R_AB
    void rab_format_graph(Float_t mark_size, Width_t line_wd, Float_t alpha);
    void rab_format_graph_sys(double xe, Width_t line_wd, Float_t alpha);
    void type_c_format(double x, double dx);


    // for Spectra
    void get_levy_data(double mark_size, double line_wd, double alpha);
    void sp_fit(double *koeff, int i);
    void sp_scale(const double *koeff);
    void data_levy_draw(int i);
    void sp_format_graph(double mark_size, double line_wd, double alpha);
    void sp_format_graph_sys(double xe, Width_t line_wd, Float_t alpha);
    void sp_draw(int i);
    void sp_draw_sys(int i);

    TGraphErrors *graph_legend(Size_t mark_size);
    TGraphErrors *graph_for_legend(Size_t mark_size, int i);

    void draw_all(int i);
    void Draw(int i);
    void DrawSys(int i);
    void DrawTypeC(int i);

    void unity_level(double *params);
};


Particles::Particles(const TString& part, int c, int n, Color_t col, Style_t mark) {
  _n = n;
  _cen = c;
  color = col;
  mark_style = mark;

  if (part == "rab_kstar_cuau") {
    set_independent_var(0);
    get_rab_kstar_cuau();
  } else if (part == "rab_kstar_uu") {
    set_independent_var(1);
    get_rab_kstar_uu();
  } else if (part == "rab_kstar_heau") {
    set_independent_var(2);
    get_rab_kstar_heau();
  }  else if (part == "rab_kstar_pau") {
    set_independent_var(3);
    get_rab_kstar_pau();
  } else if (part == "rab_kstar_pal") {
    set_independent_var(4);
    get_rab_kstar_pal();
  } else if (part == "rab_kstar_cucu") {
    set_independent_var(5);
    get_rab_kstar_cucu();
  } else if (part == "rab_kstar_dau") {
    set_independent_var(6);
    get_rab_kstar_dau();
  }


  else if (part == "rab_phi_cuau") {
    set_independent_var_phi(0);
    get_rab_phi_cuau();
  } else if (part == "rab_phi_uu") {
    set_independent_var_phi(1);
    get_rab_phi_uu();
  } else if (part == "rab_phi_heau") {
    set_independent_var_phi(2);
    get_rab_phi_heau();
  } else if (part == "rab_phi_pau") {
    set_independent_var_phi(3);
    get_rab_phi_pau();
  } else if (part == "rab_phi_pal") {
    set_independent_var_phi(4);
    get_rab_phi_pal();
  }


  else if (part == "rab_pi0_cuau") {
    set_independent_var_pi0(0);
    get_rab_pi0_cuau();
  } else if (part == "rab_pi0_uu") {
    set_independent_var_pi0(1);
    get_rab_pi0_uu();
  } else if (part == "rab_pi0_heau") {
    set_independent_var_pi0(2);
    get_rab_pi0_heau();
  } else if (part == "rab_pi0_pau") {
    set_independent_var_pi0(3);
    get_rab_pi0_pau();
  } else if (part == "rab_pi0_pal") {
    set_independent_var_pi0(4);
    get_rab_pi0_pal();
  }
};


void Particles::set_independent_var(int i) {
  for (int l = 0; l < _cen; ++l) {
    typec[l] = typec_kstar[i][l];
  }
  for (int l = 0; l < _cen; ++l) {
    npart[l] = npart_kstar[i][l];
  }
  for (int l = 0; l < _n; ++l) {
    pt[l] = pt_kstar[i][l];
  }
}


void Particles::get_rab_kstar_cuau() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_kstar_cuau[i][j][k];
        yields[i][j][k] = yields_kstar_cuau[i][j][k];
      }
    }
  }
}

void Particles::get_rab_kstar_uu() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_kstar_uu[i][j][k];
        yields[i][j][k] = yields_kstar_uu[i][j][k];
      }
    }
  }
}

void Particles::get_rab_kstar_heau() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_kstar_heau[i][j][k];
        yields[i][j][k] = yields_kstar_heau[i][j][k];
      }
    }
  }
}


void Particles::get_rab_kstar_pau() {
  cout << " " << endl;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_kstar_pau[i][j][k];
        yields[i][j][k] = yields_kstar_pau[i][j][k];
      }
    }
  }
}


void Particles::get_rab_kstar_pal() {
  cout << " " << endl;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_kstar_pal[i][j][k];
        yields[i][j][k] = yields_kstar_pal[i][j][k];
      }
    }
  }
}


void Particles::get_rab_kstar_cucu() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_kstar_cucu[i][j][k];
      }
    }
  }
}

void Particles::get_rab_kstar_dau() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_kstar_dau[i][j][k];
      }
    }
  }
}


// phi
void Particles::set_independent_var_phi(int i) {
  /*for (int l = 0; l < _cen; ++l) {
    typec[l] = typec_kstar[i][l];
  }
  for (int l = 0; l < _cen; ++l) {
    npart[l] = npart_kstar[i][l];
  }*/
  for (int l = 0; l < _n; ++l) {
    pt[l] = pt_phi[i][l];
  }
}


void Particles::get_rab_phi_cuau() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_phi_cuau[i][j][k];
      }
    }
  }
}

void Particles::get_rab_phi_uu() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_phi_uu[i][j][k];
      }
    }
  }
}

void Particles::get_rab_phi_heau() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_phi_heau[i][j][k];
      }
    }
  }
}

void Particles::get_rab_phi_pau() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_phi_pau[i][j][k];
      }
    }
  }
}

void Particles::get_rab_phi_pal() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_phi_pal[i][j][k];
      }
    }
  }
}


// pi0
void Particles::set_independent_var_pi0(int i) {
  /*for (int l = 0; l < _cen; ++l) {
    typec[l] = typec_kstar[i][l];
  }
  for (int l = 0; l < _cen; ++l) {
    npart[l] = npart_kstar[i][l];
  }*/
  for (int l = 0; l < _n; ++l) {
    pt[l] = pt_pi0[i][l];
  }
}

void Particles::get_rab_pi0_cuau() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_pi0_cuau[i][j][k];
      }
    }
  }
}

void Particles::get_rab_pi0_uu() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_pi0_uu[i][j][k];
      }
    }
  }
}

void Particles::get_rab_pi0_heau() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_pi0_heau[i][j][k];
      }
    }
  }
}

void Particles::get_rab_pi0_pau() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_pi0_pau[i][j][k];
      }
    }
  }
}

void Particles::get_rab_pi0_pal() {
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < _cen; ++j) {
      for (int k = 0; k < _n; ++k) {
        rab[i][j][k] = rab_pi0_pal[i][j][k];
      }
    }
  }
}

//== integrated_rab ==//
void Particles::get_integrated_rab() {
  for (int i = 0; i < _cen; ++i) {
    double w0 = 0, totw0 = 0, i_r = 0, i_r_stat = 0, i_r_syst = 0;
    for (int j = 0; j < _n; ++j) {
      w0 = 1.0 / pow(rab[1][i][j], 2);
      totw0 += w0;
      i_r += w0 * rab[0][i][j];
      i_r_stat += pow(w0 * rab[1][i][j], 2);
      i_r_syst += w0 * sqrt(pow(rab[2][i][j], 2) + pow(typec[i] * rab[0][i][j], 2));
    }
    int_rab[0][i] = i_r / totw0;
    int_rab[1][i] = sqrt(i_r_stat) / totw0;
    int_rab[2][i] = i_r_syst / totw0;
  }
}


void Particles::int_format_graph(Float_t mark_size, Width_t line_wd, Float_t alpha) {
  int_graph = new TGraphErrors(_cen, npart, int_rab[0], nullptr, int_rab[1]);
  Format_Graph(int_graph, mark_style, mark_size, color, 0, line_wd, color, alpha);
}

void Particles::int_format_graph_sys(double xe, Width_t line_wd, Float_t alpha) {
  double dx[_cen];
  for (int j = 0; j < _cen; ++j) {
    dx[j] = xe;
  }

  int_graph_sys = new TGraphErrors(_cen, npart, int_rab[0], dx, int_rab[2]);
  Format_Graph(int_graph_sys, 1, 0.1, kWhite, 0, line_wd, color, alpha);
  int_graph_sys->SetFillColorAlpha(color, alpha);

}

void Particles::int_draw_all() {
  int_graph->Draw("P");
  int_graph_sys->Draw("2P");
}


void Particles::int_draw() {
  int_graph->Draw("P");
}

void Particles::int_draw_sys() {
  int_graph_sys->Draw("2P");
}

void Particles::latex_draw(Double_t *param, const TString& text) {
  /*param
   * 0 - x
   * 1 - y
   * 2 - font
   * 3 - size
   * 4 - line_wd*/
  auto lat_obj = new TLatex();
  lat_obj->SetTextFont(param[2]);
  lat_obj->SetTextSize(param[3]);
  lat_obj->SetLineWidth(param[4]);
  lat_obj->DrawLatex(param[0], param[1], text);
}

void Particles::rab_format_graph(Float_t mark_size, Width_t line_wd, Float_t alpha) {
  for (int i = 0; i < _cen; i++) {
    graph[i] = new TGraphErrors(_n, pt, rab[0][i], nullptr, rab[1][i]);
    Format_Graph(graph[i], mark_style, mark_size, color, 0, line_wd, color, alpha);
  }
}


void Particles::rab_format_graph_sys(double xe, Width_t line_wd, Float_t alpha) {
  double dx[_n];
  for (int j = 0; j < _n; ++j) {
    dx[j] = xe;
  }
  for (int i = 0; i < _cen; i++) {
    graph_sys[i] = new TGraphErrors(_n, pt, rab[0][i], dx, rab[2][i]);
    Format_Graph(graph_sys[i], 1, 0.1, kWhite, 0, line_wd, color, alpha);
    graph_sys[i]->SetFillColorAlpha(color, alpha);
  }
}

void Particles::type_c_format(double x, double dx) {
  double x_pi0[1], xd_pi0[1], y_pi0[1];
  x_pi0[0] = x, xd_pi0[0] = dx;
  y_pi0[0] = 1;

  for (int k1 = 0; k1 < _cen; ++k1) {
    pline[k1] = new TGraphErrors(1, x_pi0, y_pi0, xd_pi0, typec);
    Format_TypeC(pline[k1], 1, 0.1, color, 0, 1, color, 0.6);
  }
}


TGraphErrors *Particles::graph_legend(Size_t mark_size) {
  auto gr = new TGraphErrors();
  gr->SetMarkerStyle(mark_style);
  gr->SetMarkerSize(mark_size);
  gr->SetMarkerColor(color);
  return gr;
}

void Particles::draw_all(int i) {
  graph[i]->Draw("P");
  graph_sys[i]->Draw("2P");
  pline[i]->Draw("2P");
}

void Particles::Draw(int i) {
  graph[i]->Draw("P");
}


void Particles::DrawSys(int i) {
  graph_sys[i]->Draw("2P");
}


void Particles::DrawTypeC(int i) {
  pline[i]->Draw("2P");
}


void Particles::sp_format_graph(double mark_size, double line_wd, double alpha) {
  for (int i = 0; i < _cen; i++) {
    sp_graph[i] = new TGraphErrors(_n, pt, yields[0][i], nullptr, yields[1][i]);
    Format_Graph(sp_graph[i], mark_style, mark_size, color+i, 0, line_wd, color+i, alpha);
  }
}

void Particles::sp_format_graph_sys(double xe, Width_t line_wd, Float_t alpha) {
  double dx[_n];
  for (int j = 0; j < _n; ++j) {
    dx[j] = xe;
  }
  for (int i = 0; i < _cen; i++) {
    sp_graph_sys[i] = new TGraphErrors(_n, pt, yields[0][i], dx, yields[2][i]);
    Format_Graph(sp_graph_sys[i], 1, 0.1, kWhite, 0, line_wd, color+i, alpha);
    sp_graph_sys[i]->SetFillColorAlpha(color+i, alpha);
  }
}

void Particles::sp_fit(double *koeff, int i) {

  levy[i] = new TF1("name_levy",
                    "([0]*([1]-1)*([1]-2))*(pow(sqrt((x*x+0.892*0.892)/[1]/[2]+1),-[1]))/2*3.14159*[1]*[2]/([1]*[2]+0.892*([1]-2))",
                    1.0, 7.0);
  Format_LevyFun(levy[i], koeff[2], koeff[3], koeff[4], 2, 4, kBlack);
  sp_graph[i]->Fit("name_levy", "M", "", koeff[0], koeff[1]);


}

void Particles::get_levy_data(double mark_size, double line_wd, double alpha) {
  for (int i = 0; i < _cen; i++) {
    for (int j = 0; j < _n; ++j) {
      ratio_levy[i][j] = yields[0][i][j] / levy[i]->Eval(pt[j]);
    }
    sp_graph_ratio[i] = new TGraphErrors(_n, pt, ratio_levy[i]);
    Format_Graph(sp_graph_ratio[i], mark_style, mark_size, color+i, 0, line_wd, color+i, alpha);
  }

}

void Particles::data_levy_draw(int i) {
  sp_graph_ratio[i]->Draw("P");
}

void Particles::sp_draw(int i) {
  sp_graph[i]->Draw("P");
}

void Particles::sp_draw_sys(int i) {
  sp_graph_sys[i]->Draw("2P");
}

void Particles::sp_scale(const double *koeff) {
  for (int k = 0; k < 3; ++k) {
    for (int j = 0; j < _cen; j++) {
      for (int i = 0; i < _n; i++) {
        yields[k][j][i] *= koeff[j];
      }
    }
  }
}

TGraphErrors *Particles::graph_for_legend(Size_t mark_size, int i) {
  auto gr = new TGraphErrors();
  gr->SetMarkerStyle(mark_style);
  gr->SetMarkerSize(mark_size);
  gr->SetMarkerColor(color + i);
  return gr;
}


void Particles::unity_level(double *params) {
  auto unity_level = new TLine();
  unity_level->SetLineStyle(params[2]);
  unity_level->SetLineColor(params[3]);
  unity_level->SetLineWidth(params[4]);
  unity_level->DrawLine(params[0], 1, params[1], 1);
}