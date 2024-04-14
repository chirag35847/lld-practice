#pragma once

static int nextTripId = 0;

enum class DRIVER_STATUS{
    ON_TRIP,
    LOOKING_FOR_RIDER,
    OFF_DUTY
};

enum class DRIVER_RATING{
    ONE,
    TWO,
    THREE,
    FOUR,
    FiVE
};

enum class RIDER_RATING{
    ONE,
    TWO,
    THREE,
    FOUR,
    FiVE
};

enum class TRIP_STATUS{
    CANCELLED,
    ON_THE_WAY,
    COMPLETED
};