#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QTextEdit>
#include <vector>
#include <map>               // <-- Agregado para map
#include "horsesec2.h"

struct Result {
    QString name;
    qint64 arrivalTime;
    int restTime;

    qint64 totalTime() const {
        return arrivalTime + restTime;
    }
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(std::vector<HorseSec2*> horses, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onHorseFinished(const QString& name, qint64 timeMs, int restTimeMs);

private:
    Ui::MainWindow *ui;
    std::vector<HorseSec2*> horses;
    std::vector<QLabel*> labels;
    std::vector<QProgressBar*> bars;
    QVBoxLayout *layout;
    QTextEdit *resultsArea;
    std::size_t finishedCount = 0;

    std::vector<Result> results;
    std::map<QString, QProgressBar*> horseBarMap;   // <-- Nuevo para mapear nombre->barra
};

#endif // MAINWINDOW_H

