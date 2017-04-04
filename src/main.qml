import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 500
    height: 700
    property alias num1: num1
    title: qsTr("Calculator")

    Button {
        id: num1
        x: 0
        y: scrn.height + (3*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: "1"

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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }

    }

    TextField {
        id: scrn
        x: 0
        y: 0
        width: parent.width
        height: parent.height/6
        text: qsTr("0")
        horizontalAlignment: Text.AlignRight
        font.pointSize: 30
    }

    Button {
        id: num2
        x: parent.width/4
        y: scrn.height + (3*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("2")

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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: num3
        x: parent.width/2
        y: scrn.height + (3*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("3")

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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: num4
        x: 0
        y: scrn.height + (2*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("4")

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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: num5
        x: parent.width/4
        y: scrn.height + (2*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("5")

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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: num6
        x: parent.width/2
        y: scrn.height + (2*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("6")

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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: num7
        x: 0
        y: scrn.height + (parent.height/6)
        width: parent.width/4
        height: parent.height/6
        text: qsTr("7")

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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: num8
        x: parent.width/4
        y: scrn.height + (parent.height/6)
        width: parent.width/4
        height: parent.height/6
        text: qsTr("8")

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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: num9
        x: parent.width/2
        y: scrn.height + (parent.height/6)
        width: parent.width/4
        height: parent.height/6
        text: qsTr("9")

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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: num0
        x: parent.width/4
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("0")

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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: result
        x: parent.width/2
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("=")

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

    Button {
        id: plus
        x: (parent.width/4)*3
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("+")

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

    Button {
        id: minus
        x: (parent.width/4)*3
        y: scrn.height + (parent.height/6)*3
        width: parent.width/4
        height: parent.height/6
        text: qsTr("-")

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

    Button {
        id: multiply
        x: (parent.width/4)*3
        y: scrn.height + (parent.height/6)*2
        width: parent.width/4
        height: parent.height/6
        text: qsTr("x")

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

    Button {
        id: divide
        x: (parent.width/4)*3
        y: scrn.height + (parent.height/6)
        width: parent.width/4
        height: parent.height/6
        text: qsTr("÷")

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

    Button {
        id: dec_point
        x: 0
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr(".")

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

    Button {
        id: del
        x: (parent.width/4)*3
        y: scrn.height
        width: parent.width/4
        height: parent.height/6
        text: qsTr("CE")

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
            color: "#FF5B00"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: fact
        x: 0
        y: scrn.height + (parent.height/12)
        width: parent.width/4
        height: parent.height/12
        text: qsTr("n!")

        contentItem: Text {
            width: parent.width
            height: parent.height
            text: parent.text
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            x: parent.x
            y: parent.y
            color: "white"

        }

        background: Rectangle {
            width: parent.width
            height: parent.height
            color: "#2C6700"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: sqroot
        x: 0
        y: scrn.height
        width: parent.width/4
        height: parent.height/12
        text: qsTr("√")

        contentItem: Text {
            width: parent.width
            height: parent.height
            text: parent.text
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            x: parent.x
            y: parent.y
            color: "white"

        }

        background: Rectangle {
            width: parent.width
            height: parent.height
            color: "#2C6700"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: exp
        x: parent.width/4
        y: scrn.height
        width: parent.width/4
        height: parent.height/12
        text: qsTr("x^y")

        contentItem: Text {
            width: parent.width
            height: parent.height
            text: parent.text
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            x: parent.x
            y: parent.y
            color: "white"

        }

        background: Rectangle {
            width: parent.width
            height: parent.height
            color: "#2C6700"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: sec_exp
        x: parent.width/4
        y: scrn.height + (parent.height/12)
        width: parent.width/4
        height: parent.height/12
        text: qsTr("x^2")

        contentItem: Text {
            width: parent.width
            height: parent.height
            text: parent.text
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            x: parent.x
            y: parent.y
            color: "white"

        }

        background: Rectangle {
            width: parent.width
            height: parent.height
            color: "#2C6700"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: sinx
        x: parent.width/2
        y: scrn.height
        width: parent.width/4
        height: parent.height/12
        text: qsTr("sin")

        contentItem: Text {
            width: parent.width
            height: parent.height
            text: parent.text
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            x: parent.x
            y: parent.y
            color: "white"

        }

        background: Rectangle {
            width: parent.width
            height: parent.height
            color: "#2C6700"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    Button {
        id: cosx
        x: parent.width/2
        y: scrn.height + (parent.height/12)
        width: parent.width/4
        height: parent.height/12
        text: qsTr("cos")

        contentItem: Text {
            width: parent.width
            height: parent.height
            text: parent.text
            font.pointSize: 20
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            x: parent.x
            y: parent.y
            color: "white"

        }

        background: Rectangle {
            width: parent.width
            height: parent.height
            color: "#2C6700"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

}
