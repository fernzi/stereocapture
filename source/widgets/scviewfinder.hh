/* Copyright (c) 2017-2018, Fer Zapata
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. */

#pragma once

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QCamera>


class SCViewFinder : public QGraphicsView {
  Q_OBJECT

 public:
  explicit SCViewFinder(QWidget* parent = nullptr);
  void setLeftCamera(QCamera* lc);
  void setRightCamera(QCamera* rc);

 protected:
  void resizeEvent(QResizeEvent* event) override;

 private:
  QGraphicsScene _scene;
  QGraphicsVideoItem* l_view;
  QGraphicsVideoItem* r_view;
};
