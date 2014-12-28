.PHONY: check clean

libringing-dev_0.4.0-1_amd64.deb:
	find src -perm 0664 -exec chmod 0644 {} \;
	find src -perm 0775 -exec chmod 0755 {} \;
	fakeroot dpkg-deb --build src libringing-dev_0.4.0-1_amd64.deb

check: libringing-dev_0.4.0-1_amd64.deb
	lintian libringing-dev_0.4.0-1_amd64.deb

clean:
	rm libringing-dev_0.4.0-1_amd64.deb
