/* Copyright (c) 2017-2018, Fer Zapata
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. */

#include <QGraphicsVideoItem>
#include <QPixmap>
#include "scviewfinder.hh"


SCViewFinder::SCViewFinder(QWidget* parent)
    : QGraphicsView(parent),
      l_view(new QGraphicsVideoItem),
      r_view(new QGraphicsVideoItem) {
  _scene.setBackgroundBrush(QPixmap(":/sc/image/noise"));
  _scene.addItem(l_view);
  _scene.addItem(r_view);
  l_view->moveBy(-4 - l_view->size().width() / 2, 0);
  r_view->moveBy(4 + r_view->size().width() / 2, 0);
  setScene(&_scene);
  show();
}


void SCViewFinder::setLeftCamera(QCamera* lc) {
  lc->setViewfinder(l_view);
  l_view->show();
}


void SCViewFinder::setRightCamera(QCamera* rc) {
  rc->setViewfinder(r_view);
  r_view->show();
}


void SCViewFinder::resizeEvent(QResizeEvent*) {
  fitInView(_scene.sceneRect(), Qt::KeepAspectRatio);
}
