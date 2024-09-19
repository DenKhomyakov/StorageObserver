#include <QCoreApplication>
#include <QTextStream>

void printResults(const QMap<QString, qint64>& results, qint64 totalSize) {
    QTextStream out(stdout);

    for (auto it = results.constBegin(); it != results.constEnd(); ++it) {
        double precentage;

        if (totalSize > 0) {
            precentage = static_cast<double>(it.value() / totalSize * 100);
        } else {
            precentage = 0;
        }

        QString precentageStr;

        if (precentage > 0.01) {
            precentageStr = QString::number(precentage, 'f', 2);
        } else {
            precentageStr = "< 0.01";
        }

        out << it.key() << " - " << it.value() << " bytes (" << precentageStr << "%)\n";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
