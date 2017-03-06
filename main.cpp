#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QCanBus>
#include <QCanBusDevice>
#include "e46canbusframe.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // Load gauge UI.
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml"))); 

    // Create CAN bus device and connect to can0 via SocketCAN plugin.
    QCanBusDevice *device;

    if(QCanBus::instance()->plugins().contains("socketcan"))
    {
        device = QCanBus::instance()->createDevice("socketcan", "can0");
        device->connectDevice();
    }

    // Set filters for needed data frames from the CAN bus device.
    if(device->state() == QCanBusDevice::ConnectedState)
    {
        QCanBusDevice::Filter filter;
        QList<QCanBusDevice::Filter> filterList;

        // Filter engine rpm.
        filter.frameId = 0x316u;
        filter.frameIdMask = 0x7FFu;
        filter.format = QCanBusDevice::Filter::MatchBaseFormat;
        filter.type = QCanBusFrame::DataFrame;
        filterList.append(filter);

        // Filter vehicle speed

        // Filter fuel level
        filter.frameId = 0x613u;
        filter.frameIdMask = 0x7FFu;
        filter.format = QCanBusDevice::Filter::MatchBaseFormat;
        filter.type = QCanBusFrame::DataFrame;
        filterList.append(filter);

        // Filter coolant temp
        filter.frameId = 0x329u;
        filter.frameIdMask = 0x7FFu;
        filter.format = QCanBusDevice::Filter::MatchBaseFormat;
        filter.type = QCanBusFrame::DataFrame;
        filterList.append(filter);

        // Filter oil temp
        filter.frameId = 0x545u;
        filter.frameIdMask = 0x7FFu;
        filter.format = QCanBusDevice::Filter::MatchBaseFormat;
        filter.type = QCanBusFrame::DataFrame;
        filterList.append(filter);

        // Apply filter to CAN Bus device.
        device->setConfigurationParameter(QCanBusDevice::RawFilterKey, QVariant::fromValue(filterList));

        // Read frames and push decoded data to appropriate gauge for display.
        while(device->framesAvailable() > 0 && device->state() == QCanBusDevice::ConnectedState)
        {
            // Decode data frames and send as values to appropriate gauges.
        }
    }

    return app.exec();
}
