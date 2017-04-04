import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

Item {

    RowLayout {
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20
        anchors.top: parent.top
    }

    Button {
        id: button1
        x: 53
        y: 203
        width: 130
        height: 109
        text: qsTr("1")
    }

    BusyIndicator {
        id: busyIndicator
        x: 334
        y: 144
        width: 138
        height: 124
    }
}
