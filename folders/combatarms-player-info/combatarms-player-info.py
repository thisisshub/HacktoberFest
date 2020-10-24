#!/usr/bin/python
# -*- coding: utf8 -*-

"""combatarms-player-info.py: Web Scraping to collect Combat Arms player information."""

__author__ = "Davyd Maker"
__license__ = "GPL"
__version__ = "1.0"
__email__ = "davydmaker@gmail.com"

import requests
import re

headers = {
    'User-Agent': 'Googlebot'
}

def main():
	# Enter the nick of the player
	while True:
		try:
			player = input("[+] Enter the player's name: ");
		except Exception as e:
			print("\n[ERROR] There was a problem notifying the player nick.")
			player = ""

		if player != "":
			break

	# Make the request with the website of Combat Arms
	try:
		url = "http://combatarms.uol.com.br/index.php/perfil-de-combatente/" + player
		r = requests.get(url,headers=headers)
	except Exception as e:
		print('\n[ERROR] There was a problem trying to complete the request.\n'+'[ERROR] '+e)
		exit()

	web = r.text.strip()

	# Checking if player exists
	if str(web.find('<section class="error">')) != "-1":
		print('[-] Player not found, please try again.')
		main()
		exit()

	# Separating information from the player
	r = web.split('<main id="profile">')
	r = r[1].strip()
	r = r.split('</main>')
	r = r[0].strip()

	# Player Status Information
	nick = r.split('<div class="nick">')
	nick = nick[1].strip()
	nick = nick.split('</div>')
	nick = nick[0].strip()
	nick = re.compile(r'<h2>(.*?)</h2>').findall(nick)

	status = r.split('<dl class="status">')
	status = status[1].strip()
	status = status.split('</dl>')
	status = status[0].strip()
	status = status.split('<div>')

	print('\n------------ STATUS ------------')
	print('[-]NICK: '+''.join(nick))
	for i in status:
		info = re.compile(r'<dt>(.*?)</dt>').findall(i)
		data = re.compile(r'<dd>(.*?)</dd>').findall(i)
		if len(info) < 1:
			continue
		print('[-]'+''.join(info)+': '+''.join(data))


	# Player Combos Information
	combos = r.split('<dl class="combos">')
	combos = combos[1].strip()
	combos = combos.split('</dl>')
	combos = combos[0].strip()
	combos = combos.split('<div>')

	print('\n------------ COMBOS ------------')
	for i in combos:
		info = re.compile(r'<dt>(.*?)</dt>').findall(i)
		data = re.compile(r'<dd>(.*?)</dd>').findall(i)
		if len(info) < 1:
			continue
		print('[-]'+''.join(info)+': '+''.join(data))


	# Player Statistics Information
	statistics = r.split('<section class="statistics">')
	statistics = statistics[1].strip()
	statistics = statistics.split('</section>')
	statistics = statistics[0].strip()
	statistics1 = statistics.split('<ul class="')

	print('\n---------- STATISTICS ----------')
	for i in statistics1:
		i = i.split('<li')
		for o in i:
			data = re.compile(r'<p ?>(.*?)</p>').findall(o)
			if len(data) < 1:
				continue
			print('[-]'+data[0]+': '+data[1])

	statistics2 = statistics.split('<dl>')
	for i in statistics2:
		i = i.split('<div>')
		for o in i:
			info = re.compile(r'<dt>(.*?)</dt>').findall(o)
			data = re.compile(r'<dd>(.*?)</dd>').findall(o)
			if len(data) < 1:
				continue
			print('[-]'+''.join(info)+': '+''.join(data))
	
try:
	main()
except KeyboardInterrupt as e:
	print("\n[-] User interrupted program execution.")