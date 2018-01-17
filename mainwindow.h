#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "fetchhtml.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btnFetchHTML_clicked();

    void on_plainTextEdit_textChanged();

private:
    Ui::MainWindow *ui;
    fetchHTML downloader;
};

#endif // MAINWINDOW_H
