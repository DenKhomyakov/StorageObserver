#ifndef BYFILETYPECALCULATIONSTRATEGY_H
#define BYFILETYPECALCULATIONSTRATEGY_H

#include "CalculationStrategy.h"

class ByFileTypeCalculationStrategy : public CalculationStrategy {
public:
    QMap<QString, qint64> calculateSize(const QString& directory) override;
};

#endif // BYFILETYPECALCULATIONSTRATEGY_H
