import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import CalcInterface 1.0



ApplicationWindow {
    visible: true
    width: 500
    height: 700
    title: qsTr("Calculator")

    CalcInterface {
        id: calc
    }

    /*
     * Output screen
     */
    TextField {
        id: scrn
        x: 0
        y: 0
        width: parent.width
        height: parent.height/6
        text: qsTr("0")
        horizontalAlignment: Text.AlignRight
        font.pointSize: 40
    }
   /*
    * Buttons 0-9
    */
    Button {
        id: num0
        x: parent.width/4
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("0")
        onClicked: {
            calc.number_pressed(0);
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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }
    Button {
        id: num1
        x: 0
        y: scrn.height + (3*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: "1"
        onClicked: {
            calc.number_pressed(1);
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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }

    }
    Button {
        id: num2
        x: parent.width/4
        y: scrn.height + (3*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("2")
        onClicked: {
            calc.number_pressed(2);
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
        onClicked: {
            calc.number_pressed(3);
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
        onClicked: {
            calc.number_pressed(4);
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
        onClicked: {
            calc.number_pressed(5);
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
        onClicked: {
            calc.number_pressed(6);
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
        onClicked: {
            calc.number_pressed(7);
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
        onClicked: {
            calc.number_pressed(8);
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
        onClicked: {
            calc.number_pressed(9);
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
            color: "black"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

   /*
    * Button: '='
    */
    Button {
        id: result
        x: parent.width/2
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("=")
        onClicked: {
            calc.equal_pressed();
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

    /*
     * Button: '+'
     */
    Button {
        id: plus
        x: (parent.width/4)*3
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("+")
        onClicked: {
            calc.plus_pressed();
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

    /*
     * Button: '-'
     */
    Button {
        id: minus
        x: (parent.width/4)*3
        y: scrn.height + (parent.height/6)*3
        width: parent.width/4
        height: parent.height/6
        text: qsTr("-")
        onClicked: {
            calc.minus_pressed();
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

    /*
     * Button: '*'
     */
    Button {
        id: multiply
        x: (parent.width/4)*3
        y: scrn.height + (parent.height/6)*2
        width: parent.width/4
        height: parent.height/6
        text: qsTr("x")
        onClicked: {
            calc.multiply_pressed();
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

    /*
     * Button: '/'
     */
    Button {
        id: divide
        x: (parent.width/4)*3
        y: scrn.height + (parent.height/6)
        width: parent.width/4
        height: parent.height/6
        text: qsTr("÷")
        onClicked: {
            calc.divide_pressed();
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

    /*
     * Button: '.'
     */
    Button {
        id: dec_point
        x: 0
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr(".")
        onClicked: {
            calc.point_pressed();
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

    /*
     * Button: 'CE'
     */
    Button {
        id: del
        x: (parent.width/4)*3
        y: scrn.height
        width: parent.width/4
        height: parent.height/6
        text: qsTr("CE")
        onClicked: {
            calc.delete_pressed();
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
            color: "#FF5B00"
            opacity: parent.down ? 0.6 : 1
            visible: true
        }
    }

    /*
     * Button: 'n!'
     */
    Button {
        id: fact
        x: 0
        y: scrn.height + (parent.height/12)
        width: parent.width/4
        height: parent.height/12
        text: qsTr("n!")
        onClicked: {
            calc.fact_pressed();
        }

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

    /*
     * Button: 'sqrt'
     */
    Button {
        id: sqroot
        x: 0
        y: scrn.height
        width: parent.width/4
        height: parent.height/12
        text: qsTr("√")
        onClicked: {
            calc.sqrt_pressed();
        }

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

    /*
     * Button: 'x^y'
     */
    Button {
        id: exp
        x: parent.width/4
        y: scrn.height
        width: parent.width/4
        height: parent.height/12
        text: qsTr("x<sup>y</sup>")
        onClicked: {
            calc.exp_pressed();
        }

        contentItem: Text {
            width: parent.width
            height: parent.height
            textFormat: Text.RichText
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

    /*
     * Button: 'x^2'
     */
    Button {
        id: sec_exp
        x: parent.width/4
        y: scrn.height + (parent.height/12)
        width: parent.width/4
        height: parent.height/12
        text: qsTr("x<sup>2</sup>")
        onClicked: {
            calc.sec_exp_pressed();
        }

        contentItem: Text {
            width: parent.width
            height: parent.height
            textFormat: Text.RichText
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

    /*
     * Button: 'sin'
     */
    Button {
        id: sinx
        x: parent.width/2
        y: scrn.height
        width: parent.width/4
        height: parent.height/12
        text: qsTr("sin")
        onClicked: {
            calc.sin_pressed();
        }

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

    /*
     * Button: 'cos'
     */
    Button {
        id: cosx
        x: parent.width/2
        y: scrn.height + (parent.height/12)
        width: parent.width/4
        height: parent.height/12
        text: qsTr("cos")
        onClicked: {
            calc.cos_pressed();
        }

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
