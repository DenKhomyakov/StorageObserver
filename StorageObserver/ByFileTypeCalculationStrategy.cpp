#include "ByFileTypeCalculationStrategy.h"

QMap<QString, qint64> ByFileTypeCalculationStrategy::calculateSize(const QString& directory) {
    QDir dir(directory);
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    QMap<QString, qint64> typeSize;

    for (const QFileInfo& info : list) {
        if (info.isFile()) {
            QString fileType = info.suffix();
            typeSize[fileType] += getSize(info.absoluteFilePath());
        }
    }

    return typeSize;
}
