#include "mytask.h"

MyTask::MyTask(QObject* parent) : QObject(parent) {}

void MyTask::run() {
    qDebug() << "QThread Task started in thread:" << QThread::currentThread();
    // Simulate work
    for (int i = 0; i < 5; i++) {
        QThread::sleep(1);
        qDebug() << "QThread Task progress:" << (i + 1) * 20 << "%";
    }
    emit taskFinished("QThread Task completed successfully!");
}

RunnableTask::RunnableTask(QObject* parent) : QObject(parent) {
    setAutoDelete(false);
}

void RunnableTask::run() {
    qDebug() << "QRunnable Task started in thread:" << QThread::currentThread();
    // Simulate work
    for (int i = 0; i < 5; i++) {
        QThread::sleep(1);
        qDebug() << "QRunnable Task progress:" << (i + 1) * 20 << "%";
    }
    emit taskFinished("QRunnable Task completed successfully!");
    this->deleteLater();
}
