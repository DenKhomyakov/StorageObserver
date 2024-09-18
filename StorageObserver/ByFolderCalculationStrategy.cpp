#include "ByFolderCalculationStrategy.h"

QMap<QString, qint64> ByFolderCalculationStrategy::calculateSize(const QString& directory) {
    QDir dir(directory);
    QFileInfoList list = dir.entryInfoList(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);

    QMap<QString, qint64> folderSize;
    for (const QFileInfo& info : list) {
        qint64 size = getSize(info.absoluteFilePath());
        folderSize[info.fileName()] = size;
    }

    return folderSize;
}
