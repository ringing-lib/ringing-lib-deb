.PHONY: build clean

build:
	fakeroot dpkg-deb --build src libringing-dev_0.4.0-1_amd64.deb

clean:
	rm libringing-dev_0.4.0-1_amd64.deb
