#ifndef HORSESEC2_H
#define HORSESEC2_H

#include <QThread>
#include <QString>
#include <QRandomGenerator>
#include <QElapsedTimer>

class HorseSec2 : public QThread {
    Q_OBJECT

public:
    HorseSec2(const QString& name2, QObject* parent = nullptr)
        : QThread(parent), name2(name2), restTimeMs(0), arrivalTimeMs(0) {}

    QString getName2() const {
        return name2;
    }

signals:
    void updateProgress(int value);
    void finishedRace(const QString& name, qint64 timeMs, int restTimeMs);

protected:
    void run() override {
        int i = 0;
        QElapsedTimer timer;
        timer.start();

        while (i < 100 && !isInterruptionRequested()) {
            int r2 = QRandomGenerator::global()->bounded(1000);
            QThread::msleep(r2);
            int r1 = QRandomGenerator::global()->bounded(10);
            i += r1;
            if (i > 100) i = 100;
            emit updateProgress(i);
        }

        arrivalTimeMs = timer.elapsed();

        restTimeMs = QRandomGenerator::global()->bounded(1000, 3000);
        QThread::msleep(restTimeMs);

        emit finishedRace(name2, arrivalTimeMs, restTimeMs);
    }

private:
    QString name2;
    int restTimeMs;
    qint64 arrivalTimeMs;
};

#endif // HORSESEC2_H





