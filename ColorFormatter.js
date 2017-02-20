// Formatter functions to return color values for display of gauges, text, and images.

function getTachColor(val) {
    var yellowRPM = 7500;
    var redRPM = 8000;
    var white = "#fff";
    var yellow = "#fff417";
    var red = "#ff311a";

    if(val < yellowRPM) {
        return white;
    }
    else if(val >= yellowRPM && val < redRPM)
    {
        return yellow;
    }

    return red;
}

//getFuelColor

function getCoolantTempColor(val) {
    var blue = "#4286f4";
    var white = "#fff";
    var red = "#ff311a";

    if(val < 75) {
        return blue;
    }
    else if(val > 115) {
        return red;
    }

    return white;
}

