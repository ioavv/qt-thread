#include "taskmanager.h"
#include "mytask.h"

TaskManager::TaskManager(QObject* parent) : QObject(parent), m_thread(nullptr) {}

TaskManager::~TaskManager() {
    if (m_thread) {
        m_thread->quit();
        m_thread->wait();
        delete m_thread;
    }
}

void TaskManager::startQThreadTask() {
    if (m_thread) {
        m_thread->quit();
        m_thread->wait();
        delete m_thread;
    }

    m_thread = new QThread();
    MyTask* task = new MyTask();
    task->moveToThread(m_thread);

    connect(m_thread, &QThread::started, task, &MyTask::run);
    connect(task, &MyTask::taskFinished, this, &TaskManager::onTaskFinished);
    connect(task, &MyTask::taskFinished, m_thread, &QThread::quit);
    connect(m_thread, &QThread::finished, task, &QObject::deleteLater);

    m_thread->start();
}

void TaskManager::startRunnableTask() {
    RunnableTask* task = new RunnableTask();
    connect(task, &RunnableTask::taskFinished, this, &TaskManager::onTaskFinished, Qt::QueuedConnection);
    QThreadPool::globalInstance()->start(task);
}

void TaskManager::onTaskFinished(const QString& result) {
    emit taskResultReady(result);
}
