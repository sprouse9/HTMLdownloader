#ifndef FETCHHTML_H
#define FETCHHTML_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QUrl>
#include <QDebug>
#include <QString>

class fetchHTML : public QObject
{
    Q_OBJECT
public:
    explicit fetchHTML(QObject *parent = nullptr);

    void doDownload();

public slots:
    void replyFinished (QNetworkReply *reply);
    void setStoredHTML(QString html);

signals:
    void valueChanged(QString newValue);

private:
   QNetworkAccessManager *manager;
   QString storedHTML;
};

#endif // FETCHHTML_H
