#ifndef MYTASK_H
#define MYTASK_H

#include <QThread>
#include <QRunnable>
#include <QDebug>
#include <QObject>

class MyTask : public QObject {
    Q_OBJECT
public:
    explicit MyTask(QObject* parent = nullptr);
    void run();

signals:
    void taskFinished(const QString& result);
};

// Task using QRunnable
class RunnableTask : public QObject, public QRunnable {
    Q_OBJECT
public:
    explicit RunnableTask(QObject* parent = nullptr);
    void run() override;

signals:
    void taskFinished(const QString& result);
};

#endif
