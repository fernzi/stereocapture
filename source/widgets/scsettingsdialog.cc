/* Copyright (c) 2017-2018, Fer Zapata
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. */

#include "scsettingsdialog.hh"
#include "ui_scsettingsdialog.h"


SCSettingsDialog::SCSettingsDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::SCSettingsDialog) {
  ui->setupUi(this);
}

SCSettingsDialog::~SCSettingsDialog() {
  delete ui;
}
