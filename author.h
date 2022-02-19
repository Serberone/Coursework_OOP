#ifndef AUTHOR_H
#define AUTHOR_H

#include <QObject>
#include "comix.h"

class author : public QObject
{
    Q_OBJECT
public:
    explicit author(QVector<comix*> TitleList, QObject *parent = nullptr);
    explicit author(QObject *parent = nullptr);
    QVector<comix*> Get_Lst();
    void setLst(QVector<comix*> TitleList);

private:
    QVector<comix*> TitleList;

signals:

};

#endif // AUTHOR_H
