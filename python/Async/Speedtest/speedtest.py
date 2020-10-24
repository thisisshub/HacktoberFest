# Program to test internet speed to any host machine that can run python. Try running it on https://repl.it

import speedtest
from datetime import datetime
import asyncio

def humanbytes(size):
  """Input size in bytes,
  outputs in a human readable format"""
  if not size:
      return ""
  # 2 ** 10 = 1024
  power = 2 ** 10
  raised_to_pow = 0
  dict_power_n = {0: "", 1: "K", 2: "M", 3: "G", 4: "T"}
  while size > power:
      size /= power
      raised_to_pow += 1
  return str(round(size, 2)) + " " + dict_power_n[raised_to_pow] + "B/s"

async def test():
  s = speedtest.Speedtest()
  s.get_best_server()
  s.download()
  s.upload()
  return s.results.dict()

async def run():
  print("Calculating the Internet speed!")
  print("Starting speedtest!!")
  start = datetime.now()
  response = await test()
  end = datetime.now()
  ms = (end - start).microseconds
  download_speed = response.get("download")
  upload_speed = response.get("upload")
  ping_time = response.get("ping")
  client_infos = response.get("client")
  i_s_p = client_infos.get("isp")
  i_s_p_rating = client_infos.get("isprating")
  print('SpeedTest completed in {} seconds\nPing: {}\nDownload: {}\nUpload: {}\nInternet Service Provider: {}\nISP Rating: {}'.format(
          ms, ping_time, humanbytes(download_speed), humanbytes(upload_speed), i_s_p, i_s_p_rating))

asyncio.run(run())
