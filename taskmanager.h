#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <QObject>
#include <QThread>
#include <QThreadPool>

class TaskManager : public QObject {
    Q_OBJECT
public:
    explicit TaskManager(QObject* parent = nullptr);
    ~TaskManager();

    Q_INVOKABLE void startQThreadTask();
    Q_INVOKABLE void startRunnableTask();

signals:
    void taskResultReady(const QString& result);
    void progressUpdated(int progress);

private slots:
    void onTaskFinished(const QString& result);

private:
    QThread* m_thread;
};

#endif
