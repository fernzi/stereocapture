/* Copyright (c) 2017-2018, Fer Zapata
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. */

#include <QCameraInfo>
#include <QDateTime>
#include <QCameraImageCapture>
#include <QtDebug>
#include "scmainwindow.hh"
#include "ui_scmainwindow.h"


SCMainWindow::SCMainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::SCMainWindow) {
  ui->setupUi(this);
  loadCameras();
}


SCMainWindow::~SCMainWindow() {
  delete ui;
}


void SCMainWindow::on_lCameraSelector_currentIndexChanged(int index) {
  if (index < 0) return;
  camera_l.reset(new QCamera(_cameras[index]));
  ui->cameraView->setLeftCamera(camera_l.data());
}


void SCMainWindow::on_rCameraSelector_currentIndexChanged(int index) {
  if (index < 0) return;
  camera_r.reset(new QCamera(_cameras[index]));
  ui->cameraView->setRightCamera(camera_r.data());
}


void SCMainWindow::on_captureButton_clicked() {
  auto dt = QDateTime::currentDateTime();
  auto name_l = dt.toString("yyyy-MM-dd HH:mm:ss L");
  auto name_r = dt.toString("yyyy-MM-dd HH:mm:ss R");

  QCameraImageCapture capt_l(camera_l.data());
  camera_l->setCaptureMode(QCamera::CaptureStillImage);
  camera_l->searchAndLock();
  capt_l.capture(name_l);
  camera_l->unlock();

  QCameraImageCapture capt_r(camera_r.data());
  camera_r->setCaptureMode(QCamera::CaptureStillImage);
  camera_r->searchAndLock();
  capt_r.capture(name_r);
  camera_r->unlock();
}


void SCMainWindow::on_reloadButton_clicked() {
  loadCameras();
}


void SCMainWindow::on_startButton_clicked() {
  if (not camera_l.isNull())
    camera_l->start();
  if (not camera_r.isNull())
    camera_r->start();
}


void SCMainWindow::loadCameras() {
  _cameras = QCameraInfo::availableCameras();
  ui->lCameraSelector->clear();
  ui->rCameraSelector->clear();
  for (auto i = 0; i < _cameras.count(); ++i) {
    ui->lCameraSelector->insertItem(i, _cameras[i].description(), i);
    ui->rCameraSelector->insertItem(i, _cameras[i].description(), i);
  }
}
