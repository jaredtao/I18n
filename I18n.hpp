#pragma once

#include <QObject>
#include <QTranslator>
#include <QMap>
#include <QCoreApplication>
#include <QDebug>
class I18n: public QObject{
    Q_OBJECT
public:
    I18n(QObject *parent = 0) : QObject(parent) {
        QTranslator *en = new QTranslator(this);
        QTranslator *cn = new QTranslator(this);
        bool ret = en->load("I18n_en.qm");
        qWarning() << ret;
        ret = cn->load("I18n_zh.qm");
        qWarning() << ret;
        mTrans["en"] = en;
        mTrans["zh"] = cn;
    }
    Q_INVOKABLE void reTrans(const QString &lan) {
        if (mTrans.contains(lan)) {
            if (!mLastLan.isEmpty()) {
                QCoreApplication::removeTranslator(mTrans[mLastLan]);
            }
            mLastLan = lan;
            QCoreApplication::installTranslator(mTrans[mLastLan]);
            emit retransRequest();
            qWarning() << "retrans" << lan;
        }
    }
signals:
    void retransRequest();
private:
    QMap<QString, QTranslator *> mTrans;
    QString mLastLan;
};
