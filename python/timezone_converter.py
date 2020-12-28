from datetime import datetime
from pytz import timezone

fmt = "%Y-%m-%d %H:%M:%S %Z%z"
timezonelist = ['UTC','US/Pacific','America/Sao_Paulo']
for zone in timezonelist:

    now_time = datetime.now(timezone(zone))
    print now_time.strftime(fmt)
