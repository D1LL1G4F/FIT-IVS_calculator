import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import CalcInterface 1.0



Button {
    id: num7

    onClicked: {
        calc.number_pressed(7);
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
        opacity: parent.down ? 0.8 : 1
        color: parent.hovered ? "#222222" : "black"
        visible: true
    }
}
