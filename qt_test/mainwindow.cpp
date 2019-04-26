#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QString longestWord = findLongestWord(getInputString(), getWordsSet());

    inputTextHighlighter = new Highlighter(ui->textEdit->document());
    inputTextHighlighter->setPattern(QRegularExpression(longestWord));

    wordsSetHighlighter = new Highlighter(ui->textEdit_2->document());
    wordsSetHighlighter->setPattern(QRegularExpression(longestWord));

    QObject::connect(wordsSetHighlighter, SIGNAL(patternChanged(QRegularExpression)),
                     inputTextHighlighter, SLOT(setPattern(QRegularExpression)));
    QObject::connect(this, SIGNAL(longestWordChanged(QRegularExpression)),
                     wordsSetHighlighter, SLOT(setPattern(QRegularExpression)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getInputString() const
{
    return ui->textEdit->toPlainText();
}

QStringList MainWindow::getWordsSet() const
{
    return ui->textEdit_2->toPlainText().split(QRegularExpression("\\s+"));
}

QString MainWindow::findLongestWord(const QString &string, const QStringList &wordsSet) const
{
    QString longestWord = "";

    foreach (const QString &word, wordsSet)
    {
        if (string.contains(word) && longestWord.length() < word.length())
        {
            longestWord = word;
        }
    }

    return longestWord;
}

void MainWindow::on_pushButton_clicked()
{
    //QString inputString = getInputString();
    //QString longestWord = findLongestWord(inputString, getWordsSet());

    // qDebug() << getWordsSet();

    // Highlighter *inputTextHighlighter = new Highlighter(ui->textEdit->document());
    //inputTextHighlighter->setPattern(longestWord);
   // inputTextHighlighter->highlightBlock(inputString);

    // Highlighter *wordsSetHighlighter = new Highlighter(ui->textEdit_2->document());
   // wordsSetHighlighter->setPattern(longestWord);
   // wordsSetHighlighter->highlightBlock(ui->textEdit_2->toPlainText());
}

void MainWindow::on_textEdit_2_textChanged()
{
    qDebug() << getWordsSet();
    QString inputString = getInputString();
    mLongestWord = findLongestWord(inputString, getWordsSet());
    emit longestWordChanged(QRegularExpression(mLongestWord));
}
