#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QRegularExpression>

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = 0);

 private:
  QRegularExpression m_regexp{""};
  QWidget* m_widget;
  QLineEdit* m_regexp_field;
  QLineEdit* m_text_field;
  QLineEdit* m_result_field;
  QLabel* m_error_message;

  void buildUi();
  void constructRegExp();
  void runMatch();
};

#endif  // MAINWINDOW_H
