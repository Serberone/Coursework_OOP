#ifndef GENRE_H
#define GENRE_H

#include <QObject>

class genre : public QObject
{
    Q_OBJECT
public:
    explicit genre(QString descript, QObject *parent = nullptr);
    explicit genre(QObject *parent = nullptr);
    QString Get_descript();
    void setDesc(QString descript);

private:
    QString descript;

signals:

};

#endif // GENRE_H
