#include "registerfile.h"
#include "QDebug"

RegisterFile::RegisterFile()
{

    GPmodel = new QStandardItemModel(
    ); //2 Rows and 3 Columns
    SPmodel = new QStandardItemModel(16,2,this); //2 Rows and 3 Columns
    Predmodel = new QStandardItemModel(8,2,this); //2 Rows and 3 Columns

    GPRegTable = new QTableView();
    SPRegTable = new QTableView();
    PredRegTable = new QTableView();

    GPRegTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    GPRegTable->horizontalHeader()->hide();
    GPRegTable->verticalHeader()->hide();

    SPRegTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    SPRegTable->horizontalHeader()->hide();
    SPRegTable->verticalHeader()->hide();

    PredRegTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    PredRegTable->horizontalHeader()->hide();
    PredRegTable->verticalHeader()->hide();

    for( int r=0; r<32; r++ )
        for( int c=0; c<2; c++)
        {
            if (c==0)
            {
                QStandardItem *item =  new QStandardItem( QString("$R[%1] =").arg(r) );
                GPmodel->setItem(r, c, item);
            }
            else
            {
                QStandardItem *item =  new QStandardItem( QString("0"));
                GPmodel->setItem(r, c, item);
            }


        }

    for( int r=0; r<16; r++ )
        for( int c=0; c<2; c++)
        {
            if (c==0)
            {
                QStandardItem *item =  new QStandardItem( QString("$S[%1] =").arg(r) );
                SPmodel->setItem(r, c, item);
            }
            else
            {
                QStandardItem *item =  new QStandardItem( QString("0"));
                SPmodel->setItem(r, c, item);
            }


        }

    for( int r=0; r<8; r++ )
        for( int c=0; c<2; c++)
        {
            if (c==0)
            {
                QStandardItem *item =  new QStandardItem( QString("$P[%1] =").arg(r) );
                Predmodel->setItem(r, c, item);
            }
            else
            {
                QStandardItem *item =  new QStandardItem( QString("0"));
                Predmodel->setItem(r, c, item);
            }


        }

    /* QStandardItem *item1 =  new QStandardItem( QString("%1").arg(15,0,base));
    QStandardItem *item2 =  new QStandardItem( QString("%1").arg(15,0,base));
    QStandardItem *item3 =  new QStandardItem( QString("%1").arg(15,0,10));
    QStandardItem *item4 =  new QStandardItem( QString("%1").arg(15,0,16));
    Predmodel->setItem(12, 1, item1);
    Predmodel->setItem(13, 1, item2);
    Predmodel->setItem(14, 1, item3);
    Predmodel->setItem(15, 1, item4);*/



    GPRegTable->setModel(GPmodel);
    SPRegTable->setModel(SPmodel);
    PredRegTable->setModel(Predmodel);

}





QTableView *RegisterFile::getGPRegTable() const
{
    return GPRegTable;
}

void RegisterFile::setGPRegTable(QTableView *value)
{
    GPRegTable = value;
}

QTableView *RegisterFile::getSPRegTable() const
{
    return SPRegTable;
}

void RegisterFile::setSPRegTable(QTableView *value)
{
    SPRegTable = value;
}

QTableView *RegisterFile::getPredRegTable() const
{
    return PredRegTable;
}

void RegisterFile::setPredRegTable(QTableView *value)
{
    PredRegTable = value;
}

QStandardItemModel *RegisterFile::getGPmodel() const
{
    return GPmodel;
}

void RegisterFile::setGPmodel(QStandardItemModel *value)
{
    GPmodel = value;
}

QStandardItemModel *RegisterFile::getSPmodel() const
{
    return SPmodel;
}

void RegisterFile::setSPmodel(QStandardItemModel *value)
{
    SPmodel = value;
}

QStandardItemModel *RegisterFile::getPredmodel() const
{
    return Predmodel;
}

QTableView *RegisterFile::tableToBase(const int &base, const QTableView *table)
{
    QTableView *t= new QTableView();
    QStandardItemModel *newModel = new QStandardItemModel(table->model()->rowCount(),table->model()->columnCount(),this);
    t->setModel(newModel);




    for (int r=0; r < table->model()->rowCount(); r++)
        for (int c=0; c < table->model()->columnCount(); c++)
        {
            QModelIndex index=table->model()->index(r,c);

            if (c==0)
            {
                QString val =table->model()->data(index).toString();
                QStandardItem *item =  new QStandardItem(val);
                newModel->setItem(r, c, item);
            }
            else
            {
                QString val =QString("%1").arg(table->model()->data(index).toInt(),0,base);
                QStandardItem *item =  new QStandardItem(val);
                newModel->setItem(r, c, item);

            }
        }

    t->setEditTriggers(QAbstractItemView::NoEditTriggers);
    t->horizontalHeader()->hide();
    t->verticalHeader()->hide();
    return t;

}



void RegisterFile::setPredmodel(QStandardItemModel *value)
{
    Predmodel = value;
}

void RegisterFile::setBase(int value)
{
    base = value;
}

int RegisterFile::getBase() const
{
    return base;
}

void RegisterFile::changeBase2()
{
    base=2;
    //baseUpdate(base);
    emit basechanged();
}

void RegisterFile::changeBase8()
{
    base=8;
    //baseUpdate(base);
    emit basechanged();
}

void RegisterFile::changeBase10()
{
    base=10;
    //baseUpdate(base);
    emit basechanged();
}

void RegisterFile::changeBase16()
{
    base=16;
    //baseUpdate(base);
    emit basechanged();
}

void RegisterFile::baseUpdate(const int &base)
{


    QString val1,val2,val3;
    QVariant dat1,dat2,dat3;
    QModelIndex index1,index2,index3;
    for (int r=0; r<35; r++)
    {
        index1 = GPmodel->index(r,1);
        index2 = SPmodel->index(r,1);
        index3 = Predmodel->index(r,1);

        if (r<8)
        {
            val3=QString("%1").arg(PredRegTable->model()->data(index3).toInt(),0,base);
            dat3=QVariant(val3);
            PredRegTable->model()->setData(index3,dat3);
        }
        if (r<16)
        {
            val2=QString("%1").arg(SPRegTable->model()->data(index2).toInt(),0,base);
            dat2=QVariant(val2);
            SPRegTable->model()->setData(index2,dat2);
        }
        val1=QString("%1").arg(GPRegTable->model()->data(index1).toInt(),0,base);
        dat1=QVariant(val1);
        GPRegTable->model()->setData(index1,dat1);
    }


}

void RegisterFile::clearRegisters()
{

    QString val("0");
    QVariant dat(val);
    QModelIndex index,index2,index3;

    for (int r=0; r<35; r++)
    {
        index = GPmodel->index(r,1);
        index2 = SPmodel->index(r,1);
        index3 = Predmodel->index(r,1);

        if (r<8)
            PredRegTable->model()->setData(index3,dat);
        if (r<16)
            SPRegTable->model()->setData(index2,dat);
        GPRegTable->model()->setData(index,dat);

    }
    //emit clearRegSig();

}

