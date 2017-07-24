#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H

#include <QTableWidgetItem>
#include <QStandardItemModel>
#include <QHeaderView>

QT_BEGIN_NAMESPACE
class QAction;
class QObject;
class QMenu;
class QTextEdit;
QT_END_NAMESPACE

class InstructionMemory:public QTableWidget
{
    Q_OBJECT
public:
    InstructionMemory();



    QTableView *getIMTable() const;
    void setIMTable(QTableView *value);

    QStandardItemModel *getIMmodel() const;
    void setIMmodel(QStandardItemModel *value);

    bool addline(QString line);


public slots:
    void clearmemory();

private:

    QTableView *IMTable;
    QStandardItemModel *IMmodel;
    int lastAddress=0;
    QList<QString> insts=
    {
        "add","sub","xor","or","and",
        "addi","subi","xori","ori","andi",
        "nor","shadd","shadd2",
        "mul","mulu",
        "cmpeq","cmpneq","cmplt","cmple","cmpult","cmpule","btest",
        "por","pand","pxor",
        "mts","mfs",
        "lw","lh","lb",
        "sw","sh","sb",
    };

    QList<QString> GPRegs= {"r0","r1","r2","r3","r4","r5","r6","r7","r8","r9","r10","r11","r12","r13","r14","r15",
                            "r16","r17","r18","r19","r20","r21","r22","r23","r24","r25","r26","r27","r28","r29","r30","r31",
                            "rtr","rfp","rsp","rfb","rfo"
                           };

    QList<QString> PRRegs= {"p0","p1","p2","p3","p4","p5","p6","p7"};

    QList<QString> SPRegs= {"s0","s1","s2","s3","s4","s5","s6","s7","s8","s9","s10","s11","s12","s13","s14","s15",
                            "sp","sl","sh","ss","st","srb","sro","sxb","sxo"
                           };

    void addnewdata(const QString &line);
    void addnewdata(const QStringList &list);
};

#endif // INSTRUCTIONMEMORY_H
