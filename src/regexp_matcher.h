#ifndef REGEXP_MATCHER_H
#define REGEXP_MATCHER_H

#include <QRegularExpression>

class RegExpMatcher {
 public:
  void setRegExp(QString regexp);
  bool isInvalid();
  QString errorString();
  QString runMatch(QString text);
  QString lastMatchLength();

 private:
  QRegularExpression m_regexp{""};
  int m_last_match_length = 0;
};

#endif  // REGEXP_MATCHER_H
