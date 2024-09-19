#include <QCoreApplication>
#include <QTextStream>
#include <iostream>

#include "CalculationStrategy.h"
#include <ByFolderCalculationStrategy.h>
#include <ByFileTypeCalculationStrategy.h>

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

    setlocale(LC_ALL, "Rus");

    std::string directorySrt;
    int strategy;

    while (true) {
        std::cout << "Enter the directory path: ";
        std::cin >> directorySrt;

        QString directory = QString::fromStdString(directorySrt);
        QDir dir(directory);

        if (!dir.exists()) {
            std::cerr << "Directory does not exist. Enter a valid directory path!" << std::endl;
            continue;
        }

        while (true) {
            std::cout << "Enter the strategy (1 for ByFolder, 2 for ByFileType): ";
            std::cin >> strategy;

            CalculationStrategy* calculation = nullptr;

            switch(strategy) {
            case 1:
                calculation = new ByFolderCalculationStrategy();
                break;

            case 2:
                calculation = new ByFileTypeCalculationStrategy();
                break;

            default:
                std::cerr << "Invalid strategy! Use 1 or 2." << std::endl;
                continue;
            }

            QMap<QString, qint64> results = calculation->calculateSize(directory);
            qint64 totalSize = getSize(directory);
            printResults(results, totalSize);

            delete calculation;
            break;
        }

        break;
    }

    return a.exec();
}
