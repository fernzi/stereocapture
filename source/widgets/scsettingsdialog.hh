/* Copyright (c) 2017-2018, Fer Zapata
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. */

#pragma once

#include <QDialog>


namespace Ui {
  class SCSettingsDialog;
}


class SCSettingsDialog : public QDialog {
  Q_OBJECT

 public:
  explicit SCSettingsDialog(QWidget* parent = nullptr);
  ~SCSettingsDialog();

 private:
  Ui::SCSettingsDialog* ui;
};
