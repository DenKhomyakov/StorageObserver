#ifndef CALCULATIONSTRATEGY_H
#define CALCULATIONSTRATEGY_H

#include <QMap>
#include <QDir>
#include <QFileInfo>

class CalculationStrategy {
public:
    virtual QMap<QString, qint64> calculateSize(const QString& directory) = 0;

    virtual ~CalculationStrategy() = default;
};

qint64 getSize(const QString& path);

#endif // CALCULATIONSTRATEGY_H
