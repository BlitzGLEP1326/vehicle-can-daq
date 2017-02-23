#include "candataobject.h"

CanDataObject::CanDataObject()
{

}

CanDataObject::CanDataObject(const unsigned short &er, const unsigned short &vs, const unsigned short &fl, const short &ctc, const short &ctf, const short &otc, const short &otf)
:
    engine_rpm_(er),
    vehicle_speed_(vs),
    fuel_level_(fl),
    coolant_temp_c_(ctc),
    coolant_temp_f_(ctf),
    oil_temp_c_(otc),
    oil_temp_f_(otf)
{}

CanDataObject::CanDataObject(const CanDataObject &obj)
:
    engine_rpm_(obj.getEngineRpm()),
    vehicle_speed_(obj.getVehicleSpeed()),
    fuel_level_(obj.getFuelLevel()),
    coolant_temp_c_(obj.getCoolantTempC()),
    coolant_temp_f_(obj.getCoolantTempF()),
    oil_temp_c_(obj.getOilTempC()),
    oil_temp_f_(obj.getOilTempF())
{}

unsigned short CanDataObject::getEngineRpm() const
{
    return engine_rpm_;
}

void CanDataObject::setEngineRpm(const unsigned short &val)
{
    engine_rpm_ = val;
}

unsigned short CanDataObject::getVehicleSpeed() const
{
    return vehicle_speed_;
}

void CanDataObject::setVehicleSpeed(const unsigned short &val)
{
    vehicle_speed_ = val;
}

unsigned short CanDataObject::getFuelLevel() const
{
    return fuel_level_;
}

void CanDataObject::setFuelLevel(const unsigned short &val)
{
    fuel_level_ = val;
}

short CanDataObject::getCoolantTempC() const
{
    return coolant_temp_c_;
}

void CanDataObject::setCoolantTempC(const short &val)
{
    coolant_temp_c_ = val;
}

short CanDataObject::getCoolantTempF() const
{
    return coolant_temp_f_;
}

void CanDataObject::setCoolantTempF(const short &val)
{
    coolant_temp_f_ = val;
}

short CanDataObject::getOilTempC() const
{
    return oil_temp_c_;
}

void CanDataObject::setOilTempC(const short &val)
{
    oil_temp_c_ = val;
}

short CanDataObject::getOilTempF() const
{
    return oil_temp_f_;
}

void CanDataObject::setOilTempF(const short &val)
{
    oil_temp_f_ = val;
}

unsigned short CanDataObject::decodeEngineRpm(const QByteArray &payload) const
{
    /*
    Unit: RPM
    CAN Id: 0x316 (790)
    Conversion: ((B4 * 256) + B3) / 6.4
    */

    unsigned short b3, b4;

    b3 = payload[2];
    b4 = payload[3];

    return ((b4 * 256) + b3) / 6.4;
}

unsigned short CanDataObject::decodeVehicleSpeed(const QByteArray &payload) const
{
    /*
    Unit: ?
    CAN Id: ?
    Conversion: ?
    */

    QByteArray data = payload;
    return 0;
}

unsigned short CanDataObject::decodeFuelLevel(const QByteArray &payload) const
{
    /*
    Unit: Liters
    CAN Id: 0x613 (1555)
    Conversion: B2
    Note: B2 is fuel level. Full being hex 39. Fuel light comes on at hex 8.
    */

    unsigned short b2;

    b2 = payload[1];

    return b2;
}

short CanDataObject::decodeCoolantTempC(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x329 (809)
    Conversion: (B2 * 0.75) - 48.373
    */

    unsigned short b2;

    b2 = payload[1];

    return (b2 * 0.75) - 48.373;
}

short CanDataObject::decodeCoolantTempF(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x329 (809)
    Conversion: (decodeCoolantTempC * 1.8) + 32
    */

    return decodeCoolantTempC(payload) * 1.8 + 32;
}

short CanDataObject::decodeOilTempC(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x545 (1349)
    Conversion: B5 - 48.373
    */

    unsigned short b5;

    b5 = payload[4];

    return b5 - 48.373;
}

short CanDataObject::decodeOilTempF(const QByteArray &payload) const
{
    /*
    Unit: C
    CAN Id: 0x545 (1349)
    Conversion: (decodeOilTempC * 1.8) + 32
    */

    return decodeOilTempC(payload) * 1.8 + 32;
}
