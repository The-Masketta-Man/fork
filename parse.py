from bs4 import BeautifulSoup

import urllib.request as ulib
url = 'https://1xstavka.ru/live/Football/';
f = ulib.urlretrieve(url, 'index.html')
with open("index.html", "r") as d:
	contents = d.read()

	soup = BeautifulSoup(contents, 'lxml')
	for tag in soup.find_all("li"):
		print("{0}: {1}".format(tag.name, tag.text))