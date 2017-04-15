import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import CalcInterface 1.0



Button {
    id: plus

    onClicked: {
        calc.plus_pressed();
        calc.display(scrn);
    }
    
    contentItem: Text {
        width: parent.width
        height: parent.height
        text: parent.text
        font.pointSize: 30
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        x: parent.x
        y: parent.y
        color: "white"
        
    }
    
    background: Rectangle {
        width: parent.width
        height: parent.height
        color: "#2956B2"
        opacity: parent.down ? 0.6 : 1
        visible: true
    }
}
