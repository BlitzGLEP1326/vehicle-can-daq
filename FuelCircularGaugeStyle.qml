import QtQuick 2.5
import QtQuick.Controls.Styles 1.4

CircularGaugeStyle {
    minimumValueAngle: -60
    maximumValueAngle: 60
    tickmarkStepSize: 25
    labelStepSize: 50
    labelInset: -10

    tickmark: Rectangle {
        visible: true
        implicitWidth: 2
        implicitHeight: 12
        color: styleData.value <= 25 ? "#ff0000" : "#fff"
        antialiasing: true
    }

    minorTickmark: null

    tickmarkLabel: Text {
        font.pixelSize: 12
        visible: styleData.value === 0 || styleData.value === 50 || styleData.value === 100
        text: styleData.value === 0 ? "E" : (styleData.value === 100 ? "F" : "1/2")
        color: "#fff"
        antialiasing: true
    }

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
            id: fuelLogo
            height: 48 / 3
            width: 48 / 3
            source: "../images/fuel_icon.png"
            x: (parent.width / 2) - (fuelLogo.width / 4)
            y: 25
        }
    }
}
