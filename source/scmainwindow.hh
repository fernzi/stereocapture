/* Copyright (c) 2017-2018, Fer Zapata
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. */

#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include <QCamera>
#include <QList>
#include <QSharedPointer>
#include <QCameraInfo>


namespace Ui {
  class SCMainWindow;
}


class SCMainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit SCMainWindow(QWidget* parent = nullptr);
  ~SCMainWindow();

 private slots:
  void on_lCameraSelector_currentIndexChanged(int index);
  void on_rCameraSelector_currentIndexChanged(int index);
  void on_captureButton_clicked();
  void on_reloadButton_clicked();
  void on_startButton_clicked();

 private:
  Ui::SCMainWindow* ui;
  QList<QCameraInfo> _cameras;
  QSharedPointer<QCamera> camera_l;
  QSharedPointer<QCamera> camera_r;

  void loadCameras();
};
