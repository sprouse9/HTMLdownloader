#include "fetchhtml.h"

fetchHTML::fetchHTML(QObject *parent) :
    QObject(parent)
{

}

void fetchHTML::doDownload()
{
    manager = new QNetworkAccessManager(this);

    connect( manager, SIGNAL(finished(QNetworkReply*)),
             this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl("http://localhost/dashboard/")));

    qDebug() << "* Leaving doDownload()....";
}

void fetchHTML::replyFinished(QNetworkReply *reply)
{
    if(reply->error()) {

        qDebug() << "ERROR!";
        qDebug() << reply->errorString();

    }else {

        qDebug() << reply->header(QNetworkRequest::ContentTypeHeader).toString();
        qDebug() << reply->header(QNetworkRequest::LastModifiedHeader).toDateTime().toString();
        qDebug() << reply->header(QNetworkRequest::ContentLengthHeader).toULongLong();
        qDebug() << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();

        // Now that we have a connection and retrieved the HTML, let's display it on the text area
        this->setStoredHTML( QString::fromStdString(reply->readAll().toStdString()) );
        //storedHTML = QString::fromStdString(reply->readAll().toStdString());

    }

    reply->deleteLater();

    qDebug() << "* Leaving replyFinished()....";
}

void fetchHTML::setStoredHTML(QString html)
{
    storedHTML = html;
    emit valueChanged(html);
}
