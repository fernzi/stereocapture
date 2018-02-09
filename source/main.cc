/* Copyright (c) 2017-2018, Fer Zapata
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version. */

#include <QApplication>
#include <QCommandLineParser>
#include "config.hh"
#include "scmainwindow.hh"


int main(int argc, char** argv) {
  Q_INIT_RESOURCE(stereocapture);

  QApplication::setApplicationName(Config::APPLICATION_NAME);
  QApplication::setApplicationVersion(Config::APPLICATION_VERSION);
  QApplication app(argc, argv);

  QCommandLineParser parser;
  parser.setApplicationDescription(Config::APPLICATION_DESC);
  parser.addHelpOption();
  parser.addVersionOption();
  parser.process(app);

  SCMainWindow window;
  window.show();

  return app.exec();
}
