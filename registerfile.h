#ifndef REGISTERFILE_H
#define REGISTERFILE_H

#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QHeaderView>
#include <qactiongroup.h>
#include <string>

using namespace std;

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


    enum GPRs
    {
        r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, r13, r14, r15,
        r16, r17, r18, r19, r20, r21, r22, r23, r24, r25, r26, r27, r28, r29, r30,
        r31,
        rtr = r27, // Temporary register
        rfp = r28, // Frame pointer
        rsp = r29, // Stack Pointer
        rfb = r30, // Return info: Function base
        rfo = r31  // Return info: Function offset
    };

    /// Symbols representing the predicate registers.
    enum PRRs
    {
        p0, p1, p2, p3, p4, p5, p6, p7,
    };

    /// Symbols representing the special purpose registers.
    enum SPRs
    {
        s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15,
        sp = s0,
        sl = s2,
        sh = s3,
        ss = s5,
        st = s6,
        srb = s7,
        sro = s8,
        sxb = s9,
        sxo = s10
    };







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
    /// Symbols representing the general purpose registers.


};


#endif // REGISTERFILE_H
