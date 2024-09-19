#ifndef BYFOLDERCALCULATIONSTRATEGY_H
#define BYFOLDERCALCULATIONSTRATEGY_H

#include "CalculationStrategy.h"

class ByFolderCalculationStrategy : public CalculationStrategy {
public:
    QMap<QString, qint64> calculateSize(const QString& directory) override;
};

#endif // BYFOLDERCALCULATIONSTRATEGY_H
