import QtQuick 2.5
import QtQuick.Controls.Styles 1.4

CircularGaugeStyle {
    minimumValueAngle: -60
    maximumValueAngle: 60
    tickmarkStepSize: 25

    tickmark: Rectangle {
        visible: true
        implicitWidth: 2
        implicitHeight: 12
        color: styleData.value <= 25 ? "#0088FF" : (styleData.value >= 75 ? "#ff0000" : "#fff")
        antialiasing: true
    }

    minorTickmark: null
    tickmarkLabel: null

    needle: Rectangle {
        y: outerRadius * 0.15
        implicitWidth: outerRadius * 0.04
        implicitHeight: outerRadius
        color: "#FF0000"
        antialiasing: true
    }

    foreground: Item {
        Rectangle {
            width: outerRadius * 0.35
            height: width
            radius: width / 2
            color: "#161616"
            anchors.centerIn: parent
        }
    }

    background: Item {
        Image {
            id: coolantLogo
            height: 36 / 2
            width: 39 / 2
            source: "../images/coolant_icon.png"
            x: (parent.width / 2) - (coolantLogo.width / 2)
            y: 25
        }
    }
}
