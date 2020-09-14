from bs4 import BeautifulSoupimport
from bs4 import BeautifulSoup
import re
from player import Player
from match import Game

def get_html(url):
	response = ulib.urlopen(url)
	return response.read()

def parse_elo():
	stats = list()
	atp_file = open('atp_elo.txt', 'w')
	wta_file = open('wta_elo.txt', 'w')
	atp_html = get_html('http://tennisabstract.com/reports/atp_elo_ratings.html')
	atp_soup = BeautifulSoup(atp_html, 'html.parser')
	atp_table = atp_soup.find_all('tr')
	atp_tds = atp_soup.find_all('td')
	wta_html = get_html('http://tennisabstract.com/reports/wta_elo_ratings.html')
	wta_soup = BeautifulSoup(wta_html, 'html.parser')
	wta_table = wta_soup.find_all('tr')
	wta_tds = wta_soup.find_all('td')
	k = 0
	for i in atp_tds[6:]:
		stats.append(i.text)
		k += 1
		if k == 12:
			k = 0
			Player(stats[0],
				   stats[1],
				   stats[3],
				   stats[5],
				   stats[6],
				   stats[7],
				   atp_file)
			stats = list()
	k = 0
	for i in wta_tds[6:]:
		stats.append(i.text)
		k += 1
		if k == 12:
			k = 0
			Player(stats[0],
				   stats[1],
				   stats[3],
				   stats[5],
				   stats[6],
				   stats[7],
				   wta_file)
			stats = list()

def parse_leon():
	html = get_html('https://www.leon.ru/stavki24')
	soup = BeautifulSoup(html, 'html.parser')
	div = soup.find('div', class_='main')
	scr = div.find_all('script')[1].text
	res = re.split(r'"events":', scr)[1]
	evs = re.split(r'"marketsCount":\d*},', res)
	fmats = []
	for i in evs:
		if re.findall(r'"name":"Теннис"', i):
			fmats.append(re.split(r'"', i))
	matches = list()
	for i in fmats:
		if '/'  not in i[13]:
			matches.append(Game(i[13],i[27], i[47], i[100][1:-3], i[114][1:-3], i[38][1:-1]))