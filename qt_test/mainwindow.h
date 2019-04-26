#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "highlighter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString getInputString() const;
    QStringList getWordsSet() const;
    QString findLongestWord(const QString &string, const QStringList &wordsSet) const;

signals:
   void longestWordChanged(QRegularExpression newPattern);

private slots:
   void on_pushButton_clicked();

   void on_textEdit_2_textChanged();

private:
    Ui::MainWindow *ui;
    Highlighter *inputTextHighlighter;
    Highlighter *wordsSetHighlighter;
    QString mLongestWord;
};

#endif // MAINWINDOW_H
