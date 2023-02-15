1) steady clock now() is different from system clock now()
2) time_since_epoch() returns duration where now() returns time_point
3) cannot case time_point to duration, can only case the result of add/minus of time_point to duration
4) can add duration to time_point