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
