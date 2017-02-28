#ifndef E46CANBUSFRAME_H
#define E46CANBUSFRAME_H

#include <QCanBusFrame>

class E46CanBusFrame : QCanBusFrame
{
    public:
        E46CanBusFrame();
        E46CanBusFrame(FrameType);
        E46CanBusFrame(quint32, const QByteArray&);
        unsigned short decodeEngineRpm(const QByteArray&) const;
        unsigned short decodeVehicleSpeed(const QByteArray&) const;
        unsigned short decodeFuelLevel(const QByteArray&) const;
        short decodeCoolantTempC(const QByteArray&) const;
        short decodeCoolantTempF(const QByteArray&) const;
        short decodeOilTempC(const QByteArray&) const;
        short decodeOilTempF(const QByteArray&) const;
    private:
        const unsigned short engine_rpm_id_ = 790;
        const unsigned short vehicle_speed_id_ = 0; // Value still needed.
        const unsigned short fuel_level_id_ = 1555;
        const unsigned short coolant_temp_c_id_ = 809;
        const unsigned short oil_temp_c_id_ = 1349;
};

#endif // E46CANBUSFRAME_H
