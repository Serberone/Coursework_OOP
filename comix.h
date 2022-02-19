#ifndef COMIX_H
#define COMIX_H

#include <QObject>

class comix : public QObject
{
    Q_OBJECT
public:
    explicit comix(QString title, QString author, int numb_of_ch, QString genre, QString status, QString translate, QString lic, QString description, QObject *parent = nullptr);
    explicit comix(QObject *parent = nullptr);
    QString Get_title();
    int Get_numb();
    QString Get_author();
    QString Get_genre();
    QString Get_status();
    QString Get_translate();
    QString Get_lic();
    QString Get_description();
    void setTitle(QString title);
    void setAuthor(QString author);
    void setNumbCh(int numb_of_ch);
    void setGenre(QString genre);
    void setStatus(QString status);
    void setTranslate(QString translate);
    void setLic(QString lic);
    void setDescript(QString description);

private:
    int ComixId;
    QString title;
    QString author;
    int numb_of_ch;
    QString genre;
    QString status;
    QString translate;
    QString lic;
    QString description;

signals:

};

#endif // COMIX_H
