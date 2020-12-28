#!/usr/bin/env python3
import pytz  # $ pip install pytz

time_format = "%Y-%m-%d %H:%M:%S%z"
tzids = ['Asia/Shanghai', 'Europe/London', 'America/Sao_Paulo']
for tz in map(pytz.timezone, tzids):
    time_in_tz = aware_dt.astimezone(tz)
    print(f"{time_in_tz:{time_format}}")
