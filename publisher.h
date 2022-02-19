#ifndef PUBLISHER_H
#define PUBLISHER_H

#include <QObject>
#include "comix.h"

class publisher : public QObject
{
    Q_OBJECT
public:
    explicit publisher(QVector<comix*> ComList, QObject *parent = nullptr);
    explicit publisher(QObject *parent = nullptr);
    QVector<comix*> Get_L();
    void setComixList(QVector<comix*> ComList);
private:
    QVector<comix*> ComList;

signals:

};

#endif // PUBLISHER_H
