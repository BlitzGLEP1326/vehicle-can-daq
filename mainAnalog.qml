import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4

Window {
    id: root
    visible: true
    width: 800
    height: 480
    title: "E36 Dashboard"
    color: "#000"

    Item {
        id: container
        width: root.width
        height: Math.min(root.width, root.height)
        anchors.centerIn: parent

        Row {
            id: gaugeRow
            spacing: 20
            anchors.centerIn: parent

            // Animation for Fuel Gauge.
            Timer {
                id: fuelTimer
                running: true
                repeat: true
                interval: 4500
                onTriggered: fuelGauge.value = fuelGauge.value == fuelGauge.maximumValue ? 0 : fuelGauge.maximumValue
            }

            // Animation for Coolant Gauge.
            Timer {
                id: coolantTimer
                running: true
                repeat: true
                interval: 4500
                onTriggered: coolantGauge.value = coolantGauge.value == coolantGauge.maximumValue ? 0 : coolantGauge.maximumValue
            }

            // Animation for Speedomter Gauge.
            Timer {
                id: speedoTimer
                running: true
                repeat: true
                interval: 4500
                onTriggered: speedoGauge.value = speedoGauge.value == speedoGauge.maximumValue ? 0 : speedoGauge.maximumValue
            }

            // Animation for RPM Gauge.
            Timer {
                id: rpmTimer
                running: true
                repeat: true
                interval: 4500
                onTriggered: rpmGauge.value = rpmGauge.value == rpmGauge.maximumValue ? 0 : rpmGauge.maximumValue
            }

            CircularGauge {
                id: fuelGauge
                style: FuelCircularGaugeStyle {}
                width: 125
                height: width
                minimumValue: 0
                maximumValue: 100
                value: 0
                anchors.top: parent.verticalCenter

                // For animation.
                Behavior on value {
                    NumberAnimation {
                        duration: 4000
                    }
                }
            }

            CircularGauge {
                id: speedoGauge
                style: SpeedometerGaugeStyle {}
                width: 235
                height: width
                minimumValue: 0
                maximumValue: 160
                value: 0
                anchors.verticalCenter: parent.verticalCenter

                // For animation.
                Behavior on value {
                    NumberAnimation {
                        duration: 4000
                    }
                }
            }

            CircularGauge {
                id: rpmGauge
                style: RpmGaugeStyle {}
                width: 235
                height: width
                minimumValue: 0
                maximumValue: 8
                value: 0
                anchors.verticalCenter: parent.verticalCenter

                // For animation.
                Behavior on value {
                    NumberAnimation {
                        duration: 4000
                    }
                }
            }

            CircularGauge {
                id: coolantGauge
                style: CoolantTempCircularGaugeStyle {}
                width: 125
                height: width
                minimumValue: 0
                maximumValue: 100
                value: 0
                anchors.top: parent.verticalCenter

                // For animation.
                Behavior on value {
                    NumberAnimation {
                        duration: 4000
                    }
                }
            }
        }

        Row {
            id: imageRow
            spacing: 0
            anchors.centerIn: parent

            Image {
                id: mLogo
                source: "../images/bmw_m_logo.png"
                height: 17
                width: 58
                y: speedoGauge.height / 2
            }
        }
    }
}
