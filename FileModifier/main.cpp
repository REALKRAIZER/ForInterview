#include "filemodifier.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QString inputMask = "*.txt";
    bool removeInputFile = false;
    QString outputDir = "output";//каталог должен существовать
    bool overwrite = false;
    int pollFrequency = 5000; // 5 секунд
    bool oneTimeStart = false;
    quint64 fileModificationMask = 0;

    FileModifier modifier(inputMask, removeInputFile, outputDir, overwrite, pollFrequency, oneTimeStart, fileModificationMask);

    return a.exec();
}

//#include "main.moc"
