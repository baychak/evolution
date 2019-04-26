#include "highlighter.h"

#include <QTextCharFormat>
#include <QDebug>

Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
  {}

void Highlighter::setPattern(QRegularExpression pattern)
{
    if (pattern != mPattern) {
         mPattern = pattern;
         emit patternChanged(pattern);
       }
}

void patternChanged(QRegularExpression newPattern)
{
}

void Highlighter::highlightBlock(const QString &text)
{

    QTextCharFormat format;
    format.setFontWeight(QFont::Bold);
    QRegularExpressionMatchIterator it = mPattern.globalMatch(text);
    while (it.hasNext())
    {
      QRegularExpressionMatch match = it.next();
      setFormat(match.capturedStart(), match.capturedLength(), format);
    }

    qDebug() << "XXX text " << text;

}
