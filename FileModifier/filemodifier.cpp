#include "filemodifier.h"
#include <QDataStream>

FileModifier::FileModifier(QString inputMask, bool removeInputFile, QString outputDir, bool overwrite, int pollFrequency, bool oneTimeStart, quint64 fileModificationMask) :
    inputMask_(inputMask), removeInputFile_(removeInputFile), outputDir_(outputDir), overwrite_(overwrite),
    pollFrequency_(pollFrequency), oneTimeStart_(oneTimeStart), fileModificationMask_(fileModificationMask) {

    if(oneTimeStart) {
        QTimer::singleShot(0, this, SLOT(processFiles()));
    }
    else {
        QTimer* timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(processFiles()));
        timer->start(pollFrequency);
    }
}

void FileModifier::processFiles() {
    QDir dir;
    QStringList inputFiles = dir.entryList(QStringList() << inputMask_, QDir::Files);

    foreach(const QString &inputFile, inputFiles) {
        QString filePath = QDir::current().absoluteFilePath(inputFile);
        QFile file(filePath);
        if(!file.isOpen())
            if(file.open(QIODevice::ReadOnly)) {
                QByteArray data = file.readAll();
                if(removeInputFile_)
                    file.remove();
                else
                    file.close();

                QString outputFileName;
                if(overwrite_)
                    outputFileName = inputFile;
                else
                    outputFileName = getUniqueFileName(inputFile);

                QString outputFilePath = QDir::current().absoluteFilePath(outputDir_) + "/" + outputFileName;
                QFile outputFile(outputFilePath);
                if(outputFile.open(QIODevice::WriteOnly)) {
                    QDataStream stream(data), outputDataStream(&outputFile);
                    quint64 xorData;
                    while(!stream.atEnd()) {
                        stream >> xorData;
                        xorData ^= fileModificationMask_;
                        outputDataStream << xorData;
                    }
                    outputFile.close();

                    std::cout << "File modified: " << outputFileName.toStdString() << std::endl;
                }
        }
    }
}

QString FileModifier::getUniqueFileName(QString fileName) {
    QDir dir(QDir::current().absoluteFilePath(outputDir_));
    QString baseName = QFileInfo(fileName).baseName();
    QString suffix = QFileInfo(fileName).suffix();

    QString uniqueFileName = fileName;
    int counter = 1;
    while(dir.exists(uniqueFileName)) {
        uniqueFileName = baseName + "_" + QString::number(++counter) + "." + suffix;
    }

    return uniqueFileName;
}
