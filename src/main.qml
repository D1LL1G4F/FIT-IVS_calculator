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
    Scrn {
        id: scrn
        x: 0
        y: 0
        width: parent.width
        height: parent.height/6
    }

    /*
     * Buttons 0-9
     */
    Num0 {
        id: num0
        x: parent.width/4
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("0")
    }
    Num1 {
        id: num1
        x: 0
        y: scrn.height + (3*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("1")
    }
    Num2 {
        id: num2
        x: parent.width/4
        y: scrn.height + (3*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("2")
    }
    Num3 {
        id: num3
        x: parent.width/2
        y: scrn.height + (3*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("3")
    }
    Num4 {
        id: num4
        x: 0
        y: scrn.height + (2*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("4")
    }
    Num5 {
        id: num5
        x: parent.width/4
        y: scrn.height + (2*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("5")
    }
    Num6 {
        id: num6
        x: parent.width/2
        y: scrn.height + (2*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("6")
    }
    Num7 {
        id: num7
        x: 0
        y: scrn.height + (parent.height/6)
        width: parent.width/4
        height: parent.height/6
        text: qsTr("7")
    }
    Num8 {
        id: num8
        x: parent.width/4
        y: scrn.height + (parent.height/6)
        width: parent.width/4
        height: parent.height/6
        text: qsTr("8")
    }
    Num9 {
        id: num9
        x: parent.width/2
        y: scrn.height + (parent.height/6)
        width: parent.width/4
        height: parent.height/6
        text: qsTr("9")
    }



    /*
     * Button: '='
     */
    Result {
        id: result
        x: parent.width/2
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("=")
    }

    /*
     * Button: '+'
     */
    Plus {
        id: plus
        x: (parent.width/4)*3
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr("+")
    }

    /*
     * Button: '-'
     */
    Minus {
        id: minus
        x: (parent.width/4)*3
        y: scrn.height + (parent.height/6)*3
        width: parent.width/4
        height: parent.height/6
        text: qsTr("-")
    }

    /*
     * Button: '*'
     */
    Multiply {
        id: multiply
        x: (parent.width/4)*3
        y: scrn.height + (parent.height/6)*2
        width: parent.width/4
        height: parent.height/6
        text: qsTr("x")
    }

    /*
     * Button: '/'
     */
    Divide {
        id: divide
        x: (parent.width/4)*3
        y: scrn.height + (parent.height/6)
        width: parent.width/4
        height: parent.height/6
        text: qsTr("÷")
    }

    /*
     * Button: '.'
     */
    Dec_point {
        id: dec_point
        x: 0
        y: scrn.height + (4*(parent.height/6))
        width: parent.width/4
        height: parent.height/6
        text: qsTr(".")
    }

    /*
     * Button: 'CE'
     */
    Del {
        id: del
        x: (parent.width/4)*3
        y: scrn.height
        width: parent.width/4
        height: parent.height/6
        text: qsTr("CE")
    }

    /*
     * Button: 'n!'
     */
    Fact {
        id: fact
        x: 0
        y: scrn.height + (parent.height/12)
        width: parent.width/4
        height: parent.height/12
        text: qsTr("n!")
    }

    /*
     * Button: 'sqrt'
     */
    Sqroot {
        id: sqroot
        x: 0
        y: scrn.height
        width: parent.width/4
        height: parent.height/12
        text: qsTr("√")
    }

    /*
     * Button: 'x^y'
     */
    Exp {
        id: exp
        x: parent.width/4
        y: scrn.height
        width: parent.width/4
        height: parent.height/12
        text: qsTr("x<sup>y</sup>")
    }

    /*
     * Button: 'x^2'
     */
    Sec_exp {
        id: sec_exp
        x: parent.width/4
        y: scrn.height + (parent.height/12)
        width: parent.width/4
        height: parent.height/12
        text: qsTr("x<sup>2</sup>")
    }

    /*
     * Button: 'sin'
     */
    Sinx {
        id: sinx
        x: parent.width/2
        y: scrn.height
        width: parent.width/4
        height: parent.height/12
        text: qsTr("sin")
    }

    /*
     * Button: 'cos'
     */
    Cosx {
        id: cosx
        x: parent.width/2
        y: scrn.height + (parent.height/12)
        width: parent.width/4
        height: parent.height/12
        text: qsTr("cos")
    }

}
