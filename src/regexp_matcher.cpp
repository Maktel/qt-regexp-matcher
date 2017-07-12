#include "regexp_matcher.h"

void RegExpMatcher::setRegExp(QString regexp) {
  m_regexp = QRegularExpression(regexp);
}

bool RegExpMatcher::isInvalid() { return !m_regexp.isValid(); }

QString RegExpMatcher::errorString() { return m_regexp.errorString(); }

QString RegExpMatcher::runMatch(QString text) {
  QString result("");
  int matches = 0;
  int offset = 0;
  QRegularExpressionMatch match = m_regexp.match(text, offset);
  while (match.hasMatch()) {
    ++matches;
    QString found = match.captured(0);
    found = QString::number(match.capturedStart(0)) + ": \"" + found + "\"";
    if (!result.isEmpty()) result += ", ";
    result.append(found);
    offset = match.capturedStart(0) + 1;
    match = m_regexp.match(text, offset);
  }

  m_last_match_length = matches;
  return result;
}

QString RegExpMatcher::lastMatchLength() {
  return QString::number(m_last_match_length);
}
