#ifndef FILEMODIFIER_H
#define FILEMODIFIER_H
#include <iostream>
#include <QtCore/QCoreApplication>
#include <QtCore/QDir>
#include <QtCore/QFile>
#include <QtCore/QTimer>
class FileModifier : public QObject {
    Q_OBJECT

public:
    FileModifier(QString inputMask, bool deleteLogin, QString outputDir, bool overwrite, int pollFrequency, bool oneTimeStart, quint64 fileModificationMask);

public slots:
    void processFiles();

private:
    QString inputMask_;
    bool removeInputFile_;
    QString outputDir_;
    bool overwrite_;
    int pollFrequency_;
    bool oneTimeStart_;
    quint64 fileModificationMask_;

    QString getUniqueFileName(QString fileName);
};
#endif // FILEMODIFIER_H
