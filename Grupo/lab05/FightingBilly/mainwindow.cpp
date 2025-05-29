#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <algorithm>

MainWindow::MainWindow(std::vector<HorseSec2*> horses, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), horses(horses)
{
    ui->setupUi(this);
    QWidget* central = new QWidget(this);
    layout = new QVBoxLayout(central);

    for (HorseSec2* horse : horses) {
        QLabel* label = new QLabel(horse->getName2(), this);
        QProgressBar* bar = new QProgressBar(this);
        bar->setRange(0, 100);

        layout->addWidget(label);
        layout->addWidget(bar);

        labels.push_back(label);
        bars.push_back(bar);

        horseBarMap[horse->getName2()] = bar;

        connect(horse, &HorseSec2::updateProgress, bar, &QProgressBar::setValue);
        connect(horse, &HorseSec2::finishedRace, this, &MainWindow::onHorseFinished);

        horse->start();
    }

    resultsArea = new QTextEdit(this);
    resultsArea->setReadOnly(true);
    resultsArea->setFixedHeight(200);
    layout->addWidget(resultsArea);

    central->setLayout(layout);
    setCentralWidget(central);
}

MainWindow::~MainWindow() {
    for (HorseSec2* horse : horses) {
        horse->requestInterruption();
        horse->wait();
        delete horse;
    }
    delete ui;
}

void MainWindow::onHorseFinished(const QString& name, qint64 timeMs, int restTimeMs) {
    finishedCount++;
    results.push_back({name, timeMs, restTimeMs});

    if (finishedCount == horses.size()) {
        std::sort(results.begin(), results.end(), [](const Result& a, const Result& b) {
            return a.totalTime() < b.totalTime();
        });

        resultsArea->append("🏁 Carrera finalizada 🏁");
        resultsArea->append("------------------------------");

        int posicion = 1;
        for (const Result& r : results) {
            resultsArea->append(QString::number(posicion) + ". " + r.name +
                                " - Tiempo llegada: " + QString::number(r.totalTime()) + " ms " +

                                " ms, Descanso: " + QString::number(r.restTime) + " ms");
            posicion++;
        }

        resultsArea->append("------------------------------");
        resultsArea->append("🏆 Ganador: " + results.front().name);

        int descansoTotal = 0;
        for (const Result& r : results) {
            descansoTotal += r.restTime;
        }

        resultsArea->append("tiempo total de descanso: " + QString::number(descansoTotal) + " ms");

        QProgressBar* winningBar = horseBarMap[results.front().name];
        winningBar->setStyleSheet(
            "QProgressBar::chunk { background-color: #4CAF50; }"
            "QProgressBar { text-align: center; }"
            );
    }
}
