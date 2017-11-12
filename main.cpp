#include <QCoreApplication>
#include <iostream>
#include <QDebug>

bool isGrateThan(QString src, QString dst);
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString src = "1.2.3.3";
    QString dst = "1.2.3.4";
    if (isGrateThan(src, dst)){
        qDebug() << src << "grate than" << dst;
    } else {
        qDebug() << dst << "grate than" << src;
    }
    return a.exec();
}

bool isGrateThan(QString src, QString dst)
{
    Q_ASSERT(!src.isEmpty());
    Q_ASSERT(!dst.isEmpty());
    int i = src.indexOf(".");
    int j = dst.indexOf(".");
    if (i > 0 && j >0) {
        QString tmpsrc =  src.mid(0, i);
        QString tmpdst =  dst.mid(0, j);
        if ((!tmpsrc.isEmpty()) && (!tmpdst.isEmpty())) {
            if (tmpsrc.toInt() == tmpdst.toInt()) {
                // 要把后面那个点算进去
                return isGrateThan(src.mid(tmpsrc.length() + 1), dst.mid(tmpdst.length() +1));
            }
            if (tmpsrc.toInt() > tmpdst.toInt()) {
                return true;
            } else {
                return false;
            }
        }
    } else { //递归终止条件
        if (src.toInt() == dst.toInt()) {
            return false; // 全部相等不需要更新
        } else if (src.toInt() > dst.toInt()) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}
