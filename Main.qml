import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import com.example 1.0

ApplicationWindow {
    visible: true
    width: 400
    height: 400
    title: "Thread Example"

    TaskManager {
        id: taskManager
        onTaskResultReady: {
            taskOutput.text = result
            busyIndicator.running = false
        }
    }

    ColumnLayout {
        anchors.centerIn: parent
        spacing: 20

        BusyIndicator {
            id: busyIndicator
            running: false
            Layout.alignment: Qt.AlignHCenter
        }

        Button {
            text: "Start QThread Task"
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                busyIndicator.running = true
                taskManager.startQThreadTask()
            }
        }

        Button {
            text: "Start QRunnable Task"
            Layout.alignment: Qt.AlignHCenter
            onClicked: {
                busyIndicator.running = true
                taskManager.startRunnableTask()
            }
        }

        Text {
            id: taskOutput
            text: "Task result will appear here"
            font.pixelSize: 16
            Layout.alignment: Qt.AlignHCenter
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
