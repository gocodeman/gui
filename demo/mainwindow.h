#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonDocument>
#include <qcryptographichash.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_md5Button_clicked();

    void on_sha256Button_clicked();

    void on_base64EncButton_clicked();

    void on_base64DecButton_clicked();

    void on_jsonPrettyButton_clicked();

    void on_jsonMinisizeButton_clicked();

private:
    Ui::MainWindow *ui;

    void hash(QCryptographicHash::Algorithm hashType);
    void format(QJsonDocument::JsonFormat fmt);
};
#endif // MAINWINDOW_H
