#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QJsonDocument>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(640, 520);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hash(QCryptographicHash::Algorithm hashType)
{
    QByteArray res = QCryptographicHash::hash(ui->inputEdit->toPlainText().toLatin1(),hashType);
    QString r = res.toHex();
    qDebug() << "r is " << r;
    ui->outputEdit->setText(r);
}

void MainWindow::on_md5Button_clicked()
{
    hash(QCryptographicHash::Md5);
}


void MainWindow::on_sha256Button_clicked()
{
    hash(QCryptographicHash::Sha256);
}


void MainWindow::on_base64EncButton_clicked()
{
    QByteArray ba(ui->inputEdit->toPlainText().toLatin1());
    ui->outputEdit->setText(ba.toBase64());
}


void MainWindow::on_base64DecButton_clicked()
{
    ui->outputEdit->setText(QByteArray::fromBase64(ui->inputEdit->toPlainText().toLatin1()));
}

void MainWindow::format(QJsonDocument::JsonFormat fmt) {
    QByteArray ba(ui->inputEdit->toPlainText().toLatin1());
    QJsonDocument js = QJsonDocument::fromJson(ba);
    QByteArray res = js.toJson(fmt);
    ui->outputEdit->setText(res);
}
void MainWindow::on_jsonPrettyButton_clicked()
{
    format(QJsonDocument::Indented);
}


void MainWindow::on_jsonMinisizeButton_clicked()
{
    format(QJsonDocument::Compact);
}

