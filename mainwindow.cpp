#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    ui->textEdit->setText("");
    this->setWindowTitle("Untitled");
}


void MainWindow::on_actionOpen_triggered()
{
    QString Temp;
    QStringList Temp2;
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "/home/", tr("Text files (*.txt)"));
    QFile data(fileName);
    this->setWindowTitle(fileName);
    if (data.open(QFile::ReadOnly)) {
        QTextStream in(&data);
        QString str;
        while (!in.atEnd()) {

            Temp = in.readLine();

            if (Temp.isEmpty()) break;



            Temp2 = Temp.split(" ");


            for (int i = 0; i < Temp2.size(); i++) {

               str= str+Temp2[i]+" ";


            }

            str=str+"\n";

    }
        ui->textEdit->setText(str);
   }
}

void MainWindow::on_actionSave_triggered()
{
    QString filename= windowTitle();
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
            QTextStream out(&file);
            QString str1 = ui->textEdit->toPlainText();
            out << str1;

    }
}

void MainWindow::on_actionSave_As_triggered()
{
    bool ok;
    QString filename = QInputDialog::getText(this, tr("Save As"),
                                         tr("File Name:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    QFile file(filename);
    this->setWindowTitle(filename);
    if (file.open(QIODevice::ReadWrite)) {
            QTextStream out(&file);
            QString str1 = ui->textEdit->toPlainText();
            out << str1;

    }
}
