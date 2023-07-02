#pragma once
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QMainWindow>
#include <QDataStream>
#include <QObject>
#include "Server.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Server *s;
    void printMes(QString mes);

signals:
    void sendtoClient(QString mes);

private slots:
    void getstart(QString mes);
    void on_tableView_2_clicked(const QModelIndex &index);
    void on_pushButton_2_clicked();
    void on_tableView_clicked(const QModelIndex &index);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString m_chat;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlTableModel *model;
    QSqlTableModel *modelmes;
    int row;
};



