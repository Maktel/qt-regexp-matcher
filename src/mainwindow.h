#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include "regexp_matcher.h"

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = 0);

 private:
  QWidget* m_widget;
  RegExpMatcher m_regexp_matcher{};
  QLineEdit* m_regexp_field;
  QLineEdit* m_text_field;
  QLineEdit* m_result_field;
  QLabel* m_error_message;

  void initUi();

 private slots:
  void constructRegExp();
  void runMatch();
};

#endif  // MAINWINDOW_H
