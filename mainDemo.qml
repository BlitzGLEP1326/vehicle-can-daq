import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import "ColorFormatter.js" as CF


Window {
    id: root
    visible: true
    width: 800
    height: 480
    title: "Linear Cluster"
    color: "#000"

    Item {
        id: container
        x: 0
        y: 0
        width: 800
        height: Math.min(root.width, root.height)
        visible: true
        z: 0
        rotation: 0
        scale: 1
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenterOffset: 0
        anchors.centerIn: parent

        // Animation for Tachometer.
        Timer {
            running: true
            repeat: true
            interval: 4000
            //onTriggered: tachGauge.value = tachGauge.value == tachGauge.maximumValue ? 0 : tachGauge.maximumValue
        }

        // Animation for Fuel Gauge.
        Timer {
            running: true
            repeat: true
            interval: 4500
            onTriggered: fuelGauge.value = fuelGauge.value == fuelGauge.maximumValue ? 0 : fuelGauge.maximumValue
        }

        Gauge {
            id: tachGauge
            x: -16
            style: TachGaugeStyle {}
            width: 833
            height: 50
            anchors.topMargin: 0
            minimumValue: 0
            maximumValue: 10000
            tickmarkStepSize: 75
            value: 0
            orientation: Qt.Horizontal
            anchors.top: parent.top

            Behavior on value {
                NumberAnimation {
                    duration: 5000
                }
            }
        }

        Text {
            id: txtRPM
            x: 702
            y: 78
            width: 98
            height: 46
            color: CF.getTachColor(tachGauge.value)
            text: Math.ceil(tachGauge.value) + '<font size="1"> RPM</font>'
            styleColor: "#000"
            style: Text.Normal
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignTop
            font.pixelSize: 36
        }

        Gauge {
            id: fuelGauge
            x: -20
            y: 441
            width: 31
            style: FuelGaugeStyle {}
            height: 44
            anchors.verticalCenterOffset: 219
            minimumValue: 0
            maximumValue: 100
            tickmarkStepSize: 25
            value: 0
            orientation: Qt.Vertical
            anchors.verticalCenter: parent.verticalCenter

            Behavior on value {
                NumberAnimation {
                    duration: 4000
                }
            }
        }

        Text {
            id: txtFuel
            x: 60
            y: 437
            width: 76
            height: 32
            color: fuelGauge.value <= 20 ? "#ff0000" : "#fff"
            text: Math.ceil(fuelGauge.value) + "%"
            style: Text.Normal
            verticalAlignment: Text.AlignTop
            styleColor: "#000000"
            horizontalAlignment: Text.AlignRight
            font.pixelSize: 36
        }

        Image {
            id: imgFuel
            x: 0
            y: 444
            width: 33
            height: 30
            source: "../images/fuel_gauge.png"
        }

        Image {
            id: imgCoolant
            x: 668
            y: 445
            width: 33
            height: 30
            z: 1
            source: "../images/coolant_icon.png"
        }

        Rectangle {
            id: rectCoolant
            x: 668
            y: 445
            width: 33
            height: 30
            color: CF.getCoolantTempColor((fuelGauge.value*1.2))
            border.width: 0
            border.color: "#00000000"
        }

        Text {
            id: txtCoolant
            x: 702
            y: 437
            width: 98
            height: 46
            color: CF.getCoolantTempColor((fuelGauge.value*1.3))
            text: Math.ceil((fuelGauge.value*1.3)) + "C"
            horizontalAlignment: Text.AlignRight
            style: Text.Normal
            styleColor: "#000000"
            font.pixelSize: 36
            verticalAlignment: Text.AlignTop
        }

        Image {
            id: imgTachMask
            x: -1
            y: 0
            width: 802
            height: 77
            z: 1
            source: "../images/tachometer_mask.png"
        }

        Text {
            id: txtSpeed
            x: 400
            y: 304
            width: 98
            height: 46
            color: "#fff"
            text: '<b>68</b>' + '<font size="1"> MPH</font>'
            font.family: "Arial"
            horizontalAlignment: Text.AlignRight
            style: Text.Normal
            styleColor: "#000000"
            font.pixelSize: 46
            verticalAlignment: Text.AlignTop
        }

        Rectangle {
            id: rectCurLap
            x: 250
            y: 222
            width: 303
            height: 61
            color: "#262626"
            radius: 10
            border.width: 0
            border.color: "#262626"
        }

        Text {
            id: txtCurLap
            x: 264
            y: 223
            width: 398
            height: 58
            color: "#fff"
            text: "Current " + '<font size="4"> 0:47.10</font>'
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 36
        }
    }
}
