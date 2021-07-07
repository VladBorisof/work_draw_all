//
// Created by vlad on 06.07.2021.
//

#include <TH1F.h>
#include <TVirtualPad.h>
#include <map>
#include <TPad.h>

using namespace std;

class FormatPad {
private:
    TH1F *second;

public:
    FormatPad(double *parameters, const char *title_x, const char *title_y);

    ~FormatPad();

    void set_logy();

    void set_center_axis_title();

    void set_basic_settings(double *parameters_1);

    void set_change_label_y(map <int, TString> mapper_y);

    void set_change_label_x(map <int, TString> mapper_x);

    void set_margin_pad(double *param);

    void draw_pad();
};

FormatPad::FormatPad(double *parameters, const char *title_x, const char *title_y) {
  /** param -
   * 0 - x_low
   * 1 - x_up
   * 2 - y_minimum
   * 3 - y_maximum
   **/

  second = new TH1F("", "", 100, parameters[0], parameters[1]);
  gPad->SetFillColorAlpha(0, 0);

  second->SetMinimum(parameters[2]);
  second->SetMaximum(parameters[3]);
  second->SetStats(0);
  second->SetTitle("");

  second->GetXaxis()->SetTitle(title_x);
  second->GetYaxis()->SetTitle(title_y);
}

FormatPad::~FormatPad() {
  delete second;
}

void FormatPad::set_logy() {
  gPad->SetLogy();
}

void FormatPad::draw_pad() {
  second->Draw();
}

void FormatPad::set_center_axis_title() {
  second->GetXaxis()->CenterTitle();
  second->GetYaxis()->CenterTitle();
}

void FormatPad::set_basic_settings(double *parameters_1) {
  /** 0 - x_SetTitleOffset
   * 1 - y_SetTitleOffset
   * 2 - SetTitleSize
   * 3 - SetLabelSize - numbers
   * 4 - x_SetNdivisions
   * 5 - y_SetNdivisions
   **/
  second->GetXaxis()->SetLabelFont(2);
  second->GetXaxis()->SetTitleFont(2);
  second->GetXaxis()->SetLabelSize(parameters_1[3]);
  second->GetXaxis()->SetTickSize(0.02);
  second->GetXaxis()->SetTitleSize(parameters_1[2]);
  second->GetXaxis()->SetTitleOffset(parameters_1[0]);
  second->GetXaxis()->SetNdivisions(parameters_1[4]);

  second->GetYaxis()->SetLabelFont(2);
  second->GetYaxis()->SetTitleFont(2);
  second->GetYaxis()->SetLabelSize(parameters_1[3]);
  second->GetYaxis()->SetTickSize(0.02);
  second->GetYaxis()->SetTitleSize(parameters_1[2]);
  second->GetYaxis()->SetTitleOffset(parameters_1[1]);
  second->GetYaxis()->SetNdivisions(parameters_1[5]);

}

void FormatPad::set_change_label_y(map <int, TString> mapper_y) {
  for (auto &iter : mapper_y) {
    second->GetYaxis()->ChangeLabel(iter.first,
                                    -1, -1, -1, -1, -1,
                                    iter.second);
  }
}

void FormatPad::set_change_label_x(map <int, TString> mapper_x) {
  for (auto &iter : mapper_x) {
    second->GetYaxis()->ChangeLabel(iter.first,
                                    -1, -1, -1, -1, -1,
                                    iter.second);
  }
}

void FormatPad::set_margin_pad(double *param) {
  gPad->SetLeftMargin(param[0]);
  gPad->SetRightMargin(param[1]);
  gPad->SetBottomMargin(param[2]);
  gPad->SetTopMargin(param[3]);
}