#ifndef HIGHLIGHTER_H
#define HIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QRegularExpression>

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    Highlighter(QTextDocument *parent);

    // void setPattern(const QString &word);
    void highlightBlock(const QString &text) override;

public slots:
   void setPattern(QRegularExpression pattern);

signals:
   void patternChanged(QRegularExpression newPattern);

private:
    QRegularExpression mPattern;
};

#endif // HIGHLIGHTER_H

