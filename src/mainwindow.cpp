#include "mainwindow.h"
#include <QDebug>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
  m_widget = new QWidget(this);
  m_widget->setLayout(new QVBoxLayout);
  setCentralWidget(m_widget);

  QSize min_size;
  min_size.setWidth(750);
  m_widget->setMinimumSize(min_size);

  initUi();
}

void MainWindow::initUi() {
  QGroupBox* input_group = new QGroupBox;
  QHBoxLayout* input_group_layout = new QHBoxLayout(input_group);
  QLabel* text_label = new QLabel(tr("Checked text:"));
  m_text_field = new QLineEdit;
  connect(m_text_field, &QLineEdit::textEdited, this, &MainWindow::runMatch);
  QLabel* regexp_label = new QLabel(tr("Regular expression:"));
  m_regexp_field = new QLineEdit;
  connect(m_regexp_field, &QLineEdit::textEdited, this,
          &MainWindow::constructRegExp);

  input_group_layout->addWidget(text_label);
  input_group_layout->addWidget(m_text_field);
  input_group_layout->addWidget(regexp_label);
  input_group_layout->addWidget(m_regexp_field);
  m_widget->layout()->addWidget(input_group);


  QGroupBox* output_group = new QGroupBox(tr("Output:"));
  QVBoxLayout* output_group_layout = new QVBoxLayout(output_group);
  m_error_message = new QLabel(tr("Your match:"));
  m_result_field = new QLineEdit;
  m_result_field->setReadOnly(true);

  output_group_layout->addWidget(m_error_message);
  output_group_layout->addWidget(m_result_field);
  m_widget->layout()->addWidget(output_group);
}

void MainWindow::constructRegExp() {
  m_regexp_matcher.setRegExp(m_regexp_field->text());

  if (m_regexp_matcher.isInvalid()) {
    m_error_message->setText(m_regexp_matcher.errorString());
    m_result_field->clear();
  }

  runMatch();
}

void MainWindow::runMatch() {
  if (m_regexp_matcher.isInvalid()) {
    return;
  }

  QString result = m_regexp_matcher.runMatch(m_text_field->text());
  m_result_field->setText(result);

  m_error_message->setText("Found " + m_regexp_matcher.lastMatchLength() +
                           " match(es):");
}
