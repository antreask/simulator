#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QHeaderView>
#include <qactiongroup.h>

QT_BEGIN_NAMESPACE
class QAction;
class QObject;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE

class RegisterFile:public QTableWidget
{
    Q_OBJECT

public:

    RegisterFile();

    void updateRegisters(QTableView &table,int row,int col);

    QTableView *getGPRegTable() const;
    void setGPRegTable(QTableView *value);

    QTableView *getSPRegTable() const;
    void setSPRegTable(QTableView *value);

    QTableView *getPredRegTable() const;
    void setPredRegTable(QTableView *value);

    QStandardItemModel *getGPmodel() const;
    void setGPmodel(QStandardItemModel *value);

    QStandardItemModel *getSPmodel() const;
    void setSPmodel(QStandardItemModel *value);

    QStandardItemModel *getPredmodel() const;
    void setPredmodel(QStandardItemModel *value);

    QTableView *tableToBase(const int &base, const QTableView *table);

    void setBase(int value);

    int getBase() const;

public slots:

    void changeBase2();
    void changeBase8();
    void changeBase10();
    void changeBase16();
    void clearRegisters();

signals:
    // void clearRegSig();
    void basechanged();

private:
    QTableView *GPRegTable;
    QTableView *SPRegTable;
    QTableView *PredRegTable;
    QStandardItemModel *GPmodel;
    QStandardItemModel *SPmodel;
    QStandardItemModel *Predmodel;
    void baseUpdate(const int &base);
    int base=10;

};


#endif // REGISTERFILE_H
