#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

#include <QMap>
#include <QDir>
#include <QFileInfo>

class CalculationStrategy {
public:
    virtual QMap<QString, qint64> calculateSize(const QString& directory) = 0;

    virtual ~CalculationStrategy();
};

qint64 getSize(const QString& path) {
    QFileInfo fileInfo(path);

    if (fileInfo.isFile()) {
        return fileInfo.size();
    } else if (fileInfo.isDir()) {
        QDir dir(path);
        qint64 size = 0;
        QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

        for (const QFileInfo& info : list) {
            size += getSize(info.absoluteFilePath());
        }

        return size;
    }

    return 0;
}

#endif // CALCULATIONSTRATEGY_H
