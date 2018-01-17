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

void MainWindow::on_btnFetchHTML_clicked()
{
    // we need a signal from the downloader object
    // that lets us know if/when the storedHTML property has changed
    connect(&downloader,  SIGNAL(valueChanged(QString)),
            this->ui->plainTextEdit,   SLOT(setPlainText(QString)) );


    downloader.doDownload();

    qDebug() << "* Back in the button clicked event after calling doDownload()....";

//    this->ui->plainTextEdit->setPlainText(
//            (downloader.storedHTML));

    //qDebug() << "The buffer size is: " << downloader.storedHTML.size();
    qDebug() << "* Leaving buttonClicked()";
}
